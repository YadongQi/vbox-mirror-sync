/**********************************************************
 * Copyright 2008-2009 VMware, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **********************************************************/

#include "pipe/p_defines.h"
#include "util/u_bitmask.h"
#include "util/u_format.h"
#include "util/u_inlines.h"
#include "util/u_memory.h"
#include "util/u_math.h"
#include "util/u_memory.h"

#include "svga_context.h"
#include "svga_screen.h"
#include "svga_state.h"
#include "svga_cmd.h"
#include "svga_format.h"
#include "svga_shader.h"


struct rs_queue {
   unsigned rs_count;
   SVGA3dRenderState rs[SVGA3D_RS_MAX];
};


#define EMIT_RS(svga, value, token, fail)                       \
do {                                                            \
   STATIC_ASSERT(SVGA3D_RS_##token < ARRAY_SIZE(svga->state.hw_draw.rs)); \
   if (svga->state.hw_draw.rs[SVGA3D_RS_##token] != value) {    \
      svga_queue_rs( &queue, SVGA3D_RS_##token, value );        \
      svga->state.hw_draw.rs[SVGA3D_RS_##token] = value;        \
   }                                                            \
} while (0)

#define EMIT_RS_FLOAT(svga, fvalue, token, fail)                \
do {                                                            \
   unsigned value = fui(fvalue);                                \
   STATIC_ASSERT(SVGA3D_RS_##token < ARRAY_SIZE(svga->state.hw_draw.rs)); \
   if (svga->state.hw_draw.rs[SVGA3D_RS_##token] != value) {    \
      svga_queue_rs( &queue, SVGA3D_RS_##token, value );        \
      svga->state.hw_draw.rs[SVGA3D_RS_##token] = value;        \
   }                                                            \
} while (0)


static inline void
svga_queue_rs( struct rs_queue *q,
               unsigned rss,
               unsigned value )
{
   q->rs[q->rs_count].state = rss;
   q->rs[q->rs_count].uintValue = value;
   q->rs_count++;
}


/* Compare old and new render states and emit differences between them
 * to hardware.  Simplest implementation would be to emit the whole of
 * the "to" state.
 */
static enum pipe_error
emit_rss_vgpu9(struct svga_context *svga, unsigned dirty)
{
   struct svga_screen *screen = svga_screen(svga->pipe.screen);
   struct rs_queue queue;
   float point_size_min;

   queue.rs_count = 0;

   if (dirty & (SVGA_NEW_BLEND | SVGA_NEW_BLEND_COLOR)) {
      const struct svga_blend_state *curr = svga->curr.blend;

      EMIT_RS( svga, curr->rt[0].writemask, COLORWRITEENABLE, fail );
      EMIT_RS( svga, curr->rt[0].blend_enable, BLENDENABLE, fail );

      if (curr->rt[0].blend_enable) {
         EMIT_RS( svga, curr->rt[0].srcblend, SRCBLEND, fail );
         EMIT_RS( svga, curr->rt[0].dstblend, DSTBLEND, fail );
         EMIT_RS( svga, curr->rt[0].blendeq, BLENDEQUATION, fail );

         EMIT_RS( svga, curr->rt[0].separate_alpha_blend_enable, 
                  SEPARATEALPHABLENDENABLE, fail );

         if (curr->rt[0].separate_alpha_blend_enable) {
            EMIT_RS( svga, curr->rt[0].srcblend_alpha, SRCBLENDALPHA, fail );
            EMIT_RS( svga, curr->rt[0].dstblend_alpha, DSTBLENDALPHA, fail );
            EMIT_RS( svga, curr->rt[0].blendeq_alpha, BLENDEQUATIONALPHA, fail );
         }
      }
   }

   if (dirty & SVGA_NEW_BLEND_COLOR) {
      uint32 color;
      uint32 r = float_to_ubyte(svga->curr.blend_color.color[0]);
      uint32 g = float_to_ubyte(svga->curr.blend_color.color[1]);
      uint32 b = float_to_ubyte(svga->curr.blend_color.color[2]);
      uint32 a = float_to_ubyte(svga->curr.blend_color.color[3]);

      color = (a << 24) | (r << 16) | (g << 8) | b;

      EMIT_RS( svga, color, BLENDCOLOR, fail );
   }

   if (dirty & (SVGA_NEW_DEPTH_STENCIL_ALPHA | SVGA_NEW_RAST)) {
      const struct svga_depth_stencil_state *curr = svga->curr.depth; 
      const struct svga_rasterizer_state *rast = svga->curr.rast; 

      if (!curr->stencil[0].enabled) 
      {
         /* Stencil disabled
          */
         EMIT_RS( svga, FALSE, STENCILENABLE, fail );
         EMIT_RS( svga, FALSE, STENCILENABLE2SIDED, fail );
      }
      else if (curr->stencil[0].enabled && !curr->stencil[1].enabled)
      {
         /* Regular stencil
          */
         EMIT_RS( svga, TRUE, STENCILENABLE, fail );
         EMIT_RS( svga, FALSE, STENCILENABLE2SIDED, fail );

         EMIT_RS( svga, curr->stencil[0].func,  STENCILFUNC, fail );
         EMIT_RS( svga, curr->stencil[0].fail,  STENCILFAIL, fail );
         EMIT_RS( svga, curr->stencil[0].zfail, STENCILZFAIL, fail );
         EMIT_RS( svga, curr->stencil[0].pass,  STENCILPASS, fail );

         EMIT_RS( svga, curr->stencil_mask, STENCILMASK, fail );
         EMIT_RS( svga, curr->stencil_writemask, STENCILWRITEMASK, fail );
      }
      else 
      {
         int cw, ccw;

         /* Hardware frontwinding is always CW, so if ours is also CW,
          * then our definition of front face agrees with hardware.
          * Otherwise need to flip.
          */
         if (rast->templ.front_ccw) {
            ccw = 0;
            cw = 1;
         }
         else {
            ccw = 1;
            cw = 0;
         }

         /* Twoside stencil
          */
         EMIT_RS( svga, TRUE, STENCILENABLE, fail );
         EMIT_RS( svga, TRUE, STENCILENABLE2SIDED, fail );

         EMIT_RS( svga, curr->stencil[cw].func,  STENCILFUNC, fail );
         EMIT_RS( svga, curr->stencil[cw].fail,  STENCILFAIL, fail );
         EMIT_RS( svga, curr->stencil[cw].zfail, STENCILZFAIL, fail );
         EMIT_RS( svga, curr->stencil[cw].pass,  STENCILPASS, fail );

         EMIT_RS( svga, curr->stencil[ccw].func,  CCWSTENCILFUNC, fail );
         EMIT_RS( svga, curr->stencil[ccw].fail,  CCWSTENCILFAIL, fail );
         EMIT_RS( svga, curr->stencil[ccw].zfail, CCWSTENCILZFAIL, fail );
         EMIT_RS( svga, curr->stencil[ccw].pass,  CCWSTENCILPASS, fail );

         EMIT_RS( svga, curr->stencil_mask, STENCILMASK, fail );
         EMIT_RS( svga, curr->stencil_writemask, STENCILWRITEMASK, fail );
      }

      EMIT_RS( svga, curr->zenable, ZENABLE, fail );
      if (curr->zenable) {
         EMIT_RS( svga, curr->zfunc, ZFUNC, fail );
         EMIT_RS( svga, curr->zwriteenable, ZWRITEENABLE, fail );
      }

      EMIT_RS( svga, curr->alphatestenable, ALPHATESTENABLE, fail );
      if (curr->alphatestenable) {
         EMIT_RS( svga, curr->alphafunc, ALPHAFUNC, fail );
         EMIT_RS_FLOAT( svga, curr->alpharef, ALPHAREF, fail );
      }
   }

   if (dirty & SVGA_NEW_STENCIL_REF) {
      EMIT_RS( svga, svga->curr.stencil_ref.ref_value[0], STENCILREF, fail );
   }

   if (dirty & (SVGA_NEW_RAST | SVGA_NEW_NEED_PIPELINE))
   {
      const struct svga_rasterizer_state *curr = svga->curr.rast; 
      unsigned cullmode = curr->cullmode;

      /* Shademode: still need to rearrange index list to move
       * flat-shading PV first vertex.
       */
      EMIT_RS( svga, curr->shademode, SHADEMODE, fail );

      /* Don't do culling while the software pipeline is active.  It
       * does it for us, and additionally introduces potentially
       * back-facing triangles.
       */
      if (svga->state.sw.need_pipeline)
         cullmode = SVGA3D_FACE_NONE;

      point_size_min = util_get_min_point_size(&curr->templ);

      EMIT_RS( svga, cullmode, CULLMODE, fail );
      EMIT_RS( svga, curr->scissortestenable, SCISSORTESTENABLE, fail );
      EMIT_RS( svga, curr->multisampleantialias, MULTISAMPLEANTIALIAS, fail );
      EMIT_RS( svga, curr->lastpixel, LASTPIXEL, fail );
      EMIT_RS_FLOAT( svga, curr->pointsize, POINTSIZE, fail );
      EMIT_RS_FLOAT( svga, point_size_min, POINTSIZEMIN, fail );
      EMIT_RS_FLOAT( svga, screen->maxPointSize, POINTSIZEMAX, fail );
      EMIT_RS( svga, curr->pointsprite, POINTSPRITEENABLE, fail);

      /* Emit line state, when the device understands it */
      if (screen->haveLineStipple)
         EMIT_RS( svga, curr->linepattern, LINEPATTERN, fail );
      if (screen->haveLineSmooth)
         EMIT_RS( svga, curr->antialiasedlineenable, ANTIALIASEDLINEENABLE, fail );
      if (screen->maxLineWidth > 1.0F)
         EMIT_RS_FLOAT( svga, curr->linewidth, LINEWIDTH, fail );
   }

   if (dirty & (SVGA_NEW_RAST | SVGA_NEW_FRAME_BUFFER | SVGA_NEW_NEED_PIPELINE))
   {
      const struct svga_rasterizer_state *curr = svga->curr.rast; 
      float slope = 0.0;
      float bias  = 0.0;

      /* Need to modify depth bias according to bound depthbuffer
       * format.  Don't do hardware depthbias while the software
       * pipeline is active.
       */
      if (!svga->state.sw.need_pipeline &&
          svga->curr.framebuffer.zsbuf)
      {
         slope = curr->slopescaledepthbias;
         bias  = svga->curr.depthscale * curr->depthbias;
      }

      EMIT_RS_FLOAT( svga, slope, SLOPESCALEDEPTHBIAS, fail );
      EMIT_RS_FLOAT( svga, bias, DEPTHBIAS, fail );
   }

   if (dirty & SVGA_NEW_FRAME_BUFFER) {
      /* XXX: we only look at the first color buffer's sRGB state */
      float gamma = 1.0f;
      if (svga->curr.framebuffer.cbufs[0] &&
          util_format_is_srgb(svga->curr.framebuffer.cbufs[0]->format)) {
         gamma = 2.2f;
      }
      EMIT_RS_FLOAT(svga, gamma, OUTPUTGAMMA, fail);
   }

   if (dirty & SVGA_NEW_RAST) {
      /* bitmask of the enabled clip planes */
      unsigned enabled = svga->curr.rast->templ.clip_plane_enable;
      EMIT_RS( svga, enabled, CLIPPLANEENABLE, fail );
   }

   if (queue.rs_count) {
      SVGA3dRenderState *rs;

      if (SVGA3D_BeginSetRenderState( svga->swc,
                                      &rs,
                                      queue.rs_count ) != PIPE_OK)
         goto fail;

      memcpy( rs,
              queue.rs,
              queue.rs_count * sizeof queue.rs[0]);

      SVGA_FIFOCommitAll( svga->swc );
   }

   return PIPE_OK;

fail:
   /* XXX: need to poison cached hardware state on failure to ensure
    * dirty state gets re-emitted.  Fix this by re-instating partial
    * FIFOCommit command and only updating cached hw state once the
    * initial allocation has succeeded.
    */
   memset(svga->state.hw_draw.rs, 0xcd, sizeof(svga->state.hw_draw.rs));

   return PIPE_ERROR_OUT_OF_MEMORY;
}

/** Returns a non-culling rasterizer state object to be used with
 *  point sprite.
 */
static struct svga_rasterizer_state *
get_no_cull_rasterizer_state(struct svga_context *svga)
{
   const struct svga_rasterizer_state *r = svga->curr.rast;
   unsigned int aa_point = r->templ.point_smooth;

   if (!svga->rasterizer_no_cull[aa_point]) {
      struct pipe_rasterizer_state rast;

      memset(&rast, 0, sizeof(rast));
      rast.flatshade = 1;
      rast.front_ccw = 1;
      rast.point_smooth = r->templ.point_smooth;

      /* All rasterizer states have the same half_pixel_center,
       * bottom_edge_rule and clip_halfz values since they are
       * constant for a context. If we ever implement
       * GL_ARB_clip_control, the clip_halfz field would have to be observed.
       */
      rast.half_pixel_center = r->templ.half_pixel_center;
      rast.bottom_edge_rule = r->templ.bottom_edge_rule;
      rast.clip_halfz = r->templ.clip_halfz;

      svga->rasterizer_no_cull[aa_point] =
               svga->pipe.create_rasterizer_state(&svga->pipe, &rast);
   }
   return svga->rasterizer_no_cull[aa_point];
}


/** Returns a depth stencil state object with depth and stencil test disabled.
 */
static struct svga_depth_stencil_state *
get_no_depth_stencil_test_state(struct svga_context *svga)
{
   if (!svga->depthstencil_disable) {
      struct pipe_depth_stencil_alpha_state ds = {{0}};
      svga->depthstencil_disable =
         svga->pipe.create_depth_stencil_alpha_state(&svga->pipe, &ds);
   }
   return svga->depthstencil_disable;
}


static enum pipe_error
emit_rss_vgpu10(struct svga_context *svga, unsigned dirty)
{
   enum pipe_error ret = PIPE_OK;

   svga_hwtnl_flush_retry(svga);

   if (dirty & (SVGA_NEW_BLEND | SVGA_NEW_BLEND_COLOR)) {
      const struct svga_blend_state *curr;
      float blend_factor[4];

      if (svga_has_any_integer_cbufs(svga)) {
         /* Blending is not supported in integer-valued render targets. */
         curr = svga->noop_blend;
         blend_factor[0] =
         blend_factor[1] =
         blend_factor[2] =
         blend_factor[3] = 0;
      }
      else {
         curr = svga->curr.blend;

         if (curr->blend_color_alpha) {
            blend_factor[0] =
            blend_factor[1] =
            blend_factor[2] =
            blend_factor[3] = svga->curr.blend_color.color[3];
         }
         else {
            blend_factor[0] = svga->curr.blend_color.color[0];
            blend_factor[1] = svga->curr.blend_color.color[1];
            blend_factor[2] = svga->curr.blend_color.color[2];
            blend_factor[3] = svga->curr.blend_color.color[3];
         }
      }

      /* Set/bind the blend state object */
      if (svga->state.hw_draw.blend_id != curr->id ||
          svga->state.hw_draw.blend_factor[0] != blend_factor[0] ||
          svga->state.hw_draw.blend_factor[1] != blend_factor[1] ||
          svga->state.hw_draw.blend_factor[2] != blend_factor[2] ||
          svga->state.hw_draw.blend_factor[3] != blend_factor[3] ||
          svga->state.hw_draw.blend_sample_mask != svga->curr.sample_mask) {
         ret = SVGA3D_vgpu10_SetBlendState(svga->swc, curr->id,
                                           blend_factor,
                                           svga->curr.sample_mask);
         if (ret != PIPE_OK)
            return ret;

         svga->state.hw_draw.blend_id = curr->id;
         svga->state.hw_draw.blend_factor[0] = blend_factor[0];
         svga->state.hw_draw.blend_factor[1] = blend_factor[1];
         svga->state.hw_draw.blend_factor[2] = blend_factor[2];
         svga->state.hw_draw.blend_factor[3] = blend_factor[3];
         svga->state.hw_draw.blend_sample_mask = svga->curr.sample_mask;
      }
   }

   if (svga->disable_rasterizer) {
      if (!svga->state.hw_draw.rasterizer_discard) {
         struct svga_depth_stencil_state *ds;

         /* If rasterization is to be disabled, disable depth and stencil
          * testing as well.
          */
         ds = get_no_depth_stencil_test_state(svga);
         if (ds->id != svga->state.hw_draw.depth_stencil_id) {
            ret = SVGA3D_vgpu10_SetDepthStencilState(svga->swc, ds->id, 0);
            if (ret != PIPE_OK)
               return ret;

            svga->state.hw_draw.depth_stencil_id = ds->id;
            svga->state.hw_draw.stencil_ref = 0;
         }
         svga->state.hw_draw.rasterizer_discard = TRUE;
      }
   } else {
      if ((dirty & (SVGA_NEW_DEPTH_STENCIL_ALPHA | SVGA_NEW_STENCIL_REF)) ||
          svga->state.hw_draw.rasterizer_discard) {
         const struct svga_depth_stencil_state *curr = svga->curr.depth;
         unsigned curr_ref = svga->curr.stencil_ref.ref_value[0];

         if (curr->id != svga->state.hw_draw.depth_stencil_id ||
             curr_ref != svga->state.hw_draw.stencil_ref) {
            /* Set/bind the depth/stencil state object */
            ret = SVGA3D_vgpu10_SetDepthStencilState(svga->swc, curr->id,
                                                     curr_ref);
            if (ret != PIPE_OK)
               return ret;

            svga->state.hw_draw.depth_stencil_id = curr->id;
            svga->state.hw_draw.stencil_ref = curr_ref;
         }
      }

      if (dirty & (SVGA_NEW_REDUCED_PRIMITIVE | SVGA_NEW_RAST)) {
         const struct svga_rasterizer_state *rast;

         if (svga->curr.reduced_prim == PIPE_PRIM_POINTS &&
             svga->curr.gs && svga->curr.gs->wide_point) {

            /* If we are drawing a point sprite, we will need to
             * bind a non-culling rasterizer state object
             */
            rast = get_no_cull_rasterizer_state(svga);
         }
         else {
            rast = svga->curr.rast;
         }

         if (svga->state.hw_draw.rasterizer_id != rast->id) {
            /* Set/bind the rasterizer state object */
            ret = SVGA3D_vgpu10_SetRasterizerState(svga->swc, rast->id);
            if (ret != PIPE_OK)
               return ret;
            svga->state.hw_draw.rasterizer_id = rast->id;
         }
      }
      svga->state.hw_draw.rasterizer_discard = FALSE;
   }
   return PIPE_OK;
}


static enum pipe_error
emit_rss(struct svga_context *svga, unsigned dirty)
{
   if (svga_have_vgpu10(svga)) {
      return emit_rss_vgpu10(svga, dirty);
   }
   else {
      return emit_rss_vgpu9(svga, dirty);
   }
}


struct svga_tracked_state svga_hw_rss = 
{
   "hw rss state",

   (SVGA_NEW_BLEND |
    SVGA_NEW_BLEND_COLOR |
    SVGA_NEW_DEPTH_STENCIL_ALPHA |
    SVGA_NEW_STENCIL_REF |
    SVGA_NEW_RAST |
    SVGA_NEW_FRAME_BUFFER |
    SVGA_NEW_NEED_PIPELINE |
    SVGA_NEW_FS |
    SVGA_NEW_REDUCED_PRIMITIVE),

   emit_rss
};
