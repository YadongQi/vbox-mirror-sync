#define LOCAL_VARS                           \
   char *verts = (char *) vertices;          \
   const boolean quads_flatshade_last =      \
      draw->quads_always_flatshade_last;     \
   const boolean last_vertex_last =          \
      !draw->rasterizer->flatshade_first;

#include "draw_decompose_tmp.h"
