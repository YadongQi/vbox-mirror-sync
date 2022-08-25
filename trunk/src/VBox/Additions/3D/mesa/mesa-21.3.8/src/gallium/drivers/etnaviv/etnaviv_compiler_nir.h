/*
 * Copyright (c) 2020 Etnaviv Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    Jonathan Marek <jonathan@marek.ca>
 */

#ifndef H_ETNAVIV_COMPILER_NIR
#define H_ETNAVIV_COMPILER_NIR

#include "compiler/nir/nir.h"
#include "etnaviv_asm.h"
#include "etnaviv_compiler.h"
#include "util/compiler.h"

struct etna_compile {
   nir_shader *nir;
   nir_function_impl *impl;
#define is_fs(c) ((c)->nir->info.stage == MESA_SHADER_FRAGMENT)
   const struct etna_specs *specs;
   struct etna_shader_variant *variant;

   /* block # to instr index */
   unsigned *block_ptr;

   /* Code generation */
   int inst_ptr; /* current instruction pointer */
   struct etna_inst code[ETNA_MAX_INSTRUCTIONS * ETNA_INST_SIZE];

   /* constants */
   uint64_t consts[ETNA_MAX_IMM];
   unsigned const_count;

   /* ra state */
   struct ra_graph *g;
   unsigned *live_map;
   unsigned num_nodes;

   /* There was an error during compilation */
   bool error;
};

#define compile_error(ctx, args...) ({ \
   printf(args); \
   ctx->error = true; \
   assert(0); \
})

enum {
   BYPASS_DST = 1,
   BYPASS_SRC = 2,
};

static inline bool is_sysval(nir_instr *instr)
{
   if (instr->type != nir_instr_type_intrinsic)
      return false;

   nir_intrinsic_instr *intr = nir_instr_as_intrinsic(instr);
   return intr->intrinsic == nir_intrinsic_load_front_face ||
          intr->intrinsic == nir_intrinsic_load_frag_coord;
}

/* get unique ssa/reg index for nir_src */
static inline unsigned
src_index(nir_function_impl *impl, nir_src *src)
{
   return src->is_ssa ? src->ssa->index : (src->reg.reg->index + impl->ssa_alloc);
}

/* get unique ssa/reg index for nir_dest */
static inline unsigned
dest_index(nir_function_impl *impl, nir_dest *dest)
{
   return dest->is_ssa ? dest->ssa.index : (dest->reg.reg->index + impl->ssa_alloc);
}

static inline void
update_swiz_mask(nir_alu_instr *alu, nir_dest *dest, unsigned *swiz, unsigned *mask)
{
   if (!swiz)
      return;

   bool is_vec = dest != NULL;
   unsigned swizzle = 0, write_mask = 0;
   for (unsigned i = 0; i < 4; i++) {
      /* channel not written */
      if (!(alu->dest.write_mask & (1 << i)))
         continue;
      /* src is different (only check for vecN) */
      if (is_vec && alu->src[i].src.ssa != &dest->ssa)
         continue;

      unsigned src_swiz = is_vec ? alu->src[i].swizzle[0] : alu->src[0].swizzle[i];
      swizzle |= (*swiz >> src_swiz * 2 & 3) << i * 2;
      /* this channel isn't written through this chain */
      if (*mask & (1 << src_swiz))
         write_mask |= 1 << i;
   }
   *swiz = swizzle;
   *mask = write_mask;
}

static nir_dest *
real_dest(nir_dest *dest, unsigned *swiz, unsigned *mask)
{
   if (!dest || !dest->is_ssa)
      return dest;

   bool can_bypass_src = !list_length(&dest->ssa.if_uses);
   nir_instr *p_instr = dest->ssa.parent_instr;

   /* if used by a vecN, the "real" destination becomes the vecN destination
    * lower_alu guarantees that values used by a vecN are only used by that vecN
    * we can apply the same logic to movs in a some cases too
    */
   nir_foreach_use(use_src, &dest->ssa) {
      nir_instr *instr = use_src->parent_instr;

      /* src bypass check: for now only deal with tex src mov case
       * note: for alu don't bypass mov for multiple uniform sources
       */
      switch (instr->type) {
      case nir_instr_type_tex:
         if (p_instr->type == nir_instr_type_alu &&
             nir_instr_as_alu(p_instr)->op == nir_op_mov) {
            break;
         }
         FALLTHROUGH;
      default:
         can_bypass_src = false;
         break;
      }

      if (instr->type != nir_instr_type_alu)
         continue;

      nir_alu_instr *alu = nir_instr_as_alu(instr);

      switch (alu->op) {
      case nir_op_vec2:
      case nir_op_vec3:
      case nir_op_vec4:
         assert(list_length(&dest->ssa.if_uses) == 0);
         nir_foreach_use(use_src, &dest->ssa)
            assert(use_src->parent_instr == instr);

         update_swiz_mask(alu, dest, swiz, mask);
         break;
      case nir_op_mov: {
         switch (dest->ssa.parent_instr->type) {
         case nir_instr_type_alu:
         case nir_instr_type_tex:
            break;
         default:
            continue;
         }
         if (list_length(&dest->ssa.if_uses) || list_length(&dest->ssa.uses) > 1)
            continue;

         update_swiz_mask(alu, NULL, swiz, mask);
         break;
      };
      default:
         continue;
      }

      assert(!(instr->pass_flags & BYPASS_SRC));
      instr->pass_flags |= BYPASS_DST;
      return real_dest(&alu->dest.dest, swiz, mask);
   }

   if (can_bypass_src && !(p_instr->pass_flags & BYPASS_DST)) {
      p_instr->pass_flags |= BYPASS_SRC;
      return NULL;
   }

   return dest;
}

/* if instruction dest needs a register, return nir_dest for it */
static inline nir_dest *
dest_for_instr(nir_instr *instr)
{
   nir_dest *dest = NULL;

   switch (instr->type) {
   case nir_instr_type_alu:
      dest = &nir_instr_as_alu(instr)->dest.dest;
      break;
   case nir_instr_type_tex:
      dest = &nir_instr_as_tex(instr)->dest;
      break;
   case nir_instr_type_intrinsic: {
      nir_intrinsic_instr *intr = nir_instr_as_intrinsic(instr);
      if (intr->intrinsic == nir_intrinsic_load_uniform ||
          intr->intrinsic == nir_intrinsic_load_ubo ||
          intr->intrinsic == nir_intrinsic_load_input ||
          intr->intrinsic == nir_intrinsic_load_instance_id ||
          intr->intrinsic == nir_intrinsic_load_texture_rect_scaling)
         dest = &intr->dest;
   } break;
   case nir_instr_type_deref:
      return NULL;
   default:
      break;
   }
   return real_dest(dest, NULL, NULL);
}

struct live_def {
   nir_instr *instr;
   nir_dest *dest; /* cached dest_for_instr */
   unsigned live_start, live_end; /* live range */
};

unsigned
etna_live_defs(nir_function_impl *impl, struct live_def *defs, unsigned *live_map);

/* Swizzles and write masks can be used to layer virtual non-interfering
 * registers on top of the real VEC4 registers. For example, the virtual
 * VEC3_XYZ register and the virtual SCALAR_W register that use the same
 * physical VEC4 base register do not interfere.
 */
enum reg_class {
   REG_CLASS_VIRT_SCALAR,
   REG_CLASS_VIRT_VEC2,
   REG_CLASS_VIRT_VEC3,
   REG_CLASS_VEC4,
   /* special vec2 class for fast transcendentals, limited to XY or ZW */
   REG_CLASS_VIRT_VEC2T,
   /* special classes for LOAD - contiguous components */
   REG_CLASS_VIRT_VEC2C,
   REG_CLASS_VIRT_VEC3C,
   NUM_REG_CLASSES,
};

enum reg_type {
   REG_TYPE_VEC4,
   REG_TYPE_VIRT_VEC3_XYZ,
   REG_TYPE_VIRT_VEC3_XYW,
   REG_TYPE_VIRT_VEC3_XZW,
   REG_TYPE_VIRT_VEC3_YZW,
   REG_TYPE_VIRT_VEC2_XY,
   REG_TYPE_VIRT_VEC2_XZ,
   REG_TYPE_VIRT_VEC2_XW,
   REG_TYPE_VIRT_VEC2_YZ,
   REG_TYPE_VIRT_VEC2_YW,
   REG_TYPE_VIRT_VEC2_ZW,
   REG_TYPE_VIRT_SCALAR_X,
   REG_TYPE_VIRT_SCALAR_Y,
   REG_TYPE_VIRT_SCALAR_Z,
   REG_TYPE_VIRT_SCALAR_W,
   REG_TYPE_VIRT_VEC2T_XY,
   REG_TYPE_VIRT_VEC2T_ZW,
   REG_TYPE_VIRT_VEC2C_XY,
   REG_TYPE_VIRT_VEC2C_YZ,
   REG_TYPE_VIRT_VEC2C_ZW,
   REG_TYPE_VIRT_VEC3C_XYZ,
   REG_TYPE_VIRT_VEC3C_YZW,
   NUM_REG_TYPES,
};

/* writemask when used as dest */
static const uint8_t
reg_writemask[NUM_REG_TYPES] = {
   [REG_TYPE_VEC4] = 0xf,
   [REG_TYPE_VIRT_SCALAR_X] = 0x1,
   [REG_TYPE_VIRT_SCALAR_Y] = 0x2,
   [REG_TYPE_VIRT_VEC2_XY] = 0x3,
   [REG_TYPE_VIRT_VEC2T_XY] = 0x3,
   [REG_TYPE_VIRT_VEC2C_XY] = 0x3,
   [REG_TYPE_VIRT_SCALAR_Z] = 0x4,
   [REG_TYPE_VIRT_VEC2_XZ] = 0x5,
   [REG_TYPE_VIRT_VEC2_YZ] = 0x6,
   [REG_TYPE_VIRT_VEC2C_YZ] = 0x6,
   [REG_TYPE_VIRT_VEC3_XYZ] = 0x7,
   [REG_TYPE_VIRT_VEC3C_XYZ] = 0x7,
   [REG_TYPE_VIRT_SCALAR_W] = 0x8,
   [REG_TYPE_VIRT_VEC2_XW] = 0x9,
   [REG_TYPE_VIRT_VEC2_YW] = 0xa,
   [REG_TYPE_VIRT_VEC3_XYW] = 0xb,
   [REG_TYPE_VIRT_VEC2_ZW] = 0xc,
   [REG_TYPE_VIRT_VEC2T_ZW] = 0xc,
   [REG_TYPE_VIRT_VEC2C_ZW] = 0xc,
   [REG_TYPE_VIRT_VEC3_XZW] = 0xd,
   [REG_TYPE_VIRT_VEC3_YZW] = 0xe,
   [REG_TYPE_VIRT_VEC3C_YZW] = 0xe,
};

static inline int reg_get_type(int virt_reg)
{
   return virt_reg % NUM_REG_TYPES;
}

static inline int reg_get_base(struct etna_compile *c, int virt_reg)
{
   /* offset by 1 to avoid reserved position register */
   if (c->nir->info.stage == MESA_SHADER_FRAGMENT)
      return (virt_reg / NUM_REG_TYPES + 1) % ETNA_MAX_TEMPS;
   return virt_reg / NUM_REG_TYPES;
}

struct ra_regs *
etna_ra_setup(void *mem_ctx);

void
etna_ra_assign(struct etna_compile *c, nir_shader *shader);

unsigned
etna_ra_finish(struct etna_compile *c);

static inline void
emit_inst(struct etna_compile *c, struct etna_inst *inst)
{
   c->code[c->inst_ptr++] = *inst;
}

void
etna_emit_alu(struct etna_compile *c, nir_op op, struct etna_inst_dst dst,
              struct etna_inst_src src[3], bool saturate);

void
etna_emit_tex(struct etna_compile *c, nir_texop op, unsigned texid, unsigned dst_swiz,
              struct etna_inst_dst dst, struct etna_inst_src coord,
              struct etna_inst_src lod_bias, struct etna_inst_src compare);

void
etna_emit_jump(struct etna_compile *c, unsigned block, struct etna_inst_src condition);

void
etna_emit_discard(struct etna_compile *c, struct etna_inst_src condition);

#endif
