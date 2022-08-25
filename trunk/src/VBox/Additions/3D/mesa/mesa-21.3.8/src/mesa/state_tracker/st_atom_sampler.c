/**************************************************************************
 * 
 * Copyright 2007 VMware, Inc.
 * All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 **************************************************************************/

 /*
  * Authors:
  *   Keith Whitwell <keithw@vmware.com>
  *   Brian Paul
  */
 

#include "main/macros.h"
#include "main/mtypes.h"
#include "main/glformats.h"
#include "main/samplerobj.h"
#include "main/teximage.h"
#include "main/texobj.h"

#include "st_context.h"
#include "st_cb_texture.h"
#include "st_format.h"
#include "st_atom.h"
#include "st_sampler_view.h"
#include "st_texture.h"
#include "pipe/p_context.h"
#include "pipe/p_defines.h"

#include "cso_cache/cso_context.h"

#include "util/format/u_format.h"


/**
 * Convert a gl_sampler_object to a pipe_sampler_state object.
 */
void
st_convert_sampler(const struct st_context *st,
                   const struct gl_texture_object *texobj,
                   const struct gl_sampler_object *msamp,
                   float tex_unit_lod_bias,
                   struct pipe_sampler_state *sampler,
                   bool seamless_cube_map)
{
   memcpy(sampler, &msamp->Attrib.state, sizeof(*sampler));

   sampler->seamless_cube_map |= seamless_cube_map;

   if (texobj->_IsIntegerFormat && st->ctx->Const.ForceIntegerTexNearest) {
      sampler->min_img_filter = PIPE_TEX_FILTER_NEAREST;
      sampler->mag_img_filter = PIPE_TEX_FILTER_NEAREST;
   }

   if (texobj->Target != GL_TEXTURE_RECTANGLE_ARB)
      sampler->normalized_coords = 1;

   sampler->lod_bias += tex_unit_lod_bias;

   /* Check that only wrap modes using the border color have the first bit
    * set.
    */
   STATIC_ASSERT(PIPE_TEX_WRAP_CLAMP & 0x1);
   STATIC_ASSERT(PIPE_TEX_WRAP_CLAMP_TO_BORDER & 0x1);
   STATIC_ASSERT(PIPE_TEX_WRAP_MIRROR_CLAMP & 0x1);
   STATIC_ASSERT(PIPE_TEX_WRAP_MIRROR_CLAMP_TO_BORDER & 0x1);
   STATIC_ASSERT(((PIPE_TEX_WRAP_REPEAT |
                   PIPE_TEX_WRAP_CLAMP_TO_EDGE |
                   PIPE_TEX_WRAP_MIRROR_REPEAT |
                   PIPE_TEX_WRAP_MIRROR_CLAMP_TO_EDGE) & 0x1) == 0);

   /* For non-black borders... */
   if (msamp->Attrib.IsBorderColorNonZero &&
       /* This is true if wrap modes are using the border color: */
       (sampler->wrap_s | sampler->wrap_t | sampler->wrap_r) & 0x1) {
      const GLboolean is_integer = texobj->_IsIntegerFormat;
      GLenum texBaseFormat = _mesa_base_tex_image(texobj)->_BaseFormat;

      if (texobj->StencilSampling)
         texBaseFormat = GL_STENCIL_INDEX;

      if (st->apply_texture_swizzle_to_border_color) {
         const struct st_texture_object *stobj = st_texture_object_const(texobj);
         /* XXX: clean that up to not use the sampler view at all */
         const struct st_sampler_view *sv = st_texture_get_current_sampler_view(st, stobj);

         if (sv) {
            struct pipe_sampler_view *view = sv->view;
            union pipe_color_union tmp = sampler->border_color;
            const unsigned char swz[4] =
            {
               view->swizzle_r,
               view->swizzle_g,
               view->swizzle_b,
               view->swizzle_a,
            };

            st_translate_color(&tmp, texBaseFormat, is_integer);

            util_format_apply_color_swizzle(&sampler->border_color,
                                            &tmp, swz, is_integer);
         } else {
            st_translate_color(&sampler->border_color,
                               texBaseFormat, is_integer);
         }
      } else {
         st_translate_color(&sampler->border_color,
                            texBaseFormat, is_integer);
      }
      sampler->border_color_is_integer = is_integer;
   }

   /* If sampling a depth texture and using shadow comparison */
   if (msamp->Attrib.CompareMode == GL_COMPARE_R_TO_TEXTURE) {
      GLenum texBaseFormat = _mesa_base_tex_image(texobj)->_BaseFormat;

      if (texBaseFormat == GL_DEPTH_COMPONENT ||
          (texBaseFormat == GL_DEPTH_STENCIL && !texobj->StencilSampling))
         sampler->compare_mode = PIPE_TEX_COMPARE_R_TO_TEXTURE;
   }
}

/**
 * Get a pipe_sampler_state object from a texture unit.
 */
void
st_convert_sampler_from_unit(const struct st_context *st,
                             struct pipe_sampler_state *sampler,
                             GLuint texUnit)
{
   const struct gl_texture_object *texobj;
   struct gl_context *ctx = st->ctx;
   const struct gl_sampler_object *msamp;

   texobj = ctx->Texture.Unit[texUnit]._Current;
   assert(texobj);

   msamp = _mesa_get_samplerobj(ctx, texUnit);

   st_convert_sampler(st, texobj, msamp, ctx->Texture.Unit[texUnit].LodBiasQuantized,
                      sampler, ctx->Texture.CubeMapSeamless);
}


/**
 * Update the gallium driver's sampler state for fragment, vertex or
 * geometry shader stage.
 */
static void
update_shader_samplers(struct st_context *st,
                       enum pipe_shader_type shader_stage,
                       const struct gl_program *prog,
                       struct pipe_sampler_state *samplers,
                       unsigned *out_num_samplers)
{
   struct gl_context *ctx = st->ctx;
   GLbitfield samplers_used = prog->SamplersUsed;
   GLbitfield free_slots = ~prog->SamplersUsed;
   GLbitfield external_samplers_used = prog->ExternalSamplersUsed;
   unsigned unit, num_samplers;
   struct pipe_sampler_state local_samplers[PIPE_MAX_SAMPLERS];
   const struct pipe_sampler_state *states[PIPE_MAX_SAMPLERS];

   if (samplers_used == 0x0) {
      if (out_num_samplers)
         *out_num_samplers = 0;
      return;
   }

   if (!samplers)
      samplers = local_samplers;

   num_samplers = util_last_bit(samplers_used);

   /* loop over sampler units (aka tex image units) */
   for (unit = 0; samplers_used; unit++, samplers_used >>= 1) {
      struct pipe_sampler_state *sampler = samplers + unit;
      unsigned tex_unit = prog->SamplerUnits[unit];

      /* Don't update the sampler for TBOs. cso_context will not bind sampler
       * states that are NULL.
       */
      if (samplers_used & 1 &&
          (ctx->Texture.Unit[tex_unit]._Current->Target != GL_TEXTURE_BUFFER ||
           st->texture_buffer_sampler)) {
         st_convert_sampler_from_unit(st, sampler, tex_unit);
         states[unit] = sampler;
      } else {
         states[unit] = NULL;
      }
   }

   /* For any external samplers with multiplaner YUV, stuff the additional
    * sampler states we need at the end.
    *
    * Just re-use the existing sampler-state from the primary slot.
    */
   while (unlikely(external_samplers_used)) {
      GLuint unit = u_bit_scan(&external_samplers_used);
      GLuint extra = 0;
      struct st_texture_object *stObj =
            st_get_texture_object(st->ctx, prog, unit);
      struct pipe_sampler_state *sampler = samplers + unit;

      /* if resource format matches then YUV wasn't lowered */
      if (!stObj || st_get_view_format(stObj) == stObj->pt->format)
         continue;

      switch (st_get_view_format(stObj)) {
      case PIPE_FORMAT_NV12:
         if (stObj->pt->format == PIPE_FORMAT_R8_G8B8_420_UNORM)
            /* no additional views needed */
            break;
         FALLTHROUGH;
      case PIPE_FORMAT_P010:
      case PIPE_FORMAT_P012:
      case PIPE_FORMAT_P016:
      case PIPE_FORMAT_Y210:
      case PIPE_FORMAT_Y212:
      case PIPE_FORMAT_Y216:
      case PIPE_FORMAT_YUYV:
      case PIPE_FORMAT_UYVY:
         if (stObj->pt->format == PIPE_FORMAT_R8G8_R8B8_UNORM ||
             stObj->pt->format == PIPE_FORMAT_G8R8_B8R8_UNORM) {
            /* no additional views needed */
            break;
         }

         /* we need one additional sampler: */
         extra = u_bit_scan(&free_slots);
         states[extra] = sampler;
         break;
      case PIPE_FORMAT_IYUV:
         /* we need two additional samplers: */
         extra = u_bit_scan(&free_slots);
         states[extra] = sampler;
         extra = u_bit_scan(&free_slots);
         states[extra] = sampler;
         break;
      default:
         break;
      }

      num_samplers = MAX2(num_samplers, extra + 1);
   }

   cso_set_samplers(st->cso_context, shader_stage, num_samplers, states);

   if (out_num_samplers)
      *out_num_samplers = num_samplers;
}


void
st_update_vertex_samplers(struct st_context *st)
{
   const struct gl_context *ctx = st->ctx;

   update_shader_samplers(st,
                          PIPE_SHADER_VERTEX,
                          ctx->VertexProgram._Current,
                          st->state.vert_samplers,
                          &st->state.num_vert_samplers);
}


void
st_update_tessctrl_samplers(struct st_context *st)
{
   const struct gl_context *ctx = st->ctx;

   if (ctx->TessCtrlProgram._Current) {
      update_shader_samplers(st,
                             PIPE_SHADER_TESS_CTRL,
                             ctx->TessCtrlProgram._Current, NULL, NULL);
   }
}


void
st_update_tesseval_samplers(struct st_context *st)
{
   const struct gl_context *ctx = st->ctx;

   if (ctx->TessEvalProgram._Current) {
      update_shader_samplers(st,
                             PIPE_SHADER_TESS_EVAL,
                             ctx->TessEvalProgram._Current, NULL, NULL);
   }
}


void
st_update_geometry_samplers(struct st_context *st)
{
   const struct gl_context *ctx = st->ctx;

   if (ctx->GeometryProgram._Current) {
      update_shader_samplers(st,
                             PIPE_SHADER_GEOMETRY,
                             ctx->GeometryProgram._Current, NULL, NULL);
   }
}


void
st_update_fragment_samplers(struct st_context *st)
{
   const struct gl_context *ctx = st->ctx;

   update_shader_samplers(st,
                          PIPE_SHADER_FRAGMENT,
                          ctx->FragmentProgram._Current,
                          st->state.frag_samplers,
                          &st->state.num_frag_samplers);
}


void
st_update_compute_samplers(struct st_context *st)
{
   const struct gl_context *ctx = st->ctx;

   if (ctx->ComputeProgram._Current) {
      update_shader_samplers(st,
                             PIPE_SHADER_COMPUTE,
                             ctx->ComputeProgram._Current, NULL, NULL);
   }
}
