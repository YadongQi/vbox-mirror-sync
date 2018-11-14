/* DO NOT EDIT - This file generated automatically by gl_table.py (from Mesa) script */

/*
 * (C) Copyright IBM Corporation 2005
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
 * IBM,
 * AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#if !defined( _DISPATCH_H_ )
#  define _DISPATCH_H_


/**
 * \file main/dispatch.h
 * Macros for handling GL dispatch tables.
 *
 * For each known GL function, there are 3 macros in this file.  The first
 * macro is named CALL_FuncName and is used to call that GL function using
 * the specified dispatch table.  The other 2 macros, called GET_FuncName
 * can SET_FuncName, are used to get and set the dispatch pointer for the
 * named function in the specified dispatch table.
 */

#define CALL_by_offset(disp, cast, offset, parameters) \
    (*(cast (GET_by_offset(disp, offset)))) parameters
#define GET_by_offset(disp, offset) \
    (offset >= 0) ? (((_glapi_proc *)(disp))[offset]) : NULL
#define SET_by_offset(disp, offset, fn) \
    do { \
        if ( (offset) < 0 ) { \
            /* fprintf( stderr, "[%s:%u] SET_by_offset(%p, %d, %s)!\n", */ \
            /*         __func__, __LINE__, disp, offset, # fn); */ \
            /* abort(); */ \
        } \
        else { \
            ( (_glapi_proc *) (disp) )[offset] = (_glapi_proc) fn; \
        } \
    } while(0)

/* total number of offsets below */
#define _gloffset_COUNT 1410

#define _gloffset_NewList 0
#define _gloffset_EndList 1
#define _gloffset_CallList 2
#define _gloffset_CallLists 3
#define _gloffset_DeleteLists 4
#define _gloffset_GenLists 5
#define _gloffset_ListBase 6
#define _gloffset_Begin 7
#define _gloffset_Bitmap 8
#define _gloffset_Color3b 9
#define _gloffset_Color3bv 10
#define _gloffset_Color3d 11
#define _gloffset_Color3dv 12
#define _gloffset_Color3f 13
#define _gloffset_Color3fv 14
#define _gloffset_Color3i 15
#define _gloffset_Color3iv 16
#define _gloffset_Color3s 17
#define _gloffset_Color3sv 18
#define _gloffset_Color3ub 19
#define _gloffset_Color3ubv 20
#define _gloffset_Color3ui 21
#define _gloffset_Color3uiv 22
#define _gloffset_Color3us 23
#define _gloffset_Color3usv 24
#define _gloffset_Color4b 25
#define _gloffset_Color4bv 26
#define _gloffset_Color4d 27
#define _gloffset_Color4dv 28
#define _gloffset_Color4f 29
#define _gloffset_Color4fv 30
#define _gloffset_Color4i 31
#define _gloffset_Color4iv 32
#define _gloffset_Color4s 33
#define _gloffset_Color4sv 34
#define _gloffset_Color4ub 35
#define _gloffset_Color4ubv 36
#define _gloffset_Color4ui 37
#define _gloffset_Color4uiv 38
#define _gloffset_Color4us 39
#define _gloffset_Color4usv 40
#define _gloffset_EdgeFlag 41
#define _gloffset_EdgeFlagv 42
#define _gloffset_End 43
#define _gloffset_Indexd 44
#define _gloffset_Indexdv 45
#define _gloffset_Indexf 46
#define _gloffset_Indexfv 47
#define _gloffset_Indexi 48
#define _gloffset_Indexiv 49
#define _gloffset_Indexs 50
#define _gloffset_Indexsv 51
#define _gloffset_Normal3b 52
#define _gloffset_Normal3bv 53
#define _gloffset_Normal3d 54
#define _gloffset_Normal3dv 55
#define _gloffset_Normal3f 56
#define _gloffset_Normal3fv 57
#define _gloffset_Normal3i 58
#define _gloffset_Normal3iv 59
#define _gloffset_Normal3s 60
#define _gloffset_Normal3sv 61
#define _gloffset_RasterPos2d 62
#define _gloffset_RasterPos2dv 63
#define _gloffset_RasterPos2f 64
#define _gloffset_RasterPos2fv 65
#define _gloffset_RasterPos2i 66
#define _gloffset_RasterPos2iv 67
#define _gloffset_RasterPos2s 68
#define _gloffset_RasterPos2sv 69
#define _gloffset_RasterPos3d 70
#define _gloffset_RasterPos3dv 71
#define _gloffset_RasterPos3f 72
#define _gloffset_RasterPos3fv 73
#define _gloffset_RasterPos3i 74
#define _gloffset_RasterPos3iv 75
#define _gloffset_RasterPos3s 76
#define _gloffset_RasterPos3sv 77
#define _gloffset_RasterPos4d 78
#define _gloffset_RasterPos4dv 79
#define _gloffset_RasterPos4f 80
#define _gloffset_RasterPos4fv 81
#define _gloffset_RasterPos4i 82
#define _gloffset_RasterPos4iv 83
#define _gloffset_RasterPos4s 84
#define _gloffset_RasterPos4sv 85
#define _gloffset_Rectd 86
#define _gloffset_Rectdv 87
#define _gloffset_Rectf 88
#define _gloffset_Rectfv 89
#define _gloffset_Recti 90
#define _gloffset_Rectiv 91
#define _gloffset_Rects 92
#define _gloffset_Rectsv 93
#define _gloffset_TexCoord1d 94
#define _gloffset_TexCoord1dv 95
#define _gloffset_TexCoord1f 96
#define _gloffset_TexCoord1fv 97
#define _gloffset_TexCoord1i 98
#define _gloffset_TexCoord1iv 99
#define _gloffset_TexCoord1s 100
#define _gloffset_TexCoord1sv 101
#define _gloffset_TexCoord2d 102
#define _gloffset_TexCoord2dv 103
#define _gloffset_TexCoord2f 104
#define _gloffset_TexCoord2fv 105
#define _gloffset_TexCoord2i 106
#define _gloffset_TexCoord2iv 107
#define _gloffset_TexCoord2s 108
#define _gloffset_TexCoord2sv 109
#define _gloffset_TexCoord3d 110
#define _gloffset_TexCoord3dv 111
#define _gloffset_TexCoord3f 112
#define _gloffset_TexCoord3fv 113
#define _gloffset_TexCoord3i 114
#define _gloffset_TexCoord3iv 115
#define _gloffset_TexCoord3s 116
#define _gloffset_TexCoord3sv 117
#define _gloffset_TexCoord4d 118
#define _gloffset_TexCoord4dv 119
#define _gloffset_TexCoord4f 120
#define _gloffset_TexCoord4fv 121
#define _gloffset_TexCoord4i 122
#define _gloffset_TexCoord4iv 123
#define _gloffset_TexCoord4s 124
#define _gloffset_TexCoord4sv 125
#define _gloffset_Vertex2d 126
#define _gloffset_Vertex2dv 127
#define _gloffset_Vertex2f 128
#define _gloffset_Vertex2fv 129
#define _gloffset_Vertex2i 130
#define _gloffset_Vertex2iv 131
#define _gloffset_Vertex2s 132
#define _gloffset_Vertex2sv 133
#define _gloffset_Vertex3d 134
#define _gloffset_Vertex3dv 135
#define _gloffset_Vertex3f 136
#define _gloffset_Vertex3fv 137
#define _gloffset_Vertex3i 138
#define _gloffset_Vertex3iv 139
#define _gloffset_Vertex3s 140
#define _gloffset_Vertex3sv 141
#define _gloffset_Vertex4d 142
#define _gloffset_Vertex4dv 143
#define _gloffset_Vertex4f 144
#define _gloffset_Vertex4fv 145
#define _gloffset_Vertex4i 146
#define _gloffset_Vertex4iv 147
#define _gloffset_Vertex4s 148
#define _gloffset_Vertex4sv 149
#define _gloffset_ClipPlane 150
#define _gloffset_ColorMaterial 151
#define _gloffset_CullFace 152
#define _gloffset_Fogf 153
#define _gloffset_Fogfv 154
#define _gloffset_Fogi 155
#define _gloffset_Fogiv 156
#define _gloffset_FrontFace 157
#define _gloffset_Hint 158
#define _gloffset_Lightf 159
#define _gloffset_Lightfv 160
#define _gloffset_Lighti 161
#define _gloffset_Lightiv 162
#define _gloffset_LightModelf 163
#define _gloffset_LightModelfv 164
#define _gloffset_LightModeli 165
#define _gloffset_LightModeliv 166
#define _gloffset_LineStipple 167
#define _gloffset_LineWidth 168
#define _gloffset_Materialf 169
#define _gloffset_Materialfv 170
#define _gloffset_Materiali 171
#define _gloffset_Materialiv 172
#define _gloffset_PointSize 173
#define _gloffset_PolygonMode 174
#define _gloffset_PolygonStipple 175
#define _gloffset_Scissor 176
#define _gloffset_ShadeModel 177
#define _gloffset_TexParameterf 178
#define _gloffset_TexParameterfv 179
#define _gloffset_TexParameteri 180
#define _gloffset_TexParameteriv 181
#define _gloffset_TexImage1D 182
#define _gloffset_TexImage2D 183
#define _gloffset_TexEnvf 184
#define _gloffset_TexEnvfv 185
#define _gloffset_TexEnvi 186
#define _gloffset_TexEnviv 187
#define _gloffset_TexGend 188
#define _gloffset_TexGendv 189
#define _gloffset_TexGenf 190
#define _gloffset_TexGenfv 191
#define _gloffset_TexGeni 192
#define _gloffset_TexGeniv 193
#define _gloffset_FeedbackBuffer 194
#define _gloffset_SelectBuffer 195
#define _gloffset_RenderMode 196
#define _gloffset_InitNames 197
#define _gloffset_LoadName 198
#define _gloffset_PassThrough 199
#define _gloffset_PopName 200
#define _gloffset_PushName 201
#define _gloffset_DrawBuffer 202
#define _gloffset_Clear 203
#define _gloffset_ClearAccum 204
#define _gloffset_ClearIndex 205
#define _gloffset_ClearColor 206
#define _gloffset_ClearStencil 207
#define _gloffset_ClearDepth 208
#define _gloffset_StencilMask 209
#define _gloffset_ColorMask 210
#define _gloffset_DepthMask 211
#define _gloffset_IndexMask 212
#define _gloffset_Accum 213
#define _gloffset_Disable 214
#define _gloffset_Enable 215
#define _gloffset_Finish 216
#define _gloffset_Flush 217
#define _gloffset_PopAttrib 218
#define _gloffset_PushAttrib 219
#define _gloffset_Map1d 220
#define _gloffset_Map1f 221
#define _gloffset_Map2d 222
#define _gloffset_Map2f 223
#define _gloffset_MapGrid1d 224
#define _gloffset_MapGrid1f 225
#define _gloffset_MapGrid2d 226
#define _gloffset_MapGrid2f 227
#define _gloffset_EvalCoord1d 228
#define _gloffset_EvalCoord1dv 229
#define _gloffset_EvalCoord1f 230
#define _gloffset_EvalCoord1fv 231
#define _gloffset_EvalCoord2d 232
#define _gloffset_EvalCoord2dv 233
#define _gloffset_EvalCoord2f 234
#define _gloffset_EvalCoord2fv 235
#define _gloffset_EvalMesh1 236
#define _gloffset_EvalPoint1 237
#define _gloffset_EvalMesh2 238
#define _gloffset_EvalPoint2 239
#define _gloffset_AlphaFunc 240
#define _gloffset_BlendFunc 241
#define _gloffset_LogicOp 242
#define _gloffset_StencilFunc 243
#define _gloffset_StencilOp 244
#define _gloffset_DepthFunc 245
#define _gloffset_PixelZoom 246
#define _gloffset_PixelTransferf 247
#define _gloffset_PixelTransferi 248
#define _gloffset_PixelStoref 249
#define _gloffset_PixelStorei 250
#define _gloffset_PixelMapfv 251
#define _gloffset_PixelMapuiv 252
#define _gloffset_PixelMapusv 253
#define _gloffset_ReadBuffer 254
#define _gloffset_CopyPixels 255
#define _gloffset_ReadPixels 256
#define _gloffset_DrawPixels 257
#define _gloffset_GetBooleanv 258
#define _gloffset_GetClipPlane 259
#define _gloffset_GetDoublev 260
#define _gloffset_GetError 261
#define _gloffset_GetFloatv 262
#define _gloffset_GetIntegerv 263
#define _gloffset_GetLightfv 264
#define _gloffset_GetLightiv 265
#define _gloffset_GetMapdv 266
#define _gloffset_GetMapfv 267
#define _gloffset_GetMapiv 268
#define _gloffset_GetMaterialfv 269
#define _gloffset_GetMaterialiv 270
#define _gloffset_GetPixelMapfv 271
#define _gloffset_GetPixelMapuiv 272
#define _gloffset_GetPixelMapusv 273
#define _gloffset_GetPolygonStipple 274
#define _gloffset_GetString 275
#define _gloffset_GetTexEnvfv 276
#define _gloffset_GetTexEnviv 277
#define _gloffset_GetTexGendv 278
#define _gloffset_GetTexGenfv 279
#define _gloffset_GetTexGeniv 280
#define _gloffset_GetTexImage 281
#define _gloffset_GetTexParameterfv 282
#define _gloffset_GetTexParameteriv 283
#define _gloffset_GetTexLevelParameterfv 284
#define _gloffset_GetTexLevelParameteriv 285
#define _gloffset_IsEnabled 286
#define _gloffset_IsList 287
#define _gloffset_DepthRange 288
#define _gloffset_Frustum 289
#define _gloffset_LoadIdentity 290
#define _gloffset_LoadMatrixf 291
#define _gloffset_LoadMatrixd 292
#define _gloffset_MatrixMode 293
#define _gloffset_MultMatrixf 294
#define _gloffset_MultMatrixd 295
#define _gloffset_Ortho 296
#define _gloffset_PopMatrix 297
#define _gloffset_PushMatrix 298
#define _gloffset_Rotated 299
#define _gloffset_Rotatef 300
#define _gloffset_Scaled 301
#define _gloffset_Scalef 302
#define _gloffset_Translated 303
#define _gloffset_Translatef 304
#define _gloffset_Viewport 305
#define _gloffset_ArrayElement 306
#define _gloffset_BindTexture 307
#define _gloffset_ColorPointer 308
#define _gloffset_DisableClientState 309
#define _gloffset_DrawArrays 310
#define _gloffset_DrawElements 311
#define _gloffset_EdgeFlagPointer 312
#define _gloffset_EnableClientState 313
#define _gloffset_IndexPointer 314
#define _gloffset_Indexub 315
#define _gloffset_Indexubv 316
#define _gloffset_InterleavedArrays 317
#define _gloffset_NormalPointer 318
#define _gloffset_PolygonOffset 319
#define _gloffset_TexCoordPointer 320
#define _gloffset_VertexPointer 321
#define _gloffset_AreTexturesResident 322
#define _gloffset_CopyTexImage1D 323
#define _gloffset_CopyTexImage2D 324
#define _gloffset_CopyTexSubImage1D 325
#define _gloffset_CopyTexSubImage2D 326
#define _gloffset_DeleteTextures 327
#define _gloffset_GenTextures 328
#define _gloffset_GetPointerv 329
#define _gloffset_IsTexture 330
#define _gloffset_PrioritizeTextures 331
#define _gloffset_TexSubImage1D 332
#define _gloffset_TexSubImage2D 333
#define _gloffset_PopClientAttrib 334
#define _gloffset_PushClientAttrib 335
#define _gloffset_BlendColor 336
#define _gloffset_BlendEquation 337
#define _gloffset_DrawRangeElements 338
#define _gloffset_ColorTable 339
#define _gloffset_ColorTableParameterfv 340
#define _gloffset_ColorTableParameteriv 341
#define _gloffset_CopyColorTable 342
#define _gloffset_GetColorTable 343
#define _gloffset_GetColorTableParameterfv 344
#define _gloffset_GetColorTableParameteriv 345
#define _gloffset_ColorSubTable 346
#define _gloffset_CopyColorSubTable 347
#define _gloffset_ConvolutionFilter1D 348
#define _gloffset_ConvolutionFilter2D 349
#define _gloffset_ConvolutionParameterf 350
#define _gloffset_ConvolutionParameterfv 351
#define _gloffset_ConvolutionParameteri 352
#define _gloffset_ConvolutionParameteriv 353
#define _gloffset_CopyConvolutionFilter1D 354
#define _gloffset_CopyConvolutionFilter2D 355
#define _gloffset_GetConvolutionFilter 356
#define _gloffset_GetConvolutionParameterfv 357
#define _gloffset_GetConvolutionParameteriv 358
#define _gloffset_GetSeparableFilter 359
#define _gloffset_SeparableFilter2D 360
#define _gloffset_GetHistogram 361
#define _gloffset_GetHistogramParameterfv 362
#define _gloffset_GetHistogramParameteriv 363
#define _gloffset_GetMinmax 364
#define _gloffset_GetMinmaxParameterfv 365
#define _gloffset_GetMinmaxParameteriv 366
#define _gloffset_Histogram 367
#define _gloffset_Minmax 368
#define _gloffset_ResetHistogram 369
#define _gloffset_ResetMinmax 370
#define _gloffset_TexImage3D 371
#define _gloffset_TexSubImage3D 372
#define _gloffset_CopyTexSubImage3D 373
#define _gloffset_ActiveTexture 374
#define _gloffset_ClientActiveTexture 375
#define _gloffset_MultiTexCoord1d 376
#define _gloffset_MultiTexCoord1dv 377
#define _gloffset_MultiTexCoord1fARB 378
#define _gloffset_MultiTexCoord1fvARB 379
#define _gloffset_MultiTexCoord1i 380
#define _gloffset_MultiTexCoord1iv 381
#define _gloffset_MultiTexCoord1s 382
#define _gloffset_MultiTexCoord1sv 383
#define _gloffset_MultiTexCoord2d 384
#define _gloffset_MultiTexCoord2dv 385
#define _gloffset_MultiTexCoord2fARB 386
#define _gloffset_MultiTexCoord2fvARB 387
#define _gloffset_MultiTexCoord2i 388
#define _gloffset_MultiTexCoord2iv 389
#define _gloffset_MultiTexCoord2s 390
#define _gloffset_MultiTexCoord2sv 391
#define _gloffset_MultiTexCoord3d 392
#define _gloffset_MultiTexCoord3dv 393
#define _gloffset_MultiTexCoord3fARB 394
#define _gloffset_MultiTexCoord3fvARB 395
#define _gloffset_MultiTexCoord3i 396
#define _gloffset_MultiTexCoord3iv 397
#define _gloffset_MultiTexCoord3s 398
#define _gloffset_MultiTexCoord3sv 399
#define _gloffset_MultiTexCoord4d 400
#define _gloffset_MultiTexCoord4dv 401
#define _gloffset_MultiTexCoord4fARB 402
#define _gloffset_MultiTexCoord4fvARB 403
#define _gloffset_MultiTexCoord4i 404
#define _gloffset_MultiTexCoord4iv 405
#define _gloffset_MultiTexCoord4s 406
#define _gloffset_MultiTexCoord4sv 407
#define driDispatchRemapTable_size 1002
extern int driDispatchRemapTable[ driDispatchRemapTable_size ];

#define CompressedTexImage1D_remap_index 0
#define CompressedTexImage2D_remap_index 1
#define CompressedTexImage3D_remap_index 2
#define CompressedTexSubImage1D_remap_index 3
#define CompressedTexSubImage2D_remap_index 4
#define CompressedTexSubImage3D_remap_index 5
#define GetCompressedTexImage_remap_index 6
#define LoadTransposeMatrixd_remap_index 7
#define LoadTransposeMatrixf_remap_index 8
#define MultTransposeMatrixd_remap_index 9
#define MultTransposeMatrixf_remap_index 10
#define SampleCoverage_remap_index 11
#define BlendFuncSeparate_remap_index 12
#define FogCoordPointer_remap_index 13
#define FogCoordd_remap_index 14
#define FogCoorddv_remap_index 15
#define MultiDrawArrays_remap_index 16
#define PointParameterf_remap_index 17
#define PointParameterfv_remap_index 18
#define PointParameteri_remap_index 19
#define PointParameteriv_remap_index 20
#define SecondaryColor3b_remap_index 21
#define SecondaryColor3bv_remap_index 22
#define SecondaryColor3d_remap_index 23
#define SecondaryColor3dv_remap_index 24
#define SecondaryColor3i_remap_index 25
#define SecondaryColor3iv_remap_index 26
#define SecondaryColor3s_remap_index 27
#define SecondaryColor3sv_remap_index 28
#define SecondaryColor3ub_remap_index 29
#define SecondaryColor3ubv_remap_index 30
#define SecondaryColor3ui_remap_index 31
#define SecondaryColor3uiv_remap_index 32
#define SecondaryColor3us_remap_index 33
#define SecondaryColor3usv_remap_index 34
#define SecondaryColorPointer_remap_index 35
#define WindowPos2d_remap_index 36
#define WindowPos2dv_remap_index 37
#define WindowPos2f_remap_index 38
#define WindowPos2fv_remap_index 39
#define WindowPos2i_remap_index 40
#define WindowPos2iv_remap_index 41
#define WindowPos2s_remap_index 42
#define WindowPos2sv_remap_index 43
#define WindowPos3d_remap_index 44
#define WindowPos3dv_remap_index 45
#define WindowPos3f_remap_index 46
#define WindowPos3fv_remap_index 47
#define WindowPos3i_remap_index 48
#define WindowPos3iv_remap_index 49
#define WindowPos3s_remap_index 50
#define WindowPos3sv_remap_index 51
#define BeginQuery_remap_index 52
#define BindBuffer_remap_index 53
#define BufferData_remap_index 54
#define BufferSubData_remap_index 55
#define DeleteBuffers_remap_index 56
#define DeleteQueries_remap_index 57
#define EndQuery_remap_index 58
#define GenBuffers_remap_index 59
#define GenQueries_remap_index 60
#define GetBufferParameteriv_remap_index 61
#define GetBufferPointerv_remap_index 62
#define GetBufferSubData_remap_index 63
#define GetQueryObjectiv_remap_index 64
#define GetQueryObjectuiv_remap_index 65
#define GetQueryiv_remap_index 66
#define IsBuffer_remap_index 67
#define IsQuery_remap_index 68
#define MapBuffer_remap_index 69
#define UnmapBuffer_remap_index 70
#define AttachShader_remap_index 71
#define BindAttribLocation_remap_index 72
#define BlendEquationSeparate_remap_index 73
#define CompileShader_remap_index 74
#define CreateProgram_remap_index 75
#define CreateShader_remap_index 76
#define DeleteProgram_remap_index 77
#define DeleteShader_remap_index 78
#define DetachShader_remap_index 79
#define DisableVertexAttribArray_remap_index 80
#define DrawBuffers_remap_index 81
#define EnableVertexAttribArray_remap_index 82
#define GetActiveAttrib_remap_index 83
#define GetActiveUniform_remap_index 84
#define GetAttachedShaders_remap_index 85
#define GetAttribLocation_remap_index 86
#define GetProgramInfoLog_remap_index 87
#define GetProgramiv_remap_index 88
#define GetShaderInfoLog_remap_index 89
#define GetShaderSource_remap_index 90
#define GetShaderiv_remap_index 91
#define GetUniformLocation_remap_index 92
#define GetUniformfv_remap_index 93
#define GetUniformiv_remap_index 94
#define GetVertexAttribPointerv_remap_index 95
#define GetVertexAttribdv_remap_index 96
#define GetVertexAttribfv_remap_index 97
#define GetVertexAttribiv_remap_index 98
#define IsProgram_remap_index 99
#define IsShader_remap_index 100
#define LinkProgram_remap_index 101
#define ShaderSource_remap_index 102
#define StencilFuncSeparate_remap_index 103
#define StencilMaskSeparate_remap_index 104
#define StencilOpSeparate_remap_index 105
#define Uniform1f_remap_index 106
#define Uniform1fv_remap_index 107
#define Uniform1i_remap_index 108
#define Uniform1iv_remap_index 109
#define Uniform2f_remap_index 110
#define Uniform2fv_remap_index 111
#define Uniform2i_remap_index 112
#define Uniform2iv_remap_index 113
#define Uniform3f_remap_index 114
#define Uniform3fv_remap_index 115
#define Uniform3i_remap_index 116
#define Uniform3iv_remap_index 117
#define Uniform4f_remap_index 118
#define Uniform4fv_remap_index 119
#define Uniform4i_remap_index 120
#define Uniform4iv_remap_index 121
#define UniformMatrix2fv_remap_index 122
#define UniformMatrix3fv_remap_index 123
#define UniformMatrix4fv_remap_index 124
#define UseProgram_remap_index 125
#define ValidateProgram_remap_index 126
#define VertexAttrib1d_remap_index 127
#define VertexAttrib1dv_remap_index 128
#define VertexAttrib1s_remap_index 129
#define VertexAttrib1sv_remap_index 130
#define VertexAttrib2d_remap_index 131
#define VertexAttrib2dv_remap_index 132
#define VertexAttrib2s_remap_index 133
#define VertexAttrib2sv_remap_index 134
#define VertexAttrib3d_remap_index 135
#define VertexAttrib3dv_remap_index 136
#define VertexAttrib3s_remap_index 137
#define VertexAttrib3sv_remap_index 138
#define VertexAttrib4Nbv_remap_index 139
#define VertexAttrib4Niv_remap_index 140
#define VertexAttrib4Nsv_remap_index 141
#define VertexAttrib4Nub_remap_index 142
#define VertexAttrib4Nubv_remap_index 143
#define VertexAttrib4Nuiv_remap_index 144
#define VertexAttrib4Nusv_remap_index 145
#define VertexAttrib4bv_remap_index 146
#define VertexAttrib4d_remap_index 147
#define VertexAttrib4dv_remap_index 148
#define VertexAttrib4iv_remap_index 149
#define VertexAttrib4s_remap_index 150
#define VertexAttrib4sv_remap_index 151
#define VertexAttrib4ubv_remap_index 152
#define VertexAttrib4uiv_remap_index 153
#define VertexAttrib4usv_remap_index 154
#define VertexAttribPointer_remap_index 155
#define UniformMatrix2x3fv_remap_index 156
#define UniformMatrix2x4fv_remap_index 157
#define UniformMatrix3x2fv_remap_index 158
#define UniformMatrix3x4fv_remap_index 159
#define UniformMatrix4x2fv_remap_index 160
#define UniformMatrix4x3fv_remap_index 161
#define BeginConditionalRender_remap_index 162
#define BeginTransformFeedback_remap_index 163
#define BindBufferBase_remap_index 164
#define BindBufferRange_remap_index 165
#define BindFragDataLocation_remap_index 166
#define ClampColor_remap_index 167
#define ClearBufferfi_remap_index 168
#define ClearBufferfv_remap_index 169
#define ClearBufferiv_remap_index 170
#define ClearBufferuiv_remap_index 171
#define ColorMaski_remap_index 172
#define Disablei_remap_index 173
#define Enablei_remap_index 174
#define EndConditionalRender_remap_index 175
#define EndTransformFeedback_remap_index 176
#define GetBooleani_v_remap_index 177
#define GetFragDataLocation_remap_index 178
#define GetIntegeri_v_remap_index 179
#define GetStringi_remap_index 180
#define GetTexParameterIiv_remap_index 181
#define GetTexParameterIuiv_remap_index 182
#define GetTransformFeedbackVarying_remap_index 183
#define GetUniformuiv_remap_index 184
#define GetVertexAttribIiv_remap_index 185
#define GetVertexAttribIuiv_remap_index 186
#define IsEnabledi_remap_index 187
#define TexParameterIiv_remap_index 188
#define TexParameterIuiv_remap_index 189
#define TransformFeedbackVaryings_remap_index 190
#define Uniform1ui_remap_index 191
#define Uniform1uiv_remap_index 192
#define Uniform2ui_remap_index 193
#define Uniform2uiv_remap_index 194
#define Uniform3ui_remap_index 195
#define Uniform3uiv_remap_index 196
#define Uniform4ui_remap_index 197
#define Uniform4uiv_remap_index 198
#define VertexAttribI1iv_remap_index 199
#define VertexAttribI1uiv_remap_index 200
#define VertexAttribI4bv_remap_index 201
#define VertexAttribI4sv_remap_index 202
#define VertexAttribI4ubv_remap_index 203
#define VertexAttribI4usv_remap_index 204
#define VertexAttribIPointer_remap_index 205
#define PrimitiveRestartIndex_remap_index 206
#define TexBuffer_remap_index 207
#define FramebufferTexture_remap_index 208
#define GetBufferParameteri64v_remap_index 209
#define GetInteger64i_v_remap_index 210
#define VertexAttribDivisor_remap_index 211
#define MinSampleShading_remap_index 212
#define MemoryBarrierByRegion_remap_index 213
#define BindProgramARB_remap_index 214
#define DeleteProgramsARB_remap_index 215
#define GenProgramsARB_remap_index 216
#define GetProgramEnvParameterdvARB_remap_index 217
#define GetProgramEnvParameterfvARB_remap_index 218
#define GetProgramLocalParameterdvARB_remap_index 219
#define GetProgramLocalParameterfvARB_remap_index 220
#define GetProgramStringARB_remap_index 221
#define GetProgramivARB_remap_index 222
#define IsProgramARB_remap_index 223
#define ProgramEnvParameter4dARB_remap_index 224
#define ProgramEnvParameter4dvARB_remap_index 225
#define ProgramEnvParameter4fARB_remap_index 226
#define ProgramEnvParameter4fvARB_remap_index 227
#define ProgramLocalParameter4dARB_remap_index 228
#define ProgramLocalParameter4dvARB_remap_index 229
#define ProgramLocalParameter4fARB_remap_index 230
#define ProgramLocalParameter4fvARB_remap_index 231
#define ProgramStringARB_remap_index 232
#define VertexAttrib1fARB_remap_index 233
#define VertexAttrib1fvARB_remap_index 234
#define VertexAttrib2fARB_remap_index 235
#define VertexAttrib2fvARB_remap_index 236
#define VertexAttrib3fARB_remap_index 237
#define VertexAttrib3fvARB_remap_index 238
#define VertexAttrib4fARB_remap_index 239
#define VertexAttrib4fvARB_remap_index 240
#define AttachObjectARB_remap_index 241
#define CreateProgramObjectARB_remap_index 242
#define CreateShaderObjectARB_remap_index 243
#define DeleteObjectARB_remap_index 244
#define DetachObjectARB_remap_index 245
#define GetAttachedObjectsARB_remap_index 246
#define GetHandleARB_remap_index 247
#define GetInfoLogARB_remap_index 248
#define GetObjectParameterfvARB_remap_index 249
#define GetObjectParameterivARB_remap_index 250
#define DrawArraysInstancedARB_remap_index 251
#define DrawElementsInstancedARB_remap_index 252
#define BindFramebuffer_remap_index 253
#define BindRenderbuffer_remap_index 254
#define BlitFramebuffer_remap_index 255
#define CheckFramebufferStatus_remap_index 256
#define DeleteFramebuffers_remap_index 257
#define DeleteRenderbuffers_remap_index 258
#define FramebufferRenderbuffer_remap_index 259
#define FramebufferTexture1D_remap_index 260
#define FramebufferTexture2D_remap_index 261
#define FramebufferTexture3D_remap_index 262
#define FramebufferTextureLayer_remap_index 263
#define GenFramebuffers_remap_index 264
#define GenRenderbuffers_remap_index 265
#define GenerateMipmap_remap_index 266
#define GetFramebufferAttachmentParameteriv_remap_index 267
#define GetRenderbufferParameteriv_remap_index 268
#define IsFramebuffer_remap_index 269
#define IsRenderbuffer_remap_index 270
#define RenderbufferStorage_remap_index 271
#define RenderbufferStorageMultisample_remap_index 272
#define FlushMappedBufferRange_remap_index 273
#define MapBufferRange_remap_index 274
#define BindVertexArray_remap_index 275
#define DeleteVertexArrays_remap_index 276
#define GenVertexArrays_remap_index 277
#define IsVertexArray_remap_index 278
#define GetActiveUniformBlockName_remap_index 279
#define GetActiveUniformBlockiv_remap_index 280
#define GetActiveUniformName_remap_index 281
#define GetActiveUniformsiv_remap_index 282
#define GetUniformBlockIndex_remap_index 283
#define GetUniformIndices_remap_index 284
#define UniformBlockBinding_remap_index 285
#define CopyBufferSubData_remap_index 286
#define ClientWaitSync_remap_index 287
#define DeleteSync_remap_index 288
#define FenceSync_remap_index 289
#define GetInteger64v_remap_index 290
#define GetSynciv_remap_index 291
#define IsSync_remap_index 292
#define WaitSync_remap_index 293
#define DrawElementsBaseVertex_remap_index 294
#define DrawElementsInstancedBaseVertex_remap_index 295
#define DrawRangeElementsBaseVertex_remap_index 296
#define MultiDrawElementsBaseVertex_remap_index 297
#define ProvokingVertex_remap_index 298
#define GetMultisamplefv_remap_index 299
#define SampleMaski_remap_index 300
#define TexImage2DMultisample_remap_index 301
#define TexImage3DMultisample_remap_index 302
#define BlendEquationSeparateiARB_remap_index 303
#define BlendEquationiARB_remap_index 304
#define BlendFuncSeparateiARB_remap_index 305
#define BlendFunciARB_remap_index 306
#define BindFragDataLocationIndexed_remap_index 307
#define GetFragDataIndex_remap_index 308
#define BindSampler_remap_index 309
#define DeleteSamplers_remap_index 310
#define GenSamplers_remap_index 311
#define GetSamplerParameterIiv_remap_index 312
#define GetSamplerParameterIuiv_remap_index 313
#define GetSamplerParameterfv_remap_index 314
#define GetSamplerParameteriv_remap_index 315
#define IsSampler_remap_index 316
#define SamplerParameterIiv_remap_index 317
#define SamplerParameterIuiv_remap_index 318
#define SamplerParameterf_remap_index 319
#define SamplerParameterfv_remap_index 320
#define SamplerParameteri_remap_index 321
#define SamplerParameteriv_remap_index 322
#define GetQueryObjecti64v_remap_index 323
#define GetQueryObjectui64v_remap_index 324
#define QueryCounter_remap_index 325
#define ColorP3ui_remap_index 326
#define ColorP3uiv_remap_index 327
#define ColorP4ui_remap_index 328
#define ColorP4uiv_remap_index 329
#define MultiTexCoordP1ui_remap_index 330
#define MultiTexCoordP1uiv_remap_index 331
#define MultiTexCoordP2ui_remap_index 332
#define MultiTexCoordP2uiv_remap_index 333
#define MultiTexCoordP3ui_remap_index 334
#define MultiTexCoordP3uiv_remap_index 335
#define MultiTexCoordP4ui_remap_index 336
#define MultiTexCoordP4uiv_remap_index 337
#define NormalP3ui_remap_index 338
#define NormalP3uiv_remap_index 339
#define SecondaryColorP3ui_remap_index 340
#define SecondaryColorP3uiv_remap_index 341
#define TexCoordP1ui_remap_index 342
#define TexCoordP1uiv_remap_index 343
#define TexCoordP2ui_remap_index 344
#define TexCoordP2uiv_remap_index 345
#define TexCoordP3ui_remap_index 346
#define TexCoordP3uiv_remap_index 347
#define TexCoordP4ui_remap_index 348
#define TexCoordP4uiv_remap_index 349
#define VertexAttribP1ui_remap_index 350
#define VertexAttribP1uiv_remap_index 351
#define VertexAttribP2ui_remap_index 352
#define VertexAttribP2uiv_remap_index 353
#define VertexAttribP3ui_remap_index 354
#define VertexAttribP3uiv_remap_index 355
#define VertexAttribP4ui_remap_index 356
#define VertexAttribP4uiv_remap_index 357
#define VertexP2ui_remap_index 358
#define VertexP2uiv_remap_index 359
#define VertexP3ui_remap_index 360
#define VertexP3uiv_remap_index 361
#define VertexP4ui_remap_index 362
#define VertexP4uiv_remap_index 363
#define DrawArraysIndirect_remap_index 364
#define DrawElementsIndirect_remap_index 365
#define GetUniformdv_remap_index 366
#define Uniform1d_remap_index 367
#define Uniform1dv_remap_index 368
#define Uniform2d_remap_index 369
#define Uniform2dv_remap_index 370
#define Uniform3d_remap_index 371
#define Uniform3dv_remap_index 372
#define Uniform4d_remap_index 373
#define Uniform4dv_remap_index 374
#define UniformMatrix2dv_remap_index 375
#define UniformMatrix2x3dv_remap_index 376
#define UniformMatrix2x4dv_remap_index 377
#define UniformMatrix3dv_remap_index 378
#define UniformMatrix3x2dv_remap_index 379
#define UniformMatrix3x4dv_remap_index 380
#define UniformMatrix4dv_remap_index 381
#define UniformMatrix4x2dv_remap_index 382
#define UniformMatrix4x3dv_remap_index 383
#define GetActiveSubroutineName_remap_index 384
#define GetActiveSubroutineUniformName_remap_index 385
#define GetActiveSubroutineUniformiv_remap_index 386
#define GetProgramStageiv_remap_index 387
#define GetSubroutineIndex_remap_index 388
#define GetSubroutineUniformLocation_remap_index 389
#define GetUniformSubroutineuiv_remap_index 390
#define UniformSubroutinesuiv_remap_index 391
#define PatchParameterfv_remap_index 392
#define PatchParameteri_remap_index 393
#define BindTransformFeedback_remap_index 394
#define DeleteTransformFeedbacks_remap_index 395
#define DrawTransformFeedback_remap_index 396
#define GenTransformFeedbacks_remap_index 397
#define IsTransformFeedback_remap_index 398
#define PauseTransformFeedback_remap_index 399
#define ResumeTransformFeedback_remap_index 400
#define BeginQueryIndexed_remap_index 401
#define DrawTransformFeedbackStream_remap_index 402
#define EndQueryIndexed_remap_index 403
#define GetQueryIndexediv_remap_index 404
#define ClearDepthf_remap_index 405
#define DepthRangef_remap_index 406
#define GetShaderPrecisionFormat_remap_index 407
#define ReleaseShaderCompiler_remap_index 408
#define ShaderBinary_remap_index 409
#define GetProgramBinary_remap_index 410
#define ProgramBinary_remap_index 411
#define ProgramParameteri_remap_index 412
#define GetVertexAttribLdv_remap_index 413
#define VertexAttribL1d_remap_index 414
#define VertexAttribL1dv_remap_index 415
#define VertexAttribL2d_remap_index 416
#define VertexAttribL2dv_remap_index 417
#define VertexAttribL3d_remap_index 418
#define VertexAttribL3dv_remap_index 419
#define VertexAttribL4d_remap_index 420
#define VertexAttribL4dv_remap_index 421
#define VertexAttribLPointer_remap_index 422
#define DepthRangeArrayv_remap_index 423
#define DepthRangeIndexed_remap_index 424
#define GetDoublei_v_remap_index 425
#define GetFloati_v_remap_index 426
#define ScissorArrayv_remap_index 427
#define ScissorIndexed_remap_index 428
#define ScissorIndexedv_remap_index 429
#define ViewportArrayv_remap_index 430
#define ViewportIndexedf_remap_index 431
#define ViewportIndexedfv_remap_index 432
#define GetGraphicsResetStatusARB_remap_index 433
#define GetnColorTableARB_remap_index 434
#define GetnCompressedTexImageARB_remap_index 435
#define GetnConvolutionFilterARB_remap_index 436
#define GetnHistogramARB_remap_index 437
#define GetnMapdvARB_remap_index 438
#define GetnMapfvARB_remap_index 439
#define GetnMapivARB_remap_index 440
#define GetnMinmaxARB_remap_index 441
#define GetnPixelMapfvARB_remap_index 442
#define GetnPixelMapuivARB_remap_index 443
#define GetnPixelMapusvARB_remap_index 444
#define GetnPolygonStippleARB_remap_index 445
#define GetnSeparableFilterARB_remap_index 446
#define GetnTexImageARB_remap_index 447
#define GetnUniformdvARB_remap_index 448
#define GetnUniformfvARB_remap_index 449
#define GetnUniformivARB_remap_index 450
#define GetnUniformuivARB_remap_index 451
#define ReadnPixelsARB_remap_index 452
#define DrawArraysInstancedBaseInstance_remap_index 453
#define DrawElementsInstancedBaseInstance_remap_index 454
#define DrawElementsInstancedBaseVertexBaseInstance_remap_index 455
#define DrawTransformFeedbackInstanced_remap_index 456
#define DrawTransformFeedbackStreamInstanced_remap_index 457
#define GetInternalformativ_remap_index 458
#define GetActiveAtomicCounterBufferiv_remap_index 459
#define BindImageTexture_remap_index 460
#define MemoryBarrier_remap_index 461
#define TexStorage1D_remap_index 462
#define TexStorage2D_remap_index 463
#define TexStorage3D_remap_index 464
#define TextureStorage1DEXT_remap_index 465
#define TextureStorage2DEXT_remap_index 466
#define TextureStorage3DEXT_remap_index 467
#define ClearBufferData_remap_index 468
#define ClearBufferSubData_remap_index 469
#define DispatchCompute_remap_index 470
#define DispatchComputeIndirect_remap_index 471
#define CopyImageSubData_remap_index 472
#define TextureView_remap_index 473
#define BindVertexBuffer_remap_index 474
#define VertexAttribBinding_remap_index 475
#define VertexAttribFormat_remap_index 476
#define VertexAttribIFormat_remap_index 477
#define VertexAttribLFormat_remap_index 478
#define VertexBindingDivisor_remap_index 479
#define FramebufferParameteri_remap_index 480
#define GetFramebufferParameteriv_remap_index 481
#define GetInternalformati64v_remap_index 482
#define MultiDrawArraysIndirect_remap_index 483
#define MultiDrawElementsIndirect_remap_index 484
#define GetProgramInterfaceiv_remap_index 485
#define GetProgramResourceIndex_remap_index 486
#define GetProgramResourceLocation_remap_index 487
#define GetProgramResourceLocationIndex_remap_index 488
#define GetProgramResourceName_remap_index 489
#define GetProgramResourceiv_remap_index 490
#define ShaderStorageBlockBinding_remap_index 491
#define TexBufferRange_remap_index 492
#define TexStorage2DMultisample_remap_index 493
#define TexStorage3DMultisample_remap_index 494
#define BufferStorage_remap_index 495
#define ClearTexImage_remap_index 496
#define ClearTexSubImage_remap_index 497
#define BindBuffersBase_remap_index 498
#define BindBuffersRange_remap_index 499
#define BindImageTextures_remap_index 500
#define BindSamplers_remap_index 501
#define BindTextures_remap_index 502
#define BindVertexBuffers_remap_index 503
#define GetImageHandleARB_remap_index 504
#define GetTextureHandleARB_remap_index 505
#define GetTextureSamplerHandleARB_remap_index 506
#define GetVertexAttribLui64vARB_remap_index 507
#define IsImageHandleResidentARB_remap_index 508
#define IsTextureHandleResidentARB_remap_index 509
#define MakeImageHandleNonResidentARB_remap_index 510
#define MakeImageHandleResidentARB_remap_index 511
#define MakeTextureHandleNonResidentARB_remap_index 512
#define MakeTextureHandleResidentARB_remap_index 513
#define ProgramUniformHandleui64ARB_remap_index 514
#define ProgramUniformHandleui64vARB_remap_index 515
#define UniformHandleui64ARB_remap_index 516
#define UniformHandleui64vARB_remap_index 517
#define VertexAttribL1ui64ARB_remap_index 518
#define VertexAttribL1ui64vARB_remap_index 519
#define DispatchComputeGroupSizeARB_remap_index 520
#define MultiDrawArraysIndirectCountARB_remap_index 521
#define MultiDrawElementsIndirectCountARB_remap_index 522
#define ClipControl_remap_index 523
#define BindTextureUnit_remap_index 524
#define BlitNamedFramebuffer_remap_index 525
#define CheckNamedFramebufferStatus_remap_index 526
#define ClearNamedBufferData_remap_index 527
#define ClearNamedBufferSubData_remap_index 528
#define ClearNamedFramebufferfi_remap_index 529
#define ClearNamedFramebufferfv_remap_index 530
#define ClearNamedFramebufferiv_remap_index 531
#define ClearNamedFramebufferuiv_remap_index 532
#define CompressedTextureSubImage1D_remap_index 533
#define CompressedTextureSubImage2D_remap_index 534
#define CompressedTextureSubImage3D_remap_index 535
#define CopyNamedBufferSubData_remap_index 536
#define CopyTextureSubImage1D_remap_index 537
#define CopyTextureSubImage2D_remap_index 538
#define CopyTextureSubImage3D_remap_index 539
#define CreateBuffers_remap_index 540
#define CreateFramebuffers_remap_index 541
#define CreateProgramPipelines_remap_index 542
#define CreateQueries_remap_index 543
#define CreateRenderbuffers_remap_index 544
#define CreateSamplers_remap_index 545
#define CreateTextures_remap_index 546
#define CreateTransformFeedbacks_remap_index 547
#define CreateVertexArrays_remap_index 548
#define DisableVertexArrayAttrib_remap_index 549
#define EnableVertexArrayAttrib_remap_index 550
#define FlushMappedNamedBufferRange_remap_index 551
#define GenerateTextureMipmap_remap_index 552
#define GetCompressedTextureImage_remap_index 553
#define GetNamedBufferParameteri64v_remap_index 554
#define GetNamedBufferParameteriv_remap_index 555
#define GetNamedBufferPointerv_remap_index 556
#define GetNamedBufferSubData_remap_index 557
#define GetNamedFramebufferAttachmentParameteriv_remap_index 558
#define GetNamedFramebufferParameteriv_remap_index 559
#define GetNamedRenderbufferParameteriv_remap_index 560
#define GetQueryBufferObjecti64v_remap_index 561
#define GetQueryBufferObjectiv_remap_index 562
#define GetQueryBufferObjectui64v_remap_index 563
#define GetQueryBufferObjectuiv_remap_index 564
#define GetTextureImage_remap_index 565
#define GetTextureLevelParameterfv_remap_index 566
#define GetTextureLevelParameteriv_remap_index 567
#define GetTextureParameterIiv_remap_index 568
#define GetTextureParameterIuiv_remap_index 569
#define GetTextureParameterfv_remap_index 570
#define GetTextureParameteriv_remap_index 571
#define GetTransformFeedbacki64_v_remap_index 572
#define GetTransformFeedbacki_v_remap_index 573
#define GetTransformFeedbackiv_remap_index 574
#define GetVertexArrayIndexed64iv_remap_index 575
#define GetVertexArrayIndexediv_remap_index 576
#define GetVertexArrayiv_remap_index 577
#define InvalidateNamedFramebufferData_remap_index 578
#define InvalidateNamedFramebufferSubData_remap_index 579
#define MapNamedBuffer_remap_index 580
#define MapNamedBufferRange_remap_index 581
#define NamedBufferData_remap_index 582
#define NamedBufferStorage_remap_index 583
#define NamedBufferSubData_remap_index 584
#define NamedFramebufferDrawBuffer_remap_index 585
#define NamedFramebufferDrawBuffers_remap_index 586
#define NamedFramebufferParameteri_remap_index 587
#define NamedFramebufferReadBuffer_remap_index 588
#define NamedFramebufferRenderbuffer_remap_index 589
#define NamedFramebufferTexture_remap_index 590
#define NamedFramebufferTextureLayer_remap_index 591
#define NamedRenderbufferStorage_remap_index 592
#define NamedRenderbufferStorageMultisample_remap_index 593
#define TextureBuffer_remap_index 594
#define TextureBufferRange_remap_index 595
#define TextureParameterIiv_remap_index 596
#define TextureParameterIuiv_remap_index 597
#define TextureParameterf_remap_index 598
#define TextureParameterfv_remap_index 599
#define TextureParameteri_remap_index 600
#define TextureParameteriv_remap_index 601
#define TextureStorage1D_remap_index 602
#define TextureStorage2D_remap_index 603
#define TextureStorage2DMultisample_remap_index 604
#define TextureStorage3D_remap_index 605
#define TextureStorage3DMultisample_remap_index 606
#define TextureSubImage1D_remap_index 607
#define TextureSubImage2D_remap_index 608
#define TextureSubImage3D_remap_index 609
#define TransformFeedbackBufferBase_remap_index 610
#define TransformFeedbackBufferRange_remap_index 611
#define UnmapNamedBuffer_remap_index 612
#define VertexArrayAttribBinding_remap_index 613
#define VertexArrayAttribFormat_remap_index 614
#define VertexArrayAttribIFormat_remap_index 615
#define VertexArrayAttribLFormat_remap_index 616
#define VertexArrayBindingDivisor_remap_index 617
#define VertexArrayElementBuffer_remap_index 618
#define VertexArrayVertexBuffer_remap_index 619
#define VertexArrayVertexBuffers_remap_index 620
#define GetCompressedTextureSubImage_remap_index 621
#define GetTextureSubImage_remap_index 622
#define BufferPageCommitmentARB_remap_index 623
#define NamedBufferPageCommitmentARB_remap_index 624
#define GetUniformi64vARB_remap_index 625
#define GetUniformui64vARB_remap_index 626
#define GetnUniformi64vARB_remap_index 627
#define GetnUniformui64vARB_remap_index 628
#define ProgramUniform1i64ARB_remap_index 629
#define ProgramUniform1i64vARB_remap_index 630
#define ProgramUniform1ui64ARB_remap_index 631
#define ProgramUniform1ui64vARB_remap_index 632
#define ProgramUniform2i64ARB_remap_index 633
#define ProgramUniform2i64vARB_remap_index 634
#define ProgramUniform2ui64ARB_remap_index 635
#define ProgramUniform2ui64vARB_remap_index 636
#define ProgramUniform3i64ARB_remap_index 637
#define ProgramUniform3i64vARB_remap_index 638
#define ProgramUniform3ui64ARB_remap_index 639
#define ProgramUniform3ui64vARB_remap_index 640
#define ProgramUniform4i64ARB_remap_index 641
#define ProgramUniform4i64vARB_remap_index 642
#define ProgramUniform4ui64ARB_remap_index 643
#define ProgramUniform4ui64vARB_remap_index 644
#define Uniform1i64ARB_remap_index 645
#define Uniform1i64vARB_remap_index 646
#define Uniform1ui64ARB_remap_index 647
#define Uniform1ui64vARB_remap_index 648
#define Uniform2i64ARB_remap_index 649
#define Uniform2i64vARB_remap_index 650
#define Uniform2ui64ARB_remap_index 651
#define Uniform2ui64vARB_remap_index 652
#define Uniform3i64ARB_remap_index 653
#define Uniform3i64vARB_remap_index 654
#define Uniform3ui64ARB_remap_index 655
#define Uniform3ui64vARB_remap_index 656
#define Uniform4i64ARB_remap_index 657
#define Uniform4i64vARB_remap_index 658
#define Uniform4ui64ARB_remap_index 659
#define Uniform4ui64vARB_remap_index 660
#define InvalidateBufferData_remap_index 661
#define InvalidateBufferSubData_remap_index 662
#define InvalidateFramebuffer_remap_index 663
#define InvalidateSubFramebuffer_remap_index 664
#define InvalidateTexImage_remap_index 665
#define InvalidateTexSubImage_remap_index 666
#define PolygonOffsetEXT_remap_index 667
#define DrawTexfOES_remap_index 668
#define DrawTexfvOES_remap_index 669
#define DrawTexiOES_remap_index 670
#define DrawTexivOES_remap_index 671
#define DrawTexsOES_remap_index 672
#define DrawTexsvOES_remap_index 673
#define DrawTexxOES_remap_index 674
#define DrawTexxvOES_remap_index 675
#define PointSizePointerOES_remap_index 676
#define QueryMatrixxOES_remap_index 677
#define SampleMaskSGIS_remap_index 678
#define SamplePatternSGIS_remap_index 679
#define ColorPointerEXT_remap_index 680
#define EdgeFlagPointerEXT_remap_index 681
#define IndexPointerEXT_remap_index 682
#define NormalPointerEXT_remap_index 683
#define TexCoordPointerEXT_remap_index 684
#define VertexPointerEXT_remap_index 685
#define DiscardFramebufferEXT_remap_index 686
#define ActiveShaderProgram_remap_index 687
#define BindProgramPipeline_remap_index 688
#define CreateShaderProgramv_remap_index 689
#define DeleteProgramPipelines_remap_index 690
#define GenProgramPipelines_remap_index 691
#define GetProgramPipelineInfoLog_remap_index 692
#define GetProgramPipelineiv_remap_index 693
#define IsProgramPipeline_remap_index 694
#define LockArraysEXT_remap_index 695
#define ProgramUniform1d_remap_index 696
#define ProgramUniform1dv_remap_index 697
#define ProgramUniform1f_remap_index 698
#define ProgramUniform1fv_remap_index 699
#define ProgramUniform1i_remap_index 700
#define ProgramUniform1iv_remap_index 701
#define ProgramUniform1ui_remap_index 702
#define ProgramUniform1uiv_remap_index 703
#define ProgramUniform2d_remap_index 704
#define ProgramUniform2dv_remap_index 705
#define ProgramUniform2f_remap_index 706
#define ProgramUniform2fv_remap_index 707
#define ProgramUniform2i_remap_index 708
#define ProgramUniform2iv_remap_index 709
#define ProgramUniform2ui_remap_index 710
#define ProgramUniform2uiv_remap_index 711
#define ProgramUniform3d_remap_index 712
#define ProgramUniform3dv_remap_index 713
#define ProgramUniform3f_remap_index 714
#define ProgramUniform3fv_remap_index 715
#define ProgramUniform3i_remap_index 716
#define ProgramUniform3iv_remap_index 717
#define ProgramUniform3ui_remap_index 718
#define ProgramUniform3uiv_remap_index 719
#define ProgramUniform4d_remap_index 720
#define ProgramUniform4dv_remap_index 721
#define ProgramUniform4f_remap_index 722
#define ProgramUniform4fv_remap_index 723
#define ProgramUniform4i_remap_index 724
#define ProgramUniform4iv_remap_index 725
#define ProgramUniform4ui_remap_index 726
#define ProgramUniform4uiv_remap_index 727
#define ProgramUniformMatrix2dv_remap_index 728
#define ProgramUniformMatrix2fv_remap_index 729
#define ProgramUniformMatrix2x3dv_remap_index 730
#define ProgramUniformMatrix2x3fv_remap_index 731
#define ProgramUniformMatrix2x4dv_remap_index 732
#define ProgramUniformMatrix2x4fv_remap_index 733
#define ProgramUniformMatrix3dv_remap_index 734
#define ProgramUniformMatrix3fv_remap_index 735
#define ProgramUniformMatrix3x2dv_remap_index 736
#define ProgramUniformMatrix3x2fv_remap_index 737
#define ProgramUniformMatrix3x4dv_remap_index 738
#define ProgramUniformMatrix3x4fv_remap_index 739
#define ProgramUniformMatrix4dv_remap_index 740
#define ProgramUniformMatrix4fv_remap_index 741
#define ProgramUniformMatrix4x2dv_remap_index 742
#define ProgramUniformMatrix4x2fv_remap_index 743
#define ProgramUniformMatrix4x3dv_remap_index 744
#define ProgramUniformMatrix4x3fv_remap_index 745
#define UnlockArraysEXT_remap_index 746
#define UseProgramStages_remap_index 747
#define ValidateProgramPipeline_remap_index 748
#define DebugMessageCallback_remap_index 749
#define DebugMessageControl_remap_index 750
#define DebugMessageInsert_remap_index 751
#define GetDebugMessageLog_remap_index 752
#define GetObjectLabel_remap_index 753
#define GetObjectPtrLabel_remap_index 754
#define ObjectLabel_remap_index 755
#define ObjectPtrLabel_remap_index 756
#define PopDebugGroup_remap_index 757
#define PushDebugGroup_remap_index 758
#define SecondaryColor3fEXT_remap_index 759
#define SecondaryColor3fvEXT_remap_index 760
#define MultiDrawElementsEXT_remap_index 761
#define FogCoordfEXT_remap_index 762
#define FogCoordfvEXT_remap_index 763
#define ResizeBuffersMESA_remap_index 764
#define WindowPos4dMESA_remap_index 765
#define WindowPos4dvMESA_remap_index 766
#define WindowPos4fMESA_remap_index 767
#define WindowPos4fvMESA_remap_index 768
#define WindowPos4iMESA_remap_index 769
#define WindowPos4ivMESA_remap_index 770
#define WindowPos4sMESA_remap_index 771
#define WindowPos4svMESA_remap_index 772
#define MultiModeDrawArraysIBM_remap_index 773
#define MultiModeDrawElementsIBM_remap_index 774
#define AreProgramsResidentNV_remap_index 775
#define ExecuteProgramNV_remap_index 776
#define GetProgramParameterdvNV_remap_index 777
#define GetProgramParameterfvNV_remap_index 778
#define GetProgramStringNV_remap_index 779
#define GetProgramivNV_remap_index 780
#define GetTrackMatrixivNV_remap_index 781
#define GetVertexAttribdvNV_remap_index 782
#define GetVertexAttribfvNV_remap_index 783
#define GetVertexAttribivNV_remap_index 784
#define LoadProgramNV_remap_index 785
#define ProgramParameters4dvNV_remap_index 786
#define ProgramParameters4fvNV_remap_index 787
#define RequestResidentProgramsNV_remap_index 788
#define TrackMatrixNV_remap_index 789
#define VertexAttrib1dNV_remap_index 790
#define VertexAttrib1dvNV_remap_index 791
#define VertexAttrib1fNV_remap_index 792
#define VertexAttrib1fvNV_remap_index 793
#define VertexAttrib1sNV_remap_index 794
#define VertexAttrib1svNV_remap_index 795
#define VertexAttrib2dNV_remap_index 796
#define VertexAttrib2dvNV_remap_index 797
#define VertexAttrib2fNV_remap_index 798
#define VertexAttrib2fvNV_remap_index 799
#define VertexAttrib2sNV_remap_index 800
#define VertexAttrib2svNV_remap_index 801
#define VertexAttrib3dNV_remap_index 802
#define VertexAttrib3dvNV_remap_index 803
#define VertexAttrib3fNV_remap_index 804
#define VertexAttrib3fvNV_remap_index 805
#define VertexAttrib3sNV_remap_index 806
#define VertexAttrib3svNV_remap_index 807
#define VertexAttrib4dNV_remap_index 808
#define VertexAttrib4dvNV_remap_index 809
#define VertexAttrib4fNV_remap_index 810
#define VertexAttrib4fvNV_remap_index 811
#define VertexAttrib4sNV_remap_index 812
#define VertexAttrib4svNV_remap_index 813
#define VertexAttrib4ubNV_remap_index 814
#define VertexAttrib4ubvNV_remap_index 815
#define VertexAttribPointerNV_remap_index 816
#define VertexAttribs1dvNV_remap_index 817
#define VertexAttribs1fvNV_remap_index 818
#define VertexAttribs1svNV_remap_index 819
#define VertexAttribs2dvNV_remap_index 820
#define VertexAttribs2fvNV_remap_index 821
#define VertexAttribs2svNV_remap_index 822
#define VertexAttribs3dvNV_remap_index 823
#define VertexAttribs3fvNV_remap_index 824
#define VertexAttribs3svNV_remap_index 825
#define VertexAttribs4dvNV_remap_index 826
#define VertexAttribs4fvNV_remap_index 827
#define VertexAttribs4svNV_remap_index 828
#define VertexAttribs4ubvNV_remap_index 829
#define GetTexBumpParameterfvATI_remap_index 830
#define GetTexBumpParameterivATI_remap_index 831
#define TexBumpParameterfvATI_remap_index 832
#define TexBumpParameterivATI_remap_index 833
#define AlphaFragmentOp1ATI_remap_index 834
#define AlphaFragmentOp2ATI_remap_index 835
#define AlphaFragmentOp3ATI_remap_index 836
#define BeginFragmentShaderATI_remap_index 837
#define BindFragmentShaderATI_remap_index 838
#define ColorFragmentOp1ATI_remap_index 839
#define ColorFragmentOp2ATI_remap_index 840
#define ColorFragmentOp3ATI_remap_index 841
#define DeleteFragmentShaderATI_remap_index 842
#define EndFragmentShaderATI_remap_index 843
#define GenFragmentShadersATI_remap_index 844
#define PassTexCoordATI_remap_index 845
#define SampleMapATI_remap_index 846
#define SetFragmentShaderConstantATI_remap_index 847
#define DepthRangeArrayfvOES_remap_index 848
#define DepthRangeIndexedfOES_remap_index 849
#define ActiveStencilFaceEXT_remap_index 850
#define GetProgramNamedParameterdvNV_remap_index 851
#define GetProgramNamedParameterfvNV_remap_index 852
#define ProgramNamedParameter4dNV_remap_index 853
#define ProgramNamedParameter4dvNV_remap_index 854
#define ProgramNamedParameter4fNV_remap_index 855
#define ProgramNamedParameter4fvNV_remap_index 856
#define PrimitiveRestartNV_remap_index 857
#define GetTexGenxvOES_remap_index 858
#define TexGenxOES_remap_index 859
#define TexGenxvOES_remap_index 860
#define DepthBoundsEXT_remap_index 861
#define BindFramebufferEXT_remap_index 862
#define BindRenderbufferEXT_remap_index 863
#define StringMarkerGREMEDY_remap_index 864
#define BufferParameteriAPPLE_remap_index 865
#define FlushMappedBufferRangeAPPLE_remap_index 866
#define VertexAttribI1iEXT_remap_index 867
#define VertexAttribI1uiEXT_remap_index 868
#define VertexAttribI2iEXT_remap_index 869
#define VertexAttribI2ivEXT_remap_index 870
#define VertexAttribI2uiEXT_remap_index 871
#define VertexAttribI2uivEXT_remap_index 872
#define VertexAttribI3iEXT_remap_index 873
#define VertexAttribI3ivEXT_remap_index 874
#define VertexAttribI3uiEXT_remap_index 875
#define VertexAttribI3uivEXT_remap_index 876
#define VertexAttribI4iEXT_remap_index 877
#define VertexAttribI4ivEXT_remap_index 878
#define VertexAttribI4uiEXT_remap_index 879
#define VertexAttribI4uivEXT_remap_index 880
#define ClearColorIiEXT_remap_index 881
#define ClearColorIuiEXT_remap_index 882
#define BindBufferOffsetEXT_remap_index 883
#define BeginPerfMonitorAMD_remap_index 884
#define DeletePerfMonitorsAMD_remap_index 885
#define EndPerfMonitorAMD_remap_index 886
#define GenPerfMonitorsAMD_remap_index 887
#define GetPerfMonitorCounterDataAMD_remap_index 888
#define GetPerfMonitorCounterInfoAMD_remap_index 889
#define GetPerfMonitorCounterStringAMD_remap_index 890
#define GetPerfMonitorCountersAMD_remap_index 891
#define GetPerfMonitorGroupStringAMD_remap_index 892
#define GetPerfMonitorGroupsAMD_remap_index 893
#define SelectPerfMonitorCountersAMD_remap_index 894
#define GetObjectParameterivAPPLE_remap_index 895
#define ObjectPurgeableAPPLE_remap_index 896
#define ObjectUnpurgeableAPPLE_remap_index 897
#define ActiveProgramEXT_remap_index 898
#define CreateShaderProgramEXT_remap_index 899
#define UseShaderProgramEXT_remap_index 900
#define TextureBarrierNV_remap_index 901
#define VDPAUFiniNV_remap_index 902
#define VDPAUGetSurfaceivNV_remap_index 903
#define VDPAUInitNV_remap_index 904
#define VDPAUIsSurfaceNV_remap_index 905
#define VDPAUMapSurfacesNV_remap_index 906
#define VDPAURegisterOutputSurfaceNV_remap_index 907
#define VDPAURegisterVideoSurfaceNV_remap_index 908
#define VDPAUSurfaceAccessNV_remap_index 909
#define VDPAUUnmapSurfacesNV_remap_index 910
#define VDPAUUnregisterSurfaceNV_remap_index 911
#define BeginPerfQueryINTEL_remap_index 912
#define CreatePerfQueryINTEL_remap_index 913
#define DeletePerfQueryINTEL_remap_index 914
#define EndPerfQueryINTEL_remap_index 915
#define GetFirstPerfQueryIdINTEL_remap_index 916
#define GetNextPerfQueryIdINTEL_remap_index 917
#define GetPerfCounterInfoINTEL_remap_index 918
#define GetPerfQueryDataINTEL_remap_index 919
#define GetPerfQueryIdByNameINTEL_remap_index 920
#define GetPerfQueryInfoINTEL_remap_index 921
#define PolygonOffsetClampEXT_remap_index 922
#define WindowRectanglesEXT_remap_index 923
#define BufferStorageMemEXT_remap_index 924
#define CreateMemoryObjectsEXT_remap_index 925
#define DeleteMemoryObjectsEXT_remap_index 926
#define DeleteSemaphoresEXT_remap_index 927
#define GenSemaphoresEXT_remap_index 928
#define GetMemoryObjectParameterivEXT_remap_index 929
#define GetSemaphoreParameterui64vEXT_remap_index 930
#define GetUnsignedBytei_vEXT_remap_index 931
#define GetUnsignedBytevEXT_remap_index 932
#define IsMemoryObjectEXT_remap_index 933
#define IsSemaphoreEXT_remap_index 934
#define MemoryObjectParameterivEXT_remap_index 935
#define NamedBufferStorageMemEXT_remap_index 936
#define SemaphoreParameterui64vEXT_remap_index 937
#define SignalSemaphoreEXT_remap_index 938
#define TexStorageMem1DEXT_remap_index 939
#define TexStorageMem2DEXT_remap_index 940
#define TexStorageMem2DMultisampleEXT_remap_index 941
#define TexStorageMem3DEXT_remap_index 942
#define TexStorageMem3DMultisampleEXT_remap_index 943
#define TextureStorageMem1DEXT_remap_index 944
#define TextureStorageMem2DEXT_remap_index 945
#define TextureStorageMem2DMultisampleEXT_remap_index 946
#define TextureStorageMem3DEXT_remap_index 947
#define TextureStorageMem3DMultisampleEXT_remap_index 948
#define WaitSemaphoreEXT_remap_index 949
#define ImportMemoryFdEXT_remap_index 950
#define ImportSemaphoreFdEXT_remap_index 951
#define StencilFuncSeparateATI_remap_index 952
#define ProgramEnvParameters4fvEXT_remap_index 953
#define ProgramLocalParameters4fvEXT_remap_index 954
#define EGLImageTargetRenderbufferStorageOES_remap_index 955
#define EGLImageTargetTexture2DOES_remap_index 956
#define AlphaFuncx_remap_index 957
#define ClearColorx_remap_index 958
#define ClearDepthx_remap_index 959
#define Color4x_remap_index 960
#define DepthRangex_remap_index 961
#define Fogx_remap_index 962
#define Fogxv_remap_index 963
#define Frustumf_remap_index 964
#define Frustumx_remap_index 965
#define LightModelx_remap_index 966
#define LightModelxv_remap_index 967
#define Lightx_remap_index 968
#define Lightxv_remap_index 969
#define LineWidthx_remap_index 970
#define LoadMatrixx_remap_index 971
#define Materialx_remap_index 972
#define Materialxv_remap_index 973
#define MultMatrixx_remap_index 974
#define MultiTexCoord4x_remap_index 975
#define Normal3x_remap_index 976
#define Orthof_remap_index 977
#define Orthox_remap_index 978
#define PointSizex_remap_index 979
#define PolygonOffsetx_remap_index 980
#define Rotatex_remap_index 981
#define SampleCoveragex_remap_index 982
#define Scalex_remap_index 983
#define TexEnvx_remap_index 984
#define TexEnvxv_remap_index 985
#define TexParameterx_remap_index 986
#define Translatex_remap_index 987
#define ClipPlanef_remap_index 988
#define ClipPlanex_remap_index 989
#define GetClipPlanef_remap_index 990
#define GetClipPlanex_remap_index 991
#define GetFixedv_remap_index 992
#define GetLightxv_remap_index 993
#define GetMaterialxv_remap_index 994
#define GetTexEnvxv_remap_index 995
#define GetTexParameterxv_remap_index 996
#define PointParameterx_remap_index 997
#define PointParameterxv_remap_index 998
#define TexParameterxv_remap_index 999
#define BlendBarrier_remap_index 1000
#define PrimitiveBoundingBox_remap_index 1001

#define _gloffset_CompressedTexImage1D driDispatchRemapTable[CompressedTexImage1D_remap_index]
#define _gloffset_CompressedTexImage2D driDispatchRemapTable[CompressedTexImage2D_remap_index]
#define _gloffset_CompressedTexImage3D driDispatchRemapTable[CompressedTexImage3D_remap_index]
#define _gloffset_CompressedTexSubImage1D driDispatchRemapTable[CompressedTexSubImage1D_remap_index]
#define _gloffset_CompressedTexSubImage2D driDispatchRemapTable[CompressedTexSubImage2D_remap_index]
#define _gloffset_CompressedTexSubImage3D driDispatchRemapTable[CompressedTexSubImage3D_remap_index]
#define _gloffset_GetCompressedTexImage driDispatchRemapTable[GetCompressedTexImage_remap_index]
#define _gloffset_LoadTransposeMatrixd driDispatchRemapTable[LoadTransposeMatrixd_remap_index]
#define _gloffset_LoadTransposeMatrixf driDispatchRemapTable[LoadTransposeMatrixf_remap_index]
#define _gloffset_MultTransposeMatrixd driDispatchRemapTable[MultTransposeMatrixd_remap_index]
#define _gloffset_MultTransposeMatrixf driDispatchRemapTable[MultTransposeMatrixf_remap_index]
#define _gloffset_SampleCoverage driDispatchRemapTable[SampleCoverage_remap_index]
#define _gloffset_BlendFuncSeparate driDispatchRemapTable[BlendFuncSeparate_remap_index]
#define _gloffset_FogCoordPointer driDispatchRemapTable[FogCoordPointer_remap_index]
#define _gloffset_FogCoordd driDispatchRemapTable[FogCoordd_remap_index]
#define _gloffset_FogCoorddv driDispatchRemapTable[FogCoorddv_remap_index]
#define _gloffset_MultiDrawArrays driDispatchRemapTable[MultiDrawArrays_remap_index]
#define _gloffset_PointParameterf driDispatchRemapTable[PointParameterf_remap_index]
#define _gloffset_PointParameterfv driDispatchRemapTable[PointParameterfv_remap_index]
#define _gloffset_PointParameteri driDispatchRemapTable[PointParameteri_remap_index]
#define _gloffset_PointParameteriv driDispatchRemapTable[PointParameteriv_remap_index]
#define _gloffset_SecondaryColor3b driDispatchRemapTable[SecondaryColor3b_remap_index]
#define _gloffset_SecondaryColor3bv driDispatchRemapTable[SecondaryColor3bv_remap_index]
#define _gloffset_SecondaryColor3d driDispatchRemapTable[SecondaryColor3d_remap_index]
#define _gloffset_SecondaryColor3dv driDispatchRemapTable[SecondaryColor3dv_remap_index]
#define _gloffset_SecondaryColor3i driDispatchRemapTable[SecondaryColor3i_remap_index]
#define _gloffset_SecondaryColor3iv driDispatchRemapTable[SecondaryColor3iv_remap_index]
#define _gloffset_SecondaryColor3s driDispatchRemapTable[SecondaryColor3s_remap_index]
#define _gloffset_SecondaryColor3sv driDispatchRemapTable[SecondaryColor3sv_remap_index]
#define _gloffset_SecondaryColor3ub driDispatchRemapTable[SecondaryColor3ub_remap_index]
#define _gloffset_SecondaryColor3ubv driDispatchRemapTable[SecondaryColor3ubv_remap_index]
#define _gloffset_SecondaryColor3ui driDispatchRemapTable[SecondaryColor3ui_remap_index]
#define _gloffset_SecondaryColor3uiv driDispatchRemapTable[SecondaryColor3uiv_remap_index]
#define _gloffset_SecondaryColor3us driDispatchRemapTable[SecondaryColor3us_remap_index]
#define _gloffset_SecondaryColor3usv driDispatchRemapTable[SecondaryColor3usv_remap_index]
#define _gloffset_SecondaryColorPointer driDispatchRemapTable[SecondaryColorPointer_remap_index]
#define _gloffset_WindowPos2d driDispatchRemapTable[WindowPos2d_remap_index]
#define _gloffset_WindowPos2dv driDispatchRemapTable[WindowPos2dv_remap_index]
#define _gloffset_WindowPos2f driDispatchRemapTable[WindowPos2f_remap_index]
#define _gloffset_WindowPos2fv driDispatchRemapTable[WindowPos2fv_remap_index]
#define _gloffset_WindowPos2i driDispatchRemapTable[WindowPos2i_remap_index]
#define _gloffset_WindowPos2iv driDispatchRemapTable[WindowPos2iv_remap_index]
#define _gloffset_WindowPos2s driDispatchRemapTable[WindowPos2s_remap_index]
#define _gloffset_WindowPos2sv driDispatchRemapTable[WindowPos2sv_remap_index]
#define _gloffset_WindowPos3d driDispatchRemapTable[WindowPos3d_remap_index]
#define _gloffset_WindowPos3dv driDispatchRemapTable[WindowPos3dv_remap_index]
#define _gloffset_WindowPos3f driDispatchRemapTable[WindowPos3f_remap_index]
#define _gloffset_WindowPos3fv driDispatchRemapTable[WindowPos3fv_remap_index]
#define _gloffset_WindowPos3i driDispatchRemapTable[WindowPos3i_remap_index]
#define _gloffset_WindowPos3iv driDispatchRemapTable[WindowPos3iv_remap_index]
#define _gloffset_WindowPos3s driDispatchRemapTable[WindowPos3s_remap_index]
#define _gloffset_WindowPos3sv driDispatchRemapTable[WindowPos3sv_remap_index]
#define _gloffset_BeginQuery driDispatchRemapTable[BeginQuery_remap_index]
#define _gloffset_BindBuffer driDispatchRemapTable[BindBuffer_remap_index]
#define _gloffset_BufferData driDispatchRemapTable[BufferData_remap_index]
#define _gloffset_BufferSubData driDispatchRemapTable[BufferSubData_remap_index]
#define _gloffset_DeleteBuffers driDispatchRemapTable[DeleteBuffers_remap_index]
#define _gloffset_DeleteQueries driDispatchRemapTable[DeleteQueries_remap_index]
#define _gloffset_EndQuery driDispatchRemapTable[EndQuery_remap_index]
#define _gloffset_GenBuffers driDispatchRemapTable[GenBuffers_remap_index]
#define _gloffset_GenQueries driDispatchRemapTable[GenQueries_remap_index]
#define _gloffset_GetBufferParameteriv driDispatchRemapTable[GetBufferParameteriv_remap_index]
#define _gloffset_GetBufferPointerv driDispatchRemapTable[GetBufferPointerv_remap_index]
#define _gloffset_GetBufferSubData driDispatchRemapTable[GetBufferSubData_remap_index]
#define _gloffset_GetQueryObjectiv driDispatchRemapTable[GetQueryObjectiv_remap_index]
#define _gloffset_GetQueryObjectuiv driDispatchRemapTable[GetQueryObjectuiv_remap_index]
#define _gloffset_GetQueryiv driDispatchRemapTable[GetQueryiv_remap_index]
#define _gloffset_IsBuffer driDispatchRemapTable[IsBuffer_remap_index]
#define _gloffset_IsQuery driDispatchRemapTable[IsQuery_remap_index]
#define _gloffset_MapBuffer driDispatchRemapTable[MapBuffer_remap_index]
#define _gloffset_UnmapBuffer driDispatchRemapTable[UnmapBuffer_remap_index]
#define _gloffset_AttachShader driDispatchRemapTable[AttachShader_remap_index]
#define _gloffset_BindAttribLocation driDispatchRemapTable[BindAttribLocation_remap_index]
#define _gloffset_BlendEquationSeparate driDispatchRemapTable[BlendEquationSeparate_remap_index]
#define _gloffset_CompileShader driDispatchRemapTable[CompileShader_remap_index]
#define _gloffset_CreateProgram driDispatchRemapTable[CreateProgram_remap_index]
#define _gloffset_CreateShader driDispatchRemapTable[CreateShader_remap_index]
#define _gloffset_DeleteProgram driDispatchRemapTable[DeleteProgram_remap_index]
#define _gloffset_DeleteShader driDispatchRemapTable[DeleteShader_remap_index]
#define _gloffset_DetachShader driDispatchRemapTable[DetachShader_remap_index]
#define _gloffset_DisableVertexAttribArray driDispatchRemapTable[DisableVertexAttribArray_remap_index]
#define _gloffset_DrawBuffers driDispatchRemapTable[DrawBuffers_remap_index]
#define _gloffset_EnableVertexAttribArray driDispatchRemapTable[EnableVertexAttribArray_remap_index]
#define _gloffset_GetActiveAttrib driDispatchRemapTable[GetActiveAttrib_remap_index]
#define _gloffset_GetActiveUniform driDispatchRemapTable[GetActiveUniform_remap_index]
#define _gloffset_GetAttachedShaders driDispatchRemapTable[GetAttachedShaders_remap_index]
#define _gloffset_GetAttribLocation driDispatchRemapTable[GetAttribLocation_remap_index]
#define _gloffset_GetProgramInfoLog driDispatchRemapTable[GetProgramInfoLog_remap_index]
#define _gloffset_GetProgramiv driDispatchRemapTable[GetProgramiv_remap_index]
#define _gloffset_GetShaderInfoLog driDispatchRemapTable[GetShaderInfoLog_remap_index]
#define _gloffset_GetShaderSource driDispatchRemapTable[GetShaderSource_remap_index]
#define _gloffset_GetShaderiv driDispatchRemapTable[GetShaderiv_remap_index]
#define _gloffset_GetUniformLocation driDispatchRemapTable[GetUniformLocation_remap_index]
#define _gloffset_GetUniformfv driDispatchRemapTable[GetUniformfv_remap_index]
#define _gloffset_GetUniformiv driDispatchRemapTable[GetUniformiv_remap_index]
#define _gloffset_GetVertexAttribPointerv driDispatchRemapTable[GetVertexAttribPointerv_remap_index]
#define _gloffset_GetVertexAttribdv driDispatchRemapTable[GetVertexAttribdv_remap_index]
#define _gloffset_GetVertexAttribfv driDispatchRemapTable[GetVertexAttribfv_remap_index]
#define _gloffset_GetVertexAttribiv driDispatchRemapTable[GetVertexAttribiv_remap_index]
#define _gloffset_IsProgram driDispatchRemapTable[IsProgram_remap_index]
#define _gloffset_IsShader driDispatchRemapTable[IsShader_remap_index]
#define _gloffset_LinkProgram driDispatchRemapTable[LinkProgram_remap_index]
#define _gloffset_ShaderSource driDispatchRemapTable[ShaderSource_remap_index]
#define _gloffset_StencilFuncSeparate driDispatchRemapTable[StencilFuncSeparate_remap_index]
#define _gloffset_StencilMaskSeparate driDispatchRemapTable[StencilMaskSeparate_remap_index]
#define _gloffset_StencilOpSeparate driDispatchRemapTable[StencilOpSeparate_remap_index]
#define _gloffset_Uniform1f driDispatchRemapTable[Uniform1f_remap_index]
#define _gloffset_Uniform1fv driDispatchRemapTable[Uniform1fv_remap_index]
#define _gloffset_Uniform1i driDispatchRemapTable[Uniform1i_remap_index]
#define _gloffset_Uniform1iv driDispatchRemapTable[Uniform1iv_remap_index]
#define _gloffset_Uniform2f driDispatchRemapTable[Uniform2f_remap_index]
#define _gloffset_Uniform2fv driDispatchRemapTable[Uniform2fv_remap_index]
#define _gloffset_Uniform2i driDispatchRemapTable[Uniform2i_remap_index]
#define _gloffset_Uniform2iv driDispatchRemapTable[Uniform2iv_remap_index]
#define _gloffset_Uniform3f driDispatchRemapTable[Uniform3f_remap_index]
#define _gloffset_Uniform3fv driDispatchRemapTable[Uniform3fv_remap_index]
#define _gloffset_Uniform3i driDispatchRemapTable[Uniform3i_remap_index]
#define _gloffset_Uniform3iv driDispatchRemapTable[Uniform3iv_remap_index]
#define _gloffset_Uniform4f driDispatchRemapTable[Uniform4f_remap_index]
#define _gloffset_Uniform4fv driDispatchRemapTable[Uniform4fv_remap_index]
#define _gloffset_Uniform4i driDispatchRemapTable[Uniform4i_remap_index]
#define _gloffset_Uniform4iv driDispatchRemapTable[Uniform4iv_remap_index]
#define _gloffset_UniformMatrix2fv driDispatchRemapTable[UniformMatrix2fv_remap_index]
#define _gloffset_UniformMatrix3fv driDispatchRemapTable[UniformMatrix3fv_remap_index]
#define _gloffset_UniformMatrix4fv driDispatchRemapTable[UniformMatrix4fv_remap_index]
#define _gloffset_UseProgram driDispatchRemapTable[UseProgram_remap_index]
#define _gloffset_ValidateProgram driDispatchRemapTable[ValidateProgram_remap_index]
#define _gloffset_VertexAttrib1d driDispatchRemapTable[VertexAttrib1d_remap_index]
#define _gloffset_VertexAttrib1dv driDispatchRemapTable[VertexAttrib1dv_remap_index]
#define _gloffset_VertexAttrib1s driDispatchRemapTable[VertexAttrib1s_remap_index]
#define _gloffset_VertexAttrib1sv driDispatchRemapTable[VertexAttrib1sv_remap_index]
#define _gloffset_VertexAttrib2d driDispatchRemapTable[VertexAttrib2d_remap_index]
#define _gloffset_VertexAttrib2dv driDispatchRemapTable[VertexAttrib2dv_remap_index]
#define _gloffset_VertexAttrib2s driDispatchRemapTable[VertexAttrib2s_remap_index]
#define _gloffset_VertexAttrib2sv driDispatchRemapTable[VertexAttrib2sv_remap_index]
#define _gloffset_VertexAttrib3d driDispatchRemapTable[VertexAttrib3d_remap_index]
#define _gloffset_VertexAttrib3dv driDispatchRemapTable[VertexAttrib3dv_remap_index]
#define _gloffset_VertexAttrib3s driDispatchRemapTable[VertexAttrib3s_remap_index]
#define _gloffset_VertexAttrib3sv driDispatchRemapTable[VertexAttrib3sv_remap_index]
#define _gloffset_VertexAttrib4Nbv driDispatchRemapTable[VertexAttrib4Nbv_remap_index]
#define _gloffset_VertexAttrib4Niv driDispatchRemapTable[VertexAttrib4Niv_remap_index]
#define _gloffset_VertexAttrib4Nsv driDispatchRemapTable[VertexAttrib4Nsv_remap_index]
#define _gloffset_VertexAttrib4Nub driDispatchRemapTable[VertexAttrib4Nub_remap_index]
#define _gloffset_VertexAttrib4Nubv driDispatchRemapTable[VertexAttrib4Nubv_remap_index]
#define _gloffset_VertexAttrib4Nuiv driDispatchRemapTable[VertexAttrib4Nuiv_remap_index]
#define _gloffset_VertexAttrib4Nusv driDispatchRemapTable[VertexAttrib4Nusv_remap_index]
#define _gloffset_VertexAttrib4bv driDispatchRemapTable[VertexAttrib4bv_remap_index]
#define _gloffset_VertexAttrib4d driDispatchRemapTable[VertexAttrib4d_remap_index]
#define _gloffset_VertexAttrib4dv driDispatchRemapTable[VertexAttrib4dv_remap_index]
#define _gloffset_VertexAttrib4iv driDispatchRemapTable[VertexAttrib4iv_remap_index]
#define _gloffset_VertexAttrib4s driDispatchRemapTable[VertexAttrib4s_remap_index]
#define _gloffset_VertexAttrib4sv driDispatchRemapTable[VertexAttrib4sv_remap_index]
#define _gloffset_VertexAttrib4ubv driDispatchRemapTable[VertexAttrib4ubv_remap_index]
#define _gloffset_VertexAttrib4uiv driDispatchRemapTable[VertexAttrib4uiv_remap_index]
#define _gloffset_VertexAttrib4usv driDispatchRemapTable[VertexAttrib4usv_remap_index]
#define _gloffset_VertexAttribPointer driDispatchRemapTable[VertexAttribPointer_remap_index]
#define _gloffset_UniformMatrix2x3fv driDispatchRemapTable[UniformMatrix2x3fv_remap_index]
#define _gloffset_UniformMatrix2x4fv driDispatchRemapTable[UniformMatrix2x4fv_remap_index]
#define _gloffset_UniformMatrix3x2fv driDispatchRemapTable[UniformMatrix3x2fv_remap_index]
#define _gloffset_UniformMatrix3x4fv driDispatchRemapTable[UniformMatrix3x4fv_remap_index]
#define _gloffset_UniformMatrix4x2fv driDispatchRemapTable[UniformMatrix4x2fv_remap_index]
#define _gloffset_UniformMatrix4x3fv driDispatchRemapTable[UniformMatrix4x3fv_remap_index]
#define _gloffset_BeginConditionalRender driDispatchRemapTable[BeginConditionalRender_remap_index]
#define _gloffset_BeginTransformFeedback driDispatchRemapTable[BeginTransformFeedback_remap_index]
#define _gloffset_BindBufferBase driDispatchRemapTable[BindBufferBase_remap_index]
#define _gloffset_BindBufferRange driDispatchRemapTable[BindBufferRange_remap_index]
#define _gloffset_BindFragDataLocation driDispatchRemapTable[BindFragDataLocation_remap_index]
#define _gloffset_ClampColor driDispatchRemapTable[ClampColor_remap_index]
#define _gloffset_ClearBufferfi driDispatchRemapTable[ClearBufferfi_remap_index]
#define _gloffset_ClearBufferfv driDispatchRemapTable[ClearBufferfv_remap_index]
#define _gloffset_ClearBufferiv driDispatchRemapTable[ClearBufferiv_remap_index]
#define _gloffset_ClearBufferuiv driDispatchRemapTable[ClearBufferuiv_remap_index]
#define _gloffset_ColorMaski driDispatchRemapTable[ColorMaski_remap_index]
#define _gloffset_Disablei driDispatchRemapTable[Disablei_remap_index]
#define _gloffset_Enablei driDispatchRemapTable[Enablei_remap_index]
#define _gloffset_EndConditionalRender driDispatchRemapTable[EndConditionalRender_remap_index]
#define _gloffset_EndTransformFeedback driDispatchRemapTable[EndTransformFeedback_remap_index]
#define _gloffset_GetBooleani_v driDispatchRemapTable[GetBooleani_v_remap_index]
#define _gloffset_GetFragDataLocation driDispatchRemapTable[GetFragDataLocation_remap_index]
#define _gloffset_GetIntegeri_v driDispatchRemapTable[GetIntegeri_v_remap_index]
#define _gloffset_GetStringi driDispatchRemapTable[GetStringi_remap_index]
#define _gloffset_GetTexParameterIiv driDispatchRemapTable[GetTexParameterIiv_remap_index]
#define _gloffset_GetTexParameterIuiv driDispatchRemapTable[GetTexParameterIuiv_remap_index]
#define _gloffset_GetTransformFeedbackVarying driDispatchRemapTable[GetTransformFeedbackVarying_remap_index]
#define _gloffset_GetUniformuiv driDispatchRemapTable[GetUniformuiv_remap_index]
#define _gloffset_GetVertexAttribIiv driDispatchRemapTable[GetVertexAttribIiv_remap_index]
#define _gloffset_GetVertexAttribIuiv driDispatchRemapTable[GetVertexAttribIuiv_remap_index]
#define _gloffset_IsEnabledi driDispatchRemapTable[IsEnabledi_remap_index]
#define _gloffset_TexParameterIiv driDispatchRemapTable[TexParameterIiv_remap_index]
#define _gloffset_TexParameterIuiv driDispatchRemapTable[TexParameterIuiv_remap_index]
#define _gloffset_TransformFeedbackVaryings driDispatchRemapTable[TransformFeedbackVaryings_remap_index]
#define _gloffset_Uniform1ui driDispatchRemapTable[Uniform1ui_remap_index]
#define _gloffset_Uniform1uiv driDispatchRemapTable[Uniform1uiv_remap_index]
#define _gloffset_Uniform2ui driDispatchRemapTable[Uniform2ui_remap_index]
#define _gloffset_Uniform2uiv driDispatchRemapTable[Uniform2uiv_remap_index]
#define _gloffset_Uniform3ui driDispatchRemapTable[Uniform3ui_remap_index]
#define _gloffset_Uniform3uiv driDispatchRemapTable[Uniform3uiv_remap_index]
#define _gloffset_Uniform4ui driDispatchRemapTable[Uniform4ui_remap_index]
#define _gloffset_Uniform4uiv driDispatchRemapTable[Uniform4uiv_remap_index]
#define _gloffset_VertexAttribI1iv driDispatchRemapTable[VertexAttribI1iv_remap_index]
#define _gloffset_VertexAttribI1uiv driDispatchRemapTable[VertexAttribI1uiv_remap_index]
#define _gloffset_VertexAttribI4bv driDispatchRemapTable[VertexAttribI4bv_remap_index]
#define _gloffset_VertexAttribI4sv driDispatchRemapTable[VertexAttribI4sv_remap_index]
#define _gloffset_VertexAttribI4ubv driDispatchRemapTable[VertexAttribI4ubv_remap_index]
#define _gloffset_VertexAttribI4usv driDispatchRemapTable[VertexAttribI4usv_remap_index]
#define _gloffset_VertexAttribIPointer driDispatchRemapTable[VertexAttribIPointer_remap_index]
#define _gloffset_PrimitiveRestartIndex driDispatchRemapTable[PrimitiveRestartIndex_remap_index]
#define _gloffset_TexBuffer driDispatchRemapTable[TexBuffer_remap_index]
#define _gloffset_FramebufferTexture driDispatchRemapTable[FramebufferTexture_remap_index]
#define _gloffset_GetBufferParameteri64v driDispatchRemapTable[GetBufferParameteri64v_remap_index]
#define _gloffset_GetInteger64i_v driDispatchRemapTable[GetInteger64i_v_remap_index]
#define _gloffset_VertexAttribDivisor driDispatchRemapTable[VertexAttribDivisor_remap_index]
#define _gloffset_MinSampleShading driDispatchRemapTable[MinSampleShading_remap_index]
#define _gloffset_MemoryBarrierByRegion driDispatchRemapTable[MemoryBarrierByRegion_remap_index]
#define _gloffset_BindProgramARB driDispatchRemapTable[BindProgramARB_remap_index]
#define _gloffset_DeleteProgramsARB driDispatchRemapTable[DeleteProgramsARB_remap_index]
#define _gloffset_GenProgramsARB driDispatchRemapTable[GenProgramsARB_remap_index]
#define _gloffset_GetProgramEnvParameterdvARB driDispatchRemapTable[GetProgramEnvParameterdvARB_remap_index]
#define _gloffset_GetProgramEnvParameterfvARB driDispatchRemapTable[GetProgramEnvParameterfvARB_remap_index]
#define _gloffset_GetProgramLocalParameterdvARB driDispatchRemapTable[GetProgramLocalParameterdvARB_remap_index]
#define _gloffset_GetProgramLocalParameterfvARB driDispatchRemapTable[GetProgramLocalParameterfvARB_remap_index]
#define _gloffset_GetProgramStringARB driDispatchRemapTable[GetProgramStringARB_remap_index]
#define _gloffset_GetProgramivARB driDispatchRemapTable[GetProgramivARB_remap_index]
#define _gloffset_IsProgramARB driDispatchRemapTable[IsProgramARB_remap_index]
#define _gloffset_ProgramEnvParameter4dARB driDispatchRemapTable[ProgramEnvParameter4dARB_remap_index]
#define _gloffset_ProgramEnvParameter4dvARB driDispatchRemapTable[ProgramEnvParameter4dvARB_remap_index]
#define _gloffset_ProgramEnvParameter4fARB driDispatchRemapTable[ProgramEnvParameter4fARB_remap_index]
#define _gloffset_ProgramEnvParameter4fvARB driDispatchRemapTable[ProgramEnvParameter4fvARB_remap_index]
#define _gloffset_ProgramLocalParameter4dARB driDispatchRemapTable[ProgramLocalParameter4dARB_remap_index]
#define _gloffset_ProgramLocalParameter4dvARB driDispatchRemapTable[ProgramLocalParameter4dvARB_remap_index]
#define _gloffset_ProgramLocalParameter4fARB driDispatchRemapTable[ProgramLocalParameter4fARB_remap_index]
#define _gloffset_ProgramLocalParameter4fvARB driDispatchRemapTable[ProgramLocalParameter4fvARB_remap_index]
#define _gloffset_ProgramStringARB driDispatchRemapTable[ProgramStringARB_remap_index]
#define _gloffset_VertexAttrib1fARB driDispatchRemapTable[VertexAttrib1fARB_remap_index]
#define _gloffset_VertexAttrib1fvARB driDispatchRemapTable[VertexAttrib1fvARB_remap_index]
#define _gloffset_VertexAttrib2fARB driDispatchRemapTable[VertexAttrib2fARB_remap_index]
#define _gloffset_VertexAttrib2fvARB driDispatchRemapTable[VertexAttrib2fvARB_remap_index]
#define _gloffset_VertexAttrib3fARB driDispatchRemapTable[VertexAttrib3fARB_remap_index]
#define _gloffset_VertexAttrib3fvARB driDispatchRemapTable[VertexAttrib3fvARB_remap_index]
#define _gloffset_VertexAttrib4fARB driDispatchRemapTable[VertexAttrib4fARB_remap_index]
#define _gloffset_VertexAttrib4fvARB driDispatchRemapTable[VertexAttrib4fvARB_remap_index]
#define _gloffset_AttachObjectARB driDispatchRemapTable[AttachObjectARB_remap_index]
#define _gloffset_CreateProgramObjectARB driDispatchRemapTable[CreateProgramObjectARB_remap_index]
#define _gloffset_CreateShaderObjectARB driDispatchRemapTable[CreateShaderObjectARB_remap_index]
#define _gloffset_DeleteObjectARB driDispatchRemapTable[DeleteObjectARB_remap_index]
#define _gloffset_DetachObjectARB driDispatchRemapTable[DetachObjectARB_remap_index]
#define _gloffset_GetAttachedObjectsARB driDispatchRemapTable[GetAttachedObjectsARB_remap_index]
#define _gloffset_GetHandleARB driDispatchRemapTable[GetHandleARB_remap_index]
#define _gloffset_GetInfoLogARB driDispatchRemapTable[GetInfoLogARB_remap_index]
#define _gloffset_GetObjectParameterfvARB driDispatchRemapTable[GetObjectParameterfvARB_remap_index]
#define _gloffset_GetObjectParameterivARB driDispatchRemapTable[GetObjectParameterivARB_remap_index]
#define _gloffset_DrawArraysInstancedARB driDispatchRemapTable[DrawArraysInstancedARB_remap_index]
#define _gloffset_DrawElementsInstancedARB driDispatchRemapTable[DrawElementsInstancedARB_remap_index]
#define _gloffset_BindFramebuffer driDispatchRemapTable[BindFramebuffer_remap_index]
#define _gloffset_BindRenderbuffer driDispatchRemapTable[BindRenderbuffer_remap_index]
#define _gloffset_BlitFramebuffer driDispatchRemapTable[BlitFramebuffer_remap_index]
#define _gloffset_CheckFramebufferStatus driDispatchRemapTable[CheckFramebufferStatus_remap_index]
#define _gloffset_DeleteFramebuffers driDispatchRemapTable[DeleteFramebuffers_remap_index]
#define _gloffset_DeleteRenderbuffers driDispatchRemapTable[DeleteRenderbuffers_remap_index]
#define _gloffset_FramebufferRenderbuffer driDispatchRemapTable[FramebufferRenderbuffer_remap_index]
#define _gloffset_FramebufferTexture1D driDispatchRemapTable[FramebufferTexture1D_remap_index]
#define _gloffset_FramebufferTexture2D driDispatchRemapTable[FramebufferTexture2D_remap_index]
#define _gloffset_FramebufferTexture3D driDispatchRemapTable[FramebufferTexture3D_remap_index]
#define _gloffset_FramebufferTextureLayer driDispatchRemapTable[FramebufferTextureLayer_remap_index]
#define _gloffset_GenFramebuffers driDispatchRemapTable[GenFramebuffers_remap_index]
#define _gloffset_GenRenderbuffers driDispatchRemapTable[GenRenderbuffers_remap_index]
#define _gloffset_GenerateMipmap driDispatchRemapTable[GenerateMipmap_remap_index]
#define _gloffset_GetFramebufferAttachmentParameteriv driDispatchRemapTable[GetFramebufferAttachmentParameteriv_remap_index]
#define _gloffset_GetRenderbufferParameteriv driDispatchRemapTable[GetRenderbufferParameteriv_remap_index]
#define _gloffset_IsFramebuffer driDispatchRemapTable[IsFramebuffer_remap_index]
#define _gloffset_IsRenderbuffer driDispatchRemapTable[IsRenderbuffer_remap_index]
#define _gloffset_RenderbufferStorage driDispatchRemapTable[RenderbufferStorage_remap_index]
#define _gloffset_RenderbufferStorageMultisample driDispatchRemapTable[RenderbufferStorageMultisample_remap_index]
#define _gloffset_FlushMappedBufferRange driDispatchRemapTable[FlushMappedBufferRange_remap_index]
#define _gloffset_MapBufferRange driDispatchRemapTable[MapBufferRange_remap_index]
#define _gloffset_BindVertexArray driDispatchRemapTable[BindVertexArray_remap_index]
#define _gloffset_DeleteVertexArrays driDispatchRemapTable[DeleteVertexArrays_remap_index]
#define _gloffset_GenVertexArrays driDispatchRemapTable[GenVertexArrays_remap_index]
#define _gloffset_IsVertexArray driDispatchRemapTable[IsVertexArray_remap_index]
#define _gloffset_GetActiveUniformBlockName driDispatchRemapTable[GetActiveUniformBlockName_remap_index]
#define _gloffset_GetActiveUniformBlockiv driDispatchRemapTable[GetActiveUniformBlockiv_remap_index]
#define _gloffset_GetActiveUniformName driDispatchRemapTable[GetActiveUniformName_remap_index]
#define _gloffset_GetActiveUniformsiv driDispatchRemapTable[GetActiveUniformsiv_remap_index]
#define _gloffset_GetUniformBlockIndex driDispatchRemapTable[GetUniformBlockIndex_remap_index]
#define _gloffset_GetUniformIndices driDispatchRemapTable[GetUniformIndices_remap_index]
#define _gloffset_UniformBlockBinding driDispatchRemapTable[UniformBlockBinding_remap_index]
#define _gloffset_CopyBufferSubData driDispatchRemapTable[CopyBufferSubData_remap_index]
#define _gloffset_ClientWaitSync driDispatchRemapTable[ClientWaitSync_remap_index]
#define _gloffset_DeleteSync driDispatchRemapTable[DeleteSync_remap_index]
#define _gloffset_FenceSync driDispatchRemapTable[FenceSync_remap_index]
#define _gloffset_GetInteger64v driDispatchRemapTable[GetInteger64v_remap_index]
#define _gloffset_GetSynciv driDispatchRemapTable[GetSynciv_remap_index]
#define _gloffset_IsSync driDispatchRemapTable[IsSync_remap_index]
#define _gloffset_WaitSync driDispatchRemapTable[WaitSync_remap_index]
#define _gloffset_DrawElementsBaseVertex driDispatchRemapTable[DrawElementsBaseVertex_remap_index]
#define _gloffset_DrawElementsInstancedBaseVertex driDispatchRemapTable[DrawElementsInstancedBaseVertex_remap_index]
#define _gloffset_DrawRangeElementsBaseVertex driDispatchRemapTable[DrawRangeElementsBaseVertex_remap_index]
#define _gloffset_MultiDrawElementsBaseVertex driDispatchRemapTable[MultiDrawElementsBaseVertex_remap_index]
#define _gloffset_ProvokingVertex driDispatchRemapTable[ProvokingVertex_remap_index]
#define _gloffset_GetMultisamplefv driDispatchRemapTable[GetMultisamplefv_remap_index]
#define _gloffset_SampleMaski driDispatchRemapTable[SampleMaski_remap_index]
#define _gloffset_TexImage2DMultisample driDispatchRemapTable[TexImage2DMultisample_remap_index]
#define _gloffset_TexImage3DMultisample driDispatchRemapTable[TexImage3DMultisample_remap_index]
#define _gloffset_BlendEquationSeparateiARB driDispatchRemapTable[BlendEquationSeparateiARB_remap_index]
#define _gloffset_BlendEquationiARB driDispatchRemapTable[BlendEquationiARB_remap_index]
#define _gloffset_BlendFuncSeparateiARB driDispatchRemapTable[BlendFuncSeparateiARB_remap_index]
#define _gloffset_BlendFunciARB driDispatchRemapTable[BlendFunciARB_remap_index]
#define _gloffset_BindFragDataLocationIndexed driDispatchRemapTable[BindFragDataLocationIndexed_remap_index]
#define _gloffset_GetFragDataIndex driDispatchRemapTable[GetFragDataIndex_remap_index]
#define _gloffset_BindSampler driDispatchRemapTable[BindSampler_remap_index]
#define _gloffset_DeleteSamplers driDispatchRemapTable[DeleteSamplers_remap_index]
#define _gloffset_GenSamplers driDispatchRemapTable[GenSamplers_remap_index]
#define _gloffset_GetSamplerParameterIiv driDispatchRemapTable[GetSamplerParameterIiv_remap_index]
#define _gloffset_GetSamplerParameterIuiv driDispatchRemapTable[GetSamplerParameterIuiv_remap_index]
#define _gloffset_GetSamplerParameterfv driDispatchRemapTable[GetSamplerParameterfv_remap_index]
#define _gloffset_GetSamplerParameteriv driDispatchRemapTable[GetSamplerParameteriv_remap_index]
#define _gloffset_IsSampler driDispatchRemapTable[IsSampler_remap_index]
#define _gloffset_SamplerParameterIiv driDispatchRemapTable[SamplerParameterIiv_remap_index]
#define _gloffset_SamplerParameterIuiv driDispatchRemapTable[SamplerParameterIuiv_remap_index]
#define _gloffset_SamplerParameterf driDispatchRemapTable[SamplerParameterf_remap_index]
#define _gloffset_SamplerParameterfv driDispatchRemapTable[SamplerParameterfv_remap_index]
#define _gloffset_SamplerParameteri driDispatchRemapTable[SamplerParameteri_remap_index]
#define _gloffset_SamplerParameteriv driDispatchRemapTable[SamplerParameteriv_remap_index]
#define _gloffset_GetQueryObjecti64v driDispatchRemapTable[GetQueryObjecti64v_remap_index]
#define _gloffset_GetQueryObjectui64v driDispatchRemapTable[GetQueryObjectui64v_remap_index]
#define _gloffset_QueryCounter driDispatchRemapTable[QueryCounter_remap_index]
#define _gloffset_ColorP3ui driDispatchRemapTable[ColorP3ui_remap_index]
#define _gloffset_ColorP3uiv driDispatchRemapTable[ColorP3uiv_remap_index]
#define _gloffset_ColorP4ui driDispatchRemapTable[ColorP4ui_remap_index]
#define _gloffset_ColorP4uiv driDispatchRemapTable[ColorP4uiv_remap_index]
#define _gloffset_MultiTexCoordP1ui driDispatchRemapTable[MultiTexCoordP1ui_remap_index]
#define _gloffset_MultiTexCoordP1uiv driDispatchRemapTable[MultiTexCoordP1uiv_remap_index]
#define _gloffset_MultiTexCoordP2ui driDispatchRemapTable[MultiTexCoordP2ui_remap_index]
#define _gloffset_MultiTexCoordP2uiv driDispatchRemapTable[MultiTexCoordP2uiv_remap_index]
#define _gloffset_MultiTexCoordP3ui driDispatchRemapTable[MultiTexCoordP3ui_remap_index]
#define _gloffset_MultiTexCoordP3uiv driDispatchRemapTable[MultiTexCoordP3uiv_remap_index]
#define _gloffset_MultiTexCoordP4ui driDispatchRemapTable[MultiTexCoordP4ui_remap_index]
#define _gloffset_MultiTexCoordP4uiv driDispatchRemapTable[MultiTexCoordP4uiv_remap_index]
#define _gloffset_NormalP3ui driDispatchRemapTable[NormalP3ui_remap_index]
#define _gloffset_NormalP3uiv driDispatchRemapTable[NormalP3uiv_remap_index]
#define _gloffset_SecondaryColorP3ui driDispatchRemapTable[SecondaryColorP3ui_remap_index]
#define _gloffset_SecondaryColorP3uiv driDispatchRemapTable[SecondaryColorP3uiv_remap_index]
#define _gloffset_TexCoordP1ui driDispatchRemapTable[TexCoordP1ui_remap_index]
#define _gloffset_TexCoordP1uiv driDispatchRemapTable[TexCoordP1uiv_remap_index]
#define _gloffset_TexCoordP2ui driDispatchRemapTable[TexCoordP2ui_remap_index]
#define _gloffset_TexCoordP2uiv driDispatchRemapTable[TexCoordP2uiv_remap_index]
#define _gloffset_TexCoordP3ui driDispatchRemapTable[TexCoordP3ui_remap_index]
#define _gloffset_TexCoordP3uiv driDispatchRemapTable[TexCoordP3uiv_remap_index]
#define _gloffset_TexCoordP4ui driDispatchRemapTable[TexCoordP4ui_remap_index]
#define _gloffset_TexCoordP4uiv driDispatchRemapTable[TexCoordP4uiv_remap_index]
#define _gloffset_VertexAttribP1ui driDispatchRemapTable[VertexAttribP1ui_remap_index]
#define _gloffset_VertexAttribP1uiv driDispatchRemapTable[VertexAttribP1uiv_remap_index]
#define _gloffset_VertexAttribP2ui driDispatchRemapTable[VertexAttribP2ui_remap_index]
#define _gloffset_VertexAttribP2uiv driDispatchRemapTable[VertexAttribP2uiv_remap_index]
#define _gloffset_VertexAttribP3ui driDispatchRemapTable[VertexAttribP3ui_remap_index]
#define _gloffset_VertexAttribP3uiv driDispatchRemapTable[VertexAttribP3uiv_remap_index]
#define _gloffset_VertexAttribP4ui driDispatchRemapTable[VertexAttribP4ui_remap_index]
#define _gloffset_VertexAttribP4uiv driDispatchRemapTable[VertexAttribP4uiv_remap_index]
#define _gloffset_VertexP2ui driDispatchRemapTable[VertexP2ui_remap_index]
#define _gloffset_VertexP2uiv driDispatchRemapTable[VertexP2uiv_remap_index]
#define _gloffset_VertexP3ui driDispatchRemapTable[VertexP3ui_remap_index]
#define _gloffset_VertexP3uiv driDispatchRemapTable[VertexP3uiv_remap_index]
#define _gloffset_VertexP4ui driDispatchRemapTable[VertexP4ui_remap_index]
#define _gloffset_VertexP4uiv driDispatchRemapTable[VertexP4uiv_remap_index]
#define _gloffset_DrawArraysIndirect driDispatchRemapTable[DrawArraysIndirect_remap_index]
#define _gloffset_DrawElementsIndirect driDispatchRemapTable[DrawElementsIndirect_remap_index]
#define _gloffset_GetUniformdv driDispatchRemapTable[GetUniformdv_remap_index]
#define _gloffset_Uniform1d driDispatchRemapTable[Uniform1d_remap_index]
#define _gloffset_Uniform1dv driDispatchRemapTable[Uniform1dv_remap_index]
#define _gloffset_Uniform2d driDispatchRemapTable[Uniform2d_remap_index]
#define _gloffset_Uniform2dv driDispatchRemapTable[Uniform2dv_remap_index]
#define _gloffset_Uniform3d driDispatchRemapTable[Uniform3d_remap_index]
#define _gloffset_Uniform3dv driDispatchRemapTable[Uniform3dv_remap_index]
#define _gloffset_Uniform4d driDispatchRemapTable[Uniform4d_remap_index]
#define _gloffset_Uniform4dv driDispatchRemapTable[Uniform4dv_remap_index]
#define _gloffset_UniformMatrix2dv driDispatchRemapTable[UniformMatrix2dv_remap_index]
#define _gloffset_UniformMatrix2x3dv driDispatchRemapTable[UniformMatrix2x3dv_remap_index]
#define _gloffset_UniformMatrix2x4dv driDispatchRemapTable[UniformMatrix2x4dv_remap_index]
#define _gloffset_UniformMatrix3dv driDispatchRemapTable[UniformMatrix3dv_remap_index]
#define _gloffset_UniformMatrix3x2dv driDispatchRemapTable[UniformMatrix3x2dv_remap_index]
#define _gloffset_UniformMatrix3x4dv driDispatchRemapTable[UniformMatrix3x4dv_remap_index]
#define _gloffset_UniformMatrix4dv driDispatchRemapTable[UniformMatrix4dv_remap_index]
#define _gloffset_UniformMatrix4x2dv driDispatchRemapTable[UniformMatrix4x2dv_remap_index]
#define _gloffset_UniformMatrix4x3dv driDispatchRemapTable[UniformMatrix4x3dv_remap_index]
#define _gloffset_GetActiveSubroutineName driDispatchRemapTable[GetActiveSubroutineName_remap_index]
#define _gloffset_GetActiveSubroutineUniformName driDispatchRemapTable[GetActiveSubroutineUniformName_remap_index]
#define _gloffset_GetActiveSubroutineUniformiv driDispatchRemapTable[GetActiveSubroutineUniformiv_remap_index]
#define _gloffset_GetProgramStageiv driDispatchRemapTable[GetProgramStageiv_remap_index]
#define _gloffset_GetSubroutineIndex driDispatchRemapTable[GetSubroutineIndex_remap_index]
#define _gloffset_GetSubroutineUniformLocation driDispatchRemapTable[GetSubroutineUniformLocation_remap_index]
#define _gloffset_GetUniformSubroutineuiv driDispatchRemapTable[GetUniformSubroutineuiv_remap_index]
#define _gloffset_UniformSubroutinesuiv driDispatchRemapTable[UniformSubroutinesuiv_remap_index]
#define _gloffset_PatchParameterfv driDispatchRemapTable[PatchParameterfv_remap_index]
#define _gloffset_PatchParameteri driDispatchRemapTable[PatchParameteri_remap_index]
#define _gloffset_BindTransformFeedback driDispatchRemapTable[BindTransformFeedback_remap_index]
#define _gloffset_DeleteTransformFeedbacks driDispatchRemapTable[DeleteTransformFeedbacks_remap_index]
#define _gloffset_DrawTransformFeedback driDispatchRemapTable[DrawTransformFeedback_remap_index]
#define _gloffset_GenTransformFeedbacks driDispatchRemapTable[GenTransformFeedbacks_remap_index]
#define _gloffset_IsTransformFeedback driDispatchRemapTable[IsTransformFeedback_remap_index]
#define _gloffset_PauseTransformFeedback driDispatchRemapTable[PauseTransformFeedback_remap_index]
#define _gloffset_ResumeTransformFeedback driDispatchRemapTable[ResumeTransformFeedback_remap_index]
#define _gloffset_BeginQueryIndexed driDispatchRemapTable[BeginQueryIndexed_remap_index]
#define _gloffset_DrawTransformFeedbackStream driDispatchRemapTable[DrawTransformFeedbackStream_remap_index]
#define _gloffset_EndQueryIndexed driDispatchRemapTable[EndQueryIndexed_remap_index]
#define _gloffset_GetQueryIndexediv driDispatchRemapTable[GetQueryIndexediv_remap_index]
#define _gloffset_ClearDepthf driDispatchRemapTable[ClearDepthf_remap_index]
#define _gloffset_DepthRangef driDispatchRemapTable[DepthRangef_remap_index]
#define _gloffset_GetShaderPrecisionFormat driDispatchRemapTable[GetShaderPrecisionFormat_remap_index]
#define _gloffset_ReleaseShaderCompiler driDispatchRemapTable[ReleaseShaderCompiler_remap_index]
#define _gloffset_ShaderBinary driDispatchRemapTable[ShaderBinary_remap_index]
#define _gloffset_GetProgramBinary driDispatchRemapTable[GetProgramBinary_remap_index]
#define _gloffset_ProgramBinary driDispatchRemapTable[ProgramBinary_remap_index]
#define _gloffset_ProgramParameteri driDispatchRemapTable[ProgramParameteri_remap_index]
#define _gloffset_GetVertexAttribLdv driDispatchRemapTable[GetVertexAttribLdv_remap_index]
#define _gloffset_VertexAttribL1d driDispatchRemapTable[VertexAttribL1d_remap_index]
#define _gloffset_VertexAttribL1dv driDispatchRemapTable[VertexAttribL1dv_remap_index]
#define _gloffset_VertexAttribL2d driDispatchRemapTable[VertexAttribL2d_remap_index]
#define _gloffset_VertexAttribL2dv driDispatchRemapTable[VertexAttribL2dv_remap_index]
#define _gloffset_VertexAttribL3d driDispatchRemapTable[VertexAttribL3d_remap_index]
#define _gloffset_VertexAttribL3dv driDispatchRemapTable[VertexAttribL3dv_remap_index]
#define _gloffset_VertexAttribL4d driDispatchRemapTable[VertexAttribL4d_remap_index]
#define _gloffset_VertexAttribL4dv driDispatchRemapTable[VertexAttribL4dv_remap_index]
#define _gloffset_VertexAttribLPointer driDispatchRemapTable[VertexAttribLPointer_remap_index]
#define _gloffset_DepthRangeArrayv driDispatchRemapTable[DepthRangeArrayv_remap_index]
#define _gloffset_DepthRangeIndexed driDispatchRemapTable[DepthRangeIndexed_remap_index]
#define _gloffset_GetDoublei_v driDispatchRemapTable[GetDoublei_v_remap_index]
#define _gloffset_GetFloati_v driDispatchRemapTable[GetFloati_v_remap_index]
#define _gloffset_ScissorArrayv driDispatchRemapTable[ScissorArrayv_remap_index]
#define _gloffset_ScissorIndexed driDispatchRemapTable[ScissorIndexed_remap_index]
#define _gloffset_ScissorIndexedv driDispatchRemapTable[ScissorIndexedv_remap_index]
#define _gloffset_ViewportArrayv driDispatchRemapTable[ViewportArrayv_remap_index]
#define _gloffset_ViewportIndexedf driDispatchRemapTable[ViewportIndexedf_remap_index]
#define _gloffset_ViewportIndexedfv driDispatchRemapTable[ViewportIndexedfv_remap_index]
#define _gloffset_GetGraphicsResetStatusARB driDispatchRemapTable[GetGraphicsResetStatusARB_remap_index]
#define _gloffset_GetnColorTableARB driDispatchRemapTable[GetnColorTableARB_remap_index]
#define _gloffset_GetnCompressedTexImageARB driDispatchRemapTable[GetnCompressedTexImageARB_remap_index]
#define _gloffset_GetnConvolutionFilterARB driDispatchRemapTable[GetnConvolutionFilterARB_remap_index]
#define _gloffset_GetnHistogramARB driDispatchRemapTable[GetnHistogramARB_remap_index]
#define _gloffset_GetnMapdvARB driDispatchRemapTable[GetnMapdvARB_remap_index]
#define _gloffset_GetnMapfvARB driDispatchRemapTable[GetnMapfvARB_remap_index]
#define _gloffset_GetnMapivARB driDispatchRemapTable[GetnMapivARB_remap_index]
#define _gloffset_GetnMinmaxARB driDispatchRemapTable[GetnMinmaxARB_remap_index]
#define _gloffset_GetnPixelMapfvARB driDispatchRemapTable[GetnPixelMapfvARB_remap_index]
#define _gloffset_GetnPixelMapuivARB driDispatchRemapTable[GetnPixelMapuivARB_remap_index]
#define _gloffset_GetnPixelMapusvARB driDispatchRemapTable[GetnPixelMapusvARB_remap_index]
#define _gloffset_GetnPolygonStippleARB driDispatchRemapTable[GetnPolygonStippleARB_remap_index]
#define _gloffset_GetnSeparableFilterARB driDispatchRemapTable[GetnSeparableFilterARB_remap_index]
#define _gloffset_GetnTexImageARB driDispatchRemapTable[GetnTexImageARB_remap_index]
#define _gloffset_GetnUniformdvARB driDispatchRemapTable[GetnUniformdvARB_remap_index]
#define _gloffset_GetnUniformfvARB driDispatchRemapTable[GetnUniformfvARB_remap_index]
#define _gloffset_GetnUniformivARB driDispatchRemapTable[GetnUniformivARB_remap_index]
#define _gloffset_GetnUniformuivARB driDispatchRemapTable[GetnUniformuivARB_remap_index]
#define _gloffset_ReadnPixelsARB driDispatchRemapTable[ReadnPixelsARB_remap_index]
#define _gloffset_DrawArraysInstancedBaseInstance driDispatchRemapTable[DrawArraysInstancedBaseInstance_remap_index]
#define _gloffset_DrawElementsInstancedBaseInstance driDispatchRemapTable[DrawElementsInstancedBaseInstance_remap_index]
#define _gloffset_DrawElementsInstancedBaseVertexBaseInstance driDispatchRemapTable[DrawElementsInstancedBaseVertexBaseInstance_remap_index]
#define _gloffset_DrawTransformFeedbackInstanced driDispatchRemapTable[DrawTransformFeedbackInstanced_remap_index]
#define _gloffset_DrawTransformFeedbackStreamInstanced driDispatchRemapTable[DrawTransformFeedbackStreamInstanced_remap_index]
#define _gloffset_GetInternalformativ driDispatchRemapTable[GetInternalformativ_remap_index]
#define _gloffset_GetActiveAtomicCounterBufferiv driDispatchRemapTable[GetActiveAtomicCounterBufferiv_remap_index]
#define _gloffset_BindImageTexture driDispatchRemapTable[BindImageTexture_remap_index]
#define _gloffset_MemoryBarrier driDispatchRemapTable[MemoryBarrier_remap_index]
#define _gloffset_TexStorage1D driDispatchRemapTable[TexStorage1D_remap_index]
#define _gloffset_TexStorage2D driDispatchRemapTable[TexStorage2D_remap_index]
#define _gloffset_TexStorage3D driDispatchRemapTable[TexStorage3D_remap_index]
#define _gloffset_TextureStorage1DEXT driDispatchRemapTable[TextureStorage1DEXT_remap_index]
#define _gloffset_TextureStorage2DEXT driDispatchRemapTable[TextureStorage2DEXT_remap_index]
#define _gloffset_TextureStorage3DEXT driDispatchRemapTable[TextureStorage3DEXT_remap_index]
#define _gloffset_ClearBufferData driDispatchRemapTable[ClearBufferData_remap_index]
#define _gloffset_ClearBufferSubData driDispatchRemapTable[ClearBufferSubData_remap_index]
#define _gloffset_DispatchCompute driDispatchRemapTable[DispatchCompute_remap_index]
#define _gloffset_DispatchComputeIndirect driDispatchRemapTable[DispatchComputeIndirect_remap_index]
#define _gloffset_CopyImageSubData driDispatchRemapTable[CopyImageSubData_remap_index]
#define _gloffset_TextureView driDispatchRemapTable[TextureView_remap_index]
#define _gloffset_BindVertexBuffer driDispatchRemapTable[BindVertexBuffer_remap_index]
#define _gloffset_VertexAttribBinding driDispatchRemapTable[VertexAttribBinding_remap_index]
#define _gloffset_VertexAttribFormat driDispatchRemapTable[VertexAttribFormat_remap_index]
#define _gloffset_VertexAttribIFormat driDispatchRemapTable[VertexAttribIFormat_remap_index]
#define _gloffset_VertexAttribLFormat driDispatchRemapTable[VertexAttribLFormat_remap_index]
#define _gloffset_VertexBindingDivisor driDispatchRemapTable[VertexBindingDivisor_remap_index]
#define _gloffset_FramebufferParameteri driDispatchRemapTable[FramebufferParameteri_remap_index]
#define _gloffset_GetFramebufferParameteriv driDispatchRemapTable[GetFramebufferParameteriv_remap_index]
#define _gloffset_GetInternalformati64v driDispatchRemapTable[GetInternalformati64v_remap_index]
#define _gloffset_MultiDrawArraysIndirect driDispatchRemapTable[MultiDrawArraysIndirect_remap_index]
#define _gloffset_MultiDrawElementsIndirect driDispatchRemapTable[MultiDrawElementsIndirect_remap_index]
#define _gloffset_GetProgramInterfaceiv driDispatchRemapTable[GetProgramInterfaceiv_remap_index]
#define _gloffset_GetProgramResourceIndex driDispatchRemapTable[GetProgramResourceIndex_remap_index]
#define _gloffset_GetProgramResourceLocation driDispatchRemapTable[GetProgramResourceLocation_remap_index]
#define _gloffset_GetProgramResourceLocationIndex driDispatchRemapTable[GetProgramResourceLocationIndex_remap_index]
#define _gloffset_GetProgramResourceName driDispatchRemapTable[GetProgramResourceName_remap_index]
#define _gloffset_GetProgramResourceiv driDispatchRemapTable[GetProgramResourceiv_remap_index]
#define _gloffset_ShaderStorageBlockBinding driDispatchRemapTable[ShaderStorageBlockBinding_remap_index]
#define _gloffset_TexBufferRange driDispatchRemapTable[TexBufferRange_remap_index]
#define _gloffset_TexStorage2DMultisample driDispatchRemapTable[TexStorage2DMultisample_remap_index]
#define _gloffset_TexStorage3DMultisample driDispatchRemapTable[TexStorage3DMultisample_remap_index]
#define _gloffset_BufferStorage driDispatchRemapTable[BufferStorage_remap_index]
#define _gloffset_ClearTexImage driDispatchRemapTable[ClearTexImage_remap_index]
#define _gloffset_ClearTexSubImage driDispatchRemapTable[ClearTexSubImage_remap_index]
#define _gloffset_BindBuffersBase driDispatchRemapTable[BindBuffersBase_remap_index]
#define _gloffset_BindBuffersRange driDispatchRemapTable[BindBuffersRange_remap_index]
#define _gloffset_BindImageTextures driDispatchRemapTable[BindImageTextures_remap_index]
#define _gloffset_BindSamplers driDispatchRemapTable[BindSamplers_remap_index]
#define _gloffset_BindTextures driDispatchRemapTable[BindTextures_remap_index]
#define _gloffset_BindVertexBuffers driDispatchRemapTable[BindVertexBuffers_remap_index]
#define _gloffset_GetImageHandleARB driDispatchRemapTable[GetImageHandleARB_remap_index]
#define _gloffset_GetTextureHandleARB driDispatchRemapTable[GetTextureHandleARB_remap_index]
#define _gloffset_GetTextureSamplerHandleARB driDispatchRemapTable[GetTextureSamplerHandleARB_remap_index]
#define _gloffset_GetVertexAttribLui64vARB driDispatchRemapTable[GetVertexAttribLui64vARB_remap_index]
#define _gloffset_IsImageHandleResidentARB driDispatchRemapTable[IsImageHandleResidentARB_remap_index]
#define _gloffset_IsTextureHandleResidentARB driDispatchRemapTable[IsTextureHandleResidentARB_remap_index]
#define _gloffset_MakeImageHandleNonResidentARB driDispatchRemapTable[MakeImageHandleNonResidentARB_remap_index]
#define _gloffset_MakeImageHandleResidentARB driDispatchRemapTable[MakeImageHandleResidentARB_remap_index]
#define _gloffset_MakeTextureHandleNonResidentARB driDispatchRemapTable[MakeTextureHandleNonResidentARB_remap_index]
#define _gloffset_MakeTextureHandleResidentARB driDispatchRemapTable[MakeTextureHandleResidentARB_remap_index]
#define _gloffset_ProgramUniformHandleui64ARB driDispatchRemapTable[ProgramUniformHandleui64ARB_remap_index]
#define _gloffset_ProgramUniformHandleui64vARB driDispatchRemapTable[ProgramUniformHandleui64vARB_remap_index]
#define _gloffset_UniformHandleui64ARB driDispatchRemapTable[UniformHandleui64ARB_remap_index]
#define _gloffset_UniformHandleui64vARB driDispatchRemapTable[UniformHandleui64vARB_remap_index]
#define _gloffset_VertexAttribL1ui64ARB driDispatchRemapTable[VertexAttribL1ui64ARB_remap_index]
#define _gloffset_VertexAttribL1ui64vARB driDispatchRemapTable[VertexAttribL1ui64vARB_remap_index]
#define _gloffset_DispatchComputeGroupSizeARB driDispatchRemapTable[DispatchComputeGroupSizeARB_remap_index]
#define _gloffset_MultiDrawArraysIndirectCountARB driDispatchRemapTable[MultiDrawArraysIndirectCountARB_remap_index]
#define _gloffset_MultiDrawElementsIndirectCountARB driDispatchRemapTable[MultiDrawElementsIndirectCountARB_remap_index]
#define _gloffset_ClipControl driDispatchRemapTable[ClipControl_remap_index]
#define _gloffset_BindTextureUnit driDispatchRemapTable[BindTextureUnit_remap_index]
#define _gloffset_BlitNamedFramebuffer driDispatchRemapTable[BlitNamedFramebuffer_remap_index]
#define _gloffset_CheckNamedFramebufferStatus driDispatchRemapTable[CheckNamedFramebufferStatus_remap_index]
#define _gloffset_ClearNamedBufferData driDispatchRemapTable[ClearNamedBufferData_remap_index]
#define _gloffset_ClearNamedBufferSubData driDispatchRemapTable[ClearNamedBufferSubData_remap_index]
#define _gloffset_ClearNamedFramebufferfi driDispatchRemapTable[ClearNamedFramebufferfi_remap_index]
#define _gloffset_ClearNamedFramebufferfv driDispatchRemapTable[ClearNamedFramebufferfv_remap_index]
#define _gloffset_ClearNamedFramebufferiv driDispatchRemapTable[ClearNamedFramebufferiv_remap_index]
#define _gloffset_ClearNamedFramebufferuiv driDispatchRemapTable[ClearNamedFramebufferuiv_remap_index]
#define _gloffset_CompressedTextureSubImage1D driDispatchRemapTable[CompressedTextureSubImage1D_remap_index]
#define _gloffset_CompressedTextureSubImage2D driDispatchRemapTable[CompressedTextureSubImage2D_remap_index]
#define _gloffset_CompressedTextureSubImage3D driDispatchRemapTable[CompressedTextureSubImage3D_remap_index]
#define _gloffset_CopyNamedBufferSubData driDispatchRemapTable[CopyNamedBufferSubData_remap_index]
#define _gloffset_CopyTextureSubImage1D driDispatchRemapTable[CopyTextureSubImage1D_remap_index]
#define _gloffset_CopyTextureSubImage2D driDispatchRemapTable[CopyTextureSubImage2D_remap_index]
#define _gloffset_CopyTextureSubImage3D driDispatchRemapTable[CopyTextureSubImage3D_remap_index]
#define _gloffset_CreateBuffers driDispatchRemapTable[CreateBuffers_remap_index]
#define _gloffset_CreateFramebuffers driDispatchRemapTable[CreateFramebuffers_remap_index]
#define _gloffset_CreateProgramPipelines driDispatchRemapTable[CreateProgramPipelines_remap_index]
#define _gloffset_CreateQueries driDispatchRemapTable[CreateQueries_remap_index]
#define _gloffset_CreateRenderbuffers driDispatchRemapTable[CreateRenderbuffers_remap_index]
#define _gloffset_CreateSamplers driDispatchRemapTable[CreateSamplers_remap_index]
#define _gloffset_CreateTextures driDispatchRemapTable[CreateTextures_remap_index]
#define _gloffset_CreateTransformFeedbacks driDispatchRemapTable[CreateTransformFeedbacks_remap_index]
#define _gloffset_CreateVertexArrays driDispatchRemapTable[CreateVertexArrays_remap_index]
#define _gloffset_DisableVertexArrayAttrib driDispatchRemapTable[DisableVertexArrayAttrib_remap_index]
#define _gloffset_EnableVertexArrayAttrib driDispatchRemapTable[EnableVertexArrayAttrib_remap_index]
#define _gloffset_FlushMappedNamedBufferRange driDispatchRemapTable[FlushMappedNamedBufferRange_remap_index]
#define _gloffset_GenerateTextureMipmap driDispatchRemapTable[GenerateTextureMipmap_remap_index]
#define _gloffset_GetCompressedTextureImage driDispatchRemapTable[GetCompressedTextureImage_remap_index]
#define _gloffset_GetNamedBufferParameteri64v driDispatchRemapTable[GetNamedBufferParameteri64v_remap_index]
#define _gloffset_GetNamedBufferParameteriv driDispatchRemapTable[GetNamedBufferParameteriv_remap_index]
#define _gloffset_GetNamedBufferPointerv driDispatchRemapTable[GetNamedBufferPointerv_remap_index]
#define _gloffset_GetNamedBufferSubData driDispatchRemapTable[GetNamedBufferSubData_remap_index]
#define _gloffset_GetNamedFramebufferAttachmentParameteriv driDispatchRemapTable[GetNamedFramebufferAttachmentParameteriv_remap_index]
#define _gloffset_GetNamedFramebufferParameteriv driDispatchRemapTable[GetNamedFramebufferParameteriv_remap_index]
#define _gloffset_GetNamedRenderbufferParameteriv driDispatchRemapTable[GetNamedRenderbufferParameteriv_remap_index]
#define _gloffset_GetQueryBufferObjecti64v driDispatchRemapTable[GetQueryBufferObjecti64v_remap_index]
#define _gloffset_GetQueryBufferObjectiv driDispatchRemapTable[GetQueryBufferObjectiv_remap_index]
#define _gloffset_GetQueryBufferObjectui64v driDispatchRemapTable[GetQueryBufferObjectui64v_remap_index]
#define _gloffset_GetQueryBufferObjectuiv driDispatchRemapTable[GetQueryBufferObjectuiv_remap_index]
#define _gloffset_GetTextureImage driDispatchRemapTable[GetTextureImage_remap_index]
#define _gloffset_GetTextureLevelParameterfv driDispatchRemapTable[GetTextureLevelParameterfv_remap_index]
#define _gloffset_GetTextureLevelParameteriv driDispatchRemapTable[GetTextureLevelParameteriv_remap_index]
#define _gloffset_GetTextureParameterIiv driDispatchRemapTable[GetTextureParameterIiv_remap_index]
#define _gloffset_GetTextureParameterIuiv driDispatchRemapTable[GetTextureParameterIuiv_remap_index]
#define _gloffset_GetTextureParameterfv driDispatchRemapTable[GetTextureParameterfv_remap_index]
#define _gloffset_GetTextureParameteriv driDispatchRemapTable[GetTextureParameteriv_remap_index]
#define _gloffset_GetTransformFeedbacki64_v driDispatchRemapTable[GetTransformFeedbacki64_v_remap_index]
#define _gloffset_GetTransformFeedbacki_v driDispatchRemapTable[GetTransformFeedbacki_v_remap_index]
#define _gloffset_GetTransformFeedbackiv driDispatchRemapTable[GetTransformFeedbackiv_remap_index]
#define _gloffset_GetVertexArrayIndexed64iv driDispatchRemapTable[GetVertexArrayIndexed64iv_remap_index]
#define _gloffset_GetVertexArrayIndexediv driDispatchRemapTable[GetVertexArrayIndexediv_remap_index]
#define _gloffset_GetVertexArrayiv driDispatchRemapTable[GetVertexArrayiv_remap_index]
#define _gloffset_InvalidateNamedFramebufferData driDispatchRemapTable[InvalidateNamedFramebufferData_remap_index]
#define _gloffset_InvalidateNamedFramebufferSubData driDispatchRemapTable[InvalidateNamedFramebufferSubData_remap_index]
#define _gloffset_MapNamedBuffer driDispatchRemapTable[MapNamedBuffer_remap_index]
#define _gloffset_MapNamedBufferRange driDispatchRemapTable[MapNamedBufferRange_remap_index]
#define _gloffset_NamedBufferData driDispatchRemapTable[NamedBufferData_remap_index]
#define _gloffset_NamedBufferStorage driDispatchRemapTable[NamedBufferStorage_remap_index]
#define _gloffset_NamedBufferSubData driDispatchRemapTable[NamedBufferSubData_remap_index]
#define _gloffset_NamedFramebufferDrawBuffer driDispatchRemapTable[NamedFramebufferDrawBuffer_remap_index]
#define _gloffset_NamedFramebufferDrawBuffers driDispatchRemapTable[NamedFramebufferDrawBuffers_remap_index]
#define _gloffset_NamedFramebufferParameteri driDispatchRemapTable[NamedFramebufferParameteri_remap_index]
#define _gloffset_NamedFramebufferReadBuffer driDispatchRemapTable[NamedFramebufferReadBuffer_remap_index]
#define _gloffset_NamedFramebufferRenderbuffer driDispatchRemapTable[NamedFramebufferRenderbuffer_remap_index]
#define _gloffset_NamedFramebufferTexture driDispatchRemapTable[NamedFramebufferTexture_remap_index]
#define _gloffset_NamedFramebufferTextureLayer driDispatchRemapTable[NamedFramebufferTextureLayer_remap_index]
#define _gloffset_NamedRenderbufferStorage driDispatchRemapTable[NamedRenderbufferStorage_remap_index]
#define _gloffset_NamedRenderbufferStorageMultisample driDispatchRemapTable[NamedRenderbufferStorageMultisample_remap_index]
#define _gloffset_TextureBuffer driDispatchRemapTable[TextureBuffer_remap_index]
#define _gloffset_TextureBufferRange driDispatchRemapTable[TextureBufferRange_remap_index]
#define _gloffset_TextureParameterIiv driDispatchRemapTable[TextureParameterIiv_remap_index]
#define _gloffset_TextureParameterIuiv driDispatchRemapTable[TextureParameterIuiv_remap_index]
#define _gloffset_TextureParameterf driDispatchRemapTable[TextureParameterf_remap_index]
#define _gloffset_TextureParameterfv driDispatchRemapTable[TextureParameterfv_remap_index]
#define _gloffset_TextureParameteri driDispatchRemapTable[TextureParameteri_remap_index]
#define _gloffset_TextureParameteriv driDispatchRemapTable[TextureParameteriv_remap_index]
#define _gloffset_TextureStorage1D driDispatchRemapTable[TextureStorage1D_remap_index]
#define _gloffset_TextureStorage2D driDispatchRemapTable[TextureStorage2D_remap_index]
#define _gloffset_TextureStorage2DMultisample driDispatchRemapTable[TextureStorage2DMultisample_remap_index]
#define _gloffset_TextureStorage3D driDispatchRemapTable[TextureStorage3D_remap_index]
#define _gloffset_TextureStorage3DMultisample driDispatchRemapTable[TextureStorage3DMultisample_remap_index]
#define _gloffset_TextureSubImage1D driDispatchRemapTable[TextureSubImage1D_remap_index]
#define _gloffset_TextureSubImage2D driDispatchRemapTable[TextureSubImage2D_remap_index]
#define _gloffset_TextureSubImage3D driDispatchRemapTable[TextureSubImage3D_remap_index]
#define _gloffset_TransformFeedbackBufferBase driDispatchRemapTable[TransformFeedbackBufferBase_remap_index]
#define _gloffset_TransformFeedbackBufferRange driDispatchRemapTable[TransformFeedbackBufferRange_remap_index]
#define _gloffset_UnmapNamedBuffer driDispatchRemapTable[UnmapNamedBuffer_remap_index]
#define _gloffset_VertexArrayAttribBinding driDispatchRemapTable[VertexArrayAttribBinding_remap_index]
#define _gloffset_VertexArrayAttribFormat driDispatchRemapTable[VertexArrayAttribFormat_remap_index]
#define _gloffset_VertexArrayAttribIFormat driDispatchRemapTable[VertexArrayAttribIFormat_remap_index]
#define _gloffset_VertexArrayAttribLFormat driDispatchRemapTable[VertexArrayAttribLFormat_remap_index]
#define _gloffset_VertexArrayBindingDivisor driDispatchRemapTable[VertexArrayBindingDivisor_remap_index]
#define _gloffset_VertexArrayElementBuffer driDispatchRemapTable[VertexArrayElementBuffer_remap_index]
#define _gloffset_VertexArrayVertexBuffer driDispatchRemapTable[VertexArrayVertexBuffer_remap_index]
#define _gloffset_VertexArrayVertexBuffers driDispatchRemapTable[VertexArrayVertexBuffers_remap_index]
#define _gloffset_GetCompressedTextureSubImage driDispatchRemapTable[GetCompressedTextureSubImage_remap_index]
#define _gloffset_GetTextureSubImage driDispatchRemapTable[GetTextureSubImage_remap_index]
#define _gloffset_BufferPageCommitmentARB driDispatchRemapTable[BufferPageCommitmentARB_remap_index]
#define _gloffset_NamedBufferPageCommitmentARB driDispatchRemapTable[NamedBufferPageCommitmentARB_remap_index]
#define _gloffset_GetUniformi64vARB driDispatchRemapTable[GetUniformi64vARB_remap_index]
#define _gloffset_GetUniformui64vARB driDispatchRemapTable[GetUniformui64vARB_remap_index]
#define _gloffset_GetnUniformi64vARB driDispatchRemapTable[GetnUniformi64vARB_remap_index]
#define _gloffset_GetnUniformui64vARB driDispatchRemapTable[GetnUniformui64vARB_remap_index]
#define _gloffset_ProgramUniform1i64ARB driDispatchRemapTable[ProgramUniform1i64ARB_remap_index]
#define _gloffset_ProgramUniform1i64vARB driDispatchRemapTable[ProgramUniform1i64vARB_remap_index]
#define _gloffset_ProgramUniform1ui64ARB driDispatchRemapTable[ProgramUniform1ui64ARB_remap_index]
#define _gloffset_ProgramUniform1ui64vARB driDispatchRemapTable[ProgramUniform1ui64vARB_remap_index]
#define _gloffset_ProgramUniform2i64ARB driDispatchRemapTable[ProgramUniform2i64ARB_remap_index]
#define _gloffset_ProgramUniform2i64vARB driDispatchRemapTable[ProgramUniform2i64vARB_remap_index]
#define _gloffset_ProgramUniform2ui64ARB driDispatchRemapTable[ProgramUniform2ui64ARB_remap_index]
#define _gloffset_ProgramUniform2ui64vARB driDispatchRemapTable[ProgramUniform2ui64vARB_remap_index]
#define _gloffset_ProgramUniform3i64ARB driDispatchRemapTable[ProgramUniform3i64ARB_remap_index]
#define _gloffset_ProgramUniform3i64vARB driDispatchRemapTable[ProgramUniform3i64vARB_remap_index]
#define _gloffset_ProgramUniform3ui64ARB driDispatchRemapTable[ProgramUniform3ui64ARB_remap_index]
#define _gloffset_ProgramUniform3ui64vARB driDispatchRemapTable[ProgramUniform3ui64vARB_remap_index]
#define _gloffset_ProgramUniform4i64ARB driDispatchRemapTable[ProgramUniform4i64ARB_remap_index]
#define _gloffset_ProgramUniform4i64vARB driDispatchRemapTable[ProgramUniform4i64vARB_remap_index]
#define _gloffset_ProgramUniform4ui64ARB driDispatchRemapTable[ProgramUniform4ui64ARB_remap_index]
#define _gloffset_ProgramUniform4ui64vARB driDispatchRemapTable[ProgramUniform4ui64vARB_remap_index]
#define _gloffset_Uniform1i64ARB driDispatchRemapTable[Uniform1i64ARB_remap_index]
#define _gloffset_Uniform1i64vARB driDispatchRemapTable[Uniform1i64vARB_remap_index]
#define _gloffset_Uniform1ui64ARB driDispatchRemapTable[Uniform1ui64ARB_remap_index]
#define _gloffset_Uniform1ui64vARB driDispatchRemapTable[Uniform1ui64vARB_remap_index]
#define _gloffset_Uniform2i64ARB driDispatchRemapTable[Uniform2i64ARB_remap_index]
#define _gloffset_Uniform2i64vARB driDispatchRemapTable[Uniform2i64vARB_remap_index]
#define _gloffset_Uniform2ui64ARB driDispatchRemapTable[Uniform2ui64ARB_remap_index]
#define _gloffset_Uniform2ui64vARB driDispatchRemapTable[Uniform2ui64vARB_remap_index]
#define _gloffset_Uniform3i64ARB driDispatchRemapTable[Uniform3i64ARB_remap_index]
#define _gloffset_Uniform3i64vARB driDispatchRemapTable[Uniform3i64vARB_remap_index]
#define _gloffset_Uniform3ui64ARB driDispatchRemapTable[Uniform3ui64ARB_remap_index]
#define _gloffset_Uniform3ui64vARB driDispatchRemapTable[Uniform3ui64vARB_remap_index]
#define _gloffset_Uniform4i64ARB driDispatchRemapTable[Uniform4i64ARB_remap_index]
#define _gloffset_Uniform4i64vARB driDispatchRemapTable[Uniform4i64vARB_remap_index]
#define _gloffset_Uniform4ui64ARB driDispatchRemapTable[Uniform4ui64ARB_remap_index]
#define _gloffset_Uniform4ui64vARB driDispatchRemapTable[Uniform4ui64vARB_remap_index]
#define _gloffset_InvalidateBufferData driDispatchRemapTable[InvalidateBufferData_remap_index]
#define _gloffset_InvalidateBufferSubData driDispatchRemapTable[InvalidateBufferSubData_remap_index]
#define _gloffset_InvalidateFramebuffer driDispatchRemapTable[InvalidateFramebuffer_remap_index]
#define _gloffset_InvalidateSubFramebuffer driDispatchRemapTable[InvalidateSubFramebuffer_remap_index]
#define _gloffset_InvalidateTexImage driDispatchRemapTable[InvalidateTexImage_remap_index]
#define _gloffset_InvalidateTexSubImage driDispatchRemapTable[InvalidateTexSubImage_remap_index]
#define _gloffset_PolygonOffsetEXT driDispatchRemapTable[PolygonOffsetEXT_remap_index]
#define _gloffset_DrawTexfOES driDispatchRemapTable[DrawTexfOES_remap_index]
#define _gloffset_DrawTexfvOES driDispatchRemapTable[DrawTexfvOES_remap_index]
#define _gloffset_DrawTexiOES driDispatchRemapTable[DrawTexiOES_remap_index]
#define _gloffset_DrawTexivOES driDispatchRemapTable[DrawTexivOES_remap_index]
#define _gloffset_DrawTexsOES driDispatchRemapTable[DrawTexsOES_remap_index]
#define _gloffset_DrawTexsvOES driDispatchRemapTable[DrawTexsvOES_remap_index]
#define _gloffset_DrawTexxOES driDispatchRemapTable[DrawTexxOES_remap_index]
#define _gloffset_DrawTexxvOES driDispatchRemapTable[DrawTexxvOES_remap_index]
#define _gloffset_PointSizePointerOES driDispatchRemapTable[PointSizePointerOES_remap_index]
#define _gloffset_QueryMatrixxOES driDispatchRemapTable[QueryMatrixxOES_remap_index]
#define _gloffset_SampleMaskSGIS driDispatchRemapTable[SampleMaskSGIS_remap_index]
#define _gloffset_SamplePatternSGIS driDispatchRemapTable[SamplePatternSGIS_remap_index]
#define _gloffset_ColorPointerEXT driDispatchRemapTable[ColorPointerEXT_remap_index]
#define _gloffset_EdgeFlagPointerEXT driDispatchRemapTable[EdgeFlagPointerEXT_remap_index]
#define _gloffset_IndexPointerEXT driDispatchRemapTable[IndexPointerEXT_remap_index]
#define _gloffset_NormalPointerEXT driDispatchRemapTable[NormalPointerEXT_remap_index]
#define _gloffset_TexCoordPointerEXT driDispatchRemapTable[TexCoordPointerEXT_remap_index]
#define _gloffset_VertexPointerEXT driDispatchRemapTable[VertexPointerEXT_remap_index]
#define _gloffset_DiscardFramebufferEXT driDispatchRemapTable[DiscardFramebufferEXT_remap_index]
#define _gloffset_ActiveShaderProgram driDispatchRemapTable[ActiveShaderProgram_remap_index]
#define _gloffset_BindProgramPipeline driDispatchRemapTable[BindProgramPipeline_remap_index]
#define _gloffset_CreateShaderProgramv driDispatchRemapTable[CreateShaderProgramv_remap_index]
#define _gloffset_DeleteProgramPipelines driDispatchRemapTable[DeleteProgramPipelines_remap_index]
#define _gloffset_GenProgramPipelines driDispatchRemapTable[GenProgramPipelines_remap_index]
#define _gloffset_GetProgramPipelineInfoLog driDispatchRemapTable[GetProgramPipelineInfoLog_remap_index]
#define _gloffset_GetProgramPipelineiv driDispatchRemapTable[GetProgramPipelineiv_remap_index]
#define _gloffset_IsProgramPipeline driDispatchRemapTable[IsProgramPipeline_remap_index]
#define _gloffset_LockArraysEXT driDispatchRemapTable[LockArraysEXT_remap_index]
#define _gloffset_ProgramUniform1d driDispatchRemapTable[ProgramUniform1d_remap_index]
#define _gloffset_ProgramUniform1dv driDispatchRemapTable[ProgramUniform1dv_remap_index]
#define _gloffset_ProgramUniform1f driDispatchRemapTable[ProgramUniform1f_remap_index]
#define _gloffset_ProgramUniform1fv driDispatchRemapTable[ProgramUniform1fv_remap_index]
#define _gloffset_ProgramUniform1i driDispatchRemapTable[ProgramUniform1i_remap_index]
#define _gloffset_ProgramUniform1iv driDispatchRemapTable[ProgramUniform1iv_remap_index]
#define _gloffset_ProgramUniform1ui driDispatchRemapTable[ProgramUniform1ui_remap_index]
#define _gloffset_ProgramUniform1uiv driDispatchRemapTable[ProgramUniform1uiv_remap_index]
#define _gloffset_ProgramUniform2d driDispatchRemapTable[ProgramUniform2d_remap_index]
#define _gloffset_ProgramUniform2dv driDispatchRemapTable[ProgramUniform2dv_remap_index]
#define _gloffset_ProgramUniform2f driDispatchRemapTable[ProgramUniform2f_remap_index]
#define _gloffset_ProgramUniform2fv driDispatchRemapTable[ProgramUniform2fv_remap_index]
#define _gloffset_ProgramUniform2i driDispatchRemapTable[ProgramUniform2i_remap_index]
#define _gloffset_ProgramUniform2iv driDispatchRemapTable[ProgramUniform2iv_remap_index]
#define _gloffset_ProgramUniform2ui driDispatchRemapTable[ProgramUniform2ui_remap_index]
#define _gloffset_ProgramUniform2uiv driDispatchRemapTable[ProgramUniform2uiv_remap_index]
#define _gloffset_ProgramUniform3d driDispatchRemapTable[ProgramUniform3d_remap_index]
#define _gloffset_ProgramUniform3dv driDispatchRemapTable[ProgramUniform3dv_remap_index]
#define _gloffset_ProgramUniform3f driDispatchRemapTable[ProgramUniform3f_remap_index]
#define _gloffset_ProgramUniform3fv driDispatchRemapTable[ProgramUniform3fv_remap_index]
#define _gloffset_ProgramUniform3i driDispatchRemapTable[ProgramUniform3i_remap_index]
#define _gloffset_ProgramUniform3iv driDispatchRemapTable[ProgramUniform3iv_remap_index]
#define _gloffset_ProgramUniform3ui driDispatchRemapTable[ProgramUniform3ui_remap_index]
#define _gloffset_ProgramUniform3uiv driDispatchRemapTable[ProgramUniform3uiv_remap_index]
#define _gloffset_ProgramUniform4d driDispatchRemapTable[ProgramUniform4d_remap_index]
#define _gloffset_ProgramUniform4dv driDispatchRemapTable[ProgramUniform4dv_remap_index]
#define _gloffset_ProgramUniform4f driDispatchRemapTable[ProgramUniform4f_remap_index]
#define _gloffset_ProgramUniform4fv driDispatchRemapTable[ProgramUniform4fv_remap_index]
#define _gloffset_ProgramUniform4i driDispatchRemapTable[ProgramUniform4i_remap_index]
#define _gloffset_ProgramUniform4iv driDispatchRemapTable[ProgramUniform4iv_remap_index]
#define _gloffset_ProgramUniform4ui driDispatchRemapTable[ProgramUniform4ui_remap_index]
#define _gloffset_ProgramUniform4uiv driDispatchRemapTable[ProgramUniform4uiv_remap_index]
#define _gloffset_ProgramUniformMatrix2dv driDispatchRemapTable[ProgramUniformMatrix2dv_remap_index]
#define _gloffset_ProgramUniformMatrix2fv driDispatchRemapTable[ProgramUniformMatrix2fv_remap_index]
#define _gloffset_ProgramUniformMatrix2x3dv driDispatchRemapTable[ProgramUniformMatrix2x3dv_remap_index]
#define _gloffset_ProgramUniformMatrix2x3fv driDispatchRemapTable[ProgramUniformMatrix2x3fv_remap_index]
#define _gloffset_ProgramUniformMatrix2x4dv driDispatchRemapTable[ProgramUniformMatrix2x4dv_remap_index]
#define _gloffset_ProgramUniformMatrix2x4fv driDispatchRemapTable[ProgramUniformMatrix2x4fv_remap_index]
#define _gloffset_ProgramUniformMatrix3dv driDispatchRemapTable[ProgramUniformMatrix3dv_remap_index]
#define _gloffset_ProgramUniformMatrix3fv driDispatchRemapTable[ProgramUniformMatrix3fv_remap_index]
#define _gloffset_ProgramUniformMatrix3x2dv driDispatchRemapTable[ProgramUniformMatrix3x2dv_remap_index]
#define _gloffset_ProgramUniformMatrix3x2fv driDispatchRemapTable[ProgramUniformMatrix3x2fv_remap_index]
#define _gloffset_ProgramUniformMatrix3x4dv driDispatchRemapTable[ProgramUniformMatrix3x4dv_remap_index]
#define _gloffset_ProgramUniformMatrix3x4fv driDispatchRemapTable[ProgramUniformMatrix3x4fv_remap_index]
#define _gloffset_ProgramUniformMatrix4dv driDispatchRemapTable[ProgramUniformMatrix4dv_remap_index]
#define _gloffset_ProgramUniformMatrix4fv driDispatchRemapTable[ProgramUniformMatrix4fv_remap_index]
#define _gloffset_ProgramUniformMatrix4x2dv driDispatchRemapTable[ProgramUniformMatrix4x2dv_remap_index]
#define _gloffset_ProgramUniformMatrix4x2fv driDispatchRemapTable[ProgramUniformMatrix4x2fv_remap_index]
#define _gloffset_ProgramUniformMatrix4x3dv driDispatchRemapTable[ProgramUniformMatrix4x3dv_remap_index]
#define _gloffset_ProgramUniformMatrix4x3fv driDispatchRemapTable[ProgramUniformMatrix4x3fv_remap_index]
#define _gloffset_UnlockArraysEXT driDispatchRemapTable[UnlockArraysEXT_remap_index]
#define _gloffset_UseProgramStages driDispatchRemapTable[UseProgramStages_remap_index]
#define _gloffset_ValidateProgramPipeline driDispatchRemapTable[ValidateProgramPipeline_remap_index]
#define _gloffset_DebugMessageCallback driDispatchRemapTable[DebugMessageCallback_remap_index]
#define _gloffset_DebugMessageControl driDispatchRemapTable[DebugMessageControl_remap_index]
#define _gloffset_DebugMessageInsert driDispatchRemapTable[DebugMessageInsert_remap_index]
#define _gloffset_GetDebugMessageLog driDispatchRemapTable[GetDebugMessageLog_remap_index]
#define _gloffset_GetObjectLabel driDispatchRemapTable[GetObjectLabel_remap_index]
#define _gloffset_GetObjectPtrLabel driDispatchRemapTable[GetObjectPtrLabel_remap_index]
#define _gloffset_ObjectLabel driDispatchRemapTable[ObjectLabel_remap_index]
#define _gloffset_ObjectPtrLabel driDispatchRemapTable[ObjectPtrLabel_remap_index]
#define _gloffset_PopDebugGroup driDispatchRemapTable[PopDebugGroup_remap_index]
#define _gloffset_PushDebugGroup driDispatchRemapTable[PushDebugGroup_remap_index]
#define _gloffset_SecondaryColor3fEXT driDispatchRemapTable[SecondaryColor3fEXT_remap_index]
#define _gloffset_SecondaryColor3fvEXT driDispatchRemapTable[SecondaryColor3fvEXT_remap_index]
#define _gloffset_MultiDrawElementsEXT driDispatchRemapTable[MultiDrawElementsEXT_remap_index]
#define _gloffset_FogCoordfEXT driDispatchRemapTable[FogCoordfEXT_remap_index]
#define _gloffset_FogCoordfvEXT driDispatchRemapTable[FogCoordfvEXT_remap_index]
#define _gloffset_ResizeBuffersMESA driDispatchRemapTable[ResizeBuffersMESA_remap_index]
#define _gloffset_WindowPos4dMESA driDispatchRemapTable[WindowPos4dMESA_remap_index]
#define _gloffset_WindowPos4dvMESA driDispatchRemapTable[WindowPos4dvMESA_remap_index]
#define _gloffset_WindowPos4fMESA driDispatchRemapTable[WindowPos4fMESA_remap_index]
#define _gloffset_WindowPos4fvMESA driDispatchRemapTable[WindowPos4fvMESA_remap_index]
#define _gloffset_WindowPos4iMESA driDispatchRemapTable[WindowPos4iMESA_remap_index]
#define _gloffset_WindowPos4ivMESA driDispatchRemapTable[WindowPos4ivMESA_remap_index]
#define _gloffset_WindowPos4sMESA driDispatchRemapTable[WindowPos4sMESA_remap_index]
#define _gloffset_WindowPos4svMESA driDispatchRemapTable[WindowPos4svMESA_remap_index]
#define _gloffset_MultiModeDrawArraysIBM driDispatchRemapTable[MultiModeDrawArraysIBM_remap_index]
#define _gloffset_MultiModeDrawElementsIBM driDispatchRemapTable[MultiModeDrawElementsIBM_remap_index]
#define _gloffset_AreProgramsResidentNV driDispatchRemapTable[AreProgramsResidentNV_remap_index]
#define _gloffset_ExecuteProgramNV driDispatchRemapTable[ExecuteProgramNV_remap_index]
#define _gloffset_GetProgramParameterdvNV driDispatchRemapTable[GetProgramParameterdvNV_remap_index]
#define _gloffset_GetProgramParameterfvNV driDispatchRemapTable[GetProgramParameterfvNV_remap_index]
#define _gloffset_GetProgramStringNV driDispatchRemapTable[GetProgramStringNV_remap_index]
#define _gloffset_GetProgramivNV driDispatchRemapTable[GetProgramivNV_remap_index]
#define _gloffset_GetTrackMatrixivNV driDispatchRemapTable[GetTrackMatrixivNV_remap_index]
#define _gloffset_GetVertexAttribdvNV driDispatchRemapTable[GetVertexAttribdvNV_remap_index]
#define _gloffset_GetVertexAttribfvNV driDispatchRemapTable[GetVertexAttribfvNV_remap_index]
#define _gloffset_GetVertexAttribivNV driDispatchRemapTable[GetVertexAttribivNV_remap_index]
#define _gloffset_LoadProgramNV driDispatchRemapTable[LoadProgramNV_remap_index]
#define _gloffset_ProgramParameters4dvNV driDispatchRemapTable[ProgramParameters4dvNV_remap_index]
#define _gloffset_ProgramParameters4fvNV driDispatchRemapTable[ProgramParameters4fvNV_remap_index]
#define _gloffset_RequestResidentProgramsNV driDispatchRemapTable[RequestResidentProgramsNV_remap_index]
#define _gloffset_TrackMatrixNV driDispatchRemapTable[TrackMatrixNV_remap_index]
#define _gloffset_VertexAttrib1dNV driDispatchRemapTable[VertexAttrib1dNV_remap_index]
#define _gloffset_VertexAttrib1dvNV driDispatchRemapTable[VertexAttrib1dvNV_remap_index]
#define _gloffset_VertexAttrib1fNV driDispatchRemapTable[VertexAttrib1fNV_remap_index]
#define _gloffset_VertexAttrib1fvNV driDispatchRemapTable[VertexAttrib1fvNV_remap_index]
#define _gloffset_VertexAttrib1sNV driDispatchRemapTable[VertexAttrib1sNV_remap_index]
#define _gloffset_VertexAttrib1svNV driDispatchRemapTable[VertexAttrib1svNV_remap_index]
#define _gloffset_VertexAttrib2dNV driDispatchRemapTable[VertexAttrib2dNV_remap_index]
#define _gloffset_VertexAttrib2dvNV driDispatchRemapTable[VertexAttrib2dvNV_remap_index]
#define _gloffset_VertexAttrib2fNV driDispatchRemapTable[VertexAttrib2fNV_remap_index]
#define _gloffset_VertexAttrib2fvNV driDispatchRemapTable[VertexAttrib2fvNV_remap_index]
#define _gloffset_VertexAttrib2sNV driDispatchRemapTable[VertexAttrib2sNV_remap_index]
#define _gloffset_VertexAttrib2svNV driDispatchRemapTable[VertexAttrib2svNV_remap_index]
#define _gloffset_VertexAttrib3dNV driDispatchRemapTable[VertexAttrib3dNV_remap_index]
#define _gloffset_VertexAttrib3dvNV driDispatchRemapTable[VertexAttrib3dvNV_remap_index]
#define _gloffset_VertexAttrib3fNV driDispatchRemapTable[VertexAttrib3fNV_remap_index]
#define _gloffset_VertexAttrib3fvNV driDispatchRemapTable[VertexAttrib3fvNV_remap_index]
#define _gloffset_VertexAttrib3sNV driDispatchRemapTable[VertexAttrib3sNV_remap_index]
#define _gloffset_VertexAttrib3svNV driDispatchRemapTable[VertexAttrib3svNV_remap_index]
#define _gloffset_VertexAttrib4dNV driDispatchRemapTable[VertexAttrib4dNV_remap_index]
#define _gloffset_VertexAttrib4dvNV driDispatchRemapTable[VertexAttrib4dvNV_remap_index]
#define _gloffset_VertexAttrib4fNV driDispatchRemapTable[VertexAttrib4fNV_remap_index]
#define _gloffset_VertexAttrib4fvNV driDispatchRemapTable[VertexAttrib4fvNV_remap_index]
#define _gloffset_VertexAttrib4sNV driDispatchRemapTable[VertexAttrib4sNV_remap_index]
#define _gloffset_VertexAttrib4svNV driDispatchRemapTable[VertexAttrib4svNV_remap_index]
#define _gloffset_VertexAttrib4ubNV driDispatchRemapTable[VertexAttrib4ubNV_remap_index]
#define _gloffset_VertexAttrib4ubvNV driDispatchRemapTable[VertexAttrib4ubvNV_remap_index]
#define _gloffset_VertexAttribPointerNV driDispatchRemapTable[VertexAttribPointerNV_remap_index]
#define _gloffset_VertexAttribs1dvNV driDispatchRemapTable[VertexAttribs1dvNV_remap_index]
#define _gloffset_VertexAttribs1fvNV driDispatchRemapTable[VertexAttribs1fvNV_remap_index]
#define _gloffset_VertexAttribs1svNV driDispatchRemapTable[VertexAttribs1svNV_remap_index]
#define _gloffset_VertexAttribs2dvNV driDispatchRemapTable[VertexAttribs2dvNV_remap_index]
#define _gloffset_VertexAttribs2fvNV driDispatchRemapTable[VertexAttribs2fvNV_remap_index]
#define _gloffset_VertexAttribs2svNV driDispatchRemapTable[VertexAttribs2svNV_remap_index]
#define _gloffset_VertexAttribs3dvNV driDispatchRemapTable[VertexAttribs3dvNV_remap_index]
#define _gloffset_VertexAttribs3fvNV driDispatchRemapTable[VertexAttribs3fvNV_remap_index]
#define _gloffset_VertexAttribs3svNV driDispatchRemapTable[VertexAttribs3svNV_remap_index]
#define _gloffset_VertexAttribs4dvNV driDispatchRemapTable[VertexAttribs4dvNV_remap_index]
#define _gloffset_VertexAttribs4fvNV driDispatchRemapTable[VertexAttribs4fvNV_remap_index]
#define _gloffset_VertexAttribs4svNV driDispatchRemapTable[VertexAttribs4svNV_remap_index]
#define _gloffset_VertexAttribs4ubvNV driDispatchRemapTable[VertexAttribs4ubvNV_remap_index]
#define _gloffset_GetTexBumpParameterfvATI driDispatchRemapTable[GetTexBumpParameterfvATI_remap_index]
#define _gloffset_GetTexBumpParameterivATI driDispatchRemapTable[GetTexBumpParameterivATI_remap_index]
#define _gloffset_TexBumpParameterfvATI driDispatchRemapTable[TexBumpParameterfvATI_remap_index]
#define _gloffset_TexBumpParameterivATI driDispatchRemapTable[TexBumpParameterivATI_remap_index]
#define _gloffset_AlphaFragmentOp1ATI driDispatchRemapTable[AlphaFragmentOp1ATI_remap_index]
#define _gloffset_AlphaFragmentOp2ATI driDispatchRemapTable[AlphaFragmentOp2ATI_remap_index]
#define _gloffset_AlphaFragmentOp3ATI driDispatchRemapTable[AlphaFragmentOp3ATI_remap_index]
#define _gloffset_BeginFragmentShaderATI driDispatchRemapTable[BeginFragmentShaderATI_remap_index]
#define _gloffset_BindFragmentShaderATI driDispatchRemapTable[BindFragmentShaderATI_remap_index]
#define _gloffset_ColorFragmentOp1ATI driDispatchRemapTable[ColorFragmentOp1ATI_remap_index]
#define _gloffset_ColorFragmentOp2ATI driDispatchRemapTable[ColorFragmentOp2ATI_remap_index]
#define _gloffset_ColorFragmentOp3ATI driDispatchRemapTable[ColorFragmentOp3ATI_remap_index]
#define _gloffset_DeleteFragmentShaderATI driDispatchRemapTable[DeleteFragmentShaderATI_remap_index]
#define _gloffset_EndFragmentShaderATI driDispatchRemapTable[EndFragmentShaderATI_remap_index]
#define _gloffset_GenFragmentShadersATI driDispatchRemapTable[GenFragmentShadersATI_remap_index]
#define _gloffset_PassTexCoordATI driDispatchRemapTable[PassTexCoordATI_remap_index]
#define _gloffset_SampleMapATI driDispatchRemapTable[SampleMapATI_remap_index]
#define _gloffset_SetFragmentShaderConstantATI driDispatchRemapTable[SetFragmentShaderConstantATI_remap_index]
#define _gloffset_DepthRangeArrayfvOES driDispatchRemapTable[DepthRangeArrayfvOES_remap_index]
#define _gloffset_DepthRangeIndexedfOES driDispatchRemapTable[DepthRangeIndexedfOES_remap_index]
#define _gloffset_ActiveStencilFaceEXT driDispatchRemapTable[ActiveStencilFaceEXT_remap_index]
#define _gloffset_GetProgramNamedParameterdvNV driDispatchRemapTable[GetProgramNamedParameterdvNV_remap_index]
#define _gloffset_GetProgramNamedParameterfvNV driDispatchRemapTable[GetProgramNamedParameterfvNV_remap_index]
#define _gloffset_ProgramNamedParameter4dNV driDispatchRemapTable[ProgramNamedParameter4dNV_remap_index]
#define _gloffset_ProgramNamedParameter4dvNV driDispatchRemapTable[ProgramNamedParameter4dvNV_remap_index]
#define _gloffset_ProgramNamedParameter4fNV driDispatchRemapTable[ProgramNamedParameter4fNV_remap_index]
#define _gloffset_ProgramNamedParameter4fvNV driDispatchRemapTable[ProgramNamedParameter4fvNV_remap_index]
#define _gloffset_PrimitiveRestartNV driDispatchRemapTable[PrimitiveRestartNV_remap_index]
#define _gloffset_GetTexGenxvOES driDispatchRemapTable[GetTexGenxvOES_remap_index]
#define _gloffset_TexGenxOES driDispatchRemapTable[TexGenxOES_remap_index]
#define _gloffset_TexGenxvOES driDispatchRemapTable[TexGenxvOES_remap_index]
#define _gloffset_DepthBoundsEXT driDispatchRemapTable[DepthBoundsEXT_remap_index]
#define _gloffset_BindFramebufferEXT driDispatchRemapTable[BindFramebufferEXT_remap_index]
#define _gloffset_BindRenderbufferEXT driDispatchRemapTable[BindRenderbufferEXT_remap_index]
#define _gloffset_StringMarkerGREMEDY driDispatchRemapTable[StringMarkerGREMEDY_remap_index]
#define _gloffset_BufferParameteriAPPLE driDispatchRemapTable[BufferParameteriAPPLE_remap_index]
#define _gloffset_FlushMappedBufferRangeAPPLE driDispatchRemapTable[FlushMappedBufferRangeAPPLE_remap_index]
#define _gloffset_VertexAttribI1iEXT driDispatchRemapTable[VertexAttribI1iEXT_remap_index]
#define _gloffset_VertexAttribI1uiEXT driDispatchRemapTable[VertexAttribI1uiEXT_remap_index]
#define _gloffset_VertexAttribI2iEXT driDispatchRemapTable[VertexAttribI2iEXT_remap_index]
#define _gloffset_VertexAttribI2ivEXT driDispatchRemapTable[VertexAttribI2ivEXT_remap_index]
#define _gloffset_VertexAttribI2uiEXT driDispatchRemapTable[VertexAttribI2uiEXT_remap_index]
#define _gloffset_VertexAttribI2uivEXT driDispatchRemapTable[VertexAttribI2uivEXT_remap_index]
#define _gloffset_VertexAttribI3iEXT driDispatchRemapTable[VertexAttribI3iEXT_remap_index]
#define _gloffset_VertexAttribI3ivEXT driDispatchRemapTable[VertexAttribI3ivEXT_remap_index]
#define _gloffset_VertexAttribI3uiEXT driDispatchRemapTable[VertexAttribI3uiEXT_remap_index]
#define _gloffset_VertexAttribI3uivEXT driDispatchRemapTable[VertexAttribI3uivEXT_remap_index]
#define _gloffset_VertexAttribI4iEXT driDispatchRemapTable[VertexAttribI4iEXT_remap_index]
#define _gloffset_VertexAttribI4ivEXT driDispatchRemapTable[VertexAttribI4ivEXT_remap_index]
#define _gloffset_VertexAttribI4uiEXT driDispatchRemapTable[VertexAttribI4uiEXT_remap_index]
#define _gloffset_VertexAttribI4uivEXT driDispatchRemapTable[VertexAttribI4uivEXT_remap_index]
#define _gloffset_ClearColorIiEXT driDispatchRemapTable[ClearColorIiEXT_remap_index]
#define _gloffset_ClearColorIuiEXT driDispatchRemapTable[ClearColorIuiEXT_remap_index]
#define _gloffset_BindBufferOffsetEXT driDispatchRemapTable[BindBufferOffsetEXT_remap_index]
#define _gloffset_BeginPerfMonitorAMD driDispatchRemapTable[BeginPerfMonitorAMD_remap_index]
#define _gloffset_DeletePerfMonitorsAMD driDispatchRemapTable[DeletePerfMonitorsAMD_remap_index]
#define _gloffset_EndPerfMonitorAMD driDispatchRemapTable[EndPerfMonitorAMD_remap_index]
#define _gloffset_GenPerfMonitorsAMD driDispatchRemapTable[GenPerfMonitorsAMD_remap_index]
#define _gloffset_GetPerfMonitorCounterDataAMD driDispatchRemapTable[GetPerfMonitorCounterDataAMD_remap_index]
#define _gloffset_GetPerfMonitorCounterInfoAMD driDispatchRemapTable[GetPerfMonitorCounterInfoAMD_remap_index]
#define _gloffset_GetPerfMonitorCounterStringAMD driDispatchRemapTable[GetPerfMonitorCounterStringAMD_remap_index]
#define _gloffset_GetPerfMonitorCountersAMD driDispatchRemapTable[GetPerfMonitorCountersAMD_remap_index]
#define _gloffset_GetPerfMonitorGroupStringAMD driDispatchRemapTable[GetPerfMonitorGroupStringAMD_remap_index]
#define _gloffset_GetPerfMonitorGroupsAMD driDispatchRemapTable[GetPerfMonitorGroupsAMD_remap_index]
#define _gloffset_SelectPerfMonitorCountersAMD driDispatchRemapTable[SelectPerfMonitorCountersAMD_remap_index]
#define _gloffset_GetObjectParameterivAPPLE driDispatchRemapTable[GetObjectParameterivAPPLE_remap_index]
#define _gloffset_ObjectPurgeableAPPLE driDispatchRemapTable[ObjectPurgeableAPPLE_remap_index]
#define _gloffset_ObjectUnpurgeableAPPLE driDispatchRemapTable[ObjectUnpurgeableAPPLE_remap_index]
#define _gloffset_ActiveProgramEXT driDispatchRemapTable[ActiveProgramEXT_remap_index]
#define _gloffset_CreateShaderProgramEXT driDispatchRemapTable[CreateShaderProgramEXT_remap_index]
#define _gloffset_UseShaderProgramEXT driDispatchRemapTable[UseShaderProgramEXT_remap_index]
#define _gloffset_TextureBarrierNV driDispatchRemapTable[TextureBarrierNV_remap_index]
#define _gloffset_VDPAUFiniNV driDispatchRemapTable[VDPAUFiniNV_remap_index]
#define _gloffset_VDPAUGetSurfaceivNV driDispatchRemapTable[VDPAUGetSurfaceivNV_remap_index]
#define _gloffset_VDPAUInitNV driDispatchRemapTable[VDPAUInitNV_remap_index]
#define _gloffset_VDPAUIsSurfaceNV driDispatchRemapTable[VDPAUIsSurfaceNV_remap_index]
#define _gloffset_VDPAUMapSurfacesNV driDispatchRemapTable[VDPAUMapSurfacesNV_remap_index]
#define _gloffset_VDPAURegisterOutputSurfaceNV driDispatchRemapTable[VDPAURegisterOutputSurfaceNV_remap_index]
#define _gloffset_VDPAURegisterVideoSurfaceNV driDispatchRemapTable[VDPAURegisterVideoSurfaceNV_remap_index]
#define _gloffset_VDPAUSurfaceAccessNV driDispatchRemapTable[VDPAUSurfaceAccessNV_remap_index]
#define _gloffset_VDPAUUnmapSurfacesNV driDispatchRemapTable[VDPAUUnmapSurfacesNV_remap_index]
#define _gloffset_VDPAUUnregisterSurfaceNV driDispatchRemapTable[VDPAUUnregisterSurfaceNV_remap_index]
#define _gloffset_BeginPerfQueryINTEL driDispatchRemapTable[BeginPerfQueryINTEL_remap_index]
#define _gloffset_CreatePerfQueryINTEL driDispatchRemapTable[CreatePerfQueryINTEL_remap_index]
#define _gloffset_DeletePerfQueryINTEL driDispatchRemapTable[DeletePerfQueryINTEL_remap_index]
#define _gloffset_EndPerfQueryINTEL driDispatchRemapTable[EndPerfQueryINTEL_remap_index]
#define _gloffset_GetFirstPerfQueryIdINTEL driDispatchRemapTable[GetFirstPerfQueryIdINTEL_remap_index]
#define _gloffset_GetNextPerfQueryIdINTEL driDispatchRemapTable[GetNextPerfQueryIdINTEL_remap_index]
#define _gloffset_GetPerfCounterInfoINTEL driDispatchRemapTable[GetPerfCounterInfoINTEL_remap_index]
#define _gloffset_GetPerfQueryDataINTEL driDispatchRemapTable[GetPerfQueryDataINTEL_remap_index]
#define _gloffset_GetPerfQueryIdByNameINTEL driDispatchRemapTable[GetPerfQueryIdByNameINTEL_remap_index]
#define _gloffset_GetPerfQueryInfoINTEL driDispatchRemapTable[GetPerfQueryInfoINTEL_remap_index]
#define _gloffset_PolygonOffsetClampEXT driDispatchRemapTable[PolygonOffsetClampEXT_remap_index]
#define _gloffset_WindowRectanglesEXT driDispatchRemapTable[WindowRectanglesEXT_remap_index]
#define _gloffset_BufferStorageMemEXT driDispatchRemapTable[BufferStorageMemEXT_remap_index]
#define _gloffset_CreateMemoryObjectsEXT driDispatchRemapTable[CreateMemoryObjectsEXT_remap_index]
#define _gloffset_DeleteMemoryObjectsEXT driDispatchRemapTable[DeleteMemoryObjectsEXT_remap_index]
#define _gloffset_DeleteSemaphoresEXT driDispatchRemapTable[DeleteSemaphoresEXT_remap_index]
#define _gloffset_GenSemaphoresEXT driDispatchRemapTable[GenSemaphoresEXT_remap_index]
#define _gloffset_GetMemoryObjectParameterivEXT driDispatchRemapTable[GetMemoryObjectParameterivEXT_remap_index]
#define _gloffset_GetSemaphoreParameterui64vEXT driDispatchRemapTable[GetSemaphoreParameterui64vEXT_remap_index]
#define _gloffset_GetUnsignedBytei_vEXT driDispatchRemapTable[GetUnsignedBytei_vEXT_remap_index]
#define _gloffset_GetUnsignedBytevEXT driDispatchRemapTable[GetUnsignedBytevEXT_remap_index]
#define _gloffset_IsMemoryObjectEXT driDispatchRemapTable[IsMemoryObjectEXT_remap_index]
#define _gloffset_IsSemaphoreEXT driDispatchRemapTable[IsSemaphoreEXT_remap_index]
#define _gloffset_MemoryObjectParameterivEXT driDispatchRemapTable[MemoryObjectParameterivEXT_remap_index]
#define _gloffset_NamedBufferStorageMemEXT driDispatchRemapTable[NamedBufferStorageMemEXT_remap_index]
#define _gloffset_SemaphoreParameterui64vEXT driDispatchRemapTable[SemaphoreParameterui64vEXT_remap_index]
#define _gloffset_SignalSemaphoreEXT driDispatchRemapTable[SignalSemaphoreEXT_remap_index]
#define _gloffset_TexStorageMem1DEXT driDispatchRemapTable[TexStorageMem1DEXT_remap_index]
#define _gloffset_TexStorageMem2DEXT driDispatchRemapTable[TexStorageMem2DEXT_remap_index]
#define _gloffset_TexStorageMem2DMultisampleEXT driDispatchRemapTable[TexStorageMem2DMultisampleEXT_remap_index]
#define _gloffset_TexStorageMem3DEXT driDispatchRemapTable[TexStorageMem3DEXT_remap_index]
#define _gloffset_TexStorageMem3DMultisampleEXT driDispatchRemapTable[TexStorageMem3DMultisampleEXT_remap_index]
#define _gloffset_TextureStorageMem1DEXT driDispatchRemapTable[TextureStorageMem1DEXT_remap_index]
#define _gloffset_TextureStorageMem2DEXT driDispatchRemapTable[TextureStorageMem2DEXT_remap_index]
#define _gloffset_TextureStorageMem2DMultisampleEXT driDispatchRemapTable[TextureStorageMem2DMultisampleEXT_remap_index]
#define _gloffset_TextureStorageMem3DEXT driDispatchRemapTable[TextureStorageMem3DEXT_remap_index]
#define _gloffset_TextureStorageMem3DMultisampleEXT driDispatchRemapTable[TextureStorageMem3DMultisampleEXT_remap_index]
#define _gloffset_WaitSemaphoreEXT driDispatchRemapTable[WaitSemaphoreEXT_remap_index]
#define _gloffset_ImportMemoryFdEXT driDispatchRemapTable[ImportMemoryFdEXT_remap_index]
#define _gloffset_ImportSemaphoreFdEXT driDispatchRemapTable[ImportSemaphoreFdEXT_remap_index]
#define _gloffset_StencilFuncSeparateATI driDispatchRemapTable[StencilFuncSeparateATI_remap_index]
#define _gloffset_ProgramEnvParameters4fvEXT driDispatchRemapTable[ProgramEnvParameters4fvEXT_remap_index]
#define _gloffset_ProgramLocalParameters4fvEXT driDispatchRemapTable[ProgramLocalParameters4fvEXT_remap_index]
#define _gloffset_EGLImageTargetRenderbufferStorageOES driDispatchRemapTable[EGLImageTargetRenderbufferStorageOES_remap_index]
#define _gloffset_EGLImageTargetTexture2DOES driDispatchRemapTable[EGLImageTargetTexture2DOES_remap_index]
#define _gloffset_AlphaFuncx driDispatchRemapTable[AlphaFuncx_remap_index]
#define _gloffset_ClearColorx driDispatchRemapTable[ClearColorx_remap_index]
#define _gloffset_ClearDepthx driDispatchRemapTable[ClearDepthx_remap_index]
#define _gloffset_Color4x driDispatchRemapTable[Color4x_remap_index]
#define _gloffset_DepthRangex driDispatchRemapTable[DepthRangex_remap_index]
#define _gloffset_Fogx driDispatchRemapTable[Fogx_remap_index]
#define _gloffset_Fogxv driDispatchRemapTable[Fogxv_remap_index]
#define _gloffset_Frustumf driDispatchRemapTable[Frustumf_remap_index]
#define _gloffset_Frustumx driDispatchRemapTable[Frustumx_remap_index]
#define _gloffset_LightModelx driDispatchRemapTable[LightModelx_remap_index]
#define _gloffset_LightModelxv driDispatchRemapTable[LightModelxv_remap_index]
#define _gloffset_Lightx driDispatchRemapTable[Lightx_remap_index]
#define _gloffset_Lightxv driDispatchRemapTable[Lightxv_remap_index]
#define _gloffset_LineWidthx driDispatchRemapTable[LineWidthx_remap_index]
#define _gloffset_LoadMatrixx driDispatchRemapTable[LoadMatrixx_remap_index]
#define _gloffset_Materialx driDispatchRemapTable[Materialx_remap_index]
#define _gloffset_Materialxv driDispatchRemapTable[Materialxv_remap_index]
#define _gloffset_MultMatrixx driDispatchRemapTable[MultMatrixx_remap_index]
#define _gloffset_MultiTexCoord4x driDispatchRemapTable[MultiTexCoord4x_remap_index]
#define _gloffset_Normal3x driDispatchRemapTable[Normal3x_remap_index]
#define _gloffset_Orthof driDispatchRemapTable[Orthof_remap_index]
#define _gloffset_Orthox driDispatchRemapTable[Orthox_remap_index]
#define _gloffset_PointSizex driDispatchRemapTable[PointSizex_remap_index]
#define _gloffset_PolygonOffsetx driDispatchRemapTable[PolygonOffsetx_remap_index]
#define _gloffset_Rotatex driDispatchRemapTable[Rotatex_remap_index]
#define _gloffset_SampleCoveragex driDispatchRemapTable[SampleCoveragex_remap_index]
#define _gloffset_Scalex driDispatchRemapTable[Scalex_remap_index]
#define _gloffset_TexEnvx driDispatchRemapTable[TexEnvx_remap_index]
#define _gloffset_TexEnvxv driDispatchRemapTable[TexEnvxv_remap_index]
#define _gloffset_TexParameterx driDispatchRemapTable[TexParameterx_remap_index]
#define _gloffset_Translatex driDispatchRemapTable[Translatex_remap_index]
#define _gloffset_ClipPlanef driDispatchRemapTable[ClipPlanef_remap_index]
#define _gloffset_ClipPlanex driDispatchRemapTable[ClipPlanex_remap_index]
#define _gloffset_GetClipPlanef driDispatchRemapTable[GetClipPlanef_remap_index]
#define _gloffset_GetClipPlanex driDispatchRemapTable[GetClipPlanex_remap_index]
#define _gloffset_GetFixedv driDispatchRemapTable[GetFixedv_remap_index]
#define _gloffset_GetLightxv driDispatchRemapTable[GetLightxv_remap_index]
#define _gloffset_GetMaterialxv driDispatchRemapTable[GetMaterialxv_remap_index]
#define _gloffset_GetTexEnvxv driDispatchRemapTable[GetTexEnvxv_remap_index]
#define _gloffset_GetTexParameterxv driDispatchRemapTable[GetTexParameterxv_remap_index]
#define _gloffset_PointParameterx driDispatchRemapTable[PointParameterx_remap_index]
#define _gloffset_PointParameterxv driDispatchRemapTable[PointParameterxv_remap_index]
#define _gloffset_TexParameterxv driDispatchRemapTable[TexParameterxv_remap_index]
#define _gloffset_BlendBarrier driDispatchRemapTable[BlendBarrier_remap_index]
#define _gloffset_PrimitiveBoundingBox driDispatchRemapTable[PrimitiveBoundingBox_remap_index]

typedef void (GLAPIENTRYP _glptr_NewList)(GLuint, GLenum);
#define CALL_NewList(disp, parameters) \
    (* GET_NewList(disp)) parameters
static inline _glptr_NewList GET_NewList(struct _glapi_table *disp) {
   return (_glptr_NewList) (GET_by_offset(disp, _gloffset_NewList));
}

static inline void SET_NewList(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_NewList, fn);
}

typedef void (GLAPIENTRYP _glptr_EndList)(void);
#define CALL_EndList(disp, parameters) \
    (* GET_EndList(disp)) parameters
static inline _glptr_EndList GET_EndList(struct _glapi_table *disp) {
   return (_glptr_EndList) (GET_by_offset(disp, _gloffset_EndList));
}

static inline void SET_EndList(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_EndList, fn);
}

typedef void (GLAPIENTRYP _glptr_CallList)(GLuint);
#define CALL_CallList(disp, parameters) \
    (* GET_CallList(disp)) parameters
static inline _glptr_CallList GET_CallList(struct _glapi_table *disp) {
   return (_glptr_CallList) (GET_by_offset(disp, _gloffset_CallList));
}

static inline void SET_CallList(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_CallList, fn);
}

typedef void (GLAPIENTRYP _glptr_CallLists)(GLsizei, GLenum, const GLvoid *);
#define CALL_CallLists(disp, parameters) \
    (* GET_CallLists(disp)) parameters
static inline _glptr_CallLists GET_CallLists(struct _glapi_table *disp) {
   return (_glptr_CallLists) (GET_by_offset(disp, _gloffset_CallLists));
}

static inline void SET_CallLists(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CallLists, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteLists)(GLuint, GLsizei);
#define CALL_DeleteLists(disp, parameters) \
    (* GET_DeleteLists(disp)) parameters
static inline _glptr_DeleteLists GET_DeleteLists(struct _glapi_table *disp) {
   return (_glptr_DeleteLists) (GET_by_offset(disp, _gloffset_DeleteLists));
}

static inline void SET_DeleteLists(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei)) {
   SET_by_offset(disp, _gloffset_DeleteLists, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_GenLists)(GLsizei);
#define CALL_GenLists(disp, parameters) \
    (* GET_GenLists(disp)) parameters
static inline _glptr_GenLists GET_GenLists(struct _glapi_table *disp) {
   return (_glptr_GenLists) (GET_by_offset(disp, _gloffset_GenLists));
}

static inline void SET_GenLists(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLsizei)) {
   SET_by_offset(disp, _gloffset_GenLists, fn);
}

typedef void (GLAPIENTRYP _glptr_ListBase)(GLuint);
#define CALL_ListBase(disp, parameters) \
    (* GET_ListBase(disp)) parameters
static inline _glptr_ListBase GET_ListBase(struct _glapi_table *disp) {
   return (_glptr_ListBase) (GET_by_offset(disp, _gloffset_ListBase));
}

static inline void SET_ListBase(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_ListBase, fn);
}

typedef void (GLAPIENTRYP _glptr_Begin)(GLenum);
#define CALL_Begin(disp, parameters) \
    (* GET_Begin(disp)) parameters
static inline _glptr_Begin GET_Begin(struct _glapi_table *disp) {
   return (_glptr_Begin) (GET_by_offset(disp, _gloffset_Begin));
}

static inline void SET_Begin(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_Begin, fn);
}

typedef void (GLAPIENTRYP _glptr_Bitmap)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
#define CALL_Bitmap(disp, parameters) \
    (* GET_Bitmap(disp)) parameters
static inline _glptr_Bitmap GET_Bitmap(struct _glapi_table *disp) {
   return (_glptr_Bitmap) (GET_by_offset(disp, _gloffset_Bitmap));
}

static inline void SET_Bitmap(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_Bitmap, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3b)(GLbyte, GLbyte, GLbyte);
#define CALL_Color3b(disp, parameters) \
    (* GET_Color3b(disp)) parameters
static inline _glptr_Color3b GET_Color3b(struct _glapi_table *disp) {
   return (_glptr_Color3b) (GET_by_offset(disp, _gloffset_Color3b));
}

static inline void SET_Color3b(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbyte, GLbyte, GLbyte)) {
   SET_by_offset(disp, _gloffset_Color3b, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3bv)(const GLbyte *);
#define CALL_Color3bv(disp, parameters) \
    (* GET_Color3bv(disp)) parameters
static inline _glptr_Color3bv GET_Color3bv(struct _glapi_table *disp) {
   return (_glptr_Color3bv) (GET_by_offset(disp, _gloffset_Color3bv));
}

static inline void SET_Color3bv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLbyte *)) {
   SET_by_offset(disp, _gloffset_Color3bv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3d)(GLdouble, GLdouble, GLdouble);
#define CALL_Color3d(disp, parameters) \
    (* GET_Color3d(disp)) parameters
static inline _glptr_Color3d GET_Color3d(struct _glapi_table *disp) {
   return (_glptr_Color3d) (GET_by_offset(disp, _gloffset_Color3d));
}

static inline void SET_Color3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Color3d, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3dv)(const GLdouble *);
#define CALL_Color3dv(disp, parameters) \
    (* GET_Color3dv(disp)) parameters
static inline _glptr_Color3dv GET_Color3dv(struct _glapi_table *disp) {
   return (_glptr_Color3dv) (GET_by_offset(disp, _gloffset_Color3dv));
}

static inline void SET_Color3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Color3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3f)(GLfloat, GLfloat, GLfloat);
#define CALL_Color3f(disp, parameters) \
    (* GET_Color3f(disp)) parameters
static inline _glptr_Color3f GET_Color3f(struct _glapi_table *disp) {
   return (_glptr_Color3f) (GET_by_offset(disp, _gloffset_Color3f));
}

static inline void SET_Color3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Color3f, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3fv)(const GLfloat *);
#define CALL_Color3fv(disp, parameters) \
    (* GET_Color3fv(disp)) parameters
static inline _glptr_Color3fv GET_Color3fv(struct _glapi_table *disp) {
   return (_glptr_Color3fv) (GET_by_offset(disp, _gloffset_Color3fv));
}

static inline void SET_Color3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Color3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3i)(GLint, GLint, GLint);
#define CALL_Color3i(disp, parameters) \
    (* GET_Color3i(disp)) parameters
static inline _glptr_Color3i GET_Color3i(struct _glapi_table *disp) {
   return (_glptr_Color3i) (GET_by_offset(disp, _gloffset_Color3i));
}

static inline void SET_Color3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Color3i, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3iv)(const GLint *);
#define CALL_Color3iv(disp, parameters) \
    (* GET_Color3iv(disp)) parameters
static inline _glptr_Color3iv GET_Color3iv(struct _glapi_table *disp) {
   return (_glptr_Color3iv) (GET_by_offset(disp, _gloffset_Color3iv));
}

static inline void SET_Color3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Color3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3s)(GLshort, GLshort, GLshort);
#define CALL_Color3s(disp, parameters) \
    (* GET_Color3s(disp)) parameters
static inline _glptr_Color3s GET_Color3s(struct _glapi_table *disp) {
   return (_glptr_Color3s) (GET_by_offset(disp, _gloffset_Color3s));
}

static inline void SET_Color3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Color3s, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3sv)(const GLshort *);
#define CALL_Color3sv(disp, parameters) \
    (* GET_Color3sv(disp)) parameters
static inline _glptr_Color3sv GET_Color3sv(struct _glapi_table *disp) {
   return (_glptr_Color3sv) (GET_by_offset(disp, _gloffset_Color3sv));
}

static inline void SET_Color3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Color3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3ub)(GLubyte, GLubyte, GLubyte);
#define CALL_Color3ub(disp, parameters) \
    (* GET_Color3ub(disp)) parameters
static inline _glptr_Color3ub GET_Color3ub(struct _glapi_table *disp) {
   return (_glptr_Color3ub) (GET_by_offset(disp, _gloffset_Color3ub));
}

static inline void SET_Color3ub(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLubyte, GLubyte, GLubyte)) {
   SET_by_offset(disp, _gloffset_Color3ub, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3ubv)(const GLubyte *);
#define CALL_Color3ubv(disp, parameters) \
    (* GET_Color3ubv(disp)) parameters
static inline _glptr_Color3ubv GET_Color3ubv(struct _glapi_table *disp) {
   return (_glptr_Color3ubv) (GET_by_offset(disp, _gloffset_Color3ubv));
}

static inline void SET_Color3ubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLubyte *)) {
   SET_by_offset(disp, _gloffset_Color3ubv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3ui)(GLuint, GLuint, GLuint);
#define CALL_Color3ui(disp, parameters) \
    (* GET_Color3ui(disp)) parameters
static inline _glptr_Color3ui GET_Color3ui(struct _glapi_table *disp) {
   return (_glptr_Color3ui) (GET_by_offset(disp, _gloffset_Color3ui));
}

static inline void SET_Color3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_Color3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3uiv)(const GLuint *);
#define CALL_Color3uiv(disp, parameters) \
    (* GET_Color3uiv(disp)) parameters
static inline _glptr_Color3uiv GET_Color3uiv(struct _glapi_table *disp) {
   return (_glptr_Color3uiv) (GET_by_offset(disp, _gloffset_Color3uiv));
}

static inline void SET_Color3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLuint *)) {
   SET_by_offset(disp, _gloffset_Color3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3us)(GLushort, GLushort, GLushort);
#define CALL_Color3us(disp, parameters) \
    (* GET_Color3us(disp)) parameters
static inline _glptr_Color3us GET_Color3us(struct _glapi_table *disp) {
   return (_glptr_Color3us) (GET_by_offset(disp, _gloffset_Color3us));
}

static inline void SET_Color3us(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLushort, GLushort, GLushort)) {
   SET_by_offset(disp, _gloffset_Color3us, fn);
}

typedef void (GLAPIENTRYP _glptr_Color3usv)(const GLushort *);
#define CALL_Color3usv(disp, parameters) \
    (* GET_Color3usv(disp)) parameters
static inline _glptr_Color3usv GET_Color3usv(struct _glapi_table *disp) {
   return (_glptr_Color3usv) (GET_by_offset(disp, _gloffset_Color3usv));
}

static inline void SET_Color3usv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLushort *)) {
   SET_by_offset(disp, _gloffset_Color3usv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4b)(GLbyte, GLbyte, GLbyte, GLbyte);
#define CALL_Color4b(disp, parameters) \
    (* GET_Color4b(disp)) parameters
static inline _glptr_Color4b GET_Color4b(struct _glapi_table *disp) {
   return (_glptr_Color4b) (GET_by_offset(disp, _gloffset_Color4b));
}

static inline void SET_Color4b(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbyte, GLbyte, GLbyte, GLbyte)) {
   SET_by_offset(disp, _gloffset_Color4b, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4bv)(const GLbyte *);
#define CALL_Color4bv(disp, parameters) \
    (* GET_Color4bv(disp)) parameters
static inline _glptr_Color4bv GET_Color4bv(struct _glapi_table *disp) {
   return (_glptr_Color4bv) (GET_by_offset(disp, _gloffset_Color4bv));
}

static inline void SET_Color4bv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLbyte *)) {
   SET_by_offset(disp, _gloffset_Color4bv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Color4d(disp, parameters) \
    (* GET_Color4d(disp)) parameters
static inline _glptr_Color4d GET_Color4d(struct _glapi_table *disp) {
   return (_glptr_Color4d) (GET_by_offset(disp, _gloffset_Color4d));
}

static inline void SET_Color4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Color4d, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4dv)(const GLdouble *);
#define CALL_Color4dv(disp, parameters) \
    (* GET_Color4dv(disp)) parameters
static inline _glptr_Color4dv GET_Color4dv(struct _glapi_table *disp) {
   return (_glptr_Color4dv) (GET_by_offset(disp, _gloffset_Color4dv));
}

static inline void SET_Color4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Color4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Color4f(disp, parameters) \
    (* GET_Color4f(disp)) parameters
static inline _glptr_Color4f GET_Color4f(struct _glapi_table *disp) {
   return (_glptr_Color4f) (GET_by_offset(disp, _gloffset_Color4f));
}

static inline void SET_Color4f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Color4f, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4fv)(const GLfloat *);
#define CALL_Color4fv(disp, parameters) \
    (* GET_Color4fv(disp)) parameters
static inline _glptr_Color4fv GET_Color4fv(struct _glapi_table *disp) {
   return (_glptr_Color4fv) (GET_by_offset(disp, _gloffset_Color4fv));
}

static inline void SET_Color4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Color4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4i)(GLint, GLint, GLint, GLint);
#define CALL_Color4i(disp, parameters) \
    (* GET_Color4i(disp)) parameters
static inline _glptr_Color4i GET_Color4i(struct _glapi_table *disp) {
   return (_glptr_Color4i) (GET_by_offset(disp, _gloffset_Color4i));
}

static inline void SET_Color4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Color4i, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4iv)(const GLint *);
#define CALL_Color4iv(disp, parameters) \
    (* GET_Color4iv(disp)) parameters
static inline _glptr_Color4iv GET_Color4iv(struct _glapi_table *disp) {
   return (_glptr_Color4iv) (GET_by_offset(disp, _gloffset_Color4iv));
}

static inline void SET_Color4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Color4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4s)(GLshort, GLshort, GLshort, GLshort);
#define CALL_Color4s(disp, parameters) \
    (* GET_Color4s(disp)) parameters
static inline _glptr_Color4s GET_Color4s(struct _glapi_table *disp) {
   return (_glptr_Color4s) (GET_by_offset(disp, _gloffset_Color4s));
}

static inline void SET_Color4s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Color4s, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4sv)(const GLshort *);
#define CALL_Color4sv(disp, parameters) \
    (* GET_Color4sv(disp)) parameters
static inline _glptr_Color4sv GET_Color4sv(struct _glapi_table *disp) {
   return (_glptr_Color4sv) (GET_by_offset(disp, _gloffset_Color4sv));
}

static inline void SET_Color4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Color4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4ub)(GLubyte, GLubyte, GLubyte, GLubyte);
#define CALL_Color4ub(disp, parameters) \
    (* GET_Color4ub(disp)) parameters
static inline _glptr_Color4ub GET_Color4ub(struct _glapi_table *disp) {
   return (_glptr_Color4ub) (GET_by_offset(disp, _gloffset_Color4ub));
}

static inline void SET_Color4ub(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLubyte, GLubyte, GLubyte, GLubyte)) {
   SET_by_offset(disp, _gloffset_Color4ub, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4ubv)(const GLubyte *);
#define CALL_Color4ubv(disp, parameters) \
    (* GET_Color4ubv(disp)) parameters
static inline _glptr_Color4ubv GET_Color4ubv(struct _glapi_table *disp) {
   return (_glptr_Color4ubv) (GET_by_offset(disp, _gloffset_Color4ubv));
}

static inline void SET_Color4ubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLubyte *)) {
   SET_by_offset(disp, _gloffset_Color4ubv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4ui)(GLuint, GLuint, GLuint, GLuint);
#define CALL_Color4ui(disp, parameters) \
    (* GET_Color4ui(disp)) parameters
static inline _glptr_Color4ui GET_Color4ui(struct _glapi_table *disp) {
   return (_glptr_Color4ui) (GET_by_offset(disp, _gloffset_Color4ui));
}

static inline void SET_Color4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_Color4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4uiv)(const GLuint *);
#define CALL_Color4uiv(disp, parameters) \
    (* GET_Color4uiv(disp)) parameters
static inline _glptr_Color4uiv GET_Color4uiv(struct _glapi_table *disp) {
   return (_glptr_Color4uiv) (GET_by_offset(disp, _gloffset_Color4uiv));
}

static inline void SET_Color4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLuint *)) {
   SET_by_offset(disp, _gloffset_Color4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4us)(GLushort, GLushort, GLushort, GLushort);
#define CALL_Color4us(disp, parameters) \
    (* GET_Color4us(disp)) parameters
static inline _glptr_Color4us GET_Color4us(struct _glapi_table *disp) {
   return (_glptr_Color4us) (GET_by_offset(disp, _gloffset_Color4us));
}

static inline void SET_Color4us(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLushort, GLushort, GLushort, GLushort)) {
   SET_by_offset(disp, _gloffset_Color4us, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4usv)(const GLushort *);
#define CALL_Color4usv(disp, parameters) \
    (* GET_Color4usv(disp)) parameters
static inline _glptr_Color4usv GET_Color4usv(struct _glapi_table *disp) {
   return (_glptr_Color4usv) (GET_by_offset(disp, _gloffset_Color4usv));
}

static inline void SET_Color4usv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLushort *)) {
   SET_by_offset(disp, _gloffset_Color4usv, fn);
}

typedef void (GLAPIENTRYP _glptr_EdgeFlag)(GLboolean);
#define CALL_EdgeFlag(disp, parameters) \
    (* GET_EdgeFlag(disp)) parameters
static inline _glptr_EdgeFlag GET_EdgeFlag(struct _glapi_table *disp) {
   return (_glptr_EdgeFlag) (GET_by_offset(disp, _gloffset_EdgeFlag));
}

static inline void SET_EdgeFlag(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLboolean)) {
   SET_by_offset(disp, _gloffset_EdgeFlag, fn);
}

typedef void (GLAPIENTRYP _glptr_EdgeFlagv)(const GLboolean *);
#define CALL_EdgeFlagv(disp, parameters) \
    (* GET_EdgeFlagv(disp)) parameters
static inline _glptr_EdgeFlagv GET_EdgeFlagv(struct _glapi_table *disp) {
   return (_glptr_EdgeFlagv) (GET_by_offset(disp, _gloffset_EdgeFlagv));
}

static inline void SET_EdgeFlagv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLboolean *)) {
   SET_by_offset(disp, _gloffset_EdgeFlagv, fn);
}

typedef void (GLAPIENTRYP _glptr_End)(void);
#define CALL_End(disp, parameters) \
    (* GET_End(disp)) parameters
static inline _glptr_End GET_End(struct _glapi_table *disp) {
   return (_glptr_End) (GET_by_offset(disp, _gloffset_End));
}

static inline void SET_End(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_End, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexd)(GLdouble);
#define CALL_Indexd(disp, parameters) \
    (* GET_Indexd(disp)) parameters
static inline _glptr_Indexd GET_Indexd(struct _glapi_table *disp) {
   return (_glptr_Indexd) (GET_by_offset(disp, _gloffset_Indexd));
}

static inline void SET_Indexd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble)) {
   SET_by_offset(disp, _gloffset_Indexd, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexdv)(const GLdouble *);
#define CALL_Indexdv(disp, parameters) \
    (* GET_Indexdv(disp)) parameters
static inline _glptr_Indexdv GET_Indexdv(struct _glapi_table *disp) {
   return (_glptr_Indexdv) (GET_by_offset(disp, _gloffset_Indexdv));
}

static inline void SET_Indexdv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Indexdv, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexf)(GLfloat);
#define CALL_Indexf(disp, parameters) \
    (* GET_Indexf(disp)) parameters
static inline _glptr_Indexf GET_Indexf(struct _glapi_table *disp) {
   return (_glptr_Indexf) (GET_by_offset(disp, _gloffset_Indexf));
}

static inline void SET_Indexf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_Indexf, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexfv)(const GLfloat *);
#define CALL_Indexfv(disp, parameters) \
    (* GET_Indexfv(disp)) parameters
static inline _glptr_Indexfv GET_Indexfv(struct _glapi_table *disp) {
   return (_glptr_Indexfv) (GET_by_offset(disp, _gloffset_Indexfv));
}

static inline void SET_Indexfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Indexfv, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexi)(GLint);
#define CALL_Indexi(disp, parameters) \
    (* GET_Indexi(disp)) parameters
static inline _glptr_Indexi GET_Indexi(struct _glapi_table *disp) {
   return (_glptr_Indexi) (GET_by_offset(disp, _gloffset_Indexi));
}

static inline void SET_Indexi(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint)) {
   SET_by_offset(disp, _gloffset_Indexi, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexiv)(const GLint *);
#define CALL_Indexiv(disp, parameters) \
    (* GET_Indexiv(disp)) parameters
static inline _glptr_Indexiv GET_Indexiv(struct _glapi_table *disp) {
   return (_glptr_Indexiv) (GET_by_offset(disp, _gloffset_Indexiv));
}

static inline void SET_Indexiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Indexiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexs)(GLshort);
#define CALL_Indexs(disp, parameters) \
    (* GET_Indexs(disp)) parameters
static inline _glptr_Indexs GET_Indexs(struct _glapi_table *disp) {
   return (_glptr_Indexs) (GET_by_offset(disp, _gloffset_Indexs));
}

static inline void SET_Indexs(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort)) {
   SET_by_offset(disp, _gloffset_Indexs, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexsv)(const GLshort *);
#define CALL_Indexsv(disp, parameters) \
    (* GET_Indexsv(disp)) parameters
static inline _glptr_Indexsv GET_Indexsv(struct _glapi_table *disp) {
   return (_glptr_Indexsv) (GET_by_offset(disp, _gloffset_Indexsv));
}

static inline void SET_Indexsv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Indexsv, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3b)(GLbyte, GLbyte, GLbyte);
#define CALL_Normal3b(disp, parameters) \
    (* GET_Normal3b(disp)) parameters
static inline _glptr_Normal3b GET_Normal3b(struct _glapi_table *disp) {
   return (_glptr_Normal3b) (GET_by_offset(disp, _gloffset_Normal3b));
}

static inline void SET_Normal3b(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbyte, GLbyte, GLbyte)) {
   SET_by_offset(disp, _gloffset_Normal3b, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3bv)(const GLbyte *);
#define CALL_Normal3bv(disp, parameters) \
    (* GET_Normal3bv(disp)) parameters
static inline _glptr_Normal3bv GET_Normal3bv(struct _glapi_table *disp) {
   return (_glptr_Normal3bv) (GET_by_offset(disp, _gloffset_Normal3bv));
}

static inline void SET_Normal3bv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLbyte *)) {
   SET_by_offset(disp, _gloffset_Normal3bv, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3d)(GLdouble, GLdouble, GLdouble);
#define CALL_Normal3d(disp, parameters) \
    (* GET_Normal3d(disp)) parameters
static inline _glptr_Normal3d GET_Normal3d(struct _glapi_table *disp) {
   return (_glptr_Normal3d) (GET_by_offset(disp, _gloffset_Normal3d));
}

static inline void SET_Normal3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Normal3d, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3dv)(const GLdouble *);
#define CALL_Normal3dv(disp, parameters) \
    (* GET_Normal3dv(disp)) parameters
static inline _glptr_Normal3dv GET_Normal3dv(struct _glapi_table *disp) {
   return (_glptr_Normal3dv) (GET_by_offset(disp, _gloffset_Normal3dv));
}

static inline void SET_Normal3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Normal3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3f)(GLfloat, GLfloat, GLfloat);
#define CALL_Normal3f(disp, parameters) \
    (* GET_Normal3f(disp)) parameters
static inline _glptr_Normal3f GET_Normal3f(struct _glapi_table *disp) {
   return (_glptr_Normal3f) (GET_by_offset(disp, _gloffset_Normal3f));
}

static inline void SET_Normal3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Normal3f, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3fv)(const GLfloat *);
#define CALL_Normal3fv(disp, parameters) \
    (* GET_Normal3fv(disp)) parameters
static inline _glptr_Normal3fv GET_Normal3fv(struct _glapi_table *disp) {
   return (_glptr_Normal3fv) (GET_by_offset(disp, _gloffset_Normal3fv));
}

static inline void SET_Normal3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Normal3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3i)(GLint, GLint, GLint);
#define CALL_Normal3i(disp, parameters) \
    (* GET_Normal3i(disp)) parameters
static inline _glptr_Normal3i GET_Normal3i(struct _glapi_table *disp) {
   return (_glptr_Normal3i) (GET_by_offset(disp, _gloffset_Normal3i));
}

static inline void SET_Normal3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Normal3i, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3iv)(const GLint *);
#define CALL_Normal3iv(disp, parameters) \
    (* GET_Normal3iv(disp)) parameters
static inline _glptr_Normal3iv GET_Normal3iv(struct _glapi_table *disp) {
   return (_glptr_Normal3iv) (GET_by_offset(disp, _gloffset_Normal3iv));
}

static inline void SET_Normal3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Normal3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3s)(GLshort, GLshort, GLshort);
#define CALL_Normal3s(disp, parameters) \
    (* GET_Normal3s(disp)) parameters
static inline _glptr_Normal3s GET_Normal3s(struct _glapi_table *disp) {
   return (_glptr_Normal3s) (GET_by_offset(disp, _gloffset_Normal3s));
}

static inline void SET_Normal3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Normal3s, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3sv)(const GLshort *);
#define CALL_Normal3sv(disp, parameters) \
    (* GET_Normal3sv(disp)) parameters
static inline _glptr_Normal3sv GET_Normal3sv(struct _glapi_table *disp) {
   return (_glptr_Normal3sv) (GET_by_offset(disp, _gloffset_Normal3sv));
}

static inline void SET_Normal3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Normal3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2d)(GLdouble, GLdouble);
#define CALL_RasterPos2d(disp, parameters) \
    (* GET_RasterPos2d(disp)) parameters
static inline _glptr_RasterPos2d GET_RasterPos2d(struct _glapi_table *disp) {
   return (_glptr_RasterPos2d) (GET_by_offset(disp, _gloffset_RasterPos2d));
}

static inline void SET_RasterPos2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_RasterPos2d, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2dv)(const GLdouble *);
#define CALL_RasterPos2dv(disp, parameters) \
    (* GET_RasterPos2dv(disp)) parameters
static inline _glptr_RasterPos2dv GET_RasterPos2dv(struct _glapi_table *disp) {
   return (_glptr_RasterPos2dv) (GET_by_offset(disp, _gloffset_RasterPos2dv));
}

static inline void SET_RasterPos2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_RasterPos2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2f)(GLfloat, GLfloat);
#define CALL_RasterPos2f(disp, parameters) \
    (* GET_RasterPos2f(disp)) parameters
static inline _glptr_RasterPos2f GET_RasterPos2f(struct _glapi_table *disp) {
   return (_glptr_RasterPos2f) (GET_by_offset(disp, _gloffset_RasterPos2f));
}

static inline void SET_RasterPos2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_RasterPos2f, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2fv)(const GLfloat *);
#define CALL_RasterPos2fv(disp, parameters) \
    (* GET_RasterPos2fv(disp)) parameters
static inline _glptr_RasterPos2fv GET_RasterPos2fv(struct _glapi_table *disp) {
   return (_glptr_RasterPos2fv) (GET_by_offset(disp, _gloffset_RasterPos2fv));
}

static inline void SET_RasterPos2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_RasterPos2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2i)(GLint, GLint);
#define CALL_RasterPos2i(disp, parameters) \
    (* GET_RasterPos2i(disp)) parameters
static inline _glptr_RasterPos2i GET_RasterPos2i(struct _glapi_table *disp) {
   return (_glptr_RasterPos2i) (GET_by_offset(disp, _gloffset_RasterPos2i));
}

static inline void SET_RasterPos2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint)) {
   SET_by_offset(disp, _gloffset_RasterPos2i, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2iv)(const GLint *);
#define CALL_RasterPos2iv(disp, parameters) \
    (* GET_RasterPos2iv(disp)) parameters
static inline _glptr_RasterPos2iv GET_RasterPos2iv(struct _glapi_table *disp) {
   return (_glptr_RasterPos2iv) (GET_by_offset(disp, _gloffset_RasterPos2iv));
}

static inline void SET_RasterPos2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_RasterPos2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2s)(GLshort, GLshort);
#define CALL_RasterPos2s(disp, parameters) \
    (* GET_RasterPos2s(disp)) parameters
static inline _glptr_RasterPos2s GET_RasterPos2s(struct _glapi_table *disp) {
   return (_glptr_RasterPos2s) (GET_by_offset(disp, _gloffset_RasterPos2s));
}

static inline void SET_RasterPos2s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_RasterPos2s, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos2sv)(const GLshort *);
#define CALL_RasterPos2sv(disp, parameters) \
    (* GET_RasterPos2sv(disp)) parameters
static inline _glptr_RasterPos2sv GET_RasterPos2sv(struct _glapi_table *disp) {
   return (_glptr_RasterPos2sv) (GET_by_offset(disp, _gloffset_RasterPos2sv));
}

static inline void SET_RasterPos2sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_RasterPos2sv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3d)(GLdouble, GLdouble, GLdouble);
#define CALL_RasterPos3d(disp, parameters) \
    (* GET_RasterPos3d(disp)) parameters
static inline _glptr_RasterPos3d GET_RasterPos3d(struct _glapi_table *disp) {
   return (_glptr_RasterPos3d) (GET_by_offset(disp, _gloffset_RasterPos3d));
}

static inline void SET_RasterPos3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_RasterPos3d, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3dv)(const GLdouble *);
#define CALL_RasterPos3dv(disp, parameters) \
    (* GET_RasterPos3dv(disp)) parameters
static inline _glptr_RasterPos3dv GET_RasterPos3dv(struct _glapi_table *disp) {
   return (_glptr_RasterPos3dv) (GET_by_offset(disp, _gloffset_RasterPos3dv));
}

static inline void SET_RasterPos3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_RasterPos3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3f)(GLfloat, GLfloat, GLfloat);
#define CALL_RasterPos3f(disp, parameters) \
    (* GET_RasterPos3f(disp)) parameters
static inline _glptr_RasterPos3f GET_RasterPos3f(struct _glapi_table *disp) {
   return (_glptr_RasterPos3f) (GET_by_offset(disp, _gloffset_RasterPos3f));
}

static inline void SET_RasterPos3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_RasterPos3f, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3fv)(const GLfloat *);
#define CALL_RasterPos3fv(disp, parameters) \
    (* GET_RasterPos3fv(disp)) parameters
static inline _glptr_RasterPos3fv GET_RasterPos3fv(struct _glapi_table *disp) {
   return (_glptr_RasterPos3fv) (GET_by_offset(disp, _gloffset_RasterPos3fv));
}

static inline void SET_RasterPos3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_RasterPos3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3i)(GLint, GLint, GLint);
#define CALL_RasterPos3i(disp, parameters) \
    (* GET_RasterPos3i(disp)) parameters
static inline _glptr_RasterPos3i GET_RasterPos3i(struct _glapi_table *disp) {
   return (_glptr_RasterPos3i) (GET_by_offset(disp, _gloffset_RasterPos3i));
}

static inline void SET_RasterPos3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_RasterPos3i, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3iv)(const GLint *);
#define CALL_RasterPos3iv(disp, parameters) \
    (* GET_RasterPos3iv(disp)) parameters
static inline _glptr_RasterPos3iv GET_RasterPos3iv(struct _glapi_table *disp) {
   return (_glptr_RasterPos3iv) (GET_by_offset(disp, _gloffset_RasterPos3iv));
}

static inline void SET_RasterPos3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_RasterPos3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3s)(GLshort, GLshort, GLshort);
#define CALL_RasterPos3s(disp, parameters) \
    (* GET_RasterPos3s(disp)) parameters
static inline _glptr_RasterPos3s GET_RasterPos3s(struct _glapi_table *disp) {
   return (_glptr_RasterPos3s) (GET_by_offset(disp, _gloffset_RasterPos3s));
}

static inline void SET_RasterPos3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_RasterPos3s, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos3sv)(const GLshort *);
#define CALL_RasterPos3sv(disp, parameters) \
    (* GET_RasterPos3sv(disp)) parameters
static inline _glptr_RasterPos3sv GET_RasterPos3sv(struct _glapi_table *disp) {
   return (_glptr_RasterPos3sv) (GET_by_offset(disp, _gloffset_RasterPos3sv));
}

static inline void SET_RasterPos3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_RasterPos3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_RasterPos4d(disp, parameters) \
    (* GET_RasterPos4d(disp)) parameters
static inline _glptr_RasterPos4d GET_RasterPos4d(struct _glapi_table *disp) {
   return (_glptr_RasterPos4d) (GET_by_offset(disp, _gloffset_RasterPos4d));
}

static inline void SET_RasterPos4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_RasterPos4d, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4dv)(const GLdouble *);
#define CALL_RasterPos4dv(disp, parameters) \
    (* GET_RasterPos4dv(disp)) parameters
static inline _glptr_RasterPos4dv GET_RasterPos4dv(struct _glapi_table *disp) {
   return (_glptr_RasterPos4dv) (GET_by_offset(disp, _gloffset_RasterPos4dv));
}

static inline void SET_RasterPos4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_RasterPos4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_RasterPos4f(disp, parameters) \
    (* GET_RasterPos4f(disp)) parameters
static inline _glptr_RasterPos4f GET_RasterPos4f(struct _glapi_table *disp) {
   return (_glptr_RasterPos4f) (GET_by_offset(disp, _gloffset_RasterPos4f));
}

static inline void SET_RasterPos4f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_RasterPos4f, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4fv)(const GLfloat *);
#define CALL_RasterPos4fv(disp, parameters) \
    (* GET_RasterPos4fv(disp)) parameters
static inline _glptr_RasterPos4fv GET_RasterPos4fv(struct _glapi_table *disp) {
   return (_glptr_RasterPos4fv) (GET_by_offset(disp, _gloffset_RasterPos4fv));
}

static inline void SET_RasterPos4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_RasterPos4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4i)(GLint, GLint, GLint, GLint);
#define CALL_RasterPos4i(disp, parameters) \
    (* GET_RasterPos4i(disp)) parameters
static inline _glptr_RasterPos4i GET_RasterPos4i(struct _glapi_table *disp) {
   return (_glptr_RasterPos4i) (GET_by_offset(disp, _gloffset_RasterPos4i));
}

static inline void SET_RasterPos4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_RasterPos4i, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4iv)(const GLint *);
#define CALL_RasterPos4iv(disp, parameters) \
    (* GET_RasterPos4iv(disp)) parameters
static inline _glptr_RasterPos4iv GET_RasterPos4iv(struct _glapi_table *disp) {
   return (_glptr_RasterPos4iv) (GET_by_offset(disp, _gloffset_RasterPos4iv));
}

static inline void SET_RasterPos4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_RasterPos4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4s)(GLshort, GLshort, GLshort, GLshort);
#define CALL_RasterPos4s(disp, parameters) \
    (* GET_RasterPos4s(disp)) parameters
static inline _glptr_RasterPos4s GET_RasterPos4s(struct _glapi_table *disp) {
   return (_glptr_RasterPos4s) (GET_by_offset(disp, _gloffset_RasterPos4s));
}

static inline void SET_RasterPos4s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_RasterPos4s, fn);
}

typedef void (GLAPIENTRYP _glptr_RasterPos4sv)(const GLshort *);
#define CALL_RasterPos4sv(disp, parameters) \
    (* GET_RasterPos4sv(disp)) parameters
static inline _glptr_RasterPos4sv GET_RasterPos4sv(struct _glapi_table *disp) {
   return (_glptr_RasterPos4sv) (GET_by_offset(disp, _gloffset_RasterPos4sv));
}

static inline void SET_RasterPos4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_RasterPos4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_Rectd)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Rectd(disp, parameters) \
    (* GET_Rectd(disp)) parameters
static inline _glptr_Rectd GET_Rectd(struct _glapi_table *disp) {
   return (_glptr_Rectd) (GET_by_offset(disp, _gloffset_Rectd));
}

static inline void SET_Rectd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Rectd, fn);
}

typedef void (GLAPIENTRYP _glptr_Rectdv)(const GLdouble *, const GLdouble *);
#define CALL_Rectdv(disp, parameters) \
    (* GET_Rectdv(disp)) parameters
static inline _glptr_Rectdv GET_Rectdv(struct _glapi_table *disp) {
   return (_glptr_Rectdv) (GET_by_offset(disp, _gloffset_Rectdv));
}

static inline void SET_Rectdv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Rectdv, fn);
}

typedef void (GLAPIENTRYP _glptr_Rectf)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Rectf(disp, parameters) \
    (* GET_Rectf(disp)) parameters
static inline _glptr_Rectf GET_Rectf(struct _glapi_table *disp) {
   return (_glptr_Rectf) (GET_by_offset(disp, _gloffset_Rectf));
}

static inline void SET_Rectf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Rectf, fn);
}

typedef void (GLAPIENTRYP _glptr_Rectfv)(const GLfloat *, const GLfloat *);
#define CALL_Rectfv(disp, parameters) \
    (* GET_Rectfv(disp)) parameters
static inline _glptr_Rectfv GET_Rectfv(struct _glapi_table *disp) {
   return (_glptr_Rectfv) (GET_by_offset(disp, _gloffset_Rectfv));
}

static inline void SET_Rectfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Rectfv, fn);
}

typedef void (GLAPIENTRYP _glptr_Recti)(GLint, GLint, GLint, GLint);
#define CALL_Recti(disp, parameters) \
    (* GET_Recti(disp)) parameters
static inline _glptr_Recti GET_Recti(struct _glapi_table *disp) {
   return (_glptr_Recti) (GET_by_offset(disp, _gloffset_Recti));
}

static inline void SET_Recti(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Recti, fn);
}

typedef void (GLAPIENTRYP _glptr_Rectiv)(const GLint *, const GLint *);
#define CALL_Rectiv(disp, parameters) \
    (* GET_Rectiv(disp)) parameters
static inline _glptr_Rectiv GET_Rectiv(struct _glapi_table *disp) {
   return (_glptr_Rectiv) (GET_by_offset(disp, _gloffset_Rectiv));
}

static inline void SET_Rectiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *, const GLint *)) {
   SET_by_offset(disp, _gloffset_Rectiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Rects)(GLshort, GLshort, GLshort, GLshort);
#define CALL_Rects(disp, parameters) \
    (* GET_Rects(disp)) parameters
static inline _glptr_Rects GET_Rects(struct _glapi_table *disp) {
   return (_glptr_Rects) (GET_by_offset(disp, _gloffset_Rects));
}

static inline void SET_Rects(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Rects, fn);
}

typedef void (GLAPIENTRYP _glptr_Rectsv)(const GLshort *, const GLshort *);
#define CALL_Rectsv(disp, parameters) \
    (* GET_Rectsv(disp)) parameters
static inline _glptr_Rectsv GET_Rectsv(struct _glapi_table *disp) {
   return (_glptr_Rectsv) (GET_by_offset(disp, _gloffset_Rectsv));
}

static inline void SET_Rectsv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *, const GLshort *)) {
   SET_by_offset(disp, _gloffset_Rectsv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1d)(GLdouble);
#define CALL_TexCoord1d(disp, parameters) \
    (* GET_TexCoord1d(disp)) parameters
static inline _glptr_TexCoord1d GET_TexCoord1d(struct _glapi_table *disp) {
   return (_glptr_TexCoord1d) (GET_by_offset(disp, _gloffset_TexCoord1d));
}

static inline void SET_TexCoord1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble)) {
   SET_by_offset(disp, _gloffset_TexCoord1d, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1dv)(const GLdouble *);
#define CALL_TexCoord1dv(disp, parameters) \
    (* GET_TexCoord1dv(disp)) parameters
static inline _glptr_TexCoord1dv GET_TexCoord1dv(struct _glapi_table *disp) {
   return (_glptr_TexCoord1dv) (GET_by_offset(disp, _gloffset_TexCoord1dv));
}

static inline void SET_TexCoord1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_TexCoord1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1f)(GLfloat);
#define CALL_TexCoord1f(disp, parameters) \
    (* GET_TexCoord1f(disp)) parameters
static inline _glptr_TexCoord1f GET_TexCoord1f(struct _glapi_table *disp) {
   return (_glptr_TexCoord1f) (GET_by_offset(disp, _gloffset_TexCoord1f));
}

static inline void SET_TexCoord1f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_TexCoord1f, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1fv)(const GLfloat *);
#define CALL_TexCoord1fv(disp, parameters) \
    (* GET_TexCoord1fv(disp)) parameters
static inline _glptr_TexCoord1fv GET_TexCoord1fv(struct _glapi_table *disp) {
   return (_glptr_TexCoord1fv) (GET_by_offset(disp, _gloffset_TexCoord1fv));
}

static inline void SET_TexCoord1fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexCoord1fv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1i)(GLint);
#define CALL_TexCoord1i(disp, parameters) \
    (* GET_TexCoord1i(disp)) parameters
static inline _glptr_TexCoord1i GET_TexCoord1i(struct _glapi_table *disp) {
   return (_glptr_TexCoord1i) (GET_by_offset(disp, _gloffset_TexCoord1i));
}

static inline void SET_TexCoord1i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint)) {
   SET_by_offset(disp, _gloffset_TexCoord1i, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1iv)(const GLint *);
#define CALL_TexCoord1iv(disp, parameters) \
    (* GET_TexCoord1iv(disp)) parameters
static inline _glptr_TexCoord1iv GET_TexCoord1iv(struct _glapi_table *disp) {
   return (_glptr_TexCoord1iv) (GET_by_offset(disp, _gloffset_TexCoord1iv));
}

static inline void SET_TexCoord1iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_TexCoord1iv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1s)(GLshort);
#define CALL_TexCoord1s(disp, parameters) \
    (* GET_TexCoord1s(disp)) parameters
static inline _glptr_TexCoord1s GET_TexCoord1s(struct _glapi_table *disp) {
   return (_glptr_TexCoord1s) (GET_by_offset(disp, _gloffset_TexCoord1s));
}

static inline void SET_TexCoord1s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort)) {
   SET_by_offset(disp, _gloffset_TexCoord1s, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord1sv)(const GLshort *);
#define CALL_TexCoord1sv(disp, parameters) \
    (* GET_TexCoord1sv(disp)) parameters
static inline _glptr_TexCoord1sv GET_TexCoord1sv(struct _glapi_table *disp) {
   return (_glptr_TexCoord1sv) (GET_by_offset(disp, _gloffset_TexCoord1sv));
}

static inline void SET_TexCoord1sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_TexCoord1sv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2d)(GLdouble, GLdouble);
#define CALL_TexCoord2d(disp, parameters) \
    (* GET_TexCoord2d(disp)) parameters
static inline _glptr_TexCoord2d GET_TexCoord2d(struct _glapi_table *disp) {
   return (_glptr_TexCoord2d) (GET_by_offset(disp, _gloffset_TexCoord2d));
}

static inline void SET_TexCoord2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_TexCoord2d, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2dv)(const GLdouble *);
#define CALL_TexCoord2dv(disp, parameters) \
    (* GET_TexCoord2dv(disp)) parameters
static inline _glptr_TexCoord2dv GET_TexCoord2dv(struct _glapi_table *disp) {
   return (_glptr_TexCoord2dv) (GET_by_offset(disp, _gloffset_TexCoord2dv));
}

static inline void SET_TexCoord2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_TexCoord2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2f)(GLfloat, GLfloat);
#define CALL_TexCoord2f(disp, parameters) \
    (* GET_TexCoord2f(disp)) parameters
static inline _glptr_TexCoord2f GET_TexCoord2f(struct _glapi_table *disp) {
   return (_glptr_TexCoord2f) (GET_by_offset(disp, _gloffset_TexCoord2f));
}

static inline void SET_TexCoord2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_TexCoord2f, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2fv)(const GLfloat *);
#define CALL_TexCoord2fv(disp, parameters) \
    (* GET_TexCoord2fv(disp)) parameters
static inline _glptr_TexCoord2fv GET_TexCoord2fv(struct _glapi_table *disp) {
   return (_glptr_TexCoord2fv) (GET_by_offset(disp, _gloffset_TexCoord2fv));
}

static inline void SET_TexCoord2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexCoord2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2i)(GLint, GLint);
#define CALL_TexCoord2i(disp, parameters) \
    (* GET_TexCoord2i(disp)) parameters
static inline _glptr_TexCoord2i GET_TexCoord2i(struct _glapi_table *disp) {
   return (_glptr_TexCoord2i) (GET_by_offset(disp, _gloffset_TexCoord2i));
}

static inline void SET_TexCoord2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint)) {
   SET_by_offset(disp, _gloffset_TexCoord2i, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2iv)(const GLint *);
#define CALL_TexCoord2iv(disp, parameters) \
    (* GET_TexCoord2iv(disp)) parameters
static inline _glptr_TexCoord2iv GET_TexCoord2iv(struct _glapi_table *disp) {
   return (_glptr_TexCoord2iv) (GET_by_offset(disp, _gloffset_TexCoord2iv));
}

static inline void SET_TexCoord2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_TexCoord2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2s)(GLshort, GLshort);
#define CALL_TexCoord2s(disp, parameters) \
    (* GET_TexCoord2s(disp)) parameters
static inline _glptr_TexCoord2s GET_TexCoord2s(struct _glapi_table *disp) {
   return (_glptr_TexCoord2s) (GET_by_offset(disp, _gloffset_TexCoord2s));
}

static inline void SET_TexCoord2s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_TexCoord2s, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord2sv)(const GLshort *);
#define CALL_TexCoord2sv(disp, parameters) \
    (* GET_TexCoord2sv(disp)) parameters
static inline _glptr_TexCoord2sv GET_TexCoord2sv(struct _glapi_table *disp) {
   return (_glptr_TexCoord2sv) (GET_by_offset(disp, _gloffset_TexCoord2sv));
}

static inline void SET_TexCoord2sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_TexCoord2sv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3d)(GLdouble, GLdouble, GLdouble);
#define CALL_TexCoord3d(disp, parameters) \
    (* GET_TexCoord3d(disp)) parameters
static inline _glptr_TexCoord3d GET_TexCoord3d(struct _glapi_table *disp) {
   return (_glptr_TexCoord3d) (GET_by_offset(disp, _gloffset_TexCoord3d));
}

static inline void SET_TexCoord3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_TexCoord3d, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3dv)(const GLdouble *);
#define CALL_TexCoord3dv(disp, parameters) \
    (* GET_TexCoord3dv(disp)) parameters
static inline _glptr_TexCoord3dv GET_TexCoord3dv(struct _glapi_table *disp) {
   return (_glptr_TexCoord3dv) (GET_by_offset(disp, _gloffset_TexCoord3dv));
}

static inline void SET_TexCoord3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_TexCoord3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3f)(GLfloat, GLfloat, GLfloat);
#define CALL_TexCoord3f(disp, parameters) \
    (* GET_TexCoord3f(disp)) parameters
static inline _glptr_TexCoord3f GET_TexCoord3f(struct _glapi_table *disp) {
   return (_glptr_TexCoord3f) (GET_by_offset(disp, _gloffset_TexCoord3f));
}

static inline void SET_TexCoord3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_TexCoord3f, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3fv)(const GLfloat *);
#define CALL_TexCoord3fv(disp, parameters) \
    (* GET_TexCoord3fv(disp)) parameters
static inline _glptr_TexCoord3fv GET_TexCoord3fv(struct _glapi_table *disp) {
   return (_glptr_TexCoord3fv) (GET_by_offset(disp, _gloffset_TexCoord3fv));
}

static inline void SET_TexCoord3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexCoord3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3i)(GLint, GLint, GLint);
#define CALL_TexCoord3i(disp, parameters) \
    (* GET_TexCoord3i(disp)) parameters
static inline _glptr_TexCoord3i GET_TexCoord3i(struct _glapi_table *disp) {
   return (_glptr_TexCoord3i) (GET_by_offset(disp, _gloffset_TexCoord3i));
}

static inline void SET_TexCoord3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_TexCoord3i, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3iv)(const GLint *);
#define CALL_TexCoord3iv(disp, parameters) \
    (* GET_TexCoord3iv(disp)) parameters
static inline _glptr_TexCoord3iv GET_TexCoord3iv(struct _glapi_table *disp) {
   return (_glptr_TexCoord3iv) (GET_by_offset(disp, _gloffset_TexCoord3iv));
}

static inline void SET_TexCoord3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_TexCoord3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3s)(GLshort, GLshort, GLshort);
#define CALL_TexCoord3s(disp, parameters) \
    (* GET_TexCoord3s(disp)) parameters
static inline _glptr_TexCoord3s GET_TexCoord3s(struct _glapi_table *disp) {
   return (_glptr_TexCoord3s) (GET_by_offset(disp, _gloffset_TexCoord3s));
}

static inline void SET_TexCoord3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_TexCoord3s, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord3sv)(const GLshort *);
#define CALL_TexCoord3sv(disp, parameters) \
    (* GET_TexCoord3sv(disp)) parameters
static inline _glptr_TexCoord3sv GET_TexCoord3sv(struct _glapi_table *disp) {
   return (_glptr_TexCoord3sv) (GET_by_offset(disp, _gloffset_TexCoord3sv));
}

static inline void SET_TexCoord3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_TexCoord3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_TexCoord4d(disp, parameters) \
    (* GET_TexCoord4d(disp)) parameters
static inline _glptr_TexCoord4d GET_TexCoord4d(struct _glapi_table *disp) {
   return (_glptr_TexCoord4d) (GET_by_offset(disp, _gloffset_TexCoord4d));
}

static inline void SET_TexCoord4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_TexCoord4d, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4dv)(const GLdouble *);
#define CALL_TexCoord4dv(disp, parameters) \
    (* GET_TexCoord4dv(disp)) parameters
static inline _glptr_TexCoord4dv GET_TexCoord4dv(struct _glapi_table *disp) {
   return (_glptr_TexCoord4dv) (GET_by_offset(disp, _gloffset_TexCoord4dv));
}

static inline void SET_TexCoord4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_TexCoord4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_TexCoord4f(disp, parameters) \
    (* GET_TexCoord4f(disp)) parameters
static inline _glptr_TexCoord4f GET_TexCoord4f(struct _glapi_table *disp) {
   return (_glptr_TexCoord4f) (GET_by_offset(disp, _gloffset_TexCoord4f));
}

static inline void SET_TexCoord4f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_TexCoord4f, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4fv)(const GLfloat *);
#define CALL_TexCoord4fv(disp, parameters) \
    (* GET_TexCoord4fv(disp)) parameters
static inline _glptr_TexCoord4fv GET_TexCoord4fv(struct _glapi_table *disp) {
   return (_glptr_TexCoord4fv) (GET_by_offset(disp, _gloffset_TexCoord4fv));
}

static inline void SET_TexCoord4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexCoord4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4i)(GLint, GLint, GLint, GLint);
#define CALL_TexCoord4i(disp, parameters) \
    (* GET_TexCoord4i(disp)) parameters
static inline _glptr_TexCoord4i GET_TexCoord4i(struct _glapi_table *disp) {
   return (_glptr_TexCoord4i) (GET_by_offset(disp, _gloffset_TexCoord4i));
}

static inline void SET_TexCoord4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_TexCoord4i, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4iv)(const GLint *);
#define CALL_TexCoord4iv(disp, parameters) \
    (* GET_TexCoord4iv(disp)) parameters
static inline _glptr_TexCoord4iv GET_TexCoord4iv(struct _glapi_table *disp) {
   return (_glptr_TexCoord4iv) (GET_by_offset(disp, _gloffset_TexCoord4iv));
}

static inline void SET_TexCoord4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_TexCoord4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4s)(GLshort, GLshort, GLshort, GLshort);
#define CALL_TexCoord4s(disp, parameters) \
    (* GET_TexCoord4s(disp)) parameters
static inline _glptr_TexCoord4s GET_TexCoord4s(struct _glapi_table *disp) {
   return (_glptr_TexCoord4s) (GET_by_offset(disp, _gloffset_TexCoord4s));
}

static inline void SET_TexCoord4s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_TexCoord4s, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoord4sv)(const GLshort *);
#define CALL_TexCoord4sv(disp, parameters) \
    (* GET_TexCoord4sv(disp)) parameters
static inline _glptr_TexCoord4sv GET_TexCoord4sv(struct _glapi_table *disp) {
   return (_glptr_TexCoord4sv) (GET_by_offset(disp, _gloffset_TexCoord4sv));
}

static inline void SET_TexCoord4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_TexCoord4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2d)(GLdouble, GLdouble);
#define CALL_Vertex2d(disp, parameters) \
    (* GET_Vertex2d(disp)) parameters
static inline _glptr_Vertex2d GET_Vertex2d(struct _glapi_table *disp) {
   return (_glptr_Vertex2d) (GET_by_offset(disp, _gloffset_Vertex2d));
}

static inline void SET_Vertex2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Vertex2d, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2dv)(const GLdouble *);
#define CALL_Vertex2dv(disp, parameters) \
    (* GET_Vertex2dv(disp)) parameters
static inline _glptr_Vertex2dv GET_Vertex2dv(struct _glapi_table *disp) {
   return (_glptr_Vertex2dv) (GET_by_offset(disp, _gloffset_Vertex2dv));
}

static inline void SET_Vertex2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Vertex2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2f)(GLfloat, GLfloat);
#define CALL_Vertex2f(disp, parameters) \
    (* GET_Vertex2f(disp)) parameters
static inline _glptr_Vertex2f GET_Vertex2f(struct _glapi_table *disp) {
   return (_glptr_Vertex2f) (GET_by_offset(disp, _gloffset_Vertex2f));
}

static inline void SET_Vertex2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Vertex2f, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2fv)(const GLfloat *);
#define CALL_Vertex2fv(disp, parameters) \
    (* GET_Vertex2fv(disp)) parameters
static inline _glptr_Vertex2fv GET_Vertex2fv(struct _glapi_table *disp) {
   return (_glptr_Vertex2fv) (GET_by_offset(disp, _gloffset_Vertex2fv));
}

static inline void SET_Vertex2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Vertex2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2i)(GLint, GLint);
#define CALL_Vertex2i(disp, parameters) \
    (* GET_Vertex2i(disp)) parameters
static inline _glptr_Vertex2i GET_Vertex2i(struct _glapi_table *disp) {
   return (_glptr_Vertex2i) (GET_by_offset(disp, _gloffset_Vertex2i));
}

static inline void SET_Vertex2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Vertex2i, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2iv)(const GLint *);
#define CALL_Vertex2iv(disp, parameters) \
    (* GET_Vertex2iv(disp)) parameters
static inline _glptr_Vertex2iv GET_Vertex2iv(struct _glapi_table *disp) {
   return (_glptr_Vertex2iv) (GET_by_offset(disp, _gloffset_Vertex2iv));
}

static inline void SET_Vertex2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Vertex2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2s)(GLshort, GLshort);
#define CALL_Vertex2s(disp, parameters) \
    (* GET_Vertex2s(disp)) parameters
static inline _glptr_Vertex2s GET_Vertex2s(struct _glapi_table *disp) {
   return (_glptr_Vertex2s) (GET_by_offset(disp, _gloffset_Vertex2s));
}

static inline void SET_Vertex2s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Vertex2s, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex2sv)(const GLshort *);
#define CALL_Vertex2sv(disp, parameters) \
    (* GET_Vertex2sv(disp)) parameters
static inline _glptr_Vertex2sv GET_Vertex2sv(struct _glapi_table *disp) {
   return (_glptr_Vertex2sv) (GET_by_offset(disp, _gloffset_Vertex2sv));
}

static inline void SET_Vertex2sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Vertex2sv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3d)(GLdouble, GLdouble, GLdouble);
#define CALL_Vertex3d(disp, parameters) \
    (* GET_Vertex3d(disp)) parameters
static inline _glptr_Vertex3d GET_Vertex3d(struct _glapi_table *disp) {
   return (_glptr_Vertex3d) (GET_by_offset(disp, _gloffset_Vertex3d));
}

static inline void SET_Vertex3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Vertex3d, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3dv)(const GLdouble *);
#define CALL_Vertex3dv(disp, parameters) \
    (* GET_Vertex3dv(disp)) parameters
static inline _glptr_Vertex3dv GET_Vertex3dv(struct _glapi_table *disp) {
   return (_glptr_Vertex3dv) (GET_by_offset(disp, _gloffset_Vertex3dv));
}

static inline void SET_Vertex3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Vertex3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3f)(GLfloat, GLfloat, GLfloat);
#define CALL_Vertex3f(disp, parameters) \
    (* GET_Vertex3f(disp)) parameters
static inline _glptr_Vertex3f GET_Vertex3f(struct _glapi_table *disp) {
   return (_glptr_Vertex3f) (GET_by_offset(disp, _gloffset_Vertex3f));
}

static inline void SET_Vertex3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Vertex3f, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3fv)(const GLfloat *);
#define CALL_Vertex3fv(disp, parameters) \
    (* GET_Vertex3fv(disp)) parameters
static inline _glptr_Vertex3fv GET_Vertex3fv(struct _glapi_table *disp) {
   return (_glptr_Vertex3fv) (GET_by_offset(disp, _gloffset_Vertex3fv));
}

static inline void SET_Vertex3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Vertex3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3i)(GLint, GLint, GLint);
#define CALL_Vertex3i(disp, parameters) \
    (* GET_Vertex3i(disp)) parameters
static inline _glptr_Vertex3i GET_Vertex3i(struct _glapi_table *disp) {
   return (_glptr_Vertex3i) (GET_by_offset(disp, _gloffset_Vertex3i));
}

static inline void SET_Vertex3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Vertex3i, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3iv)(const GLint *);
#define CALL_Vertex3iv(disp, parameters) \
    (* GET_Vertex3iv(disp)) parameters
static inline _glptr_Vertex3iv GET_Vertex3iv(struct _glapi_table *disp) {
   return (_glptr_Vertex3iv) (GET_by_offset(disp, _gloffset_Vertex3iv));
}

static inline void SET_Vertex3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Vertex3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3s)(GLshort, GLshort, GLshort);
#define CALL_Vertex3s(disp, parameters) \
    (* GET_Vertex3s(disp)) parameters
static inline _glptr_Vertex3s GET_Vertex3s(struct _glapi_table *disp) {
   return (_glptr_Vertex3s) (GET_by_offset(disp, _gloffset_Vertex3s));
}

static inline void SET_Vertex3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Vertex3s, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex3sv)(const GLshort *);
#define CALL_Vertex3sv(disp, parameters) \
    (* GET_Vertex3sv(disp)) parameters
static inline _glptr_Vertex3sv GET_Vertex3sv(struct _glapi_table *disp) {
   return (_glptr_Vertex3sv) (GET_by_offset(disp, _gloffset_Vertex3sv));
}

static inline void SET_Vertex3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Vertex3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Vertex4d(disp, parameters) \
    (* GET_Vertex4d(disp)) parameters
static inline _glptr_Vertex4d GET_Vertex4d(struct _glapi_table *disp) {
   return (_glptr_Vertex4d) (GET_by_offset(disp, _gloffset_Vertex4d));
}

static inline void SET_Vertex4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Vertex4d, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4dv)(const GLdouble *);
#define CALL_Vertex4dv(disp, parameters) \
    (* GET_Vertex4dv(disp)) parameters
static inline _glptr_Vertex4dv GET_Vertex4dv(struct _glapi_table *disp) {
   return (_glptr_Vertex4dv) (GET_by_offset(disp, _gloffset_Vertex4dv));
}

static inline void SET_Vertex4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Vertex4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Vertex4f(disp, parameters) \
    (* GET_Vertex4f(disp)) parameters
static inline _glptr_Vertex4f GET_Vertex4f(struct _glapi_table *disp) {
   return (_glptr_Vertex4f) (GET_by_offset(disp, _gloffset_Vertex4f));
}

static inline void SET_Vertex4f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Vertex4f, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4fv)(const GLfloat *);
#define CALL_Vertex4fv(disp, parameters) \
    (* GET_Vertex4fv(disp)) parameters
static inline _glptr_Vertex4fv GET_Vertex4fv(struct _glapi_table *disp) {
   return (_glptr_Vertex4fv) (GET_by_offset(disp, _gloffset_Vertex4fv));
}

static inline void SET_Vertex4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Vertex4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4i)(GLint, GLint, GLint, GLint);
#define CALL_Vertex4i(disp, parameters) \
    (* GET_Vertex4i(disp)) parameters
static inline _glptr_Vertex4i GET_Vertex4i(struct _glapi_table *disp) {
   return (_glptr_Vertex4i) (GET_by_offset(disp, _gloffset_Vertex4i));
}

static inline void SET_Vertex4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Vertex4i, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4iv)(const GLint *);
#define CALL_Vertex4iv(disp, parameters) \
    (* GET_Vertex4iv(disp)) parameters
static inline _glptr_Vertex4iv GET_Vertex4iv(struct _glapi_table *disp) {
   return (_glptr_Vertex4iv) (GET_by_offset(disp, _gloffset_Vertex4iv));
}

static inline void SET_Vertex4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_Vertex4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4s)(GLshort, GLshort, GLshort, GLshort);
#define CALL_Vertex4s(disp, parameters) \
    (* GET_Vertex4s(disp)) parameters
static inline _glptr_Vertex4s GET_Vertex4s(struct _glapi_table *disp) {
   return (_glptr_Vertex4s) (GET_by_offset(disp, _gloffset_Vertex4s));
}

static inline void SET_Vertex4s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_Vertex4s, fn);
}

typedef void (GLAPIENTRYP _glptr_Vertex4sv)(const GLshort *);
#define CALL_Vertex4sv(disp, parameters) \
    (* GET_Vertex4sv(disp)) parameters
static inline _glptr_Vertex4sv GET_Vertex4sv(struct _glapi_table *disp) {
   return (_glptr_Vertex4sv) (GET_by_offset(disp, _gloffset_Vertex4sv));
}

static inline void SET_Vertex4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_Vertex4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_ClipPlane)(GLenum, const GLdouble *);
#define CALL_ClipPlane(disp, parameters) \
    (* GET_ClipPlane(disp)) parameters
static inline _glptr_ClipPlane GET_ClipPlane(struct _glapi_table *disp) {
   return (_glptr_ClipPlane) (GET_by_offset(disp, _gloffset_ClipPlane));
}

static inline void SET_ClipPlane(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ClipPlane, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorMaterial)(GLenum, GLenum);
#define CALL_ColorMaterial(disp, parameters) \
    (* GET_ColorMaterial(disp)) parameters
static inline _glptr_ColorMaterial GET_ColorMaterial(struct _glapi_table *disp) {
   return (_glptr_ColorMaterial) (GET_by_offset(disp, _gloffset_ColorMaterial));
}

static inline void SET_ColorMaterial(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_ColorMaterial, fn);
}

typedef void (GLAPIENTRYP _glptr_CullFace)(GLenum);
#define CALL_CullFace(disp, parameters) \
    (* GET_CullFace(disp)) parameters
static inline _glptr_CullFace GET_CullFace(struct _glapi_table *disp) {
   return (_glptr_CullFace) (GET_by_offset(disp, _gloffset_CullFace));
}

static inline void SET_CullFace(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_CullFace, fn);
}

typedef void (GLAPIENTRYP _glptr_Fogf)(GLenum, GLfloat);
#define CALL_Fogf(disp, parameters) \
    (* GET_Fogf(disp)) parameters
static inline _glptr_Fogf GET_Fogf(struct _glapi_table *disp) {
   return (_glptr_Fogf) (GET_by_offset(disp, _gloffset_Fogf));
}

static inline void SET_Fogf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_Fogf, fn);
}

typedef void (GLAPIENTRYP _glptr_Fogfv)(GLenum, const GLfloat *);
#define CALL_Fogfv(disp, parameters) \
    (* GET_Fogfv(disp)) parameters
static inline _glptr_Fogfv GET_Fogfv(struct _glapi_table *disp) {
   return (_glptr_Fogfv) (GET_by_offset(disp, _gloffset_Fogfv));
}

static inline void SET_Fogfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Fogfv, fn);
}

typedef void (GLAPIENTRYP _glptr_Fogi)(GLenum, GLint);
#define CALL_Fogi(disp, parameters) \
    (* GET_Fogi(disp)) parameters
static inline _glptr_Fogi GET_Fogi(struct _glapi_table *disp) {
   return (_glptr_Fogi) (GET_by_offset(disp, _gloffset_Fogi));
}

static inline void SET_Fogi(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_Fogi, fn);
}

typedef void (GLAPIENTRYP _glptr_Fogiv)(GLenum, const GLint *);
#define CALL_Fogiv(disp, parameters) \
    (* GET_Fogiv(disp)) parameters
static inline _glptr_Fogiv GET_Fogiv(struct _glapi_table *disp) {
   return (_glptr_Fogiv) (GET_by_offset(disp, _gloffset_Fogiv));
}

static inline void SET_Fogiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_Fogiv, fn);
}

typedef void (GLAPIENTRYP _glptr_FrontFace)(GLenum);
#define CALL_FrontFace(disp, parameters) \
    (* GET_FrontFace(disp)) parameters
static inline _glptr_FrontFace GET_FrontFace(struct _glapi_table *disp) {
   return (_glptr_FrontFace) (GET_by_offset(disp, _gloffset_FrontFace));
}

static inline void SET_FrontFace(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_FrontFace, fn);
}

typedef void (GLAPIENTRYP _glptr_Hint)(GLenum, GLenum);
#define CALL_Hint(disp, parameters) \
    (* GET_Hint(disp)) parameters
static inline _glptr_Hint GET_Hint(struct _glapi_table *disp) {
   return (_glptr_Hint) (GET_by_offset(disp, _gloffset_Hint));
}

static inline void SET_Hint(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_Hint, fn);
}

typedef void (GLAPIENTRYP _glptr_Lightf)(GLenum, GLenum, GLfloat);
#define CALL_Lightf(disp, parameters) \
    (* GET_Lightf(disp)) parameters
static inline _glptr_Lightf GET_Lightf(struct _glapi_table *disp) {
   return (_glptr_Lightf) (GET_by_offset(disp, _gloffset_Lightf));
}

static inline void SET_Lightf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_Lightf, fn);
}

typedef void (GLAPIENTRYP _glptr_Lightfv)(GLenum, GLenum, const GLfloat *);
#define CALL_Lightfv(disp, parameters) \
    (* GET_Lightfv(disp)) parameters
static inline _glptr_Lightfv GET_Lightfv(struct _glapi_table *disp) {
   return (_glptr_Lightfv) (GET_by_offset(disp, _gloffset_Lightfv));
}

static inline void SET_Lightfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Lightfv, fn);
}

typedef void (GLAPIENTRYP _glptr_Lighti)(GLenum, GLenum, GLint);
#define CALL_Lighti(disp, parameters) \
    (* GET_Lighti(disp)) parameters
static inline _glptr_Lighti GET_Lighti(struct _glapi_table *disp) {
   return (_glptr_Lighti) (GET_by_offset(disp, _gloffset_Lighti));
}

static inline void SET_Lighti(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_Lighti, fn);
}

typedef void (GLAPIENTRYP _glptr_Lightiv)(GLenum, GLenum, const GLint *);
#define CALL_Lightiv(disp, parameters) \
    (* GET_Lightiv(disp)) parameters
static inline _glptr_Lightiv GET_Lightiv(struct _glapi_table *disp) {
   return (_glptr_Lightiv) (GET_by_offset(disp, _gloffset_Lightiv));
}

static inline void SET_Lightiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_Lightiv, fn);
}

typedef void (GLAPIENTRYP _glptr_LightModelf)(GLenum, GLfloat);
#define CALL_LightModelf(disp, parameters) \
    (* GET_LightModelf(disp)) parameters
static inline _glptr_LightModelf GET_LightModelf(struct _glapi_table *disp) {
   return (_glptr_LightModelf) (GET_by_offset(disp, _gloffset_LightModelf));
}

static inline void SET_LightModelf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_LightModelf, fn);
}

typedef void (GLAPIENTRYP _glptr_LightModelfv)(GLenum, const GLfloat *);
#define CALL_LightModelfv(disp, parameters) \
    (* GET_LightModelfv(disp)) parameters
static inline _glptr_LightModelfv GET_LightModelfv(struct _glapi_table *disp) {
   return (_glptr_LightModelfv) (GET_by_offset(disp, _gloffset_LightModelfv));
}

static inline void SET_LightModelfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_LightModelfv, fn);
}

typedef void (GLAPIENTRYP _glptr_LightModeli)(GLenum, GLint);
#define CALL_LightModeli(disp, parameters) \
    (* GET_LightModeli(disp)) parameters
static inline _glptr_LightModeli GET_LightModeli(struct _glapi_table *disp) {
   return (_glptr_LightModeli) (GET_by_offset(disp, _gloffset_LightModeli));
}

static inline void SET_LightModeli(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_LightModeli, fn);
}

typedef void (GLAPIENTRYP _glptr_LightModeliv)(GLenum, const GLint *);
#define CALL_LightModeliv(disp, parameters) \
    (* GET_LightModeliv(disp)) parameters
static inline _glptr_LightModeliv GET_LightModeliv(struct _glapi_table *disp) {
   return (_glptr_LightModeliv) (GET_by_offset(disp, _gloffset_LightModeliv));
}

static inline void SET_LightModeliv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_LightModeliv, fn);
}

typedef void (GLAPIENTRYP _glptr_LineStipple)(GLint, GLushort);
#define CALL_LineStipple(disp, parameters) \
    (* GET_LineStipple(disp)) parameters
static inline _glptr_LineStipple GET_LineStipple(struct _glapi_table *disp) {
   return (_glptr_LineStipple) (GET_by_offset(disp, _gloffset_LineStipple));
}

static inline void SET_LineStipple(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLushort)) {
   SET_by_offset(disp, _gloffset_LineStipple, fn);
}

typedef void (GLAPIENTRYP _glptr_LineWidth)(GLfloat);
#define CALL_LineWidth(disp, parameters) \
    (* GET_LineWidth(disp)) parameters
static inline _glptr_LineWidth GET_LineWidth(struct _glapi_table *disp) {
   return (_glptr_LineWidth) (GET_by_offset(disp, _gloffset_LineWidth));
}

static inline void SET_LineWidth(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_LineWidth, fn);
}

typedef void (GLAPIENTRYP _glptr_Materialf)(GLenum, GLenum, GLfloat);
#define CALL_Materialf(disp, parameters) \
    (* GET_Materialf(disp)) parameters
static inline _glptr_Materialf GET_Materialf(struct _glapi_table *disp) {
   return (_glptr_Materialf) (GET_by_offset(disp, _gloffset_Materialf));
}

static inline void SET_Materialf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_Materialf, fn);
}

typedef void (GLAPIENTRYP _glptr_Materialfv)(GLenum, GLenum, const GLfloat *);
#define CALL_Materialfv(disp, parameters) \
    (* GET_Materialfv(disp)) parameters
static inline _glptr_Materialfv GET_Materialfv(struct _glapi_table *disp) {
   return (_glptr_Materialfv) (GET_by_offset(disp, _gloffset_Materialfv));
}

static inline void SET_Materialfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Materialfv, fn);
}

typedef void (GLAPIENTRYP _glptr_Materiali)(GLenum, GLenum, GLint);
#define CALL_Materiali(disp, parameters) \
    (* GET_Materiali(disp)) parameters
static inline _glptr_Materiali GET_Materiali(struct _glapi_table *disp) {
   return (_glptr_Materiali) (GET_by_offset(disp, _gloffset_Materiali));
}

static inline void SET_Materiali(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_Materiali, fn);
}

typedef void (GLAPIENTRYP _glptr_Materialiv)(GLenum, GLenum, const GLint *);
#define CALL_Materialiv(disp, parameters) \
    (* GET_Materialiv(disp)) parameters
static inline _glptr_Materialiv GET_Materialiv(struct _glapi_table *disp) {
   return (_glptr_Materialiv) (GET_by_offset(disp, _gloffset_Materialiv));
}

static inline void SET_Materialiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_Materialiv, fn);
}

typedef void (GLAPIENTRYP _glptr_PointSize)(GLfloat);
#define CALL_PointSize(disp, parameters) \
    (* GET_PointSize(disp)) parameters
static inline _glptr_PointSize GET_PointSize(struct _glapi_table *disp) {
   return (_glptr_PointSize) (GET_by_offset(disp, _gloffset_PointSize));
}

static inline void SET_PointSize(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_PointSize, fn);
}

typedef void (GLAPIENTRYP _glptr_PolygonMode)(GLenum, GLenum);
#define CALL_PolygonMode(disp, parameters) \
    (* GET_PolygonMode(disp)) parameters
static inline _glptr_PolygonMode GET_PolygonMode(struct _glapi_table *disp) {
   return (_glptr_PolygonMode) (GET_by_offset(disp, _gloffset_PolygonMode));
}

static inline void SET_PolygonMode(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_PolygonMode, fn);
}

typedef void (GLAPIENTRYP _glptr_PolygonStipple)(const GLubyte *);
#define CALL_PolygonStipple(disp, parameters) \
    (* GET_PolygonStipple(disp)) parameters
static inline _glptr_PolygonStipple GET_PolygonStipple(struct _glapi_table *disp) {
   return (_glptr_PolygonStipple) (GET_by_offset(disp, _gloffset_PolygonStipple));
}

static inline void SET_PolygonStipple(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLubyte *)) {
   SET_by_offset(disp, _gloffset_PolygonStipple, fn);
}

typedef void (GLAPIENTRYP _glptr_Scissor)(GLint, GLint, GLsizei, GLsizei);
#define CALL_Scissor(disp, parameters) \
    (* GET_Scissor(disp)) parameters
static inline _glptr_Scissor GET_Scissor(struct _glapi_table *disp) {
   return (_glptr_Scissor) (GET_by_offset(disp, _gloffset_Scissor));
}

static inline void SET_Scissor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_Scissor, fn);
}

typedef void (GLAPIENTRYP _glptr_ShadeModel)(GLenum);
#define CALL_ShadeModel(disp, parameters) \
    (* GET_ShadeModel(disp)) parameters
static inline _glptr_ShadeModel GET_ShadeModel(struct _glapi_table *disp) {
   return (_glptr_ShadeModel) (GET_by_offset(disp, _gloffset_ShadeModel));
}

static inline void SET_ShadeModel(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ShadeModel, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameterf)(GLenum, GLenum, GLfloat);
#define CALL_TexParameterf(disp, parameters) \
    (* GET_TexParameterf(disp)) parameters
static inline _glptr_TexParameterf GET_TexParameterf(struct _glapi_table *disp) {
   return (_glptr_TexParameterf) (GET_by_offset(disp, _gloffset_TexParameterf));
}

static inline void SET_TexParameterf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_TexParameterf, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameterfv)(GLenum, GLenum, const GLfloat *);
#define CALL_TexParameterfv(disp, parameters) \
    (* GET_TexParameterfv(disp)) parameters
static inline _glptr_TexParameterfv GET_TexParameterfv(struct _glapi_table *disp) {
   return (_glptr_TexParameterfv) (GET_by_offset(disp, _gloffset_TexParameterfv));
}

static inline void SET_TexParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameteri)(GLenum, GLenum, GLint);
#define CALL_TexParameteri(disp, parameters) \
    (* GET_TexParameteri(disp)) parameters
static inline _glptr_TexParameteri GET_TexParameteri(struct _glapi_table *disp) {
   return (_glptr_TexParameteri) (GET_by_offset(disp, _gloffset_TexParameteri));
}

static inline void SET_TexParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_TexParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameteriv)(GLenum, GLenum, const GLint *);
#define CALL_TexParameteriv(disp, parameters) \
    (* GET_TexParameteriv(disp)) parameters
static inline _glptr_TexParameteriv GET_TexParameteriv(struct _glapi_table *disp) {
   return (_glptr_TexParameteriv) (GET_by_offset(disp, _gloffset_TexParameteriv));
}

static inline void SET_TexParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TexParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexImage1D)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define CALL_TexImage1D(disp, parameters) \
    (* GET_TexImage1D(disp)) parameters
static inline _glptr_TexImage1D GET_TexImage1D(struct _glapi_table *disp) {
   return (_glptr_TexImage1D) (GET_by_offset(disp, _gloffset_TexImage1D));
}

static inline void SET_TexImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_TexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define CALL_TexImage2D(disp, parameters) \
    (* GET_TexImage2D(disp)) parameters
static inline _glptr_TexImage2D GET_TexImage2D(struct _glapi_table *disp) {
   return (_glptr_TexImage2D) (GET_by_offset(disp, _gloffset_TexImage2D));
}

static inline void SET_TexImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_TexEnvf)(GLenum, GLenum, GLfloat);
#define CALL_TexEnvf(disp, parameters) \
    (* GET_TexEnvf(disp)) parameters
static inline _glptr_TexEnvf GET_TexEnvf(struct _glapi_table *disp) {
   return (_glptr_TexEnvf) (GET_by_offset(disp, _gloffset_TexEnvf));
}

static inline void SET_TexEnvf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_TexEnvf, fn);
}

typedef void (GLAPIENTRYP _glptr_TexEnvfv)(GLenum, GLenum, const GLfloat *);
#define CALL_TexEnvfv(disp, parameters) \
    (* GET_TexEnvfv(disp)) parameters
static inline _glptr_TexEnvfv GET_TexEnvfv(struct _glapi_table *disp) {
   return (_glptr_TexEnvfv) (GET_by_offset(disp, _gloffset_TexEnvfv));
}

static inline void SET_TexEnvfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexEnvfv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexEnvi)(GLenum, GLenum, GLint);
#define CALL_TexEnvi(disp, parameters) \
    (* GET_TexEnvi(disp)) parameters
static inline _glptr_TexEnvi GET_TexEnvi(struct _glapi_table *disp) {
   return (_glptr_TexEnvi) (GET_by_offset(disp, _gloffset_TexEnvi));
}

static inline void SET_TexEnvi(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_TexEnvi, fn);
}

typedef void (GLAPIENTRYP _glptr_TexEnviv)(GLenum, GLenum, const GLint *);
#define CALL_TexEnviv(disp, parameters) \
    (* GET_TexEnviv(disp)) parameters
static inline _glptr_TexEnviv GET_TexEnviv(struct _glapi_table *disp) {
   return (_glptr_TexEnviv) (GET_by_offset(disp, _gloffset_TexEnviv));
}

static inline void SET_TexEnviv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TexEnviv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGend)(GLenum, GLenum, GLdouble);
#define CALL_TexGend(disp, parameters) \
    (* GET_TexGend(disp)) parameters
static inline _glptr_TexGend GET_TexGend(struct _glapi_table *disp) {
   return (_glptr_TexGend) (GET_by_offset(disp, _gloffset_TexGend));
}

static inline void SET_TexGend(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLdouble)) {
   SET_by_offset(disp, _gloffset_TexGend, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGendv)(GLenum, GLenum, const GLdouble *);
#define CALL_TexGendv(disp, parameters) \
    (* GET_TexGendv(disp)) parameters
static inline _glptr_TexGendv GET_TexGendv(struct _glapi_table *disp) {
   return (_glptr_TexGendv) (GET_by_offset(disp, _gloffset_TexGendv));
}

static inline void SET_TexGendv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_TexGendv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGenf)(GLenum, GLenum, GLfloat);
#define CALL_TexGenf(disp, parameters) \
    (* GET_TexGenf(disp)) parameters
static inline _glptr_TexGenf GET_TexGenf(struct _glapi_table *disp) {
   return (_glptr_TexGenf) (GET_by_offset(disp, _gloffset_TexGenf));
}

static inline void SET_TexGenf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_TexGenf, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGenfv)(GLenum, GLenum, const GLfloat *);
#define CALL_TexGenfv(disp, parameters) \
    (* GET_TexGenfv(disp)) parameters
static inline _glptr_TexGenfv GET_TexGenfv(struct _glapi_table *disp) {
   return (_glptr_TexGenfv) (GET_by_offset(disp, _gloffset_TexGenfv));
}

static inline void SET_TexGenfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexGenfv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGeni)(GLenum, GLenum, GLint);
#define CALL_TexGeni(disp, parameters) \
    (* GET_TexGeni(disp)) parameters
static inline _glptr_TexGeni GET_TexGeni(struct _glapi_table *disp) {
   return (_glptr_TexGeni) (GET_by_offset(disp, _gloffset_TexGeni));
}

static inline void SET_TexGeni(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_TexGeni, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGeniv)(GLenum, GLenum, const GLint *);
#define CALL_TexGeniv(disp, parameters) \
    (* GET_TexGeniv(disp)) parameters
static inline _glptr_TexGeniv GET_TexGeniv(struct _glapi_table *disp) {
   return (_glptr_TexGeniv) (GET_by_offset(disp, _gloffset_TexGeniv));
}

static inline void SET_TexGeniv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TexGeniv, fn);
}

typedef void (GLAPIENTRYP _glptr_FeedbackBuffer)(GLsizei, GLenum, GLfloat *);
#define CALL_FeedbackBuffer(disp, parameters) \
    (* GET_FeedbackBuffer(disp)) parameters
static inline _glptr_FeedbackBuffer GET_FeedbackBuffer(struct _glapi_table *disp) {
   return (_glptr_FeedbackBuffer) (GET_by_offset(disp, _gloffset_FeedbackBuffer));
}

static inline void SET_FeedbackBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_FeedbackBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_SelectBuffer)(GLsizei, GLuint *);
#define CALL_SelectBuffer(disp, parameters) \
    (* GET_SelectBuffer(disp)) parameters
static inline _glptr_SelectBuffer GET_SelectBuffer(struct _glapi_table *disp) {
   return (_glptr_SelectBuffer) (GET_by_offset(disp, _gloffset_SelectBuffer));
}

static inline void SET_SelectBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_SelectBuffer, fn);
}

typedef GLint (GLAPIENTRYP _glptr_RenderMode)(GLenum);
#define CALL_RenderMode(disp, parameters) \
    (* GET_RenderMode(disp)) parameters
static inline _glptr_RenderMode GET_RenderMode(struct _glapi_table *disp) {
   return (_glptr_RenderMode) (GET_by_offset(disp, _gloffset_RenderMode));
}

static inline void SET_RenderMode(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_RenderMode, fn);
}

typedef void (GLAPIENTRYP _glptr_InitNames)(void);
#define CALL_InitNames(disp, parameters) \
    (* GET_InitNames(disp)) parameters
static inline _glptr_InitNames GET_InitNames(struct _glapi_table *disp) {
   return (_glptr_InitNames) (GET_by_offset(disp, _gloffset_InitNames));
}

static inline void SET_InitNames(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_InitNames, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadName)(GLuint);
#define CALL_LoadName(disp, parameters) \
    (* GET_LoadName(disp)) parameters
static inline _glptr_LoadName GET_LoadName(struct _glapi_table *disp) {
   return (_glptr_LoadName) (GET_by_offset(disp, _gloffset_LoadName));
}

static inline void SET_LoadName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_LoadName, fn);
}

typedef void (GLAPIENTRYP _glptr_PassThrough)(GLfloat);
#define CALL_PassThrough(disp, parameters) \
    (* GET_PassThrough(disp)) parameters
static inline _glptr_PassThrough GET_PassThrough(struct _glapi_table *disp) {
   return (_glptr_PassThrough) (GET_by_offset(disp, _gloffset_PassThrough));
}

static inline void SET_PassThrough(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_PassThrough, fn);
}

typedef void (GLAPIENTRYP _glptr_PopName)(void);
#define CALL_PopName(disp, parameters) \
    (* GET_PopName(disp)) parameters
static inline _glptr_PopName GET_PopName(struct _glapi_table *disp) {
   return (_glptr_PopName) (GET_by_offset(disp, _gloffset_PopName));
}

static inline void SET_PopName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PopName, fn);
}

typedef void (GLAPIENTRYP _glptr_PushName)(GLuint);
#define CALL_PushName(disp, parameters) \
    (* GET_PushName(disp)) parameters
static inline _glptr_PushName GET_PushName(struct _glapi_table *disp) {
   return (_glptr_PushName) (GET_by_offset(disp, _gloffset_PushName));
}

static inline void SET_PushName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_PushName, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawBuffer)(GLenum);
#define CALL_DrawBuffer(disp, parameters) \
    (* GET_DrawBuffer(disp)) parameters
static inline _glptr_DrawBuffer GET_DrawBuffer(struct _glapi_table *disp) {
   return (_glptr_DrawBuffer) (GET_by_offset(disp, _gloffset_DrawBuffer));
}

static inline void SET_DrawBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_DrawBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_Clear)(GLbitfield);
#define CALL_Clear(disp, parameters) \
    (* GET_Clear(disp)) parameters
static inline _glptr_Clear GET_Clear(struct _glapi_table *disp) {
   return (_glptr_Clear) (GET_by_offset(disp, _gloffset_Clear));
}

static inline void SET_Clear(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbitfield)) {
   SET_by_offset(disp, _gloffset_Clear, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearAccum)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_ClearAccum(disp, parameters) \
    (* GET_ClearAccum(disp)) parameters
static inline _glptr_ClearAccum GET_ClearAccum(struct _glapi_table *disp) {
   return (_glptr_ClearAccum) (GET_by_offset(disp, _gloffset_ClearAccum));
}

static inline void SET_ClearAccum(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ClearAccum, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearIndex)(GLfloat);
#define CALL_ClearIndex(disp, parameters) \
    (* GET_ClearIndex(disp)) parameters
static inline _glptr_ClearIndex GET_ClearIndex(struct _glapi_table *disp) {
   return (_glptr_ClearIndex) (GET_by_offset(disp, _gloffset_ClearIndex));
}

static inline void SET_ClearIndex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_ClearIndex, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearColor)(GLclampf, GLclampf, GLclampf, GLclampf);
#define CALL_ClearColor(disp, parameters) \
    (* GET_ClearColor(disp)) parameters
static inline _glptr_ClearColor GET_ClearColor(struct _glapi_table *disp) {
   return (_glptr_ClearColor) (GET_by_offset(disp, _gloffset_ClearColor));
}

static inline void SET_ClearColor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampf, GLclampf, GLclampf, GLclampf)) {
   SET_by_offset(disp, _gloffset_ClearColor, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearStencil)(GLint);
#define CALL_ClearStencil(disp, parameters) \
    (* GET_ClearStencil(disp)) parameters
static inline _glptr_ClearStencil GET_ClearStencil(struct _glapi_table *disp) {
   return (_glptr_ClearStencil) (GET_by_offset(disp, _gloffset_ClearStencil));
}

static inline void SET_ClearStencil(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint)) {
   SET_by_offset(disp, _gloffset_ClearStencil, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearDepth)(GLclampd);
#define CALL_ClearDepth(disp, parameters) \
    (* GET_ClearDepth(disp)) parameters
static inline _glptr_ClearDepth GET_ClearDepth(struct _glapi_table *disp) {
   return (_glptr_ClearDepth) (GET_by_offset(disp, _gloffset_ClearDepth));
}

static inline void SET_ClearDepth(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampd)) {
   SET_by_offset(disp, _gloffset_ClearDepth, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilMask)(GLuint);
#define CALL_StencilMask(disp, parameters) \
    (* GET_StencilMask(disp)) parameters
static inline _glptr_StencilMask GET_StencilMask(struct _glapi_table *disp) {
   return (_glptr_StencilMask) (GET_by_offset(disp, _gloffset_StencilMask));
}

static inline void SET_StencilMask(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_StencilMask, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorMask)(GLboolean, GLboolean, GLboolean, GLboolean);
#define CALL_ColorMask(disp, parameters) \
    (* GET_ColorMask(disp)) parameters
static inline _glptr_ColorMask GET_ColorMask(struct _glapi_table *disp) {
   return (_glptr_ColorMask) (GET_by_offset(disp, _gloffset_ColorMask));
}

static inline void SET_ColorMask(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLboolean, GLboolean, GLboolean, GLboolean)) {
   SET_by_offset(disp, _gloffset_ColorMask, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthMask)(GLboolean);
#define CALL_DepthMask(disp, parameters) \
    (* GET_DepthMask(disp)) parameters
static inline _glptr_DepthMask GET_DepthMask(struct _glapi_table *disp) {
   return (_glptr_DepthMask) (GET_by_offset(disp, _gloffset_DepthMask));
}

static inline void SET_DepthMask(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLboolean)) {
   SET_by_offset(disp, _gloffset_DepthMask, fn);
}

typedef void (GLAPIENTRYP _glptr_IndexMask)(GLuint);
#define CALL_IndexMask(disp, parameters) \
    (* GET_IndexMask(disp)) parameters
static inline _glptr_IndexMask GET_IndexMask(struct _glapi_table *disp) {
   return (_glptr_IndexMask) (GET_by_offset(disp, _gloffset_IndexMask));
}

static inline void SET_IndexMask(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IndexMask, fn);
}

typedef void (GLAPIENTRYP _glptr_Accum)(GLenum, GLfloat);
#define CALL_Accum(disp, parameters) \
    (* GET_Accum(disp)) parameters
static inline _glptr_Accum GET_Accum(struct _glapi_table *disp) {
   return (_glptr_Accum) (GET_by_offset(disp, _gloffset_Accum));
}

static inline void SET_Accum(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_Accum, fn);
}

typedef void (GLAPIENTRYP _glptr_Disable)(GLenum);
#define CALL_Disable(disp, parameters) \
    (* GET_Disable(disp)) parameters
static inline _glptr_Disable GET_Disable(struct _glapi_table *disp) {
   return (_glptr_Disable) (GET_by_offset(disp, _gloffset_Disable));
}

static inline void SET_Disable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_Disable, fn);
}

typedef void (GLAPIENTRYP _glptr_Enable)(GLenum);
#define CALL_Enable(disp, parameters) \
    (* GET_Enable(disp)) parameters
static inline _glptr_Enable GET_Enable(struct _glapi_table *disp) {
   return (_glptr_Enable) (GET_by_offset(disp, _gloffset_Enable));
}

static inline void SET_Enable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_Enable, fn);
}

typedef void (GLAPIENTRYP _glptr_Finish)(void);
#define CALL_Finish(disp, parameters) \
    (* GET_Finish(disp)) parameters
static inline _glptr_Finish GET_Finish(struct _glapi_table *disp) {
   return (_glptr_Finish) (GET_by_offset(disp, _gloffset_Finish));
}

static inline void SET_Finish(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_Finish, fn);
}

typedef void (GLAPIENTRYP _glptr_Flush)(void);
#define CALL_Flush(disp, parameters) \
    (* GET_Flush(disp)) parameters
static inline _glptr_Flush GET_Flush(struct _glapi_table *disp) {
   return (_glptr_Flush) (GET_by_offset(disp, _gloffset_Flush));
}

static inline void SET_Flush(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_Flush, fn);
}

typedef void (GLAPIENTRYP _glptr_PopAttrib)(void);
#define CALL_PopAttrib(disp, parameters) \
    (* GET_PopAttrib(disp)) parameters
static inline _glptr_PopAttrib GET_PopAttrib(struct _glapi_table *disp) {
   return (_glptr_PopAttrib) (GET_by_offset(disp, _gloffset_PopAttrib));
}

static inline void SET_PopAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PopAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_PushAttrib)(GLbitfield);
#define CALL_PushAttrib(disp, parameters) \
    (* GET_PushAttrib(disp)) parameters
static inline _glptr_PushAttrib GET_PushAttrib(struct _glapi_table *disp) {
   return (_glptr_PushAttrib) (GET_by_offset(disp, _gloffset_PushAttrib));
}

static inline void SET_PushAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbitfield)) {
   SET_by_offset(disp, _gloffset_PushAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_Map1d)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define CALL_Map1d(disp, parameters) \
    (* GET_Map1d(disp)) parameters
static inline _glptr_Map1d GET_Map1d(struct _glapi_table *disp) {
   return (_glptr_Map1d) (GET_by_offset(disp, _gloffset_Map1d));
}

static inline void SET_Map1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Map1d, fn);
}

typedef void (GLAPIENTRYP _glptr_Map1f)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define CALL_Map1f(disp, parameters) \
    (* GET_Map1f(disp)) parameters
static inline _glptr_Map1f GET_Map1f(struct _glapi_table *disp) {
   return (_glptr_Map1f) (GET_by_offset(disp, _gloffset_Map1f));
}

static inline void SET_Map1f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Map1f, fn);
}

typedef void (GLAPIENTRYP _glptr_Map2d)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define CALL_Map2d(disp, parameters) \
    (* GET_Map2d(disp)) parameters
static inline _glptr_Map2d GET_Map2d(struct _glapi_table *disp) {
   return (_glptr_Map2d) (GET_by_offset(disp, _gloffset_Map2d));
}

static inline void SET_Map2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Map2d, fn);
}

typedef void (GLAPIENTRYP _glptr_Map2f)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define CALL_Map2f(disp, parameters) \
    (* GET_Map2f(disp)) parameters
static inline _glptr_Map2f GET_Map2f(struct _glapi_table *disp) {
   return (_glptr_Map2f) (GET_by_offset(disp, _gloffset_Map2f));
}

static inline void SET_Map2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Map2f, fn);
}

typedef void (GLAPIENTRYP _glptr_MapGrid1d)(GLint, GLdouble, GLdouble);
#define CALL_MapGrid1d(disp, parameters) \
    (* GET_MapGrid1d(disp)) parameters
static inline _glptr_MapGrid1d GET_MapGrid1d(struct _glapi_table *disp) {
   return (_glptr_MapGrid1d) (GET_by_offset(disp, _gloffset_MapGrid1d));
}

static inline void SET_MapGrid1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_MapGrid1d, fn);
}

typedef void (GLAPIENTRYP _glptr_MapGrid1f)(GLint, GLfloat, GLfloat);
#define CALL_MapGrid1f(disp, parameters) \
    (* GET_MapGrid1f(disp)) parameters
static inline _glptr_MapGrid1f GET_MapGrid1f(struct _glapi_table *disp) {
   return (_glptr_MapGrid1f) (GET_by_offset(disp, _gloffset_MapGrid1f));
}

static inline void SET_MapGrid1f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_MapGrid1f, fn);
}

typedef void (GLAPIENTRYP _glptr_MapGrid2d)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
#define CALL_MapGrid2d(disp, parameters) \
    (* GET_MapGrid2d(disp)) parameters
static inline _glptr_MapGrid2d GET_MapGrid2d(struct _glapi_table *disp) {
   return (_glptr_MapGrid2d) (GET_by_offset(disp, _gloffset_MapGrid2d));
}

static inline void SET_MapGrid2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_MapGrid2d, fn);
}

typedef void (GLAPIENTRYP _glptr_MapGrid2f)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
#define CALL_MapGrid2f(disp, parameters) \
    (* GET_MapGrid2f(disp)) parameters
static inline _glptr_MapGrid2f GET_MapGrid2f(struct _glapi_table *disp) {
   return (_glptr_MapGrid2f) (GET_by_offset(disp, _gloffset_MapGrid2f));
}

static inline void SET_MapGrid2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_MapGrid2f, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord1d)(GLdouble);
#define CALL_EvalCoord1d(disp, parameters) \
    (* GET_EvalCoord1d(disp)) parameters
static inline _glptr_EvalCoord1d GET_EvalCoord1d(struct _glapi_table *disp) {
   return (_glptr_EvalCoord1d) (GET_by_offset(disp, _gloffset_EvalCoord1d));
}

static inline void SET_EvalCoord1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble)) {
   SET_by_offset(disp, _gloffset_EvalCoord1d, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord1dv)(const GLdouble *);
#define CALL_EvalCoord1dv(disp, parameters) \
    (* GET_EvalCoord1dv(disp)) parameters
static inline _glptr_EvalCoord1dv GET_EvalCoord1dv(struct _glapi_table *disp) {
   return (_glptr_EvalCoord1dv) (GET_by_offset(disp, _gloffset_EvalCoord1dv));
}

static inline void SET_EvalCoord1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_EvalCoord1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord1f)(GLfloat);
#define CALL_EvalCoord1f(disp, parameters) \
    (* GET_EvalCoord1f(disp)) parameters
static inline _glptr_EvalCoord1f GET_EvalCoord1f(struct _glapi_table *disp) {
   return (_glptr_EvalCoord1f) (GET_by_offset(disp, _gloffset_EvalCoord1f));
}

static inline void SET_EvalCoord1f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_EvalCoord1f, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord1fv)(const GLfloat *);
#define CALL_EvalCoord1fv(disp, parameters) \
    (* GET_EvalCoord1fv(disp)) parameters
static inline _glptr_EvalCoord1fv GET_EvalCoord1fv(struct _glapi_table *disp) {
   return (_glptr_EvalCoord1fv) (GET_by_offset(disp, _gloffset_EvalCoord1fv));
}

static inline void SET_EvalCoord1fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_EvalCoord1fv, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord2d)(GLdouble, GLdouble);
#define CALL_EvalCoord2d(disp, parameters) \
    (* GET_EvalCoord2d(disp)) parameters
static inline _glptr_EvalCoord2d GET_EvalCoord2d(struct _glapi_table *disp) {
   return (_glptr_EvalCoord2d) (GET_by_offset(disp, _gloffset_EvalCoord2d));
}

static inline void SET_EvalCoord2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_EvalCoord2d, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord2dv)(const GLdouble *);
#define CALL_EvalCoord2dv(disp, parameters) \
    (* GET_EvalCoord2dv(disp)) parameters
static inline _glptr_EvalCoord2dv GET_EvalCoord2dv(struct _glapi_table *disp) {
   return (_glptr_EvalCoord2dv) (GET_by_offset(disp, _gloffset_EvalCoord2dv));
}

static inline void SET_EvalCoord2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_EvalCoord2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord2f)(GLfloat, GLfloat);
#define CALL_EvalCoord2f(disp, parameters) \
    (* GET_EvalCoord2f(disp)) parameters
static inline _glptr_EvalCoord2f GET_EvalCoord2f(struct _glapi_table *disp) {
   return (_glptr_EvalCoord2f) (GET_by_offset(disp, _gloffset_EvalCoord2f));
}

static inline void SET_EvalCoord2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_EvalCoord2f, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalCoord2fv)(const GLfloat *);
#define CALL_EvalCoord2fv(disp, parameters) \
    (* GET_EvalCoord2fv(disp)) parameters
static inline _glptr_EvalCoord2fv GET_EvalCoord2fv(struct _glapi_table *disp) {
   return (_glptr_EvalCoord2fv) (GET_by_offset(disp, _gloffset_EvalCoord2fv));
}

static inline void SET_EvalCoord2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_EvalCoord2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalMesh1)(GLenum, GLint, GLint);
#define CALL_EvalMesh1(disp, parameters) \
    (* GET_EvalMesh1(disp)) parameters
static inline _glptr_EvalMesh1 GET_EvalMesh1(struct _glapi_table *disp) {
   return (_glptr_EvalMesh1) (GET_by_offset(disp, _gloffset_EvalMesh1));
}

static inline void SET_EvalMesh1(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_EvalMesh1, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalPoint1)(GLint);
#define CALL_EvalPoint1(disp, parameters) \
    (* GET_EvalPoint1(disp)) parameters
static inline _glptr_EvalPoint1 GET_EvalPoint1(struct _glapi_table *disp) {
   return (_glptr_EvalPoint1) (GET_by_offset(disp, _gloffset_EvalPoint1));
}

static inline void SET_EvalPoint1(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint)) {
   SET_by_offset(disp, _gloffset_EvalPoint1, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalMesh2)(GLenum, GLint, GLint, GLint, GLint);
#define CALL_EvalMesh2(disp, parameters) \
    (* GET_EvalMesh2(disp)) parameters
static inline _glptr_EvalMesh2 GET_EvalMesh2(struct _glapi_table *disp) {
   return (_glptr_EvalMesh2) (GET_by_offset(disp, _gloffset_EvalMesh2));
}

static inline void SET_EvalMesh2(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_EvalMesh2, fn);
}

typedef void (GLAPIENTRYP _glptr_EvalPoint2)(GLint, GLint);
#define CALL_EvalPoint2(disp, parameters) \
    (* GET_EvalPoint2(disp)) parameters
static inline _glptr_EvalPoint2 GET_EvalPoint2(struct _glapi_table *disp) {
   return (_glptr_EvalPoint2) (GET_by_offset(disp, _gloffset_EvalPoint2));
}

static inline void SET_EvalPoint2(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint)) {
   SET_by_offset(disp, _gloffset_EvalPoint2, fn);
}

typedef void (GLAPIENTRYP _glptr_AlphaFunc)(GLenum, GLclampf);
#define CALL_AlphaFunc(disp, parameters) \
    (* GET_AlphaFunc(disp)) parameters
static inline _glptr_AlphaFunc GET_AlphaFunc(struct _glapi_table *disp) {
   return (_glptr_AlphaFunc) (GET_by_offset(disp, _gloffset_AlphaFunc));
}

static inline void SET_AlphaFunc(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLclampf)) {
   SET_by_offset(disp, _gloffset_AlphaFunc, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendFunc)(GLenum, GLenum);
#define CALL_BlendFunc(disp, parameters) \
    (* GET_BlendFunc(disp)) parameters
static inline _glptr_BlendFunc GET_BlendFunc(struct _glapi_table *disp) {
   return (_glptr_BlendFunc) (GET_by_offset(disp, _gloffset_BlendFunc));
}

static inline void SET_BlendFunc(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendFunc, fn);
}

typedef void (GLAPIENTRYP _glptr_LogicOp)(GLenum);
#define CALL_LogicOp(disp, parameters) \
    (* GET_LogicOp(disp)) parameters
static inline _glptr_LogicOp GET_LogicOp(struct _glapi_table *disp) {
   return (_glptr_LogicOp) (GET_by_offset(disp, _gloffset_LogicOp));
}

static inline void SET_LogicOp(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_LogicOp, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilFunc)(GLenum, GLint, GLuint);
#define CALL_StencilFunc(disp, parameters) \
    (* GET_StencilFunc(disp)) parameters
static inline _glptr_StencilFunc GET_StencilFunc(struct _glapi_table *disp) {
   return (_glptr_StencilFunc) (GET_by_offset(disp, _gloffset_StencilFunc));
}

static inline void SET_StencilFunc(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLuint)) {
   SET_by_offset(disp, _gloffset_StencilFunc, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilOp)(GLenum, GLenum, GLenum);
#define CALL_StencilOp(disp, parameters) \
    (* GET_StencilOp(disp)) parameters
static inline _glptr_StencilOp GET_StencilOp(struct _glapi_table *disp) {
   return (_glptr_StencilOp) (GET_by_offset(disp, _gloffset_StencilOp));
}

static inline void SET_StencilOp(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_StencilOp, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthFunc)(GLenum);
#define CALL_DepthFunc(disp, parameters) \
    (* GET_DepthFunc(disp)) parameters
static inline _glptr_DepthFunc GET_DepthFunc(struct _glapi_table *disp) {
   return (_glptr_DepthFunc) (GET_by_offset(disp, _gloffset_DepthFunc));
}

static inline void SET_DepthFunc(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_DepthFunc, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelZoom)(GLfloat, GLfloat);
#define CALL_PixelZoom(disp, parameters) \
    (* GET_PixelZoom(disp)) parameters
static inline _glptr_PixelZoom GET_PixelZoom(struct _glapi_table *disp) {
   return (_glptr_PixelZoom) (GET_by_offset(disp, _gloffset_PixelZoom));
}

static inline void SET_PixelZoom(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_PixelZoom, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelTransferf)(GLenum, GLfloat);
#define CALL_PixelTransferf(disp, parameters) \
    (* GET_PixelTransferf(disp)) parameters
static inline _glptr_PixelTransferf GET_PixelTransferf(struct _glapi_table *disp) {
   return (_glptr_PixelTransferf) (GET_by_offset(disp, _gloffset_PixelTransferf));
}

static inline void SET_PixelTransferf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_PixelTransferf, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelTransferi)(GLenum, GLint);
#define CALL_PixelTransferi(disp, parameters) \
    (* GET_PixelTransferi(disp)) parameters
static inline _glptr_PixelTransferi GET_PixelTransferi(struct _glapi_table *disp) {
   return (_glptr_PixelTransferi) (GET_by_offset(disp, _gloffset_PixelTransferi));
}

static inline void SET_PixelTransferi(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_PixelTransferi, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelStoref)(GLenum, GLfloat);
#define CALL_PixelStoref(disp, parameters) \
    (* GET_PixelStoref(disp)) parameters
static inline _glptr_PixelStoref GET_PixelStoref(struct _glapi_table *disp) {
   return (_glptr_PixelStoref) (GET_by_offset(disp, _gloffset_PixelStoref));
}

static inline void SET_PixelStoref(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_PixelStoref, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelStorei)(GLenum, GLint);
#define CALL_PixelStorei(disp, parameters) \
    (* GET_PixelStorei(disp)) parameters
static inline _glptr_PixelStorei GET_PixelStorei(struct _glapi_table *disp) {
   return (_glptr_PixelStorei) (GET_by_offset(disp, _gloffset_PixelStorei));
}

static inline void SET_PixelStorei(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_PixelStorei, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelMapfv)(GLenum, GLsizei, const GLfloat *);
#define CALL_PixelMapfv(disp, parameters) \
    (* GET_PixelMapfv(disp)) parameters
static inline _glptr_PixelMapfv GET_PixelMapfv(struct _glapi_table *disp) {
   return (_glptr_PixelMapfv) (GET_by_offset(disp, _gloffset_PixelMapfv));
}

static inline void SET_PixelMapfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_PixelMapfv, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelMapuiv)(GLenum, GLsizei, const GLuint *);
#define CALL_PixelMapuiv(disp, parameters) \
    (* GET_PixelMapuiv(disp)) parameters
static inline _glptr_PixelMapuiv GET_PixelMapuiv(struct _glapi_table *disp) {
   return (_glptr_PixelMapuiv) (GET_by_offset(disp, _gloffset_PixelMapuiv));
}

static inline void SET_PixelMapuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_PixelMapuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_PixelMapusv)(GLenum, GLsizei, const GLushort *);
#define CALL_PixelMapusv(disp, parameters) \
    (* GET_PixelMapusv(disp)) parameters
static inline _glptr_PixelMapusv GET_PixelMapusv(struct _glapi_table *disp) {
   return (_glptr_PixelMapusv) (GET_by_offset(disp, _gloffset_PixelMapusv));
}

static inline void SET_PixelMapusv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLushort *)) {
   SET_by_offset(disp, _gloffset_PixelMapusv, fn);
}

typedef void (GLAPIENTRYP _glptr_ReadBuffer)(GLenum);
#define CALL_ReadBuffer(disp, parameters) \
    (* GET_ReadBuffer(disp)) parameters
static inline _glptr_ReadBuffer GET_ReadBuffer(struct _glapi_table *disp) {
   return (_glptr_ReadBuffer) (GET_by_offset(disp, _gloffset_ReadBuffer));
}

static inline void SET_ReadBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ReadBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyPixels)(GLint, GLint, GLsizei, GLsizei, GLenum);
#define CALL_CopyPixels(disp, parameters) \
    (* GET_CopyPixels(disp)) parameters
static inline _glptr_CopyPixels GET_CopyPixels(struct _glapi_table *disp) {
   return (_glptr_CopyPixels) (GET_by_offset(disp, _gloffset_CopyPixels));
}

static inline void SET_CopyPixels(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLsizei, GLsizei, GLenum)) {
   SET_by_offset(disp, _gloffset_CopyPixels, fn);
}

typedef void (GLAPIENTRYP _glptr_ReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
#define CALL_ReadPixels(disp, parameters) \
    (* GET_ReadPixels(disp)) parameters
static inline _glptr_ReadPixels GET_ReadPixels(struct _glapi_table *disp) {
   return (_glptr_ReadPixels) (GET_by_offset(disp, _gloffset_ReadPixels));
}

static inline void SET_ReadPixels(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_ReadPixels, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawPixels)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_DrawPixels(disp, parameters) \
    (* GET_DrawPixels(disp)) parameters
static inline _glptr_DrawPixels GET_DrawPixels(struct _glapi_table *disp) {
   return (_glptr_DrawPixels) (GET_by_offset(disp, _gloffset_DrawPixels));
}

static inline void SET_DrawPixels(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_DrawPixels, fn);
}

typedef void (GLAPIENTRYP _glptr_GetBooleanv)(GLenum, GLboolean *);
#define CALL_GetBooleanv(disp, parameters) \
    (* GET_GetBooleanv(disp)) parameters
static inline _glptr_GetBooleanv GET_GetBooleanv(struct _glapi_table *disp) {
   return (_glptr_GetBooleanv) (GET_by_offset(disp, _gloffset_GetBooleanv));
}

static inline void SET_GetBooleanv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLboolean *)) {
   SET_by_offset(disp, _gloffset_GetBooleanv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetClipPlane)(GLenum, GLdouble *);
#define CALL_GetClipPlane(disp, parameters) \
    (* GET_GetClipPlane(disp)) parameters
static inline _glptr_GetClipPlane GET_GetClipPlane(struct _glapi_table *disp) {
   return (_glptr_GetClipPlane) (GET_by_offset(disp, _gloffset_GetClipPlane));
}

static inline void SET_GetClipPlane(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetClipPlane, fn);
}

typedef void (GLAPIENTRYP _glptr_GetDoublev)(GLenum, GLdouble *);
#define CALL_GetDoublev(disp, parameters) \
    (* GET_GetDoublev(disp)) parameters
static inline _glptr_GetDoublev GET_GetDoublev(struct _glapi_table *disp) {
   return (_glptr_GetDoublev) (GET_by_offset(disp, _gloffset_GetDoublev));
}

static inline void SET_GetDoublev(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetDoublev, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_GetError)(void);
#define CALL_GetError(disp, parameters) \
    (* GET_GetError(disp)) parameters
static inline _glptr_GetError GET_GetError(struct _glapi_table *disp) {
   return (_glptr_GetError) (GET_by_offset(disp, _gloffset_GetError));
}

static inline void SET_GetError(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_GetError, fn);
}

typedef void (GLAPIENTRYP _glptr_GetFloatv)(GLenum, GLfloat *);
#define CALL_GetFloatv(disp, parameters) \
    (* GET_GetFloatv(disp)) parameters
static inline _glptr_GetFloatv GET_GetFloatv(struct _glapi_table *disp) {
   return (_glptr_GetFloatv) (GET_by_offset(disp, _gloffset_GetFloatv));
}

static inline void SET_GetFloatv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetFloatv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetIntegerv)(GLenum, GLint *);
#define CALL_GetIntegerv(disp, parameters) \
    (* GET_GetIntegerv(disp)) parameters
static inline _glptr_GetIntegerv GET_GetIntegerv(struct _glapi_table *disp) {
   return (_glptr_GetIntegerv) (GET_by_offset(disp, _gloffset_GetIntegerv));
}

static inline void SET_GetIntegerv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetIntegerv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetLightfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetLightfv(disp, parameters) \
    (* GET_GetLightfv(disp)) parameters
static inline _glptr_GetLightfv GET_GetLightfv(struct _glapi_table *disp) {
   return (_glptr_GetLightfv) (GET_by_offset(disp, _gloffset_GetLightfv));
}

static inline void SET_GetLightfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetLightfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetLightiv)(GLenum, GLenum, GLint *);
#define CALL_GetLightiv(disp, parameters) \
    (* GET_GetLightiv(disp)) parameters
static inline _glptr_GetLightiv GET_GetLightiv(struct _glapi_table *disp) {
   return (_glptr_GetLightiv) (GET_by_offset(disp, _gloffset_GetLightiv));
}

static inline void SET_GetLightiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetLightiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMapdv)(GLenum, GLenum, GLdouble *);
#define CALL_GetMapdv(disp, parameters) \
    (* GET_GetMapdv(disp)) parameters
static inline _glptr_GetMapdv GET_GetMapdv(struct _glapi_table *disp) {
   return (_glptr_GetMapdv) (GET_by_offset(disp, _gloffset_GetMapdv));
}

static inline void SET_GetMapdv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetMapdv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMapfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetMapfv(disp, parameters) \
    (* GET_GetMapfv(disp)) parameters
static inline _glptr_GetMapfv GET_GetMapfv(struct _glapi_table *disp) {
   return (_glptr_GetMapfv) (GET_by_offset(disp, _gloffset_GetMapfv));
}

static inline void SET_GetMapfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetMapfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMapiv)(GLenum, GLenum, GLint *);
#define CALL_GetMapiv(disp, parameters) \
    (* GET_GetMapiv(disp)) parameters
static inline _glptr_GetMapiv GET_GetMapiv(struct _glapi_table *disp) {
   return (_glptr_GetMapiv) (GET_by_offset(disp, _gloffset_GetMapiv));
}

static inline void SET_GetMapiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetMapiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMaterialfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetMaterialfv(disp, parameters) \
    (* GET_GetMaterialfv(disp)) parameters
static inline _glptr_GetMaterialfv GET_GetMaterialfv(struct _glapi_table *disp) {
   return (_glptr_GetMaterialfv) (GET_by_offset(disp, _gloffset_GetMaterialfv));
}

static inline void SET_GetMaterialfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetMaterialfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMaterialiv)(GLenum, GLenum, GLint *);
#define CALL_GetMaterialiv(disp, parameters) \
    (* GET_GetMaterialiv(disp)) parameters
static inline _glptr_GetMaterialiv GET_GetMaterialiv(struct _glapi_table *disp) {
   return (_glptr_GetMaterialiv) (GET_by_offset(disp, _gloffset_GetMaterialiv));
}

static inline void SET_GetMaterialiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetMaterialiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPixelMapfv)(GLenum, GLfloat *);
#define CALL_GetPixelMapfv(disp, parameters) \
    (* GET_GetPixelMapfv(disp)) parameters
static inline _glptr_GetPixelMapfv GET_GetPixelMapfv(struct _glapi_table *disp) {
   return (_glptr_GetPixelMapfv) (GET_by_offset(disp, _gloffset_GetPixelMapfv));
}

static inline void SET_GetPixelMapfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetPixelMapfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPixelMapuiv)(GLenum, GLuint *);
#define CALL_GetPixelMapuiv(disp, parameters) \
    (* GET_GetPixelMapuiv(disp)) parameters
static inline _glptr_GetPixelMapuiv GET_GetPixelMapuiv(struct _glapi_table *disp) {
   return (_glptr_GetPixelMapuiv) (GET_by_offset(disp, _gloffset_GetPixelMapuiv));
}

static inline void SET_GetPixelMapuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetPixelMapuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPixelMapusv)(GLenum, GLushort *);
#define CALL_GetPixelMapusv(disp, parameters) \
    (* GET_GetPixelMapusv(disp)) parameters
static inline _glptr_GetPixelMapusv GET_GetPixelMapusv(struct _glapi_table *disp) {
   return (_glptr_GetPixelMapusv) (GET_by_offset(disp, _gloffset_GetPixelMapusv));
}

static inline void SET_GetPixelMapusv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLushort *)) {
   SET_by_offset(disp, _gloffset_GetPixelMapusv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPolygonStipple)(GLubyte *);
#define CALL_GetPolygonStipple(disp, parameters) \
    (* GET_GetPolygonStipple(disp)) parameters
static inline _glptr_GetPolygonStipple GET_GetPolygonStipple(struct _glapi_table *disp) {
   return (_glptr_GetPolygonStipple) (GET_by_offset(disp, _gloffset_GetPolygonStipple));
}

static inline void SET_GetPolygonStipple(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLubyte *)) {
   SET_by_offset(disp, _gloffset_GetPolygonStipple, fn);
}

typedef const GLubyte * (GLAPIENTRYP _glptr_GetString)(GLenum);
#define CALL_GetString(disp, parameters) \
    (* GET_GetString(disp)) parameters
static inline _glptr_GetString GET_GetString(struct _glapi_table *disp) {
   return (_glptr_GetString) (GET_by_offset(disp, _gloffset_GetString));
}

static inline void SET_GetString(struct _glapi_table *disp, const GLubyte * (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_GetString, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexEnvfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetTexEnvfv(disp, parameters) \
    (* GET_GetTexEnvfv(disp)) parameters
static inline _glptr_GetTexEnvfv GET_GetTexEnvfv(struct _glapi_table *disp) {
   return (_glptr_GetTexEnvfv) (GET_by_offset(disp, _gloffset_GetTexEnvfv));
}

static inline void SET_GetTexEnvfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTexEnvfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexEnviv)(GLenum, GLenum, GLint *);
#define CALL_GetTexEnviv(disp, parameters) \
    (* GET_GetTexEnviv(disp)) parameters
static inline _glptr_GetTexEnviv GET_GetTexEnviv(struct _glapi_table *disp) {
   return (_glptr_GetTexEnviv) (GET_by_offset(disp, _gloffset_GetTexEnviv));
}

static inline void SET_GetTexEnviv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTexEnviv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexGendv)(GLenum, GLenum, GLdouble *);
#define CALL_GetTexGendv(disp, parameters) \
    (* GET_GetTexGendv(disp)) parameters
static inline _glptr_GetTexGendv GET_GetTexGendv(struct _glapi_table *disp) {
   return (_glptr_GetTexGendv) (GET_by_offset(disp, _gloffset_GetTexGendv));
}

static inline void SET_GetTexGendv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetTexGendv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexGenfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetTexGenfv(disp, parameters) \
    (* GET_GetTexGenfv(disp)) parameters
static inline _glptr_GetTexGenfv GET_GetTexGenfv(struct _glapi_table *disp) {
   return (_glptr_GetTexGenfv) (GET_by_offset(disp, _gloffset_GetTexGenfv));
}

static inline void SET_GetTexGenfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTexGenfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexGeniv)(GLenum, GLenum, GLint *);
#define CALL_GetTexGeniv(disp, parameters) \
    (* GET_GetTexGeniv(disp)) parameters
static inline _glptr_GetTexGeniv GET_GetTexGeniv(struct _glapi_table *disp) {
   return (_glptr_GetTexGeniv) (GET_by_offset(disp, _gloffset_GetTexGeniv));
}

static inline void SET_GetTexGeniv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTexGeniv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexImage)(GLenum, GLint, GLenum, GLenum, GLvoid *);
#define CALL_GetTexImage(disp, parameters) \
    (* GET_GetTexImage(disp)) parameters
static inline _glptr_GetTexImage GET_GetTexImage(struct _glapi_table *disp) {
   return (_glptr_GetTexImage) (GET_by_offset(disp, _gloffset_GetTexImage));
}

static inline void SET_GetTexImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetTexImage, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexParameterfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetTexParameterfv(disp, parameters) \
    (* GET_GetTexParameterfv(disp)) parameters
static inline _glptr_GetTexParameterfv GET_GetTexParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetTexParameterfv) (GET_by_offset(disp, _gloffset_GetTexParameterfv));
}

static inline void SET_GetTexParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTexParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetTexParameteriv(disp, parameters) \
    (* GET_GetTexParameteriv(disp)) parameters
static inline _glptr_GetTexParameteriv GET_GetTexParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetTexParameteriv) (GET_by_offset(disp, _gloffset_GetTexParameteriv));
}

static inline void SET_GetTexParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTexParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexLevelParameterfv)(GLenum, GLint, GLenum, GLfloat *);
#define CALL_GetTexLevelParameterfv(disp, parameters) \
    (* GET_GetTexLevelParameterfv(disp)) parameters
static inline _glptr_GetTexLevelParameterfv GET_GetTexLevelParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetTexLevelParameterfv) (GET_by_offset(disp, _gloffset_GetTexLevelParameterfv));
}

static inline void SET_GetTexLevelParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTexLevelParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexLevelParameteriv)(GLenum, GLint, GLenum, GLint *);
#define CALL_GetTexLevelParameteriv(disp, parameters) \
    (* GET_GetTexLevelParameteriv(disp)) parameters
static inline _glptr_GetTexLevelParameteriv GET_GetTexLevelParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetTexLevelParameteriv) (GET_by_offset(disp, _gloffset_GetTexLevelParameteriv));
}

static inline void SET_GetTexLevelParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTexLevelParameteriv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsEnabled)(GLenum);
#define CALL_IsEnabled(disp, parameters) \
    (* GET_IsEnabled(disp)) parameters
static inline _glptr_IsEnabled GET_IsEnabled(struct _glapi_table *disp) {
   return (_glptr_IsEnabled) (GET_by_offset(disp, _gloffset_IsEnabled));
}

static inline void SET_IsEnabled(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_IsEnabled, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsList)(GLuint);
#define CALL_IsList(disp, parameters) \
    (* GET_IsList(disp)) parameters
static inline _glptr_IsList GET_IsList(struct _glapi_table *disp) {
   return (_glptr_IsList) (GET_by_offset(disp, _gloffset_IsList));
}

static inline void SET_IsList(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsList, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRange)(GLclampd, GLclampd);
#define CALL_DepthRange(disp, parameters) \
    (* GET_DepthRange(disp)) parameters
static inline _glptr_DepthRange GET_DepthRange(struct _glapi_table *disp) {
   return (_glptr_DepthRange) (GET_by_offset(disp, _gloffset_DepthRange));
}

static inline void SET_DepthRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampd, GLclampd)) {
   SET_by_offset(disp, _gloffset_DepthRange, fn);
}

typedef void (GLAPIENTRYP _glptr_Frustum)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Frustum(disp, parameters) \
    (* GET_Frustum(disp)) parameters
static inline _glptr_Frustum GET_Frustum(struct _glapi_table *disp) {
   return (_glptr_Frustum) (GET_by_offset(disp, _gloffset_Frustum));
}

static inline void SET_Frustum(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Frustum, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadIdentity)(void);
#define CALL_LoadIdentity(disp, parameters) \
    (* GET_LoadIdentity(disp)) parameters
static inline _glptr_LoadIdentity GET_LoadIdentity(struct _glapi_table *disp) {
   return (_glptr_LoadIdentity) (GET_by_offset(disp, _gloffset_LoadIdentity));
}

static inline void SET_LoadIdentity(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_LoadIdentity, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadMatrixf)(const GLfloat *);
#define CALL_LoadMatrixf(disp, parameters) \
    (* GET_LoadMatrixf(disp)) parameters
static inline _glptr_LoadMatrixf GET_LoadMatrixf(struct _glapi_table *disp) {
   return (_glptr_LoadMatrixf) (GET_by_offset(disp, _gloffset_LoadMatrixf));
}

static inline void SET_LoadMatrixf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_LoadMatrixf, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadMatrixd)(const GLdouble *);
#define CALL_LoadMatrixd(disp, parameters) \
    (* GET_LoadMatrixd(disp)) parameters
static inline _glptr_LoadMatrixd GET_LoadMatrixd(struct _glapi_table *disp) {
   return (_glptr_LoadMatrixd) (GET_by_offset(disp, _gloffset_LoadMatrixd));
}

static inline void SET_LoadMatrixd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_LoadMatrixd, fn);
}

typedef void (GLAPIENTRYP _glptr_MatrixMode)(GLenum);
#define CALL_MatrixMode(disp, parameters) \
    (* GET_MatrixMode(disp)) parameters
static inline _glptr_MatrixMode GET_MatrixMode(struct _glapi_table *disp) {
   return (_glptr_MatrixMode) (GET_by_offset(disp, _gloffset_MatrixMode));
}

static inline void SET_MatrixMode(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_MatrixMode, fn);
}

typedef void (GLAPIENTRYP _glptr_MultMatrixf)(const GLfloat *);
#define CALL_MultMatrixf(disp, parameters) \
    (* GET_MultMatrixf(disp)) parameters
static inline _glptr_MultMatrixf GET_MultMatrixf(struct _glapi_table *disp) {
   return (_glptr_MultMatrixf) (GET_by_offset(disp, _gloffset_MultMatrixf));
}

static inline void SET_MultMatrixf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_MultMatrixf, fn);
}

typedef void (GLAPIENTRYP _glptr_MultMatrixd)(const GLdouble *);
#define CALL_MultMatrixd(disp, parameters) \
    (* GET_MultMatrixd(disp)) parameters
static inline _glptr_MultMatrixd GET_MultMatrixd(struct _glapi_table *disp) {
   return (_glptr_MultMatrixd) (GET_by_offset(disp, _gloffset_MultMatrixd));
}

static inline void SET_MultMatrixd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_MultMatrixd, fn);
}

typedef void (GLAPIENTRYP _glptr_Ortho)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Ortho(disp, parameters) \
    (* GET_Ortho(disp)) parameters
static inline _glptr_Ortho GET_Ortho(struct _glapi_table *disp) {
   return (_glptr_Ortho) (GET_by_offset(disp, _gloffset_Ortho));
}

static inline void SET_Ortho(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Ortho, fn);
}

typedef void (GLAPIENTRYP _glptr_PopMatrix)(void);
#define CALL_PopMatrix(disp, parameters) \
    (* GET_PopMatrix(disp)) parameters
static inline _glptr_PopMatrix GET_PopMatrix(struct _glapi_table *disp) {
   return (_glptr_PopMatrix) (GET_by_offset(disp, _gloffset_PopMatrix));
}

static inline void SET_PopMatrix(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PopMatrix, fn);
}

typedef void (GLAPIENTRYP _glptr_PushMatrix)(void);
#define CALL_PushMatrix(disp, parameters) \
    (* GET_PushMatrix(disp)) parameters
static inline _glptr_PushMatrix GET_PushMatrix(struct _glapi_table *disp) {
   return (_glptr_PushMatrix) (GET_by_offset(disp, _gloffset_PushMatrix));
}

static inline void SET_PushMatrix(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PushMatrix, fn);
}

typedef void (GLAPIENTRYP _glptr_Rotated)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Rotated(disp, parameters) \
    (* GET_Rotated(disp)) parameters
static inline _glptr_Rotated GET_Rotated(struct _glapi_table *disp) {
   return (_glptr_Rotated) (GET_by_offset(disp, _gloffset_Rotated));
}

static inline void SET_Rotated(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Rotated, fn);
}

typedef void (GLAPIENTRYP _glptr_Rotatef)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Rotatef(disp, parameters) \
    (* GET_Rotatef(disp)) parameters
static inline _glptr_Rotatef GET_Rotatef(struct _glapi_table *disp) {
   return (_glptr_Rotatef) (GET_by_offset(disp, _gloffset_Rotatef));
}

static inline void SET_Rotatef(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Rotatef, fn);
}

typedef void (GLAPIENTRYP _glptr_Scaled)(GLdouble, GLdouble, GLdouble);
#define CALL_Scaled(disp, parameters) \
    (* GET_Scaled(disp)) parameters
static inline _glptr_Scaled GET_Scaled(struct _glapi_table *disp) {
   return (_glptr_Scaled) (GET_by_offset(disp, _gloffset_Scaled));
}

static inline void SET_Scaled(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Scaled, fn);
}

typedef void (GLAPIENTRYP _glptr_Scalef)(GLfloat, GLfloat, GLfloat);
#define CALL_Scalef(disp, parameters) \
    (* GET_Scalef(disp)) parameters
static inline _glptr_Scalef GET_Scalef(struct _glapi_table *disp) {
   return (_glptr_Scalef) (GET_by_offset(disp, _gloffset_Scalef));
}

static inline void SET_Scalef(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Scalef, fn);
}

typedef void (GLAPIENTRYP _glptr_Translated)(GLdouble, GLdouble, GLdouble);
#define CALL_Translated(disp, parameters) \
    (* GET_Translated(disp)) parameters
static inline _glptr_Translated GET_Translated(struct _glapi_table *disp) {
   return (_glptr_Translated) (GET_by_offset(disp, _gloffset_Translated));
}

static inline void SET_Translated(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Translated, fn);
}

typedef void (GLAPIENTRYP _glptr_Translatef)(GLfloat, GLfloat, GLfloat);
#define CALL_Translatef(disp, parameters) \
    (* GET_Translatef(disp)) parameters
static inline _glptr_Translatef GET_Translatef(struct _glapi_table *disp) {
   return (_glptr_Translatef) (GET_by_offset(disp, _gloffset_Translatef));
}

static inline void SET_Translatef(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Translatef, fn);
}

typedef void (GLAPIENTRYP _glptr_Viewport)(GLint, GLint, GLsizei, GLsizei);
#define CALL_Viewport(disp, parameters) \
    (* GET_Viewport(disp)) parameters
static inline _glptr_Viewport GET_Viewport(struct _glapi_table *disp) {
   return (_glptr_Viewport) (GET_by_offset(disp, _gloffset_Viewport));
}

static inline void SET_Viewport(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_Viewport, fn);
}

typedef void (GLAPIENTRYP _glptr_ArrayElement)(GLint);
#define CALL_ArrayElement(disp, parameters) \
    (* GET_ArrayElement(disp)) parameters
static inline _glptr_ArrayElement GET_ArrayElement(struct _glapi_table *disp) {
   return (_glptr_ArrayElement) (GET_by_offset(disp, _gloffset_ArrayElement));
}

static inline void SET_ArrayElement(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint)) {
   SET_by_offset(disp, _gloffset_ArrayElement, fn);
}

typedef void (GLAPIENTRYP _glptr_BindTexture)(GLenum, GLuint);
#define CALL_BindTexture(disp, parameters) \
    (* GET_BindTexture(disp)) parameters
static inline _glptr_BindTexture GET_BindTexture(struct _glapi_table *disp) {
   return (_glptr_BindTexture) (GET_by_offset(disp, _gloffset_BindTexture));
}

static inline void SET_BindTexture(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_ColorPointer(disp, parameters) \
    (* GET_ColorPointer(disp)) parameters
static inline _glptr_ColorPointer GET_ColorPointer(struct _glapi_table *disp) {
   return (_glptr_ColorPointer) (GET_by_offset(disp, _gloffset_ColorPointer));
}

static inline void SET_ColorPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ColorPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_DisableClientState)(GLenum);
#define CALL_DisableClientState(disp, parameters) \
    (* GET_DisableClientState(disp)) parameters
static inline _glptr_DisableClientState GET_DisableClientState(struct _glapi_table *disp) {
   return (_glptr_DisableClientState) (GET_by_offset(disp, _gloffset_DisableClientState));
}

static inline void SET_DisableClientState(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_DisableClientState, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawArrays)(GLenum, GLint, GLsizei);
#define CALL_DrawArrays(disp, parameters) \
    (* GET_DrawArrays(disp)) parameters
static inline _glptr_DrawArrays GET_DrawArrays(struct _glapi_table *disp) {
   return (_glptr_DrawArrays) (GET_by_offset(disp, _gloffset_DrawArrays));
}

static inline void SET_DrawArrays(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_DrawArrays, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElements)(GLenum, GLsizei, GLenum, const GLvoid *);
#define CALL_DrawElements(disp, parameters) \
    (* GET_DrawElements(disp)) parameters
static inline _glptr_DrawElements GET_DrawElements(struct _glapi_table *disp) {
   return (_glptr_DrawElements) (GET_by_offset(disp, _gloffset_DrawElements));
}

static inline void SET_DrawElements(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_DrawElements, fn);
}

typedef void (GLAPIENTRYP _glptr_EdgeFlagPointer)(GLsizei, const GLvoid *);
#define CALL_EdgeFlagPointer(disp, parameters) \
    (* GET_EdgeFlagPointer(disp)) parameters
static inline _glptr_EdgeFlagPointer GET_EdgeFlagPointer(struct _glapi_table *disp) {
   return (_glptr_EdgeFlagPointer) (GET_by_offset(disp, _gloffset_EdgeFlagPointer));
}

static inline void SET_EdgeFlagPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_EdgeFlagPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_EnableClientState)(GLenum);
#define CALL_EnableClientState(disp, parameters) \
    (* GET_EnableClientState(disp)) parameters
static inline _glptr_EnableClientState GET_EnableClientState(struct _glapi_table *disp) {
   return (_glptr_EnableClientState) (GET_by_offset(disp, _gloffset_EnableClientState));
}

static inline void SET_EnableClientState(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_EnableClientState, fn);
}

typedef void (GLAPIENTRYP _glptr_IndexPointer)(GLenum, GLsizei, const GLvoid *);
#define CALL_IndexPointer(disp, parameters) \
    (* GET_IndexPointer(disp)) parameters
static inline _glptr_IndexPointer GET_IndexPointer(struct _glapi_table *disp) {
   return (_glptr_IndexPointer) (GET_by_offset(disp, _gloffset_IndexPointer));
}

static inline void SET_IndexPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_IndexPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexub)(GLubyte);
#define CALL_Indexub(disp, parameters) \
    (* GET_Indexub(disp)) parameters
static inline _glptr_Indexub GET_Indexub(struct _glapi_table *disp) {
   return (_glptr_Indexub) (GET_by_offset(disp, _gloffset_Indexub));
}

static inline void SET_Indexub(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLubyte)) {
   SET_by_offset(disp, _gloffset_Indexub, fn);
}

typedef void (GLAPIENTRYP _glptr_Indexubv)(const GLubyte *);
#define CALL_Indexubv(disp, parameters) \
    (* GET_Indexubv(disp)) parameters
static inline _glptr_Indexubv GET_Indexubv(struct _glapi_table *disp) {
   return (_glptr_Indexubv) (GET_by_offset(disp, _gloffset_Indexubv));
}

static inline void SET_Indexubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLubyte *)) {
   SET_by_offset(disp, _gloffset_Indexubv, fn);
}

typedef void (GLAPIENTRYP _glptr_InterleavedArrays)(GLenum, GLsizei, const GLvoid *);
#define CALL_InterleavedArrays(disp, parameters) \
    (* GET_InterleavedArrays(disp)) parameters
static inline _glptr_InterleavedArrays GET_InterleavedArrays(struct _glapi_table *disp) {
   return (_glptr_InterleavedArrays) (GET_by_offset(disp, _gloffset_InterleavedArrays));
}

static inline void SET_InterleavedArrays(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_InterleavedArrays, fn);
}

typedef void (GLAPIENTRYP _glptr_NormalPointer)(GLenum, GLsizei, const GLvoid *);
#define CALL_NormalPointer(disp, parameters) \
    (* GET_NormalPointer(disp)) parameters
static inline _glptr_NormalPointer GET_NormalPointer(struct _glapi_table *disp) {
   return (_glptr_NormalPointer) (GET_by_offset(disp, _gloffset_NormalPointer));
}

static inline void SET_NormalPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_NormalPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_PolygonOffset)(GLfloat, GLfloat);
#define CALL_PolygonOffset(disp, parameters) \
    (* GET_PolygonOffset(disp)) parameters
static inline _glptr_PolygonOffset GET_PolygonOffset(struct _glapi_table *disp) {
   return (_glptr_PolygonOffset) (GET_by_offset(disp, _gloffset_PolygonOffset));
}

static inline void SET_PolygonOffset(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_PolygonOffset, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_TexCoordPointer(disp, parameters) \
    (* GET_TexCoordPointer(disp)) parameters
static inline _glptr_TexCoordPointer GET_TexCoordPointer(struct _glapi_table *disp) {
   return (_glptr_TexCoordPointer) (GET_by_offset(disp, _gloffset_TexCoordPointer));
}

static inline void SET_TexCoordPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexCoordPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_VertexPointer(disp, parameters) \
    (* GET_VertexPointer(disp)) parameters
static inline _glptr_VertexPointer GET_VertexPointer(struct _glapi_table *disp) {
   return (_glptr_VertexPointer) (GET_by_offset(disp, _gloffset_VertexPointer));
}

static inline void SET_VertexPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VertexPointer, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_AreTexturesResident)(GLsizei, const GLuint *, GLboolean *);
#define CALL_AreTexturesResident(disp, parameters) \
    (* GET_AreTexturesResident(disp)) parameters
static inline _glptr_AreTexturesResident GET_AreTexturesResident(struct _glapi_table *disp) {
   return (_glptr_AreTexturesResident) (GET_by_offset(disp, _gloffset_AreTexturesResident));
}

static inline void SET_AreTexturesResident(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLsizei, const GLuint *, GLboolean *)) {
   SET_by_offset(disp, _gloffset_AreTexturesResident, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTexImage1D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
#define CALL_CopyTexImage1D(disp, parameters) \
    (* GET_CopyTexImage1D(disp)) parameters
static inline _glptr_CopyTexImage1D GET_CopyTexImage1D(struct _glapi_table *disp) {
   return (_glptr_CopyTexImage1D) (GET_by_offset(disp, _gloffset_CopyTexImage1D));
}

static inline void SET_CopyTexImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)) {
   SET_by_offset(disp, _gloffset_CopyTexImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
#define CALL_CopyTexImage2D(disp, parameters) \
    (* GET_CopyTexImage2D(disp)) parameters
static inline _glptr_CopyTexImage2D GET_CopyTexImage2D(struct _glapi_table *disp) {
   return (_glptr_CopyTexImage2D) (GET_by_offset(disp, _gloffset_CopyTexImage2D));
}

static inline void SET_CopyTexImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)) {
   SET_by_offset(disp, _gloffset_CopyTexImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTexSubImage1D)(GLenum, GLint, GLint, GLint, GLint, GLsizei);
#define CALL_CopyTexSubImage1D(disp, parameters) \
    (* GET_CopyTexSubImage1D(disp)) parameters
static inline _glptr_CopyTexSubImage1D GET_CopyTexSubImage1D(struct _glapi_table *disp) {
   return (_glptr_CopyTexSubImage1D) (GET_by_offset(disp, _gloffset_CopyTexSubImage1D));
}

static inline void SET_CopyTexSubImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyTexSubImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define CALL_CopyTexSubImage2D(disp, parameters) \
    (* GET_CopyTexSubImage2D(disp)) parameters
static inline _glptr_CopyTexSubImage2D GET_CopyTexSubImage2D(struct _glapi_table *disp) {
   return (_glptr_CopyTexSubImage2D) (GET_by_offset(disp, _gloffset_CopyTexSubImage2D));
}

static inline void SET_CopyTexSubImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyTexSubImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteTextures)(GLsizei, const GLuint *);
#define CALL_DeleteTextures(disp, parameters) \
    (* GET_DeleteTextures(disp)) parameters
static inline _glptr_DeleteTextures GET_DeleteTextures(struct _glapi_table *disp) {
   return (_glptr_DeleteTextures) (GET_by_offset(disp, _gloffset_DeleteTextures));
}

static inline void SET_DeleteTextures(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteTextures, fn);
}

typedef void (GLAPIENTRYP _glptr_GenTextures)(GLsizei, GLuint *);
#define CALL_GenTextures(disp, parameters) \
    (* GET_GenTextures(disp)) parameters
static inline _glptr_GenTextures GET_GenTextures(struct _glapi_table *disp) {
   return (_glptr_GenTextures) (GET_by_offset(disp, _gloffset_GenTextures));
}

static inline void SET_GenTextures(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenTextures, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPointerv)(GLenum, GLvoid **);
#define CALL_GetPointerv(disp, parameters) \
    (* GET_GetPointerv(disp)) parameters
static inline _glptr_GetPointerv GET_GetPointerv(struct _glapi_table *disp) {
   return (_glptr_GetPointerv) (GET_by_offset(disp, _gloffset_GetPointerv));
}

static inline void SET_GetPointerv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLvoid **)) {
   SET_by_offset(disp, _gloffset_GetPointerv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsTexture)(GLuint);
#define CALL_IsTexture(disp, parameters) \
    (* GET_IsTexture(disp)) parameters
static inline _glptr_IsTexture GET_IsTexture(struct _glapi_table *disp) {
   return (_glptr_IsTexture) (GET_by_offset(disp, _gloffset_IsTexture));
}

static inline void SET_IsTexture(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_PrioritizeTextures)(GLsizei, const GLuint *, const GLclampf *);
#define CALL_PrioritizeTextures(disp, parameters) \
    (* GET_PrioritizeTextures(disp)) parameters
static inline _glptr_PrioritizeTextures GET_PrioritizeTextures(struct _glapi_table *disp) {
   return (_glptr_PrioritizeTextures) (GET_by_offset(disp, _gloffset_PrioritizeTextures));
}

static inline void SET_PrioritizeTextures(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *, const GLclampf *)) {
   SET_by_offset(disp, _gloffset_PrioritizeTextures, fn);
}

typedef void (GLAPIENTRYP _glptr_TexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_TexSubImage1D(disp, parameters) \
    (* GET_TexSubImage1D(disp)) parameters
static inline _glptr_TexSubImage1D GET_TexSubImage1D(struct _glapi_table *disp) {
   return (_glptr_TexSubImage1D) (GET_by_offset(disp, _gloffset_TexSubImage1D));
}

static inline void SET_TexSubImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexSubImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_TexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_TexSubImage2D(disp, parameters) \
    (* GET_TexSubImage2D(disp)) parameters
static inline _glptr_TexSubImage2D GET_TexSubImage2D(struct _glapi_table *disp) {
   return (_glptr_TexSubImage2D) (GET_by_offset(disp, _gloffset_TexSubImage2D));
}

static inline void SET_TexSubImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexSubImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_PopClientAttrib)(void);
#define CALL_PopClientAttrib(disp, parameters) \
    (* GET_PopClientAttrib(disp)) parameters
static inline _glptr_PopClientAttrib GET_PopClientAttrib(struct _glapi_table *disp) {
   return (_glptr_PopClientAttrib) (GET_by_offset(disp, _gloffset_PopClientAttrib));
}

static inline void SET_PopClientAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PopClientAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_PushClientAttrib)(GLbitfield);
#define CALL_PushClientAttrib(disp, parameters) \
    (* GET_PushClientAttrib(disp)) parameters
static inline _glptr_PushClientAttrib GET_PushClientAttrib(struct _glapi_table *disp) {
   return (_glptr_PushClientAttrib) (GET_by_offset(disp, _gloffset_PushClientAttrib));
}

static inline void SET_PushClientAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbitfield)) {
   SET_by_offset(disp, _gloffset_PushClientAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendColor)(GLclampf, GLclampf, GLclampf, GLclampf);
#define CALL_BlendColor(disp, parameters) \
    (* GET_BlendColor(disp)) parameters
static inline _glptr_BlendColor GET_BlendColor(struct _glapi_table *disp) {
   return (_glptr_BlendColor) (GET_by_offset(disp, _gloffset_BlendColor));
}

static inline void SET_BlendColor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampf, GLclampf, GLclampf, GLclampf)) {
   SET_by_offset(disp, _gloffset_BlendColor, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendEquation)(GLenum);
#define CALL_BlendEquation(disp, parameters) \
    (* GET_BlendEquation(disp)) parameters
static inline _glptr_BlendEquation GET_BlendEquation(struct _glapi_table *disp) {
   return (_glptr_BlendEquation) (GET_by_offset(disp, _gloffset_BlendEquation));
}

static inline void SET_BlendEquation(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_BlendEquation, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawRangeElements)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
#define CALL_DrawRangeElements(disp, parameters) \
    (* GET_DrawRangeElements(disp)) parameters
static inline _glptr_DrawRangeElements GET_DrawRangeElements(struct _glapi_table *disp) {
   return (_glptr_DrawRangeElements) (GET_by_offset(disp, _gloffset_DrawRangeElements));
}

static inline void SET_DrawRangeElements(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_DrawRangeElements, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorTable)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_ColorTable(disp, parameters) \
    (* GET_ColorTable(disp)) parameters
static inline _glptr_ColorTable GET_ColorTable(struct _glapi_table *disp) {
   return (_glptr_ColorTable) (GET_by_offset(disp, _gloffset_ColorTable));
}

static inline void SET_ColorTable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ColorTable, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorTableParameterfv)(GLenum, GLenum, const GLfloat *);
#define CALL_ColorTableParameterfv(disp, parameters) \
    (* GET_ColorTableParameterfv(disp)) parameters
static inline _glptr_ColorTableParameterfv GET_ColorTableParameterfv(struct _glapi_table *disp) {
   return (_glptr_ColorTableParameterfv) (GET_by_offset(disp, _gloffset_ColorTableParameterfv));
}

static inline void SET_ColorTableParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ColorTableParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorTableParameteriv)(GLenum, GLenum, const GLint *);
#define CALL_ColorTableParameteriv(disp, parameters) \
    (* GET_ColorTableParameteriv(disp)) parameters
static inline _glptr_ColorTableParameteriv GET_ColorTableParameteriv(struct _glapi_table *disp) {
   return (_glptr_ColorTableParameteriv) (GET_by_offset(disp, _gloffset_ColorTableParameteriv));
}

static inline void SET_ColorTableParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_ColorTableParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyColorTable)(GLenum, GLenum, GLint, GLint, GLsizei);
#define CALL_CopyColorTable(disp, parameters) \
    (* GET_CopyColorTable(disp)) parameters
static inline _glptr_CopyColorTable GET_CopyColorTable(struct _glapi_table *disp) {
   return (_glptr_CopyColorTable) (GET_by_offset(disp, _gloffset_CopyColorTable));
}

static inline void SET_CopyColorTable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint, GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyColorTable, fn);
}

typedef void (GLAPIENTRYP _glptr_GetColorTable)(GLenum, GLenum, GLenum, GLvoid *);
#define CALL_GetColorTable(disp, parameters) \
    (* GET_GetColorTable(disp)) parameters
static inline _glptr_GetColorTable GET_GetColorTable(struct _glapi_table *disp) {
   return (_glptr_GetColorTable) (GET_by_offset(disp, _gloffset_GetColorTable));
}

static inline void SET_GetColorTable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetColorTable, fn);
}

typedef void (GLAPIENTRYP _glptr_GetColorTableParameterfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetColorTableParameterfv(disp, parameters) \
    (* GET_GetColorTableParameterfv(disp)) parameters
static inline _glptr_GetColorTableParameterfv GET_GetColorTableParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetColorTableParameterfv) (GET_by_offset(disp, _gloffset_GetColorTableParameterfv));
}

static inline void SET_GetColorTableParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetColorTableParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetColorTableParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetColorTableParameteriv(disp, parameters) \
    (* GET_GetColorTableParameteriv(disp)) parameters
static inline _glptr_GetColorTableParameteriv GET_GetColorTableParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetColorTableParameteriv) (GET_by_offset(disp, _gloffset_GetColorTableParameteriv));
}

static inline void SET_GetColorTableParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetColorTableParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorSubTable)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_ColorSubTable(disp, parameters) \
    (* GET_ColorSubTable(disp)) parameters
static inline _glptr_ColorSubTable GET_ColorSubTable(struct _glapi_table *disp) {
   return (_glptr_ColorSubTable) (GET_by_offset(disp, _gloffset_ColorSubTable));
}

static inline void SET_ColorSubTable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ColorSubTable, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyColorSubTable)(GLenum, GLsizei, GLint, GLint, GLsizei);
#define CALL_CopyColorSubTable(disp, parameters) \
    (* GET_CopyColorSubTable(disp)) parameters
static inline _glptr_CopyColorSubTable GET_CopyColorSubTable(struct _glapi_table *disp) {
   return (_glptr_CopyColorSubTable) (GET_by_offset(disp, _gloffset_CopyColorSubTable));
}

static inline void SET_CopyColorSubTable(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLint, GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyColorSubTable, fn);
}

typedef void (GLAPIENTRYP _glptr_ConvolutionFilter1D)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_ConvolutionFilter1D(disp, parameters) \
    (* GET_ConvolutionFilter1D(disp)) parameters
static inline _glptr_ConvolutionFilter1D GET_ConvolutionFilter1D(struct _glapi_table *disp) {
   return (_glptr_ConvolutionFilter1D) (GET_by_offset(disp, _gloffset_ConvolutionFilter1D));
}

static inline void SET_ConvolutionFilter1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ConvolutionFilter1D, fn);
}

typedef void (GLAPIENTRYP _glptr_ConvolutionFilter2D)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_ConvolutionFilter2D(disp, parameters) \
    (* GET_ConvolutionFilter2D(disp)) parameters
static inline _glptr_ConvolutionFilter2D GET_ConvolutionFilter2D(struct _glapi_table *disp) {
   return (_glptr_ConvolutionFilter2D) (GET_by_offset(disp, _gloffset_ConvolutionFilter2D));
}

static inline void SET_ConvolutionFilter2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ConvolutionFilter2D, fn);
}

typedef void (GLAPIENTRYP _glptr_ConvolutionParameterf)(GLenum, GLenum, GLfloat);
#define CALL_ConvolutionParameterf(disp, parameters) \
    (* GET_ConvolutionParameterf(disp)) parameters
static inline _glptr_ConvolutionParameterf GET_ConvolutionParameterf(struct _glapi_table *disp) {
   return (_glptr_ConvolutionParameterf) (GET_by_offset(disp, _gloffset_ConvolutionParameterf));
}

static inline void SET_ConvolutionParameterf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_ConvolutionParameterf, fn);
}

typedef void (GLAPIENTRYP _glptr_ConvolutionParameterfv)(GLenum, GLenum, const GLfloat *);
#define CALL_ConvolutionParameterfv(disp, parameters) \
    (* GET_ConvolutionParameterfv(disp)) parameters
static inline _glptr_ConvolutionParameterfv GET_ConvolutionParameterfv(struct _glapi_table *disp) {
   return (_glptr_ConvolutionParameterfv) (GET_by_offset(disp, _gloffset_ConvolutionParameterfv));
}

static inline void SET_ConvolutionParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ConvolutionParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_ConvolutionParameteri)(GLenum, GLenum, GLint);
#define CALL_ConvolutionParameteri(disp, parameters) \
    (* GET_ConvolutionParameteri(disp)) parameters
static inline _glptr_ConvolutionParameteri GET_ConvolutionParameteri(struct _glapi_table *disp) {
   return (_glptr_ConvolutionParameteri) (GET_by_offset(disp, _gloffset_ConvolutionParameteri));
}

static inline void SET_ConvolutionParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_ConvolutionParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_ConvolutionParameteriv)(GLenum, GLenum, const GLint *);
#define CALL_ConvolutionParameteriv(disp, parameters) \
    (* GET_ConvolutionParameteriv(disp)) parameters
static inline _glptr_ConvolutionParameteriv GET_ConvolutionParameteriv(struct _glapi_table *disp) {
   return (_glptr_ConvolutionParameteriv) (GET_by_offset(disp, _gloffset_ConvolutionParameteriv));
}

static inline void SET_ConvolutionParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_ConvolutionParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyConvolutionFilter1D)(GLenum, GLenum, GLint, GLint, GLsizei);
#define CALL_CopyConvolutionFilter1D(disp, parameters) \
    (* GET_CopyConvolutionFilter1D(disp)) parameters
static inline _glptr_CopyConvolutionFilter1D GET_CopyConvolutionFilter1D(struct _glapi_table *disp) {
   return (_glptr_CopyConvolutionFilter1D) (GET_by_offset(disp, _gloffset_CopyConvolutionFilter1D));
}

static inline void SET_CopyConvolutionFilter1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint, GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyConvolutionFilter1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyConvolutionFilter2D)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
#define CALL_CopyConvolutionFilter2D(disp, parameters) \
    (* GET_CopyConvolutionFilter2D(disp)) parameters
static inline _glptr_CopyConvolutionFilter2D GET_CopyConvolutionFilter2D(struct _glapi_table *disp) {
   return (_glptr_CopyConvolutionFilter2D) (GET_by_offset(disp, _gloffset_CopyConvolutionFilter2D));
}

static inline void SET_CopyConvolutionFilter2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyConvolutionFilter2D, fn);
}

typedef void (GLAPIENTRYP _glptr_GetConvolutionFilter)(GLenum, GLenum, GLenum, GLvoid *);
#define CALL_GetConvolutionFilter(disp, parameters) \
    (* GET_GetConvolutionFilter(disp)) parameters
static inline _glptr_GetConvolutionFilter GET_GetConvolutionFilter(struct _glapi_table *disp) {
   return (_glptr_GetConvolutionFilter) (GET_by_offset(disp, _gloffset_GetConvolutionFilter));
}

static inline void SET_GetConvolutionFilter(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetConvolutionFilter, fn);
}

typedef void (GLAPIENTRYP _glptr_GetConvolutionParameterfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetConvolutionParameterfv(disp, parameters) \
    (* GET_GetConvolutionParameterfv(disp)) parameters
static inline _glptr_GetConvolutionParameterfv GET_GetConvolutionParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetConvolutionParameterfv) (GET_by_offset(disp, _gloffset_GetConvolutionParameterfv));
}

static inline void SET_GetConvolutionParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetConvolutionParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetConvolutionParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetConvolutionParameteriv(disp, parameters) \
    (* GET_GetConvolutionParameteriv(disp)) parameters
static inline _glptr_GetConvolutionParameteriv GET_GetConvolutionParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetConvolutionParameteriv) (GET_by_offset(disp, _gloffset_GetConvolutionParameteriv));
}

static inline void SET_GetConvolutionParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetConvolutionParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSeparableFilter)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *);
#define CALL_GetSeparableFilter(disp, parameters) \
    (* GET_GetSeparableFilter(disp)) parameters
static inline _glptr_GetSeparableFilter GET_GetSeparableFilter(struct _glapi_table *disp) {
   return (_glptr_GetSeparableFilter) (GET_by_offset(disp, _gloffset_GetSeparableFilter));
}

static inline void SET_GetSeparableFilter(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetSeparableFilter, fn);
}

typedef void (GLAPIENTRYP _glptr_SeparableFilter2D)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *);
#define CALL_SeparableFilter2D(disp, parameters) \
    (* GET_SeparableFilter2D(disp)) parameters
static inline _glptr_SeparableFilter2D GET_SeparableFilter2D(struct _glapi_table *disp) {
   return (_glptr_SeparableFilter2D) (GET_by_offset(disp, _gloffset_SeparableFilter2D));
}

static inline void SET_SeparableFilter2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_SeparableFilter2D, fn);
}

typedef void (GLAPIENTRYP _glptr_GetHistogram)(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
#define CALL_GetHistogram(disp, parameters) \
    (* GET_GetHistogram(disp)) parameters
static inline _glptr_GetHistogram GET_GetHistogram(struct _glapi_table *disp) {
   return (_glptr_GetHistogram) (GET_by_offset(disp, _gloffset_GetHistogram));
}

static inline void SET_GetHistogram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLboolean, GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetHistogram, fn);
}

typedef void (GLAPIENTRYP _glptr_GetHistogramParameterfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetHistogramParameterfv(disp, parameters) \
    (* GET_GetHistogramParameterfv(disp)) parameters
static inline _glptr_GetHistogramParameterfv GET_GetHistogramParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetHistogramParameterfv) (GET_by_offset(disp, _gloffset_GetHistogramParameterfv));
}

static inline void SET_GetHistogramParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetHistogramParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetHistogramParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetHistogramParameteriv(disp, parameters) \
    (* GET_GetHistogramParameteriv(disp)) parameters
static inline _glptr_GetHistogramParameteriv GET_GetHistogramParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetHistogramParameteriv) (GET_by_offset(disp, _gloffset_GetHistogramParameteriv));
}

static inline void SET_GetHistogramParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetHistogramParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMinmax)(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
#define CALL_GetMinmax(disp, parameters) \
    (* GET_GetMinmax(disp)) parameters
static inline _glptr_GetMinmax GET_GetMinmax(struct _glapi_table *disp) {
   return (_glptr_GetMinmax) (GET_by_offset(disp, _gloffset_GetMinmax));
}

static inline void SET_GetMinmax(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLboolean, GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetMinmax, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMinmaxParameterfv)(GLenum, GLenum, GLfloat *);
#define CALL_GetMinmaxParameterfv(disp, parameters) \
    (* GET_GetMinmaxParameterfv(disp)) parameters
static inline _glptr_GetMinmaxParameterfv GET_GetMinmaxParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetMinmaxParameterfv) (GET_by_offset(disp, _gloffset_GetMinmaxParameterfv));
}

static inline void SET_GetMinmaxParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetMinmaxParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMinmaxParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetMinmaxParameteriv(disp, parameters) \
    (* GET_GetMinmaxParameteriv(disp)) parameters
static inline _glptr_GetMinmaxParameteriv GET_GetMinmaxParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetMinmaxParameteriv) (GET_by_offset(disp, _gloffset_GetMinmaxParameteriv));
}

static inline void SET_GetMinmaxParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetMinmaxParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_Histogram)(GLenum, GLsizei, GLenum, GLboolean);
#define CALL_Histogram(disp, parameters) \
    (* GET_Histogram(disp)) parameters
static inline _glptr_Histogram GET_Histogram(struct _glapi_table *disp) {
   return (_glptr_Histogram) (GET_by_offset(disp, _gloffset_Histogram));
}

static inline void SET_Histogram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLboolean)) {
   SET_by_offset(disp, _gloffset_Histogram, fn);
}

typedef void (GLAPIENTRYP _glptr_Minmax)(GLenum, GLenum, GLboolean);
#define CALL_Minmax(disp, parameters) \
    (* GET_Minmax(disp)) parameters
static inline _glptr_Minmax GET_Minmax(struct _glapi_table *disp) {
   return (_glptr_Minmax) (GET_by_offset(disp, _gloffset_Minmax));
}

static inline void SET_Minmax(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLboolean)) {
   SET_by_offset(disp, _gloffset_Minmax, fn);
}

typedef void (GLAPIENTRYP _glptr_ResetHistogram)(GLenum);
#define CALL_ResetHistogram(disp, parameters) \
    (* GET_ResetHistogram(disp)) parameters
static inline _glptr_ResetHistogram GET_ResetHistogram(struct _glapi_table *disp) {
   return (_glptr_ResetHistogram) (GET_by_offset(disp, _gloffset_ResetHistogram));
}

static inline void SET_ResetHistogram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ResetHistogram, fn);
}

typedef void (GLAPIENTRYP _glptr_ResetMinmax)(GLenum);
#define CALL_ResetMinmax(disp, parameters) \
    (* GET_ResetMinmax(disp)) parameters
static inline _glptr_ResetMinmax GET_ResetMinmax(struct _glapi_table *disp) {
   return (_glptr_ResetMinmax) (GET_by_offset(disp, _gloffset_ResetMinmax));
}

static inline void SET_ResetMinmax(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ResetMinmax, fn);
}

typedef void (GLAPIENTRYP _glptr_TexImage3D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define CALL_TexImage3D(disp, parameters) \
    (* GET_TexImage3D(disp)) parameters
static inline _glptr_TexImage3D GET_TexImage3D(struct _glapi_table *disp) {
   return (_glptr_TexImage3D) (GET_by_offset(disp, _gloffset_TexImage3D));
}

static inline void SET_TexImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_TexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_TexSubImage3D(disp, parameters) \
    (* GET_TexSubImage3D(disp)) parameters
static inline _glptr_TexSubImage3D GET_TexSubImage3D(struct _glapi_table *disp) {
   return (_glptr_TexSubImage3D) (GET_by_offset(disp, _gloffset_TexSubImage3D));
}

static inline void SET_TexSubImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexSubImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define CALL_CopyTexSubImage3D(disp, parameters) \
    (* GET_CopyTexSubImage3D(disp)) parameters
static inline _glptr_CopyTexSubImage3D GET_CopyTexSubImage3D(struct _glapi_table *disp) {
   return (_glptr_CopyTexSubImage3D) (GET_by_offset(disp, _gloffset_CopyTexSubImage3D));
}

static inline void SET_CopyTexSubImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyTexSubImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_ActiveTexture)(GLenum);
#define CALL_ActiveTexture(disp, parameters) \
    (* GET_ActiveTexture(disp)) parameters
static inline _glptr_ActiveTexture GET_ActiveTexture(struct _glapi_table *disp) {
   return (_glptr_ActiveTexture) (GET_by_offset(disp, _gloffset_ActiveTexture));
}

static inline void SET_ActiveTexture(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ActiveTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_ClientActiveTexture)(GLenum);
#define CALL_ClientActiveTexture(disp, parameters) \
    (* GET_ClientActiveTexture(disp)) parameters
static inline _glptr_ClientActiveTexture GET_ClientActiveTexture(struct _glapi_table *disp) {
   return (_glptr_ClientActiveTexture) (GET_by_offset(disp, _gloffset_ClientActiveTexture));
}

static inline void SET_ClientActiveTexture(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ClientActiveTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1d)(GLenum, GLdouble);
#define CALL_MultiTexCoord1d(disp, parameters) \
    (* GET_MultiTexCoord1d(disp)) parameters
static inline _glptr_MultiTexCoord1d GET_MultiTexCoord1d(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1d) (GET_by_offset(disp, _gloffset_MultiTexCoord1d));
}

static inline void SET_MultiTexCoord1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1d, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1dv)(GLenum, const GLdouble *);
#define CALL_MultiTexCoord1dv(disp, parameters) \
    (* GET_MultiTexCoord1dv(disp)) parameters
static inline _glptr_MultiTexCoord1dv GET_MultiTexCoord1dv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1dv) (GET_by_offset(disp, _gloffset_MultiTexCoord1dv));
}

static inline void SET_MultiTexCoord1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1fARB)(GLenum, GLfloat);
#define CALL_MultiTexCoord1fARB(disp, parameters) \
    (* GET_MultiTexCoord1fARB(disp)) parameters
static inline _glptr_MultiTexCoord1fARB GET_MultiTexCoord1fARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1fARB) (GET_by_offset(disp, _gloffset_MultiTexCoord1fARB));
}

static inline void SET_MultiTexCoord1fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1fvARB)(GLenum, const GLfloat *);
#define CALL_MultiTexCoord1fvARB(disp, parameters) \
    (* GET_MultiTexCoord1fvARB(disp)) parameters
static inline _glptr_MultiTexCoord1fvARB GET_MultiTexCoord1fvARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1fvARB) (GET_by_offset(disp, _gloffset_MultiTexCoord1fvARB));
}

static inline void SET_MultiTexCoord1fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1i)(GLenum, GLint);
#define CALL_MultiTexCoord1i(disp, parameters) \
    (* GET_MultiTexCoord1i(disp)) parameters
static inline _glptr_MultiTexCoord1i GET_MultiTexCoord1i(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1i) (GET_by_offset(disp, _gloffset_MultiTexCoord1i));
}

static inline void SET_MultiTexCoord1i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1i, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1iv)(GLenum, const GLint *);
#define CALL_MultiTexCoord1iv(disp, parameters) \
    (* GET_MultiTexCoord1iv(disp)) parameters
static inline _glptr_MultiTexCoord1iv GET_MultiTexCoord1iv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1iv) (GET_by_offset(disp, _gloffset_MultiTexCoord1iv));
}

static inline void SET_MultiTexCoord1iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1iv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1s)(GLenum, GLshort);
#define CALL_MultiTexCoord1s(disp, parameters) \
    (* GET_MultiTexCoord1s(disp)) parameters
static inline _glptr_MultiTexCoord1s GET_MultiTexCoord1s(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1s) (GET_by_offset(disp, _gloffset_MultiTexCoord1s));
}

static inline void SET_MultiTexCoord1s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLshort)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1s, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord1sv)(GLenum, const GLshort *);
#define CALL_MultiTexCoord1sv(disp, parameters) \
    (* GET_MultiTexCoord1sv(disp)) parameters
static inline _glptr_MultiTexCoord1sv GET_MultiTexCoord1sv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord1sv) (GET_by_offset(disp, _gloffset_MultiTexCoord1sv));
}

static inline void SET_MultiTexCoord1sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLshort *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord1sv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2d)(GLenum, GLdouble, GLdouble);
#define CALL_MultiTexCoord2d(disp, parameters) \
    (* GET_MultiTexCoord2d(disp)) parameters
static inline _glptr_MultiTexCoord2d GET_MultiTexCoord2d(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2d) (GET_by_offset(disp, _gloffset_MultiTexCoord2d));
}

static inline void SET_MultiTexCoord2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2d, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2dv)(GLenum, const GLdouble *);
#define CALL_MultiTexCoord2dv(disp, parameters) \
    (* GET_MultiTexCoord2dv(disp)) parameters
static inline _glptr_MultiTexCoord2dv GET_MultiTexCoord2dv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2dv) (GET_by_offset(disp, _gloffset_MultiTexCoord2dv));
}

static inline void SET_MultiTexCoord2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2fARB)(GLenum, GLfloat, GLfloat);
#define CALL_MultiTexCoord2fARB(disp, parameters) \
    (* GET_MultiTexCoord2fARB(disp)) parameters
static inline _glptr_MultiTexCoord2fARB GET_MultiTexCoord2fARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2fARB) (GET_by_offset(disp, _gloffset_MultiTexCoord2fARB));
}

static inline void SET_MultiTexCoord2fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2fvARB)(GLenum, const GLfloat *);
#define CALL_MultiTexCoord2fvARB(disp, parameters) \
    (* GET_MultiTexCoord2fvARB(disp)) parameters
static inline _glptr_MultiTexCoord2fvARB GET_MultiTexCoord2fvARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2fvARB) (GET_by_offset(disp, _gloffset_MultiTexCoord2fvARB));
}

static inline void SET_MultiTexCoord2fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2i)(GLenum, GLint, GLint);
#define CALL_MultiTexCoord2i(disp, parameters) \
    (* GET_MultiTexCoord2i(disp)) parameters
static inline _glptr_MultiTexCoord2i GET_MultiTexCoord2i(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2i) (GET_by_offset(disp, _gloffset_MultiTexCoord2i));
}

static inline void SET_MultiTexCoord2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2i, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2iv)(GLenum, const GLint *);
#define CALL_MultiTexCoord2iv(disp, parameters) \
    (* GET_MultiTexCoord2iv(disp)) parameters
static inline _glptr_MultiTexCoord2iv GET_MultiTexCoord2iv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2iv) (GET_by_offset(disp, _gloffset_MultiTexCoord2iv));
}

static inline void SET_MultiTexCoord2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2s)(GLenum, GLshort, GLshort);
#define CALL_MultiTexCoord2s(disp, parameters) \
    (* GET_MultiTexCoord2s(disp)) parameters
static inline _glptr_MultiTexCoord2s GET_MultiTexCoord2s(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2s) (GET_by_offset(disp, _gloffset_MultiTexCoord2s));
}

static inline void SET_MultiTexCoord2s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2s, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord2sv)(GLenum, const GLshort *);
#define CALL_MultiTexCoord2sv(disp, parameters) \
    (* GET_MultiTexCoord2sv(disp)) parameters
static inline _glptr_MultiTexCoord2sv GET_MultiTexCoord2sv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord2sv) (GET_by_offset(disp, _gloffset_MultiTexCoord2sv));
}

static inline void SET_MultiTexCoord2sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLshort *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord2sv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3d)(GLenum, GLdouble, GLdouble, GLdouble);
#define CALL_MultiTexCoord3d(disp, parameters) \
    (* GET_MultiTexCoord3d(disp)) parameters
static inline _glptr_MultiTexCoord3d GET_MultiTexCoord3d(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3d) (GET_by_offset(disp, _gloffset_MultiTexCoord3d));
}

static inline void SET_MultiTexCoord3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3d, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3dv)(GLenum, const GLdouble *);
#define CALL_MultiTexCoord3dv(disp, parameters) \
    (* GET_MultiTexCoord3dv(disp)) parameters
static inline _glptr_MultiTexCoord3dv GET_MultiTexCoord3dv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3dv) (GET_by_offset(disp, _gloffset_MultiTexCoord3dv));
}

static inline void SET_MultiTexCoord3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3fARB)(GLenum, GLfloat, GLfloat, GLfloat);
#define CALL_MultiTexCoord3fARB(disp, parameters) \
    (* GET_MultiTexCoord3fARB(disp)) parameters
static inline _glptr_MultiTexCoord3fARB GET_MultiTexCoord3fARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3fARB) (GET_by_offset(disp, _gloffset_MultiTexCoord3fARB));
}

static inline void SET_MultiTexCoord3fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3fvARB)(GLenum, const GLfloat *);
#define CALL_MultiTexCoord3fvARB(disp, parameters) \
    (* GET_MultiTexCoord3fvARB(disp)) parameters
static inline _glptr_MultiTexCoord3fvARB GET_MultiTexCoord3fvARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3fvARB) (GET_by_offset(disp, _gloffset_MultiTexCoord3fvARB));
}

static inline void SET_MultiTexCoord3fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3i)(GLenum, GLint, GLint, GLint);
#define CALL_MultiTexCoord3i(disp, parameters) \
    (* GET_MultiTexCoord3i(disp)) parameters
static inline _glptr_MultiTexCoord3i GET_MultiTexCoord3i(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3i) (GET_by_offset(disp, _gloffset_MultiTexCoord3i));
}

static inline void SET_MultiTexCoord3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3i, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3iv)(GLenum, const GLint *);
#define CALL_MultiTexCoord3iv(disp, parameters) \
    (* GET_MultiTexCoord3iv(disp)) parameters
static inline _glptr_MultiTexCoord3iv GET_MultiTexCoord3iv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3iv) (GET_by_offset(disp, _gloffset_MultiTexCoord3iv));
}

static inline void SET_MultiTexCoord3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3s)(GLenum, GLshort, GLshort, GLshort);
#define CALL_MultiTexCoord3s(disp, parameters) \
    (* GET_MultiTexCoord3s(disp)) parameters
static inline _glptr_MultiTexCoord3s GET_MultiTexCoord3s(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3s) (GET_by_offset(disp, _gloffset_MultiTexCoord3s));
}

static inline void SET_MultiTexCoord3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3s, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord3sv)(GLenum, const GLshort *);
#define CALL_MultiTexCoord3sv(disp, parameters) \
    (* GET_MultiTexCoord3sv(disp)) parameters
static inline _glptr_MultiTexCoord3sv GET_MultiTexCoord3sv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord3sv) (GET_by_offset(disp, _gloffset_MultiTexCoord3sv));
}

static inline void SET_MultiTexCoord3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLshort *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4d)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_MultiTexCoord4d(disp, parameters) \
    (* GET_MultiTexCoord4d(disp)) parameters
static inline _glptr_MultiTexCoord4d GET_MultiTexCoord4d(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4d) (GET_by_offset(disp, _gloffset_MultiTexCoord4d));
}

static inline void SET_MultiTexCoord4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4d, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4dv)(GLenum, const GLdouble *);
#define CALL_MultiTexCoord4dv(disp, parameters) \
    (* GET_MultiTexCoord4dv(disp)) parameters
static inline _glptr_MultiTexCoord4dv GET_MultiTexCoord4dv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4dv) (GET_by_offset(disp, _gloffset_MultiTexCoord4dv));
}

static inline void SET_MultiTexCoord4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4fARB)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_MultiTexCoord4fARB(disp, parameters) \
    (* GET_MultiTexCoord4fARB(disp)) parameters
static inline _glptr_MultiTexCoord4fARB GET_MultiTexCoord4fARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4fARB) (GET_by_offset(disp, _gloffset_MultiTexCoord4fARB));
}

static inline void SET_MultiTexCoord4fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4fvARB)(GLenum, const GLfloat *);
#define CALL_MultiTexCoord4fvARB(disp, parameters) \
    (* GET_MultiTexCoord4fvARB(disp)) parameters
static inline _glptr_MultiTexCoord4fvARB GET_MultiTexCoord4fvARB(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4fvARB) (GET_by_offset(disp, _gloffset_MultiTexCoord4fvARB));
}

static inline void SET_MultiTexCoord4fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4i)(GLenum, GLint, GLint, GLint, GLint);
#define CALL_MultiTexCoord4i(disp, parameters) \
    (* GET_MultiTexCoord4i(disp)) parameters
static inline _glptr_MultiTexCoord4i GET_MultiTexCoord4i(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4i) (GET_by_offset(disp, _gloffset_MultiTexCoord4i));
}

static inline void SET_MultiTexCoord4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4i, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4iv)(GLenum, const GLint *);
#define CALL_MultiTexCoord4iv(disp, parameters) \
    (* GET_MultiTexCoord4iv(disp)) parameters
static inline _glptr_MultiTexCoord4iv GET_MultiTexCoord4iv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4iv) (GET_by_offset(disp, _gloffset_MultiTexCoord4iv));
}

static inline void SET_MultiTexCoord4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4s)(GLenum, GLshort, GLshort, GLshort, GLshort);
#define CALL_MultiTexCoord4s(disp, parameters) \
    (* GET_MultiTexCoord4s(disp)) parameters
static inline _glptr_MultiTexCoord4s GET_MultiTexCoord4s(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4s) (GET_by_offset(disp, _gloffset_MultiTexCoord4s));
}

static inline void SET_MultiTexCoord4s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4s, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4sv)(GLenum, const GLshort *);
#define CALL_MultiTexCoord4sv(disp, parameters) \
    (* GET_MultiTexCoord4sv(disp)) parameters
static inline _glptr_MultiTexCoord4sv GET_MultiTexCoord4sv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4sv) (GET_by_offset(disp, _gloffset_MultiTexCoord4sv));
}

static inline void SET_MultiTexCoord4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLshort *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTexImage1D)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
#define CALL_CompressedTexImage1D(disp, parameters) \
    (* GET_CompressedTexImage1D(disp)) parameters
static inline _glptr_CompressedTexImage1D GET_CompressedTexImage1D(struct _glapi_table *disp) {
   return (_glptr_CompressedTexImage1D) (GET_by_offset(disp, _gloffset_CompressedTexImage1D));
}

static inline void SET_CompressedTexImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTexImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define CALL_CompressedTexImage2D(disp, parameters) \
    (* GET_CompressedTexImage2D(disp)) parameters
static inline _glptr_CompressedTexImage2D GET_CompressedTexImage2D(struct _glapi_table *disp) {
   return (_glptr_CompressedTexImage2D) (GET_by_offset(disp, _gloffset_CompressedTexImage2D));
}

static inline void SET_CompressedTexImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTexImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTexImage3D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define CALL_CompressedTexImage3D(disp, parameters) \
    (* GET_CompressedTexImage3D(disp)) parameters
static inline _glptr_CompressedTexImage3D GET_CompressedTexImage3D(struct _glapi_table *disp) {
   return (_glptr_CompressedTexImage3D) (GET_by_offset(disp, _gloffset_CompressedTexImage3D));
}

static inline void SET_CompressedTexImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTexImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
#define CALL_CompressedTexSubImage1D(disp, parameters) \
    (* GET_CompressedTexSubImage1D(disp)) parameters
static inline _glptr_CompressedTexSubImage1D GET_CompressedTexSubImage1D(struct _glapi_table *disp) {
   return (_glptr_CompressedTexSubImage1D) (GET_by_offset(disp, _gloffset_CompressedTexSubImage1D));
}

static inline void SET_CompressedTexSubImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTexSubImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define CALL_CompressedTexSubImage2D(disp, parameters) \
    (* GET_CompressedTexSubImage2D(disp)) parameters
static inline _glptr_CompressedTexSubImage2D GET_CompressedTexSubImage2D(struct _glapi_table *disp) {
   return (_glptr_CompressedTexSubImage2D) (GET_by_offset(disp, _gloffset_CompressedTexSubImage2D));
}

static inline void SET_CompressedTexSubImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTexSubImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define CALL_CompressedTexSubImage3D(disp, parameters) \
    (* GET_CompressedTexSubImage3D(disp)) parameters
static inline _glptr_CompressedTexSubImage3D GET_CompressedTexSubImage3D(struct _glapi_table *disp) {
   return (_glptr_CompressedTexSubImage3D) (GET_by_offset(disp, _gloffset_CompressedTexSubImage3D));
}

static inline void SET_CompressedTexSubImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTexSubImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_GetCompressedTexImage)(GLenum, GLint, GLvoid *);
#define CALL_GetCompressedTexImage(disp, parameters) \
    (* GET_GetCompressedTexImage(disp)) parameters
static inline _glptr_GetCompressedTexImage GET_GetCompressedTexImage(struct _glapi_table *disp) {
   return (_glptr_GetCompressedTexImage) (GET_by_offset(disp, _gloffset_GetCompressedTexImage));
}

static inline void SET_GetCompressedTexImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetCompressedTexImage, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadTransposeMatrixd)(const GLdouble *);
#define CALL_LoadTransposeMatrixd(disp, parameters) \
    (* GET_LoadTransposeMatrixd(disp)) parameters
static inline _glptr_LoadTransposeMatrixd GET_LoadTransposeMatrixd(struct _glapi_table *disp) {
   return (_glptr_LoadTransposeMatrixd) (GET_by_offset(disp, _gloffset_LoadTransposeMatrixd));
}

static inline void SET_LoadTransposeMatrixd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_LoadTransposeMatrixd, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadTransposeMatrixf)(const GLfloat *);
#define CALL_LoadTransposeMatrixf(disp, parameters) \
    (* GET_LoadTransposeMatrixf(disp)) parameters
static inline _glptr_LoadTransposeMatrixf GET_LoadTransposeMatrixf(struct _glapi_table *disp) {
   return (_glptr_LoadTransposeMatrixf) (GET_by_offset(disp, _gloffset_LoadTransposeMatrixf));
}

static inline void SET_LoadTransposeMatrixf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_LoadTransposeMatrixf, fn);
}

typedef void (GLAPIENTRYP _glptr_MultTransposeMatrixd)(const GLdouble *);
#define CALL_MultTransposeMatrixd(disp, parameters) \
    (* GET_MultTransposeMatrixd(disp)) parameters
static inline _glptr_MultTransposeMatrixd GET_MultTransposeMatrixd(struct _glapi_table *disp) {
   return (_glptr_MultTransposeMatrixd) (GET_by_offset(disp, _gloffset_MultTransposeMatrixd));
}

static inline void SET_MultTransposeMatrixd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_MultTransposeMatrixd, fn);
}

typedef void (GLAPIENTRYP _glptr_MultTransposeMatrixf)(const GLfloat *);
#define CALL_MultTransposeMatrixf(disp, parameters) \
    (* GET_MultTransposeMatrixf(disp)) parameters
static inline _glptr_MultTransposeMatrixf GET_MultTransposeMatrixf(struct _glapi_table *disp) {
   return (_glptr_MultTransposeMatrixf) (GET_by_offset(disp, _gloffset_MultTransposeMatrixf));
}

static inline void SET_MultTransposeMatrixf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_MultTransposeMatrixf, fn);
}

typedef void (GLAPIENTRYP _glptr_SampleCoverage)(GLclampf, GLboolean);
#define CALL_SampleCoverage(disp, parameters) \
    (* GET_SampleCoverage(disp)) parameters
static inline _glptr_SampleCoverage GET_SampleCoverage(struct _glapi_table *disp) {
   return (_glptr_SampleCoverage) (GET_by_offset(disp, _gloffset_SampleCoverage));
}

static inline void SET_SampleCoverage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampf, GLboolean)) {
   SET_by_offset(disp, _gloffset_SampleCoverage, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum);
#define CALL_BlendFuncSeparate(disp, parameters) \
    (* GET_BlendFuncSeparate(disp)) parameters
static inline _glptr_BlendFuncSeparate GET_BlendFuncSeparate(struct _glapi_table *disp) {
   return (_glptr_BlendFuncSeparate) (GET_by_offset(disp, _gloffset_BlendFuncSeparate));
}

static inline void SET_BlendFuncSeparate(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendFuncSeparate, fn);
}

typedef void (GLAPIENTRYP _glptr_FogCoordPointer)(GLenum, GLsizei, const GLvoid *);
#define CALL_FogCoordPointer(disp, parameters) \
    (* GET_FogCoordPointer(disp)) parameters
static inline _glptr_FogCoordPointer GET_FogCoordPointer(struct _glapi_table *disp) {
   return (_glptr_FogCoordPointer) (GET_by_offset(disp, _gloffset_FogCoordPointer));
}

static inline void SET_FogCoordPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_FogCoordPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_FogCoordd)(GLdouble);
#define CALL_FogCoordd(disp, parameters) \
    (* GET_FogCoordd(disp)) parameters
static inline _glptr_FogCoordd GET_FogCoordd(struct _glapi_table *disp) {
   return (_glptr_FogCoordd) (GET_by_offset(disp, _gloffset_FogCoordd));
}

static inline void SET_FogCoordd(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble)) {
   SET_by_offset(disp, _gloffset_FogCoordd, fn);
}

typedef void (GLAPIENTRYP _glptr_FogCoorddv)(const GLdouble *);
#define CALL_FogCoorddv(disp, parameters) \
    (* GET_FogCoorddv(disp)) parameters
static inline _glptr_FogCoorddv GET_FogCoorddv(struct _glapi_table *disp) {
   return (_glptr_FogCoorddv) (GET_by_offset(disp, _gloffset_FogCoorddv));
}

static inline void SET_FogCoorddv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_FogCoorddv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawArrays)(GLenum, const GLint *, const GLsizei *, GLsizei);
#define CALL_MultiDrawArrays(disp, parameters) \
    (* GET_MultiDrawArrays(disp)) parameters
static inline _glptr_MultiDrawArrays GET_MultiDrawArrays(struct _glapi_table *disp) {
   return (_glptr_MultiDrawArrays) (GET_by_offset(disp, _gloffset_MultiDrawArrays));
}

static inline void SET_MultiDrawArrays(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *, const GLsizei *, GLsizei)) {
   SET_by_offset(disp, _gloffset_MultiDrawArrays, fn);
}

typedef void (GLAPIENTRYP _glptr_PointParameterf)(GLenum, GLfloat);
#define CALL_PointParameterf(disp, parameters) \
    (* GET_PointParameterf(disp)) parameters
static inline _glptr_PointParameterf GET_PointParameterf(struct _glapi_table *disp) {
   return (_glptr_PointParameterf) (GET_by_offset(disp, _gloffset_PointParameterf));
}

static inline void SET_PointParameterf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_PointParameterf, fn);
}

typedef void (GLAPIENTRYP _glptr_PointParameterfv)(GLenum, const GLfloat *);
#define CALL_PointParameterfv(disp, parameters) \
    (* GET_PointParameterfv(disp)) parameters
static inline _glptr_PointParameterfv GET_PointParameterfv(struct _glapi_table *disp) {
   return (_glptr_PointParameterfv) (GET_by_offset(disp, _gloffset_PointParameterfv));
}

static inline void SET_PointParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_PointParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_PointParameteri)(GLenum, GLint);
#define CALL_PointParameteri(disp, parameters) \
    (* GET_PointParameteri(disp)) parameters
static inline _glptr_PointParameteri GET_PointParameteri(struct _glapi_table *disp) {
   return (_glptr_PointParameteri) (GET_by_offset(disp, _gloffset_PointParameteri));
}

static inline void SET_PointParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_PointParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_PointParameteriv)(GLenum, const GLint *);
#define CALL_PointParameteriv(disp, parameters) \
    (* GET_PointParameteriv(disp)) parameters
static inline _glptr_PointParameteriv GET_PointParameteriv(struct _glapi_table *disp) {
   return (_glptr_PointParameteriv) (GET_by_offset(disp, _gloffset_PointParameteriv));
}

static inline void SET_PointParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_PointParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3b)(GLbyte, GLbyte, GLbyte);
#define CALL_SecondaryColor3b(disp, parameters) \
    (* GET_SecondaryColor3b(disp)) parameters
static inline _glptr_SecondaryColor3b GET_SecondaryColor3b(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3b) (GET_by_offset(disp, _gloffset_SecondaryColor3b));
}

static inline void SET_SecondaryColor3b(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbyte, GLbyte, GLbyte)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3b, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3bv)(const GLbyte *);
#define CALL_SecondaryColor3bv(disp, parameters) \
    (* GET_SecondaryColor3bv(disp)) parameters
static inline _glptr_SecondaryColor3bv GET_SecondaryColor3bv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3bv) (GET_by_offset(disp, _gloffset_SecondaryColor3bv));
}

static inline void SET_SecondaryColor3bv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLbyte *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3bv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3d)(GLdouble, GLdouble, GLdouble);
#define CALL_SecondaryColor3d(disp, parameters) \
    (* GET_SecondaryColor3d(disp)) parameters
static inline _glptr_SecondaryColor3d GET_SecondaryColor3d(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3d) (GET_by_offset(disp, _gloffset_SecondaryColor3d));
}

static inline void SET_SecondaryColor3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3d, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3dv)(const GLdouble *);
#define CALL_SecondaryColor3dv(disp, parameters) \
    (* GET_SecondaryColor3dv(disp)) parameters
static inline _glptr_SecondaryColor3dv GET_SecondaryColor3dv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3dv) (GET_by_offset(disp, _gloffset_SecondaryColor3dv));
}

static inline void SET_SecondaryColor3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3i)(GLint, GLint, GLint);
#define CALL_SecondaryColor3i(disp, parameters) \
    (* GET_SecondaryColor3i(disp)) parameters
static inline _glptr_SecondaryColor3i GET_SecondaryColor3i(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3i) (GET_by_offset(disp, _gloffset_SecondaryColor3i));
}

static inline void SET_SecondaryColor3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3i, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3iv)(const GLint *);
#define CALL_SecondaryColor3iv(disp, parameters) \
    (* GET_SecondaryColor3iv(disp)) parameters
static inline _glptr_SecondaryColor3iv GET_SecondaryColor3iv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3iv) (GET_by_offset(disp, _gloffset_SecondaryColor3iv));
}

static inline void SET_SecondaryColor3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3s)(GLshort, GLshort, GLshort);
#define CALL_SecondaryColor3s(disp, parameters) \
    (* GET_SecondaryColor3s(disp)) parameters
static inline _glptr_SecondaryColor3s GET_SecondaryColor3s(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3s) (GET_by_offset(disp, _gloffset_SecondaryColor3s));
}

static inline void SET_SecondaryColor3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3s, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3sv)(const GLshort *);
#define CALL_SecondaryColor3sv(disp, parameters) \
    (* GET_SecondaryColor3sv(disp)) parameters
static inline _glptr_SecondaryColor3sv GET_SecondaryColor3sv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3sv) (GET_by_offset(disp, _gloffset_SecondaryColor3sv));
}

static inline void SET_SecondaryColor3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3ub)(GLubyte, GLubyte, GLubyte);
#define CALL_SecondaryColor3ub(disp, parameters) \
    (* GET_SecondaryColor3ub(disp)) parameters
static inline _glptr_SecondaryColor3ub GET_SecondaryColor3ub(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3ub) (GET_by_offset(disp, _gloffset_SecondaryColor3ub));
}

static inline void SET_SecondaryColor3ub(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLubyte, GLubyte, GLubyte)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3ub, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3ubv)(const GLubyte *);
#define CALL_SecondaryColor3ubv(disp, parameters) \
    (* GET_SecondaryColor3ubv(disp)) parameters
static inline _glptr_SecondaryColor3ubv GET_SecondaryColor3ubv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3ubv) (GET_by_offset(disp, _gloffset_SecondaryColor3ubv));
}

static inline void SET_SecondaryColor3ubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLubyte *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3ubv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3ui)(GLuint, GLuint, GLuint);
#define CALL_SecondaryColor3ui(disp, parameters) \
    (* GET_SecondaryColor3ui(disp)) parameters
static inline _glptr_SecondaryColor3ui GET_SecondaryColor3ui(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3ui) (GET_by_offset(disp, _gloffset_SecondaryColor3ui));
}

static inline void SET_SecondaryColor3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3uiv)(const GLuint *);
#define CALL_SecondaryColor3uiv(disp, parameters) \
    (* GET_SecondaryColor3uiv(disp)) parameters
static inline _glptr_SecondaryColor3uiv GET_SecondaryColor3uiv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3uiv) (GET_by_offset(disp, _gloffset_SecondaryColor3uiv));
}

static inline void SET_SecondaryColor3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLuint *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3us)(GLushort, GLushort, GLushort);
#define CALL_SecondaryColor3us(disp, parameters) \
    (* GET_SecondaryColor3us(disp)) parameters
static inline _glptr_SecondaryColor3us GET_SecondaryColor3us(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3us) (GET_by_offset(disp, _gloffset_SecondaryColor3us));
}

static inline void SET_SecondaryColor3us(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLushort, GLushort, GLushort)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3us, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3usv)(const GLushort *);
#define CALL_SecondaryColor3usv(disp, parameters) \
    (* GET_SecondaryColor3usv(disp)) parameters
static inline _glptr_SecondaryColor3usv GET_SecondaryColor3usv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3usv) (GET_by_offset(disp, _gloffset_SecondaryColor3usv));
}

static inline void SET_SecondaryColor3usv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLushort *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3usv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColorPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_SecondaryColorPointer(disp, parameters) \
    (* GET_SecondaryColorPointer(disp)) parameters
static inline _glptr_SecondaryColorPointer GET_SecondaryColorPointer(struct _glapi_table *disp) {
   return (_glptr_SecondaryColorPointer) (GET_by_offset(disp, _gloffset_SecondaryColorPointer));
}

static inline void SET_SecondaryColorPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_SecondaryColorPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2d)(GLdouble, GLdouble);
#define CALL_WindowPos2d(disp, parameters) \
    (* GET_WindowPos2d(disp)) parameters
static inline _glptr_WindowPos2d GET_WindowPos2d(struct _glapi_table *disp) {
   return (_glptr_WindowPos2d) (GET_by_offset(disp, _gloffset_WindowPos2d));
}

static inline void SET_WindowPos2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_WindowPos2d, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2dv)(const GLdouble *);
#define CALL_WindowPos2dv(disp, parameters) \
    (* GET_WindowPos2dv(disp)) parameters
static inline _glptr_WindowPos2dv GET_WindowPos2dv(struct _glapi_table *disp) {
   return (_glptr_WindowPos2dv) (GET_by_offset(disp, _gloffset_WindowPos2dv));
}

static inline void SET_WindowPos2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_WindowPos2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2f)(GLfloat, GLfloat);
#define CALL_WindowPos2f(disp, parameters) \
    (* GET_WindowPos2f(disp)) parameters
static inline _glptr_WindowPos2f GET_WindowPos2f(struct _glapi_table *disp) {
   return (_glptr_WindowPos2f) (GET_by_offset(disp, _gloffset_WindowPos2f));
}

static inline void SET_WindowPos2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_WindowPos2f, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2fv)(const GLfloat *);
#define CALL_WindowPos2fv(disp, parameters) \
    (* GET_WindowPos2fv(disp)) parameters
static inline _glptr_WindowPos2fv GET_WindowPos2fv(struct _glapi_table *disp) {
   return (_glptr_WindowPos2fv) (GET_by_offset(disp, _gloffset_WindowPos2fv));
}

static inline void SET_WindowPos2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_WindowPos2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2i)(GLint, GLint);
#define CALL_WindowPos2i(disp, parameters) \
    (* GET_WindowPos2i(disp)) parameters
static inline _glptr_WindowPos2i GET_WindowPos2i(struct _glapi_table *disp) {
   return (_glptr_WindowPos2i) (GET_by_offset(disp, _gloffset_WindowPos2i));
}

static inline void SET_WindowPos2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint)) {
   SET_by_offset(disp, _gloffset_WindowPos2i, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2iv)(const GLint *);
#define CALL_WindowPos2iv(disp, parameters) \
    (* GET_WindowPos2iv(disp)) parameters
static inline _glptr_WindowPos2iv GET_WindowPos2iv(struct _glapi_table *disp) {
   return (_glptr_WindowPos2iv) (GET_by_offset(disp, _gloffset_WindowPos2iv));
}

static inline void SET_WindowPos2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_WindowPos2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2s)(GLshort, GLshort);
#define CALL_WindowPos2s(disp, parameters) \
    (* GET_WindowPos2s(disp)) parameters
static inline _glptr_WindowPos2s GET_WindowPos2s(struct _glapi_table *disp) {
   return (_glptr_WindowPos2s) (GET_by_offset(disp, _gloffset_WindowPos2s));
}

static inline void SET_WindowPos2s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_WindowPos2s, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos2sv)(const GLshort *);
#define CALL_WindowPos2sv(disp, parameters) \
    (* GET_WindowPos2sv(disp)) parameters
static inline _glptr_WindowPos2sv GET_WindowPos2sv(struct _glapi_table *disp) {
   return (_glptr_WindowPos2sv) (GET_by_offset(disp, _gloffset_WindowPos2sv));
}

static inline void SET_WindowPos2sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_WindowPos2sv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3d)(GLdouble, GLdouble, GLdouble);
#define CALL_WindowPos3d(disp, parameters) \
    (* GET_WindowPos3d(disp)) parameters
static inline _glptr_WindowPos3d GET_WindowPos3d(struct _glapi_table *disp) {
   return (_glptr_WindowPos3d) (GET_by_offset(disp, _gloffset_WindowPos3d));
}

static inline void SET_WindowPos3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_WindowPos3d, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3dv)(const GLdouble *);
#define CALL_WindowPos3dv(disp, parameters) \
    (* GET_WindowPos3dv(disp)) parameters
static inline _glptr_WindowPos3dv GET_WindowPos3dv(struct _glapi_table *disp) {
   return (_glptr_WindowPos3dv) (GET_by_offset(disp, _gloffset_WindowPos3dv));
}

static inline void SET_WindowPos3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_WindowPos3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3f)(GLfloat, GLfloat, GLfloat);
#define CALL_WindowPos3f(disp, parameters) \
    (* GET_WindowPos3f(disp)) parameters
static inline _glptr_WindowPos3f GET_WindowPos3f(struct _glapi_table *disp) {
   return (_glptr_WindowPos3f) (GET_by_offset(disp, _gloffset_WindowPos3f));
}

static inline void SET_WindowPos3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_WindowPos3f, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3fv)(const GLfloat *);
#define CALL_WindowPos3fv(disp, parameters) \
    (* GET_WindowPos3fv(disp)) parameters
static inline _glptr_WindowPos3fv GET_WindowPos3fv(struct _glapi_table *disp) {
   return (_glptr_WindowPos3fv) (GET_by_offset(disp, _gloffset_WindowPos3fv));
}

static inline void SET_WindowPos3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_WindowPos3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3i)(GLint, GLint, GLint);
#define CALL_WindowPos3i(disp, parameters) \
    (* GET_WindowPos3i(disp)) parameters
static inline _glptr_WindowPos3i GET_WindowPos3i(struct _glapi_table *disp) {
   return (_glptr_WindowPos3i) (GET_by_offset(disp, _gloffset_WindowPos3i));
}

static inline void SET_WindowPos3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_WindowPos3i, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3iv)(const GLint *);
#define CALL_WindowPos3iv(disp, parameters) \
    (* GET_WindowPos3iv(disp)) parameters
static inline _glptr_WindowPos3iv GET_WindowPos3iv(struct _glapi_table *disp) {
   return (_glptr_WindowPos3iv) (GET_by_offset(disp, _gloffset_WindowPos3iv));
}

static inline void SET_WindowPos3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_WindowPos3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3s)(GLshort, GLshort, GLshort);
#define CALL_WindowPos3s(disp, parameters) \
    (* GET_WindowPos3s(disp)) parameters
static inline _glptr_WindowPos3s GET_WindowPos3s(struct _glapi_table *disp) {
   return (_glptr_WindowPos3s) (GET_by_offset(disp, _gloffset_WindowPos3s));
}

static inline void SET_WindowPos3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_WindowPos3s, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos3sv)(const GLshort *);
#define CALL_WindowPos3sv(disp, parameters) \
    (* GET_WindowPos3sv(disp)) parameters
static inline _glptr_WindowPos3sv GET_WindowPos3sv(struct _glapi_table *disp) {
   return (_glptr_WindowPos3sv) (GET_by_offset(disp, _gloffset_WindowPos3sv));
}

static inline void SET_WindowPos3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_WindowPos3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginQuery)(GLenum, GLuint);
#define CALL_BeginQuery(disp, parameters) \
    (* GET_BeginQuery(disp)) parameters
static inline _glptr_BeginQuery GET_BeginQuery(struct _glapi_table *disp) {
   return (_glptr_BeginQuery) (GET_by_offset(disp, _gloffset_BeginQuery));
}

static inline void SET_BeginQuery(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BeginQuery, fn);
}

typedef void (GLAPIENTRYP _glptr_BindBuffer)(GLenum, GLuint);
#define CALL_BindBuffer(disp, parameters) \
    (* GET_BindBuffer(disp)) parameters
static inline _glptr_BindBuffer GET_BindBuffer(struct _glapi_table *disp) {
   return (_glptr_BindBuffer) (GET_by_offset(disp, _gloffset_BindBuffer));
}

static inline void SET_BindBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_BufferData)(GLenum, GLsizeiptr, const GLvoid *, GLenum);
#define CALL_BufferData(disp, parameters) \
    (* GET_BufferData(disp)) parameters
static inline _glptr_BufferData GET_BufferData(struct _glapi_table *disp) {
   return (_glptr_BufferData) (GET_by_offset(disp, _gloffset_BufferData));
}

static inline void SET_BufferData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizeiptr, const GLvoid *, GLenum)) {
   SET_by_offset(disp, _gloffset_BufferData, fn);
}

typedef void (GLAPIENTRYP _glptr_BufferSubData)(GLenum, GLintptr, GLsizeiptr, const GLvoid *);
#define CALL_BufferSubData(disp, parameters) \
    (* GET_BufferSubData(disp)) parameters
static inline _glptr_BufferSubData GET_BufferSubData(struct _glapi_table *disp) {
   return (_glptr_BufferSubData) (GET_by_offset(disp, _gloffset_BufferSubData));
}

static inline void SET_BufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLintptr, GLsizeiptr, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_BufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteBuffers)(GLsizei, const GLuint *);
#define CALL_DeleteBuffers(disp, parameters) \
    (* GET_DeleteBuffers(disp)) parameters
static inline _glptr_DeleteBuffers GET_DeleteBuffers(struct _glapi_table *disp) {
   return (_glptr_DeleteBuffers) (GET_by_offset(disp, _gloffset_DeleteBuffers));
}

static inline void SET_DeleteBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteBuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteQueries)(GLsizei, const GLuint *);
#define CALL_DeleteQueries(disp, parameters) \
    (* GET_DeleteQueries(disp)) parameters
static inline _glptr_DeleteQueries GET_DeleteQueries(struct _glapi_table *disp) {
   return (_glptr_DeleteQueries) (GET_by_offset(disp, _gloffset_DeleteQueries));
}

static inline void SET_DeleteQueries(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteQueries, fn);
}

typedef void (GLAPIENTRYP _glptr_EndQuery)(GLenum);
#define CALL_EndQuery(disp, parameters) \
    (* GET_EndQuery(disp)) parameters
static inline _glptr_EndQuery GET_EndQuery(struct _glapi_table *disp) {
   return (_glptr_EndQuery) (GET_by_offset(disp, _gloffset_EndQuery));
}

static inline void SET_EndQuery(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_EndQuery, fn);
}

typedef void (GLAPIENTRYP _glptr_GenBuffers)(GLsizei, GLuint *);
#define CALL_GenBuffers(disp, parameters) \
    (* GET_GenBuffers(disp)) parameters
static inline _glptr_GenBuffers GET_GenBuffers(struct _glapi_table *disp) {
   return (_glptr_GenBuffers) (GET_by_offset(disp, _gloffset_GenBuffers));
}

static inline void SET_GenBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenBuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_GenQueries)(GLsizei, GLuint *);
#define CALL_GenQueries(disp, parameters) \
    (* GET_GenQueries(disp)) parameters
static inline _glptr_GenQueries GET_GenQueries(struct _glapi_table *disp) {
   return (_glptr_GenQueries) (GET_by_offset(disp, _gloffset_GenQueries));
}

static inline void SET_GenQueries(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenQueries, fn);
}

typedef void (GLAPIENTRYP _glptr_GetBufferParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetBufferParameteriv(disp, parameters) \
    (* GET_GetBufferParameteriv(disp)) parameters
static inline _glptr_GetBufferParameteriv GET_GetBufferParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetBufferParameteriv) (GET_by_offset(disp, _gloffset_GetBufferParameteriv));
}

static inline void SET_GetBufferParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetBufferParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetBufferPointerv)(GLenum, GLenum, GLvoid **);
#define CALL_GetBufferPointerv(disp, parameters) \
    (* GET_GetBufferPointerv(disp)) parameters
static inline _glptr_GetBufferPointerv GET_GetBufferPointerv(struct _glapi_table *disp) {
   return (_glptr_GetBufferPointerv) (GET_by_offset(disp, _gloffset_GetBufferPointerv));
}

static inline void SET_GetBufferPointerv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLvoid **)) {
   SET_by_offset(disp, _gloffset_GetBufferPointerv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetBufferSubData)(GLenum, GLintptr, GLsizeiptr, GLvoid *);
#define CALL_GetBufferSubData(disp, parameters) \
    (* GET_GetBufferSubData(disp)) parameters
static inline _glptr_GetBufferSubData GET_GetBufferSubData(struct _glapi_table *disp) {
   return (_glptr_GetBufferSubData) (GET_by_offset(disp, _gloffset_GetBufferSubData));
}

static inline void SET_GetBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLintptr, GLsizeiptr, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryObjectiv)(GLuint, GLenum, GLint *);
#define CALL_GetQueryObjectiv(disp, parameters) \
    (* GET_GetQueryObjectiv(disp)) parameters
static inline _glptr_GetQueryObjectiv GET_GetQueryObjectiv(struct _glapi_table *disp) {
   return (_glptr_GetQueryObjectiv) (GET_by_offset(disp, _gloffset_GetQueryObjectiv));
}

static inline void SET_GetQueryObjectiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetQueryObjectiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryObjectuiv)(GLuint, GLenum, GLuint *);
#define CALL_GetQueryObjectuiv(disp, parameters) \
    (* GET_GetQueryObjectuiv(disp)) parameters
static inline _glptr_GetQueryObjectuiv GET_GetQueryObjectuiv(struct _glapi_table *disp) {
   return (_glptr_GetQueryObjectuiv) (GET_by_offset(disp, _gloffset_GetQueryObjectuiv));
}

static inline void SET_GetQueryObjectuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetQueryObjectuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryiv)(GLenum, GLenum, GLint *);
#define CALL_GetQueryiv(disp, parameters) \
    (* GET_GetQueryiv(disp)) parameters
static inline _glptr_GetQueryiv GET_GetQueryiv(struct _glapi_table *disp) {
   return (_glptr_GetQueryiv) (GET_by_offset(disp, _gloffset_GetQueryiv));
}

static inline void SET_GetQueryiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetQueryiv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsBuffer)(GLuint);
#define CALL_IsBuffer(disp, parameters) \
    (* GET_IsBuffer(disp)) parameters
static inline _glptr_IsBuffer GET_IsBuffer(struct _glapi_table *disp) {
   return (_glptr_IsBuffer) (GET_by_offset(disp, _gloffset_IsBuffer));
}

static inline void SET_IsBuffer(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsBuffer, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsQuery)(GLuint);
#define CALL_IsQuery(disp, parameters) \
    (* GET_IsQuery(disp)) parameters
static inline _glptr_IsQuery GET_IsQuery(struct _glapi_table *disp) {
   return (_glptr_IsQuery) (GET_by_offset(disp, _gloffset_IsQuery));
}

static inline void SET_IsQuery(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsQuery, fn);
}

typedef GLvoid * (GLAPIENTRYP _glptr_MapBuffer)(GLenum, GLenum);
#define CALL_MapBuffer(disp, parameters) \
    (* GET_MapBuffer(disp)) parameters
static inline _glptr_MapBuffer GET_MapBuffer(struct _glapi_table *disp) {
   return (_glptr_MapBuffer) (GET_by_offset(disp, _gloffset_MapBuffer));
}

static inline void SET_MapBuffer(struct _glapi_table *disp, GLvoid * (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_MapBuffer, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_UnmapBuffer)(GLenum);
#define CALL_UnmapBuffer(disp, parameters) \
    (* GET_UnmapBuffer(disp)) parameters
static inline _glptr_UnmapBuffer GET_UnmapBuffer(struct _glapi_table *disp) {
   return (_glptr_UnmapBuffer) (GET_by_offset(disp, _gloffset_UnmapBuffer));
}

static inline void SET_UnmapBuffer(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_UnmapBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_AttachShader)(GLuint, GLuint);
#define CALL_AttachShader(disp, parameters) \
    (* GET_AttachShader(disp)) parameters
static inline _glptr_AttachShader GET_AttachShader(struct _glapi_table *disp) {
   return (_glptr_AttachShader) (GET_by_offset(disp, _gloffset_AttachShader));
}

static inline void SET_AttachShader(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_AttachShader, fn);
}

typedef void (GLAPIENTRYP _glptr_BindAttribLocation)(GLuint, GLuint, const GLchar *);
#define CALL_BindAttribLocation(disp, parameters) \
    (* GET_BindAttribLocation(disp)) parameters
static inline _glptr_BindAttribLocation GET_BindAttribLocation(struct _glapi_table *disp) {
   return (_glptr_BindAttribLocation) (GET_by_offset(disp, _gloffset_BindAttribLocation));
}

static inline void SET_BindAttribLocation(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_BindAttribLocation, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendEquationSeparate)(GLenum, GLenum);
#define CALL_BlendEquationSeparate(disp, parameters) \
    (* GET_BlendEquationSeparate(disp)) parameters
static inline _glptr_BlendEquationSeparate GET_BlendEquationSeparate(struct _glapi_table *disp) {
   return (_glptr_BlendEquationSeparate) (GET_by_offset(disp, _gloffset_BlendEquationSeparate));
}

static inline void SET_BlendEquationSeparate(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendEquationSeparate, fn);
}

typedef void (GLAPIENTRYP _glptr_CompileShader)(GLuint);
#define CALL_CompileShader(disp, parameters) \
    (* GET_CompileShader(disp)) parameters
static inline _glptr_CompileShader GET_CompileShader(struct _glapi_table *disp) {
   return (_glptr_CompileShader) (GET_by_offset(disp, _gloffset_CompileShader));
}

static inline void SET_CompileShader(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_CompileShader, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_CreateProgram)(void);
#define CALL_CreateProgram(disp, parameters) \
    (* GET_CreateProgram(disp)) parameters
static inline _glptr_CreateProgram GET_CreateProgram(struct _glapi_table *disp) {
   return (_glptr_CreateProgram) (GET_by_offset(disp, _gloffset_CreateProgram));
}

static inline void SET_CreateProgram(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_CreateProgram, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_CreateShader)(GLenum);
#define CALL_CreateShader(disp, parameters) \
    (* GET_CreateShader(disp)) parameters
static inline _glptr_CreateShader GET_CreateShader(struct _glapi_table *disp) {
   return (_glptr_CreateShader) (GET_by_offset(disp, _gloffset_CreateShader));
}

static inline void SET_CreateShader(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_CreateShader, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteProgram)(GLuint);
#define CALL_DeleteProgram(disp, parameters) \
    (* GET_DeleteProgram(disp)) parameters
static inline _glptr_DeleteProgram GET_DeleteProgram(struct _glapi_table *disp) {
   return (_glptr_DeleteProgram) (GET_by_offset(disp, _gloffset_DeleteProgram));
}

static inline void SET_DeleteProgram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_DeleteProgram, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteShader)(GLuint);
#define CALL_DeleteShader(disp, parameters) \
    (* GET_DeleteShader(disp)) parameters
static inline _glptr_DeleteShader GET_DeleteShader(struct _glapi_table *disp) {
   return (_glptr_DeleteShader) (GET_by_offset(disp, _gloffset_DeleteShader));
}

static inline void SET_DeleteShader(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_DeleteShader, fn);
}

typedef void (GLAPIENTRYP _glptr_DetachShader)(GLuint, GLuint);
#define CALL_DetachShader(disp, parameters) \
    (* GET_DetachShader(disp)) parameters
static inline _glptr_DetachShader GET_DetachShader(struct _glapi_table *disp) {
   return (_glptr_DetachShader) (GET_by_offset(disp, _gloffset_DetachShader));
}

static inline void SET_DetachShader(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_DetachShader, fn);
}

typedef void (GLAPIENTRYP _glptr_DisableVertexAttribArray)(GLuint);
#define CALL_DisableVertexAttribArray(disp, parameters) \
    (* GET_DisableVertexAttribArray(disp)) parameters
static inline _glptr_DisableVertexAttribArray GET_DisableVertexAttribArray(struct _glapi_table *disp) {
   return (_glptr_DisableVertexAttribArray) (GET_by_offset(disp, _gloffset_DisableVertexAttribArray));
}

static inline void SET_DisableVertexAttribArray(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_DisableVertexAttribArray, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawBuffers)(GLsizei, const GLenum *);
#define CALL_DrawBuffers(disp, parameters) \
    (* GET_DrawBuffers(disp)) parameters
static inline _glptr_DrawBuffers GET_DrawBuffers(struct _glapi_table *disp) {
   return (_glptr_DrawBuffers) (GET_by_offset(disp, _gloffset_DrawBuffers));
}

static inline void SET_DrawBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLenum *)) {
   SET_by_offset(disp, _gloffset_DrawBuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_EnableVertexAttribArray)(GLuint);
#define CALL_EnableVertexAttribArray(disp, parameters) \
    (* GET_EnableVertexAttribArray(disp)) parameters
static inline _glptr_EnableVertexAttribArray GET_EnableVertexAttribArray(struct _glapi_table *disp) {
   return (_glptr_EnableVertexAttribArray) (GET_by_offset(disp, _gloffset_EnableVertexAttribArray));
}

static inline void SET_EnableVertexAttribArray(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_EnableVertexAttribArray, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveAttrib)(GLuint, GLuint, GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
#define CALL_GetActiveAttrib(disp, parameters) \
    (* GET_GetActiveAttrib(disp)) parameters
static inline _glptr_GetActiveAttrib GET_GetActiveAttrib(struct _glapi_table *disp) {
   return (_glptr_GetActiveAttrib) (GET_by_offset(disp, _gloffset_GetActiveAttrib));
}

static inline void SET_GetActiveAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei , GLsizei *, GLint *, GLenum *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetActiveAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
#define CALL_GetActiveUniform(disp, parameters) \
    (* GET_GetActiveUniform(disp)) parameters
static inline _glptr_GetActiveUniform GET_GetActiveUniform(struct _glapi_table *disp) {
   return (_glptr_GetActiveUniform) (GET_by_offset(disp, _gloffset_GetActiveUniform));
}

static inline void SET_GetActiveUniform(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetActiveUniform, fn);
}

typedef void (GLAPIENTRYP _glptr_GetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *);
#define CALL_GetAttachedShaders(disp, parameters) \
    (* GET_GetAttachedShaders(disp)) parameters
static inline _glptr_GetAttachedShaders GET_GetAttachedShaders(struct _glapi_table *disp) {
   return (_glptr_GetAttachedShaders) (GET_by_offset(disp, _gloffset_GetAttachedShaders));
}

static inline void SET_GetAttachedShaders(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetAttachedShaders, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetAttribLocation)(GLuint, const GLchar *);
#define CALL_GetAttribLocation(disp, parameters) \
    (* GET_GetAttribLocation(disp)) parameters
static inline _glptr_GetAttribLocation GET_GetAttribLocation(struct _glapi_table *disp) {
   return (_glptr_GetAttribLocation) (GET_by_offset(disp, _gloffset_GetAttribLocation));
}

static inline void SET_GetAttribLocation(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetAttribLocation, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetProgramInfoLog(disp, parameters) \
    (* GET_GetProgramInfoLog(disp)) parameters
static inline _glptr_GetProgramInfoLog GET_GetProgramInfoLog(struct _glapi_table *disp) {
   return (_glptr_GetProgramInfoLog) (GET_by_offset(disp, _gloffset_GetProgramInfoLog));
}

static inline void SET_GetProgramInfoLog(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetProgramInfoLog, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramiv)(GLuint, GLenum, GLint *);
#define CALL_GetProgramiv(disp, parameters) \
    (* GET_GetProgramiv(disp)) parameters
static inline _glptr_GetProgramiv GET_GetProgramiv(struct _glapi_table *disp) {
   return (_glptr_GetProgramiv) (GET_by_offset(disp, _gloffset_GetProgramiv));
}

static inline void SET_GetProgramiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetShaderInfoLog(disp, parameters) \
    (* GET_GetShaderInfoLog(disp)) parameters
static inline _glptr_GetShaderInfoLog GET_GetShaderInfoLog(struct _glapi_table *disp) {
   return (_glptr_GetShaderInfoLog) (GET_by_offset(disp, _gloffset_GetShaderInfoLog));
}

static inline void SET_GetShaderInfoLog(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetShaderInfoLog, fn);
}

typedef void (GLAPIENTRYP _glptr_GetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetShaderSource(disp, parameters) \
    (* GET_GetShaderSource(disp)) parameters
static inline _glptr_GetShaderSource GET_GetShaderSource(struct _glapi_table *disp) {
   return (_glptr_GetShaderSource) (GET_by_offset(disp, _gloffset_GetShaderSource));
}

static inline void SET_GetShaderSource(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetShaderSource, fn);
}

typedef void (GLAPIENTRYP _glptr_GetShaderiv)(GLuint, GLenum, GLint *);
#define CALL_GetShaderiv(disp, parameters) \
    (* GET_GetShaderiv(disp)) parameters
static inline _glptr_GetShaderiv GET_GetShaderiv(struct _glapi_table *disp) {
   return (_glptr_GetShaderiv) (GET_by_offset(disp, _gloffset_GetShaderiv));
}

static inline void SET_GetShaderiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetShaderiv, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetUniformLocation)(GLuint, const GLchar *);
#define CALL_GetUniformLocation(disp, parameters) \
    (* GET_GetUniformLocation(disp)) parameters
static inline _glptr_GetUniformLocation GET_GetUniformLocation(struct _glapi_table *disp) {
   return (_glptr_GetUniformLocation) (GET_by_offset(disp, _gloffset_GetUniformLocation));
}

static inline void SET_GetUniformLocation(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetUniformLocation, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformfv)(GLuint, GLint, GLfloat *);
#define CALL_GetUniformfv(disp, parameters) \
    (* GET_GetUniformfv(disp)) parameters
static inline _glptr_GetUniformfv GET_GetUniformfv(struct _glapi_table *disp) {
   return (_glptr_GetUniformfv) (GET_by_offset(disp, _gloffset_GetUniformfv));
}

static inline void SET_GetUniformfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetUniformfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformiv)(GLuint, GLint, GLint *);
#define CALL_GetUniformiv(disp, parameters) \
    (* GET_GetUniformiv(disp)) parameters
static inline _glptr_GetUniformiv GET_GetUniformiv(struct _glapi_table *disp) {
   return (_glptr_GetUniformiv) (GET_by_offset(disp, _gloffset_GetUniformiv));
}

static inline void SET_GetUniformiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint *)) {
   SET_by_offset(disp, _gloffset_GetUniformiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribPointerv)(GLuint, GLenum, GLvoid **);
#define CALL_GetVertexAttribPointerv(disp, parameters) \
    (* GET_GetVertexAttribPointerv(disp)) parameters
static inline _glptr_GetVertexAttribPointerv GET_GetVertexAttribPointerv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribPointerv) (GET_by_offset(disp, _gloffset_GetVertexAttribPointerv));
}

static inline void SET_GetVertexAttribPointerv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLvoid **)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribPointerv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribdv)(GLuint, GLenum, GLdouble *);
#define CALL_GetVertexAttribdv(disp, parameters) \
    (* GET_GetVertexAttribdv(disp)) parameters
static inline _glptr_GetVertexAttribdv GET_GetVertexAttribdv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribdv) (GET_by_offset(disp, _gloffset_GetVertexAttribdv));
}

static inline void SET_GetVertexAttribdv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribdv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribfv)(GLuint, GLenum, GLfloat *);
#define CALL_GetVertexAttribfv(disp, parameters) \
    (* GET_GetVertexAttribfv(disp)) parameters
static inline _glptr_GetVertexAttribfv GET_GetVertexAttribfv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribfv) (GET_by_offset(disp, _gloffset_GetVertexAttribfv));
}

static inline void SET_GetVertexAttribfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribiv)(GLuint, GLenum, GLint *);
#define CALL_GetVertexAttribiv(disp, parameters) \
    (* GET_GetVertexAttribiv(disp)) parameters
static inline _glptr_GetVertexAttribiv GET_GetVertexAttribiv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribiv) (GET_by_offset(disp, _gloffset_GetVertexAttribiv));
}

static inline void SET_GetVertexAttribiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribiv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsProgram)(GLuint);
#define CALL_IsProgram(disp, parameters) \
    (* GET_IsProgram(disp)) parameters
static inline _glptr_IsProgram GET_IsProgram(struct _glapi_table *disp) {
   return (_glptr_IsProgram) (GET_by_offset(disp, _gloffset_IsProgram));
}

static inline void SET_IsProgram(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsProgram, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsShader)(GLuint);
#define CALL_IsShader(disp, parameters) \
    (* GET_IsShader(disp)) parameters
static inline _glptr_IsShader GET_IsShader(struct _glapi_table *disp) {
   return (_glptr_IsShader) (GET_by_offset(disp, _gloffset_IsShader));
}

static inline void SET_IsShader(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsShader, fn);
}

typedef void (GLAPIENTRYP _glptr_LinkProgram)(GLuint);
#define CALL_LinkProgram(disp, parameters) \
    (* GET_LinkProgram(disp)) parameters
static inline _glptr_LinkProgram GET_LinkProgram(struct _glapi_table *disp) {
   return (_glptr_LinkProgram) (GET_by_offset(disp, _gloffset_LinkProgram));
}

static inline void SET_LinkProgram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_LinkProgram, fn);
}

typedef void (GLAPIENTRYP _glptr_ShaderSource)(GLuint, GLsizei, const GLchar * const *, const GLint *);
#define CALL_ShaderSource(disp, parameters) \
    (* GET_ShaderSource(disp)) parameters
static inline _glptr_ShaderSource GET_ShaderSource(struct _glapi_table *disp) {
   return (_glptr_ShaderSource) (GET_by_offset(disp, _gloffset_ShaderSource));
}

static inline void SET_ShaderSource(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLchar * const *, const GLint *)) {
   SET_by_offset(disp, _gloffset_ShaderSource, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilFuncSeparate)(GLenum, GLenum, GLint, GLuint);
#define CALL_StencilFuncSeparate(disp, parameters) \
    (* GET_StencilFuncSeparate(disp)) parameters
static inline _glptr_StencilFuncSeparate GET_StencilFuncSeparate(struct _glapi_table *disp) {
   return (_glptr_StencilFuncSeparate) (GET_by_offset(disp, _gloffset_StencilFuncSeparate));
}

static inline void SET_StencilFuncSeparate(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint, GLuint)) {
   SET_by_offset(disp, _gloffset_StencilFuncSeparate, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilMaskSeparate)(GLenum, GLuint);
#define CALL_StencilMaskSeparate(disp, parameters) \
    (* GET_StencilMaskSeparate(disp)) parameters
static inline _glptr_StencilMaskSeparate GET_StencilMaskSeparate(struct _glapi_table *disp) {
   return (_glptr_StencilMaskSeparate) (GET_by_offset(disp, _gloffset_StencilMaskSeparate));
}

static inline void SET_StencilMaskSeparate(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_StencilMaskSeparate, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilOpSeparate)(GLenum, GLenum, GLenum, GLenum);
#define CALL_StencilOpSeparate(disp, parameters) \
    (* GET_StencilOpSeparate(disp)) parameters
static inline _glptr_StencilOpSeparate GET_StencilOpSeparate(struct _glapi_table *disp) {
   return (_glptr_StencilOpSeparate) (GET_by_offset(disp, _gloffset_StencilOpSeparate));
}

static inline void SET_StencilOpSeparate(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_StencilOpSeparate, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1f)(GLint, GLfloat);
#define CALL_Uniform1f(disp, parameters) \
    (* GET_Uniform1f(disp)) parameters
static inline _glptr_Uniform1f GET_Uniform1f(struct _glapi_table *disp) {
   return (_glptr_Uniform1f) (GET_by_offset(disp, _gloffset_Uniform1f));
}

static inline void SET_Uniform1f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLfloat)) {
   SET_by_offset(disp, _gloffset_Uniform1f, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1fv)(GLint, GLsizei, const GLfloat *);
#define CALL_Uniform1fv(disp, parameters) \
    (* GET_Uniform1fv(disp)) parameters
static inline _glptr_Uniform1fv GET_Uniform1fv(struct _glapi_table *disp) {
   return (_glptr_Uniform1fv) (GET_by_offset(disp, _gloffset_Uniform1fv));
}

static inline void SET_Uniform1fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Uniform1fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1i)(GLint, GLint);
#define CALL_Uniform1i(disp, parameters) \
    (* GET_Uniform1i(disp)) parameters
static inline _glptr_Uniform1i GET_Uniform1i(struct _glapi_table *disp) {
   return (_glptr_Uniform1i) (GET_by_offset(disp, _gloffset_Uniform1i));
}

static inline void SET_Uniform1i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Uniform1i, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1iv)(GLint, GLsizei, const GLint *);
#define CALL_Uniform1iv(disp, parameters) \
    (* GET_Uniform1iv(disp)) parameters
static inline _glptr_Uniform1iv GET_Uniform1iv(struct _glapi_table *disp) {
   return (_glptr_Uniform1iv) (GET_by_offset(disp, _gloffset_Uniform1iv));
}

static inline void SET_Uniform1iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_Uniform1iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2f)(GLint, GLfloat, GLfloat);
#define CALL_Uniform2f(disp, parameters) \
    (* GET_Uniform2f(disp)) parameters
static inline _glptr_Uniform2f GET_Uniform2f(struct _glapi_table *disp) {
   return (_glptr_Uniform2f) (GET_by_offset(disp, _gloffset_Uniform2f));
}

static inline void SET_Uniform2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Uniform2f, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2fv)(GLint, GLsizei, const GLfloat *);
#define CALL_Uniform2fv(disp, parameters) \
    (* GET_Uniform2fv(disp)) parameters
static inline _glptr_Uniform2fv GET_Uniform2fv(struct _glapi_table *disp) {
   return (_glptr_Uniform2fv) (GET_by_offset(disp, _gloffset_Uniform2fv));
}

static inline void SET_Uniform2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Uniform2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2i)(GLint, GLint, GLint);
#define CALL_Uniform2i(disp, parameters) \
    (* GET_Uniform2i(disp)) parameters
static inline _glptr_Uniform2i GET_Uniform2i(struct _glapi_table *disp) {
   return (_glptr_Uniform2i) (GET_by_offset(disp, _gloffset_Uniform2i));
}

static inline void SET_Uniform2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Uniform2i, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2iv)(GLint, GLsizei, const GLint *);
#define CALL_Uniform2iv(disp, parameters) \
    (* GET_Uniform2iv(disp)) parameters
static inline _glptr_Uniform2iv GET_Uniform2iv(struct _glapi_table *disp) {
   return (_glptr_Uniform2iv) (GET_by_offset(disp, _gloffset_Uniform2iv));
}

static inline void SET_Uniform2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_Uniform2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3f)(GLint, GLfloat, GLfloat, GLfloat);
#define CALL_Uniform3f(disp, parameters) \
    (* GET_Uniform3f(disp)) parameters
static inline _glptr_Uniform3f GET_Uniform3f(struct _glapi_table *disp) {
   return (_glptr_Uniform3f) (GET_by_offset(disp, _gloffset_Uniform3f));
}

static inline void SET_Uniform3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Uniform3f, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3fv)(GLint, GLsizei, const GLfloat *);
#define CALL_Uniform3fv(disp, parameters) \
    (* GET_Uniform3fv(disp)) parameters
static inline _glptr_Uniform3fv GET_Uniform3fv(struct _glapi_table *disp) {
   return (_glptr_Uniform3fv) (GET_by_offset(disp, _gloffset_Uniform3fv));
}

static inline void SET_Uniform3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Uniform3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3i)(GLint, GLint, GLint, GLint);
#define CALL_Uniform3i(disp, parameters) \
    (* GET_Uniform3i(disp)) parameters
static inline _glptr_Uniform3i GET_Uniform3i(struct _glapi_table *disp) {
   return (_glptr_Uniform3i) (GET_by_offset(disp, _gloffset_Uniform3i));
}

static inline void SET_Uniform3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Uniform3i, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3iv)(GLint, GLsizei, const GLint *);
#define CALL_Uniform3iv(disp, parameters) \
    (* GET_Uniform3iv(disp)) parameters
static inline _glptr_Uniform3iv GET_Uniform3iv(struct _glapi_table *disp) {
   return (_glptr_Uniform3iv) (GET_by_offset(disp, _gloffset_Uniform3iv));
}

static inline void SET_Uniform3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_Uniform3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Uniform4f(disp, parameters) \
    (* GET_Uniform4f(disp)) parameters
static inline _glptr_Uniform4f GET_Uniform4f(struct _glapi_table *disp) {
   return (_glptr_Uniform4f) (GET_by_offset(disp, _gloffset_Uniform4f));
}

static inline void SET_Uniform4f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Uniform4f, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4fv)(GLint, GLsizei, const GLfloat *);
#define CALL_Uniform4fv(disp, parameters) \
    (* GET_Uniform4fv(disp)) parameters
static inline _glptr_Uniform4fv GET_Uniform4fv(struct _glapi_table *disp) {
   return (_glptr_Uniform4fv) (GET_by_offset(disp, _gloffset_Uniform4fv));
}

static inline void SET_Uniform4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_Uniform4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4i)(GLint, GLint, GLint, GLint, GLint);
#define CALL_Uniform4i(disp, parameters) \
    (* GET_Uniform4i(disp)) parameters
static inline _glptr_Uniform4i GET_Uniform4i(struct _glapi_table *disp) {
   return (_glptr_Uniform4i) (GET_by_offset(disp, _gloffset_Uniform4i));
}

static inline void SET_Uniform4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_Uniform4i, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4iv)(GLint, GLsizei, const GLint *);
#define CALL_Uniform4iv(disp, parameters) \
    (* GET_Uniform4iv(disp)) parameters
static inline _glptr_Uniform4iv GET_Uniform4iv(struct _glapi_table *disp) {
   return (_glptr_Uniform4iv) (GET_by_offset(disp, _gloffset_Uniform4iv));
}

static inline void SET_Uniform4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_Uniform4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix2fv(disp, parameters) \
    (* GET_UniformMatrix2fv(disp)) parameters
static inline _glptr_UniformMatrix2fv GET_UniformMatrix2fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix2fv) (GET_by_offset(disp, _gloffset_UniformMatrix2fv));
}

static inline void SET_UniformMatrix2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix3fv(disp, parameters) \
    (* GET_UniformMatrix3fv(disp)) parameters
static inline _glptr_UniformMatrix3fv GET_UniformMatrix3fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix3fv) (GET_by_offset(disp, _gloffset_UniformMatrix3fv));
}

static inline void SET_UniformMatrix3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix4fv(disp, parameters) \
    (* GET_UniformMatrix4fv(disp)) parameters
static inline _glptr_UniformMatrix4fv GET_UniformMatrix4fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix4fv) (GET_by_offset(disp, _gloffset_UniformMatrix4fv));
}

static inline void SET_UniformMatrix4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UseProgram)(GLuint);
#define CALL_UseProgram(disp, parameters) \
    (* GET_UseProgram(disp)) parameters
static inline _glptr_UseProgram GET_UseProgram(struct _glapi_table *disp) {
   return (_glptr_UseProgram) (GET_by_offset(disp, _gloffset_UseProgram));
}

static inline void SET_UseProgram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_UseProgram, fn);
}

typedef void (GLAPIENTRYP _glptr_ValidateProgram)(GLuint);
#define CALL_ValidateProgram(disp, parameters) \
    (* GET_ValidateProgram(disp)) parameters
static inline _glptr_ValidateProgram GET_ValidateProgram(struct _glapi_table *disp) {
   return (_glptr_ValidateProgram) (GET_by_offset(disp, _gloffset_ValidateProgram));
}

static inline void SET_ValidateProgram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_ValidateProgram, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1d)(GLuint, GLdouble);
#define CALL_VertexAttrib1d(disp, parameters) \
    (* GET_VertexAttrib1d(disp)) parameters
static inline _glptr_VertexAttrib1d GET_VertexAttrib1d(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1d) (GET_by_offset(disp, _gloffset_VertexAttrib1d));
}

static inline void SET_VertexAttrib1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1dv)(GLuint, const GLdouble *);
#define CALL_VertexAttrib1dv(disp, parameters) \
    (* GET_VertexAttrib1dv(disp)) parameters
static inline _glptr_VertexAttrib1dv GET_VertexAttrib1dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1dv) (GET_by_offset(disp, _gloffset_VertexAttrib1dv));
}

static inline void SET_VertexAttrib1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1s)(GLuint, GLshort);
#define CALL_VertexAttrib1s(disp, parameters) \
    (* GET_VertexAttrib1s(disp)) parameters
static inline _glptr_VertexAttrib1s GET_VertexAttrib1s(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1s) (GET_by_offset(disp, _gloffset_VertexAttrib1s));
}

static inline void SET_VertexAttrib1s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1s, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1sv)(GLuint, const GLshort *);
#define CALL_VertexAttrib1sv(disp, parameters) \
    (* GET_VertexAttrib1sv(disp)) parameters
static inline _glptr_VertexAttrib1sv GET_VertexAttrib1sv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1sv) (GET_by_offset(disp, _gloffset_VertexAttrib1sv));
}

static inline void SET_VertexAttrib1sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1sv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2d)(GLuint, GLdouble, GLdouble);
#define CALL_VertexAttrib2d(disp, parameters) \
    (* GET_VertexAttrib2d(disp)) parameters
static inline _glptr_VertexAttrib2d GET_VertexAttrib2d(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2d) (GET_by_offset(disp, _gloffset_VertexAttrib2d));
}

static inline void SET_VertexAttrib2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2dv)(GLuint, const GLdouble *);
#define CALL_VertexAttrib2dv(disp, parameters) \
    (* GET_VertexAttrib2dv(disp)) parameters
static inline _glptr_VertexAttrib2dv GET_VertexAttrib2dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2dv) (GET_by_offset(disp, _gloffset_VertexAttrib2dv));
}

static inline void SET_VertexAttrib2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2s)(GLuint, GLshort, GLshort);
#define CALL_VertexAttrib2s(disp, parameters) \
    (* GET_VertexAttrib2s(disp)) parameters
static inline _glptr_VertexAttrib2s GET_VertexAttrib2s(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2s) (GET_by_offset(disp, _gloffset_VertexAttrib2s));
}

static inline void SET_VertexAttrib2s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2s, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2sv)(GLuint, const GLshort *);
#define CALL_VertexAttrib2sv(disp, parameters) \
    (* GET_VertexAttrib2sv(disp)) parameters
static inline _glptr_VertexAttrib2sv GET_VertexAttrib2sv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2sv) (GET_by_offset(disp, _gloffset_VertexAttrib2sv));
}

static inline void SET_VertexAttrib2sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2sv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3d)(GLuint, GLdouble, GLdouble, GLdouble);
#define CALL_VertexAttrib3d(disp, parameters) \
    (* GET_VertexAttrib3d(disp)) parameters
static inline _glptr_VertexAttrib3d GET_VertexAttrib3d(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3d) (GET_by_offset(disp, _gloffset_VertexAttrib3d));
}

static inline void SET_VertexAttrib3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3dv)(GLuint, const GLdouble *);
#define CALL_VertexAttrib3dv(disp, parameters) \
    (* GET_VertexAttrib3dv(disp)) parameters
static inline _glptr_VertexAttrib3dv GET_VertexAttrib3dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3dv) (GET_by_offset(disp, _gloffset_VertexAttrib3dv));
}

static inline void SET_VertexAttrib3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3s)(GLuint, GLshort, GLshort, GLshort);
#define CALL_VertexAttrib3s(disp, parameters) \
    (* GET_VertexAttrib3s(disp)) parameters
static inline _glptr_VertexAttrib3s GET_VertexAttrib3s(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3s) (GET_by_offset(disp, _gloffset_VertexAttrib3s));
}

static inline void SET_VertexAttrib3s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3s, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3sv)(GLuint, const GLshort *);
#define CALL_VertexAttrib3sv(disp, parameters) \
    (* GET_VertexAttrib3sv(disp)) parameters
static inline _glptr_VertexAttrib3sv GET_VertexAttrib3sv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3sv) (GET_by_offset(disp, _gloffset_VertexAttrib3sv));
}

static inline void SET_VertexAttrib3sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3sv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Nbv)(GLuint, const GLbyte *);
#define CALL_VertexAttrib4Nbv(disp, parameters) \
    (* GET_VertexAttrib4Nbv(disp)) parameters
static inline _glptr_VertexAttrib4Nbv GET_VertexAttrib4Nbv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Nbv) (GET_by_offset(disp, _gloffset_VertexAttrib4Nbv));
}

static inline void SET_VertexAttrib4Nbv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLbyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Nbv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Niv)(GLuint, const GLint *);
#define CALL_VertexAttrib4Niv(disp, parameters) \
    (* GET_VertexAttrib4Niv(disp)) parameters
static inline _glptr_VertexAttrib4Niv GET_VertexAttrib4Niv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Niv) (GET_by_offset(disp, _gloffset_VertexAttrib4Niv));
}

static inline void SET_VertexAttrib4Niv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Niv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Nsv)(GLuint, const GLshort *);
#define CALL_VertexAttrib4Nsv(disp, parameters) \
    (* GET_VertexAttrib4Nsv(disp)) parameters
static inline _glptr_VertexAttrib4Nsv GET_VertexAttrib4Nsv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Nsv) (GET_by_offset(disp, _gloffset_VertexAttrib4Nsv));
}

static inline void SET_VertexAttrib4Nsv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Nsv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Nub)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
#define CALL_VertexAttrib4Nub(disp, parameters) \
    (* GET_VertexAttrib4Nub(disp)) parameters
static inline _glptr_VertexAttrib4Nub GET_VertexAttrib4Nub(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Nub) (GET_by_offset(disp, _gloffset_VertexAttrib4Nub));
}

static inline void SET_VertexAttrib4Nub(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Nub, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Nubv)(GLuint, const GLubyte *);
#define CALL_VertexAttrib4Nubv(disp, parameters) \
    (* GET_VertexAttrib4Nubv(disp)) parameters
static inline _glptr_VertexAttrib4Nubv GET_VertexAttrib4Nubv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Nubv) (GET_by_offset(disp, _gloffset_VertexAttrib4Nubv));
}

static inline void SET_VertexAttrib4Nubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Nubv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Nuiv)(GLuint, const GLuint *);
#define CALL_VertexAttrib4Nuiv(disp, parameters) \
    (* GET_VertexAttrib4Nuiv(disp)) parameters
static inline _glptr_VertexAttrib4Nuiv GET_VertexAttrib4Nuiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Nuiv) (GET_by_offset(disp, _gloffset_VertexAttrib4Nuiv));
}

static inline void SET_VertexAttrib4Nuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Nuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4Nusv)(GLuint, const GLushort *);
#define CALL_VertexAttrib4Nusv(disp, parameters) \
    (* GET_VertexAttrib4Nusv(disp)) parameters
static inline _glptr_VertexAttrib4Nusv GET_VertexAttrib4Nusv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4Nusv) (GET_by_offset(disp, _gloffset_VertexAttrib4Nusv));
}

static inline void SET_VertexAttrib4Nusv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLushort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4Nusv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4bv)(GLuint, const GLbyte *);
#define CALL_VertexAttrib4bv(disp, parameters) \
    (* GET_VertexAttrib4bv(disp)) parameters
static inline _glptr_VertexAttrib4bv GET_VertexAttrib4bv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4bv) (GET_by_offset(disp, _gloffset_VertexAttrib4bv));
}

static inline void SET_VertexAttrib4bv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLbyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4bv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_VertexAttrib4d(disp, parameters) \
    (* GET_VertexAttrib4d(disp)) parameters
static inline _glptr_VertexAttrib4d GET_VertexAttrib4d(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4d) (GET_by_offset(disp, _gloffset_VertexAttrib4d));
}

static inline void SET_VertexAttrib4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4dv)(GLuint, const GLdouble *);
#define CALL_VertexAttrib4dv(disp, parameters) \
    (* GET_VertexAttrib4dv(disp)) parameters
static inline _glptr_VertexAttrib4dv GET_VertexAttrib4dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4dv) (GET_by_offset(disp, _gloffset_VertexAttrib4dv));
}

static inline void SET_VertexAttrib4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4iv)(GLuint, const GLint *);
#define CALL_VertexAttrib4iv(disp, parameters) \
    (* GET_VertexAttrib4iv(disp)) parameters
static inline _glptr_VertexAttrib4iv GET_VertexAttrib4iv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4iv) (GET_by_offset(disp, _gloffset_VertexAttrib4iv));
}

static inline void SET_VertexAttrib4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4s)(GLuint, GLshort, GLshort, GLshort, GLshort);
#define CALL_VertexAttrib4s(disp, parameters) \
    (* GET_VertexAttrib4s(disp)) parameters
static inline _glptr_VertexAttrib4s GET_VertexAttrib4s(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4s) (GET_by_offset(disp, _gloffset_VertexAttrib4s));
}

static inline void SET_VertexAttrib4s(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4s, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4sv)(GLuint, const GLshort *);
#define CALL_VertexAttrib4sv(disp, parameters) \
    (* GET_VertexAttrib4sv(disp)) parameters
static inline _glptr_VertexAttrib4sv GET_VertexAttrib4sv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4sv) (GET_by_offset(disp, _gloffset_VertexAttrib4sv));
}

static inline void SET_VertexAttrib4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4ubv)(GLuint, const GLubyte *);
#define CALL_VertexAttrib4ubv(disp, parameters) \
    (* GET_VertexAttrib4ubv(disp)) parameters
static inline _glptr_VertexAttrib4ubv GET_VertexAttrib4ubv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4ubv) (GET_by_offset(disp, _gloffset_VertexAttrib4ubv));
}

static inline void SET_VertexAttrib4ubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4ubv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4uiv)(GLuint, const GLuint *);
#define CALL_VertexAttrib4uiv(disp, parameters) \
    (* GET_VertexAttrib4uiv(disp)) parameters
static inline _glptr_VertexAttrib4uiv GET_VertexAttrib4uiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4uiv) (GET_by_offset(disp, _gloffset_VertexAttrib4uiv));
}

static inline void SET_VertexAttrib4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4usv)(GLuint, const GLushort *);
#define CALL_VertexAttrib4usv(disp, parameters) \
    (* GET_VertexAttrib4usv(disp)) parameters
static inline _glptr_VertexAttrib4usv GET_VertexAttrib4usv(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4usv) (GET_by_offset(disp, _gloffset_VertexAttrib4usv));
}

static inline void SET_VertexAttrib4usv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLushort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4usv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
#define CALL_VertexAttribPointer(disp, parameters) \
    (* GET_VertexAttribPointer(disp)) parameters
static inline _glptr_VertexAttribPointer GET_VertexAttribPointer(struct _glapi_table *disp) {
   return (_glptr_VertexAttribPointer) (GET_by_offset(disp, _gloffset_VertexAttribPointer));
}

static inline void SET_VertexAttribPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VertexAttribPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix2x3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix2x3fv(disp, parameters) \
    (* GET_UniformMatrix2x3fv(disp)) parameters
static inline _glptr_UniformMatrix2x3fv GET_UniformMatrix2x3fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix2x3fv) (GET_by_offset(disp, _gloffset_UniformMatrix2x3fv));
}

static inline void SET_UniformMatrix2x3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix2x3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix2x4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix2x4fv(disp, parameters) \
    (* GET_UniformMatrix2x4fv(disp)) parameters
static inline _glptr_UniformMatrix2x4fv GET_UniformMatrix2x4fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix2x4fv) (GET_by_offset(disp, _gloffset_UniformMatrix2x4fv));
}

static inline void SET_UniformMatrix2x4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix2x4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix3x2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix3x2fv(disp, parameters) \
    (* GET_UniformMatrix3x2fv(disp)) parameters
static inline _glptr_UniformMatrix3x2fv GET_UniformMatrix3x2fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix3x2fv) (GET_by_offset(disp, _gloffset_UniformMatrix3x2fv));
}

static inline void SET_UniformMatrix3x2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix3x2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix3x4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix3x4fv(disp, parameters) \
    (* GET_UniformMatrix3x4fv(disp)) parameters
static inline _glptr_UniformMatrix3x4fv GET_UniformMatrix3x4fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix3x4fv) (GET_by_offset(disp, _gloffset_UniformMatrix3x4fv));
}

static inline void SET_UniformMatrix3x4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix3x4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix4x2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix4x2fv(disp, parameters) \
    (* GET_UniformMatrix4x2fv(disp)) parameters
static inline _glptr_UniformMatrix4x2fv GET_UniformMatrix4x2fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix4x2fv) (GET_by_offset(disp, _gloffset_UniformMatrix4x2fv));
}

static inline void SET_UniformMatrix4x2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix4x2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix4x3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_UniformMatrix4x3fv(disp, parameters) \
    (* GET_UniformMatrix4x3fv(disp)) parameters
static inline _glptr_UniformMatrix4x3fv GET_UniformMatrix4x3fv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix4x3fv) (GET_by_offset(disp, _gloffset_UniformMatrix4x3fv));
}

static inline void SET_UniformMatrix4x3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix4x3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginConditionalRender)(GLuint, GLenum);
#define CALL_BeginConditionalRender(disp, parameters) \
    (* GET_BeginConditionalRender(disp)) parameters
static inline _glptr_BeginConditionalRender GET_BeginConditionalRender(struct _glapi_table *disp) {
   return (_glptr_BeginConditionalRender) (GET_by_offset(disp, _gloffset_BeginConditionalRender));
}

static inline void SET_BeginConditionalRender(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_BeginConditionalRender, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginTransformFeedback)(GLenum);
#define CALL_BeginTransformFeedback(disp, parameters) \
    (* GET_BeginTransformFeedback(disp)) parameters
static inline _glptr_BeginTransformFeedback GET_BeginTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_BeginTransformFeedback) (GET_by_offset(disp, _gloffset_BeginTransformFeedback));
}

static inline void SET_BeginTransformFeedback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_BeginTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_BindBufferBase)(GLenum, GLuint, GLuint);
#define CALL_BindBufferBase(disp, parameters) \
    (* GET_BindBufferBase(disp)) parameters
static inline _glptr_BindBufferBase GET_BindBufferBase(struct _glapi_table *disp) {
   return (_glptr_BindBufferBase) (GET_by_offset(disp, _gloffset_BindBufferBase));
}

static inline void SET_BindBufferBase(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_BindBufferBase, fn);
}

typedef void (GLAPIENTRYP _glptr_BindBufferRange)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
#define CALL_BindBufferRange(disp, parameters) \
    (* GET_BindBufferRange(disp)) parameters
static inline _glptr_BindBufferRange GET_BindBufferRange(struct _glapi_table *disp) {
   return (_glptr_BindBufferRange) (GET_by_offset(disp, _gloffset_BindBufferRange));
}

static inline void SET_BindBufferRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_BindBufferRange, fn);
}

typedef void (GLAPIENTRYP _glptr_BindFragDataLocation)(GLuint, GLuint, const GLchar *);
#define CALL_BindFragDataLocation(disp, parameters) \
    (* GET_BindFragDataLocation(disp)) parameters
static inline _glptr_BindFragDataLocation GET_BindFragDataLocation(struct _glapi_table *disp) {
   return (_glptr_BindFragDataLocation) (GET_by_offset(disp, _gloffset_BindFragDataLocation));
}

static inline void SET_BindFragDataLocation(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_BindFragDataLocation, fn);
}

typedef void (GLAPIENTRYP _glptr_ClampColor)(GLenum, GLenum);
#define CALL_ClampColor(disp, parameters) \
    (* GET_ClampColor(disp)) parameters
static inline _glptr_ClampColor GET_ClampColor(struct _glapi_table *disp) {
   return (_glptr_ClampColor) (GET_by_offset(disp, _gloffset_ClampColor));
}

static inline void SET_ClampColor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_ClampColor, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearBufferfi)(GLenum, GLint, GLfloat, GLint);
#define CALL_ClearBufferfi(disp, parameters) \
    (* GET_ClearBufferfi(disp)) parameters
static inline _glptr_ClearBufferfi GET_ClearBufferfi(struct _glapi_table *disp) {
   return (_glptr_ClearBufferfi) (GET_by_offset(disp, _gloffset_ClearBufferfi));
}

static inline void SET_ClearBufferfi(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLfloat, GLint)) {
   SET_by_offset(disp, _gloffset_ClearBufferfi, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearBufferfv)(GLenum, GLint, const GLfloat *);
#define CALL_ClearBufferfv(disp, parameters) \
    (* GET_ClearBufferfv(disp)) parameters
static inline _glptr_ClearBufferfv GET_ClearBufferfv(struct _glapi_table *disp) {
   return (_glptr_ClearBufferfv) (GET_by_offset(disp, _gloffset_ClearBufferfv));
}

static inline void SET_ClearBufferfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ClearBufferfv, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearBufferiv)(GLenum, GLint, const GLint *);
#define CALL_ClearBufferiv(disp, parameters) \
    (* GET_ClearBufferiv(disp)) parameters
static inline _glptr_ClearBufferiv GET_ClearBufferiv(struct _glapi_table *disp) {
   return (_glptr_ClearBufferiv) (GET_by_offset(disp, _gloffset_ClearBufferiv));
}

static inline void SET_ClearBufferiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, const GLint *)) {
   SET_by_offset(disp, _gloffset_ClearBufferiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearBufferuiv)(GLenum, GLint, const GLuint *);
#define CALL_ClearBufferuiv(disp, parameters) \
    (* GET_ClearBufferuiv(disp)) parameters
static inline _glptr_ClearBufferuiv GET_ClearBufferuiv(struct _glapi_table *disp) {
   return (_glptr_ClearBufferuiv) (GET_by_offset(disp, _gloffset_ClearBufferuiv));
}

static inline void SET_ClearBufferuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ClearBufferuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorMaski)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
#define CALL_ColorMaski(disp, parameters) \
    (* GET_ColorMaski(disp)) parameters
static inline _glptr_ColorMaski GET_ColorMaski(struct _glapi_table *disp) {
   return (_glptr_ColorMaski) (GET_by_offset(disp, _gloffset_ColorMaski));
}

static inline void SET_ColorMaski(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean)) {
   SET_by_offset(disp, _gloffset_ColorMaski, fn);
}

typedef void (GLAPIENTRYP _glptr_Disablei)(GLenum, GLuint);
#define CALL_Disablei(disp, parameters) \
    (* GET_Disablei(disp)) parameters
static inline _glptr_Disablei GET_Disablei(struct _glapi_table *disp) {
   return (_glptr_Disablei) (GET_by_offset(disp, _gloffset_Disablei));
}

static inline void SET_Disablei(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_Disablei, fn);
}

typedef void (GLAPIENTRYP _glptr_Enablei)(GLenum, GLuint);
#define CALL_Enablei(disp, parameters) \
    (* GET_Enablei(disp)) parameters
static inline _glptr_Enablei GET_Enablei(struct _glapi_table *disp) {
   return (_glptr_Enablei) (GET_by_offset(disp, _gloffset_Enablei));
}

static inline void SET_Enablei(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_Enablei, fn);
}

typedef void (GLAPIENTRYP _glptr_EndConditionalRender)(void);
#define CALL_EndConditionalRender(disp, parameters) \
    (* GET_EndConditionalRender(disp)) parameters
static inline _glptr_EndConditionalRender GET_EndConditionalRender(struct _glapi_table *disp) {
   return (_glptr_EndConditionalRender) (GET_by_offset(disp, _gloffset_EndConditionalRender));
}

static inline void SET_EndConditionalRender(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_EndConditionalRender, fn);
}

typedef void (GLAPIENTRYP _glptr_EndTransformFeedback)(void);
#define CALL_EndTransformFeedback(disp, parameters) \
    (* GET_EndTransformFeedback(disp)) parameters
static inline _glptr_EndTransformFeedback GET_EndTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_EndTransformFeedback) (GET_by_offset(disp, _gloffset_EndTransformFeedback));
}

static inline void SET_EndTransformFeedback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_EndTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_GetBooleani_v)(GLenum, GLuint, GLboolean *);
#define CALL_GetBooleani_v(disp, parameters) \
    (* GET_GetBooleani_v(disp)) parameters
static inline _glptr_GetBooleani_v GET_GetBooleani_v(struct _glapi_table *disp) {
   return (_glptr_GetBooleani_v) (GET_by_offset(disp, _gloffset_GetBooleani_v));
}

static inline void SET_GetBooleani_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLboolean *)) {
   SET_by_offset(disp, _gloffset_GetBooleani_v, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetFragDataLocation)(GLuint, const GLchar *);
#define CALL_GetFragDataLocation(disp, parameters) \
    (* GET_GetFragDataLocation(disp)) parameters
static inline _glptr_GetFragDataLocation GET_GetFragDataLocation(struct _glapi_table *disp) {
   return (_glptr_GetFragDataLocation) (GET_by_offset(disp, _gloffset_GetFragDataLocation));
}

static inline void SET_GetFragDataLocation(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetFragDataLocation, fn);
}

typedef void (GLAPIENTRYP _glptr_GetIntegeri_v)(GLenum, GLuint, GLint *);
#define CALL_GetIntegeri_v(disp, parameters) \
    (* GET_GetIntegeri_v(disp)) parameters
static inline _glptr_GetIntegeri_v GET_GetIntegeri_v(struct _glapi_table *disp) {
   return (_glptr_GetIntegeri_v) (GET_by_offset(disp, _gloffset_GetIntegeri_v));
}

static inline void SET_GetIntegeri_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLint *)) {
   SET_by_offset(disp, _gloffset_GetIntegeri_v, fn);
}

typedef const GLubyte * (GLAPIENTRYP _glptr_GetStringi)(GLenum, GLuint);
#define CALL_GetStringi(disp, parameters) \
    (* GET_GetStringi(disp)) parameters
static inline _glptr_GetStringi GET_GetStringi(struct _glapi_table *disp) {
   return (_glptr_GetStringi) (GET_by_offset(disp, _gloffset_GetStringi));
}

static inline void SET_GetStringi(struct _glapi_table *disp, const GLubyte * (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_GetStringi, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexParameterIiv)(GLenum, GLenum, GLint *);
#define CALL_GetTexParameterIiv(disp, parameters) \
    (* GET_GetTexParameterIiv(disp)) parameters
static inline _glptr_GetTexParameterIiv GET_GetTexParameterIiv(struct _glapi_table *disp) {
   return (_glptr_GetTexParameterIiv) (GET_by_offset(disp, _gloffset_GetTexParameterIiv));
}

static inline void SET_GetTexParameterIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTexParameterIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexParameterIuiv)(GLenum, GLenum, GLuint *);
#define CALL_GetTexParameterIuiv(disp, parameters) \
    (* GET_GetTexParameterIuiv(disp)) parameters
static inline _glptr_GetTexParameterIuiv GET_GetTexParameterIuiv(struct _glapi_table *disp) {
   return (_glptr_GetTexParameterIuiv) (GET_by_offset(disp, _gloffset_GetTexParameterIuiv));
}

static inline void SET_GetTexParameterIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetTexParameterIuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTransformFeedbackVarying)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
#define CALL_GetTransformFeedbackVarying(disp, parameters) \
    (* GET_GetTransformFeedbackVarying(disp)) parameters
static inline _glptr_GetTransformFeedbackVarying GET_GetTransformFeedbackVarying(struct _glapi_table *disp) {
   return (_glptr_GetTransformFeedbackVarying) (GET_by_offset(disp, _gloffset_GetTransformFeedbackVarying));
}

static inline void SET_GetTransformFeedbackVarying(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetTransformFeedbackVarying, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformuiv)(GLuint, GLint, GLuint *);
#define CALL_GetUniformuiv(disp, parameters) \
    (* GET_GetUniformuiv(disp)) parameters
static inline _glptr_GetUniformuiv GET_GetUniformuiv(struct _glapi_table *disp) {
   return (_glptr_GetUniformuiv) (GET_by_offset(disp, _gloffset_GetUniformuiv));
}

static inline void SET_GetUniformuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetUniformuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribIiv)(GLuint, GLenum, GLint *);
#define CALL_GetVertexAttribIiv(disp, parameters) \
    (* GET_GetVertexAttribIiv(disp)) parameters
static inline _glptr_GetVertexAttribIiv GET_GetVertexAttribIiv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribIiv) (GET_by_offset(disp, _gloffset_GetVertexAttribIiv));
}

static inline void SET_GetVertexAttribIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribIuiv)(GLuint, GLenum, GLuint *);
#define CALL_GetVertexAttribIuiv(disp, parameters) \
    (* GET_GetVertexAttribIuiv(disp)) parameters
static inline _glptr_GetVertexAttribIuiv GET_GetVertexAttribIuiv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribIuiv) (GET_by_offset(disp, _gloffset_GetVertexAttribIuiv));
}

static inline void SET_GetVertexAttribIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribIuiv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsEnabledi)(GLenum, GLuint);
#define CALL_IsEnabledi(disp, parameters) \
    (* GET_IsEnabledi(disp)) parameters
static inline _glptr_IsEnabledi GET_IsEnabledi(struct _glapi_table *disp) {
   return (_glptr_IsEnabledi) (GET_by_offset(disp, _gloffset_IsEnabledi));
}

static inline void SET_IsEnabledi(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_IsEnabledi, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameterIiv)(GLenum, GLenum, const GLint *);
#define CALL_TexParameterIiv(disp, parameters) \
    (* GET_TexParameterIiv(disp)) parameters
static inline _glptr_TexParameterIiv GET_TexParameterIiv(struct _glapi_table *disp) {
   return (_glptr_TexParameterIiv) (GET_by_offset(disp, _gloffset_TexParameterIiv));
}

static inline void SET_TexParameterIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TexParameterIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameterIuiv)(GLenum, GLenum, const GLuint *);
#define CALL_TexParameterIuiv(disp, parameters) \
    (* GET_TexParameterIuiv(disp)) parameters
static inline _glptr_TexParameterIuiv GET_TexParameterIuiv(struct _glapi_table *disp) {
   return (_glptr_TexParameterIuiv) (GET_by_offset(disp, _gloffset_TexParameterIuiv));
}

static inline void SET_TexParameterIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_TexParameterIuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TransformFeedbackVaryings)(GLuint, GLsizei, const GLchar * const *, GLenum);
#define CALL_TransformFeedbackVaryings(disp, parameters) \
    (* GET_TransformFeedbackVaryings(disp)) parameters
static inline _glptr_TransformFeedbackVaryings GET_TransformFeedbackVaryings(struct _glapi_table *disp) {
   return (_glptr_TransformFeedbackVaryings) (GET_by_offset(disp, _gloffset_TransformFeedbackVaryings));
}

static inline void SET_TransformFeedbackVaryings(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLchar * const *, GLenum)) {
   SET_by_offset(disp, _gloffset_TransformFeedbackVaryings, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1ui)(GLint, GLuint);
#define CALL_Uniform1ui(disp, parameters) \
    (* GET_Uniform1ui(disp)) parameters
static inline _glptr_Uniform1ui GET_Uniform1ui(struct _glapi_table *disp) {
   return (_glptr_Uniform1ui) (GET_by_offset(disp, _gloffset_Uniform1ui));
}

static inline void SET_Uniform1ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint)) {
   SET_by_offset(disp, _gloffset_Uniform1ui, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1uiv)(GLint, GLsizei, const GLuint *);
#define CALL_Uniform1uiv(disp, parameters) \
    (* GET_Uniform1uiv(disp)) parameters
static inline _glptr_Uniform1uiv GET_Uniform1uiv(struct _glapi_table *disp) {
   return (_glptr_Uniform1uiv) (GET_by_offset(disp, _gloffset_Uniform1uiv));
}

static inline void SET_Uniform1uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_Uniform1uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2ui)(GLint, GLuint, GLuint);
#define CALL_Uniform2ui(disp, parameters) \
    (* GET_Uniform2ui(disp)) parameters
static inline _glptr_Uniform2ui GET_Uniform2ui(struct _glapi_table *disp) {
   return (_glptr_Uniform2ui) (GET_by_offset(disp, _gloffset_Uniform2ui));
}

static inline void SET_Uniform2ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_Uniform2ui, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2uiv)(GLint, GLsizei, const GLuint *);
#define CALL_Uniform2uiv(disp, parameters) \
    (* GET_Uniform2uiv(disp)) parameters
static inline _glptr_Uniform2uiv GET_Uniform2uiv(struct _glapi_table *disp) {
   return (_glptr_Uniform2uiv) (GET_by_offset(disp, _gloffset_Uniform2uiv));
}

static inline void SET_Uniform2uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_Uniform2uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3ui)(GLint, GLuint, GLuint, GLuint);
#define CALL_Uniform3ui(disp, parameters) \
    (* GET_Uniform3ui(disp)) parameters
static inline _glptr_Uniform3ui GET_Uniform3ui(struct _glapi_table *disp) {
   return (_glptr_Uniform3ui) (GET_by_offset(disp, _gloffset_Uniform3ui));
}

static inline void SET_Uniform3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_Uniform3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3uiv)(GLint, GLsizei, const GLuint *);
#define CALL_Uniform3uiv(disp, parameters) \
    (* GET_Uniform3uiv(disp)) parameters
static inline _glptr_Uniform3uiv GET_Uniform3uiv(struct _glapi_table *disp) {
   return (_glptr_Uniform3uiv) (GET_by_offset(disp, _gloffset_Uniform3uiv));
}

static inline void SET_Uniform3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_Uniform3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4ui)(GLint, GLuint, GLuint, GLuint, GLuint);
#define CALL_Uniform4ui(disp, parameters) \
    (* GET_Uniform4ui(disp)) parameters
static inline _glptr_Uniform4ui GET_Uniform4ui(struct _glapi_table *disp) {
   return (_glptr_Uniform4ui) (GET_by_offset(disp, _gloffset_Uniform4ui));
}

static inline void SET_Uniform4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_Uniform4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4uiv)(GLint, GLsizei, const GLuint *);
#define CALL_Uniform4uiv(disp, parameters) \
    (* GET_Uniform4uiv(disp)) parameters
static inline _glptr_Uniform4uiv GET_Uniform4uiv(struct _glapi_table *disp) {
   return (_glptr_Uniform4uiv) (GET_by_offset(disp, _gloffset_Uniform4uiv));
}

static inline void SET_Uniform4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_Uniform4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI1iv)(GLuint, const GLint *);
#define CALL_VertexAttribI1iv(disp, parameters) \
    (* GET_VertexAttribI1iv(disp)) parameters
static inline _glptr_VertexAttribI1iv GET_VertexAttribI1iv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI1iv) (GET_by_offset(disp, _gloffset_VertexAttribI1iv));
}

static inline void SET_VertexAttribI1iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI1iv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI1uiv)(GLuint, const GLuint *);
#define CALL_VertexAttribI1uiv(disp, parameters) \
    (* GET_VertexAttribI1uiv(disp)) parameters
static inline _glptr_VertexAttribI1uiv GET_VertexAttribI1uiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI1uiv) (GET_by_offset(disp, _gloffset_VertexAttribI1uiv));
}

static inline void SET_VertexAttribI1uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI1uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4bv)(GLuint, const GLbyte *);
#define CALL_VertexAttribI4bv(disp, parameters) \
    (* GET_VertexAttribI4bv(disp)) parameters
static inline _glptr_VertexAttribI4bv GET_VertexAttribI4bv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4bv) (GET_by_offset(disp, _gloffset_VertexAttribI4bv));
}

static inline void SET_VertexAttribI4bv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLbyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4bv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4sv)(GLuint, const GLshort *);
#define CALL_VertexAttribI4sv(disp, parameters) \
    (* GET_VertexAttribI4sv(disp)) parameters
static inline _glptr_VertexAttribI4sv GET_VertexAttribI4sv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4sv) (GET_by_offset(disp, _gloffset_VertexAttribI4sv));
}

static inline void SET_VertexAttribI4sv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4sv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4ubv)(GLuint, const GLubyte *);
#define CALL_VertexAttribI4ubv(disp, parameters) \
    (* GET_VertexAttribI4ubv(disp)) parameters
static inline _glptr_VertexAttribI4ubv GET_VertexAttribI4ubv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4ubv) (GET_by_offset(disp, _gloffset_VertexAttribI4ubv));
}

static inline void SET_VertexAttribI4ubv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4ubv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4usv)(GLuint, const GLushort *);
#define CALL_VertexAttribI4usv(disp, parameters) \
    (* GET_VertexAttribI4usv(disp)) parameters
static inline _glptr_VertexAttribI4usv GET_VertexAttribI4usv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4usv) (GET_by_offset(disp, _gloffset_VertexAttribI4usv));
}

static inline void SET_VertexAttribI4usv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLushort *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4usv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribIPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_VertexAttribIPointer(disp, parameters) \
    (* GET_VertexAttribIPointer(disp)) parameters
static inline _glptr_VertexAttribIPointer GET_VertexAttribIPointer(struct _glapi_table *disp) {
   return (_glptr_VertexAttribIPointer) (GET_by_offset(disp, _gloffset_VertexAttribIPointer));
}

static inline void SET_VertexAttribIPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VertexAttribIPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_PrimitiveRestartIndex)(GLuint);
#define CALL_PrimitiveRestartIndex(disp, parameters) \
    (* GET_PrimitiveRestartIndex(disp)) parameters
static inline _glptr_PrimitiveRestartIndex GET_PrimitiveRestartIndex(struct _glapi_table *disp) {
   return (_glptr_PrimitiveRestartIndex) (GET_by_offset(disp, _gloffset_PrimitiveRestartIndex));
}

static inline void SET_PrimitiveRestartIndex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_PrimitiveRestartIndex, fn);
}

typedef void (GLAPIENTRYP _glptr_TexBuffer)(GLenum, GLenum, GLuint);
#define CALL_TexBuffer(disp, parameters) \
    (* GET_TexBuffer(disp)) parameters
static inline _glptr_TexBuffer GET_TexBuffer(struct _glapi_table *disp) {
   return (_glptr_TexBuffer) (GET_by_offset(disp, _gloffset_TexBuffer));
}

static inline void SET_TexBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_TexBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferTexture)(GLenum, GLenum, GLuint, GLint);
#define CALL_FramebufferTexture(disp, parameters) \
    (* GET_FramebufferTexture(disp)) parameters
static inline _glptr_FramebufferTexture GET_FramebufferTexture(struct _glapi_table *disp) {
   return (_glptr_FramebufferTexture) (GET_by_offset(disp, _gloffset_FramebufferTexture));
}

static inline void SET_FramebufferTexture(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint, GLint)) {
   SET_by_offset(disp, _gloffset_FramebufferTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_GetBufferParameteri64v)(GLenum, GLenum, GLint64 *);
#define CALL_GetBufferParameteri64v(disp, parameters) \
    (* GET_GetBufferParameteri64v(disp)) parameters
static inline _glptr_GetBufferParameteri64v GET_GetBufferParameteri64v(struct _glapi_table *disp) {
   return (_glptr_GetBufferParameteri64v) (GET_by_offset(disp, _gloffset_GetBufferParameteri64v));
}

static inline void SET_GetBufferParameteri64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetBufferParameteri64v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetInteger64i_v)(GLenum, GLuint, GLint64 *);
#define CALL_GetInteger64i_v(disp, parameters) \
    (* GET_GetInteger64i_v(disp)) parameters
static inline _glptr_GetInteger64i_v GET_GetInteger64i_v(struct _glapi_table *disp) {
   return (_glptr_GetInteger64i_v) (GET_by_offset(disp, _gloffset_GetInteger64i_v));
}

static inline void SET_GetInteger64i_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetInteger64i_v, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribDivisor)(GLuint, GLuint);
#define CALL_VertexAttribDivisor(disp, parameters) \
    (* GET_VertexAttribDivisor(disp)) parameters
static inline _glptr_VertexAttribDivisor GET_VertexAttribDivisor(struct _glapi_table *disp) {
   return (_glptr_VertexAttribDivisor) (GET_by_offset(disp, _gloffset_VertexAttribDivisor));
}

static inline void SET_VertexAttribDivisor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribDivisor, fn);
}

typedef void (GLAPIENTRYP _glptr_MinSampleShading)(GLfloat);
#define CALL_MinSampleShading(disp, parameters) \
    (* GET_MinSampleShading(disp)) parameters
static inline _glptr_MinSampleShading GET_MinSampleShading(struct _glapi_table *disp) {
   return (_glptr_MinSampleShading) (GET_by_offset(disp, _gloffset_MinSampleShading));
}

static inline void SET_MinSampleShading(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_MinSampleShading, fn);
}

typedef void (GLAPIENTRYP _glptr_MemoryBarrierByRegion)(GLbitfield);
#define CALL_MemoryBarrierByRegion(disp, parameters) \
    (* GET_MemoryBarrierByRegion(disp)) parameters
static inline _glptr_MemoryBarrierByRegion GET_MemoryBarrierByRegion(struct _glapi_table *disp) {
   return (_glptr_MemoryBarrierByRegion) (GET_by_offset(disp, _gloffset_MemoryBarrierByRegion));
}

static inline void SET_MemoryBarrierByRegion(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbitfield)) {
   SET_by_offset(disp, _gloffset_MemoryBarrierByRegion, fn);
}

typedef void (GLAPIENTRYP _glptr_BindProgramARB)(GLenum, GLuint);
#define CALL_BindProgramARB(disp, parameters) \
    (* GET_BindProgramARB(disp)) parameters
static inline _glptr_BindProgramARB GET_BindProgramARB(struct _glapi_table *disp) {
   return (_glptr_BindProgramARB) (GET_by_offset(disp, _gloffset_BindProgramARB));
}

static inline void SET_BindProgramARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindProgramARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteProgramsARB)(GLsizei, const GLuint *);
#define CALL_DeleteProgramsARB(disp, parameters) \
    (* GET_DeleteProgramsARB(disp)) parameters
static inline _glptr_DeleteProgramsARB GET_DeleteProgramsARB(struct _glapi_table *disp) {
   return (_glptr_DeleteProgramsARB) (GET_by_offset(disp, _gloffset_DeleteProgramsARB));
}

static inline void SET_DeleteProgramsARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteProgramsARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GenProgramsARB)(GLsizei, GLuint *);
#define CALL_GenProgramsARB(disp, parameters) \
    (* GET_GenProgramsARB(disp)) parameters
static inline _glptr_GenProgramsARB GET_GenProgramsARB(struct _glapi_table *disp) {
   return (_glptr_GenProgramsARB) (GET_by_offset(disp, _gloffset_GenProgramsARB));
}

static inline void SET_GenProgramsARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenProgramsARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramEnvParameterdvARB)(GLenum, GLuint, GLdouble *);
#define CALL_GetProgramEnvParameterdvARB(disp, parameters) \
    (* GET_GetProgramEnvParameterdvARB(disp)) parameters
static inline _glptr_GetProgramEnvParameterdvARB GET_GetProgramEnvParameterdvARB(struct _glapi_table *disp) {
   return (_glptr_GetProgramEnvParameterdvARB) (GET_by_offset(disp, _gloffset_GetProgramEnvParameterdvARB));
}

static inline void SET_GetProgramEnvParameterdvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetProgramEnvParameterdvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramEnvParameterfvARB)(GLenum, GLuint, GLfloat *);
#define CALL_GetProgramEnvParameterfvARB(disp, parameters) \
    (* GET_GetProgramEnvParameterfvARB(disp)) parameters
static inline _glptr_GetProgramEnvParameterfvARB GET_GetProgramEnvParameterfvARB(struct _glapi_table *disp) {
   return (_glptr_GetProgramEnvParameterfvARB) (GET_by_offset(disp, _gloffset_GetProgramEnvParameterfvARB));
}

static inline void SET_GetProgramEnvParameterfvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetProgramEnvParameterfvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramLocalParameterdvARB)(GLenum, GLuint, GLdouble *);
#define CALL_GetProgramLocalParameterdvARB(disp, parameters) \
    (* GET_GetProgramLocalParameterdvARB(disp)) parameters
static inline _glptr_GetProgramLocalParameterdvARB GET_GetProgramLocalParameterdvARB(struct _glapi_table *disp) {
   return (_glptr_GetProgramLocalParameterdvARB) (GET_by_offset(disp, _gloffset_GetProgramLocalParameterdvARB));
}

static inline void SET_GetProgramLocalParameterdvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetProgramLocalParameterdvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramLocalParameterfvARB)(GLenum, GLuint, GLfloat *);
#define CALL_GetProgramLocalParameterfvARB(disp, parameters) \
    (* GET_GetProgramLocalParameterfvARB(disp)) parameters
static inline _glptr_GetProgramLocalParameterfvARB GET_GetProgramLocalParameterfvARB(struct _glapi_table *disp) {
   return (_glptr_GetProgramLocalParameterfvARB) (GET_by_offset(disp, _gloffset_GetProgramLocalParameterfvARB));
}

static inline void SET_GetProgramLocalParameterfvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetProgramLocalParameterfvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramStringARB)(GLenum, GLenum, GLvoid *);
#define CALL_GetProgramStringARB(disp, parameters) \
    (* GET_GetProgramStringARB(disp)) parameters
static inline _glptr_GetProgramStringARB GET_GetProgramStringARB(struct _glapi_table *disp) {
   return (_glptr_GetProgramStringARB) (GET_by_offset(disp, _gloffset_GetProgramStringARB));
}

static inline void SET_GetProgramStringARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetProgramStringARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramivARB)(GLenum, GLenum, GLint *);
#define CALL_GetProgramivARB(disp, parameters) \
    (* GET_GetProgramivARB(disp)) parameters
static inline _glptr_GetProgramivARB GET_GetProgramivARB(struct _glapi_table *disp) {
   return (_glptr_GetProgramivARB) (GET_by_offset(disp, _gloffset_GetProgramivARB));
}

static inline void SET_GetProgramivARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramivARB, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsProgramARB)(GLuint);
#define CALL_IsProgramARB(disp, parameters) \
    (* GET_IsProgramARB(disp)) parameters
static inline _glptr_IsProgramARB GET_IsProgramARB(struct _glapi_table *disp) {
   return (_glptr_IsProgramARB) (GET_by_offset(disp, _gloffset_IsProgramARB));
}

static inline void SET_IsProgramARB(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsProgramARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramEnvParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_ProgramEnvParameter4dARB(disp, parameters) \
    (* GET_ProgramEnvParameter4dARB(disp)) parameters
static inline _glptr_ProgramEnvParameter4dARB GET_ProgramEnvParameter4dARB(struct _glapi_table *disp) {
   return (_glptr_ProgramEnvParameter4dARB) (GET_by_offset(disp, _gloffset_ProgramEnvParameter4dARB));
}

static inline void SET_ProgramEnvParameter4dARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramEnvParameter4dARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramEnvParameter4dvARB)(GLenum, GLuint, const GLdouble *);
#define CALL_ProgramEnvParameter4dvARB(disp, parameters) \
    (* GET_ProgramEnvParameter4dvARB(disp)) parameters
static inline _glptr_ProgramEnvParameter4dvARB GET_ProgramEnvParameter4dvARB(struct _glapi_table *disp) {
   return (_glptr_ProgramEnvParameter4dvARB) (GET_by_offset(disp, _gloffset_ProgramEnvParameter4dvARB));
}

static inline void SET_ProgramEnvParameter4dvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramEnvParameter4dvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramEnvParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_ProgramEnvParameter4fARB(disp, parameters) \
    (* GET_ProgramEnvParameter4fARB(disp)) parameters
static inline _glptr_ProgramEnvParameter4fARB GET_ProgramEnvParameter4fARB(struct _glapi_table *disp) {
   return (_glptr_ProgramEnvParameter4fARB) (GET_by_offset(disp, _gloffset_ProgramEnvParameter4fARB));
}

static inline void SET_ProgramEnvParameter4fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramEnvParameter4fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramEnvParameter4fvARB)(GLenum, GLuint, const GLfloat *);
#define CALL_ProgramEnvParameter4fvARB(disp, parameters) \
    (* GET_ProgramEnvParameter4fvARB(disp)) parameters
static inline _glptr_ProgramEnvParameter4fvARB GET_ProgramEnvParameter4fvARB(struct _glapi_table *disp) {
   return (_glptr_ProgramEnvParameter4fvARB) (GET_by_offset(disp, _gloffset_ProgramEnvParameter4fvARB));
}

static inline void SET_ProgramEnvParameter4fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramEnvParameter4fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramLocalParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_ProgramLocalParameter4dARB(disp, parameters) \
    (* GET_ProgramLocalParameter4dARB(disp)) parameters
static inline _glptr_ProgramLocalParameter4dARB GET_ProgramLocalParameter4dARB(struct _glapi_table *disp) {
   return (_glptr_ProgramLocalParameter4dARB) (GET_by_offset(disp, _gloffset_ProgramLocalParameter4dARB));
}

static inline void SET_ProgramLocalParameter4dARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramLocalParameter4dARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramLocalParameter4dvARB)(GLenum, GLuint, const GLdouble *);
#define CALL_ProgramLocalParameter4dvARB(disp, parameters) \
    (* GET_ProgramLocalParameter4dvARB(disp)) parameters
static inline _glptr_ProgramLocalParameter4dvARB GET_ProgramLocalParameter4dvARB(struct _glapi_table *disp) {
   return (_glptr_ProgramLocalParameter4dvARB) (GET_by_offset(disp, _gloffset_ProgramLocalParameter4dvARB));
}

static inline void SET_ProgramLocalParameter4dvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramLocalParameter4dvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramLocalParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_ProgramLocalParameter4fARB(disp, parameters) \
    (* GET_ProgramLocalParameter4fARB(disp)) parameters
static inline _glptr_ProgramLocalParameter4fARB GET_ProgramLocalParameter4fARB(struct _glapi_table *disp) {
   return (_glptr_ProgramLocalParameter4fARB) (GET_by_offset(disp, _gloffset_ProgramLocalParameter4fARB));
}

static inline void SET_ProgramLocalParameter4fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramLocalParameter4fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramLocalParameter4fvARB)(GLenum, GLuint, const GLfloat *);
#define CALL_ProgramLocalParameter4fvARB(disp, parameters) \
    (* GET_ProgramLocalParameter4fvARB(disp)) parameters
static inline _glptr_ProgramLocalParameter4fvARB GET_ProgramLocalParameter4fvARB(struct _glapi_table *disp) {
   return (_glptr_ProgramLocalParameter4fvARB) (GET_by_offset(disp, _gloffset_ProgramLocalParameter4fvARB));
}

static inline void SET_ProgramLocalParameter4fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramLocalParameter4fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramStringARB)(GLenum, GLenum, GLsizei, const GLvoid *);
#define CALL_ProgramStringARB(disp, parameters) \
    (* GET_ProgramStringARB(disp)) parameters
static inline _glptr_ProgramStringARB GET_ProgramStringARB(struct _glapi_table *disp) {
   return (_glptr_ProgramStringARB) (GET_by_offset(disp, _gloffset_ProgramStringARB));
}

static inline void SET_ProgramStringARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ProgramStringARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1fARB)(GLuint, GLfloat);
#define CALL_VertexAttrib1fARB(disp, parameters) \
    (* GET_VertexAttrib1fARB(disp)) parameters
static inline _glptr_VertexAttrib1fARB GET_VertexAttrib1fARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1fARB) (GET_by_offset(disp, _gloffset_VertexAttrib1fARB));
}

static inline void SET_VertexAttrib1fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1fvARB)(GLuint, const GLfloat *);
#define CALL_VertexAttrib1fvARB(disp, parameters) \
    (* GET_VertexAttrib1fvARB(disp)) parameters
static inline _glptr_VertexAttrib1fvARB GET_VertexAttrib1fvARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1fvARB) (GET_by_offset(disp, _gloffset_VertexAttrib1fvARB));
}

static inline void SET_VertexAttrib1fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2fARB)(GLuint, GLfloat, GLfloat);
#define CALL_VertexAttrib2fARB(disp, parameters) \
    (* GET_VertexAttrib2fARB(disp)) parameters
static inline _glptr_VertexAttrib2fARB GET_VertexAttrib2fARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2fARB) (GET_by_offset(disp, _gloffset_VertexAttrib2fARB));
}

static inline void SET_VertexAttrib2fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2fvARB)(GLuint, const GLfloat *);
#define CALL_VertexAttrib2fvARB(disp, parameters) \
    (* GET_VertexAttrib2fvARB(disp)) parameters
static inline _glptr_VertexAttrib2fvARB GET_VertexAttrib2fvARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2fvARB) (GET_by_offset(disp, _gloffset_VertexAttrib2fvARB));
}

static inline void SET_VertexAttrib2fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3fARB)(GLuint, GLfloat, GLfloat, GLfloat);
#define CALL_VertexAttrib3fARB(disp, parameters) \
    (* GET_VertexAttrib3fARB(disp)) parameters
static inline _glptr_VertexAttrib3fARB GET_VertexAttrib3fARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3fARB) (GET_by_offset(disp, _gloffset_VertexAttrib3fARB));
}

static inline void SET_VertexAttrib3fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3fvARB)(GLuint, const GLfloat *);
#define CALL_VertexAttrib3fvARB(disp, parameters) \
    (* GET_VertexAttrib3fvARB(disp)) parameters
static inline _glptr_VertexAttrib3fvARB GET_VertexAttrib3fvARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3fvARB) (GET_by_offset(disp, _gloffset_VertexAttrib3fvARB));
}

static inline void SET_VertexAttrib3fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4fARB)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_VertexAttrib4fARB(disp, parameters) \
    (* GET_VertexAttrib4fARB(disp)) parameters
static inline _glptr_VertexAttrib4fARB GET_VertexAttrib4fARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4fARB) (GET_by_offset(disp, _gloffset_VertexAttrib4fARB));
}

static inline void SET_VertexAttrib4fARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4fARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4fvARB)(GLuint, const GLfloat *);
#define CALL_VertexAttrib4fvARB(disp, parameters) \
    (* GET_VertexAttrib4fvARB(disp)) parameters
static inline _glptr_VertexAttrib4fvARB GET_VertexAttrib4fvARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4fvARB) (GET_by_offset(disp, _gloffset_VertexAttrib4fvARB));
}

static inline void SET_VertexAttrib4fvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4fvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_AttachObjectARB)(GLhandleARB, GLhandleARB);
#define CALL_AttachObjectARB(disp, parameters) \
    (* GET_AttachObjectARB(disp)) parameters
static inline _glptr_AttachObjectARB GET_AttachObjectARB(struct _glapi_table *disp) {
   return (_glptr_AttachObjectARB) (GET_by_offset(disp, _gloffset_AttachObjectARB));
}

static inline void SET_AttachObjectARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB, GLhandleARB)) {
   SET_by_offset(disp, _gloffset_AttachObjectARB, fn);
}

typedef GLhandleARB (GLAPIENTRYP _glptr_CreateProgramObjectARB)(void);
#define CALL_CreateProgramObjectARB(disp, parameters) \
    (* GET_CreateProgramObjectARB(disp)) parameters
static inline _glptr_CreateProgramObjectARB GET_CreateProgramObjectARB(struct _glapi_table *disp) {
   return (_glptr_CreateProgramObjectARB) (GET_by_offset(disp, _gloffset_CreateProgramObjectARB));
}

static inline void SET_CreateProgramObjectARB(struct _glapi_table *disp, GLhandleARB (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_CreateProgramObjectARB, fn);
}

typedef GLhandleARB (GLAPIENTRYP _glptr_CreateShaderObjectARB)(GLenum);
#define CALL_CreateShaderObjectARB(disp, parameters) \
    (* GET_CreateShaderObjectARB(disp)) parameters
static inline _glptr_CreateShaderObjectARB GET_CreateShaderObjectARB(struct _glapi_table *disp) {
   return (_glptr_CreateShaderObjectARB) (GET_by_offset(disp, _gloffset_CreateShaderObjectARB));
}

static inline void SET_CreateShaderObjectARB(struct _glapi_table *disp, GLhandleARB (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_CreateShaderObjectARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteObjectARB)(GLhandleARB);
#define CALL_DeleteObjectARB(disp, parameters) \
    (* GET_DeleteObjectARB(disp)) parameters
static inline _glptr_DeleteObjectARB GET_DeleteObjectARB(struct _glapi_table *disp) {
   return (_glptr_DeleteObjectARB) (GET_by_offset(disp, _gloffset_DeleteObjectARB));
}

static inline void SET_DeleteObjectARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB)) {
   SET_by_offset(disp, _gloffset_DeleteObjectARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DetachObjectARB)(GLhandleARB, GLhandleARB);
#define CALL_DetachObjectARB(disp, parameters) \
    (* GET_DetachObjectARB(disp)) parameters
static inline _glptr_DetachObjectARB GET_DetachObjectARB(struct _glapi_table *disp) {
   return (_glptr_DetachObjectARB) (GET_by_offset(disp, _gloffset_DetachObjectARB));
}

static inline void SET_DetachObjectARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB, GLhandleARB)) {
   SET_by_offset(disp, _gloffset_DetachObjectARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetAttachedObjectsARB)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *);
#define CALL_GetAttachedObjectsARB(disp, parameters) \
    (* GET_GetAttachedObjectsARB(disp)) parameters
static inline _glptr_GetAttachedObjectsARB GET_GetAttachedObjectsARB(struct _glapi_table *disp) {
   return (_glptr_GetAttachedObjectsARB) (GET_by_offset(disp, _gloffset_GetAttachedObjectsARB));
}

static inline void SET_GetAttachedObjectsARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *)) {
   SET_by_offset(disp, _gloffset_GetAttachedObjectsARB, fn);
}

typedef GLhandleARB (GLAPIENTRYP _glptr_GetHandleARB)(GLenum);
#define CALL_GetHandleARB(disp, parameters) \
    (* GET_GetHandleARB(disp)) parameters
static inline _glptr_GetHandleARB GET_GetHandleARB(struct _glapi_table *disp) {
   return (_glptr_GetHandleARB) (GET_by_offset(disp, _gloffset_GetHandleARB));
}

static inline void SET_GetHandleARB(struct _glapi_table *disp, GLhandleARB (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_GetHandleARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetInfoLogARB)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *);
#define CALL_GetInfoLogARB(disp, parameters) \
    (* GET_GetInfoLogARB(disp)) parameters
static inline _glptr_GetInfoLogARB GET_GetInfoLogARB(struct _glapi_table *disp) {
   return (_glptr_GetInfoLogARB) (GET_by_offset(disp, _gloffset_GetInfoLogARB));
}

static inline void SET_GetInfoLogARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *)) {
   SET_by_offset(disp, _gloffset_GetInfoLogARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetObjectParameterfvARB)(GLhandleARB, GLenum, GLfloat *);
#define CALL_GetObjectParameterfvARB(disp, parameters) \
    (* GET_GetObjectParameterfvARB(disp)) parameters
static inline _glptr_GetObjectParameterfvARB GET_GetObjectParameterfvARB(struct _glapi_table *disp) {
   return (_glptr_GetObjectParameterfvARB) (GET_by_offset(disp, _gloffset_GetObjectParameterfvARB));
}

static inline void SET_GetObjectParameterfvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetObjectParameterfvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetObjectParameterivARB)(GLhandleARB, GLenum, GLint *);
#define CALL_GetObjectParameterivARB(disp, parameters) \
    (* GET_GetObjectParameterivARB(disp)) parameters
static inline _glptr_GetObjectParameterivARB GET_GetObjectParameterivARB(struct _glapi_table *disp) {
   return (_glptr_GetObjectParameterivARB) (GET_by_offset(disp, _gloffset_GetObjectParameterivARB));
}

static inline void SET_GetObjectParameterivARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLhandleARB, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetObjectParameterivARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawArraysInstancedARB)(GLenum, GLint, GLsizei, GLsizei);
#define CALL_DrawArraysInstancedARB(disp, parameters) \
    (* GET_DrawArraysInstancedARB(disp)) parameters
static inline _glptr_DrawArraysInstancedARB GET_DrawArraysInstancedARB(struct _glapi_table *disp) {
   return (_glptr_DrawArraysInstancedARB) (GET_by_offset(disp, _gloffset_DrawArraysInstancedARB));
}

static inline void SET_DrawArraysInstancedARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_DrawArraysInstancedARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElementsInstancedARB)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
#define CALL_DrawElementsInstancedARB(disp, parameters) \
    (* GET_DrawElementsInstancedARB(disp)) parameters
static inline _glptr_DrawElementsInstancedARB GET_DrawElementsInstancedARB(struct _glapi_table *disp) {
   return (_glptr_DrawElementsInstancedARB) (GET_by_offset(disp, _gloffset_DrawElementsInstancedARB));
}

static inline void SET_DrawElementsInstancedARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei)) {
   SET_by_offset(disp, _gloffset_DrawElementsInstancedARB, fn);
}

typedef void (GLAPIENTRYP _glptr_BindFramebuffer)(GLenum, GLuint);
#define CALL_BindFramebuffer(disp, parameters) \
    (* GET_BindFramebuffer(disp)) parameters
static inline _glptr_BindFramebuffer GET_BindFramebuffer(struct _glapi_table *disp) {
   return (_glptr_BindFramebuffer) (GET_by_offset(disp, _gloffset_BindFramebuffer));
}

static inline void SET_BindFramebuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindFramebuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_BindRenderbuffer)(GLenum, GLuint);
#define CALL_BindRenderbuffer(disp, parameters) \
    (* GET_BindRenderbuffer(disp)) parameters
static inline _glptr_BindRenderbuffer GET_BindRenderbuffer(struct _glapi_table *disp) {
   return (_glptr_BindRenderbuffer) (GET_by_offset(disp, _gloffset_BindRenderbuffer));
}

static inline void SET_BindRenderbuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindRenderbuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_BlitFramebuffer)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
#define CALL_BlitFramebuffer(disp, parameters) \
    (* GET_BlitFramebuffer(disp)) parameters
static inline _glptr_BlitFramebuffer GET_BlitFramebuffer(struct _glapi_table *disp) {
   return (_glptr_BlitFramebuffer) (GET_by_offset(disp, _gloffset_BlitFramebuffer));
}

static inline void SET_BlitFramebuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)) {
   SET_by_offset(disp, _gloffset_BlitFramebuffer, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_CheckFramebufferStatus)(GLenum);
#define CALL_CheckFramebufferStatus(disp, parameters) \
    (* GET_CheckFramebufferStatus(disp)) parameters
static inline _glptr_CheckFramebufferStatus GET_CheckFramebufferStatus(struct _glapi_table *disp) {
   return (_glptr_CheckFramebufferStatus) (GET_by_offset(disp, _gloffset_CheckFramebufferStatus));
}

static inline void SET_CheckFramebufferStatus(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_CheckFramebufferStatus, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteFramebuffers)(GLsizei, const GLuint *);
#define CALL_DeleteFramebuffers(disp, parameters) \
    (* GET_DeleteFramebuffers(disp)) parameters
static inline _glptr_DeleteFramebuffers GET_DeleteFramebuffers(struct _glapi_table *disp) {
   return (_glptr_DeleteFramebuffers) (GET_by_offset(disp, _gloffset_DeleteFramebuffers));
}

static inline void SET_DeleteFramebuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteFramebuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteRenderbuffers)(GLsizei, const GLuint *);
#define CALL_DeleteRenderbuffers(disp, parameters) \
    (* GET_DeleteRenderbuffers(disp)) parameters
static inline _glptr_DeleteRenderbuffers GET_DeleteRenderbuffers(struct _glapi_table *disp) {
   return (_glptr_DeleteRenderbuffers) (GET_by_offset(disp, _gloffset_DeleteRenderbuffers));
}

static inline void SET_DeleteRenderbuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteRenderbuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint);
#define CALL_FramebufferRenderbuffer(disp, parameters) \
    (* GET_FramebufferRenderbuffer(disp)) parameters
static inline _glptr_FramebufferRenderbuffer GET_FramebufferRenderbuffer(struct _glapi_table *disp) {
   return (_glptr_FramebufferRenderbuffer) (GET_by_offset(disp, _gloffset_FramebufferRenderbuffer));
}

static inline void SET_FramebufferRenderbuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_FramebufferRenderbuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferTexture1D)(GLenum, GLenum, GLenum, GLuint, GLint);
#define CALL_FramebufferTexture1D(disp, parameters) \
    (* GET_FramebufferTexture1D(disp)) parameters
static inline _glptr_FramebufferTexture1D GET_FramebufferTexture1D(struct _glapi_table *disp) {
   return (_glptr_FramebufferTexture1D) (GET_by_offset(disp, _gloffset_FramebufferTexture1D));
}

static inline void SET_FramebufferTexture1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLuint, GLint)) {
   SET_by_offset(disp, _gloffset_FramebufferTexture1D, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint);
#define CALL_FramebufferTexture2D(disp, parameters) \
    (* GET_FramebufferTexture2D(disp)) parameters
static inline _glptr_FramebufferTexture2D GET_FramebufferTexture2D(struct _glapi_table *disp) {
   return (_glptr_FramebufferTexture2D) (GET_by_offset(disp, _gloffset_FramebufferTexture2D));
}

static inline void SET_FramebufferTexture2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLuint, GLint)) {
   SET_by_offset(disp, _gloffset_FramebufferTexture2D, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferTexture3D)(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
#define CALL_FramebufferTexture3D(disp, parameters) \
    (* GET_FramebufferTexture3D(disp)) parameters
static inline _glptr_FramebufferTexture3D GET_FramebufferTexture3D(struct _glapi_table *disp) {
   return (_glptr_FramebufferTexture3D) (GET_by_offset(disp, _gloffset_FramebufferTexture3D));
}

static inline void SET_FramebufferTexture3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLuint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_FramebufferTexture3D, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferTextureLayer)(GLenum, GLenum, GLuint, GLint, GLint);
#define CALL_FramebufferTextureLayer(disp, parameters) \
    (* GET_FramebufferTextureLayer(disp)) parameters
static inline _glptr_FramebufferTextureLayer GET_FramebufferTextureLayer(struct _glapi_table *disp) {
   return (_glptr_FramebufferTextureLayer) (GET_by_offset(disp, _gloffset_FramebufferTextureLayer));
}

static inline void SET_FramebufferTextureLayer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_FramebufferTextureLayer, fn);
}

typedef void (GLAPIENTRYP _glptr_GenFramebuffers)(GLsizei, GLuint *);
#define CALL_GenFramebuffers(disp, parameters) \
    (* GET_GenFramebuffers(disp)) parameters
static inline _glptr_GenFramebuffers GET_GenFramebuffers(struct _glapi_table *disp) {
   return (_glptr_GenFramebuffers) (GET_by_offset(disp, _gloffset_GenFramebuffers));
}

static inline void SET_GenFramebuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenFramebuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_GenRenderbuffers)(GLsizei, GLuint *);
#define CALL_GenRenderbuffers(disp, parameters) \
    (* GET_GenRenderbuffers(disp)) parameters
static inline _glptr_GenRenderbuffers GET_GenRenderbuffers(struct _glapi_table *disp) {
   return (_glptr_GenRenderbuffers) (GET_by_offset(disp, _gloffset_GenRenderbuffers));
}

static inline void SET_GenRenderbuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenRenderbuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_GenerateMipmap)(GLenum);
#define CALL_GenerateMipmap(disp, parameters) \
    (* GET_GenerateMipmap(disp)) parameters
static inline _glptr_GenerateMipmap GET_GenerateMipmap(struct _glapi_table *disp) {
   return (_glptr_GenerateMipmap) (GET_by_offset(disp, _gloffset_GenerateMipmap));
}

static inline void SET_GenerateMipmap(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_GenerateMipmap, fn);
}

typedef void (GLAPIENTRYP _glptr_GetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *);
#define CALL_GetFramebufferAttachmentParameteriv(disp, parameters) \
    (* GET_GetFramebufferAttachmentParameteriv(disp)) parameters
static inline _glptr_GetFramebufferAttachmentParameteriv GET_GetFramebufferAttachmentParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetFramebufferAttachmentParameteriv) (GET_by_offset(disp, _gloffset_GetFramebufferAttachmentParameteriv));
}

static inline void SET_GetFramebufferAttachmentParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetFramebufferAttachmentParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetRenderbufferParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetRenderbufferParameteriv(disp, parameters) \
    (* GET_GetRenderbufferParameteriv(disp)) parameters
static inline _glptr_GetRenderbufferParameteriv GET_GetRenderbufferParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetRenderbufferParameteriv) (GET_by_offset(disp, _gloffset_GetRenderbufferParameteriv));
}

static inline void SET_GetRenderbufferParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetRenderbufferParameteriv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsFramebuffer)(GLuint);
#define CALL_IsFramebuffer(disp, parameters) \
    (* GET_IsFramebuffer(disp)) parameters
static inline _glptr_IsFramebuffer GET_IsFramebuffer(struct _glapi_table *disp) {
   return (_glptr_IsFramebuffer) (GET_by_offset(disp, _gloffset_IsFramebuffer));
}

static inline void SET_IsFramebuffer(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsFramebuffer, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsRenderbuffer)(GLuint);
#define CALL_IsRenderbuffer(disp, parameters) \
    (* GET_IsRenderbuffer(disp)) parameters
static inline _glptr_IsRenderbuffer GET_IsRenderbuffer(struct _glapi_table *disp) {
   return (_glptr_IsRenderbuffer) (GET_by_offset(disp, _gloffset_IsRenderbuffer));
}

static inline void SET_IsRenderbuffer(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsRenderbuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_RenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei);
#define CALL_RenderbufferStorage(disp, parameters) \
    (* GET_RenderbufferStorage(disp)) parameters
static inline _glptr_RenderbufferStorage GET_RenderbufferStorage(struct _glapi_table *disp) {
   return (_glptr_RenderbufferStorage) (GET_by_offset(disp, _gloffset_RenderbufferStorage));
}

static inline void SET_RenderbufferStorage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_RenderbufferStorage, fn);
}

typedef void (GLAPIENTRYP _glptr_RenderbufferStorageMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define CALL_RenderbufferStorageMultisample(disp, parameters) \
    (* GET_RenderbufferStorageMultisample(disp)) parameters
static inline _glptr_RenderbufferStorageMultisample GET_RenderbufferStorageMultisample(struct _glapi_table *disp) {
   return (_glptr_RenderbufferStorageMultisample) (GET_by_offset(disp, _gloffset_RenderbufferStorageMultisample));
}

static inline void SET_RenderbufferStorageMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_RenderbufferStorageMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_FlushMappedBufferRange)(GLenum, GLintptr, GLsizeiptr);
#define CALL_FlushMappedBufferRange(disp, parameters) \
    (* GET_FlushMappedBufferRange(disp)) parameters
static inline _glptr_FlushMappedBufferRange GET_FlushMappedBufferRange(struct _glapi_table *disp) {
   return (_glptr_FlushMappedBufferRange) (GET_by_offset(disp, _gloffset_FlushMappedBufferRange));
}

static inline void SET_FlushMappedBufferRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_FlushMappedBufferRange, fn);
}

typedef GLvoid * (GLAPIENTRYP _glptr_MapBufferRange)(GLenum, GLintptr, GLsizeiptr, GLbitfield);
#define CALL_MapBufferRange(disp, parameters) \
    (* GET_MapBufferRange(disp)) parameters
static inline _glptr_MapBufferRange GET_MapBufferRange(struct _glapi_table *disp) {
   return (_glptr_MapBufferRange) (GET_by_offset(disp, _gloffset_MapBufferRange));
}

static inline void SET_MapBufferRange(struct _glapi_table *disp, GLvoid * (GLAPIENTRYP fn)(GLenum, GLintptr, GLsizeiptr, GLbitfield)) {
   SET_by_offset(disp, _gloffset_MapBufferRange, fn);
}

typedef void (GLAPIENTRYP _glptr_BindVertexArray)(GLuint);
#define CALL_BindVertexArray(disp, parameters) \
    (* GET_BindVertexArray(disp)) parameters
static inline _glptr_BindVertexArray GET_BindVertexArray(struct _glapi_table *disp) {
   return (_glptr_BindVertexArray) (GET_by_offset(disp, _gloffset_BindVertexArray));
}

static inline void SET_BindVertexArray(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_BindVertexArray, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteVertexArrays)(GLsizei, const GLuint *);
#define CALL_DeleteVertexArrays(disp, parameters) \
    (* GET_DeleteVertexArrays(disp)) parameters
static inline _glptr_DeleteVertexArrays GET_DeleteVertexArrays(struct _glapi_table *disp) {
   return (_glptr_DeleteVertexArrays) (GET_by_offset(disp, _gloffset_DeleteVertexArrays));
}

static inline void SET_DeleteVertexArrays(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteVertexArrays, fn);
}

typedef void (GLAPIENTRYP _glptr_GenVertexArrays)(GLsizei, GLuint *);
#define CALL_GenVertexArrays(disp, parameters) \
    (* GET_GenVertexArrays(disp)) parameters
static inline _glptr_GenVertexArrays GET_GenVertexArrays(struct _glapi_table *disp) {
   return (_glptr_GenVertexArrays) (GET_by_offset(disp, _gloffset_GenVertexArrays));
}

static inline void SET_GenVertexArrays(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenVertexArrays, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsVertexArray)(GLuint);
#define CALL_IsVertexArray(disp, parameters) \
    (* GET_IsVertexArray(disp)) parameters
static inline _glptr_IsVertexArray GET_IsVertexArray(struct _glapi_table *disp) {
   return (_glptr_IsVertexArray) (GET_by_offset(disp, _gloffset_IsVertexArray));
}

static inline void SET_IsVertexArray(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsVertexArray, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveUniformBlockName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetActiveUniformBlockName(disp, parameters) \
    (* GET_GetActiveUniformBlockName(disp)) parameters
static inline _glptr_GetActiveUniformBlockName GET_GetActiveUniformBlockName(struct _glapi_table *disp) {
   return (_glptr_GetActiveUniformBlockName) (GET_by_offset(disp, _gloffset_GetActiveUniformBlockName));
}

static inline void SET_GetActiveUniformBlockName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetActiveUniformBlockName, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveUniformBlockiv)(GLuint, GLuint, GLenum, GLint *);
#define CALL_GetActiveUniformBlockiv(disp, parameters) \
    (* GET_GetActiveUniformBlockiv(disp)) parameters
static inline _glptr_GetActiveUniformBlockiv GET_GetActiveUniformBlockiv(struct _glapi_table *disp) {
   return (_glptr_GetActiveUniformBlockiv) (GET_by_offset(disp, _gloffset_GetActiveUniformBlockiv));
}

static inline void SET_GetActiveUniformBlockiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetActiveUniformBlockiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveUniformName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetActiveUniformName(disp, parameters) \
    (* GET_GetActiveUniformName(disp)) parameters
static inline _glptr_GetActiveUniformName GET_GetActiveUniformName(struct _glapi_table *disp) {
   return (_glptr_GetActiveUniformName) (GET_by_offset(disp, _gloffset_GetActiveUniformName));
}

static inline void SET_GetActiveUniformName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetActiveUniformName, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveUniformsiv)(GLuint, GLsizei, const GLuint *, GLenum, GLint *);
#define CALL_GetActiveUniformsiv(disp, parameters) \
    (* GET_GetActiveUniformsiv(disp)) parameters
static inline _glptr_GetActiveUniformsiv GET_GetActiveUniformsiv(struct _glapi_table *disp) {
   return (_glptr_GetActiveUniformsiv) (GET_by_offset(disp, _gloffset_GetActiveUniformsiv));
}

static inline void SET_GetActiveUniformsiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLuint *, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetActiveUniformsiv, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_GetUniformBlockIndex)(GLuint, const GLchar *);
#define CALL_GetUniformBlockIndex(disp, parameters) \
    (* GET_GetUniformBlockIndex(disp)) parameters
static inline _glptr_GetUniformBlockIndex GET_GetUniformBlockIndex(struct _glapi_table *disp) {
   return (_glptr_GetUniformBlockIndex) (GET_by_offset(disp, _gloffset_GetUniformBlockIndex));
}

static inline void SET_GetUniformBlockIndex(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetUniformBlockIndex, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformIndices)(GLuint, GLsizei, const GLchar * const *, GLuint *);
#define CALL_GetUniformIndices(disp, parameters) \
    (* GET_GetUniformIndices(disp)) parameters
static inline _glptr_GetUniformIndices GET_GetUniformIndices(struct _glapi_table *disp) {
   return (_glptr_GetUniformIndices) (GET_by_offset(disp, _gloffset_GetUniformIndices));
}

static inline void SET_GetUniformIndices(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLchar * const *, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetUniformIndices, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformBlockBinding)(GLuint, GLuint, GLuint);
#define CALL_UniformBlockBinding(disp, parameters) \
    (* GET_UniformBlockBinding(disp)) parameters
static inline _glptr_UniformBlockBinding GET_UniformBlockBinding(struct _glapi_table *disp) {
   return (_glptr_UniformBlockBinding) (GET_by_offset(disp, _gloffset_UniformBlockBinding));
}

static inline void SET_UniformBlockBinding(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_UniformBlockBinding, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyBufferSubData)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr);
#define CALL_CopyBufferSubData(disp, parameters) \
    (* GET_CopyBufferSubData(disp)) parameters
static inline _glptr_CopyBufferSubData GET_CopyBufferSubData(struct _glapi_table *disp) {
   return (_glptr_CopyBufferSubData) (GET_by_offset(disp, _gloffset_CopyBufferSubData));
}

static inline void SET_CopyBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_CopyBufferSubData, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_ClientWaitSync)(GLsync, GLbitfield, GLuint64);
#define CALL_ClientWaitSync(disp, parameters) \
    (* GET_ClientWaitSync(disp)) parameters
static inline _glptr_ClientWaitSync GET_ClientWaitSync(struct _glapi_table *disp) {
   return (_glptr_ClientWaitSync) (GET_by_offset(disp, _gloffset_ClientWaitSync));
}

static inline void SET_ClientWaitSync(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(GLsync, GLbitfield, GLuint64)) {
   SET_by_offset(disp, _gloffset_ClientWaitSync, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteSync)(GLsync);
#define CALL_DeleteSync(disp, parameters) \
    (* GET_DeleteSync(disp)) parameters
static inline _glptr_DeleteSync GET_DeleteSync(struct _glapi_table *disp) {
   return (_glptr_DeleteSync) (GET_by_offset(disp, _gloffset_DeleteSync));
}

static inline void SET_DeleteSync(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsync)) {
   SET_by_offset(disp, _gloffset_DeleteSync, fn);
}

typedef GLsync (GLAPIENTRYP _glptr_FenceSync)(GLenum, GLbitfield);
#define CALL_FenceSync(disp, parameters) \
    (* GET_FenceSync(disp)) parameters
static inline _glptr_FenceSync GET_FenceSync(struct _glapi_table *disp) {
   return (_glptr_FenceSync) (GET_by_offset(disp, _gloffset_FenceSync));
}

static inline void SET_FenceSync(struct _glapi_table *disp, GLsync (GLAPIENTRYP fn)(GLenum, GLbitfield)) {
   SET_by_offset(disp, _gloffset_FenceSync, fn);
}

typedef void (GLAPIENTRYP _glptr_GetInteger64v)(GLenum, GLint64 *);
#define CALL_GetInteger64v(disp, parameters) \
    (* GET_GetInteger64v(disp)) parameters
static inline _glptr_GetInteger64v GET_GetInteger64v(struct _glapi_table *disp) {
   return (_glptr_GetInteger64v) (GET_by_offset(disp, _gloffset_GetInteger64v));
}

static inline void SET_GetInteger64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetInteger64v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSynciv)(GLsync, GLenum, GLsizei, GLsizei *, GLint *);
#define CALL_GetSynciv(disp, parameters) \
    (* GET_GetSynciv(disp)) parameters
static inline _glptr_GetSynciv GET_GetSynciv(struct _glapi_table *disp) {
   return (_glptr_GetSynciv) (GET_by_offset(disp, _gloffset_GetSynciv));
}

static inline void SET_GetSynciv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsync, GLenum, GLsizei, GLsizei *, GLint *)) {
   SET_by_offset(disp, _gloffset_GetSynciv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsSync)(GLsync);
#define CALL_IsSync(disp, parameters) \
    (* GET_IsSync(disp)) parameters
static inline _glptr_IsSync GET_IsSync(struct _glapi_table *disp) {
   return (_glptr_IsSync) (GET_by_offset(disp, _gloffset_IsSync));
}

static inline void SET_IsSync(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLsync)) {
   SET_by_offset(disp, _gloffset_IsSync, fn);
}

typedef void (GLAPIENTRYP _glptr_WaitSync)(GLsync, GLbitfield, GLuint64);
#define CALL_WaitSync(disp, parameters) \
    (* GET_WaitSync(disp)) parameters
static inline _glptr_WaitSync GET_WaitSync(struct _glapi_table *disp) {
   return (_glptr_WaitSync) (GET_by_offset(disp, _gloffset_WaitSync));
}

static inline void SET_WaitSync(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsync, GLbitfield, GLuint64)) {
   SET_by_offset(disp, _gloffset_WaitSync, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElementsBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLint);
#define CALL_DrawElementsBaseVertex(disp, parameters) \
    (* GET_DrawElementsBaseVertex(disp)) parameters
static inline _glptr_DrawElementsBaseVertex GET_DrawElementsBaseVertex(struct _glapi_table *disp) {
   return (_glptr_DrawElementsBaseVertex) (GET_by_offset(disp, _gloffset_DrawElementsBaseVertex));
}

static inline void SET_DrawElementsBaseVertex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, const GLvoid *, GLint)) {
   SET_by_offset(disp, _gloffset_DrawElementsBaseVertex, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElementsInstancedBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint);
#define CALL_DrawElementsInstancedBaseVertex(disp, parameters) \
    (* GET_DrawElementsInstancedBaseVertex(disp)) parameters
static inline _glptr_DrawElementsInstancedBaseVertex GET_DrawElementsInstancedBaseVertex(struct _glapi_table *disp) {
   return (_glptr_DrawElementsInstancedBaseVertex) (GET_by_offset(disp, _gloffset_DrawElementsInstancedBaseVertex));
}

static inline void SET_DrawElementsInstancedBaseVertex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint)) {
   SET_by_offset(disp, _gloffset_DrawElementsInstancedBaseVertex, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawRangeElementsBaseVertex)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint);
#define CALL_DrawRangeElementsBaseVertex(disp, parameters) \
    (* GET_DrawRangeElementsBaseVertex(disp)) parameters
static inline _glptr_DrawRangeElementsBaseVertex GET_DrawRangeElementsBaseVertex(struct _glapi_table *disp) {
   return (_glptr_DrawRangeElementsBaseVertex) (GET_by_offset(disp, _gloffset_DrawRangeElementsBaseVertex));
}

static inline void SET_DrawRangeElementsBaseVertex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint)) {
   SET_by_offset(disp, _gloffset_DrawRangeElementsBaseVertex, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawElementsBaseVertex)(GLenum, const GLsizei *, GLenum, const GLvoid * const *, GLsizei, const GLint *);
#define CALL_MultiDrawElementsBaseVertex(disp, parameters) \
    (* GET_MultiDrawElementsBaseVertex(disp)) parameters
static inline _glptr_MultiDrawElementsBaseVertex GET_MultiDrawElementsBaseVertex(struct _glapi_table *disp) {
   return (_glptr_MultiDrawElementsBaseVertex) (GET_by_offset(disp, _gloffset_MultiDrawElementsBaseVertex));
}

static inline void SET_MultiDrawElementsBaseVertex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLsizei *, GLenum, const GLvoid * const *, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_MultiDrawElementsBaseVertex, fn);
}

typedef void (GLAPIENTRYP _glptr_ProvokingVertex)(GLenum);
#define CALL_ProvokingVertex(disp, parameters) \
    (* GET_ProvokingVertex(disp)) parameters
static inline _glptr_ProvokingVertex GET_ProvokingVertex(struct _glapi_table *disp) {
   return (_glptr_ProvokingVertex) (GET_by_offset(disp, _gloffset_ProvokingVertex));
}

static inline void SET_ProvokingVertex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ProvokingVertex, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMultisamplefv)(GLenum, GLuint, GLfloat *);
#define CALL_GetMultisamplefv(disp, parameters) \
    (* GET_GetMultisamplefv(disp)) parameters
static inline _glptr_GetMultisamplefv GET_GetMultisamplefv(struct _glapi_table *disp) {
   return (_glptr_GetMultisamplefv) (GET_by_offset(disp, _gloffset_GetMultisamplefv));
}

static inline void SET_GetMultisamplefv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetMultisamplefv, fn);
}

typedef void (GLAPIENTRYP _glptr_SampleMaski)(GLuint, GLbitfield);
#define CALL_SampleMaski(disp, parameters) \
    (* GET_SampleMaski(disp)) parameters
static inline _glptr_SampleMaski GET_SampleMaski(struct _glapi_table *disp) {
   return (_glptr_SampleMaski) (GET_by_offset(disp, _gloffset_SampleMaski));
}

static inline void SET_SampleMaski(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLbitfield)) {
   SET_by_offset(disp, _gloffset_SampleMaski, fn);
}

typedef void (GLAPIENTRYP _glptr_TexImage2DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
#define CALL_TexImage2DMultisample(disp, parameters) \
    (* GET_TexImage2DMultisample(disp)) parameters
static inline _glptr_TexImage2DMultisample GET_TexImage2DMultisample(struct _glapi_table *disp) {
   return (_glptr_TexImage2DMultisample) (GET_by_offset(disp, _gloffset_TexImage2DMultisample));
}

static inline void SET_TexImage2DMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)) {
   SET_by_offset(disp, _gloffset_TexImage2DMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_TexImage3DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
#define CALL_TexImage3DMultisample(disp, parameters) \
    (* GET_TexImage3DMultisample(disp)) parameters
static inline _glptr_TexImage3DMultisample GET_TexImage3DMultisample(struct _glapi_table *disp) {
   return (_glptr_TexImage3DMultisample) (GET_by_offset(disp, _gloffset_TexImage3DMultisample));
}

static inline void SET_TexImage3DMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)) {
   SET_by_offset(disp, _gloffset_TexImage3DMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendEquationSeparateiARB)(GLuint, GLenum, GLenum);
#define CALL_BlendEquationSeparateiARB(disp, parameters) \
    (* GET_BlendEquationSeparateiARB(disp)) parameters
static inline _glptr_BlendEquationSeparateiARB GET_BlendEquationSeparateiARB(struct _glapi_table *disp) {
   return (_glptr_BlendEquationSeparateiARB) (GET_by_offset(disp, _gloffset_BlendEquationSeparateiARB));
}

static inline void SET_BlendEquationSeparateiARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendEquationSeparateiARB, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendEquationiARB)(GLuint, GLenum);
#define CALL_BlendEquationiARB(disp, parameters) \
    (* GET_BlendEquationiARB(disp)) parameters
static inline _glptr_BlendEquationiARB GET_BlendEquationiARB(struct _glapi_table *disp) {
   return (_glptr_BlendEquationiARB) (GET_by_offset(disp, _gloffset_BlendEquationiARB));
}

static inline void SET_BlendEquationiARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendEquationiARB, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendFuncSeparateiARB)(GLuint, GLenum, GLenum, GLenum, GLenum);
#define CALL_BlendFuncSeparateiARB(disp, parameters) \
    (* GET_BlendFuncSeparateiARB(disp)) parameters
static inline _glptr_BlendFuncSeparateiARB GET_BlendFuncSeparateiARB(struct _glapi_table *disp) {
   return (_glptr_BlendFuncSeparateiARB) (GET_by_offset(disp, _gloffset_BlendFuncSeparateiARB));
}

static inline void SET_BlendFuncSeparateiARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendFuncSeparateiARB, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendFunciARB)(GLuint, GLenum, GLenum);
#define CALL_BlendFunciARB(disp, parameters) \
    (* GET_BlendFunciARB(disp)) parameters
static inline _glptr_BlendFunciARB GET_BlendFunciARB(struct _glapi_table *disp) {
   return (_glptr_BlendFunciARB) (GET_by_offset(disp, _gloffset_BlendFunciARB));
}

static inline void SET_BlendFunciARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BlendFunciARB, fn);
}

typedef void (GLAPIENTRYP _glptr_BindFragDataLocationIndexed)(GLuint, GLuint, GLuint, const GLchar *);
#define CALL_BindFragDataLocationIndexed(disp, parameters) \
    (* GET_BindFragDataLocationIndexed(disp)) parameters
static inline _glptr_BindFragDataLocationIndexed GET_BindFragDataLocationIndexed(struct _glapi_table *disp) {
   return (_glptr_BindFragDataLocationIndexed) (GET_by_offset(disp, _gloffset_BindFragDataLocationIndexed));
}

static inline void SET_BindFragDataLocationIndexed(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_BindFragDataLocationIndexed, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetFragDataIndex)(GLuint, const GLchar *);
#define CALL_GetFragDataIndex(disp, parameters) \
    (* GET_GetFragDataIndex(disp)) parameters
static inline _glptr_GetFragDataIndex GET_GetFragDataIndex(struct _glapi_table *disp) {
   return (_glptr_GetFragDataIndex) (GET_by_offset(disp, _gloffset_GetFragDataIndex));
}

static inline void SET_GetFragDataIndex(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetFragDataIndex, fn);
}

typedef void (GLAPIENTRYP _glptr_BindSampler)(GLuint, GLuint);
#define CALL_BindSampler(disp, parameters) \
    (* GET_BindSampler(disp)) parameters
static inline _glptr_BindSampler GET_BindSampler(struct _glapi_table *disp) {
   return (_glptr_BindSampler) (GET_by_offset(disp, _gloffset_BindSampler));
}

static inline void SET_BindSampler(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_BindSampler, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteSamplers)(GLsizei, const GLuint *);
#define CALL_DeleteSamplers(disp, parameters) \
    (* GET_DeleteSamplers(disp)) parameters
static inline _glptr_DeleteSamplers GET_DeleteSamplers(struct _glapi_table *disp) {
   return (_glptr_DeleteSamplers) (GET_by_offset(disp, _gloffset_DeleteSamplers));
}

static inline void SET_DeleteSamplers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteSamplers, fn);
}

typedef void (GLAPIENTRYP _glptr_GenSamplers)(GLsizei, GLuint *);
#define CALL_GenSamplers(disp, parameters) \
    (* GET_GenSamplers(disp)) parameters
static inline _glptr_GenSamplers GET_GenSamplers(struct _glapi_table *disp) {
   return (_glptr_GenSamplers) (GET_by_offset(disp, _gloffset_GenSamplers));
}

static inline void SET_GenSamplers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenSamplers, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSamplerParameterIiv)(GLuint, GLenum, GLint *);
#define CALL_GetSamplerParameterIiv(disp, parameters) \
    (* GET_GetSamplerParameterIiv(disp)) parameters
static inline _glptr_GetSamplerParameterIiv GET_GetSamplerParameterIiv(struct _glapi_table *disp) {
   return (_glptr_GetSamplerParameterIiv) (GET_by_offset(disp, _gloffset_GetSamplerParameterIiv));
}

static inline void SET_GetSamplerParameterIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetSamplerParameterIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSamplerParameterIuiv)(GLuint, GLenum, GLuint *);
#define CALL_GetSamplerParameterIuiv(disp, parameters) \
    (* GET_GetSamplerParameterIuiv(disp)) parameters
static inline _glptr_GetSamplerParameterIuiv GET_GetSamplerParameterIuiv(struct _glapi_table *disp) {
   return (_glptr_GetSamplerParameterIuiv) (GET_by_offset(disp, _gloffset_GetSamplerParameterIuiv));
}

static inline void SET_GetSamplerParameterIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetSamplerParameterIuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSamplerParameterfv)(GLuint, GLenum, GLfloat *);
#define CALL_GetSamplerParameterfv(disp, parameters) \
    (* GET_GetSamplerParameterfv(disp)) parameters
static inline _glptr_GetSamplerParameterfv GET_GetSamplerParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetSamplerParameterfv) (GET_by_offset(disp, _gloffset_GetSamplerParameterfv));
}

static inline void SET_GetSamplerParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetSamplerParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSamplerParameteriv)(GLuint, GLenum, GLint *);
#define CALL_GetSamplerParameteriv(disp, parameters) \
    (* GET_GetSamplerParameteriv(disp)) parameters
static inline _glptr_GetSamplerParameteriv GET_GetSamplerParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetSamplerParameteriv) (GET_by_offset(disp, _gloffset_GetSamplerParameteriv));
}

static inline void SET_GetSamplerParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetSamplerParameteriv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsSampler)(GLuint);
#define CALL_IsSampler(disp, parameters) \
    (* GET_IsSampler(disp)) parameters
static inline _glptr_IsSampler GET_IsSampler(struct _glapi_table *disp) {
   return (_glptr_IsSampler) (GET_by_offset(disp, _gloffset_IsSampler));
}

static inline void SET_IsSampler(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsSampler, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplerParameterIiv)(GLuint, GLenum, const GLint *);
#define CALL_SamplerParameterIiv(disp, parameters) \
    (* GET_SamplerParameterIiv(disp)) parameters
static inline _glptr_SamplerParameterIiv GET_SamplerParameterIiv(struct _glapi_table *disp) {
   return (_glptr_SamplerParameterIiv) (GET_by_offset(disp, _gloffset_SamplerParameterIiv));
}

static inline void SET_SamplerParameterIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_SamplerParameterIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplerParameterIuiv)(GLuint, GLenum, const GLuint *);
#define CALL_SamplerParameterIuiv(disp, parameters) \
    (* GET_SamplerParameterIuiv(disp)) parameters
static inline _glptr_SamplerParameterIuiv GET_SamplerParameterIuiv(struct _glapi_table *disp) {
   return (_glptr_SamplerParameterIuiv) (GET_by_offset(disp, _gloffset_SamplerParameterIuiv));
}

static inline void SET_SamplerParameterIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_SamplerParameterIuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplerParameterf)(GLuint, GLenum, GLfloat);
#define CALL_SamplerParameterf(disp, parameters) \
    (* GET_SamplerParameterf(disp)) parameters
static inline _glptr_SamplerParameterf GET_SamplerParameterf(struct _glapi_table *disp) {
   return (_glptr_SamplerParameterf) (GET_by_offset(disp, _gloffset_SamplerParameterf));
}

static inline void SET_SamplerParameterf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_SamplerParameterf, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplerParameterfv)(GLuint, GLenum, const GLfloat *);
#define CALL_SamplerParameterfv(disp, parameters) \
    (* GET_SamplerParameterfv(disp)) parameters
static inline _glptr_SamplerParameterfv GET_SamplerParameterfv(struct _glapi_table *disp) {
   return (_glptr_SamplerParameterfv) (GET_by_offset(disp, _gloffset_SamplerParameterfv));
}

static inline void SET_SamplerParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_SamplerParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplerParameteri)(GLuint, GLenum, GLint);
#define CALL_SamplerParameteri(disp, parameters) \
    (* GET_SamplerParameteri(disp)) parameters
static inline _glptr_SamplerParameteri GET_SamplerParameteri(struct _glapi_table *disp) {
   return (_glptr_SamplerParameteri) (GET_by_offset(disp, _gloffset_SamplerParameteri));
}

static inline void SET_SamplerParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_SamplerParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplerParameteriv)(GLuint, GLenum, const GLint *);
#define CALL_SamplerParameteriv(disp, parameters) \
    (* GET_SamplerParameteriv(disp)) parameters
static inline _glptr_SamplerParameteriv GET_SamplerParameteriv(struct _glapi_table *disp) {
   return (_glptr_SamplerParameteriv) (GET_by_offset(disp, _gloffset_SamplerParameteriv));
}

static inline void SET_SamplerParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_SamplerParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryObjecti64v)(GLuint, GLenum, GLint64 *);
#define CALL_GetQueryObjecti64v(disp, parameters) \
    (* GET_GetQueryObjecti64v(disp)) parameters
static inline _glptr_GetQueryObjecti64v GET_GetQueryObjecti64v(struct _glapi_table *disp) {
   return (_glptr_GetQueryObjecti64v) (GET_by_offset(disp, _gloffset_GetQueryObjecti64v));
}

static inline void SET_GetQueryObjecti64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetQueryObjecti64v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryObjectui64v)(GLuint, GLenum, GLuint64 *);
#define CALL_GetQueryObjectui64v(disp, parameters) \
    (* GET_GetQueryObjectui64v(disp)) parameters
static inline _glptr_GetQueryObjectui64v GET_GetQueryObjectui64v(struct _glapi_table *disp) {
   return (_glptr_GetQueryObjectui64v) (GET_by_offset(disp, _gloffset_GetQueryObjectui64v));
}

static inline void SET_GetQueryObjectui64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint64 *)) {
   SET_by_offset(disp, _gloffset_GetQueryObjectui64v, fn);
}

typedef void (GLAPIENTRYP _glptr_QueryCounter)(GLuint, GLenum);
#define CALL_QueryCounter(disp, parameters) \
    (* GET_QueryCounter(disp)) parameters
static inline _glptr_QueryCounter GET_QueryCounter(struct _glapi_table *disp) {
   return (_glptr_QueryCounter) (GET_by_offset(disp, _gloffset_QueryCounter));
}

static inline void SET_QueryCounter(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_QueryCounter, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorP3ui)(GLenum, GLuint);
#define CALL_ColorP3ui(disp, parameters) \
    (* GET_ColorP3ui(disp)) parameters
static inline _glptr_ColorP3ui GET_ColorP3ui(struct _glapi_table *disp) {
   return (_glptr_ColorP3ui) (GET_by_offset(disp, _gloffset_ColorP3ui));
}

static inline void SET_ColorP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_ColorP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorP3uiv)(GLenum, const GLuint *);
#define CALL_ColorP3uiv(disp, parameters) \
    (* GET_ColorP3uiv(disp)) parameters
static inline _glptr_ColorP3uiv GET_ColorP3uiv(struct _glapi_table *disp) {
   return (_glptr_ColorP3uiv) (GET_by_offset(disp, _gloffset_ColorP3uiv));
}

static inline void SET_ColorP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ColorP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorP4ui)(GLenum, GLuint);
#define CALL_ColorP4ui(disp, parameters) \
    (* GET_ColorP4ui(disp)) parameters
static inline _glptr_ColorP4ui GET_ColorP4ui(struct _glapi_table *disp) {
   return (_glptr_ColorP4ui) (GET_by_offset(disp, _gloffset_ColorP4ui));
}

static inline void SET_ColorP4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_ColorP4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorP4uiv)(GLenum, const GLuint *);
#define CALL_ColorP4uiv(disp, parameters) \
    (* GET_ColorP4uiv(disp)) parameters
static inline _glptr_ColorP4uiv GET_ColorP4uiv(struct _glapi_table *disp) {
   return (_glptr_ColorP4uiv) (GET_by_offset(disp, _gloffset_ColorP4uiv));
}

static inline void SET_ColorP4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ColorP4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP1ui)(GLenum, GLenum, GLuint);
#define CALL_MultiTexCoordP1ui(disp, parameters) \
    (* GET_MultiTexCoordP1ui(disp)) parameters
static inline _glptr_MultiTexCoordP1ui GET_MultiTexCoordP1ui(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP1ui) (GET_by_offset(disp, _gloffset_MultiTexCoordP1ui));
}

static inline void SET_MultiTexCoordP1ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP1ui, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP1uiv)(GLenum, GLenum, const GLuint *);
#define CALL_MultiTexCoordP1uiv(disp, parameters) \
    (* GET_MultiTexCoordP1uiv(disp)) parameters
static inline _glptr_MultiTexCoordP1uiv GET_MultiTexCoordP1uiv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP1uiv) (GET_by_offset(disp, _gloffset_MultiTexCoordP1uiv));
}

static inline void SET_MultiTexCoordP1uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP1uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP2ui)(GLenum, GLenum, GLuint);
#define CALL_MultiTexCoordP2ui(disp, parameters) \
    (* GET_MultiTexCoordP2ui(disp)) parameters
static inline _glptr_MultiTexCoordP2ui GET_MultiTexCoordP2ui(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP2ui) (GET_by_offset(disp, _gloffset_MultiTexCoordP2ui));
}

static inline void SET_MultiTexCoordP2ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP2ui, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP2uiv)(GLenum, GLenum, const GLuint *);
#define CALL_MultiTexCoordP2uiv(disp, parameters) \
    (* GET_MultiTexCoordP2uiv(disp)) parameters
static inline _glptr_MultiTexCoordP2uiv GET_MultiTexCoordP2uiv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP2uiv) (GET_by_offset(disp, _gloffset_MultiTexCoordP2uiv));
}

static inline void SET_MultiTexCoordP2uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP2uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP3ui)(GLenum, GLenum, GLuint);
#define CALL_MultiTexCoordP3ui(disp, parameters) \
    (* GET_MultiTexCoordP3ui(disp)) parameters
static inline _glptr_MultiTexCoordP3ui GET_MultiTexCoordP3ui(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP3ui) (GET_by_offset(disp, _gloffset_MultiTexCoordP3ui));
}

static inline void SET_MultiTexCoordP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP3uiv)(GLenum, GLenum, const GLuint *);
#define CALL_MultiTexCoordP3uiv(disp, parameters) \
    (* GET_MultiTexCoordP3uiv(disp)) parameters
static inline _glptr_MultiTexCoordP3uiv GET_MultiTexCoordP3uiv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP3uiv) (GET_by_offset(disp, _gloffset_MultiTexCoordP3uiv));
}

static inline void SET_MultiTexCoordP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP4ui)(GLenum, GLenum, GLuint);
#define CALL_MultiTexCoordP4ui(disp, parameters) \
    (* GET_MultiTexCoordP4ui(disp)) parameters
static inline _glptr_MultiTexCoordP4ui GET_MultiTexCoordP4ui(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP4ui) (GET_by_offset(disp, _gloffset_MultiTexCoordP4ui));
}

static inline void SET_MultiTexCoordP4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoordP4uiv)(GLenum, GLenum, const GLuint *);
#define CALL_MultiTexCoordP4uiv(disp, parameters) \
    (* GET_MultiTexCoordP4uiv(disp)) parameters
static inline _glptr_MultiTexCoordP4uiv GET_MultiTexCoordP4uiv(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoordP4uiv) (GET_by_offset(disp, _gloffset_MultiTexCoordP4uiv));
}

static inline void SET_MultiTexCoordP4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_MultiTexCoordP4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_NormalP3ui)(GLenum, GLuint);
#define CALL_NormalP3ui(disp, parameters) \
    (* GET_NormalP3ui(disp)) parameters
static inline _glptr_NormalP3ui GET_NormalP3ui(struct _glapi_table *disp) {
   return (_glptr_NormalP3ui) (GET_by_offset(disp, _gloffset_NormalP3ui));
}

static inline void SET_NormalP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_NormalP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_NormalP3uiv)(GLenum, const GLuint *);
#define CALL_NormalP3uiv(disp, parameters) \
    (* GET_NormalP3uiv(disp)) parameters
static inline _glptr_NormalP3uiv GET_NormalP3uiv(struct _glapi_table *disp) {
   return (_glptr_NormalP3uiv) (GET_by_offset(disp, _gloffset_NormalP3uiv));
}

static inline void SET_NormalP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_NormalP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColorP3ui)(GLenum, GLuint);
#define CALL_SecondaryColorP3ui(disp, parameters) \
    (* GET_SecondaryColorP3ui(disp)) parameters
static inline _glptr_SecondaryColorP3ui GET_SecondaryColorP3ui(struct _glapi_table *disp) {
   return (_glptr_SecondaryColorP3ui) (GET_by_offset(disp, _gloffset_SecondaryColorP3ui));
}

static inline void SET_SecondaryColorP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_SecondaryColorP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColorP3uiv)(GLenum, const GLuint *);
#define CALL_SecondaryColorP3uiv(disp, parameters) \
    (* GET_SecondaryColorP3uiv(disp)) parameters
static inline _glptr_SecondaryColorP3uiv GET_SecondaryColorP3uiv(struct _glapi_table *disp) {
   return (_glptr_SecondaryColorP3uiv) (GET_by_offset(disp, _gloffset_SecondaryColorP3uiv));
}

static inline void SET_SecondaryColorP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_SecondaryColorP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP1ui)(GLenum, GLuint);
#define CALL_TexCoordP1ui(disp, parameters) \
    (* GET_TexCoordP1ui(disp)) parameters
static inline _glptr_TexCoordP1ui GET_TexCoordP1ui(struct _glapi_table *disp) {
   return (_glptr_TexCoordP1ui) (GET_by_offset(disp, _gloffset_TexCoordP1ui));
}

static inline void SET_TexCoordP1ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_TexCoordP1ui, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP1uiv)(GLenum, const GLuint *);
#define CALL_TexCoordP1uiv(disp, parameters) \
    (* GET_TexCoordP1uiv(disp)) parameters
static inline _glptr_TexCoordP1uiv GET_TexCoordP1uiv(struct _glapi_table *disp) {
   return (_glptr_TexCoordP1uiv) (GET_by_offset(disp, _gloffset_TexCoordP1uiv));
}

static inline void SET_TexCoordP1uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_TexCoordP1uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP2ui)(GLenum, GLuint);
#define CALL_TexCoordP2ui(disp, parameters) \
    (* GET_TexCoordP2ui(disp)) parameters
static inline _glptr_TexCoordP2ui GET_TexCoordP2ui(struct _glapi_table *disp) {
   return (_glptr_TexCoordP2ui) (GET_by_offset(disp, _gloffset_TexCoordP2ui));
}

static inline void SET_TexCoordP2ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_TexCoordP2ui, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP2uiv)(GLenum, const GLuint *);
#define CALL_TexCoordP2uiv(disp, parameters) \
    (* GET_TexCoordP2uiv(disp)) parameters
static inline _glptr_TexCoordP2uiv GET_TexCoordP2uiv(struct _glapi_table *disp) {
   return (_glptr_TexCoordP2uiv) (GET_by_offset(disp, _gloffset_TexCoordP2uiv));
}

static inline void SET_TexCoordP2uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_TexCoordP2uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP3ui)(GLenum, GLuint);
#define CALL_TexCoordP3ui(disp, parameters) \
    (* GET_TexCoordP3ui(disp)) parameters
static inline _glptr_TexCoordP3ui GET_TexCoordP3ui(struct _glapi_table *disp) {
   return (_glptr_TexCoordP3ui) (GET_by_offset(disp, _gloffset_TexCoordP3ui));
}

static inline void SET_TexCoordP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_TexCoordP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP3uiv)(GLenum, const GLuint *);
#define CALL_TexCoordP3uiv(disp, parameters) \
    (* GET_TexCoordP3uiv(disp)) parameters
static inline _glptr_TexCoordP3uiv GET_TexCoordP3uiv(struct _glapi_table *disp) {
   return (_glptr_TexCoordP3uiv) (GET_by_offset(disp, _gloffset_TexCoordP3uiv));
}

static inline void SET_TexCoordP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_TexCoordP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP4ui)(GLenum, GLuint);
#define CALL_TexCoordP4ui(disp, parameters) \
    (* GET_TexCoordP4ui(disp)) parameters
static inline _glptr_TexCoordP4ui GET_TexCoordP4ui(struct _glapi_table *disp) {
   return (_glptr_TexCoordP4ui) (GET_by_offset(disp, _gloffset_TexCoordP4ui));
}

static inline void SET_TexCoordP4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_TexCoordP4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordP4uiv)(GLenum, const GLuint *);
#define CALL_TexCoordP4uiv(disp, parameters) \
    (* GET_TexCoordP4uiv(disp)) parameters
static inline _glptr_TexCoordP4uiv GET_TexCoordP4uiv(struct _glapi_table *disp) {
   return (_glptr_TexCoordP4uiv) (GET_by_offset(disp, _gloffset_TexCoordP4uiv));
}

static inline void SET_TexCoordP4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_TexCoordP4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP1ui)(GLuint, GLenum, GLboolean, GLuint);
#define CALL_VertexAttribP1ui(disp, parameters) \
    (* GET_VertexAttribP1ui(disp)) parameters
static inline _glptr_VertexAttribP1ui GET_VertexAttribP1ui(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP1ui) (GET_by_offset(disp, _gloffset_VertexAttribP1ui));
}

static inline void SET_VertexAttribP1ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribP1ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP1uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define CALL_VertexAttribP1uiv(disp, parameters) \
    (* GET_VertexAttribP1uiv(disp)) parameters
static inline _glptr_VertexAttribP1uiv GET_VertexAttribP1uiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP1uiv) (GET_by_offset(disp, _gloffset_VertexAttribP1uiv));
}

static inline void SET_VertexAttribP1uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribP1uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP2ui)(GLuint, GLenum, GLboolean, GLuint);
#define CALL_VertexAttribP2ui(disp, parameters) \
    (* GET_VertexAttribP2ui(disp)) parameters
static inline _glptr_VertexAttribP2ui GET_VertexAttribP2ui(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP2ui) (GET_by_offset(disp, _gloffset_VertexAttribP2ui));
}

static inline void SET_VertexAttribP2ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribP2ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP2uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define CALL_VertexAttribP2uiv(disp, parameters) \
    (* GET_VertexAttribP2uiv(disp)) parameters
static inline _glptr_VertexAttribP2uiv GET_VertexAttribP2uiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP2uiv) (GET_by_offset(disp, _gloffset_VertexAttribP2uiv));
}

static inline void SET_VertexAttribP2uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribP2uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP3ui)(GLuint, GLenum, GLboolean, GLuint);
#define CALL_VertexAttribP3ui(disp, parameters) \
    (* GET_VertexAttribP3ui(disp)) parameters
static inline _glptr_VertexAttribP3ui GET_VertexAttribP3ui(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP3ui) (GET_by_offset(disp, _gloffset_VertexAttribP3ui));
}

static inline void SET_VertexAttribP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP3uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define CALL_VertexAttribP3uiv(disp, parameters) \
    (* GET_VertexAttribP3uiv(disp)) parameters
static inline _glptr_VertexAttribP3uiv GET_VertexAttribP3uiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP3uiv) (GET_by_offset(disp, _gloffset_VertexAttribP3uiv));
}

static inline void SET_VertexAttribP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP4ui)(GLuint, GLenum, GLboolean, GLuint);
#define CALL_VertexAttribP4ui(disp, parameters) \
    (* GET_VertexAttribP4ui(disp)) parameters
static inline _glptr_VertexAttribP4ui GET_VertexAttribP4ui(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP4ui) (GET_by_offset(disp, _gloffset_VertexAttribP4ui));
}

static inline void SET_VertexAttribP4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribP4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribP4uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define CALL_VertexAttribP4uiv(disp, parameters) \
    (* GET_VertexAttribP4uiv(disp)) parameters
static inline _glptr_VertexAttribP4uiv GET_VertexAttribP4uiv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribP4uiv) (GET_by_offset(disp, _gloffset_VertexAttribP4uiv));
}

static inline void SET_VertexAttribP4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLboolean, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribP4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexP2ui)(GLenum, GLuint);
#define CALL_VertexP2ui(disp, parameters) \
    (* GET_VertexP2ui(disp)) parameters
static inline _glptr_VertexP2ui GET_VertexP2ui(struct _glapi_table *disp) {
   return (_glptr_VertexP2ui) (GET_by_offset(disp, _gloffset_VertexP2ui));
}

static inline void SET_VertexP2ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexP2ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexP2uiv)(GLenum, const GLuint *);
#define CALL_VertexP2uiv(disp, parameters) \
    (* GET_VertexP2uiv(disp)) parameters
static inline _glptr_VertexP2uiv GET_VertexP2uiv(struct _glapi_table *disp) {
   return (_glptr_VertexP2uiv) (GET_by_offset(disp, _gloffset_VertexP2uiv));
}

static inline void SET_VertexP2uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexP2uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexP3ui)(GLenum, GLuint);
#define CALL_VertexP3ui(disp, parameters) \
    (* GET_VertexP3ui(disp)) parameters
static inline _glptr_VertexP3ui GET_VertexP3ui(struct _glapi_table *disp) {
   return (_glptr_VertexP3ui) (GET_by_offset(disp, _gloffset_VertexP3ui));
}

static inline void SET_VertexP3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexP3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexP3uiv)(GLenum, const GLuint *);
#define CALL_VertexP3uiv(disp, parameters) \
    (* GET_VertexP3uiv(disp)) parameters
static inline _glptr_VertexP3uiv GET_VertexP3uiv(struct _glapi_table *disp) {
   return (_glptr_VertexP3uiv) (GET_by_offset(disp, _gloffset_VertexP3uiv));
}

static inline void SET_VertexP3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexP3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexP4ui)(GLenum, GLuint);
#define CALL_VertexP4ui(disp, parameters) \
    (* GET_VertexP4ui(disp)) parameters
static inline _glptr_VertexP4ui GET_VertexP4ui(struct _glapi_table *disp) {
   return (_glptr_VertexP4ui) (GET_by_offset(disp, _gloffset_VertexP4ui));
}

static inline void SET_VertexP4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexP4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexP4uiv)(GLenum, const GLuint *);
#define CALL_VertexP4uiv(disp, parameters) \
    (* GET_VertexP4uiv(disp)) parameters
static inline _glptr_VertexP4uiv GET_VertexP4uiv(struct _glapi_table *disp) {
   return (_glptr_VertexP4uiv) (GET_by_offset(disp, _gloffset_VertexP4uiv));
}

static inline void SET_VertexP4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexP4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawArraysIndirect)(GLenum, const GLvoid *);
#define CALL_DrawArraysIndirect(disp, parameters) \
    (* GET_DrawArraysIndirect(disp)) parameters
static inline _glptr_DrawArraysIndirect GET_DrawArraysIndirect(struct _glapi_table *disp) {
   return (_glptr_DrawArraysIndirect) (GET_by_offset(disp, _gloffset_DrawArraysIndirect));
}

static inline void SET_DrawArraysIndirect(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_DrawArraysIndirect, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElementsIndirect)(GLenum, GLenum, const GLvoid *);
#define CALL_DrawElementsIndirect(disp, parameters) \
    (* GET_DrawElementsIndirect(disp)) parameters
static inline _glptr_DrawElementsIndirect GET_DrawElementsIndirect(struct _glapi_table *disp) {
   return (_glptr_DrawElementsIndirect) (GET_by_offset(disp, _gloffset_DrawElementsIndirect));
}

static inline void SET_DrawElementsIndirect(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_DrawElementsIndirect, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformdv)(GLuint, GLint, GLdouble *);
#define CALL_GetUniformdv(disp, parameters) \
    (* GET_GetUniformdv(disp)) parameters
static inline _glptr_GetUniformdv GET_GetUniformdv(struct _glapi_table *disp) {
   return (_glptr_GetUniformdv) (GET_by_offset(disp, _gloffset_GetUniformdv));
}

static inline void SET_GetUniformdv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetUniformdv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1d)(GLint, GLdouble);
#define CALL_Uniform1d(disp, parameters) \
    (* GET_Uniform1d(disp)) parameters
static inline _glptr_Uniform1d GET_Uniform1d(struct _glapi_table *disp) {
   return (_glptr_Uniform1d) (GET_by_offset(disp, _gloffset_Uniform1d));
}

static inline void SET_Uniform1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLdouble)) {
   SET_by_offset(disp, _gloffset_Uniform1d, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1dv)(GLint, GLsizei, const GLdouble *);
#define CALL_Uniform1dv(disp, parameters) \
    (* GET_Uniform1dv(disp)) parameters
static inline _glptr_Uniform1dv GET_Uniform1dv(struct _glapi_table *disp) {
   return (_glptr_Uniform1dv) (GET_by_offset(disp, _gloffset_Uniform1dv));
}

static inline void SET_Uniform1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Uniform1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2d)(GLint, GLdouble, GLdouble);
#define CALL_Uniform2d(disp, parameters) \
    (* GET_Uniform2d(disp)) parameters
static inline _glptr_Uniform2d GET_Uniform2d(struct _glapi_table *disp) {
   return (_glptr_Uniform2d) (GET_by_offset(disp, _gloffset_Uniform2d));
}

static inline void SET_Uniform2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Uniform2d, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2dv)(GLint, GLsizei, const GLdouble *);
#define CALL_Uniform2dv(disp, parameters) \
    (* GET_Uniform2dv(disp)) parameters
static inline _glptr_Uniform2dv GET_Uniform2dv(struct _glapi_table *disp) {
   return (_glptr_Uniform2dv) (GET_by_offset(disp, _gloffset_Uniform2dv));
}

static inline void SET_Uniform2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Uniform2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3d)(GLint, GLdouble, GLdouble, GLdouble);
#define CALL_Uniform3d(disp, parameters) \
    (* GET_Uniform3d(disp)) parameters
static inline _glptr_Uniform3d GET_Uniform3d(struct _glapi_table *disp) {
   return (_glptr_Uniform3d) (GET_by_offset(disp, _gloffset_Uniform3d));
}

static inline void SET_Uniform3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Uniform3d, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3dv)(GLint, GLsizei, const GLdouble *);
#define CALL_Uniform3dv(disp, parameters) \
    (* GET_Uniform3dv(disp)) parameters
static inline _glptr_Uniform3dv GET_Uniform3dv(struct _glapi_table *disp) {
   return (_glptr_Uniform3dv) (GET_by_offset(disp, _gloffset_Uniform3dv));
}

static inline void SET_Uniform3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Uniform3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4d)(GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_Uniform4d(disp, parameters) \
    (* GET_Uniform4d(disp)) parameters
static inline _glptr_Uniform4d GET_Uniform4d(struct _glapi_table *disp) {
   return (_glptr_Uniform4d) (GET_by_offset(disp, _gloffset_Uniform4d));
}

static inline void SET_Uniform4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_Uniform4d, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4dv)(GLint, GLsizei, const GLdouble *);
#define CALL_Uniform4dv(disp, parameters) \
    (* GET_Uniform4dv(disp)) parameters
static inline _glptr_Uniform4dv GET_Uniform4dv(struct _glapi_table *disp) {
   return (_glptr_Uniform4dv) (GET_by_offset(disp, _gloffset_Uniform4dv));
}

static inline void SET_Uniform4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_Uniform4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix2dv(disp, parameters) \
    (* GET_UniformMatrix2dv(disp)) parameters
static inline _glptr_UniformMatrix2dv GET_UniformMatrix2dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix2dv) (GET_by_offset(disp, _gloffset_UniformMatrix2dv));
}

static inline void SET_UniformMatrix2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix2x3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix2x3dv(disp, parameters) \
    (* GET_UniformMatrix2x3dv(disp)) parameters
static inline _glptr_UniformMatrix2x3dv GET_UniformMatrix2x3dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix2x3dv) (GET_by_offset(disp, _gloffset_UniformMatrix2x3dv));
}

static inline void SET_UniformMatrix2x3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix2x3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix2x4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix2x4dv(disp, parameters) \
    (* GET_UniformMatrix2x4dv(disp)) parameters
static inline _glptr_UniformMatrix2x4dv GET_UniformMatrix2x4dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix2x4dv) (GET_by_offset(disp, _gloffset_UniformMatrix2x4dv));
}

static inline void SET_UniformMatrix2x4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix2x4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix3dv(disp, parameters) \
    (* GET_UniformMatrix3dv(disp)) parameters
static inline _glptr_UniformMatrix3dv GET_UniformMatrix3dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix3dv) (GET_by_offset(disp, _gloffset_UniformMatrix3dv));
}

static inline void SET_UniformMatrix3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix3x2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix3x2dv(disp, parameters) \
    (* GET_UniformMatrix3x2dv(disp)) parameters
static inline _glptr_UniformMatrix3x2dv GET_UniformMatrix3x2dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix3x2dv) (GET_by_offset(disp, _gloffset_UniformMatrix3x2dv));
}

static inline void SET_UniformMatrix3x2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix3x2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix3x4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix3x4dv(disp, parameters) \
    (* GET_UniformMatrix3x4dv(disp)) parameters
static inline _glptr_UniformMatrix3x4dv GET_UniformMatrix3x4dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix3x4dv) (GET_by_offset(disp, _gloffset_UniformMatrix3x4dv));
}

static inline void SET_UniformMatrix3x4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix3x4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix4dv(disp, parameters) \
    (* GET_UniformMatrix4dv(disp)) parameters
static inline _glptr_UniformMatrix4dv GET_UniformMatrix4dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix4dv) (GET_by_offset(disp, _gloffset_UniformMatrix4dv));
}

static inline void SET_UniformMatrix4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix4x2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix4x2dv(disp, parameters) \
    (* GET_UniformMatrix4x2dv(disp)) parameters
static inline _glptr_UniformMatrix4x2dv GET_UniformMatrix4x2dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix4x2dv) (GET_by_offset(disp, _gloffset_UniformMatrix4x2dv));
}

static inline void SET_UniformMatrix4x2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix4x2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformMatrix4x3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_UniformMatrix4x3dv(disp, parameters) \
    (* GET_UniformMatrix4x3dv(disp)) parameters
static inline _glptr_UniformMatrix4x3dv GET_UniformMatrix4x3dv(struct _glapi_table *disp) {
   return (_glptr_UniformMatrix4x3dv) (GET_by_offset(disp, _gloffset_UniformMatrix4x3dv));
}

static inline void SET_UniformMatrix4x3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_UniformMatrix4x3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveSubroutineName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetActiveSubroutineName(disp, parameters) \
    (* GET_GetActiveSubroutineName(disp)) parameters
static inline _glptr_GetActiveSubroutineName GET_GetActiveSubroutineName(struct _glapi_table *disp) {
   return (_glptr_GetActiveSubroutineName) (GET_by_offset(disp, _gloffset_GetActiveSubroutineName));
}

static inline void SET_GetActiveSubroutineName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetActiveSubroutineName, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveSubroutineUniformName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetActiveSubroutineUniformName(disp, parameters) \
    (* GET_GetActiveSubroutineUniformName(disp)) parameters
static inline _glptr_GetActiveSubroutineUniformName GET_GetActiveSubroutineUniformName(struct _glapi_table *disp) {
   return (_glptr_GetActiveSubroutineUniformName) (GET_by_offset(disp, _gloffset_GetActiveSubroutineUniformName));
}

static inline void SET_GetActiveSubroutineUniformName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetActiveSubroutineUniformName, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveSubroutineUniformiv)(GLuint, GLenum, GLuint, GLenum, GLint *);
#define CALL_GetActiveSubroutineUniformiv(disp, parameters) \
    (* GET_GetActiveSubroutineUniformiv(disp)) parameters
static inline _glptr_GetActiveSubroutineUniformiv GET_GetActiveSubroutineUniformiv(struct _glapi_table *disp) {
   return (_glptr_GetActiveSubroutineUniformiv) (GET_by_offset(disp, _gloffset_GetActiveSubroutineUniformiv));
}

static inline void SET_GetActiveSubroutineUniformiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetActiveSubroutineUniformiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramStageiv)(GLuint, GLenum, GLenum, GLint *);
#define CALL_GetProgramStageiv(disp, parameters) \
    (* GET_GetProgramStageiv(disp)) parameters
static inline _glptr_GetProgramStageiv GET_GetProgramStageiv(struct _glapi_table *disp) {
   return (_glptr_GetProgramStageiv) (GET_by_offset(disp, _gloffset_GetProgramStageiv));
}

static inline void SET_GetProgramStageiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramStageiv, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_GetSubroutineIndex)(GLuint, GLenum, const GLchar *);
#define CALL_GetSubroutineIndex(disp, parameters) \
    (* GET_GetSubroutineIndex(disp)) parameters
static inline _glptr_GetSubroutineIndex GET_GetSubroutineIndex(struct _glapi_table *disp) {
   return (_glptr_GetSubroutineIndex) (GET_by_offset(disp, _gloffset_GetSubroutineIndex));
}

static inline void SET_GetSubroutineIndex(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLuint, GLenum, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetSubroutineIndex, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetSubroutineUniformLocation)(GLuint, GLenum, const GLchar *);
#define CALL_GetSubroutineUniformLocation(disp, parameters) \
    (* GET_GetSubroutineUniformLocation(disp)) parameters
static inline _glptr_GetSubroutineUniformLocation GET_GetSubroutineUniformLocation(struct _glapi_table *disp) {
   return (_glptr_GetSubroutineUniformLocation) (GET_by_offset(disp, _gloffset_GetSubroutineUniformLocation));
}

static inline void SET_GetSubroutineUniformLocation(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, GLenum, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetSubroutineUniformLocation, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformSubroutineuiv)(GLenum, GLint, GLuint *);
#define CALL_GetUniformSubroutineuiv(disp, parameters) \
    (* GET_GetUniformSubroutineuiv(disp)) parameters
static inline _glptr_GetUniformSubroutineuiv GET_GetUniformSubroutineuiv(struct _glapi_table *disp) {
   return (_glptr_GetUniformSubroutineuiv) (GET_by_offset(disp, _gloffset_GetUniformSubroutineuiv));
}

static inline void SET_GetUniformSubroutineuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetUniformSubroutineuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformSubroutinesuiv)(GLenum, GLsizei, const GLuint *);
#define CALL_UniformSubroutinesuiv(disp, parameters) \
    (* GET_UniformSubroutinesuiv(disp)) parameters
static inline _glptr_UniformSubroutinesuiv GET_UniformSubroutinesuiv(struct _glapi_table *disp) {
   return (_glptr_UniformSubroutinesuiv) (GET_by_offset(disp, _gloffset_UniformSubroutinesuiv));
}

static inline void SET_UniformSubroutinesuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_UniformSubroutinesuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_PatchParameterfv)(GLenum, const GLfloat *);
#define CALL_PatchParameterfv(disp, parameters) \
    (* GET_PatchParameterfv(disp)) parameters
static inline _glptr_PatchParameterfv GET_PatchParameterfv(struct _glapi_table *disp) {
   return (_glptr_PatchParameterfv) (GET_by_offset(disp, _gloffset_PatchParameterfv));
}

static inline void SET_PatchParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_PatchParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_PatchParameteri)(GLenum, GLint);
#define CALL_PatchParameteri(disp, parameters) \
    (* GET_PatchParameteri(disp)) parameters
static inline _glptr_PatchParameteri GET_PatchParameteri(struct _glapi_table *disp) {
   return (_glptr_PatchParameteri) (GET_by_offset(disp, _gloffset_PatchParameteri));
}

static inline void SET_PatchParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_PatchParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_BindTransformFeedback)(GLenum, GLuint);
#define CALL_BindTransformFeedback(disp, parameters) \
    (* GET_BindTransformFeedback(disp)) parameters
static inline _glptr_BindTransformFeedback GET_BindTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_BindTransformFeedback) (GET_by_offset(disp, _gloffset_BindTransformFeedback));
}

static inline void SET_BindTransformFeedback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteTransformFeedbacks)(GLsizei, const GLuint *);
#define CALL_DeleteTransformFeedbacks(disp, parameters) \
    (* GET_DeleteTransformFeedbacks(disp)) parameters
static inline _glptr_DeleteTransformFeedbacks GET_DeleteTransformFeedbacks(struct _glapi_table *disp) {
   return (_glptr_DeleteTransformFeedbacks) (GET_by_offset(disp, _gloffset_DeleteTransformFeedbacks));
}

static inline void SET_DeleteTransformFeedbacks(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteTransformFeedbacks, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTransformFeedback)(GLenum, GLuint);
#define CALL_DrawTransformFeedback(disp, parameters) \
    (* GET_DrawTransformFeedback(disp)) parameters
static inline _glptr_DrawTransformFeedback GET_DrawTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_DrawTransformFeedback) (GET_by_offset(disp, _gloffset_DrawTransformFeedback));
}

static inline void SET_DrawTransformFeedback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_DrawTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_GenTransformFeedbacks)(GLsizei, GLuint *);
#define CALL_GenTransformFeedbacks(disp, parameters) \
    (* GET_GenTransformFeedbacks(disp)) parameters
static inline _glptr_GenTransformFeedbacks GET_GenTransformFeedbacks(struct _glapi_table *disp) {
   return (_glptr_GenTransformFeedbacks) (GET_by_offset(disp, _gloffset_GenTransformFeedbacks));
}

static inline void SET_GenTransformFeedbacks(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenTransformFeedbacks, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsTransformFeedback)(GLuint);
#define CALL_IsTransformFeedback(disp, parameters) \
    (* GET_IsTransformFeedback(disp)) parameters
static inline _glptr_IsTransformFeedback GET_IsTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_IsTransformFeedback) (GET_by_offset(disp, _gloffset_IsTransformFeedback));
}

static inline void SET_IsTransformFeedback(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_PauseTransformFeedback)(void);
#define CALL_PauseTransformFeedback(disp, parameters) \
    (* GET_PauseTransformFeedback(disp)) parameters
static inline _glptr_PauseTransformFeedback GET_PauseTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_PauseTransformFeedback) (GET_by_offset(disp, _gloffset_PauseTransformFeedback));
}

static inline void SET_PauseTransformFeedback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PauseTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_ResumeTransformFeedback)(void);
#define CALL_ResumeTransformFeedback(disp, parameters) \
    (* GET_ResumeTransformFeedback(disp)) parameters
static inline _glptr_ResumeTransformFeedback GET_ResumeTransformFeedback(struct _glapi_table *disp) {
   return (_glptr_ResumeTransformFeedback) (GET_by_offset(disp, _gloffset_ResumeTransformFeedback));
}

static inline void SET_ResumeTransformFeedback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_ResumeTransformFeedback, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginQueryIndexed)(GLenum, GLuint, GLuint);
#define CALL_BeginQueryIndexed(disp, parameters) \
    (* GET_BeginQueryIndexed(disp)) parameters
static inline _glptr_BeginQueryIndexed GET_BeginQueryIndexed(struct _glapi_table *disp) {
   return (_glptr_BeginQueryIndexed) (GET_by_offset(disp, _gloffset_BeginQueryIndexed));
}

static inline void SET_BeginQueryIndexed(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_BeginQueryIndexed, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTransformFeedbackStream)(GLenum, GLuint, GLuint);
#define CALL_DrawTransformFeedbackStream(disp, parameters) \
    (* GET_DrawTransformFeedbackStream(disp)) parameters
static inline _glptr_DrawTransformFeedbackStream GET_DrawTransformFeedbackStream(struct _glapi_table *disp) {
   return (_glptr_DrawTransformFeedbackStream) (GET_by_offset(disp, _gloffset_DrawTransformFeedbackStream));
}

static inline void SET_DrawTransformFeedbackStream(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_DrawTransformFeedbackStream, fn);
}

typedef void (GLAPIENTRYP _glptr_EndQueryIndexed)(GLenum, GLuint);
#define CALL_EndQueryIndexed(disp, parameters) \
    (* GET_EndQueryIndexed(disp)) parameters
static inline _glptr_EndQueryIndexed GET_EndQueryIndexed(struct _glapi_table *disp) {
   return (_glptr_EndQueryIndexed) (GET_by_offset(disp, _gloffset_EndQueryIndexed));
}

static inline void SET_EndQueryIndexed(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_EndQueryIndexed, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryIndexediv)(GLenum, GLuint, GLenum, GLint *);
#define CALL_GetQueryIndexediv(disp, parameters) \
    (* GET_GetQueryIndexediv(disp)) parameters
static inline _glptr_GetQueryIndexediv GET_GetQueryIndexediv(struct _glapi_table *disp) {
   return (_glptr_GetQueryIndexediv) (GET_by_offset(disp, _gloffset_GetQueryIndexediv));
}

static inline void SET_GetQueryIndexediv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetQueryIndexediv, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearDepthf)(GLclampf);
#define CALL_ClearDepthf(disp, parameters) \
    (* GET_ClearDepthf(disp)) parameters
static inline _glptr_ClearDepthf GET_ClearDepthf(struct _glapi_table *disp) {
   return (_glptr_ClearDepthf) (GET_by_offset(disp, _gloffset_ClearDepthf));
}

static inline void SET_ClearDepthf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampf)) {
   SET_by_offset(disp, _gloffset_ClearDepthf, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRangef)(GLclampf, GLclampf);
#define CALL_DepthRangef(disp, parameters) \
    (* GET_DepthRangef(disp)) parameters
static inline _glptr_DepthRangef GET_DepthRangef(struct _glapi_table *disp) {
   return (_glptr_DepthRangef) (GET_by_offset(disp, _gloffset_DepthRangef));
}

static inline void SET_DepthRangef(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampf, GLclampf)) {
   SET_by_offset(disp, _gloffset_DepthRangef, fn);
}

typedef void (GLAPIENTRYP _glptr_GetShaderPrecisionFormat)(GLenum, GLenum, GLint *, GLint *);
#define CALL_GetShaderPrecisionFormat(disp, parameters) \
    (* GET_GetShaderPrecisionFormat(disp)) parameters
static inline _glptr_GetShaderPrecisionFormat GET_GetShaderPrecisionFormat(struct _glapi_table *disp) {
   return (_glptr_GetShaderPrecisionFormat) (GET_by_offset(disp, _gloffset_GetShaderPrecisionFormat));
}

static inline void SET_GetShaderPrecisionFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *, GLint *)) {
   SET_by_offset(disp, _gloffset_GetShaderPrecisionFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_ReleaseShaderCompiler)(void);
#define CALL_ReleaseShaderCompiler(disp, parameters) \
    (* GET_ReleaseShaderCompiler(disp)) parameters
static inline _glptr_ReleaseShaderCompiler GET_ReleaseShaderCompiler(struct _glapi_table *disp) {
   return (_glptr_ReleaseShaderCompiler) (GET_by_offset(disp, _gloffset_ReleaseShaderCompiler));
}

static inline void SET_ReleaseShaderCompiler(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_ReleaseShaderCompiler, fn);
}

typedef void (GLAPIENTRYP _glptr_ShaderBinary)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei);
#define CALL_ShaderBinary(disp, parameters) \
    (* GET_ShaderBinary(disp)) parameters
static inline _glptr_ShaderBinary GET_ShaderBinary(struct _glapi_table *disp) {
   return (_glptr_ShaderBinary) (GET_by_offset(disp, _gloffset_ShaderBinary));
}

static inline void SET_ShaderBinary(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei)) {
   SET_by_offset(disp, _gloffset_ShaderBinary, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramBinary)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *);
#define CALL_GetProgramBinary(disp, parameters) \
    (* GET_GetProgramBinary(disp)) parameters
static inline _glptr_GetProgramBinary GET_GetProgramBinary(struct _glapi_table *disp) {
   return (_glptr_GetProgramBinary) (GET_by_offset(disp, _gloffset_GetProgramBinary));
}

static inline void SET_GetProgramBinary(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetProgramBinary, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramBinary)(GLuint, GLenum, const GLvoid *, GLsizei);
#define CALL_ProgramBinary(disp, parameters) \
    (* GET_ProgramBinary(disp)) parameters
static inline _glptr_ProgramBinary GET_ProgramBinary(struct _glapi_table *disp) {
   return (_glptr_ProgramBinary) (GET_by_offset(disp, _gloffset_ProgramBinary));
}

static inline void SET_ProgramBinary(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLvoid *, GLsizei)) {
   SET_by_offset(disp, _gloffset_ProgramBinary, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramParameteri)(GLuint, GLenum, GLint);
#define CALL_ProgramParameteri(disp, parameters) \
    (* GET_ProgramParameteri(disp)) parameters
static inline _glptr_ProgramParameteri GET_ProgramParameteri(struct _glapi_table *disp) {
   return (_glptr_ProgramParameteri) (GET_by_offset(disp, _gloffset_ProgramParameteri));
}

static inline void SET_ProgramParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_ProgramParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribLdv)(GLuint, GLenum, GLdouble *);
#define CALL_GetVertexAttribLdv(disp, parameters) \
    (* GET_GetVertexAttribLdv(disp)) parameters
static inline _glptr_GetVertexAttribLdv GET_GetVertexAttribLdv(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribLdv) (GET_by_offset(disp, _gloffset_GetVertexAttribLdv));
}

static inline void SET_GetVertexAttribLdv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribLdv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL1d)(GLuint, GLdouble);
#define CALL_VertexAttribL1d(disp, parameters) \
    (* GET_VertexAttribL1d(disp)) parameters
static inline _glptr_VertexAttribL1d GET_VertexAttribL1d(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL1d) (GET_by_offset(disp, _gloffset_VertexAttribL1d));
}

static inline void SET_VertexAttribL1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttribL1d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL1dv)(GLuint, const GLdouble *);
#define CALL_VertexAttribL1dv(disp, parameters) \
    (* GET_VertexAttribL1dv(disp)) parameters
static inline _glptr_VertexAttribL1dv GET_VertexAttribL1dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL1dv) (GET_by_offset(disp, _gloffset_VertexAttribL1dv));
}

static inline void SET_VertexAttribL1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribL1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL2d)(GLuint, GLdouble, GLdouble);
#define CALL_VertexAttribL2d(disp, parameters) \
    (* GET_VertexAttribL2d(disp)) parameters
static inline _glptr_VertexAttribL2d GET_VertexAttribL2d(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL2d) (GET_by_offset(disp, _gloffset_VertexAttribL2d));
}

static inline void SET_VertexAttribL2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttribL2d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL2dv)(GLuint, const GLdouble *);
#define CALL_VertexAttribL2dv(disp, parameters) \
    (* GET_VertexAttribL2dv(disp)) parameters
static inline _glptr_VertexAttribL2dv GET_VertexAttribL2dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL2dv) (GET_by_offset(disp, _gloffset_VertexAttribL2dv));
}

static inline void SET_VertexAttribL2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribL2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL3d)(GLuint, GLdouble, GLdouble, GLdouble);
#define CALL_VertexAttribL3d(disp, parameters) \
    (* GET_VertexAttribL3d(disp)) parameters
static inline _glptr_VertexAttribL3d GET_VertexAttribL3d(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL3d) (GET_by_offset(disp, _gloffset_VertexAttribL3d));
}

static inline void SET_VertexAttribL3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttribL3d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL3dv)(GLuint, const GLdouble *);
#define CALL_VertexAttribL3dv(disp, parameters) \
    (* GET_VertexAttribL3dv(disp)) parameters
static inline _glptr_VertexAttribL3dv GET_VertexAttribL3dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL3dv) (GET_by_offset(disp, _gloffset_VertexAttribL3dv));
}

static inline void SET_VertexAttribL3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribL3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_VertexAttribL4d(disp, parameters) \
    (* GET_VertexAttribL4d(disp)) parameters
static inline _glptr_VertexAttribL4d GET_VertexAttribL4d(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL4d) (GET_by_offset(disp, _gloffset_VertexAttribL4d));
}

static inline void SET_VertexAttribL4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttribL4d, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL4dv)(GLuint, const GLdouble *);
#define CALL_VertexAttribL4dv(disp, parameters) \
    (* GET_VertexAttribL4dv(disp)) parameters
static inline _glptr_VertexAttribL4dv GET_VertexAttribL4dv(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL4dv) (GET_by_offset(disp, _gloffset_VertexAttribL4dv));
}

static inline void SET_VertexAttribL4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribL4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribLPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_VertexAttribLPointer(disp, parameters) \
    (* GET_VertexAttribLPointer(disp)) parameters
static inline _glptr_VertexAttribLPointer GET_VertexAttribLPointer(struct _glapi_table *disp) {
   return (_glptr_VertexAttribLPointer) (GET_by_offset(disp, _gloffset_VertexAttribLPointer));
}

static inline void SET_VertexAttribLPointer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VertexAttribLPointer, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRangeArrayv)(GLuint, GLsizei, const GLclampd *);
#define CALL_DepthRangeArrayv(disp, parameters) \
    (* GET_DepthRangeArrayv(disp)) parameters
static inline _glptr_DepthRangeArrayv GET_DepthRangeArrayv(struct _glapi_table *disp) {
   return (_glptr_DepthRangeArrayv) (GET_by_offset(disp, _gloffset_DepthRangeArrayv));
}

static inline void SET_DepthRangeArrayv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLclampd *)) {
   SET_by_offset(disp, _gloffset_DepthRangeArrayv, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRangeIndexed)(GLuint, GLclampd, GLclampd);
#define CALL_DepthRangeIndexed(disp, parameters) \
    (* GET_DepthRangeIndexed(disp)) parameters
static inline _glptr_DepthRangeIndexed GET_DepthRangeIndexed(struct _glapi_table *disp) {
   return (_glptr_DepthRangeIndexed) (GET_by_offset(disp, _gloffset_DepthRangeIndexed));
}

static inline void SET_DepthRangeIndexed(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLclampd, GLclampd)) {
   SET_by_offset(disp, _gloffset_DepthRangeIndexed, fn);
}

typedef void (GLAPIENTRYP _glptr_GetDoublei_v)(GLenum, GLuint, GLdouble *);
#define CALL_GetDoublei_v(disp, parameters) \
    (* GET_GetDoublei_v(disp)) parameters
static inline _glptr_GetDoublei_v GET_GetDoublei_v(struct _glapi_table *disp) {
   return (_glptr_GetDoublei_v) (GET_by_offset(disp, _gloffset_GetDoublei_v));
}

static inline void SET_GetDoublei_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetDoublei_v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetFloati_v)(GLenum, GLuint, GLfloat *);
#define CALL_GetFloati_v(disp, parameters) \
    (* GET_GetFloati_v(disp)) parameters
static inline _glptr_GetFloati_v GET_GetFloati_v(struct _glapi_table *disp) {
   return (_glptr_GetFloati_v) (GET_by_offset(disp, _gloffset_GetFloati_v));
}

static inline void SET_GetFloati_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetFloati_v, fn);
}

typedef void (GLAPIENTRYP _glptr_ScissorArrayv)(GLuint, GLsizei, const int *);
#define CALL_ScissorArrayv(disp, parameters) \
    (* GET_ScissorArrayv(disp)) parameters
static inline _glptr_ScissorArrayv GET_ScissorArrayv(struct _glapi_table *disp) {
   return (_glptr_ScissorArrayv) (GET_by_offset(disp, _gloffset_ScissorArrayv));
}

static inline void SET_ScissorArrayv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const int *)) {
   SET_by_offset(disp, _gloffset_ScissorArrayv, fn);
}

typedef void (GLAPIENTRYP _glptr_ScissorIndexed)(GLuint, GLint, GLint, GLsizei, GLsizei);
#define CALL_ScissorIndexed(disp, parameters) \
    (* GET_ScissorIndexed(disp)) parameters
static inline _glptr_ScissorIndexed GET_ScissorIndexed(struct _glapi_table *disp) {
   return (_glptr_ScissorIndexed) (GET_by_offset(disp, _gloffset_ScissorIndexed));
}

static inline void SET_ScissorIndexed(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_ScissorIndexed, fn);
}

typedef void (GLAPIENTRYP _glptr_ScissorIndexedv)(GLuint, const GLint *);
#define CALL_ScissorIndexedv(disp, parameters) \
    (* GET_ScissorIndexedv(disp)) parameters
static inline _glptr_ScissorIndexedv GET_ScissorIndexedv(struct _glapi_table *disp) {
   return (_glptr_ScissorIndexedv) (GET_by_offset(disp, _gloffset_ScissorIndexedv));
}

static inline void SET_ScissorIndexedv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_ScissorIndexedv, fn);
}

typedef void (GLAPIENTRYP _glptr_ViewportArrayv)(GLuint, GLsizei, const GLfloat *);
#define CALL_ViewportArrayv(disp, parameters) \
    (* GET_ViewportArrayv(disp)) parameters
static inline _glptr_ViewportArrayv GET_ViewportArrayv(struct _glapi_table *disp) {
   return (_glptr_ViewportArrayv) (GET_by_offset(disp, _gloffset_ViewportArrayv));
}

static inline void SET_ViewportArrayv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ViewportArrayv, fn);
}

typedef void (GLAPIENTRYP _glptr_ViewportIndexedf)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_ViewportIndexedf(disp, parameters) \
    (* GET_ViewportIndexedf(disp)) parameters
static inline _glptr_ViewportIndexedf GET_ViewportIndexedf(struct _glapi_table *disp) {
   return (_glptr_ViewportIndexedf) (GET_by_offset(disp, _gloffset_ViewportIndexedf));
}

static inline void SET_ViewportIndexedf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ViewportIndexedf, fn);
}

typedef void (GLAPIENTRYP _glptr_ViewportIndexedfv)(GLuint, const GLfloat *);
#define CALL_ViewportIndexedfv(disp, parameters) \
    (* GET_ViewportIndexedfv(disp)) parameters
static inline _glptr_ViewportIndexedfv GET_ViewportIndexedfv(struct _glapi_table *disp) {
   return (_glptr_ViewportIndexedfv) (GET_by_offset(disp, _gloffset_ViewportIndexedfv));
}

static inline void SET_ViewportIndexedfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ViewportIndexedfv, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_GetGraphicsResetStatusARB)(void);
#define CALL_GetGraphicsResetStatusARB(disp, parameters) \
    (* GET_GetGraphicsResetStatusARB(disp)) parameters
static inline _glptr_GetGraphicsResetStatusARB GET_GetGraphicsResetStatusARB(struct _glapi_table *disp) {
   return (_glptr_GetGraphicsResetStatusARB) (GET_by_offset(disp, _gloffset_GetGraphicsResetStatusARB));
}

static inline void SET_GetGraphicsResetStatusARB(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_GetGraphicsResetStatusARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnColorTableARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetnColorTableARB(disp, parameters) \
    (* GET_GetnColorTableARB(disp)) parameters
static inline _glptr_GetnColorTableARB GET_GetnColorTableARB(struct _glapi_table *disp) {
   return (_glptr_GetnColorTableARB) (GET_by_offset(disp, _gloffset_GetnColorTableARB));
}

static inline void SET_GetnColorTableARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnColorTableARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnCompressedTexImageARB)(GLenum, GLint, GLsizei, GLvoid *);
#define CALL_GetnCompressedTexImageARB(disp, parameters) \
    (* GET_GetnCompressedTexImageARB(disp)) parameters
static inline _glptr_GetnCompressedTexImageARB GET_GetnCompressedTexImageARB(struct _glapi_table *disp) {
   return (_glptr_GetnCompressedTexImageARB) (GET_by_offset(disp, _gloffset_GetnCompressedTexImageARB));
}

static inline void SET_GetnCompressedTexImageARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnCompressedTexImageARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnConvolutionFilterARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetnConvolutionFilterARB(disp, parameters) \
    (* GET_GetnConvolutionFilterARB(disp)) parameters
static inline _glptr_GetnConvolutionFilterARB GET_GetnConvolutionFilterARB(struct _glapi_table *disp) {
   return (_glptr_GetnConvolutionFilterARB) (GET_by_offset(disp, _gloffset_GetnConvolutionFilterARB));
}

static inline void SET_GetnConvolutionFilterARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnConvolutionFilterARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnHistogramARB)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetnHistogramARB(disp, parameters) \
    (* GET_GetnHistogramARB(disp)) parameters
static inline _glptr_GetnHistogramARB GET_GetnHistogramARB(struct _glapi_table *disp) {
   return (_glptr_GetnHistogramARB) (GET_by_offset(disp, _gloffset_GetnHistogramARB));
}

static inline void SET_GetnHistogramARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnHistogramARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnMapdvARB)(GLenum, GLenum, GLsizei, GLdouble *);
#define CALL_GetnMapdvARB(disp, parameters) \
    (* GET_GetnMapdvARB(disp)) parameters
static inline _glptr_GetnMapdvARB GET_GetnMapdvARB(struct _glapi_table *disp) {
   return (_glptr_GetnMapdvARB) (GET_by_offset(disp, _gloffset_GetnMapdvARB));
}

static inline void SET_GetnMapdvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetnMapdvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnMapfvARB)(GLenum, GLenum, GLsizei, GLfloat *);
#define CALL_GetnMapfvARB(disp, parameters) \
    (* GET_GetnMapfvARB(disp)) parameters
static inline _glptr_GetnMapfvARB GET_GetnMapfvARB(struct _glapi_table *disp) {
   return (_glptr_GetnMapfvARB) (GET_by_offset(disp, _gloffset_GetnMapfvARB));
}

static inline void SET_GetnMapfvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetnMapfvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnMapivARB)(GLenum, GLenum, GLsizei, GLint *);
#define CALL_GetnMapivARB(disp, parameters) \
    (* GET_GetnMapivARB(disp)) parameters
static inline _glptr_GetnMapivARB GET_GetnMapivARB(struct _glapi_table *disp) {
   return (_glptr_GetnMapivARB) (GET_by_offset(disp, _gloffset_GetnMapivARB));
}

static inline void SET_GetnMapivARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLsizei, GLint *)) {
   SET_by_offset(disp, _gloffset_GetnMapivARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnMinmaxARB)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetnMinmaxARB(disp, parameters) \
    (* GET_GetnMinmaxARB(disp)) parameters
static inline _glptr_GetnMinmaxARB GET_GetnMinmaxARB(struct _glapi_table *disp) {
   return (_glptr_GetnMinmaxARB) (GET_by_offset(disp, _gloffset_GetnMinmaxARB));
}

static inline void SET_GetnMinmaxARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnMinmaxARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnPixelMapfvARB)(GLenum, GLsizei, GLfloat *);
#define CALL_GetnPixelMapfvARB(disp, parameters) \
    (* GET_GetnPixelMapfvARB(disp)) parameters
static inline _glptr_GetnPixelMapfvARB GET_GetnPixelMapfvARB(struct _glapi_table *disp) {
   return (_glptr_GetnPixelMapfvARB) (GET_by_offset(disp, _gloffset_GetnPixelMapfvARB));
}

static inline void SET_GetnPixelMapfvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetnPixelMapfvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnPixelMapuivARB)(GLenum, GLsizei, GLuint *);
#define CALL_GetnPixelMapuivARB(disp, parameters) \
    (* GET_GetnPixelMapuivARB(disp)) parameters
static inline _glptr_GetnPixelMapuivARB GET_GetnPixelMapuivARB(struct _glapi_table *disp) {
   return (_glptr_GetnPixelMapuivARB) (GET_by_offset(disp, _gloffset_GetnPixelMapuivARB));
}

static inline void SET_GetnPixelMapuivARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetnPixelMapuivARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnPixelMapusvARB)(GLenum, GLsizei, GLushort *);
#define CALL_GetnPixelMapusvARB(disp, parameters) \
    (* GET_GetnPixelMapusvARB(disp)) parameters
static inline _glptr_GetnPixelMapusvARB GET_GetnPixelMapusvARB(struct _glapi_table *disp) {
   return (_glptr_GetnPixelMapusvARB) (GET_by_offset(disp, _gloffset_GetnPixelMapusvARB));
}

static inline void SET_GetnPixelMapusvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLushort *)) {
   SET_by_offset(disp, _gloffset_GetnPixelMapusvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnPolygonStippleARB)(GLsizei, GLubyte *);
#define CALL_GetnPolygonStippleARB(disp, parameters) \
    (* GET_GetnPolygonStippleARB(disp)) parameters
static inline _glptr_GetnPolygonStippleARB GET_GetnPolygonStippleARB(struct _glapi_table *disp) {
   return (_glptr_GetnPolygonStippleARB) (GET_by_offset(disp, _gloffset_GetnPolygonStippleARB));
}

static inline void SET_GetnPolygonStippleARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLubyte *)) {
   SET_by_offset(disp, _gloffset_GetnPolygonStippleARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnSeparableFilterARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *, GLsizei, GLvoid *, GLvoid *);
#define CALL_GetnSeparableFilterARB(disp, parameters) \
    (* GET_GetnSeparableFilterARB(disp)) parameters
static inline _glptr_GetnSeparableFilterARB GET_GetnSeparableFilterARB(struct _glapi_table *disp) {
   return (_glptr_GetnSeparableFilterARB) (GET_by_offset(disp, _gloffset_GetnSeparableFilterARB));
}

static inline void SET_GetnSeparableFilterARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLsizei, GLvoid *, GLsizei, GLvoid *, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnSeparableFilterARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnTexImageARB)(GLenum, GLint, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetnTexImageARB(disp, parameters) \
    (* GET_GetnTexImageARB(disp)) parameters
static inline _glptr_GetnTexImageARB GET_GetnTexImageARB(struct _glapi_table *disp) {
   return (_glptr_GetnTexImageARB) (GET_by_offset(disp, _gloffset_GetnTexImageARB));
}

static inline void SET_GetnTexImageARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetnTexImageARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnUniformdvARB)(GLuint, GLint, GLsizei, GLdouble *);
#define CALL_GetnUniformdvARB(disp, parameters) \
    (* GET_GetnUniformdvARB(disp)) parameters
static inline _glptr_GetnUniformdvARB GET_GetnUniformdvARB(struct _glapi_table *disp) {
   return (_glptr_GetnUniformdvARB) (GET_by_offset(disp, _gloffset_GetnUniformdvARB));
}

static inline void SET_GetnUniformdvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetnUniformdvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnUniformfvARB)(GLuint, GLint, GLsizei, GLfloat *);
#define CALL_GetnUniformfvARB(disp, parameters) \
    (* GET_GetnUniformfvARB(disp)) parameters
static inline _glptr_GetnUniformfvARB GET_GetnUniformfvARB(struct _glapi_table *disp) {
   return (_glptr_GetnUniformfvARB) (GET_by_offset(disp, _gloffset_GetnUniformfvARB));
}

static inline void SET_GetnUniformfvARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetnUniformfvARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnUniformivARB)(GLuint, GLint, GLsizei, GLint *);
#define CALL_GetnUniformivARB(disp, parameters) \
    (* GET_GetnUniformivARB(disp)) parameters
static inline _glptr_GetnUniformivARB GET_GetnUniformivARB(struct _glapi_table *disp) {
   return (_glptr_GetnUniformivARB) (GET_by_offset(disp, _gloffset_GetnUniformivARB));
}

static inline void SET_GetnUniformivARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLint *)) {
   SET_by_offset(disp, _gloffset_GetnUniformivARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnUniformuivARB)(GLuint, GLint, GLsizei, GLuint *);
#define CALL_GetnUniformuivARB(disp, parameters) \
    (* GET_GetnUniformuivARB(disp)) parameters
static inline _glptr_GetnUniformuivARB GET_GetnUniformuivARB(struct _glapi_table *disp) {
   return (_glptr_GetnUniformuivARB) (GET_by_offset(disp, _gloffset_GetnUniformuivARB));
}

static inline void SET_GetnUniformuivARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetnUniformuivARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ReadnPixelsARB)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_ReadnPixelsARB(disp, parameters) \
    (* GET_ReadnPixelsARB(disp)) parameters
static inline _glptr_ReadnPixelsARB GET_ReadnPixelsARB(struct _glapi_table *disp) {
   return (_glptr_ReadnPixelsARB) (GET_by_offset(disp, _gloffset_ReadnPixelsARB));
}

static inline void SET_ReadnPixelsARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_ReadnPixelsARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawArraysInstancedBaseInstance)(GLenum, GLint, GLsizei, GLsizei, GLuint);
#define CALL_DrawArraysInstancedBaseInstance(disp, parameters) \
    (* GET_DrawArraysInstancedBaseInstance(disp)) parameters
static inline _glptr_DrawArraysInstancedBaseInstance GET_DrawArraysInstancedBaseInstance(struct _glapi_table *disp) {
   return (_glptr_DrawArraysInstancedBaseInstance) (GET_by_offset(disp, _gloffset_DrawArraysInstancedBaseInstance));
}

static inline void SET_DrawArraysInstancedBaseInstance(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint, GLsizei, GLsizei, GLuint)) {
   SET_by_offset(disp, _gloffset_DrawArraysInstancedBaseInstance, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElementsInstancedBaseInstance)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLuint);
#define CALL_DrawElementsInstancedBaseInstance(disp, parameters) \
    (* GET_DrawElementsInstancedBaseInstance(disp)) parameters
static inline _glptr_DrawElementsInstancedBaseInstance GET_DrawElementsInstancedBaseInstance(struct _glapi_table *disp) {
   return (_glptr_DrawElementsInstancedBaseInstance) (GET_by_offset(disp, _gloffset_DrawElementsInstancedBaseInstance));
}

static inline void SET_DrawElementsInstancedBaseInstance(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLuint)) {
   SET_by_offset(disp, _gloffset_DrawElementsInstancedBaseInstance, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawElementsInstancedBaseVertexBaseInstance)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint, GLuint);
#define CALL_DrawElementsInstancedBaseVertexBaseInstance(disp, parameters) \
    (* GET_DrawElementsInstancedBaseVertexBaseInstance(disp)) parameters
static inline _glptr_DrawElementsInstancedBaseVertexBaseInstance GET_DrawElementsInstancedBaseVertexBaseInstance(struct _glapi_table *disp) {
   return (_glptr_DrawElementsInstancedBaseVertexBaseInstance) (GET_by_offset(disp, _gloffset_DrawElementsInstancedBaseVertexBaseInstance));
}

static inline void SET_DrawElementsInstancedBaseVertexBaseInstance(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint, GLuint)) {
   SET_by_offset(disp, _gloffset_DrawElementsInstancedBaseVertexBaseInstance, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTransformFeedbackInstanced)(GLenum, GLuint, GLsizei);
#define CALL_DrawTransformFeedbackInstanced(disp, parameters) \
    (* GET_DrawTransformFeedbackInstanced(disp)) parameters
static inline _glptr_DrawTransformFeedbackInstanced GET_DrawTransformFeedbackInstanced(struct _glapi_table *disp) {
   return (_glptr_DrawTransformFeedbackInstanced) (GET_by_offset(disp, _gloffset_DrawTransformFeedbackInstanced));
}

static inline void SET_DrawTransformFeedbackInstanced(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei)) {
   SET_by_offset(disp, _gloffset_DrawTransformFeedbackInstanced, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTransformFeedbackStreamInstanced)(GLenum, GLuint, GLuint, GLsizei);
#define CALL_DrawTransformFeedbackStreamInstanced(disp, parameters) \
    (* GET_DrawTransformFeedbackStreamInstanced(disp)) parameters
static inline _glptr_DrawTransformFeedbackStreamInstanced GET_DrawTransformFeedbackStreamInstanced(struct _glapi_table *disp) {
   return (_glptr_DrawTransformFeedbackStreamInstanced) (GET_by_offset(disp, _gloffset_DrawTransformFeedbackStreamInstanced));
}

static inline void SET_DrawTransformFeedbackStreamInstanced(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLsizei)) {
   SET_by_offset(disp, _gloffset_DrawTransformFeedbackStreamInstanced, fn);
}

typedef void (GLAPIENTRYP _glptr_GetInternalformativ)(GLenum, GLenum, GLenum, GLsizei, GLint *);
#define CALL_GetInternalformativ(disp, parameters) \
    (* GET_GetInternalformativ(disp)) parameters
static inline _glptr_GetInternalformativ GET_GetInternalformativ(struct _glapi_table *disp) {
   return (_glptr_GetInternalformativ) (GET_by_offset(disp, _gloffset_GetInternalformativ));
}

static inline void SET_GetInternalformativ(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLsizei, GLint *)) {
   SET_by_offset(disp, _gloffset_GetInternalformativ, fn);
}

typedef void (GLAPIENTRYP _glptr_GetActiveAtomicCounterBufferiv)(GLuint, GLuint, GLenum, GLint *);
#define CALL_GetActiveAtomicCounterBufferiv(disp, parameters) \
    (* GET_GetActiveAtomicCounterBufferiv(disp)) parameters
static inline _glptr_GetActiveAtomicCounterBufferiv GET_GetActiveAtomicCounterBufferiv(struct _glapi_table *disp) {
   return (_glptr_GetActiveAtomicCounterBufferiv) (GET_by_offset(disp, _gloffset_GetActiveAtomicCounterBufferiv));
}

static inline void SET_GetActiveAtomicCounterBufferiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetActiveAtomicCounterBufferiv, fn);
}

typedef void (GLAPIENTRYP _glptr_BindImageTexture)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum);
#define CALL_BindImageTexture(disp, parameters) \
    (* GET_BindImageTexture(disp)) parameters
static inline _glptr_BindImageTexture GET_BindImageTexture(struct _glapi_table *disp) {
   return (_glptr_BindImageTexture) (GET_by_offset(disp, _gloffset_BindImageTexture));
}

static inline void SET_BindImageTexture(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_BindImageTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_MemoryBarrier)(GLbitfield);
#define CALL_MemoryBarrier(disp, parameters) \
    (* GET_MemoryBarrier(disp)) parameters
static inline _glptr_MemoryBarrier GET_MemoryBarrier(struct _glapi_table *disp) {
   return (_glptr_MemoryBarrier) (GET_by_offset(disp, _gloffset_MemoryBarrier));
}

static inline void SET_MemoryBarrier(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLbitfield)) {
   SET_by_offset(disp, _gloffset_MemoryBarrier, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorage1D)(GLenum, GLsizei, GLenum, GLsizei);
#define CALL_TexStorage1D(disp, parameters) \
    (* GET_TexStorage1D(disp)) parameters
static inline _glptr_TexStorage1D GET_TexStorage1D(struct _glapi_table *disp) {
   return (_glptr_TexStorage1D) (GET_by_offset(disp, _gloffset_TexStorage1D));
}

static inline void SET_TexStorage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei)) {
   SET_by_offset(disp, _gloffset_TexStorage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorage2D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define CALL_TexStorage2D(disp, parameters) \
    (* GET_TexStorage2D(disp)) parameters
static inline _glptr_TexStorage2D GET_TexStorage2D(struct _glapi_table *disp) {
   return (_glptr_TexStorage2D) (GET_by_offset(disp, _gloffset_TexStorage2D));
}

static inline void SET_TexStorage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_TexStorage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorage3D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
#define CALL_TexStorage3D(disp, parameters) \
    (* GET_TexStorage3D(disp)) parameters
static inline _glptr_TexStorage3D GET_TexStorage3D(struct _glapi_table *disp) {
   return (_glptr_TexStorage3D) (GET_by_offset(disp, _gloffset_TexStorage3D));
}

static inline void SET_TexStorage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_TexStorage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage1DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei);
#define CALL_TextureStorage1DEXT(disp, parameters) \
    (* GET_TextureStorage1DEXT(disp)) parameters
static inline _glptr_TextureStorage1DEXT GET_TextureStorage1DEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorage1DEXT) (GET_by_offset(disp, _gloffset_TextureStorage1DEXT));
}

static inline void SET_TextureStorage1DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLsizei, GLenum, GLsizei)) {
   SET_by_offset(disp, _gloffset_TextureStorage1DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage2DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define CALL_TextureStorage2DEXT(disp, parameters) \
    (* GET_TextureStorage2DEXT(disp)) parameters
static inline _glptr_TextureStorage2DEXT GET_TextureStorage2DEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorage2DEXT) (GET_by_offset(disp, _gloffset_TextureStorage2DEXT));
}

static inline void SET_TextureStorage2DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_TextureStorage2DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage3DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
#define CALL_TextureStorage3DEXT(disp, parameters) \
    (* GET_TextureStorage3DEXT(disp)) parameters
static inline _glptr_TextureStorage3DEXT GET_TextureStorage3DEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorage3DEXT) (GET_by_offset(disp, _gloffset_TextureStorage3DEXT));
}

static inline void SET_TextureStorage3DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_TextureStorage3DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearBufferData)(GLenum, GLenum, GLenum, GLenum, const GLvoid *);
#define CALL_ClearBufferData(disp, parameters) \
    (* GET_ClearBufferData(disp)) parameters
static inline _glptr_ClearBufferData GET_ClearBufferData(struct _glapi_table *disp) {
   return (_glptr_ClearBufferData) (GET_by_offset(disp, _gloffset_ClearBufferData));
}

static inline void SET_ClearBufferData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ClearBufferData, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearBufferSubData)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const GLvoid *);
#define CALL_ClearBufferSubData(disp, parameters) \
    (* GET_ClearBufferSubData(disp)) parameters
static inline _glptr_ClearBufferSubData GET_ClearBufferSubData(struct _glapi_table *disp) {
   return (_glptr_ClearBufferSubData) (GET_by_offset(disp, _gloffset_ClearBufferSubData));
}

static inline void SET_ClearBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ClearBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_DispatchCompute)(GLuint, GLuint, GLuint);
#define CALL_DispatchCompute(disp, parameters) \
    (* GET_DispatchCompute(disp)) parameters
static inline _glptr_DispatchCompute GET_DispatchCompute(struct _glapi_table *disp) {
   return (_glptr_DispatchCompute) (GET_by_offset(disp, _gloffset_DispatchCompute));
}

static inline void SET_DispatchCompute(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_DispatchCompute, fn);
}

typedef void (GLAPIENTRYP _glptr_DispatchComputeIndirect)(GLintptr);
#define CALL_DispatchComputeIndirect(disp, parameters) \
    (* GET_DispatchComputeIndirect(disp)) parameters
static inline _glptr_DispatchComputeIndirect GET_DispatchComputeIndirect(struct _glapi_table *disp) {
   return (_glptr_DispatchComputeIndirect) (GET_by_offset(disp, _gloffset_DispatchComputeIndirect));
}

static inline void SET_DispatchComputeIndirect(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLintptr)) {
   SET_by_offset(disp, _gloffset_DispatchComputeIndirect, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyImageSubData)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define CALL_CopyImageSubData(disp, parameters) \
    (* GET_CopyImageSubData(disp)) parameters
static inline _glptr_CopyImageSubData GET_CopyImageSubData(struct _glapi_table *disp) {
   return (_glptr_CopyImageSubData) (GET_by_offset(disp, _gloffset_CopyImageSubData));
}

static inline void SET_CopyImageSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyImageSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureView)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint);
#define CALL_TextureView(disp, parameters) \
    (* GET_TextureView(disp)) parameters
static inline _glptr_TextureView GET_TextureView(struct _glapi_table *disp) {
   return (_glptr_TextureView) (GET_by_offset(disp, _gloffset_TextureView));
}

static inline void SET_TextureView(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_TextureView, fn);
}

typedef void (GLAPIENTRYP _glptr_BindVertexBuffer)(GLuint, GLuint, GLintptr, GLsizei);
#define CALL_BindVertexBuffer(disp, parameters) \
    (* GET_BindVertexBuffer(disp)) parameters
static inline _glptr_BindVertexBuffer GET_BindVertexBuffer(struct _glapi_table *disp) {
   return (_glptr_BindVertexBuffer) (GET_by_offset(disp, _gloffset_BindVertexBuffer));
}

static inline void SET_BindVertexBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLintptr, GLsizei)) {
   SET_by_offset(disp, _gloffset_BindVertexBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribBinding)(GLuint, GLuint);
#define CALL_VertexAttribBinding(disp, parameters) \
    (* GET_VertexAttribBinding(disp)) parameters
static inline _glptr_VertexAttribBinding GET_VertexAttribBinding(struct _glapi_table *disp) {
   return (_glptr_VertexAttribBinding) (GET_by_offset(disp, _gloffset_VertexAttribBinding));
}

static inline void SET_VertexAttribBinding(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribBinding, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribFormat)(GLuint, GLint, GLenum, GLboolean, GLuint);
#define CALL_VertexAttribFormat(disp, parameters) \
    (* GET_VertexAttribFormat(disp)) parameters
static inline _glptr_VertexAttribFormat GET_VertexAttribFormat(struct _glapi_table *disp) {
   return (_glptr_VertexAttribFormat) (GET_by_offset(disp, _gloffset_VertexAttribFormat));
}

static inline void SET_VertexAttribFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLboolean, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribIFormat)(GLuint, GLint, GLenum, GLuint);
#define CALL_VertexAttribIFormat(disp, parameters) \
    (* GET_VertexAttribIFormat(disp)) parameters
static inline _glptr_VertexAttribIFormat GET_VertexAttribIFormat(struct _glapi_table *disp) {
   return (_glptr_VertexAttribIFormat) (GET_by_offset(disp, _gloffset_VertexAttribIFormat));
}

static inline void SET_VertexAttribIFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribIFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribLFormat)(GLuint, GLint, GLenum, GLuint);
#define CALL_VertexAttribLFormat(disp, parameters) \
    (* GET_VertexAttribLFormat(disp)) parameters
static inline _glptr_VertexAttribLFormat GET_VertexAttribLFormat(struct _glapi_table *disp) {
   return (_glptr_VertexAttribLFormat) (GET_by_offset(disp, _gloffset_VertexAttribLFormat));
}

static inline void SET_VertexAttribLFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribLFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexBindingDivisor)(GLuint, GLuint);
#define CALL_VertexBindingDivisor(disp, parameters) \
    (* GET_VertexBindingDivisor(disp)) parameters
static inline _glptr_VertexBindingDivisor GET_VertexBindingDivisor(struct _glapi_table *disp) {
   return (_glptr_VertexBindingDivisor) (GET_by_offset(disp, _gloffset_VertexBindingDivisor));
}

static inline void SET_VertexBindingDivisor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexBindingDivisor, fn);
}

typedef void (GLAPIENTRYP _glptr_FramebufferParameteri)(GLenum, GLenum, GLint);
#define CALL_FramebufferParameteri(disp, parameters) \
    (* GET_FramebufferParameteri(disp)) parameters
static inline _glptr_FramebufferParameteri GET_FramebufferParameteri(struct _glapi_table *disp) {
   return (_glptr_FramebufferParameteri) (GET_by_offset(disp, _gloffset_FramebufferParameteri));
}

static inline void SET_FramebufferParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_FramebufferParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_GetFramebufferParameteriv)(GLenum, GLenum, GLint *);
#define CALL_GetFramebufferParameteriv(disp, parameters) \
    (* GET_GetFramebufferParameteriv(disp)) parameters
static inline _glptr_GetFramebufferParameteriv GET_GetFramebufferParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetFramebufferParameteriv) (GET_by_offset(disp, _gloffset_GetFramebufferParameteriv));
}

static inline void SET_GetFramebufferParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetFramebufferParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetInternalformati64v)(GLenum, GLenum, GLenum, GLsizei, GLint64 *);
#define CALL_GetInternalformati64v(disp, parameters) \
    (* GET_GetInternalformati64v(disp)) parameters
static inline _glptr_GetInternalformati64v GET_GetInternalformati64v(struct _glapi_table *disp) {
   return (_glptr_GetInternalformati64v) (GET_by_offset(disp, _gloffset_GetInternalformati64v));
}

static inline void SET_GetInternalformati64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLsizei, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetInternalformati64v, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawArraysIndirect)(GLenum, const GLvoid *, GLsizei, GLsizei);
#define CALL_MultiDrawArraysIndirect(disp, parameters) \
    (* GET_MultiDrawArraysIndirect(disp)) parameters
static inline _glptr_MultiDrawArraysIndirect GET_MultiDrawArraysIndirect(struct _glapi_table *disp) {
   return (_glptr_MultiDrawArraysIndirect) (GET_by_offset(disp, _gloffset_MultiDrawArraysIndirect));
}

static inline void SET_MultiDrawArraysIndirect(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLvoid *, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_MultiDrawArraysIndirect, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawElementsIndirect)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei);
#define CALL_MultiDrawElementsIndirect(disp, parameters) \
    (* GET_MultiDrawElementsIndirect(disp)) parameters
static inline _glptr_MultiDrawElementsIndirect GET_MultiDrawElementsIndirect(struct _glapi_table *disp) {
   return (_glptr_MultiDrawElementsIndirect) (GET_by_offset(disp, _gloffset_MultiDrawElementsIndirect));
}

static inline void SET_MultiDrawElementsIndirect(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_MultiDrawElementsIndirect, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramInterfaceiv)(GLuint, GLenum, GLenum, GLint *);
#define CALL_GetProgramInterfaceiv(disp, parameters) \
    (* GET_GetProgramInterfaceiv(disp)) parameters
static inline _glptr_GetProgramInterfaceiv GET_GetProgramInterfaceiv(struct _glapi_table *disp) {
   return (_glptr_GetProgramInterfaceiv) (GET_by_offset(disp, _gloffset_GetProgramInterfaceiv));
}

static inline void SET_GetProgramInterfaceiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramInterfaceiv, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_GetProgramResourceIndex)(GLuint, GLenum, const GLchar *);
#define CALL_GetProgramResourceIndex(disp, parameters) \
    (* GET_GetProgramResourceIndex(disp)) parameters
static inline _glptr_GetProgramResourceIndex GET_GetProgramResourceIndex(struct _glapi_table *disp) {
   return (_glptr_GetProgramResourceIndex) (GET_by_offset(disp, _gloffset_GetProgramResourceIndex));
}

static inline void SET_GetProgramResourceIndex(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLuint, GLenum, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetProgramResourceIndex, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetProgramResourceLocation)(GLuint, GLenum, const GLchar *);
#define CALL_GetProgramResourceLocation(disp, parameters) \
    (* GET_GetProgramResourceLocation(disp)) parameters
static inline _glptr_GetProgramResourceLocation GET_GetProgramResourceLocation(struct _glapi_table *disp) {
   return (_glptr_GetProgramResourceLocation) (GET_by_offset(disp, _gloffset_GetProgramResourceLocation));
}

static inline void SET_GetProgramResourceLocation(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, GLenum, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetProgramResourceLocation, fn);
}

typedef GLint (GLAPIENTRYP _glptr_GetProgramResourceLocationIndex)(GLuint, GLenum, const GLchar *);
#define CALL_GetProgramResourceLocationIndex(disp, parameters) \
    (* GET_GetProgramResourceLocationIndex(disp)) parameters
static inline _glptr_GetProgramResourceLocationIndex GET_GetProgramResourceLocationIndex(struct _glapi_table *disp) {
   return (_glptr_GetProgramResourceLocationIndex) (GET_by_offset(disp, _gloffset_GetProgramResourceLocationIndex));
}

static inline void SET_GetProgramResourceLocationIndex(struct _glapi_table *disp, GLint (GLAPIENTRYP fn)(GLuint, GLenum, const GLchar *)) {
   SET_by_offset(disp, _gloffset_GetProgramResourceLocationIndex, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramResourceName)(GLuint, GLenum, GLuint, GLsizei , GLsizei *, GLchar *);
#define CALL_GetProgramResourceName(disp, parameters) \
    (* GET_GetProgramResourceName(disp)) parameters
static inline _glptr_GetProgramResourceName GET_GetProgramResourceName(struct _glapi_table *disp) {
   return (_glptr_GetProgramResourceName) (GET_by_offset(disp, _gloffset_GetProgramResourceName));
}

static inline void SET_GetProgramResourceName(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLsizei , GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetProgramResourceName, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramResourceiv)(GLuint, GLenum, GLuint, GLsizei , const GLenum *, GLsizei , GLsizei *, GLint *);
#define CALL_GetProgramResourceiv(disp, parameters) \
    (* GET_GetProgramResourceiv(disp)) parameters
static inline _glptr_GetProgramResourceiv GET_GetProgramResourceiv(struct _glapi_table *disp) {
   return (_glptr_GetProgramResourceiv) (GET_by_offset(disp, _gloffset_GetProgramResourceiv));
}

static inline void SET_GetProgramResourceiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLsizei , const GLenum *, GLsizei , GLsizei *, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramResourceiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ShaderStorageBlockBinding)(GLuint, GLuint, GLuint);
#define CALL_ShaderStorageBlockBinding(disp, parameters) \
    (* GET_ShaderStorageBlockBinding(disp)) parameters
static inline _glptr_ShaderStorageBlockBinding GET_ShaderStorageBlockBinding(struct _glapi_table *disp) {
   return (_glptr_ShaderStorageBlockBinding) (GET_by_offset(disp, _gloffset_ShaderStorageBlockBinding));
}

static inline void SET_ShaderStorageBlockBinding(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ShaderStorageBlockBinding, fn);
}

typedef void (GLAPIENTRYP _glptr_TexBufferRange)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr);
#define CALL_TexBufferRange(disp, parameters) \
    (* GET_TexBufferRange(disp)) parameters
static inline _glptr_TexBufferRange GET_TexBufferRange(struct _glapi_table *disp) {
   return (_glptr_TexBufferRange) (GET_by_offset(disp, _gloffset_TexBufferRange));
}

static inline void SET_TexBufferRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_TexBufferRange, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorage2DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
#define CALL_TexStorage2DMultisample(disp, parameters) \
    (* GET_TexStorage2DMultisample(disp)) parameters
static inline _glptr_TexStorage2DMultisample GET_TexStorage2DMultisample(struct _glapi_table *disp) {
   return (_glptr_TexStorage2DMultisample) (GET_by_offset(disp, _gloffset_TexStorage2DMultisample));
}

static inline void SET_TexStorage2DMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)) {
   SET_by_offset(disp, _gloffset_TexStorage2DMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorage3DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
#define CALL_TexStorage3DMultisample(disp, parameters) \
    (* GET_TexStorage3DMultisample(disp)) parameters
static inline _glptr_TexStorage3DMultisample GET_TexStorage3DMultisample(struct _glapi_table *disp) {
   return (_glptr_TexStorage3DMultisample) (GET_by_offset(disp, _gloffset_TexStorage3DMultisample));
}

static inline void SET_TexStorage3DMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)) {
   SET_by_offset(disp, _gloffset_TexStorage3DMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_BufferStorage)(GLenum, GLsizeiptr, const GLvoid *, GLbitfield);
#define CALL_BufferStorage(disp, parameters) \
    (* GET_BufferStorage(disp)) parameters
static inline _glptr_BufferStorage GET_BufferStorage(struct _glapi_table *disp) {
   return (_glptr_BufferStorage) (GET_by_offset(disp, _gloffset_BufferStorage));
}

static inline void SET_BufferStorage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizeiptr, const GLvoid *, GLbitfield)) {
   SET_by_offset(disp, _gloffset_BufferStorage, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearTexImage)(GLuint, GLint, GLenum, GLenum, const GLvoid *);
#define CALL_ClearTexImage(disp, parameters) \
    (* GET_ClearTexImage(disp)) parameters
static inline _glptr_ClearTexImage GET_ClearTexImage(struct _glapi_table *disp) {
   return (_glptr_ClearTexImage) (GET_by_offset(disp, _gloffset_ClearTexImage));
}

static inline void SET_ClearTexImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ClearTexImage, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_ClearTexSubImage(disp, parameters) \
    (* GET_ClearTexSubImage(disp)) parameters
static inline _glptr_ClearTexSubImage GET_ClearTexSubImage(struct _glapi_table *disp) {
   return (_glptr_ClearTexSubImage) (GET_by_offset(disp, _gloffset_ClearTexSubImage));
}

static inline void SET_ClearTexSubImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ClearTexSubImage, fn);
}

typedef void (GLAPIENTRYP _glptr_BindBuffersBase)(GLenum, GLuint, GLsizei, const GLuint *);
#define CALL_BindBuffersBase(disp, parameters) \
    (* GET_BindBuffersBase(disp)) parameters
static inline _glptr_BindBuffersBase GET_BindBuffersBase(struct _glapi_table *disp) {
   return (_glptr_BindBuffersBase) (GET_by_offset(disp, _gloffset_BindBuffersBase));
}

static inline void SET_BindBuffersBase(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_BindBuffersBase, fn);
}

typedef void (GLAPIENTRYP _glptr_BindBuffersRange)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *);
#define CALL_BindBuffersRange(disp, parameters) \
    (* GET_BindBuffersRange(disp)) parameters
static inline _glptr_BindBuffersRange GET_BindBuffersRange(struct _glapi_table *disp) {
   return (_glptr_BindBuffersRange) (GET_by_offset(disp, _gloffset_BindBuffersRange));
}

static inline void SET_BindBuffersRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *)) {
   SET_by_offset(disp, _gloffset_BindBuffersRange, fn);
}

typedef void (GLAPIENTRYP _glptr_BindImageTextures)(GLuint, GLsizei, const GLuint *);
#define CALL_BindImageTextures(disp, parameters) \
    (* GET_BindImageTextures(disp)) parameters
static inline _glptr_BindImageTextures GET_BindImageTextures(struct _glapi_table *disp) {
   return (_glptr_BindImageTextures) (GET_by_offset(disp, _gloffset_BindImageTextures));
}

static inline void SET_BindImageTextures(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_BindImageTextures, fn);
}

typedef void (GLAPIENTRYP _glptr_BindSamplers)(GLuint, GLsizei, const GLuint *);
#define CALL_BindSamplers(disp, parameters) \
    (* GET_BindSamplers(disp)) parameters
static inline _glptr_BindSamplers GET_BindSamplers(struct _glapi_table *disp) {
   return (_glptr_BindSamplers) (GET_by_offset(disp, _gloffset_BindSamplers));
}

static inline void SET_BindSamplers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_BindSamplers, fn);
}

typedef void (GLAPIENTRYP _glptr_BindTextures)(GLuint, GLsizei, const GLuint *);
#define CALL_BindTextures(disp, parameters) \
    (* GET_BindTextures(disp)) parameters
static inline _glptr_BindTextures GET_BindTextures(struct _glapi_table *disp) {
   return (_glptr_BindTextures) (GET_by_offset(disp, _gloffset_BindTextures));
}

static inline void SET_BindTextures(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_BindTextures, fn);
}

typedef void (GLAPIENTRYP _glptr_BindVertexBuffers)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *);
#define CALL_BindVertexBuffers(disp, parameters) \
    (* GET_BindVertexBuffers(disp)) parameters
static inline _glptr_BindVertexBuffers GET_BindVertexBuffers(struct _glapi_table *disp) {
   return (_glptr_BindVertexBuffers) (GET_by_offset(disp, _gloffset_BindVertexBuffers));
}

static inline void SET_BindVertexBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *)) {
   SET_by_offset(disp, _gloffset_BindVertexBuffers, fn);
}

typedef GLuint64 (GLAPIENTRYP _glptr_GetImageHandleARB)(GLuint, GLint, GLboolean, GLint, GLenum);
#define CALL_GetImageHandleARB(disp, parameters) \
    (* GET_GetImageHandleARB(disp)) parameters
static inline _glptr_GetImageHandleARB GET_GetImageHandleARB(struct _glapi_table *disp) {
   return (_glptr_GetImageHandleARB) (GET_by_offset(disp, _gloffset_GetImageHandleARB));
}

static inline void SET_GetImageHandleARB(struct _glapi_table *disp, GLuint64 (GLAPIENTRYP fn)(GLuint, GLint, GLboolean, GLint, GLenum)) {
   SET_by_offset(disp, _gloffset_GetImageHandleARB, fn);
}

typedef GLuint64 (GLAPIENTRYP _glptr_GetTextureHandleARB)(GLuint);
#define CALL_GetTextureHandleARB(disp, parameters) \
    (* GET_GetTextureHandleARB(disp)) parameters
static inline _glptr_GetTextureHandleARB GET_GetTextureHandleARB(struct _glapi_table *disp) {
   return (_glptr_GetTextureHandleARB) (GET_by_offset(disp, _gloffset_GetTextureHandleARB));
}

static inline void SET_GetTextureHandleARB(struct _glapi_table *disp, GLuint64 (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_GetTextureHandleARB, fn);
}

typedef GLuint64 (GLAPIENTRYP _glptr_GetTextureSamplerHandleARB)(GLuint, GLuint);
#define CALL_GetTextureSamplerHandleARB(disp, parameters) \
    (* GET_GetTextureSamplerHandleARB(disp)) parameters
static inline _glptr_GetTextureSamplerHandleARB GET_GetTextureSamplerHandleARB(struct _glapi_table *disp) {
   return (_glptr_GetTextureSamplerHandleARB) (GET_by_offset(disp, _gloffset_GetTextureSamplerHandleARB));
}

static inline void SET_GetTextureSamplerHandleARB(struct _glapi_table *disp, GLuint64 (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_GetTextureSamplerHandleARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribLui64vARB)(GLuint, GLenum, GLuint64EXT *);
#define CALL_GetVertexAttribLui64vARB(disp, parameters) \
    (* GET_GetVertexAttribLui64vARB(disp)) parameters
static inline _glptr_GetVertexAttribLui64vARB GET_GetVertexAttribLui64vARB(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribLui64vARB) (GET_by_offset(disp, _gloffset_GetVertexAttribLui64vARB));
}

static inline void SET_GetVertexAttribLui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint64EXT *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribLui64vARB, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsImageHandleResidentARB)(GLuint64);
#define CALL_IsImageHandleResidentARB(disp, parameters) \
    (* GET_IsImageHandleResidentARB(disp)) parameters
static inline _glptr_IsImageHandleResidentARB GET_IsImageHandleResidentARB(struct _glapi_table *disp) {
   return (_glptr_IsImageHandleResidentARB) (GET_by_offset(disp, _gloffset_IsImageHandleResidentARB));
}

static inline void SET_IsImageHandleResidentARB(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint64)) {
   SET_by_offset(disp, _gloffset_IsImageHandleResidentARB, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsTextureHandleResidentARB)(GLuint64);
#define CALL_IsTextureHandleResidentARB(disp, parameters) \
    (* GET_IsTextureHandleResidentARB(disp)) parameters
static inline _glptr_IsTextureHandleResidentARB GET_IsTextureHandleResidentARB(struct _glapi_table *disp) {
   return (_glptr_IsTextureHandleResidentARB) (GET_by_offset(disp, _gloffset_IsTextureHandleResidentARB));
}

static inline void SET_IsTextureHandleResidentARB(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint64)) {
   SET_by_offset(disp, _gloffset_IsTextureHandleResidentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MakeImageHandleNonResidentARB)(GLuint64);
#define CALL_MakeImageHandleNonResidentARB(disp, parameters) \
    (* GET_MakeImageHandleNonResidentARB(disp)) parameters
static inline _glptr_MakeImageHandleNonResidentARB GET_MakeImageHandleNonResidentARB(struct _glapi_table *disp) {
   return (_glptr_MakeImageHandleNonResidentARB) (GET_by_offset(disp, _gloffset_MakeImageHandleNonResidentARB));
}

static inline void SET_MakeImageHandleNonResidentARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint64)) {
   SET_by_offset(disp, _gloffset_MakeImageHandleNonResidentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MakeImageHandleResidentARB)(GLuint64, GLenum);
#define CALL_MakeImageHandleResidentARB(disp, parameters) \
    (* GET_MakeImageHandleResidentARB(disp)) parameters
static inline _glptr_MakeImageHandleResidentARB GET_MakeImageHandleResidentARB(struct _glapi_table *disp) {
   return (_glptr_MakeImageHandleResidentARB) (GET_by_offset(disp, _gloffset_MakeImageHandleResidentARB));
}

static inline void SET_MakeImageHandleResidentARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint64, GLenum)) {
   SET_by_offset(disp, _gloffset_MakeImageHandleResidentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MakeTextureHandleNonResidentARB)(GLuint64);
#define CALL_MakeTextureHandleNonResidentARB(disp, parameters) \
    (* GET_MakeTextureHandleNonResidentARB(disp)) parameters
static inline _glptr_MakeTextureHandleNonResidentARB GET_MakeTextureHandleNonResidentARB(struct _glapi_table *disp) {
   return (_glptr_MakeTextureHandleNonResidentARB) (GET_by_offset(disp, _gloffset_MakeTextureHandleNonResidentARB));
}

static inline void SET_MakeTextureHandleNonResidentARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint64)) {
   SET_by_offset(disp, _gloffset_MakeTextureHandleNonResidentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MakeTextureHandleResidentARB)(GLuint64);
#define CALL_MakeTextureHandleResidentARB(disp, parameters) \
    (* GET_MakeTextureHandleResidentARB(disp)) parameters
static inline _glptr_MakeTextureHandleResidentARB GET_MakeTextureHandleResidentARB(struct _glapi_table *disp) {
   return (_glptr_MakeTextureHandleResidentARB) (GET_by_offset(disp, _gloffset_MakeTextureHandleResidentARB));
}

static inline void SET_MakeTextureHandleResidentARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint64)) {
   SET_by_offset(disp, _gloffset_MakeTextureHandleResidentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformHandleui64ARB)(GLuint, GLint, GLuint64);
#define CALL_ProgramUniformHandleui64ARB(disp, parameters) \
    (* GET_ProgramUniformHandleui64ARB(disp)) parameters
static inline _glptr_ProgramUniformHandleui64ARB GET_ProgramUniformHandleui64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformHandleui64ARB) (GET_by_offset(disp, _gloffset_ProgramUniformHandleui64ARB));
}

static inline void SET_ProgramUniformHandleui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniformHandleui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformHandleui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *);
#define CALL_ProgramUniformHandleui64vARB(disp, parameters) \
    (* GET_ProgramUniformHandleui64vARB(disp)) parameters
static inline _glptr_ProgramUniformHandleui64vARB GET_ProgramUniformHandleui64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformHandleui64vARB) (GET_by_offset(disp, _gloffset_ProgramUniformHandleui64vARB));
}

static inline void SET_ProgramUniformHandleui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformHandleui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformHandleui64ARB)(GLint, GLuint64);
#define CALL_UniformHandleui64ARB(disp, parameters) \
    (* GET_UniformHandleui64ARB(disp)) parameters
static inline _glptr_UniformHandleui64ARB GET_UniformHandleui64ARB(struct _glapi_table *disp) {
   return (_glptr_UniformHandleui64ARB) (GET_by_offset(disp, _gloffset_UniformHandleui64ARB));
}

static inline void SET_UniformHandleui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint64)) {
   SET_by_offset(disp, _gloffset_UniformHandleui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_UniformHandleui64vARB)(GLint, GLsizei, const GLuint64 *);
#define CALL_UniformHandleui64vARB(disp, parameters) \
    (* GET_UniformHandleui64vARB(disp)) parameters
static inline _glptr_UniformHandleui64vARB GET_UniformHandleui64vARB(struct _glapi_table *disp) {
   return (_glptr_UniformHandleui64vARB) (GET_by_offset(disp, _gloffset_UniformHandleui64vARB));
}

static inline void SET_UniformHandleui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_UniformHandleui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL1ui64ARB)(GLuint, GLuint64EXT);
#define CALL_VertexAttribL1ui64ARB(disp, parameters) \
    (* GET_VertexAttribL1ui64ARB(disp)) parameters
static inline _glptr_VertexAttribL1ui64ARB GET_VertexAttribL1ui64ARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL1ui64ARB) (GET_by_offset(disp, _gloffset_VertexAttribL1ui64ARB));
}

static inline void SET_VertexAttribL1ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint64EXT)) {
   SET_by_offset(disp, _gloffset_VertexAttribL1ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribL1ui64vARB)(GLuint, const GLuint64EXT *);
#define CALL_VertexAttribL1ui64vARB(disp, parameters) \
    (* GET_VertexAttribL1ui64vARB(disp)) parameters
static inline _glptr_VertexAttribL1ui64vARB GET_VertexAttribL1ui64vARB(struct _glapi_table *disp) {
   return (_glptr_VertexAttribL1ui64vARB) (GET_by_offset(disp, _gloffset_VertexAttribL1ui64vARB));
}

static inline void SET_VertexAttribL1ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint64EXT *)) {
   SET_by_offset(disp, _gloffset_VertexAttribL1ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_DispatchComputeGroupSizeARB)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_DispatchComputeGroupSizeARB(disp, parameters) \
    (* GET_DispatchComputeGroupSizeARB(disp)) parameters
static inline _glptr_DispatchComputeGroupSizeARB GET_DispatchComputeGroupSizeARB(struct _glapi_table *disp) {
   return (_glptr_DispatchComputeGroupSizeARB) (GET_by_offset(disp, _gloffset_DispatchComputeGroupSizeARB));
}

static inline void SET_DispatchComputeGroupSizeARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_DispatchComputeGroupSizeARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawArraysIndirectCountARB)(GLenum, GLintptr, GLintptr, GLsizei, GLsizei);
#define CALL_MultiDrawArraysIndirectCountARB(disp, parameters) \
    (* GET_MultiDrawArraysIndirectCountARB(disp)) parameters
static inline _glptr_MultiDrawArraysIndirectCountARB GET_MultiDrawArraysIndirectCountARB(struct _glapi_table *disp) {
   return (_glptr_MultiDrawArraysIndirectCountARB) (GET_by_offset(disp, _gloffset_MultiDrawArraysIndirectCountARB));
}

static inline void SET_MultiDrawArraysIndirectCountARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLintptr, GLintptr, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_MultiDrawArraysIndirectCountARB, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawElementsIndirectCountARB)(GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei);
#define CALL_MultiDrawElementsIndirectCountARB(disp, parameters) \
    (* GET_MultiDrawElementsIndirectCountARB(disp)) parameters
static inline _glptr_MultiDrawElementsIndirectCountARB GET_MultiDrawElementsIndirectCountARB(struct _glapi_table *disp) {
   return (_glptr_MultiDrawElementsIndirectCountARB) (GET_by_offset(disp, _gloffset_MultiDrawElementsIndirectCountARB));
}

static inline void SET_MultiDrawElementsIndirectCountARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_MultiDrawElementsIndirectCountARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ClipControl)(GLenum, GLenum);
#define CALL_ClipControl(disp, parameters) \
    (* GET_ClipControl(disp)) parameters
static inline _glptr_ClipControl GET_ClipControl(struct _glapi_table *disp) {
   return (_glptr_ClipControl) (GET_by_offset(disp, _gloffset_ClipControl));
}

static inline void SET_ClipControl(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_ClipControl, fn);
}

typedef void (GLAPIENTRYP _glptr_BindTextureUnit)(GLuint, GLuint);
#define CALL_BindTextureUnit(disp, parameters) \
    (* GET_BindTextureUnit(disp)) parameters
static inline _glptr_BindTextureUnit GET_BindTextureUnit(struct _glapi_table *disp) {
   return (_glptr_BindTextureUnit) (GET_by_offset(disp, _gloffset_BindTextureUnit));
}

static inline void SET_BindTextureUnit(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_BindTextureUnit, fn);
}

typedef void (GLAPIENTRYP _glptr_BlitNamedFramebuffer)(GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
#define CALL_BlitNamedFramebuffer(disp, parameters) \
    (* GET_BlitNamedFramebuffer(disp)) parameters
static inline _glptr_BlitNamedFramebuffer GET_BlitNamedFramebuffer(struct _glapi_table *disp) {
   return (_glptr_BlitNamedFramebuffer) (GET_by_offset(disp, _gloffset_BlitNamedFramebuffer));
}

static inline void SET_BlitNamedFramebuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum)) {
   SET_by_offset(disp, _gloffset_BlitNamedFramebuffer, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_CheckNamedFramebufferStatus)(GLuint, GLenum);
#define CALL_CheckNamedFramebufferStatus(disp, parameters) \
    (* GET_CheckNamedFramebufferStatus(disp)) parameters
static inline _glptr_CheckNamedFramebufferStatus GET_CheckNamedFramebufferStatus(struct _glapi_table *disp) {
   return (_glptr_CheckNamedFramebufferStatus) (GET_by_offset(disp, _gloffset_CheckNamedFramebufferStatus));
}

static inline void SET_CheckNamedFramebufferStatus(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_CheckNamedFramebufferStatus, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearNamedBufferData)(GLuint, GLenum, GLenum, GLenum, const GLvoid *);
#define CALL_ClearNamedBufferData(disp, parameters) \
    (* GET_ClearNamedBufferData(disp)) parameters
static inline _glptr_ClearNamedBufferData GET_ClearNamedBufferData(struct _glapi_table *disp) {
   return (_glptr_ClearNamedBufferData) (GET_by_offset(disp, _gloffset_ClearNamedBufferData));
}

static inline void SET_ClearNamedBufferData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ClearNamedBufferData, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearNamedBufferSubData)(GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const GLvoid *);
#define CALL_ClearNamedBufferSubData(disp, parameters) \
    (* GET_ClearNamedBufferSubData(disp)) parameters
static inline _glptr_ClearNamedBufferSubData GET_ClearNamedBufferSubData(struct _glapi_table *disp) {
   return (_glptr_ClearNamedBufferSubData) (GET_by_offset(disp, _gloffset_ClearNamedBufferSubData));
}

static inline void SET_ClearNamedBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ClearNamedBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearNamedFramebufferfi)(GLuint, GLenum, GLint, GLfloat, GLint);
#define CALL_ClearNamedFramebufferfi(disp, parameters) \
    (* GET_ClearNamedFramebufferfi(disp)) parameters
static inline _glptr_ClearNamedFramebufferfi GET_ClearNamedFramebufferfi(struct _glapi_table *disp) {
   return (_glptr_ClearNamedFramebufferfi) (GET_by_offset(disp, _gloffset_ClearNamedFramebufferfi));
}

static inline void SET_ClearNamedFramebufferfi(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint, GLfloat, GLint)) {
   SET_by_offset(disp, _gloffset_ClearNamedFramebufferfi, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearNamedFramebufferfv)(GLuint, GLenum, GLint, const GLfloat *);
#define CALL_ClearNamedFramebufferfv(disp, parameters) \
    (* GET_ClearNamedFramebufferfv(disp)) parameters
static inline _glptr_ClearNamedFramebufferfv GET_ClearNamedFramebufferfv(struct _glapi_table *disp) {
   return (_glptr_ClearNamedFramebufferfv) (GET_by_offset(disp, _gloffset_ClearNamedFramebufferfv));
}

static inline void SET_ClearNamedFramebufferfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ClearNamedFramebufferfv, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearNamedFramebufferiv)(GLuint, GLenum, GLint, const GLint *);
#define CALL_ClearNamedFramebufferiv(disp, parameters) \
    (* GET_ClearNamedFramebufferiv(disp)) parameters
static inline _glptr_ClearNamedFramebufferiv GET_ClearNamedFramebufferiv(struct _glapi_table *disp) {
   return (_glptr_ClearNamedFramebufferiv) (GET_by_offset(disp, _gloffset_ClearNamedFramebufferiv));
}

static inline void SET_ClearNamedFramebufferiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint, const GLint *)) {
   SET_by_offset(disp, _gloffset_ClearNamedFramebufferiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearNamedFramebufferuiv)(GLuint, GLenum, GLint, const GLuint *);
#define CALL_ClearNamedFramebufferuiv(disp, parameters) \
    (* GET_ClearNamedFramebufferuiv(disp)) parameters
static inline _glptr_ClearNamedFramebufferuiv GET_ClearNamedFramebufferuiv(struct _glapi_table *disp) {
   return (_glptr_ClearNamedFramebufferuiv) (GET_by_offset(disp, _gloffset_ClearNamedFramebufferuiv));
}

static inline void SET_ClearNamedFramebufferuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ClearNamedFramebufferuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTextureSubImage1D)(GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
#define CALL_CompressedTextureSubImage1D(disp, parameters) \
    (* GET_CompressedTextureSubImage1D(disp)) parameters
static inline _glptr_CompressedTextureSubImage1D GET_CompressedTextureSubImage1D(struct _glapi_table *disp) {
   return (_glptr_CompressedTextureSubImage1D) (GET_by_offset(disp, _gloffset_CompressedTextureSubImage1D));
}

static inline void SET_CompressedTextureSubImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTextureSubImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTextureSubImage2D)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define CALL_CompressedTextureSubImage2D(disp, parameters) \
    (* GET_CompressedTextureSubImage2D(disp)) parameters
static inline _glptr_CompressedTextureSubImage2D GET_CompressedTextureSubImage2D(struct _glapi_table *disp) {
   return (_glptr_CompressedTextureSubImage2D) (GET_by_offset(disp, _gloffset_CompressedTextureSubImage2D));
}

static inline void SET_CompressedTextureSubImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTextureSubImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_CompressedTextureSubImage3D)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define CALL_CompressedTextureSubImage3D(disp, parameters) \
    (* GET_CompressedTextureSubImage3D(disp)) parameters
static inline _glptr_CompressedTextureSubImage3D GET_CompressedTextureSubImage3D(struct _glapi_table *disp) {
   return (_glptr_CompressedTextureSubImage3D) (GET_by_offset(disp, _gloffset_CompressedTextureSubImage3D));
}

static inline void SET_CompressedTextureSubImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_CompressedTextureSubImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyNamedBufferSubData)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr);
#define CALL_CopyNamedBufferSubData(disp, parameters) \
    (* GET_CopyNamedBufferSubData(disp)) parameters
static inline _glptr_CopyNamedBufferSubData GET_CopyNamedBufferSubData(struct _glapi_table *disp) {
   return (_glptr_CopyNamedBufferSubData) (GET_by_offset(disp, _gloffset_CopyNamedBufferSubData));
}

static inline void SET_CopyNamedBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_CopyNamedBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTextureSubImage1D)(GLuint, GLint, GLint, GLint, GLint, GLsizei);
#define CALL_CopyTextureSubImage1D(disp, parameters) \
    (* GET_CopyTextureSubImage1D(disp)) parameters
static inline _glptr_CopyTextureSubImage1D GET_CopyTextureSubImage1D(struct _glapi_table *disp) {
   return (_glptr_CopyTextureSubImage1D) (GET_by_offset(disp, _gloffset_CopyTextureSubImage1D));
}

static inline void SET_CopyTextureSubImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyTextureSubImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTextureSubImage2D)(GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define CALL_CopyTextureSubImage2D(disp, parameters) \
    (* GET_CopyTextureSubImage2D(disp)) parameters
static inline _glptr_CopyTextureSubImage2D GET_CopyTextureSubImage2D(struct _glapi_table *disp) {
   return (_glptr_CopyTextureSubImage2D) (GET_by_offset(disp, _gloffset_CopyTextureSubImage2D));
}

static inline void SET_CopyTextureSubImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyTextureSubImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_CopyTextureSubImage3D)(GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define CALL_CopyTextureSubImage3D(disp, parameters) \
    (* GET_CopyTextureSubImage3D(disp)) parameters
static inline _glptr_CopyTextureSubImage3D GET_CopyTextureSubImage3D(struct _glapi_table *disp) {
   return (_glptr_CopyTextureSubImage3D) (GET_by_offset(disp, _gloffset_CopyTextureSubImage3D));
}

static inline void SET_CopyTextureSubImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_CopyTextureSubImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateBuffers)(GLsizei, GLuint *);
#define CALL_CreateBuffers(disp, parameters) \
    (* GET_CreateBuffers(disp)) parameters
static inline _glptr_CreateBuffers GET_CreateBuffers(struct _glapi_table *disp) {
   return (_glptr_CreateBuffers) (GET_by_offset(disp, _gloffset_CreateBuffers));
}

static inline void SET_CreateBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateBuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateFramebuffers)(GLsizei, GLuint *);
#define CALL_CreateFramebuffers(disp, parameters) \
    (* GET_CreateFramebuffers(disp)) parameters
static inline _glptr_CreateFramebuffers GET_CreateFramebuffers(struct _glapi_table *disp) {
   return (_glptr_CreateFramebuffers) (GET_by_offset(disp, _gloffset_CreateFramebuffers));
}

static inline void SET_CreateFramebuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateFramebuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateProgramPipelines)(GLsizei, GLuint *);
#define CALL_CreateProgramPipelines(disp, parameters) \
    (* GET_CreateProgramPipelines(disp)) parameters
static inline _glptr_CreateProgramPipelines GET_CreateProgramPipelines(struct _glapi_table *disp) {
   return (_glptr_CreateProgramPipelines) (GET_by_offset(disp, _gloffset_CreateProgramPipelines));
}

static inline void SET_CreateProgramPipelines(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateProgramPipelines, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateQueries)(GLenum, GLsizei, GLuint *);
#define CALL_CreateQueries(disp, parameters) \
    (* GET_CreateQueries(disp)) parameters
static inline _glptr_CreateQueries GET_CreateQueries(struct _glapi_table *disp) {
   return (_glptr_CreateQueries) (GET_by_offset(disp, _gloffset_CreateQueries));
}

static inline void SET_CreateQueries(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateQueries, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateRenderbuffers)(GLsizei, GLuint *);
#define CALL_CreateRenderbuffers(disp, parameters) \
    (* GET_CreateRenderbuffers(disp)) parameters
static inline _glptr_CreateRenderbuffers GET_CreateRenderbuffers(struct _glapi_table *disp) {
   return (_glptr_CreateRenderbuffers) (GET_by_offset(disp, _gloffset_CreateRenderbuffers));
}

static inline void SET_CreateRenderbuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateRenderbuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateSamplers)(GLsizei, GLuint *);
#define CALL_CreateSamplers(disp, parameters) \
    (* GET_CreateSamplers(disp)) parameters
static inline _glptr_CreateSamplers GET_CreateSamplers(struct _glapi_table *disp) {
   return (_glptr_CreateSamplers) (GET_by_offset(disp, _gloffset_CreateSamplers));
}

static inline void SET_CreateSamplers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateSamplers, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateTextures)(GLenum, GLsizei, GLuint *);
#define CALL_CreateTextures(disp, parameters) \
    (* GET_CreateTextures(disp)) parameters
static inline _glptr_CreateTextures GET_CreateTextures(struct _glapi_table *disp) {
   return (_glptr_CreateTextures) (GET_by_offset(disp, _gloffset_CreateTextures));
}

static inline void SET_CreateTextures(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateTextures, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateTransformFeedbacks)(GLsizei, GLuint *);
#define CALL_CreateTransformFeedbacks(disp, parameters) \
    (* GET_CreateTransformFeedbacks(disp)) parameters
static inline _glptr_CreateTransformFeedbacks GET_CreateTransformFeedbacks(struct _glapi_table *disp) {
   return (_glptr_CreateTransformFeedbacks) (GET_by_offset(disp, _gloffset_CreateTransformFeedbacks));
}

static inline void SET_CreateTransformFeedbacks(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateTransformFeedbacks, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateVertexArrays)(GLsizei, GLuint *);
#define CALL_CreateVertexArrays(disp, parameters) \
    (* GET_CreateVertexArrays(disp)) parameters
static inline _glptr_CreateVertexArrays GET_CreateVertexArrays(struct _glapi_table *disp) {
   return (_glptr_CreateVertexArrays) (GET_by_offset(disp, _gloffset_CreateVertexArrays));
}

static inline void SET_CreateVertexArrays(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateVertexArrays, fn);
}

typedef void (GLAPIENTRYP _glptr_DisableVertexArrayAttrib)(GLuint, GLuint);
#define CALL_DisableVertexArrayAttrib(disp, parameters) \
    (* GET_DisableVertexArrayAttrib(disp)) parameters
static inline _glptr_DisableVertexArrayAttrib GET_DisableVertexArrayAttrib(struct _glapi_table *disp) {
   return (_glptr_DisableVertexArrayAttrib) (GET_by_offset(disp, _gloffset_DisableVertexArrayAttrib));
}

static inline void SET_DisableVertexArrayAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_DisableVertexArrayAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_EnableVertexArrayAttrib)(GLuint, GLuint);
#define CALL_EnableVertexArrayAttrib(disp, parameters) \
    (* GET_EnableVertexArrayAttrib(disp)) parameters
static inline _glptr_EnableVertexArrayAttrib GET_EnableVertexArrayAttrib(struct _glapi_table *disp) {
   return (_glptr_EnableVertexArrayAttrib) (GET_by_offset(disp, _gloffset_EnableVertexArrayAttrib));
}

static inline void SET_EnableVertexArrayAttrib(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_EnableVertexArrayAttrib, fn);
}

typedef void (GLAPIENTRYP _glptr_FlushMappedNamedBufferRange)(GLuint, GLintptr, GLsizeiptr);
#define CALL_FlushMappedNamedBufferRange(disp, parameters) \
    (* GET_FlushMappedNamedBufferRange(disp)) parameters
static inline _glptr_FlushMappedNamedBufferRange GET_FlushMappedNamedBufferRange(struct _glapi_table *disp) {
   return (_glptr_FlushMappedNamedBufferRange) (GET_by_offset(disp, _gloffset_FlushMappedNamedBufferRange));
}

static inline void SET_FlushMappedNamedBufferRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_FlushMappedNamedBufferRange, fn);
}

typedef void (GLAPIENTRYP _glptr_GenerateTextureMipmap)(GLuint);
#define CALL_GenerateTextureMipmap(disp, parameters) \
    (* GET_GenerateTextureMipmap(disp)) parameters
static inline _glptr_GenerateTextureMipmap GET_GenerateTextureMipmap(struct _glapi_table *disp) {
   return (_glptr_GenerateTextureMipmap) (GET_by_offset(disp, _gloffset_GenerateTextureMipmap));
}

static inline void SET_GenerateTextureMipmap(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_GenerateTextureMipmap, fn);
}

typedef void (GLAPIENTRYP _glptr_GetCompressedTextureImage)(GLuint, GLint, GLsizei, GLvoid *);
#define CALL_GetCompressedTextureImage(disp, parameters) \
    (* GET_GetCompressedTextureImage(disp)) parameters
static inline _glptr_GetCompressedTextureImage GET_GetCompressedTextureImage(struct _glapi_table *disp) {
   return (_glptr_GetCompressedTextureImage) (GET_by_offset(disp, _gloffset_GetCompressedTextureImage));
}

static inline void SET_GetCompressedTextureImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetCompressedTextureImage, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedBufferParameteri64v)(GLuint, GLenum, GLint64 *);
#define CALL_GetNamedBufferParameteri64v(disp, parameters) \
    (* GET_GetNamedBufferParameteri64v(disp)) parameters
static inline _glptr_GetNamedBufferParameteri64v GET_GetNamedBufferParameteri64v(struct _glapi_table *disp) {
   return (_glptr_GetNamedBufferParameteri64v) (GET_by_offset(disp, _gloffset_GetNamedBufferParameteri64v));
}

static inline void SET_GetNamedBufferParameteri64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetNamedBufferParameteri64v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedBufferParameteriv)(GLuint, GLenum, GLint *);
#define CALL_GetNamedBufferParameteriv(disp, parameters) \
    (* GET_GetNamedBufferParameteriv(disp)) parameters
static inline _glptr_GetNamedBufferParameteriv GET_GetNamedBufferParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetNamedBufferParameteriv) (GET_by_offset(disp, _gloffset_GetNamedBufferParameteriv));
}

static inline void SET_GetNamedBufferParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetNamedBufferParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedBufferPointerv)(GLuint, GLenum, GLvoid **);
#define CALL_GetNamedBufferPointerv(disp, parameters) \
    (* GET_GetNamedBufferPointerv(disp)) parameters
static inline _glptr_GetNamedBufferPointerv GET_GetNamedBufferPointerv(struct _glapi_table *disp) {
   return (_glptr_GetNamedBufferPointerv) (GET_by_offset(disp, _gloffset_GetNamedBufferPointerv));
}

static inline void SET_GetNamedBufferPointerv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLvoid **)) {
   SET_by_offset(disp, _gloffset_GetNamedBufferPointerv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedBufferSubData)(GLuint, GLintptr, GLsizeiptr, GLvoid *);
#define CALL_GetNamedBufferSubData(disp, parameters) \
    (* GET_GetNamedBufferSubData(disp)) parameters
static inline _glptr_GetNamedBufferSubData GET_GetNamedBufferSubData(struct _glapi_table *disp) {
   return (_glptr_GetNamedBufferSubData) (GET_by_offset(disp, _gloffset_GetNamedBufferSubData));
}

static inline void SET_GetNamedBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLintptr, GLsizeiptr, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetNamedBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedFramebufferAttachmentParameteriv)(GLuint, GLenum, GLenum, GLint *);
#define CALL_GetNamedFramebufferAttachmentParameteriv(disp, parameters) \
    (* GET_GetNamedFramebufferAttachmentParameteriv(disp)) parameters
static inline _glptr_GetNamedFramebufferAttachmentParameteriv GET_GetNamedFramebufferAttachmentParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetNamedFramebufferAttachmentParameteriv) (GET_by_offset(disp, _gloffset_GetNamedFramebufferAttachmentParameteriv));
}

static inline void SET_GetNamedFramebufferAttachmentParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetNamedFramebufferAttachmentParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedFramebufferParameteriv)(GLuint, GLenum, GLint *);
#define CALL_GetNamedFramebufferParameteriv(disp, parameters) \
    (* GET_GetNamedFramebufferParameteriv(disp)) parameters
static inline _glptr_GetNamedFramebufferParameteriv GET_GetNamedFramebufferParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetNamedFramebufferParameteriv) (GET_by_offset(disp, _gloffset_GetNamedFramebufferParameteriv));
}

static inline void SET_GetNamedFramebufferParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetNamedFramebufferParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNamedRenderbufferParameteriv)(GLuint, GLenum, GLint *);
#define CALL_GetNamedRenderbufferParameteriv(disp, parameters) \
    (* GET_GetNamedRenderbufferParameteriv(disp)) parameters
static inline _glptr_GetNamedRenderbufferParameteriv GET_GetNamedRenderbufferParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetNamedRenderbufferParameteriv) (GET_by_offset(disp, _gloffset_GetNamedRenderbufferParameteriv));
}

static inline void SET_GetNamedRenderbufferParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetNamedRenderbufferParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryBufferObjecti64v)(GLuint, GLuint, GLenum, GLintptr);
#define CALL_GetQueryBufferObjecti64v(disp, parameters) \
    (* GET_GetQueryBufferObjecti64v(disp)) parameters
static inline _glptr_GetQueryBufferObjecti64v GET_GetQueryBufferObjecti64v(struct _glapi_table *disp) {
   return (_glptr_GetQueryBufferObjecti64v) (GET_by_offset(disp, _gloffset_GetQueryBufferObjecti64v));
}

static inline void SET_GetQueryBufferObjecti64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLintptr)) {
   SET_by_offset(disp, _gloffset_GetQueryBufferObjecti64v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryBufferObjectiv)(GLuint, GLuint, GLenum, GLintptr);
#define CALL_GetQueryBufferObjectiv(disp, parameters) \
    (* GET_GetQueryBufferObjectiv(disp)) parameters
static inline _glptr_GetQueryBufferObjectiv GET_GetQueryBufferObjectiv(struct _glapi_table *disp) {
   return (_glptr_GetQueryBufferObjectiv) (GET_by_offset(disp, _gloffset_GetQueryBufferObjectiv));
}

static inline void SET_GetQueryBufferObjectiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLintptr)) {
   SET_by_offset(disp, _gloffset_GetQueryBufferObjectiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryBufferObjectui64v)(GLuint, GLuint, GLenum, GLintptr);
#define CALL_GetQueryBufferObjectui64v(disp, parameters) \
    (* GET_GetQueryBufferObjectui64v(disp)) parameters
static inline _glptr_GetQueryBufferObjectui64v GET_GetQueryBufferObjectui64v(struct _glapi_table *disp) {
   return (_glptr_GetQueryBufferObjectui64v) (GET_by_offset(disp, _gloffset_GetQueryBufferObjectui64v));
}

static inline void SET_GetQueryBufferObjectui64v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLintptr)) {
   SET_by_offset(disp, _gloffset_GetQueryBufferObjectui64v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetQueryBufferObjectuiv)(GLuint, GLuint, GLenum, GLintptr);
#define CALL_GetQueryBufferObjectuiv(disp, parameters) \
    (* GET_GetQueryBufferObjectuiv(disp)) parameters
static inline _glptr_GetQueryBufferObjectuiv GET_GetQueryBufferObjectuiv(struct _glapi_table *disp) {
   return (_glptr_GetQueryBufferObjectuiv) (GET_by_offset(disp, _gloffset_GetQueryBufferObjectuiv));
}

static inline void SET_GetQueryBufferObjectuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLintptr)) {
   SET_by_offset(disp, _gloffset_GetQueryBufferObjectuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureImage)(GLuint, GLint, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetTextureImage(disp, parameters) \
    (* GET_GetTextureImage(disp)) parameters
static inline _glptr_GetTextureImage GET_GetTextureImage(struct _glapi_table *disp) {
   return (_glptr_GetTextureImage) (GET_by_offset(disp, _gloffset_GetTextureImage));
}

static inline void SET_GetTextureImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetTextureImage, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureLevelParameterfv)(GLuint, GLint, GLenum, GLfloat *);
#define CALL_GetTextureLevelParameterfv(disp, parameters) \
    (* GET_GetTextureLevelParameterfv(disp)) parameters
static inline _glptr_GetTextureLevelParameterfv GET_GetTextureLevelParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetTextureLevelParameterfv) (GET_by_offset(disp, _gloffset_GetTextureLevelParameterfv));
}

static inline void SET_GetTextureLevelParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTextureLevelParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureLevelParameteriv)(GLuint, GLint, GLenum, GLint *);
#define CALL_GetTextureLevelParameteriv(disp, parameters) \
    (* GET_GetTextureLevelParameteriv(disp)) parameters
static inline _glptr_GetTextureLevelParameteriv GET_GetTextureLevelParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetTextureLevelParameteriv) (GET_by_offset(disp, _gloffset_GetTextureLevelParameteriv));
}

static inline void SET_GetTextureLevelParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTextureLevelParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureParameterIiv)(GLuint, GLenum, GLint *);
#define CALL_GetTextureParameterIiv(disp, parameters) \
    (* GET_GetTextureParameterIiv(disp)) parameters
static inline _glptr_GetTextureParameterIiv GET_GetTextureParameterIiv(struct _glapi_table *disp) {
   return (_glptr_GetTextureParameterIiv) (GET_by_offset(disp, _gloffset_GetTextureParameterIiv));
}

static inline void SET_GetTextureParameterIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTextureParameterIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureParameterIuiv)(GLuint, GLenum, GLuint *);
#define CALL_GetTextureParameterIuiv(disp, parameters) \
    (* GET_GetTextureParameterIuiv(disp)) parameters
static inline _glptr_GetTextureParameterIuiv GET_GetTextureParameterIuiv(struct _glapi_table *disp) {
   return (_glptr_GetTextureParameterIuiv) (GET_by_offset(disp, _gloffset_GetTextureParameterIuiv));
}

static inline void SET_GetTextureParameterIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetTextureParameterIuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureParameterfv)(GLuint, GLenum, GLfloat *);
#define CALL_GetTextureParameterfv(disp, parameters) \
    (* GET_GetTextureParameterfv(disp)) parameters
static inline _glptr_GetTextureParameterfv GET_GetTextureParameterfv(struct _glapi_table *disp) {
   return (_glptr_GetTextureParameterfv) (GET_by_offset(disp, _gloffset_GetTextureParameterfv));
}

static inline void SET_GetTextureParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTextureParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureParameteriv)(GLuint, GLenum, GLint *);
#define CALL_GetTextureParameteriv(disp, parameters) \
    (* GET_GetTextureParameteriv(disp)) parameters
static inline _glptr_GetTextureParameteriv GET_GetTextureParameteriv(struct _glapi_table *disp) {
   return (_glptr_GetTextureParameteriv) (GET_by_offset(disp, _gloffset_GetTextureParameteriv));
}

static inline void SET_GetTextureParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTextureParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTransformFeedbacki64_v)(GLuint, GLenum, GLuint, GLint64 *);
#define CALL_GetTransformFeedbacki64_v(disp, parameters) \
    (* GET_GetTransformFeedbacki64_v(disp)) parameters
static inline _glptr_GetTransformFeedbacki64_v GET_GetTransformFeedbacki64_v(struct _glapi_table *disp) {
   return (_glptr_GetTransformFeedbacki64_v) (GET_by_offset(disp, _gloffset_GetTransformFeedbacki64_v));
}

static inline void SET_GetTransformFeedbacki64_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetTransformFeedbacki64_v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTransformFeedbacki_v)(GLuint, GLenum, GLuint, GLint *);
#define CALL_GetTransformFeedbacki_v(disp, parameters) \
    (* GET_GetTransformFeedbacki_v(disp)) parameters
static inline _glptr_GetTransformFeedbacki_v GET_GetTransformFeedbacki_v(struct _glapi_table *disp) {
   return (_glptr_GetTransformFeedbacki_v) (GET_by_offset(disp, _gloffset_GetTransformFeedbacki_v));
}

static inline void SET_GetTransformFeedbacki_v(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTransformFeedbacki_v, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTransformFeedbackiv)(GLuint, GLenum, GLint *);
#define CALL_GetTransformFeedbackiv(disp, parameters) \
    (* GET_GetTransformFeedbackiv(disp)) parameters
static inline _glptr_GetTransformFeedbackiv GET_GetTransformFeedbackiv(struct _glapi_table *disp) {
   return (_glptr_GetTransformFeedbackiv) (GET_by_offset(disp, _gloffset_GetTransformFeedbackiv));
}

static inline void SET_GetTransformFeedbackiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTransformFeedbackiv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexArrayIndexed64iv)(GLuint, GLuint, GLenum, GLint64 *);
#define CALL_GetVertexArrayIndexed64iv(disp, parameters) \
    (* GET_GetVertexArrayIndexed64iv(disp)) parameters
static inline _glptr_GetVertexArrayIndexed64iv GET_GetVertexArrayIndexed64iv(struct _glapi_table *disp) {
   return (_glptr_GetVertexArrayIndexed64iv) (GET_by_offset(disp, _gloffset_GetVertexArrayIndexed64iv));
}

static inline void SET_GetVertexArrayIndexed64iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetVertexArrayIndexed64iv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexArrayIndexediv)(GLuint, GLuint, GLenum, GLint *);
#define CALL_GetVertexArrayIndexediv(disp, parameters) \
    (* GET_GetVertexArrayIndexediv(disp)) parameters
static inline _glptr_GetVertexArrayIndexediv GET_GetVertexArrayIndexediv(struct _glapi_table *disp) {
   return (_glptr_GetVertexArrayIndexediv) (GET_by_offset(disp, _gloffset_GetVertexArrayIndexediv));
}

static inline void SET_GetVertexArrayIndexediv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetVertexArrayIndexediv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexArrayiv)(GLuint, GLenum, GLint *);
#define CALL_GetVertexArrayiv(disp, parameters) \
    (* GET_GetVertexArrayiv(disp)) parameters
static inline _glptr_GetVertexArrayiv GET_GetVertexArrayiv(struct _glapi_table *disp) {
   return (_glptr_GetVertexArrayiv) (GET_by_offset(disp, _gloffset_GetVertexArrayiv));
}

static inline void SET_GetVertexArrayiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetVertexArrayiv, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateNamedFramebufferData)(GLuint, GLsizei, const GLenum *);
#define CALL_InvalidateNamedFramebufferData(disp, parameters) \
    (* GET_InvalidateNamedFramebufferData(disp)) parameters
static inline _glptr_InvalidateNamedFramebufferData GET_InvalidateNamedFramebufferData(struct _glapi_table *disp) {
   return (_glptr_InvalidateNamedFramebufferData) (GET_by_offset(disp, _gloffset_InvalidateNamedFramebufferData));
}

static inline void SET_InvalidateNamedFramebufferData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLenum *)) {
   SET_by_offset(disp, _gloffset_InvalidateNamedFramebufferData, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateNamedFramebufferSubData)(GLuint, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei);
#define CALL_InvalidateNamedFramebufferSubData(disp, parameters) \
    (* GET_InvalidateNamedFramebufferSubData(disp)) parameters
static inline _glptr_InvalidateNamedFramebufferSubData GET_InvalidateNamedFramebufferSubData(struct _glapi_table *disp) {
   return (_glptr_InvalidateNamedFramebufferSubData) (GET_by_offset(disp, _gloffset_InvalidateNamedFramebufferSubData));
}

static inline void SET_InvalidateNamedFramebufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_InvalidateNamedFramebufferSubData, fn);
}

typedef GLvoid * (GLAPIENTRYP _glptr_MapNamedBuffer)(GLuint, GLenum);
#define CALL_MapNamedBuffer(disp, parameters) \
    (* GET_MapNamedBuffer(disp)) parameters
static inline _glptr_MapNamedBuffer GET_MapNamedBuffer(struct _glapi_table *disp) {
   return (_glptr_MapNamedBuffer) (GET_by_offset(disp, _gloffset_MapNamedBuffer));
}

static inline void SET_MapNamedBuffer(struct _glapi_table *disp, GLvoid * (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_MapNamedBuffer, fn);
}

typedef GLvoid * (GLAPIENTRYP _glptr_MapNamedBufferRange)(GLuint, GLintptr, GLsizeiptr, GLbitfield);
#define CALL_MapNamedBufferRange(disp, parameters) \
    (* GET_MapNamedBufferRange(disp)) parameters
static inline _glptr_MapNamedBufferRange GET_MapNamedBufferRange(struct _glapi_table *disp) {
   return (_glptr_MapNamedBufferRange) (GET_by_offset(disp, _gloffset_MapNamedBufferRange));
}

static inline void SET_MapNamedBufferRange(struct _glapi_table *disp, GLvoid * (GLAPIENTRYP fn)(GLuint, GLintptr, GLsizeiptr, GLbitfield)) {
   SET_by_offset(disp, _gloffset_MapNamedBufferRange, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedBufferData)(GLuint, GLsizeiptr, const GLvoid *, GLenum);
#define CALL_NamedBufferData(disp, parameters) \
    (* GET_NamedBufferData(disp)) parameters
static inline _glptr_NamedBufferData GET_NamedBufferData(struct _glapi_table *disp) {
   return (_glptr_NamedBufferData) (GET_by_offset(disp, _gloffset_NamedBufferData));
}

static inline void SET_NamedBufferData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizeiptr, const GLvoid *, GLenum)) {
   SET_by_offset(disp, _gloffset_NamedBufferData, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedBufferStorage)(GLuint, GLsizeiptr, const GLvoid *, GLbitfield);
#define CALL_NamedBufferStorage(disp, parameters) \
    (* GET_NamedBufferStorage(disp)) parameters
static inline _glptr_NamedBufferStorage GET_NamedBufferStorage(struct _glapi_table *disp) {
   return (_glptr_NamedBufferStorage) (GET_by_offset(disp, _gloffset_NamedBufferStorage));
}

static inline void SET_NamedBufferStorage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizeiptr, const GLvoid *, GLbitfield)) {
   SET_by_offset(disp, _gloffset_NamedBufferStorage, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedBufferSubData)(GLuint, GLintptr, GLsizeiptr, const GLvoid *);
#define CALL_NamedBufferSubData(disp, parameters) \
    (* GET_NamedBufferSubData(disp)) parameters
static inline _glptr_NamedBufferSubData GET_NamedBufferSubData(struct _glapi_table *disp) {
   return (_glptr_NamedBufferSubData) (GET_by_offset(disp, _gloffset_NamedBufferSubData));
}

static inline void SET_NamedBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLintptr, GLsizeiptr, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_NamedBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferDrawBuffer)(GLuint, GLenum);
#define CALL_NamedFramebufferDrawBuffer(disp, parameters) \
    (* GET_NamedFramebufferDrawBuffer(disp)) parameters
static inline _glptr_NamedFramebufferDrawBuffer GET_NamedFramebufferDrawBuffer(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferDrawBuffer) (GET_by_offset(disp, _gloffset_NamedFramebufferDrawBuffer));
}

static inline void SET_NamedFramebufferDrawBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferDrawBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferDrawBuffers)(GLuint, GLsizei, const GLenum *);
#define CALL_NamedFramebufferDrawBuffers(disp, parameters) \
    (* GET_NamedFramebufferDrawBuffers(disp)) parameters
static inline _glptr_NamedFramebufferDrawBuffers GET_NamedFramebufferDrawBuffers(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferDrawBuffers) (GET_by_offset(disp, _gloffset_NamedFramebufferDrawBuffers));
}

static inline void SET_NamedFramebufferDrawBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLenum *)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferDrawBuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferParameteri)(GLuint, GLenum, GLint);
#define CALL_NamedFramebufferParameteri(disp, parameters) \
    (* GET_NamedFramebufferParameteri(disp)) parameters
static inline _glptr_NamedFramebufferParameteri GET_NamedFramebufferParameteri(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferParameteri) (GET_by_offset(disp, _gloffset_NamedFramebufferParameteri));
}

static inline void SET_NamedFramebufferParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferReadBuffer)(GLuint, GLenum);
#define CALL_NamedFramebufferReadBuffer(disp, parameters) \
    (* GET_NamedFramebufferReadBuffer(disp)) parameters
static inline _glptr_NamedFramebufferReadBuffer GET_NamedFramebufferReadBuffer(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferReadBuffer) (GET_by_offset(disp, _gloffset_NamedFramebufferReadBuffer));
}

static inline void SET_NamedFramebufferReadBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferReadBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferRenderbuffer)(GLuint, GLenum, GLenum, GLuint);
#define CALL_NamedFramebufferRenderbuffer(disp, parameters) \
    (* GET_NamedFramebufferRenderbuffer(disp)) parameters
static inline _glptr_NamedFramebufferRenderbuffer GET_NamedFramebufferRenderbuffer(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferRenderbuffer) (GET_by_offset(disp, _gloffset_NamedFramebufferRenderbuffer));
}

static inline void SET_NamedFramebufferRenderbuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferRenderbuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferTexture)(GLuint, GLenum, GLuint, GLint);
#define CALL_NamedFramebufferTexture(disp, parameters) \
    (* GET_NamedFramebufferTexture(disp)) parameters
static inline _glptr_NamedFramebufferTexture GET_NamedFramebufferTexture(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferTexture) (GET_by_offset(disp, _gloffset_NamedFramebufferTexture));
}

static inline void SET_NamedFramebufferTexture(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLint)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferTexture, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedFramebufferTextureLayer)(GLuint, GLenum, GLuint, GLint, GLint);
#define CALL_NamedFramebufferTextureLayer(disp, parameters) \
    (* GET_NamedFramebufferTextureLayer(disp)) parameters
static inline _glptr_NamedFramebufferTextureLayer GET_NamedFramebufferTextureLayer(struct _glapi_table *disp) {
   return (_glptr_NamedFramebufferTextureLayer) (GET_by_offset(disp, _gloffset_NamedFramebufferTextureLayer));
}

static inline void SET_NamedFramebufferTextureLayer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_NamedFramebufferTextureLayer, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedRenderbufferStorage)(GLuint, GLenum, GLsizei, GLsizei);
#define CALL_NamedRenderbufferStorage(disp, parameters) \
    (* GET_NamedRenderbufferStorage(disp)) parameters
static inline _glptr_NamedRenderbufferStorage GET_NamedRenderbufferStorage(struct _glapi_table *disp) {
   return (_glptr_NamedRenderbufferStorage) (GET_by_offset(disp, _gloffset_NamedRenderbufferStorage));
}

static inline void SET_NamedRenderbufferStorage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_NamedRenderbufferStorage, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedRenderbufferStorageMultisample)(GLuint, GLsizei, GLenum, GLsizei, GLsizei);
#define CALL_NamedRenderbufferStorageMultisample(disp, parameters) \
    (* GET_NamedRenderbufferStorageMultisample(disp)) parameters
static inline _glptr_NamedRenderbufferStorageMultisample GET_NamedRenderbufferStorageMultisample(struct _glapi_table *disp) {
   return (_glptr_NamedRenderbufferStorageMultisample) (GET_by_offset(disp, _gloffset_NamedRenderbufferStorageMultisample));
}

static inline void SET_NamedRenderbufferStorageMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_NamedRenderbufferStorageMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureBuffer)(GLuint, GLenum, GLuint);
#define CALL_TextureBuffer(disp, parameters) \
    (* GET_TextureBuffer(disp)) parameters
static inline _glptr_TextureBuffer GET_TextureBuffer(struct _glapi_table *disp) {
   return (_glptr_TextureBuffer) (GET_by_offset(disp, _gloffset_TextureBuffer));
}

static inline void SET_TextureBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_TextureBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureBufferRange)(GLuint, GLenum, GLuint, GLintptr, GLsizeiptr);
#define CALL_TextureBufferRange(disp, parameters) \
    (* GET_TextureBufferRange(disp)) parameters
static inline _glptr_TextureBufferRange GET_TextureBufferRange(struct _glapi_table *disp) {
   return (_glptr_TextureBufferRange) (GET_by_offset(disp, _gloffset_TextureBufferRange));
}

static inline void SET_TextureBufferRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_TextureBufferRange, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureParameterIiv)(GLuint, GLenum, const GLint *);
#define CALL_TextureParameterIiv(disp, parameters) \
    (* GET_TextureParameterIiv(disp)) parameters
static inline _glptr_TextureParameterIiv GET_TextureParameterIiv(struct _glapi_table *disp) {
   return (_glptr_TextureParameterIiv) (GET_by_offset(disp, _gloffset_TextureParameterIiv));
}

static inline void SET_TextureParameterIiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TextureParameterIiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureParameterIuiv)(GLuint, GLenum, const GLuint *);
#define CALL_TextureParameterIuiv(disp, parameters) \
    (* GET_TextureParameterIuiv(disp)) parameters
static inline _glptr_TextureParameterIuiv GET_TextureParameterIuiv(struct _glapi_table *disp) {
   return (_glptr_TextureParameterIuiv) (GET_by_offset(disp, _gloffset_TextureParameterIuiv));
}

static inline void SET_TextureParameterIuiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLuint *)) {
   SET_by_offset(disp, _gloffset_TextureParameterIuiv, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureParameterf)(GLuint, GLenum, GLfloat);
#define CALL_TextureParameterf(disp, parameters) \
    (* GET_TextureParameterf(disp)) parameters
static inline _glptr_TextureParameterf GET_TextureParameterf(struct _glapi_table *disp) {
   return (_glptr_TextureParameterf) (GET_by_offset(disp, _gloffset_TextureParameterf));
}

static inline void SET_TextureParameterf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLfloat)) {
   SET_by_offset(disp, _gloffset_TextureParameterf, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureParameterfv)(GLuint, GLenum, const GLfloat *);
#define CALL_TextureParameterfv(disp, parameters) \
    (* GET_TextureParameterfv(disp)) parameters
static inline _glptr_TextureParameterfv GET_TextureParameterfv(struct _glapi_table *disp) {
   return (_glptr_TextureParameterfv) (GET_by_offset(disp, _gloffset_TextureParameterfv));
}

static inline void SET_TextureParameterfv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TextureParameterfv, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureParameteri)(GLuint, GLenum, GLint);
#define CALL_TextureParameteri(disp, parameters) \
    (* GET_TextureParameteri(disp)) parameters
static inline _glptr_TextureParameteri GET_TextureParameteri(struct _glapi_table *disp) {
   return (_glptr_TextureParameteri) (GET_by_offset(disp, _gloffset_TextureParameteri));
}

static inline void SET_TextureParameteri(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_TextureParameteri, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureParameteriv)(GLuint, GLenum, const GLint *);
#define CALL_TextureParameteriv(disp, parameters) \
    (* GET_TextureParameteriv(disp)) parameters
static inline _glptr_TextureParameteriv GET_TextureParameteriv(struct _glapi_table *disp) {
   return (_glptr_TextureParameteriv) (GET_by_offset(disp, _gloffset_TextureParameteriv));
}

static inline void SET_TextureParameteriv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TextureParameteriv, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage1D)(GLuint, GLsizei, GLenum, GLsizei);
#define CALL_TextureStorage1D(disp, parameters) \
    (* GET_TextureStorage1D(disp)) parameters
static inline _glptr_TextureStorage1D GET_TextureStorage1D(struct _glapi_table *disp) {
   return (_glptr_TextureStorage1D) (GET_by_offset(disp, _gloffset_TextureStorage1D));
}

static inline void SET_TextureStorage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei)) {
   SET_by_offset(disp, _gloffset_TextureStorage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage2D)(GLuint, GLsizei, GLenum, GLsizei, GLsizei);
#define CALL_TextureStorage2D(disp, parameters) \
    (* GET_TextureStorage2D(disp)) parameters
static inline _glptr_TextureStorage2D GET_TextureStorage2D(struct _glapi_table *disp) {
   return (_glptr_TextureStorage2D) (GET_by_offset(disp, _gloffset_TextureStorage2D));
}

static inline void SET_TextureStorage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_TextureStorage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage2DMultisample)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
#define CALL_TextureStorage2DMultisample(disp, parameters) \
    (* GET_TextureStorage2DMultisample(disp)) parameters
static inline _glptr_TextureStorage2DMultisample GET_TextureStorage2DMultisample(struct _glapi_table *disp) {
   return (_glptr_TextureStorage2DMultisample) (GET_by_offset(disp, _gloffset_TextureStorage2DMultisample));
}

static inline void SET_TextureStorage2DMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean)) {
   SET_by_offset(disp, _gloffset_TextureStorage2DMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage3D)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
#define CALL_TextureStorage3D(disp, parameters) \
    (* GET_TextureStorage3D(disp)) parameters
static inline _glptr_TextureStorage3D GET_TextureStorage3D(struct _glapi_table *disp) {
   return (_glptr_TextureStorage3D) (GET_by_offset(disp, _gloffset_TextureStorage3D));
}

static inline void SET_TextureStorage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_TextureStorage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorage3DMultisample)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
#define CALL_TextureStorage3DMultisample(disp, parameters) \
    (* GET_TextureStorage3DMultisample(disp)) parameters
static inline _glptr_TextureStorage3DMultisample GET_TextureStorage3DMultisample(struct _glapi_table *disp) {
   return (_glptr_TextureStorage3DMultisample) (GET_by_offset(disp, _gloffset_TextureStorage3DMultisample));
}

static inline void SET_TextureStorage3DMultisample(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean)) {
   SET_by_offset(disp, _gloffset_TextureStorage3DMultisample, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureSubImage1D)(GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_TextureSubImage1D(disp, parameters) \
    (* GET_TextureSubImage1D(disp)) parameters
static inline _glptr_TextureSubImage1D GET_TextureSubImage1D(struct _glapi_table *disp) {
   return (_glptr_TextureSubImage1D) (GET_by_offset(disp, _gloffset_TextureSubImage1D));
}

static inline void SET_TextureSubImage1D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TextureSubImage1D, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureSubImage2D)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_TextureSubImage2D(disp, parameters) \
    (* GET_TextureSubImage2D(disp)) parameters
static inline _glptr_TextureSubImage2D GET_TextureSubImage2D(struct _glapi_table *disp) {
   return (_glptr_TextureSubImage2D) (GET_by_offset(disp, _gloffset_TextureSubImage2D));
}

static inline void SET_TextureSubImage2D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TextureSubImage2D, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureSubImage3D)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define CALL_TextureSubImage3D(disp, parameters) \
    (* GET_TextureSubImage3D(disp)) parameters
static inline _glptr_TextureSubImage3D GET_TextureSubImage3D(struct _glapi_table *disp) {
   return (_glptr_TextureSubImage3D) (GET_by_offset(disp, _gloffset_TextureSubImage3D));
}

static inline void SET_TextureSubImage3D(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TextureSubImage3D, fn);
}

typedef void (GLAPIENTRYP _glptr_TransformFeedbackBufferBase)(GLuint, GLuint, GLuint);
#define CALL_TransformFeedbackBufferBase(disp, parameters) \
    (* GET_TransformFeedbackBufferBase(disp)) parameters
static inline _glptr_TransformFeedbackBufferBase GET_TransformFeedbackBufferBase(struct _glapi_table *disp) {
   return (_glptr_TransformFeedbackBufferBase) (GET_by_offset(disp, _gloffset_TransformFeedbackBufferBase));
}

static inline void SET_TransformFeedbackBufferBase(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_TransformFeedbackBufferBase, fn);
}

typedef void (GLAPIENTRYP _glptr_TransformFeedbackBufferRange)(GLuint, GLuint, GLuint, GLintptr, GLsizeiptr);
#define CALL_TransformFeedbackBufferRange(disp, parameters) \
    (* GET_TransformFeedbackBufferRange(disp)) parameters
static inline _glptr_TransformFeedbackBufferRange GET_TransformFeedbackBufferRange(struct _glapi_table *disp) {
   return (_glptr_TransformFeedbackBufferRange) (GET_by_offset(disp, _gloffset_TransformFeedbackBufferRange));
}

static inline void SET_TransformFeedbackBufferRange(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_TransformFeedbackBufferRange, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_UnmapNamedBuffer)(GLuint);
#define CALL_UnmapNamedBuffer(disp, parameters) \
    (* GET_UnmapNamedBuffer(disp)) parameters
static inline _glptr_UnmapNamedBuffer GET_UnmapNamedBuffer(struct _glapi_table *disp) {
   return (_glptr_UnmapNamedBuffer) (GET_by_offset(disp, _gloffset_UnmapNamedBuffer));
}

static inline void SET_UnmapNamedBuffer(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_UnmapNamedBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayAttribBinding)(GLuint, GLuint, GLuint);
#define CALL_VertexArrayAttribBinding(disp, parameters) \
    (* GET_VertexArrayAttribBinding(disp)) parameters
static inline _glptr_VertexArrayAttribBinding GET_VertexArrayAttribBinding(struct _glapi_table *disp) {
   return (_glptr_VertexArrayAttribBinding) (GET_by_offset(disp, _gloffset_VertexArrayAttribBinding));
}

static inline void SET_VertexArrayAttribBinding(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexArrayAttribBinding, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayAttribFormat)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint);
#define CALL_VertexArrayAttribFormat(disp, parameters) \
    (* GET_VertexArrayAttribFormat(disp)) parameters
static inline _glptr_VertexArrayAttribFormat GET_VertexArrayAttribFormat(struct _glapi_table *disp) {
   return (_glptr_VertexArrayAttribFormat) (GET_by_offset(disp, _gloffset_VertexArrayAttribFormat));
}

static inline void SET_VertexArrayAttribFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexArrayAttribFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayAttribIFormat)(GLuint, GLuint, GLint, GLenum, GLuint);
#define CALL_VertexArrayAttribIFormat(disp, parameters) \
    (* GET_VertexArrayAttribIFormat(disp)) parameters
static inline _glptr_VertexArrayAttribIFormat GET_VertexArrayAttribIFormat(struct _glapi_table *disp) {
   return (_glptr_VertexArrayAttribIFormat) (GET_by_offset(disp, _gloffset_VertexArrayAttribIFormat));
}

static inline void SET_VertexArrayAttribIFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLint, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexArrayAttribIFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayAttribLFormat)(GLuint, GLuint, GLint, GLenum, GLuint);
#define CALL_VertexArrayAttribLFormat(disp, parameters) \
    (* GET_VertexArrayAttribLFormat(disp)) parameters
static inline _glptr_VertexArrayAttribLFormat GET_VertexArrayAttribLFormat(struct _glapi_table *disp) {
   return (_glptr_VertexArrayAttribLFormat) (GET_by_offset(disp, _gloffset_VertexArrayAttribLFormat));
}

static inline void SET_VertexArrayAttribLFormat(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLint, GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexArrayAttribLFormat, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayBindingDivisor)(GLuint, GLuint, GLuint);
#define CALL_VertexArrayBindingDivisor(disp, parameters) \
    (* GET_VertexArrayBindingDivisor(disp)) parameters
static inline _glptr_VertexArrayBindingDivisor GET_VertexArrayBindingDivisor(struct _glapi_table *disp) {
   return (_glptr_VertexArrayBindingDivisor) (GET_by_offset(disp, _gloffset_VertexArrayBindingDivisor));
}

static inline void SET_VertexArrayBindingDivisor(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexArrayBindingDivisor, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayElementBuffer)(GLuint, GLuint);
#define CALL_VertexArrayElementBuffer(disp, parameters) \
    (* GET_VertexArrayElementBuffer(disp)) parameters
static inline _glptr_VertexArrayElementBuffer GET_VertexArrayElementBuffer(struct _glapi_table *disp) {
   return (_glptr_VertexArrayElementBuffer) (GET_by_offset(disp, _gloffset_VertexArrayElementBuffer));
}

static inline void SET_VertexArrayElementBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexArrayElementBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayVertexBuffer)(GLuint, GLuint, GLuint, GLintptr, GLsizei);
#define CALL_VertexArrayVertexBuffer(disp, parameters) \
    (* GET_VertexArrayVertexBuffer(disp)) parameters
static inline _glptr_VertexArrayVertexBuffer GET_VertexArrayVertexBuffer(struct _glapi_table *disp) {
   return (_glptr_VertexArrayVertexBuffer) (GET_by_offset(disp, _gloffset_VertexArrayVertexBuffer));
}

static inline void SET_VertexArrayVertexBuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLintptr, GLsizei)) {
   SET_by_offset(disp, _gloffset_VertexArrayVertexBuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexArrayVertexBuffers)(GLuint, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *);
#define CALL_VertexArrayVertexBuffers(disp, parameters) \
    (* GET_VertexArrayVertexBuffers(disp)) parameters
static inline _glptr_VertexArrayVertexBuffers GET_VertexArrayVertexBuffers(struct _glapi_table *disp) {
   return (_glptr_VertexArrayVertexBuffers) (GET_by_offset(disp, _gloffset_VertexArrayVertexBuffers));
}

static inline void SET_VertexArrayVertexBuffers(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *)) {
   SET_by_offset(disp, _gloffset_VertexArrayVertexBuffers, fn);
}

typedef void (GLAPIENTRYP _glptr_GetCompressedTextureSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLvoid *);
#define CALL_GetCompressedTextureSubImage(disp, parameters) \
    (* GET_GetCompressedTextureSubImage(disp)) parameters
static inline _glptr_GetCompressedTextureSubImage GET_GetCompressedTextureSubImage(struct _glapi_table *disp) {
   return (_glptr_GetCompressedTextureSubImage) (GET_by_offset(disp, _gloffset_GetCompressedTextureSubImage));
}

static inline void SET_GetCompressedTextureSubImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetCompressedTextureSubImage, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTextureSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *);
#define CALL_GetTextureSubImage(disp, parameters) \
    (* GET_GetTextureSubImage(disp)) parameters
static inline _glptr_GetTextureSubImage GET_GetTextureSubImage(struct _glapi_table *disp) {
   return (_glptr_GetTextureSubImage) (GET_by_offset(disp, _gloffset_GetTextureSubImage));
}

static inline void SET_GetTextureSubImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetTextureSubImage, fn);
}

typedef void (GLAPIENTRYP _glptr_BufferPageCommitmentARB)(GLenum, GLintptr, GLsizeiptr, GLboolean);
#define CALL_BufferPageCommitmentARB(disp, parameters) \
    (* GET_BufferPageCommitmentARB(disp)) parameters
static inline _glptr_BufferPageCommitmentARB GET_BufferPageCommitmentARB(struct _glapi_table *disp) {
   return (_glptr_BufferPageCommitmentARB) (GET_by_offset(disp, _gloffset_BufferPageCommitmentARB));
}

static inline void SET_BufferPageCommitmentARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLintptr, GLsizeiptr, GLboolean)) {
   SET_by_offset(disp, _gloffset_BufferPageCommitmentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedBufferPageCommitmentARB)(GLuint, GLintptr, GLsizeiptr, GLboolean);
#define CALL_NamedBufferPageCommitmentARB(disp, parameters) \
    (* GET_NamedBufferPageCommitmentARB(disp)) parameters
static inline _glptr_NamedBufferPageCommitmentARB GET_NamedBufferPageCommitmentARB(struct _glapi_table *disp) {
   return (_glptr_NamedBufferPageCommitmentARB) (GET_by_offset(disp, _gloffset_NamedBufferPageCommitmentARB));
}

static inline void SET_NamedBufferPageCommitmentARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLintptr, GLsizeiptr, GLboolean)) {
   SET_by_offset(disp, _gloffset_NamedBufferPageCommitmentARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformi64vARB)(GLuint, GLint, GLint64 *);
#define CALL_GetUniformi64vARB(disp, parameters) \
    (* GET_GetUniformi64vARB(disp)) parameters
static inline _glptr_GetUniformi64vARB GET_GetUniformi64vARB(struct _glapi_table *disp) {
   return (_glptr_GetUniformi64vARB) (GET_by_offset(disp, _gloffset_GetUniformi64vARB));
}

static inline void SET_GetUniformi64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetUniformi64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUniformui64vARB)(GLuint, GLint, GLuint64 *);
#define CALL_GetUniformui64vARB(disp, parameters) \
    (* GET_GetUniformui64vARB(disp)) parameters
static inline _glptr_GetUniformui64vARB GET_GetUniformui64vARB(struct _glapi_table *disp) {
   return (_glptr_GetUniformui64vARB) (GET_by_offset(disp, _gloffset_GetUniformui64vARB));
}

static inline void SET_GetUniformui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint64 *)) {
   SET_by_offset(disp, _gloffset_GetUniformui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnUniformi64vARB)(GLuint, GLint, GLsizei, GLint64 *);
#define CALL_GetnUniformi64vARB(disp, parameters) \
    (* GET_GetnUniformi64vARB(disp)) parameters
static inline _glptr_GetnUniformi64vARB GET_GetnUniformi64vARB(struct _glapi_table *disp) {
   return (_glptr_GetnUniformi64vARB) (GET_by_offset(disp, _gloffset_GetnUniformi64vARB));
}

static inline void SET_GetnUniformi64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLint64 *)) {
   SET_by_offset(disp, _gloffset_GetnUniformi64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_GetnUniformui64vARB)(GLuint, GLint, GLsizei, GLuint64 *);
#define CALL_GetnUniformui64vARB(disp, parameters) \
    (* GET_GetnUniformui64vARB(disp)) parameters
static inline _glptr_GetnUniformui64vARB GET_GetnUniformui64vARB(struct _glapi_table *disp) {
   return (_glptr_GetnUniformui64vARB) (GET_by_offset(disp, _gloffset_GetnUniformui64vARB));
}

static inline void SET_GetnUniformui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLuint64 *)) {
   SET_by_offset(disp, _gloffset_GetnUniformui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1i64ARB)(GLuint, GLint, GLint64);
#define CALL_ProgramUniform1i64ARB(disp, parameters) \
    (* GET_ProgramUniform1i64ARB(disp)) parameters
static inline _glptr_ProgramUniform1i64ARB GET_ProgramUniform1i64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1i64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform1i64ARB));
}

static inline void SET_ProgramUniform1i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1i64vARB)(GLuint, GLint, GLsizei, const GLint64 *);
#define CALL_ProgramUniform1i64vARB(disp, parameters) \
    (* GET_ProgramUniform1i64vARB(disp)) parameters
static inline _glptr_ProgramUniform1i64vARB GET_ProgramUniform1i64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1i64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform1i64vARB));
}

static inline void SET_ProgramUniform1i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1ui64ARB)(GLuint, GLint, GLuint64);
#define CALL_ProgramUniform1ui64ARB(disp, parameters) \
    (* GET_ProgramUniform1ui64ARB(disp)) parameters
static inline _glptr_ProgramUniform1ui64ARB GET_ProgramUniform1ui64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1ui64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform1ui64ARB));
}

static inline void SET_ProgramUniform1ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1ui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *);
#define CALL_ProgramUniform1ui64vARB(disp, parameters) \
    (* GET_ProgramUniform1ui64vARB(disp)) parameters
static inline _glptr_ProgramUniform1ui64vARB GET_ProgramUniform1ui64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1ui64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform1ui64vARB));
}

static inline void SET_ProgramUniform1ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2i64ARB)(GLuint, GLint, GLint64, GLint64);
#define CALL_ProgramUniform2i64ARB(disp, parameters) \
    (* GET_ProgramUniform2i64ARB(disp)) parameters
static inline _glptr_ProgramUniform2i64ARB GET_ProgramUniform2i64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2i64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform2i64ARB));
}

static inline void SET_ProgramUniform2i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint64, GLint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2i64vARB)(GLuint, GLint, GLsizei, const GLint64 *);
#define CALL_ProgramUniform2i64vARB(disp, parameters) \
    (* GET_ProgramUniform2i64vARB(disp)) parameters
static inline _glptr_ProgramUniform2i64vARB GET_ProgramUniform2i64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2i64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform2i64vARB));
}

static inline void SET_ProgramUniform2i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2ui64ARB)(GLuint, GLint, GLuint64, GLuint64);
#define CALL_ProgramUniform2ui64ARB(disp, parameters) \
    (* GET_ProgramUniform2ui64ARB(disp)) parameters
static inline _glptr_ProgramUniform2ui64ARB GET_ProgramUniform2ui64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2ui64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform2ui64ARB));
}

static inline void SET_ProgramUniform2ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint64, GLuint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2ui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *);
#define CALL_ProgramUniform2ui64vARB(disp, parameters) \
    (* GET_ProgramUniform2ui64vARB(disp)) parameters
static inline _glptr_ProgramUniform2ui64vARB GET_ProgramUniform2ui64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2ui64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform2ui64vARB));
}

static inline void SET_ProgramUniform2ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3i64ARB)(GLuint, GLint, GLint64, GLint64, GLint64);
#define CALL_ProgramUniform3i64ARB(disp, parameters) \
    (* GET_ProgramUniform3i64ARB(disp)) parameters
static inline _glptr_ProgramUniform3i64ARB GET_ProgramUniform3i64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3i64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform3i64ARB));
}

static inline void SET_ProgramUniform3i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint64, GLint64, GLint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3i64vARB)(GLuint, GLint, GLsizei, const GLint64 *);
#define CALL_ProgramUniform3i64vARB(disp, parameters) \
    (* GET_ProgramUniform3i64vARB(disp)) parameters
static inline _glptr_ProgramUniform3i64vARB GET_ProgramUniform3i64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3i64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform3i64vARB));
}

static inline void SET_ProgramUniform3i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3ui64ARB)(GLuint, GLint, GLuint64, GLuint64, GLuint64);
#define CALL_ProgramUniform3ui64ARB(disp, parameters) \
    (* GET_ProgramUniform3ui64ARB(disp)) parameters
static inline _glptr_ProgramUniform3ui64ARB GET_ProgramUniform3ui64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3ui64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform3ui64ARB));
}

static inline void SET_ProgramUniform3ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint64, GLuint64, GLuint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3ui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *);
#define CALL_ProgramUniform3ui64vARB(disp, parameters) \
    (* GET_ProgramUniform3ui64vARB(disp)) parameters
static inline _glptr_ProgramUniform3ui64vARB GET_ProgramUniform3ui64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3ui64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform3ui64vARB));
}

static inline void SET_ProgramUniform3ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4i64ARB)(GLuint, GLint, GLint64, GLint64, GLint64, GLint64);
#define CALL_ProgramUniform4i64ARB(disp, parameters) \
    (* GET_ProgramUniform4i64ARB(disp)) parameters
static inline _glptr_ProgramUniform4i64ARB GET_ProgramUniform4i64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4i64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform4i64ARB));
}

static inline void SET_ProgramUniform4i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint64, GLint64, GLint64, GLint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4i64vARB)(GLuint, GLint, GLsizei, const GLint64 *);
#define CALL_ProgramUniform4i64vARB(disp, parameters) \
    (* GET_ProgramUniform4i64vARB(disp)) parameters
static inline _glptr_ProgramUniform4i64vARB GET_ProgramUniform4i64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4i64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform4i64vARB));
}

static inline void SET_ProgramUniform4i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4ui64ARB)(GLuint, GLint, GLuint64, GLuint64, GLuint64, GLuint64);
#define CALL_ProgramUniform4ui64ARB(disp, parameters) \
    (* GET_ProgramUniform4ui64ARB(disp)) parameters
static inline _glptr_ProgramUniform4ui64ARB GET_ProgramUniform4ui64ARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4ui64ARB) (GET_by_offset(disp, _gloffset_ProgramUniform4ui64ARB));
}

static inline void SET_ProgramUniform4ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint64, GLuint64, GLuint64, GLuint64)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4ui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *);
#define CALL_ProgramUniform4ui64vARB(disp, parameters) \
    (* GET_ProgramUniform4ui64vARB(disp)) parameters
static inline _glptr_ProgramUniform4ui64vARB GET_ProgramUniform4ui64vARB(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4ui64vARB) (GET_by_offset(disp, _gloffset_ProgramUniform4ui64vARB));
}

static inline void SET_ProgramUniform4ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1i64ARB)(GLint, GLint64);
#define CALL_Uniform1i64ARB(disp, parameters) \
    (* GET_Uniform1i64ARB(disp)) parameters
static inline _glptr_Uniform1i64ARB GET_Uniform1i64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform1i64ARB) (GET_by_offset(disp, _gloffset_Uniform1i64ARB));
}

static inline void SET_Uniform1i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint64)) {
   SET_by_offset(disp, _gloffset_Uniform1i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1i64vARB)(GLint, GLsizei, const GLint64 *);
#define CALL_Uniform1i64vARB(disp, parameters) \
    (* GET_Uniform1i64vARB(disp)) parameters
static inline _glptr_Uniform1i64vARB GET_Uniform1i64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform1i64vARB) (GET_by_offset(disp, _gloffset_Uniform1i64vARB));
}

static inline void SET_Uniform1i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform1i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1ui64ARB)(GLint, GLuint64);
#define CALL_Uniform1ui64ARB(disp, parameters) \
    (* GET_Uniform1ui64ARB(disp)) parameters
static inline _glptr_Uniform1ui64ARB GET_Uniform1ui64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform1ui64ARB) (GET_by_offset(disp, _gloffset_Uniform1ui64ARB));
}

static inline void SET_Uniform1ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint64)) {
   SET_by_offset(disp, _gloffset_Uniform1ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform1ui64vARB)(GLint, GLsizei, const GLuint64 *);
#define CALL_Uniform1ui64vARB(disp, parameters) \
    (* GET_Uniform1ui64vARB(disp)) parameters
static inline _glptr_Uniform1ui64vARB GET_Uniform1ui64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform1ui64vARB) (GET_by_offset(disp, _gloffset_Uniform1ui64vARB));
}

static inline void SET_Uniform1ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform1ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2i64ARB)(GLint, GLint64, GLint64);
#define CALL_Uniform2i64ARB(disp, parameters) \
    (* GET_Uniform2i64ARB(disp)) parameters
static inline _glptr_Uniform2i64ARB GET_Uniform2i64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform2i64ARB) (GET_by_offset(disp, _gloffset_Uniform2i64ARB));
}

static inline void SET_Uniform2i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint64, GLint64)) {
   SET_by_offset(disp, _gloffset_Uniform2i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2i64vARB)(GLint, GLsizei, const GLint64 *);
#define CALL_Uniform2i64vARB(disp, parameters) \
    (* GET_Uniform2i64vARB(disp)) parameters
static inline _glptr_Uniform2i64vARB GET_Uniform2i64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform2i64vARB) (GET_by_offset(disp, _gloffset_Uniform2i64vARB));
}

static inline void SET_Uniform2i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform2i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2ui64ARB)(GLint, GLuint64, GLuint64);
#define CALL_Uniform2ui64ARB(disp, parameters) \
    (* GET_Uniform2ui64ARB(disp)) parameters
static inline _glptr_Uniform2ui64ARB GET_Uniform2ui64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform2ui64ARB) (GET_by_offset(disp, _gloffset_Uniform2ui64ARB));
}

static inline void SET_Uniform2ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint64, GLuint64)) {
   SET_by_offset(disp, _gloffset_Uniform2ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform2ui64vARB)(GLint, GLsizei, const GLuint64 *);
#define CALL_Uniform2ui64vARB(disp, parameters) \
    (* GET_Uniform2ui64vARB(disp)) parameters
static inline _glptr_Uniform2ui64vARB GET_Uniform2ui64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform2ui64vARB) (GET_by_offset(disp, _gloffset_Uniform2ui64vARB));
}

static inline void SET_Uniform2ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform2ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3i64ARB)(GLint, GLint64, GLint64, GLint64);
#define CALL_Uniform3i64ARB(disp, parameters) \
    (* GET_Uniform3i64ARB(disp)) parameters
static inline _glptr_Uniform3i64ARB GET_Uniform3i64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform3i64ARB) (GET_by_offset(disp, _gloffset_Uniform3i64ARB));
}

static inline void SET_Uniform3i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint64, GLint64, GLint64)) {
   SET_by_offset(disp, _gloffset_Uniform3i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3i64vARB)(GLint, GLsizei, const GLint64 *);
#define CALL_Uniform3i64vARB(disp, parameters) \
    (* GET_Uniform3i64vARB(disp)) parameters
static inline _glptr_Uniform3i64vARB GET_Uniform3i64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform3i64vARB) (GET_by_offset(disp, _gloffset_Uniform3i64vARB));
}

static inline void SET_Uniform3i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform3i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3ui64ARB)(GLint, GLuint64, GLuint64, GLuint64);
#define CALL_Uniform3ui64ARB(disp, parameters) \
    (* GET_Uniform3ui64ARB(disp)) parameters
static inline _glptr_Uniform3ui64ARB GET_Uniform3ui64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform3ui64ARB) (GET_by_offset(disp, _gloffset_Uniform3ui64ARB));
}

static inline void SET_Uniform3ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint64, GLuint64, GLuint64)) {
   SET_by_offset(disp, _gloffset_Uniform3ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform3ui64vARB)(GLint, GLsizei, const GLuint64 *);
#define CALL_Uniform3ui64vARB(disp, parameters) \
    (* GET_Uniform3ui64vARB(disp)) parameters
static inline _glptr_Uniform3ui64vARB GET_Uniform3ui64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform3ui64vARB) (GET_by_offset(disp, _gloffset_Uniform3ui64vARB));
}

static inline void SET_Uniform3ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform3ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4i64ARB)(GLint, GLint64, GLint64, GLint64, GLint64);
#define CALL_Uniform4i64ARB(disp, parameters) \
    (* GET_Uniform4i64ARB(disp)) parameters
static inline _glptr_Uniform4i64ARB GET_Uniform4i64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform4i64ARB) (GET_by_offset(disp, _gloffset_Uniform4i64ARB));
}

static inline void SET_Uniform4i64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint64, GLint64, GLint64, GLint64)) {
   SET_by_offset(disp, _gloffset_Uniform4i64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4i64vARB)(GLint, GLsizei, const GLint64 *);
#define CALL_Uniform4i64vARB(disp, parameters) \
    (* GET_Uniform4i64vARB(disp)) parameters
static inline _glptr_Uniform4i64vARB GET_Uniform4i64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform4i64vARB) (GET_by_offset(disp, _gloffset_Uniform4i64vARB));
}

static inline void SET_Uniform4i64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform4i64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4ui64ARB)(GLint, GLuint64, GLuint64, GLuint64, GLuint64);
#define CALL_Uniform4ui64ARB(disp, parameters) \
    (* GET_Uniform4ui64ARB(disp)) parameters
static inline _glptr_Uniform4ui64ARB GET_Uniform4ui64ARB(struct _glapi_table *disp) {
   return (_glptr_Uniform4ui64ARB) (GET_by_offset(disp, _gloffset_Uniform4ui64ARB));
}

static inline void SET_Uniform4ui64ARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLuint64, GLuint64, GLuint64, GLuint64)) {
   SET_by_offset(disp, _gloffset_Uniform4ui64ARB, fn);
}

typedef void (GLAPIENTRYP _glptr_Uniform4ui64vARB)(GLint, GLsizei, const GLuint64 *);
#define CALL_Uniform4ui64vARB(disp, parameters) \
    (* GET_Uniform4ui64vARB(disp)) parameters
static inline _glptr_Uniform4ui64vARB GET_Uniform4ui64vARB(struct _glapi_table *disp) {
   return (_glptr_Uniform4ui64vARB) (GET_by_offset(disp, _gloffset_Uniform4ui64vARB));
}

static inline void SET_Uniform4ui64vARB(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_Uniform4ui64vARB, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateBufferData)(GLuint);
#define CALL_InvalidateBufferData(disp, parameters) \
    (* GET_InvalidateBufferData(disp)) parameters
static inline _glptr_InvalidateBufferData GET_InvalidateBufferData(struct _glapi_table *disp) {
   return (_glptr_InvalidateBufferData) (GET_by_offset(disp, _gloffset_InvalidateBufferData));
}

static inline void SET_InvalidateBufferData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_InvalidateBufferData, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateBufferSubData)(GLuint, GLintptr, GLsizeiptr);
#define CALL_InvalidateBufferSubData(disp, parameters) \
    (* GET_InvalidateBufferSubData(disp)) parameters
static inline _glptr_InvalidateBufferSubData GET_InvalidateBufferSubData(struct _glapi_table *disp) {
   return (_glptr_InvalidateBufferSubData) (GET_by_offset(disp, _gloffset_InvalidateBufferSubData));
}

static inline void SET_InvalidateBufferSubData(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_InvalidateBufferSubData, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateFramebuffer)(GLenum, GLsizei, const GLenum *);
#define CALL_InvalidateFramebuffer(disp, parameters) \
    (* GET_InvalidateFramebuffer(disp)) parameters
static inline _glptr_InvalidateFramebuffer GET_InvalidateFramebuffer(struct _glapi_table *disp) {
   return (_glptr_InvalidateFramebuffer) (GET_by_offset(disp, _gloffset_InvalidateFramebuffer));
}

static inline void SET_InvalidateFramebuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLenum *)) {
   SET_by_offset(disp, _gloffset_InvalidateFramebuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateSubFramebuffer)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei);
#define CALL_InvalidateSubFramebuffer(disp, parameters) \
    (* GET_InvalidateSubFramebuffer(disp)) parameters
static inline _glptr_InvalidateSubFramebuffer GET_InvalidateSubFramebuffer(struct _glapi_table *disp) {
   return (_glptr_InvalidateSubFramebuffer) (GET_by_offset(disp, _gloffset_InvalidateSubFramebuffer));
}

static inline void SET_InvalidateSubFramebuffer(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_InvalidateSubFramebuffer, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateTexImage)(GLuint, GLint);
#define CALL_InvalidateTexImage(disp, parameters) \
    (* GET_InvalidateTexImage(disp)) parameters
static inline _glptr_InvalidateTexImage GET_InvalidateTexImage(struct _glapi_table *disp) {
   return (_glptr_InvalidateTexImage) (GET_by_offset(disp, _gloffset_InvalidateTexImage));
}

static inline void SET_InvalidateTexImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint)) {
   SET_by_offset(disp, _gloffset_InvalidateTexImage, fn);
}

typedef void (GLAPIENTRYP _glptr_InvalidateTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define CALL_InvalidateTexSubImage(disp, parameters) \
    (* GET_InvalidateTexSubImage(disp)) parameters
static inline _glptr_InvalidateTexSubImage GET_InvalidateTexSubImage(struct _glapi_table *disp) {
   return (_glptr_InvalidateTexSubImage) (GET_by_offset(disp, _gloffset_InvalidateTexSubImage));
}

static inline void SET_InvalidateTexSubImage(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei)) {
   SET_by_offset(disp, _gloffset_InvalidateTexSubImage, fn);
}

typedef void (GLAPIENTRYP _glptr_PolygonOffsetEXT)(GLfloat, GLfloat);
#define CALL_PolygonOffsetEXT(disp, parameters) \
    (* GET_PolygonOffsetEXT(disp)) parameters
static inline _glptr_PolygonOffsetEXT GET_PolygonOffsetEXT(struct _glapi_table *disp) {
   return (_glptr_PolygonOffsetEXT) (GET_by_offset(disp, _gloffset_PolygonOffsetEXT));
}

static inline void SET_PolygonOffsetEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_PolygonOffsetEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexfOES)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_DrawTexfOES(disp, parameters) \
    (* GET_DrawTexfOES(disp)) parameters
static inline _glptr_DrawTexfOES GET_DrawTexfOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexfOES) (GET_by_offset(disp, _gloffset_DrawTexfOES));
}

static inline void SET_DrawTexfOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_DrawTexfOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexfvOES)(const GLfloat *);
#define CALL_DrawTexfvOES(disp, parameters) \
    (* GET_DrawTexfvOES(disp)) parameters
static inline _glptr_DrawTexfvOES GET_DrawTexfvOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexfvOES) (GET_by_offset(disp, _gloffset_DrawTexfvOES));
}

static inline void SET_DrawTexfvOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_DrawTexfvOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexiOES)(GLint, GLint, GLint, GLint, GLint);
#define CALL_DrawTexiOES(disp, parameters) \
    (* GET_DrawTexiOES(disp)) parameters
static inline _glptr_DrawTexiOES GET_DrawTexiOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexiOES) (GET_by_offset(disp, _gloffset_DrawTexiOES));
}

static inline void SET_DrawTexiOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_DrawTexiOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexivOES)(const GLint *);
#define CALL_DrawTexivOES(disp, parameters) \
    (* GET_DrawTexivOES(disp)) parameters
static inline _glptr_DrawTexivOES GET_DrawTexivOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexivOES) (GET_by_offset(disp, _gloffset_DrawTexivOES));
}

static inline void SET_DrawTexivOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_DrawTexivOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexsOES)(GLshort, GLshort, GLshort, GLshort, GLshort);
#define CALL_DrawTexsOES(disp, parameters) \
    (* GET_DrawTexsOES(disp)) parameters
static inline _glptr_DrawTexsOES GET_DrawTexsOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexsOES) (GET_by_offset(disp, _gloffset_DrawTexsOES));
}

static inline void SET_DrawTexsOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_DrawTexsOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexsvOES)(const GLshort *);
#define CALL_DrawTexsvOES(disp, parameters) \
    (* GET_DrawTexsvOES(disp)) parameters
static inline _glptr_DrawTexsvOES GET_DrawTexsvOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexsvOES) (GET_by_offset(disp, _gloffset_DrawTexsvOES));
}

static inline void SET_DrawTexsvOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_DrawTexsvOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexxOES)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed);
#define CALL_DrawTexxOES(disp, parameters) \
    (* GET_DrawTexxOES(disp)) parameters
static inline _glptr_DrawTexxOES GET_DrawTexxOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexxOES) (GET_by_offset(disp, _gloffset_DrawTexxOES));
}

static inline void SET_DrawTexxOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_DrawTexxOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DrawTexxvOES)(const GLfixed *);
#define CALL_DrawTexxvOES(disp, parameters) \
    (* GET_DrawTexxvOES(disp)) parameters
static inline _glptr_DrawTexxvOES GET_DrawTexxvOES(struct _glapi_table *disp) {
   return (_glptr_DrawTexxvOES) (GET_by_offset(disp, _gloffset_DrawTexxvOES));
}

static inline void SET_DrawTexxvOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfixed *)) {
   SET_by_offset(disp, _gloffset_DrawTexxvOES, fn);
}

typedef void (GLAPIENTRYP _glptr_PointSizePointerOES)(GLenum, GLsizei, const GLvoid *);
#define CALL_PointSizePointerOES(disp, parameters) \
    (* GET_PointSizePointerOES(disp)) parameters
static inline _glptr_PointSizePointerOES GET_PointSizePointerOES(struct _glapi_table *disp) {
   return (_glptr_PointSizePointerOES) (GET_by_offset(disp, _gloffset_PointSizePointerOES));
}

static inline void SET_PointSizePointerOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_PointSizePointerOES, fn);
}

typedef GLbitfield (GLAPIENTRYP _glptr_QueryMatrixxOES)(GLfixed *, GLint *);
#define CALL_QueryMatrixxOES(disp, parameters) \
    (* GET_QueryMatrixxOES(disp)) parameters
static inline _glptr_QueryMatrixxOES GET_QueryMatrixxOES(struct _glapi_table *disp) {
   return (_glptr_QueryMatrixxOES) (GET_by_offset(disp, _gloffset_QueryMatrixxOES));
}

static inline void SET_QueryMatrixxOES(struct _glapi_table *disp, GLbitfield (GLAPIENTRYP fn)(GLfixed *, GLint *)) {
   SET_by_offset(disp, _gloffset_QueryMatrixxOES, fn);
}

typedef void (GLAPIENTRYP _glptr_SampleMaskSGIS)(GLclampf, GLboolean);
#define CALL_SampleMaskSGIS(disp, parameters) \
    (* GET_SampleMaskSGIS(disp)) parameters
static inline _glptr_SampleMaskSGIS GET_SampleMaskSGIS(struct _glapi_table *disp) {
   return (_glptr_SampleMaskSGIS) (GET_by_offset(disp, _gloffset_SampleMaskSGIS));
}

static inline void SET_SampleMaskSGIS(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampf, GLboolean)) {
   SET_by_offset(disp, _gloffset_SampleMaskSGIS, fn);
}

typedef void (GLAPIENTRYP _glptr_SamplePatternSGIS)(GLenum);
#define CALL_SamplePatternSGIS(disp, parameters) \
    (* GET_SamplePatternSGIS(disp)) parameters
static inline _glptr_SamplePatternSGIS GET_SamplePatternSGIS(struct _glapi_table *disp) {
   return (_glptr_SamplePatternSGIS) (GET_by_offset(disp, _gloffset_SamplePatternSGIS));
}

static inline void SET_SamplePatternSGIS(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_SamplePatternSGIS, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
#define CALL_ColorPointerEXT(disp, parameters) \
    (* GET_ColorPointerEXT(disp)) parameters
static inline _glptr_ColorPointerEXT GET_ColorPointerEXT(struct _glapi_table *disp) {
   return (_glptr_ColorPointerEXT) (GET_by_offset(disp, _gloffset_ColorPointerEXT));
}

static inline void SET_ColorPointerEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_ColorPointerEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_EdgeFlagPointerEXT)(GLsizei, GLsizei, const GLboolean *);
#define CALL_EdgeFlagPointerEXT(disp, parameters) \
    (* GET_EdgeFlagPointerEXT(disp)) parameters
static inline _glptr_EdgeFlagPointerEXT GET_EdgeFlagPointerEXT(struct _glapi_table *disp) {
   return (_glptr_EdgeFlagPointerEXT) (GET_by_offset(disp, _gloffset_EdgeFlagPointerEXT));
}

static inline void SET_EdgeFlagPointerEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLsizei, const GLboolean *)) {
   SET_by_offset(disp, _gloffset_EdgeFlagPointerEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_IndexPointerEXT)(GLenum, GLsizei, GLsizei, const GLvoid *);
#define CALL_IndexPointerEXT(disp, parameters) \
    (* GET_IndexPointerEXT(disp)) parameters
static inline _glptr_IndexPointerEXT GET_IndexPointerEXT(struct _glapi_table *disp) {
   return (_glptr_IndexPointerEXT) (GET_by_offset(disp, _gloffset_IndexPointerEXT));
}

static inline void SET_IndexPointerEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_IndexPointerEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_NormalPointerEXT)(GLenum, GLsizei, GLsizei, const GLvoid *);
#define CALL_NormalPointerEXT(disp, parameters) \
    (* GET_NormalPointerEXT(disp)) parameters
static inline _glptr_NormalPointerEXT GET_NormalPointerEXT(struct _glapi_table *disp) {
   return (_glptr_NormalPointerEXT) (GET_by_offset(disp, _gloffset_NormalPointerEXT));
}

static inline void SET_NormalPointerEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_NormalPointerEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TexCoordPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
#define CALL_TexCoordPointerEXT(disp, parameters) \
    (* GET_TexCoordPointerEXT(disp)) parameters
static inline _glptr_TexCoordPointerEXT GET_TexCoordPointerEXT(struct _glapi_table *disp) {
   return (_glptr_TexCoordPointerEXT) (GET_by_offset(disp, _gloffset_TexCoordPointerEXT));
}

static inline void SET_TexCoordPointerEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_TexCoordPointerEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
#define CALL_VertexPointerEXT(disp, parameters) \
    (* GET_VertexPointerEXT(disp)) parameters
static inline _glptr_VertexPointerEXT GET_VertexPointerEXT(struct _glapi_table *disp) {
   return (_glptr_VertexPointerEXT) (GET_by_offset(disp, _gloffset_VertexPointerEXT));
}

static inline void SET_VertexPointerEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VertexPointerEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_DiscardFramebufferEXT)(GLenum, GLsizei, const GLenum *);
#define CALL_DiscardFramebufferEXT(disp, parameters) \
    (* GET_DiscardFramebufferEXT(disp)) parameters
static inline _glptr_DiscardFramebufferEXT GET_DiscardFramebufferEXT(struct _glapi_table *disp) {
   return (_glptr_DiscardFramebufferEXT) (GET_by_offset(disp, _gloffset_DiscardFramebufferEXT));
}

static inline void SET_DiscardFramebufferEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLenum *)) {
   SET_by_offset(disp, _gloffset_DiscardFramebufferEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ActiveShaderProgram)(GLuint, GLuint);
#define CALL_ActiveShaderProgram(disp, parameters) \
    (* GET_ActiveShaderProgram(disp)) parameters
static inline _glptr_ActiveShaderProgram GET_ActiveShaderProgram(struct _glapi_table *disp) {
   return (_glptr_ActiveShaderProgram) (GET_by_offset(disp, _gloffset_ActiveShaderProgram));
}

static inline void SET_ActiveShaderProgram(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ActiveShaderProgram, fn);
}

typedef void (GLAPIENTRYP _glptr_BindProgramPipeline)(GLuint);
#define CALL_BindProgramPipeline(disp, parameters) \
    (* GET_BindProgramPipeline(disp)) parameters
static inline _glptr_BindProgramPipeline GET_BindProgramPipeline(struct _glapi_table *disp) {
   return (_glptr_BindProgramPipeline) (GET_by_offset(disp, _gloffset_BindProgramPipeline));
}

static inline void SET_BindProgramPipeline(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_BindProgramPipeline, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_CreateShaderProgramv)(GLenum, GLsizei, const GLchar * const *);
#define CALL_CreateShaderProgramv(disp, parameters) \
    (* GET_CreateShaderProgramv(disp)) parameters
static inline _glptr_CreateShaderProgramv GET_CreateShaderProgramv(struct _glapi_table *disp) {
   return (_glptr_CreateShaderProgramv) (GET_by_offset(disp, _gloffset_CreateShaderProgramv));
}

static inline void SET_CreateShaderProgramv(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLenum, GLsizei, const GLchar * const *)) {
   SET_by_offset(disp, _gloffset_CreateShaderProgramv, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteProgramPipelines)(GLsizei, const GLuint *);
#define CALL_DeleteProgramPipelines(disp, parameters) \
    (* GET_DeleteProgramPipelines(disp)) parameters
static inline _glptr_DeleteProgramPipelines GET_DeleteProgramPipelines(struct _glapi_table *disp) {
   return (_glptr_DeleteProgramPipelines) (GET_by_offset(disp, _gloffset_DeleteProgramPipelines));
}

static inline void SET_DeleteProgramPipelines(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteProgramPipelines, fn);
}

typedef void (GLAPIENTRYP _glptr_GenProgramPipelines)(GLsizei, GLuint *);
#define CALL_GenProgramPipelines(disp, parameters) \
    (* GET_GenProgramPipelines(disp)) parameters
static inline _glptr_GenProgramPipelines GET_GenProgramPipelines(struct _glapi_table *disp) {
   return (_glptr_GenProgramPipelines) (GET_by_offset(disp, _gloffset_GenProgramPipelines));
}

static inline void SET_GenProgramPipelines(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenProgramPipelines, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramPipelineInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetProgramPipelineInfoLog(disp, parameters) \
    (* GET_GetProgramPipelineInfoLog(disp)) parameters
static inline _glptr_GetProgramPipelineInfoLog GET_GetProgramPipelineInfoLog(struct _glapi_table *disp) {
   return (_glptr_GetProgramPipelineInfoLog) (GET_by_offset(disp, _gloffset_GetProgramPipelineInfoLog));
}

static inline void SET_GetProgramPipelineInfoLog(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetProgramPipelineInfoLog, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramPipelineiv)(GLuint, GLenum, GLint *);
#define CALL_GetProgramPipelineiv(disp, parameters) \
    (* GET_GetProgramPipelineiv(disp)) parameters
static inline _glptr_GetProgramPipelineiv GET_GetProgramPipelineiv(struct _glapi_table *disp) {
   return (_glptr_GetProgramPipelineiv) (GET_by_offset(disp, _gloffset_GetProgramPipelineiv));
}

static inline void SET_GetProgramPipelineiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramPipelineiv, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsProgramPipeline)(GLuint);
#define CALL_IsProgramPipeline(disp, parameters) \
    (* GET_IsProgramPipeline(disp)) parameters
static inline _glptr_IsProgramPipeline GET_IsProgramPipeline(struct _glapi_table *disp) {
   return (_glptr_IsProgramPipeline) (GET_by_offset(disp, _gloffset_IsProgramPipeline));
}

static inline void SET_IsProgramPipeline(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsProgramPipeline, fn);
}

typedef void (GLAPIENTRYP _glptr_LockArraysEXT)(GLint, GLsizei);
#define CALL_LockArraysEXT(disp, parameters) \
    (* GET_LockArraysEXT(disp)) parameters
static inline _glptr_LockArraysEXT GET_LockArraysEXT(struct _glapi_table *disp) {
   return (_glptr_LockArraysEXT) (GET_by_offset(disp, _gloffset_LockArraysEXT));
}

static inline void SET_LockArraysEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLsizei)) {
   SET_by_offset(disp, _gloffset_LockArraysEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1d)(GLuint, GLint, GLdouble);
#define CALL_ProgramUniform1d(disp, parameters) \
    (* GET_ProgramUniform1d(disp)) parameters
static inline _glptr_ProgramUniform1d GET_ProgramUniform1d(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1d) (GET_by_offset(disp, _gloffset_ProgramUniform1d));
}

static inline void SET_ProgramUniform1d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1d, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define CALL_ProgramUniform1dv(disp, parameters) \
    (* GET_ProgramUniform1dv(disp)) parameters
static inline _glptr_ProgramUniform1dv GET_ProgramUniform1dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1dv) (GET_by_offset(disp, _gloffset_ProgramUniform1dv));
}

static inline void SET_ProgramUniform1dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1f)(GLuint, GLint, GLfloat);
#define CALL_ProgramUniform1f(disp, parameters) \
    (* GET_ProgramUniform1f(disp)) parameters
static inline _glptr_ProgramUniform1f GET_ProgramUniform1f(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1f) (GET_by_offset(disp, _gloffset_ProgramUniform1f));
}

static inline void SET_ProgramUniform1f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1f, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define CALL_ProgramUniform1fv(disp, parameters) \
    (* GET_ProgramUniform1fv(disp)) parameters
static inline _glptr_ProgramUniform1fv GET_ProgramUniform1fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1fv) (GET_by_offset(disp, _gloffset_ProgramUniform1fv));
}

static inline void SET_ProgramUniform1fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1i)(GLuint, GLint, GLint);
#define CALL_ProgramUniform1i(disp, parameters) \
    (* GET_ProgramUniform1i(disp)) parameters
static inline _glptr_ProgramUniform1i GET_ProgramUniform1i(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1i) (GET_by_offset(disp, _gloffset_ProgramUniform1i));
}

static inline void SET_ProgramUniform1i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1i, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1iv)(GLuint, GLint, GLsizei, const GLint *);
#define CALL_ProgramUniform1iv(disp, parameters) \
    (* GET_ProgramUniform1iv(disp)) parameters
static inline _glptr_ProgramUniform1iv GET_ProgramUniform1iv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1iv) (GET_by_offset(disp, _gloffset_ProgramUniform1iv));
}

static inline void SET_ProgramUniform1iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1iv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1ui)(GLuint, GLint, GLuint);
#define CALL_ProgramUniform1ui(disp, parameters) \
    (* GET_ProgramUniform1ui(disp)) parameters
static inline _glptr_ProgramUniform1ui GET_ProgramUniform1ui(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1ui) (GET_by_offset(disp, _gloffset_ProgramUniform1ui));
}

static inline void SET_ProgramUniform1ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1ui, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform1uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define CALL_ProgramUniform1uiv(disp, parameters) \
    (* GET_ProgramUniform1uiv(disp)) parameters
static inline _glptr_ProgramUniform1uiv GET_ProgramUniform1uiv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform1uiv) (GET_by_offset(disp, _gloffset_ProgramUniform1uiv));
}

static inline void SET_ProgramUniform1uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform1uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2d)(GLuint, GLint, GLdouble, GLdouble);
#define CALL_ProgramUniform2d(disp, parameters) \
    (* GET_ProgramUniform2d(disp)) parameters
static inline _glptr_ProgramUniform2d GET_ProgramUniform2d(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2d) (GET_by_offset(disp, _gloffset_ProgramUniform2d));
}

static inline void SET_ProgramUniform2d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2d, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define CALL_ProgramUniform2dv(disp, parameters) \
    (* GET_ProgramUniform2dv(disp)) parameters
static inline _glptr_ProgramUniform2dv GET_ProgramUniform2dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2dv) (GET_by_offset(disp, _gloffset_ProgramUniform2dv));
}

static inline void SET_ProgramUniform2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2f)(GLuint, GLint, GLfloat, GLfloat);
#define CALL_ProgramUniform2f(disp, parameters) \
    (* GET_ProgramUniform2f(disp)) parameters
static inline _glptr_ProgramUniform2f GET_ProgramUniform2f(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2f) (GET_by_offset(disp, _gloffset_ProgramUniform2f));
}

static inline void SET_ProgramUniform2f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2f, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define CALL_ProgramUniform2fv(disp, parameters) \
    (* GET_ProgramUniform2fv(disp)) parameters
static inline _glptr_ProgramUniform2fv GET_ProgramUniform2fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2fv) (GET_by_offset(disp, _gloffset_ProgramUniform2fv));
}

static inline void SET_ProgramUniform2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2i)(GLuint, GLint, GLint, GLint);
#define CALL_ProgramUniform2i(disp, parameters) \
    (* GET_ProgramUniform2i(disp)) parameters
static inline _glptr_ProgramUniform2i GET_ProgramUniform2i(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2i) (GET_by_offset(disp, _gloffset_ProgramUniform2i));
}

static inline void SET_ProgramUniform2i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2i, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2iv)(GLuint, GLint, GLsizei, const GLint *);
#define CALL_ProgramUniform2iv(disp, parameters) \
    (* GET_ProgramUniform2iv(disp)) parameters
static inline _glptr_ProgramUniform2iv GET_ProgramUniform2iv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2iv) (GET_by_offset(disp, _gloffset_ProgramUniform2iv));
}

static inline void SET_ProgramUniform2iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2iv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2ui)(GLuint, GLint, GLuint, GLuint);
#define CALL_ProgramUniform2ui(disp, parameters) \
    (* GET_ProgramUniform2ui(disp)) parameters
static inline _glptr_ProgramUniform2ui GET_ProgramUniform2ui(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2ui) (GET_by_offset(disp, _gloffset_ProgramUniform2ui));
}

static inline void SET_ProgramUniform2ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2ui, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform2uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define CALL_ProgramUniform2uiv(disp, parameters) \
    (* GET_ProgramUniform2uiv(disp)) parameters
static inline _glptr_ProgramUniform2uiv GET_ProgramUniform2uiv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform2uiv) (GET_by_offset(disp, _gloffset_ProgramUniform2uiv));
}

static inline void SET_ProgramUniform2uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform2uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3d)(GLuint, GLint, GLdouble, GLdouble, GLdouble);
#define CALL_ProgramUniform3d(disp, parameters) \
    (* GET_ProgramUniform3d(disp)) parameters
static inline _glptr_ProgramUniform3d GET_ProgramUniform3d(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3d) (GET_by_offset(disp, _gloffset_ProgramUniform3d));
}

static inline void SET_ProgramUniform3d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3d, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define CALL_ProgramUniform3dv(disp, parameters) \
    (* GET_ProgramUniform3dv(disp)) parameters
static inline _glptr_ProgramUniform3dv GET_ProgramUniform3dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3dv) (GET_by_offset(disp, _gloffset_ProgramUniform3dv));
}

static inline void SET_ProgramUniform3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3f)(GLuint, GLint, GLfloat, GLfloat, GLfloat);
#define CALL_ProgramUniform3f(disp, parameters) \
    (* GET_ProgramUniform3f(disp)) parameters
static inline _glptr_ProgramUniform3f GET_ProgramUniform3f(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3f) (GET_by_offset(disp, _gloffset_ProgramUniform3f));
}

static inline void SET_ProgramUniform3f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3f, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define CALL_ProgramUniform3fv(disp, parameters) \
    (* GET_ProgramUniform3fv(disp)) parameters
static inline _glptr_ProgramUniform3fv GET_ProgramUniform3fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3fv) (GET_by_offset(disp, _gloffset_ProgramUniform3fv));
}

static inline void SET_ProgramUniform3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3i)(GLuint, GLint, GLint, GLint, GLint);
#define CALL_ProgramUniform3i(disp, parameters) \
    (* GET_ProgramUniform3i(disp)) parameters
static inline _glptr_ProgramUniform3i GET_ProgramUniform3i(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3i) (GET_by_offset(disp, _gloffset_ProgramUniform3i));
}

static inline void SET_ProgramUniform3i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3i, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3iv)(GLuint, GLint, GLsizei, const GLint *);
#define CALL_ProgramUniform3iv(disp, parameters) \
    (* GET_ProgramUniform3iv(disp)) parameters
static inline _glptr_ProgramUniform3iv GET_ProgramUniform3iv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3iv) (GET_by_offset(disp, _gloffset_ProgramUniform3iv));
}

static inline void SET_ProgramUniform3iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3iv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3ui)(GLuint, GLint, GLuint, GLuint, GLuint);
#define CALL_ProgramUniform3ui(disp, parameters) \
    (* GET_ProgramUniform3ui(disp)) parameters
static inline _glptr_ProgramUniform3ui GET_ProgramUniform3ui(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3ui) (GET_by_offset(disp, _gloffset_ProgramUniform3ui));
}

static inline void SET_ProgramUniform3ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3ui, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform3uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define CALL_ProgramUniform3uiv(disp, parameters) \
    (* GET_ProgramUniform3uiv(disp)) parameters
static inline _glptr_ProgramUniform3uiv GET_ProgramUniform3uiv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform3uiv) (GET_by_offset(disp, _gloffset_ProgramUniform3uiv));
}

static inline void SET_ProgramUniform3uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform3uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4d)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_ProgramUniform4d(disp, parameters) \
    (* GET_ProgramUniform4d(disp)) parameters
static inline _glptr_ProgramUniform4d GET_ProgramUniform4d(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4d) (GET_by_offset(disp, _gloffset_ProgramUniform4d));
}

static inline void SET_ProgramUniform4d(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4d, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define CALL_ProgramUniform4dv(disp, parameters) \
    (* GET_ProgramUniform4dv(disp)) parameters
static inline _glptr_ProgramUniform4dv GET_ProgramUniform4dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4dv) (GET_by_offset(disp, _gloffset_ProgramUniform4dv));
}

static inline void SET_ProgramUniform4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4f)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_ProgramUniform4f(disp, parameters) \
    (* GET_ProgramUniform4f(disp)) parameters
static inline _glptr_ProgramUniform4f GET_ProgramUniform4f(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4f) (GET_by_offset(disp, _gloffset_ProgramUniform4f));
}

static inline void SET_ProgramUniform4f(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4f, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define CALL_ProgramUniform4fv(disp, parameters) \
    (* GET_ProgramUniform4fv(disp)) parameters
static inline _glptr_ProgramUniform4fv GET_ProgramUniform4fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4fv) (GET_by_offset(disp, _gloffset_ProgramUniform4fv));
}

static inline void SET_ProgramUniform4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4i)(GLuint, GLint, GLint, GLint, GLint, GLint);
#define CALL_ProgramUniform4i(disp, parameters) \
    (* GET_ProgramUniform4i(disp)) parameters
static inline _glptr_ProgramUniform4i GET_ProgramUniform4i(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4i) (GET_by_offset(disp, _gloffset_ProgramUniform4i));
}

static inline void SET_ProgramUniform4i(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4i, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4iv)(GLuint, GLint, GLsizei, const GLint *);
#define CALL_ProgramUniform4iv(disp, parameters) \
    (* GET_ProgramUniform4iv(disp)) parameters
static inline _glptr_ProgramUniform4iv GET_ProgramUniform4iv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4iv) (GET_by_offset(disp, _gloffset_ProgramUniform4iv));
}

static inline void SET_ProgramUniform4iv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4iv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4ui)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
#define CALL_ProgramUniform4ui(disp, parameters) \
    (* GET_ProgramUniform4ui(disp)) parameters
static inline _glptr_ProgramUniform4ui GET_ProgramUniform4ui(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4ui) (GET_by_offset(disp, _gloffset_ProgramUniform4ui));
}

static inline void SET_ProgramUniform4ui(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4ui, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniform4uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define CALL_ProgramUniform4uiv(disp, parameters) \
    (* GET_ProgramUniform4uiv(disp)) parameters
static inline _glptr_ProgramUniform4uiv GET_ProgramUniform4uiv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniform4uiv) (GET_by_offset(disp, _gloffset_ProgramUniform4uiv));
}

static inline void SET_ProgramUniform4uiv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_ProgramUniform4uiv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix2dv(disp, parameters) \
    (* GET_ProgramUniformMatrix2dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix2dv GET_ProgramUniformMatrix2dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix2dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix2dv));
}

static inline void SET_ProgramUniformMatrix2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix2fv(disp, parameters) \
    (* GET_ProgramUniformMatrix2fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix2fv GET_ProgramUniformMatrix2fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix2fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix2fv));
}

static inline void SET_ProgramUniformMatrix2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix2x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix2x3dv(disp, parameters) \
    (* GET_ProgramUniformMatrix2x3dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix2x3dv GET_ProgramUniformMatrix2x3dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix2x3dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix2x3dv));
}

static inline void SET_ProgramUniformMatrix2x3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix2x3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix2x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix2x3fv(disp, parameters) \
    (* GET_ProgramUniformMatrix2x3fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix2x3fv GET_ProgramUniformMatrix2x3fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix2x3fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix2x3fv));
}

static inline void SET_ProgramUniformMatrix2x3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix2x3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix2x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix2x4dv(disp, parameters) \
    (* GET_ProgramUniformMatrix2x4dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix2x4dv GET_ProgramUniformMatrix2x4dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix2x4dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix2x4dv));
}

static inline void SET_ProgramUniformMatrix2x4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix2x4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix2x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix2x4fv(disp, parameters) \
    (* GET_ProgramUniformMatrix2x4fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix2x4fv GET_ProgramUniformMatrix2x4fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix2x4fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix2x4fv));
}

static inline void SET_ProgramUniformMatrix2x4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix2x4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix3dv(disp, parameters) \
    (* GET_ProgramUniformMatrix3dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix3dv GET_ProgramUniformMatrix3dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix3dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix3dv));
}

static inline void SET_ProgramUniformMatrix3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix3fv(disp, parameters) \
    (* GET_ProgramUniformMatrix3fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix3fv GET_ProgramUniformMatrix3fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix3fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix3fv));
}

static inline void SET_ProgramUniformMatrix3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix3x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix3x2dv(disp, parameters) \
    (* GET_ProgramUniformMatrix3x2dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix3x2dv GET_ProgramUniformMatrix3x2dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix3x2dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix3x2dv));
}

static inline void SET_ProgramUniformMatrix3x2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix3x2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix3x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix3x2fv(disp, parameters) \
    (* GET_ProgramUniformMatrix3x2fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix3x2fv GET_ProgramUniformMatrix3x2fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix3x2fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix3x2fv));
}

static inline void SET_ProgramUniformMatrix3x2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix3x2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix3x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix3x4dv(disp, parameters) \
    (* GET_ProgramUniformMatrix3x4dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix3x4dv GET_ProgramUniformMatrix3x4dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix3x4dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix3x4dv));
}

static inline void SET_ProgramUniformMatrix3x4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix3x4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix3x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix3x4fv(disp, parameters) \
    (* GET_ProgramUniformMatrix3x4fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix3x4fv GET_ProgramUniformMatrix3x4fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix3x4fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix3x4fv));
}

static inline void SET_ProgramUniformMatrix3x4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix3x4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix4dv(disp, parameters) \
    (* GET_ProgramUniformMatrix4dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix4dv GET_ProgramUniformMatrix4dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix4dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix4dv));
}

static inline void SET_ProgramUniformMatrix4dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix4dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix4fv(disp, parameters) \
    (* GET_ProgramUniformMatrix4fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix4fv GET_ProgramUniformMatrix4fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix4fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix4fv));
}

static inline void SET_ProgramUniformMatrix4fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix4fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix4x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix4x2dv(disp, parameters) \
    (* GET_ProgramUniformMatrix4x2dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix4x2dv GET_ProgramUniformMatrix4x2dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix4x2dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix4x2dv));
}

static inline void SET_ProgramUniformMatrix4x2dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix4x2dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix4x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix4x2fv(disp, parameters) \
    (* GET_ProgramUniformMatrix4x2fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix4x2fv GET_ProgramUniformMatrix4x2fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix4x2fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix4x2fv));
}

static inline void SET_ProgramUniformMatrix4x2fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix4x2fv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix4x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define CALL_ProgramUniformMatrix4x3dv(disp, parameters) \
    (* GET_ProgramUniformMatrix4x3dv(disp)) parameters
static inline _glptr_ProgramUniformMatrix4x3dv GET_ProgramUniformMatrix4x3dv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix4x3dv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix4x3dv));
}

static inline void SET_ProgramUniformMatrix4x3dv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix4x3dv, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramUniformMatrix4x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define CALL_ProgramUniformMatrix4x3fv(disp, parameters) \
    (* GET_ProgramUniformMatrix4x3fv(disp)) parameters
static inline _glptr_ProgramUniformMatrix4x3fv GET_ProgramUniformMatrix4x3fv(struct _glapi_table *disp) {
   return (_glptr_ProgramUniformMatrix4x3fv) (GET_by_offset(disp, _gloffset_ProgramUniformMatrix4x3fv));
}

static inline void SET_ProgramUniformMatrix4x3fv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramUniformMatrix4x3fv, fn);
}

typedef void (GLAPIENTRYP _glptr_UnlockArraysEXT)(void);
#define CALL_UnlockArraysEXT(disp, parameters) \
    (* GET_UnlockArraysEXT(disp)) parameters
static inline _glptr_UnlockArraysEXT GET_UnlockArraysEXT(struct _glapi_table *disp) {
   return (_glptr_UnlockArraysEXT) (GET_by_offset(disp, _gloffset_UnlockArraysEXT));
}

static inline void SET_UnlockArraysEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_UnlockArraysEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_UseProgramStages)(GLuint, GLbitfield, GLuint);
#define CALL_UseProgramStages(disp, parameters) \
    (* GET_UseProgramStages(disp)) parameters
static inline _glptr_UseProgramStages GET_UseProgramStages(struct _glapi_table *disp) {
   return (_glptr_UseProgramStages) (GET_by_offset(disp, _gloffset_UseProgramStages));
}

static inline void SET_UseProgramStages(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLbitfield, GLuint)) {
   SET_by_offset(disp, _gloffset_UseProgramStages, fn);
}

typedef void (GLAPIENTRYP _glptr_ValidateProgramPipeline)(GLuint);
#define CALL_ValidateProgramPipeline(disp, parameters) \
    (* GET_ValidateProgramPipeline(disp)) parameters
static inline _glptr_ValidateProgramPipeline GET_ValidateProgramPipeline(struct _glapi_table *disp) {
   return (_glptr_ValidateProgramPipeline) (GET_by_offset(disp, _gloffset_ValidateProgramPipeline));
}

static inline void SET_ValidateProgramPipeline(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_ValidateProgramPipeline, fn);
}

typedef void (GLAPIENTRYP _glptr_DebugMessageCallback)(GLDEBUGPROC, const GLvoid *);
#define CALL_DebugMessageCallback(disp, parameters) \
    (* GET_DebugMessageCallback(disp)) parameters
static inline _glptr_DebugMessageCallback GET_DebugMessageCallback(struct _glapi_table *disp) {
   return (_glptr_DebugMessageCallback) (GET_by_offset(disp, _gloffset_DebugMessageCallback));
}

static inline void SET_DebugMessageCallback(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLDEBUGPROC, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_DebugMessageCallback, fn);
}

typedef void (GLAPIENTRYP _glptr_DebugMessageControl)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean);
#define CALL_DebugMessageControl(disp, parameters) \
    (* GET_DebugMessageControl(disp)) parameters
static inline _glptr_DebugMessageControl GET_DebugMessageControl(struct _glapi_table *disp) {
   return (_glptr_DebugMessageControl) (GET_by_offset(disp, _gloffset_DebugMessageControl));
}

static inline void SET_DebugMessageControl(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean)) {
   SET_by_offset(disp, _gloffset_DebugMessageControl, fn);
}

typedef void (GLAPIENTRYP _glptr_DebugMessageInsert)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *);
#define CALL_DebugMessageInsert(disp, parameters) \
    (* GET_DebugMessageInsert(disp)) parameters
static inline _glptr_DebugMessageInsert GET_DebugMessageInsert(struct _glapi_table *disp) {
   return (_glptr_DebugMessageInsert) (GET_by_offset(disp, _gloffset_DebugMessageInsert));
}

static inline void SET_DebugMessageInsert(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *)) {
   SET_by_offset(disp, _gloffset_DebugMessageInsert, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_GetDebugMessageLog)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);
#define CALL_GetDebugMessageLog(disp, parameters) \
    (* GET_GetDebugMessageLog(disp)) parameters
static inline _glptr_GetDebugMessageLog GET_GetDebugMessageLog(struct _glapi_table *disp) {
   return (_glptr_GetDebugMessageLog) (GET_by_offset(disp, _gloffset_GetDebugMessageLog));
}

static inline void SET_GetDebugMessageLog(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetDebugMessageLog, fn);
}

typedef void (GLAPIENTRYP _glptr_GetObjectLabel)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetObjectLabel(disp, parameters) \
    (* GET_GetObjectLabel(disp)) parameters
static inline _glptr_GetObjectLabel GET_GetObjectLabel(struct _glapi_table *disp) {
   return (_glptr_GetObjectLabel) (GET_by_offset(disp, _gloffset_GetObjectLabel));
}

static inline void SET_GetObjectLabel(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetObjectLabel, fn);
}

typedef void (GLAPIENTRYP _glptr_GetObjectPtrLabel)(const GLvoid *, GLsizei, GLsizei *, GLchar *);
#define CALL_GetObjectPtrLabel(disp, parameters) \
    (* GET_GetObjectPtrLabel(disp)) parameters
static inline _glptr_GetObjectPtrLabel GET_GetObjectPtrLabel(struct _glapi_table *disp) {
   return (_glptr_GetObjectPtrLabel) (GET_by_offset(disp, _gloffset_GetObjectPtrLabel));
}

static inline void SET_GetObjectPtrLabel(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLvoid *, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetObjectPtrLabel, fn);
}

typedef void (GLAPIENTRYP _glptr_ObjectLabel)(GLenum, GLuint, GLsizei, const GLchar *);
#define CALL_ObjectLabel(disp, parameters) \
    (* GET_ObjectLabel(disp)) parameters
static inline _glptr_ObjectLabel GET_ObjectLabel(struct _glapi_table *disp) {
   return (_glptr_ObjectLabel) (GET_by_offset(disp, _gloffset_ObjectLabel));
}

static inline void SET_ObjectLabel(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLchar *)) {
   SET_by_offset(disp, _gloffset_ObjectLabel, fn);
}

typedef void (GLAPIENTRYP _glptr_ObjectPtrLabel)(const GLvoid *, GLsizei, const GLchar *);
#define CALL_ObjectPtrLabel(disp, parameters) \
    (* GET_ObjectPtrLabel(disp)) parameters
static inline _glptr_ObjectPtrLabel GET_ObjectPtrLabel(struct _glapi_table *disp) {
   return (_glptr_ObjectPtrLabel) (GET_by_offset(disp, _gloffset_ObjectPtrLabel));
}

static inline void SET_ObjectPtrLabel(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLvoid *, GLsizei, const GLchar *)) {
   SET_by_offset(disp, _gloffset_ObjectPtrLabel, fn);
}

typedef void (GLAPIENTRYP _glptr_PopDebugGroup)(void);
#define CALL_PopDebugGroup(disp, parameters) \
    (* GET_PopDebugGroup(disp)) parameters
static inline _glptr_PopDebugGroup GET_PopDebugGroup(struct _glapi_table *disp) {
   return (_glptr_PopDebugGroup) (GET_by_offset(disp, _gloffset_PopDebugGroup));
}

static inline void SET_PopDebugGroup(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PopDebugGroup, fn);
}

typedef void (GLAPIENTRYP _glptr_PushDebugGroup)(GLenum, GLuint, GLsizei, const GLchar *);
#define CALL_PushDebugGroup(disp, parameters) \
    (* GET_PushDebugGroup(disp)) parameters
static inline _glptr_PushDebugGroup GET_PushDebugGroup(struct _glapi_table *disp) {
   return (_glptr_PushDebugGroup) (GET_by_offset(disp, _gloffset_PushDebugGroup));
}

static inline void SET_PushDebugGroup(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLchar *)) {
   SET_by_offset(disp, _gloffset_PushDebugGroup, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3fEXT)(GLfloat, GLfloat, GLfloat);
#define CALL_SecondaryColor3fEXT(disp, parameters) \
    (* GET_SecondaryColor3fEXT(disp)) parameters
static inline _glptr_SecondaryColor3fEXT GET_SecondaryColor3fEXT(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3fEXT) (GET_by_offset(disp, _gloffset_SecondaryColor3fEXT));
}

static inline void SET_SecondaryColor3fEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3fEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_SecondaryColor3fvEXT)(const GLfloat *);
#define CALL_SecondaryColor3fvEXT(disp, parameters) \
    (* GET_SecondaryColor3fvEXT(disp)) parameters
static inline _glptr_SecondaryColor3fvEXT GET_SecondaryColor3fvEXT(struct _glapi_table *disp) {
   return (_glptr_SecondaryColor3fvEXT) (GET_by_offset(disp, _gloffset_SecondaryColor3fvEXT));
}

static inline void SET_SecondaryColor3fvEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_SecondaryColor3fvEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiDrawElementsEXT)(GLenum, const GLsizei *, GLenum, const GLvoid * const *, GLsizei);
#define CALL_MultiDrawElementsEXT(disp, parameters) \
    (* GET_MultiDrawElementsEXT(disp)) parameters
static inline _glptr_MultiDrawElementsEXT GET_MultiDrawElementsEXT(struct _glapi_table *disp) {
   return (_glptr_MultiDrawElementsEXT) (GET_by_offset(disp, _gloffset_MultiDrawElementsEXT));
}

static inline void SET_MultiDrawElementsEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLsizei *, GLenum, const GLvoid * const *, GLsizei)) {
   SET_by_offset(disp, _gloffset_MultiDrawElementsEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_FogCoordfEXT)(GLfloat);
#define CALL_FogCoordfEXT(disp, parameters) \
    (* GET_FogCoordfEXT(disp)) parameters
static inline _glptr_FogCoordfEXT GET_FogCoordfEXT(struct _glapi_table *disp) {
   return (_glptr_FogCoordfEXT) (GET_by_offset(disp, _gloffset_FogCoordfEXT));
}

static inline void SET_FogCoordfEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat)) {
   SET_by_offset(disp, _gloffset_FogCoordfEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_FogCoordfvEXT)(const GLfloat *);
#define CALL_FogCoordfvEXT(disp, parameters) \
    (* GET_FogCoordfvEXT(disp)) parameters
static inline _glptr_FogCoordfvEXT GET_FogCoordfvEXT(struct _glapi_table *disp) {
   return (_glptr_FogCoordfvEXT) (GET_by_offset(disp, _gloffset_FogCoordfvEXT));
}

static inline void SET_FogCoordfvEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_FogCoordfvEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ResizeBuffersMESA)(void);
#define CALL_ResizeBuffersMESA(disp, parameters) \
    (* GET_ResizeBuffersMESA(disp)) parameters
static inline _glptr_ResizeBuffersMESA GET_ResizeBuffersMESA(struct _glapi_table *disp) {
   return (_glptr_ResizeBuffersMESA) (GET_by_offset(disp, _gloffset_ResizeBuffersMESA));
}

static inline void SET_ResizeBuffersMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_ResizeBuffersMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4dMESA)(GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_WindowPos4dMESA(disp, parameters) \
    (* GET_WindowPos4dMESA(disp)) parameters
static inline _glptr_WindowPos4dMESA GET_WindowPos4dMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4dMESA) (GET_by_offset(disp, _gloffset_WindowPos4dMESA));
}

static inline void SET_WindowPos4dMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_WindowPos4dMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4dvMESA)(const GLdouble *);
#define CALL_WindowPos4dvMESA(disp, parameters) \
    (* GET_WindowPos4dvMESA(disp)) parameters
static inline _glptr_WindowPos4dvMESA GET_WindowPos4dvMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4dvMESA) (GET_by_offset(disp, _gloffset_WindowPos4dvMESA));
}

static inline void SET_WindowPos4dvMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLdouble *)) {
   SET_by_offset(disp, _gloffset_WindowPos4dvMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4fMESA)(GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_WindowPos4fMESA(disp, parameters) \
    (* GET_WindowPos4fMESA(disp)) parameters
static inline _glptr_WindowPos4fMESA GET_WindowPos4fMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4fMESA) (GET_by_offset(disp, _gloffset_WindowPos4fMESA));
}

static inline void SET_WindowPos4fMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_WindowPos4fMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4fvMESA)(const GLfloat *);
#define CALL_WindowPos4fvMESA(disp, parameters) \
    (* GET_WindowPos4fvMESA(disp)) parameters
static inline _glptr_WindowPos4fvMESA GET_WindowPos4fvMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4fvMESA) (GET_by_offset(disp, _gloffset_WindowPos4fvMESA));
}

static inline void SET_WindowPos4fvMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfloat *)) {
   SET_by_offset(disp, _gloffset_WindowPos4fvMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4iMESA)(GLint, GLint, GLint, GLint);
#define CALL_WindowPos4iMESA(disp, parameters) \
    (* GET_WindowPos4iMESA(disp)) parameters
static inline _glptr_WindowPos4iMESA GET_WindowPos4iMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4iMESA) (GET_by_offset(disp, _gloffset_WindowPos4iMESA));
}

static inline void SET_WindowPos4iMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_WindowPos4iMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4ivMESA)(const GLint *);
#define CALL_WindowPos4ivMESA(disp, parameters) \
    (* GET_WindowPos4ivMESA(disp)) parameters
static inline _glptr_WindowPos4ivMESA GET_WindowPos4ivMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4ivMESA) (GET_by_offset(disp, _gloffset_WindowPos4ivMESA));
}

static inline void SET_WindowPos4ivMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLint *)) {
   SET_by_offset(disp, _gloffset_WindowPos4ivMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4sMESA)(GLshort, GLshort, GLshort, GLshort);
#define CALL_WindowPos4sMESA(disp, parameters) \
    (* GET_WindowPos4sMESA(disp)) parameters
static inline _glptr_WindowPos4sMESA GET_WindowPos4sMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4sMESA) (GET_by_offset(disp, _gloffset_WindowPos4sMESA));
}

static inline void SET_WindowPos4sMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_WindowPos4sMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowPos4svMESA)(const GLshort *);
#define CALL_WindowPos4svMESA(disp, parameters) \
    (* GET_WindowPos4svMESA(disp)) parameters
static inline _glptr_WindowPos4svMESA GET_WindowPos4svMESA(struct _glapi_table *disp) {
   return (_glptr_WindowPos4svMESA) (GET_by_offset(disp, _gloffset_WindowPos4svMESA));
}

static inline void SET_WindowPos4svMESA(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLshort *)) {
   SET_by_offset(disp, _gloffset_WindowPos4svMESA, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiModeDrawArraysIBM)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint);
#define CALL_MultiModeDrawArraysIBM(disp, parameters) \
    (* GET_MultiModeDrawArraysIBM(disp)) parameters
static inline _glptr_MultiModeDrawArraysIBM GET_MultiModeDrawArraysIBM(struct _glapi_table *disp) {
   return (_glptr_MultiModeDrawArraysIBM) (GET_by_offset(disp, _gloffset_MultiModeDrawArraysIBM));
}

static inline void SET_MultiModeDrawArraysIBM(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint)) {
   SET_by_offset(disp, _gloffset_MultiModeDrawArraysIBM, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiModeDrawElementsIBM)(const GLenum *, const GLsizei *, GLenum, const GLvoid * const *, GLsizei, GLint);
#define CALL_MultiModeDrawElementsIBM(disp, parameters) \
    (* GET_MultiModeDrawElementsIBM(disp)) parameters
static inline _glptr_MultiModeDrawElementsIBM GET_MultiModeDrawElementsIBM(struct _glapi_table *disp) {
   return (_glptr_MultiModeDrawElementsIBM) (GET_by_offset(disp, _gloffset_MultiModeDrawElementsIBM));
}

static inline void SET_MultiModeDrawElementsIBM(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLenum *, const GLsizei *, GLenum, const GLvoid * const *, GLsizei, GLint)) {
   SET_by_offset(disp, _gloffset_MultiModeDrawElementsIBM, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_AreProgramsResidentNV)(GLsizei, const GLuint *, GLboolean *);
#define CALL_AreProgramsResidentNV(disp, parameters) \
    (* GET_AreProgramsResidentNV(disp)) parameters
static inline _glptr_AreProgramsResidentNV GET_AreProgramsResidentNV(struct _glapi_table *disp) {
   return (_glptr_AreProgramsResidentNV) (GET_by_offset(disp, _gloffset_AreProgramsResidentNV));
}

static inline void SET_AreProgramsResidentNV(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLsizei, const GLuint *, GLboolean *)) {
   SET_by_offset(disp, _gloffset_AreProgramsResidentNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ExecuteProgramNV)(GLenum, GLuint, const GLfloat *);
#define CALL_ExecuteProgramNV(disp, parameters) \
    (* GET_ExecuteProgramNV(disp)) parameters
static inline _glptr_ExecuteProgramNV GET_ExecuteProgramNV(struct _glapi_table *disp) {
   return (_glptr_ExecuteProgramNV) (GET_by_offset(disp, _gloffset_ExecuteProgramNV));
}

static inline void SET_ExecuteProgramNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ExecuteProgramNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramParameterdvNV)(GLenum, GLuint, GLenum, GLdouble *);
#define CALL_GetProgramParameterdvNV(disp, parameters) \
    (* GET_GetProgramParameterdvNV(disp)) parameters
static inline _glptr_GetProgramParameterdvNV GET_GetProgramParameterdvNV(struct _glapi_table *disp) {
   return (_glptr_GetProgramParameterdvNV) (GET_by_offset(disp, _gloffset_GetProgramParameterdvNV));
}

static inline void SET_GetProgramParameterdvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetProgramParameterdvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramParameterfvNV)(GLenum, GLuint, GLenum, GLfloat *);
#define CALL_GetProgramParameterfvNV(disp, parameters) \
    (* GET_GetProgramParameterfvNV(disp)) parameters
static inline _glptr_GetProgramParameterfvNV GET_GetProgramParameterfvNV(struct _glapi_table *disp) {
   return (_glptr_GetProgramParameterfvNV) (GET_by_offset(disp, _gloffset_GetProgramParameterfvNV));
}

static inline void SET_GetProgramParameterfvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetProgramParameterfvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramStringNV)(GLuint, GLenum, GLubyte *);
#define CALL_GetProgramStringNV(disp, parameters) \
    (* GET_GetProgramStringNV(disp)) parameters
static inline _glptr_GetProgramStringNV GET_GetProgramStringNV(struct _glapi_table *disp) {
   return (_glptr_GetProgramStringNV) (GET_by_offset(disp, _gloffset_GetProgramStringNV));
}

static inline void SET_GetProgramStringNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLubyte *)) {
   SET_by_offset(disp, _gloffset_GetProgramStringNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramivNV)(GLuint, GLenum, GLint *);
#define CALL_GetProgramivNV(disp, parameters) \
    (* GET_GetProgramivNV(disp)) parameters
static inline _glptr_GetProgramivNV GET_GetProgramivNV(struct _glapi_table *disp) {
   return (_glptr_GetProgramivNV) (GET_by_offset(disp, _gloffset_GetProgramivNV));
}

static inline void SET_GetProgramivNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetProgramivNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTrackMatrixivNV)(GLenum, GLuint, GLenum, GLint *);
#define CALL_GetTrackMatrixivNV(disp, parameters) \
    (* GET_GetTrackMatrixivNV(disp)) parameters
static inline _glptr_GetTrackMatrixivNV GET_GetTrackMatrixivNV(struct _glapi_table *disp) {
   return (_glptr_GetTrackMatrixivNV) (GET_by_offset(disp, _gloffset_GetTrackMatrixivNV));
}

static inline void SET_GetTrackMatrixivNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTrackMatrixivNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribdvNV)(GLuint, GLenum, GLdouble *);
#define CALL_GetVertexAttribdvNV(disp, parameters) \
    (* GET_GetVertexAttribdvNV(disp)) parameters
static inline _glptr_GetVertexAttribdvNV GET_GetVertexAttribdvNV(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribdvNV) (GET_by_offset(disp, _gloffset_GetVertexAttribdvNV));
}

static inline void SET_GetVertexAttribdvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribdvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribfvNV)(GLuint, GLenum, GLfloat *);
#define CALL_GetVertexAttribfvNV(disp, parameters) \
    (* GET_GetVertexAttribfvNV(disp)) parameters
static inline _glptr_GetVertexAttribfvNV GET_GetVertexAttribfvNV(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribfvNV) (GET_by_offset(disp, _gloffset_GetVertexAttribfvNV));
}

static inline void SET_GetVertexAttribfvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribfvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetVertexAttribivNV)(GLuint, GLenum, GLint *);
#define CALL_GetVertexAttribivNV(disp, parameters) \
    (* GET_GetVertexAttribivNV(disp)) parameters
static inline _glptr_GetVertexAttribivNV GET_GetVertexAttribivNV(struct _glapi_table *disp) {
   return (_glptr_GetVertexAttribivNV) (GET_by_offset(disp, _gloffset_GetVertexAttribivNV));
}

static inline void SET_GetVertexAttribivNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetVertexAttribivNV, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadProgramNV)(GLenum, GLuint, GLsizei, const GLubyte *);
#define CALL_LoadProgramNV(disp, parameters) \
    (* GET_LoadProgramNV(disp)) parameters
static inline _glptr_LoadProgramNV GET_LoadProgramNV(struct _glapi_table *disp) {
   return (_glptr_LoadProgramNV) (GET_by_offset(disp, _gloffset_LoadProgramNV));
}

static inline void SET_LoadProgramNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_LoadProgramNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramParameters4dvNV)(GLenum, GLuint, GLsizei, const GLdouble *);
#define CALL_ProgramParameters4dvNV(disp, parameters) \
    (* GET_ProgramParameters4dvNV(disp)) parameters
static inline _glptr_ProgramParameters4dvNV GET_ProgramParameters4dvNV(struct _glapi_table *disp) {
   return (_glptr_ProgramParameters4dvNV) (GET_by_offset(disp, _gloffset_ProgramParameters4dvNV));
}

static inline void SET_ProgramParameters4dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramParameters4dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramParameters4fvNV)(GLenum, GLuint, GLsizei, const GLfloat *);
#define CALL_ProgramParameters4fvNV(disp, parameters) \
    (* GET_ProgramParameters4fvNV(disp)) parameters
static inline _glptr_ProgramParameters4fvNV GET_ProgramParameters4fvNV(struct _glapi_table *disp) {
   return (_glptr_ProgramParameters4fvNV) (GET_by_offset(disp, _gloffset_ProgramParameters4fvNV));
}

static inline void SET_ProgramParameters4fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramParameters4fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_RequestResidentProgramsNV)(GLsizei, const GLuint *);
#define CALL_RequestResidentProgramsNV(disp, parameters) \
    (* GET_RequestResidentProgramsNV(disp)) parameters
static inline _glptr_RequestResidentProgramsNV GET_RequestResidentProgramsNV(struct _glapi_table *disp) {
   return (_glptr_RequestResidentProgramsNV) (GET_by_offset(disp, _gloffset_RequestResidentProgramsNV));
}

static inline void SET_RequestResidentProgramsNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_RequestResidentProgramsNV, fn);
}

typedef void (GLAPIENTRYP _glptr_TrackMatrixNV)(GLenum, GLuint, GLenum, GLenum);
#define CALL_TrackMatrixNV(disp, parameters) \
    (* GET_TrackMatrixNV(disp)) parameters
static inline _glptr_TrackMatrixNV GET_TrackMatrixNV(struct _glapi_table *disp) {
   return (_glptr_TrackMatrixNV) (GET_by_offset(disp, _gloffset_TrackMatrixNV));
}

static inline void SET_TrackMatrixNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLenum, GLenum)) {
   SET_by_offset(disp, _gloffset_TrackMatrixNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1dNV)(GLuint, GLdouble);
#define CALL_VertexAttrib1dNV(disp, parameters) \
    (* GET_VertexAttrib1dNV(disp)) parameters
static inline _glptr_VertexAttrib1dNV GET_VertexAttrib1dNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1dNV) (GET_by_offset(disp, _gloffset_VertexAttrib1dNV));
}

static inline void SET_VertexAttrib1dNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1dNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1dvNV)(GLuint, const GLdouble *);
#define CALL_VertexAttrib1dvNV(disp, parameters) \
    (* GET_VertexAttrib1dvNV(disp)) parameters
static inline _glptr_VertexAttrib1dvNV GET_VertexAttrib1dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1dvNV) (GET_by_offset(disp, _gloffset_VertexAttrib1dvNV));
}

static inline void SET_VertexAttrib1dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1fNV)(GLuint, GLfloat);
#define CALL_VertexAttrib1fNV(disp, parameters) \
    (* GET_VertexAttrib1fNV(disp)) parameters
static inline _glptr_VertexAttrib1fNV GET_VertexAttrib1fNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1fNV) (GET_by_offset(disp, _gloffset_VertexAttrib1fNV));
}

static inline void SET_VertexAttrib1fNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1fNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1fvNV)(GLuint, const GLfloat *);
#define CALL_VertexAttrib1fvNV(disp, parameters) \
    (* GET_VertexAttrib1fvNV(disp)) parameters
static inline _glptr_VertexAttrib1fvNV GET_VertexAttrib1fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1fvNV) (GET_by_offset(disp, _gloffset_VertexAttrib1fvNV));
}

static inline void SET_VertexAttrib1fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1sNV)(GLuint, GLshort);
#define CALL_VertexAttrib1sNV(disp, parameters) \
    (* GET_VertexAttrib1sNV(disp)) parameters
static inline _glptr_VertexAttrib1sNV GET_VertexAttrib1sNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1sNV) (GET_by_offset(disp, _gloffset_VertexAttrib1sNV));
}

static inline void SET_VertexAttrib1sNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1sNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib1svNV)(GLuint, const GLshort *);
#define CALL_VertexAttrib1svNV(disp, parameters) \
    (* GET_VertexAttrib1svNV(disp)) parameters
static inline _glptr_VertexAttrib1svNV GET_VertexAttrib1svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib1svNV) (GET_by_offset(disp, _gloffset_VertexAttrib1svNV));
}

static inline void SET_VertexAttrib1svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib1svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2dNV)(GLuint, GLdouble, GLdouble);
#define CALL_VertexAttrib2dNV(disp, parameters) \
    (* GET_VertexAttrib2dNV(disp)) parameters
static inline _glptr_VertexAttrib2dNV GET_VertexAttrib2dNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2dNV) (GET_by_offset(disp, _gloffset_VertexAttrib2dNV));
}

static inline void SET_VertexAttrib2dNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2dNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2dvNV)(GLuint, const GLdouble *);
#define CALL_VertexAttrib2dvNV(disp, parameters) \
    (* GET_VertexAttrib2dvNV(disp)) parameters
static inline _glptr_VertexAttrib2dvNV GET_VertexAttrib2dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2dvNV) (GET_by_offset(disp, _gloffset_VertexAttrib2dvNV));
}

static inline void SET_VertexAttrib2dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2fNV)(GLuint, GLfloat, GLfloat);
#define CALL_VertexAttrib2fNV(disp, parameters) \
    (* GET_VertexAttrib2fNV(disp)) parameters
static inline _glptr_VertexAttrib2fNV GET_VertexAttrib2fNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2fNV) (GET_by_offset(disp, _gloffset_VertexAttrib2fNV));
}

static inline void SET_VertexAttrib2fNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2fNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2fvNV)(GLuint, const GLfloat *);
#define CALL_VertexAttrib2fvNV(disp, parameters) \
    (* GET_VertexAttrib2fvNV(disp)) parameters
static inline _glptr_VertexAttrib2fvNV GET_VertexAttrib2fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2fvNV) (GET_by_offset(disp, _gloffset_VertexAttrib2fvNV));
}

static inline void SET_VertexAttrib2fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2sNV)(GLuint, GLshort, GLshort);
#define CALL_VertexAttrib2sNV(disp, parameters) \
    (* GET_VertexAttrib2sNV(disp)) parameters
static inline _glptr_VertexAttrib2sNV GET_VertexAttrib2sNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2sNV) (GET_by_offset(disp, _gloffset_VertexAttrib2sNV));
}

static inline void SET_VertexAttrib2sNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2sNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib2svNV)(GLuint, const GLshort *);
#define CALL_VertexAttrib2svNV(disp, parameters) \
    (* GET_VertexAttrib2svNV(disp)) parameters
static inline _glptr_VertexAttrib2svNV GET_VertexAttrib2svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib2svNV) (GET_by_offset(disp, _gloffset_VertexAttrib2svNV));
}

static inline void SET_VertexAttrib2svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib2svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3dNV)(GLuint, GLdouble, GLdouble, GLdouble);
#define CALL_VertexAttrib3dNV(disp, parameters) \
    (* GET_VertexAttrib3dNV(disp)) parameters
static inline _glptr_VertexAttrib3dNV GET_VertexAttrib3dNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3dNV) (GET_by_offset(disp, _gloffset_VertexAttrib3dNV));
}

static inline void SET_VertexAttrib3dNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3dNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3dvNV)(GLuint, const GLdouble *);
#define CALL_VertexAttrib3dvNV(disp, parameters) \
    (* GET_VertexAttrib3dvNV(disp)) parameters
static inline _glptr_VertexAttrib3dvNV GET_VertexAttrib3dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3dvNV) (GET_by_offset(disp, _gloffset_VertexAttrib3dvNV));
}

static inline void SET_VertexAttrib3dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3fNV)(GLuint, GLfloat, GLfloat, GLfloat);
#define CALL_VertexAttrib3fNV(disp, parameters) \
    (* GET_VertexAttrib3fNV(disp)) parameters
static inline _glptr_VertexAttrib3fNV GET_VertexAttrib3fNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3fNV) (GET_by_offset(disp, _gloffset_VertexAttrib3fNV));
}

static inline void SET_VertexAttrib3fNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3fNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3fvNV)(GLuint, const GLfloat *);
#define CALL_VertexAttrib3fvNV(disp, parameters) \
    (* GET_VertexAttrib3fvNV(disp)) parameters
static inline _glptr_VertexAttrib3fvNV GET_VertexAttrib3fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3fvNV) (GET_by_offset(disp, _gloffset_VertexAttrib3fvNV));
}

static inline void SET_VertexAttrib3fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3sNV)(GLuint, GLshort, GLshort, GLshort);
#define CALL_VertexAttrib3sNV(disp, parameters) \
    (* GET_VertexAttrib3sNV(disp)) parameters
static inline _glptr_VertexAttrib3sNV GET_VertexAttrib3sNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3sNV) (GET_by_offset(disp, _gloffset_VertexAttrib3sNV));
}

static inline void SET_VertexAttrib3sNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3sNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib3svNV)(GLuint, const GLshort *);
#define CALL_VertexAttrib3svNV(disp, parameters) \
    (* GET_VertexAttrib3svNV(disp)) parameters
static inline _glptr_VertexAttrib3svNV GET_VertexAttrib3svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib3svNV) (GET_by_offset(disp, _gloffset_VertexAttrib3svNV));
}

static inline void SET_VertexAttrib3svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib3svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4dNV)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_VertexAttrib4dNV(disp, parameters) \
    (* GET_VertexAttrib4dNV(disp)) parameters
static inline _glptr_VertexAttrib4dNV GET_VertexAttrib4dNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4dNV) (GET_by_offset(disp, _gloffset_VertexAttrib4dNV));
}

static inline void SET_VertexAttrib4dNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4dNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4dvNV)(GLuint, const GLdouble *);
#define CALL_VertexAttrib4dvNV(disp, parameters) \
    (* GET_VertexAttrib4dvNV(disp)) parameters
static inline _glptr_VertexAttrib4dvNV GET_VertexAttrib4dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4dvNV) (GET_by_offset(disp, _gloffset_VertexAttrib4dvNV));
}

static inline void SET_VertexAttrib4dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4fNV)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_VertexAttrib4fNV(disp, parameters) \
    (* GET_VertexAttrib4fNV(disp)) parameters
static inline _glptr_VertexAttrib4fNV GET_VertexAttrib4fNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4fNV) (GET_by_offset(disp, _gloffset_VertexAttrib4fNV));
}

static inline void SET_VertexAttrib4fNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4fNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4fvNV)(GLuint, const GLfloat *);
#define CALL_VertexAttrib4fvNV(disp, parameters) \
    (* GET_VertexAttrib4fvNV(disp)) parameters
static inline _glptr_VertexAttrib4fvNV GET_VertexAttrib4fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4fvNV) (GET_by_offset(disp, _gloffset_VertexAttrib4fvNV));
}

static inline void SET_VertexAttrib4fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4sNV)(GLuint, GLshort, GLshort, GLshort, GLshort);
#define CALL_VertexAttrib4sNV(disp, parameters) \
    (* GET_VertexAttrib4sNV(disp)) parameters
static inline _glptr_VertexAttrib4sNV GET_VertexAttrib4sNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4sNV) (GET_by_offset(disp, _gloffset_VertexAttrib4sNV));
}

static inline void SET_VertexAttrib4sNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLshort, GLshort, GLshort, GLshort)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4sNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4svNV)(GLuint, const GLshort *);
#define CALL_VertexAttrib4svNV(disp, parameters) \
    (* GET_VertexAttrib4svNV(disp)) parameters
static inline _glptr_VertexAttrib4svNV GET_VertexAttrib4svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4svNV) (GET_by_offset(disp, _gloffset_VertexAttrib4svNV));
}

static inline void SET_VertexAttrib4svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4ubNV)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
#define CALL_VertexAttrib4ubNV(disp, parameters) \
    (* GET_VertexAttrib4ubNV(disp)) parameters
static inline _glptr_VertexAttrib4ubNV GET_VertexAttrib4ubNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4ubNV) (GET_by_offset(disp, _gloffset_VertexAttrib4ubNV));
}

static inline void SET_VertexAttrib4ubNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4ubNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttrib4ubvNV)(GLuint, const GLubyte *);
#define CALL_VertexAttrib4ubvNV(disp, parameters) \
    (* GET_VertexAttrib4ubvNV(disp)) parameters
static inline _glptr_VertexAttrib4ubvNV GET_VertexAttrib4ubvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttrib4ubvNV) (GET_by_offset(disp, _gloffset_VertexAttrib4ubvNV));
}

static inline void SET_VertexAttrib4ubvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttrib4ubvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribPointerNV)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define CALL_VertexAttribPointerNV(disp, parameters) \
    (* GET_VertexAttribPointerNV(disp)) parameters
static inline _glptr_VertexAttribPointerNV GET_VertexAttribPointerNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribPointerNV) (GET_by_offset(disp, _gloffset_VertexAttribPointerNV));
}

static inline void SET_VertexAttribPointerNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLenum, GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VertexAttribPointerNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs1dvNV)(GLuint, GLsizei, const GLdouble *);
#define CALL_VertexAttribs1dvNV(disp, parameters) \
    (* GET_VertexAttribs1dvNV(disp)) parameters
static inline _glptr_VertexAttribs1dvNV GET_VertexAttribs1dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs1dvNV) (GET_by_offset(disp, _gloffset_VertexAttribs1dvNV));
}

static inline void SET_VertexAttribs1dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs1dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs1fvNV)(GLuint, GLsizei, const GLfloat *);
#define CALL_VertexAttribs1fvNV(disp, parameters) \
    (* GET_VertexAttribs1fvNV(disp)) parameters
static inline _glptr_VertexAttribs1fvNV GET_VertexAttribs1fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs1fvNV) (GET_by_offset(disp, _gloffset_VertexAttribs1fvNV));
}

static inline void SET_VertexAttribs1fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs1fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs1svNV)(GLuint, GLsizei, const GLshort *);
#define CALL_VertexAttribs1svNV(disp, parameters) \
    (* GET_VertexAttribs1svNV(disp)) parameters
static inline _glptr_VertexAttribs1svNV GET_VertexAttribs1svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs1svNV) (GET_by_offset(disp, _gloffset_VertexAttribs1svNV));
}

static inline void SET_VertexAttribs1svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs1svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs2dvNV)(GLuint, GLsizei, const GLdouble *);
#define CALL_VertexAttribs2dvNV(disp, parameters) \
    (* GET_VertexAttribs2dvNV(disp)) parameters
static inline _glptr_VertexAttribs2dvNV GET_VertexAttribs2dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs2dvNV) (GET_by_offset(disp, _gloffset_VertexAttribs2dvNV));
}

static inline void SET_VertexAttribs2dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs2dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs2fvNV)(GLuint, GLsizei, const GLfloat *);
#define CALL_VertexAttribs2fvNV(disp, parameters) \
    (* GET_VertexAttribs2fvNV(disp)) parameters
static inline _glptr_VertexAttribs2fvNV GET_VertexAttribs2fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs2fvNV) (GET_by_offset(disp, _gloffset_VertexAttribs2fvNV));
}

static inline void SET_VertexAttribs2fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs2fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs2svNV)(GLuint, GLsizei, const GLshort *);
#define CALL_VertexAttribs2svNV(disp, parameters) \
    (* GET_VertexAttribs2svNV(disp)) parameters
static inline _glptr_VertexAttribs2svNV GET_VertexAttribs2svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs2svNV) (GET_by_offset(disp, _gloffset_VertexAttribs2svNV));
}

static inline void SET_VertexAttribs2svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs2svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs3dvNV)(GLuint, GLsizei, const GLdouble *);
#define CALL_VertexAttribs3dvNV(disp, parameters) \
    (* GET_VertexAttribs3dvNV(disp)) parameters
static inline _glptr_VertexAttribs3dvNV GET_VertexAttribs3dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs3dvNV) (GET_by_offset(disp, _gloffset_VertexAttribs3dvNV));
}

static inline void SET_VertexAttribs3dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs3dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs3fvNV)(GLuint, GLsizei, const GLfloat *);
#define CALL_VertexAttribs3fvNV(disp, parameters) \
    (* GET_VertexAttribs3fvNV(disp)) parameters
static inline _glptr_VertexAttribs3fvNV GET_VertexAttribs3fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs3fvNV) (GET_by_offset(disp, _gloffset_VertexAttribs3fvNV));
}

static inline void SET_VertexAttribs3fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs3fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs3svNV)(GLuint, GLsizei, const GLshort *);
#define CALL_VertexAttribs3svNV(disp, parameters) \
    (* GET_VertexAttribs3svNV(disp)) parameters
static inline _glptr_VertexAttribs3svNV GET_VertexAttribs3svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs3svNV) (GET_by_offset(disp, _gloffset_VertexAttribs3svNV));
}

static inline void SET_VertexAttribs3svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs3svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs4dvNV)(GLuint, GLsizei, const GLdouble *);
#define CALL_VertexAttribs4dvNV(disp, parameters) \
    (* GET_VertexAttribs4dvNV(disp)) parameters
static inline _glptr_VertexAttribs4dvNV GET_VertexAttribs4dvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs4dvNV) (GET_by_offset(disp, _gloffset_VertexAttribs4dvNV));
}

static inline void SET_VertexAttribs4dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs4dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs4fvNV)(GLuint, GLsizei, const GLfloat *);
#define CALL_VertexAttribs4fvNV(disp, parameters) \
    (* GET_VertexAttribs4fvNV(disp)) parameters
static inline _glptr_VertexAttribs4fvNV GET_VertexAttribs4fvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs4fvNV) (GET_by_offset(disp, _gloffset_VertexAttribs4fvNV));
}

static inline void SET_VertexAttribs4fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs4fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs4svNV)(GLuint, GLsizei, const GLshort *);
#define CALL_VertexAttribs4svNV(disp, parameters) \
    (* GET_VertexAttribs4svNV(disp)) parameters
static inline _glptr_VertexAttribs4svNV GET_VertexAttribs4svNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs4svNV) (GET_by_offset(disp, _gloffset_VertexAttribs4svNV));
}

static inline void SET_VertexAttribs4svNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLshort *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs4svNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribs4ubvNV)(GLuint, GLsizei, const GLubyte *);
#define CALL_VertexAttribs4ubvNV(disp, parameters) \
    (* GET_VertexAttribs4ubvNV(disp)) parameters
static inline _glptr_VertexAttribs4ubvNV GET_VertexAttribs4ubvNV(struct _glapi_table *disp) {
   return (_glptr_VertexAttribs4ubvNV) (GET_by_offset(disp, _gloffset_VertexAttribs4ubvNV));
}

static inline void SET_VertexAttribs4ubvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *)) {
   SET_by_offset(disp, _gloffset_VertexAttribs4ubvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexBumpParameterfvATI)(GLenum, GLfloat *);
#define CALL_GetTexBumpParameterfvATI(disp, parameters) \
    (* GET_GetTexBumpParameterfvATI(disp)) parameters
static inline _glptr_GetTexBumpParameterfvATI GET_GetTexBumpParameterfvATI(struct _glapi_table *disp) {
   return (_glptr_GetTexBumpParameterfvATI) (GET_by_offset(disp, _gloffset_GetTexBumpParameterfvATI));
}

static inline void SET_GetTexBumpParameterfvATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetTexBumpParameterfvATI, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexBumpParameterivATI)(GLenum, GLint *);
#define CALL_GetTexBumpParameterivATI(disp, parameters) \
    (* GET_GetTexBumpParameterivATI(disp)) parameters
static inline _glptr_GetTexBumpParameterivATI GET_GetTexBumpParameterivATI(struct _glapi_table *disp) {
   return (_glptr_GetTexBumpParameterivATI) (GET_by_offset(disp, _gloffset_GetTexBumpParameterivATI));
}

static inline void SET_GetTexBumpParameterivATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetTexBumpParameterivATI, fn);
}

typedef void (GLAPIENTRYP _glptr_TexBumpParameterfvATI)(GLenum, const GLfloat *);
#define CALL_TexBumpParameterfvATI(disp, parameters) \
    (* GET_TexBumpParameterfvATI(disp)) parameters
static inline _glptr_TexBumpParameterfvATI GET_TexBumpParameterfvATI(struct _glapi_table *disp) {
   return (_glptr_TexBumpParameterfvATI) (GET_by_offset(disp, _gloffset_TexBumpParameterfvATI));
}

static inline void SET_TexBumpParameterfvATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_TexBumpParameterfvATI, fn);
}

typedef void (GLAPIENTRYP _glptr_TexBumpParameterivATI)(GLenum, const GLint *);
#define CALL_TexBumpParameterivATI(disp, parameters) \
    (* GET_TexBumpParameterivATI(disp)) parameters
static inline _glptr_TexBumpParameterivATI GET_TexBumpParameterivATI(struct _glapi_table *disp) {
   return (_glptr_TexBumpParameterivATI) (GET_by_offset(disp, _gloffset_TexBumpParameterivATI));
}

static inline void SET_TexBumpParameterivATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_TexBumpParameterivATI, fn);
}

typedef void (GLAPIENTRYP _glptr_AlphaFragmentOp1ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_AlphaFragmentOp1ATI(disp, parameters) \
    (* GET_AlphaFragmentOp1ATI(disp)) parameters
static inline _glptr_AlphaFragmentOp1ATI GET_AlphaFragmentOp1ATI(struct _glapi_table *disp) {
   return (_glptr_AlphaFragmentOp1ATI) (GET_by_offset(disp, _gloffset_AlphaFragmentOp1ATI));
}

static inline void SET_AlphaFragmentOp1ATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_AlphaFragmentOp1ATI, fn);
}

typedef void (GLAPIENTRYP _glptr_AlphaFragmentOp2ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_AlphaFragmentOp2ATI(disp, parameters) \
    (* GET_AlphaFragmentOp2ATI(disp)) parameters
static inline _glptr_AlphaFragmentOp2ATI GET_AlphaFragmentOp2ATI(struct _glapi_table *disp) {
   return (_glptr_AlphaFragmentOp2ATI) (GET_by_offset(disp, _gloffset_AlphaFragmentOp2ATI));
}

static inline void SET_AlphaFragmentOp2ATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_AlphaFragmentOp2ATI, fn);
}

typedef void (GLAPIENTRYP _glptr_AlphaFragmentOp3ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_AlphaFragmentOp3ATI(disp, parameters) \
    (* GET_AlphaFragmentOp3ATI(disp)) parameters
static inline _glptr_AlphaFragmentOp3ATI GET_AlphaFragmentOp3ATI(struct _glapi_table *disp) {
   return (_glptr_AlphaFragmentOp3ATI) (GET_by_offset(disp, _gloffset_AlphaFragmentOp3ATI));
}

static inline void SET_AlphaFragmentOp3ATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_AlphaFragmentOp3ATI, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginFragmentShaderATI)(void);
#define CALL_BeginFragmentShaderATI(disp, parameters) \
    (* GET_BeginFragmentShaderATI(disp)) parameters
static inline _glptr_BeginFragmentShaderATI GET_BeginFragmentShaderATI(struct _glapi_table *disp) {
   return (_glptr_BeginFragmentShaderATI) (GET_by_offset(disp, _gloffset_BeginFragmentShaderATI));
}

static inline void SET_BeginFragmentShaderATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_BeginFragmentShaderATI, fn);
}

typedef void (GLAPIENTRYP _glptr_BindFragmentShaderATI)(GLuint);
#define CALL_BindFragmentShaderATI(disp, parameters) \
    (* GET_BindFragmentShaderATI(disp)) parameters
static inline _glptr_BindFragmentShaderATI GET_BindFragmentShaderATI(struct _glapi_table *disp) {
   return (_glptr_BindFragmentShaderATI) (GET_by_offset(disp, _gloffset_BindFragmentShaderATI));
}

static inline void SET_BindFragmentShaderATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_BindFragmentShaderATI, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorFragmentOp1ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_ColorFragmentOp1ATI(disp, parameters) \
    (* GET_ColorFragmentOp1ATI(disp)) parameters
static inline _glptr_ColorFragmentOp1ATI GET_ColorFragmentOp1ATI(struct _glapi_table *disp) {
   return (_glptr_ColorFragmentOp1ATI) (GET_by_offset(disp, _gloffset_ColorFragmentOp1ATI));
}

static inline void SET_ColorFragmentOp1ATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ColorFragmentOp1ATI, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorFragmentOp2ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_ColorFragmentOp2ATI(disp, parameters) \
    (* GET_ColorFragmentOp2ATI(disp)) parameters
static inline _glptr_ColorFragmentOp2ATI GET_ColorFragmentOp2ATI(struct _glapi_table *disp) {
   return (_glptr_ColorFragmentOp2ATI) (GET_by_offset(disp, _gloffset_ColorFragmentOp2ATI));
}

static inline void SET_ColorFragmentOp2ATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ColorFragmentOp2ATI, fn);
}

typedef void (GLAPIENTRYP _glptr_ColorFragmentOp3ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_ColorFragmentOp3ATI(disp, parameters) \
    (* GET_ColorFragmentOp3ATI(disp)) parameters
static inline _glptr_ColorFragmentOp3ATI GET_ColorFragmentOp3ATI(struct _glapi_table *disp) {
   return (_glptr_ColorFragmentOp3ATI) (GET_by_offset(disp, _gloffset_ColorFragmentOp3ATI));
}

static inline void SET_ColorFragmentOp3ATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ColorFragmentOp3ATI, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteFragmentShaderATI)(GLuint);
#define CALL_DeleteFragmentShaderATI(disp, parameters) \
    (* GET_DeleteFragmentShaderATI(disp)) parameters
static inline _glptr_DeleteFragmentShaderATI GET_DeleteFragmentShaderATI(struct _glapi_table *disp) {
   return (_glptr_DeleteFragmentShaderATI) (GET_by_offset(disp, _gloffset_DeleteFragmentShaderATI));
}

static inline void SET_DeleteFragmentShaderATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_DeleteFragmentShaderATI, fn);
}

typedef void (GLAPIENTRYP _glptr_EndFragmentShaderATI)(void);
#define CALL_EndFragmentShaderATI(disp, parameters) \
    (* GET_EndFragmentShaderATI(disp)) parameters
static inline _glptr_EndFragmentShaderATI GET_EndFragmentShaderATI(struct _glapi_table *disp) {
   return (_glptr_EndFragmentShaderATI) (GET_by_offset(disp, _gloffset_EndFragmentShaderATI));
}

static inline void SET_EndFragmentShaderATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_EndFragmentShaderATI, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_GenFragmentShadersATI)(GLuint);
#define CALL_GenFragmentShadersATI(disp, parameters) \
    (* GET_GenFragmentShadersATI(disp)) parameters
static inline _glptr_GenFragmentShadersATI GET_GenFragmentShadersATI(struct _glapi_table *disp) {
   return (_glptr_GenFragmentShadersATI) (GET_by_offset(disp, _gloffset_GenFragmentShadersATI));
}

static inline void SET_GenFragmentShadersATI(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_GenFragmentShadersATI, fn);
}

typedef void (GLAPIENTRYP _glptr_PassTexCoordATI)(GLuint, GLuint, GLenum);
#define CALL_PassTexCoordATI(disp, parameters) \
    (* GET_PassTexCoordATI(disp)) parameters
static inline _glptr_PassTexCoordATI GET_PassTexCoordATI(struct _glapi_table *disp) {
   return (_glptr_PassTexCoordATI) (GET_by_offset(disp, _gloffset_PassTexCoordATI));
}

static inline void SET_PassTexCoordATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_PassTexCoordATI, fn);
}

typedef void (GLAPIENTRYP _glptr_SampleMapATI)(GLuint, GLuint, GLenum);
#define CALL_SampleMapATI(disp, parameters) \
    (* GET_SampleMapATI(disp)) parameters
static inline _glptr_SampleMapATI GET_SampleMapATI(struct _glapi_table *disp) {
   return (_glptr_SampleMapATI) (GET_by_offset(disp, _gloffset_SampleMapATI));
}

static inline void SET_SampleMapATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_SampleMapATI, fn);
}

typedef void (GLAPIENTRYP _glptr_SetFragmentShaderConstantATI)(GLuint, const GLfloat *);
#define CALL_SetFragmentShaderConstantATI(disp, parameters) \
    (* GET_SetFragmentShaderConstantATI(disp)) parameters
static inline _glptr_SetFragmentShaderConstantATI GET_SetFragmentShaderConstantATI(struct _glapi_table *disp) {
   return (_glptr_SetFragmentShaderConstantATI) (GET_by_offset(disp, _gloffset_SetFragmentShaderConstantATI));
}

static inline void SET_SetFragmentShaderConstantATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_SetFragmentShaderConstantATI, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRangeArrayfvOES)(GLuint, GLsizei, const GLfloat *);
#define CALL_DepthRangeArrayfvOES(disp, parameters) \
    (* GET_DepthRangeArrayfvOES(disp)) parameters
static inline _glptr_DepthRangeArrayfvOES GET_DepthRangeArrayfvOES(struct _glapi_table *disp) {
   return (_glptr_DepthRangeArrayfvOES) (GET_by_offset(disp, _gloffset_DepthRangeArrayfvOES));
}

static inline void SET_DepthRangeArrayfvOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_DepthRangeArrayfvOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRangeIndexedfOES)(GLuint, GLfloat, GLfloat);
#define CALL_DepthRangeIndexedfOES(disp, parameters) \
    (* GET_DepthRangeIndexedfOES(disp)) parameters
static inline _glptr_DepthRangeIndexedfOES GET_DepthRangeIndexedfOES(struct _glapi_table *disp) {
   return (_glptr_DepthRangeIndexedfOES) (GET_by_offset(disp, _gloffset_DepthRangeIndexedfOES));
}

static inline void SET_DepthRangeIndexedfOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_DepthRangeIndexedfOES, fn);
}

typedef void (GLAPIENTRYP _glptr_ActiveStencilFaceEXT)(GLenum);
#define CALL_ActiveStencilFaceEXT(disp, parameters) \
    (* GET_ActiveStencilFaceEXT(disp)) parameters
static inline _glptr_ActiveStencilFaceEXT GET_ActiveStencilFaceEXT(struct _glapi_table *disp) {
   return (_glptr_ActiveStencilFaceEXT) (GET_by_offset(disp, _gloffset_ActiveStencilFaceEXT));
}

static inline void SET_ActiveStencilFaceEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum)) {
   SET_by_offset(disp, _gloffset_ActiveStencilFaceEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramNamedParameterdvNV)(GLuint, GLsizei, const GLubyte *, GLdouble *);
#define CALL_GetProgramNamedParameterdvNV(disp, parameters) \
    (* GET_GetProgramNamedParameterdvNV(disp)) parameters
static inline _glptr_GetProgramNamedParameterdvNV GET_GetProgramNamedParameterdvNV(struct _glapi_table *disp) {
   return (_glptr_GetProgramNamedParameterdvNV) (GET_by_offset(disp, _gloffset_GetProgramNamedParameterdvNV));
}

static inline void SET_GetProgramNamedParameterdvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *, GLdouble *)) {
   SET_by_offset(disp, _gloffset_GetProgramNamedParameterdvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetProgramNamedParameterfvNV)(GLuint, GLsizei, const GLubyte *, GLfloat *);
#define CALL_GetProgramNamedParameterfvNV(disp, parameters) \
    (* GET_GetProgramNamedParameterfvNV(disp)) parameters
static inline _glptr_GetProgramNamedParameterfvNV GET_GetProgramNamedParameterfvNV(struct _glapi_table *disp) {
   return (_glptr_GetProgramNamedParameterfvNV) (GET_by_offset(disp, _gloffset_GetProgramNamedParameterfvNV));
}

static inline void SET_GetProgramNamedParameterfvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetProgramNamedParameterfvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramNamedParameter4dNV)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble);
#define CALL_ProgramNamedParameter4dNV(disp, parameters) \
    (* GET_ProgramNamedParameter4dNV(disp)) parameters
static inline _glptr_ProgramNamedParameter4dNV GET_ProgramNamedParameter4dNV(struct _glapi_table *disp) {
   return (_glptr_ProgramNamedParameter4dNV) (GET_by_offset(disp, _gloffset_ProgramNamedParameter4dNV));
}

static inline void SET_ProgramNamedParameter4dNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble)) {
   SET_by_offset(disp, _gloffset_ProgramNamedParameter4dNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramNamedParameter4dvNV)(GLuint, GLsizei, const GLubyte *, const GLdouble *);
#define CALL_ProgramNamedParameter4dvNV(disp, parameters) \
    (* GET_ProgramNamedParameter4dvNV(disp)) parameters
static inline _glptr_ProgramNamedParameter4dvNV GET_ProgramNamedParameter4dvNV(struct _glapi_table *disp) {
   return (_glptr_ProgramNamedParameter4dvNV) (GET_by_offset(disp, _gloffset_ProgramNamedParameter4dvNV));
}

static inline void SET_ProgramNamedParameter4dvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *, const GLdouble *)) {
   SET_by_offset(disp, _gloffset_ProgramNamedParameter4dvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramNamedParameter4fNV)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_ProgramNamedParameter4fNV(disp, parameters) \
    (* GET_ProgramNamedParameter4fNV(disp)) parameters
static inline _glptr_ProgramNamedParameter4fNV GET_ProgramNamedParameter4fNV(struct _glapi_table *disp) {
   return (_glptr_ProgramNamedParameter4fNV) (GET_by_offset(disp, _gloffset_ProgramNamedParameter4fNV));
}

static inline void SET_ProgramNamedParameter4fNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_ProgramNamedParameter4fNV, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramNamedParameter4fvNV)(GLuint, GLsizei, const GLubyte *, const GLfloat *);
#define CALL_ProgramNamedParameter4fvNV(disp, parameters) \
    (* GET_ProgramNamedParameter4fvNV(disp)) parameters
static inline _glptr_ProgramNamedParameter4fvNV GET_ProgramNamedParameter4fvNV(struct _glapi_table *disp) {
   return (_glptr_ProgramNamedParameter4fvNV) (GET_by_offset(disp, _gloffset_ProgramNamedParameter4fvNV));
}

static inline void SET_ProgramNamedParameter4fvNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, const GLubyte *, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramNamedParameter4fvNV, fn);
}

typedef void (GLAPIENTRYP _glptr_PrimitiveRestartNV)(void);
#define CALL_PrimitiveRestartNV(disp, parameters) \
    (* GET_PrimitiveRestartNV(disp)) parameters
static inline _glptr_PrimitiveRestartNV GET_PrimitiveRestartNV(struct _glapi_table *disp) {
   return (_glptr_PrimitiveRestartNV) (GET_by_offset(disp, _gloffset_PrimitiveRestartNV));
}

static inline void SET_PrimitiveRestartNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_PrimitiveRestartNV, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexGenxvOES)(GLenum, GLenum, GLfixed *);
#define CALL_GetTexGenxvOES(disp, parameters) \
    (* GET_GetTexGenxvOES(disp)) parameters
static inline _glptr_GetTexGenxvOES GET_GetTexGenxvOES(struct _glapi_table *disp) {
   return (_glptr_GetTexGenxvOES) (GET_by_offset(disp, _gloffset_GetTexGenxvOES));
}

static inline void SET_GetTexGenxvOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetTexGenxvOES, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGenxOES)(GLenum, GLenum, GLint);
#define CALL_TexGenxOES(disp, parameters) \
    (* GET_TexGenxOES(disp)) parameters
static inline _glptr_TexGenxOES GET_TexGenxOES(struct _glapi_table *disp) {
   return (_glptr_TexGenxOES) (GET_by_offset(disp, _gloffset_TexGenxOES));
}

static inline void SET_TexGenxOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_TexGenxOES, fn);
}

typedef void (GLAPIENTRYP _glptr_TexGenxvOES)(GLenum, GLenum, const GLfixed *);
#define CALL_TexGenxvOES(disp, parameters) \
    (* GET_TexGenxvOES(disp)) parameters
static inline _glptr_TexGenxvOES GET_TexGenxvOES(struct _glapi_table *disp) {
   return (_glptr_TexGenxvOES) (GET_by_offset(disp, _gloffset_TexGenxvOES));
}

static inline void SET_TexGenxvOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_TexGenxvOES, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthBoundsEXT)(GLclampd, GLclampd);
#define CALL_DepthBoundsEXT(disp, parameters) \
    (* GET_DepthBoundsEXT(disp)) parameters
static inline _glptr_DepthBoundsEXT GET_DepthBoundsEXT(struct _glapi_table *disp) {
   return (_glptr_DepthBoundsEXT) (GET_by_offset(disp, _gloffset_DepthBoundsEXT));
}

static inline void SET_DepthBoundsEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampd, GLclampd)) {
   SET_by_offset(disp, _gloffset_DepthBoundsEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_BindFramebufferEXT)(GLenum, GLuint);
#define CALL_BindFramebufferEXT(disp, parameters) \
    (* GET_BindFramebufferEXT(disp)) parameters
static inline _glptr_BindFramebufferEXT GET_BindFramebufferEXT(struct _glapi_table *disp) {
   return (_glptr_BindFramebufferEXT) (GET_by_offset(disp, _gloffset_BindFramebufferEXT));
}

static inline void SET_BindFramebufferEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindFramebufferEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_BindRenderbufferEXT)(GLenum, GLuint);
#define CALL_BindRenderbufferEXT(disp, parameters) \
    (* GET_BindRenderbufferEXT(disp)) parameters
static inline _glptr_BindRenderbufferEXT GET_BindRenderbufferEXT(struct _glapi_table *disp) {
   return (_glptr_BindRenderbufferEXT) (GET_by_offset(disp, _gloffset_BindRenderbufferEXT));
}

static inline void SET_BindRenderbufferEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_BindRenderbufferEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_StringMarkerGREMEDY)(GLsizei, const GLvoid *);
#define CALL_StringMarkerGREMEDY(disp, parameters) \
    (* GET_StringMarkerGREMEDY(disp)) parameters
static inline _glptr_StringMarkerGREMEDY GET_StringMarkerGREMEDY(struct _glapi_table *disp) {
   return (_glptr_StringMarkerGREMEDY) (GET_by_offset(disp, _gloffset_StringMarkerGREMEDY));
}

static inline void SET_StringMarkerGREMEDY(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_StringMarkerGREMEDY, fn);
}

typedef void (GLAPIENTRYP _glptr_BufferParameteriAPPLE)(GLenum, GLenum, GLint);
#define CALL_BufferParameteriAPPLE(disp, parameters) \
    (* GET_BufferParameteriAPPLE(disp)) parameters
static inline _glptr_BufferParameteriAPPLE GET_BufferParameteriAPPLE(struct _glapi_table *disp) {
   return (_glptr_BufferParameteriAPPLE) (GET_by_offset(disp, _gloffset_BufferParameteriAPPLE));
}

static inline void SET_BufferParameteriAPPLE(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_BufferParameteriAPPLE, fn);
}

typedef void (GLAPIENTRYP _glptr_FlushMappedBufferRangeAPPLE)(GLenum, GLintptr, GLsizeiptr);
#define CALL_FlushMappedBufferRangeAPPLE(disp, parameters) \
    (* GET_FlushMappedBufferRangeAPPLE(disp)) parameters
static inline _glptr_FlushMappedBufferRangeAPPLE GET_FlushMappedBufferRangeAPPLE(struct _glapi_table *disp) {
   return (_glptr_FlushMappedBufferRangeAPPLE) (GET_by_offset(disp, _gloffset_FlushMappedBufferRangeAPPLE));
}

static inline void SET_FlushMappedBufferRangeAPPLE(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLintptr, GLsizeiptr)) {
   SET_by_offset(disp, _gloffset_FlushMappedBufferRangeAPPLE, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI1iEXT)(GLuint, GLint);
#define CALL_VertexAttribI1iEXT(disp, parameters) \
    (* GET_VertexAttribI1iEXT(disp)) parameters
static inline _glptr_VertexAttribI1iEXT GET_VertexAttribI1iEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI1iEXT) (GET_by_offset(disp, _gloffset_VertexAttribI1iEXT));
}

static inline void SET_VertexAttribI1iEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI1iEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI1uiEXT)(GLuint, GLuint);
#define CALL_VertexAttribI1uiEXT(disp, parameters) \
    (* GET_VertexAttribI1uiEXT(disp)) parameters
static inline _glptr_VertexAttribI1uiEXT GET_VertexAttribI1uiEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI1uiEXT) (GET_by_offset(disp, _gloffset_VertexAttribI1uiEXT));
}

static inline void SET_VertexAttribI1uiEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI1uiEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI2iEXT)(GLuint, GLint, GLint);
#define CALL_VertexAttribI2iEXT(disp, parameters) \
    (* GET_VertexAttribI2iEXT(disp)) parameters
static inline _glptr_VertexAttribI2iEXT GET_VertexAttribI2iEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI2iEXT) (GET_by_offset(disp, _gloffset_VertexAttribI2iEXT));
}

static inline void SET_VertexAttribI2iEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI2iEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI2ivEXT)(GLuint, const GLint *);
#define CALL_VertexAttribI2ivEXT(disp, parameters) \
    (* GET_VertexAttribI2ivEXT(disp)) parameters
static inline _glptr_VertexAttribI2ivEXT GET_VertexAttribI2ivEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI2ivEXT) (GET_by_offset(disp, _gloffset_VertexAttribI2ivEXT));
}

static inline void SET_VertexAttribI2ivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI2ivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI2uiEXT)(GLuint, GLuint, GLuint);
#define CALL_VertexAttribI2uiEXT(disp, parameters) \
    (* GET_VertexAttribI2uiEXT(disp)) parameters
static inline _glptr_VertexAttribI2uiEXT GET_VertexAttribI2uiEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI2uiEXT) (GET_by_offset(disp, _gloffset_VertexAttribI2uiEXT));
}

static inline void SET_VertexAttribI2uiEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI2uiEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI2uivEXT)(GLuint, const GLuint *);
#define CALL_VertexAttribI2uivEXT(disp, parameters) \
    (* GET_VertexAttribI2uivEXT(disp)) parameters
static inline _glptr_VertexAttribI2uivEXT GET_VertexAttribI2uivEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI2uivEXT) (GET_by_offset(disp, _gloffset_VertexAttribI2uivEXT));
}

static inline void SET_VertexAttribI2uivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI2uivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI3iEXT)(GLuint, GLint, GLint, GLint);
#define CALL_VertexAttribI3iEXT(disp, parameters) \
    (* GET_VertexAttribI3iEXT(disp)) parameters
static inline _glptr_VertexAttribI3iEXT GET_VertexAttribI3iEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI3iEXT) (GET_by_offset(disp, _gloffset_VertexAttribI3iEXT));
}

static inline void SET_VertexAttribI3iEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI3iEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI3ivEXT)(GLuint, const GLint *);
#define CALL_VertexAttribI3ivEXT(disp, parameters) \
    (* GET_VertexAttribI3ivEXT(disp)) parameters
static inline _glptr_VertexAttribI3ivEXT GET_VertexAttribI3ivEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI3ivEXT) (GET_by_offset(disp, _gloffset_VertexAttribI3ivEXT));
}

static inline void SET_VertexAttribI3ivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI3ivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI3uiEXT)(GLuint, GLuint, GLuint, GLuint);
#define CALL_VertexAttribI3uiEXT(disp, parameters) \
    (* GET_VertexAttribI3uiEXT(disp)) parameters
static inline _glptr_VertexAttribI3uiEXT GET_VertexAttribI3uiEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI3uiEXT) (GET_by_offset(disp, _gloffset_VertexAttribI3uiEXT));
}

static inline void SET_VertexAttribI3uiEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI3uiEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI3uivEXT)(GLuint, const GLuint *);
#define CALL_VertexAttribI3uivEXT(disp, parameters) \
    (* GET_VertexAttribI3uivEXT(disp)) parameters
static inline _glptr_VertexAttribI3uivEXT GET_VertexAttribI3uivEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI3uivEXT) (GET_by_offset(disp, _gloffset_VertexAttribI3uivEXT));
}

static inline void SET_VertexAttribI3uivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI3uivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4iEXT)(GLuint, GLint, GLint, GLint, GLint);
#define CALL_VertexAttribI4iEXT(disp, parameters) \
    (* GET_VertexAttribI4iEXT(disp)) parameters
static inline _glptr_VertexAttribI4iEXT GET_VertexAttribI4iEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4iEXT) (GET_by_offset(disp, _gloffset_VertexAttribI4iEXT));
}

static inline void SET_VertexAttribI4iEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4iEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4ivEXT)(GLuint, const GLint *);
#define CALL_VertexAttribI4ivEXT(disp, parameters) \
    (* GET_VertexAttribI4ivEXT(disp)) parameters
static inline _glptr_VertexAttribI4ivEXT GET_VertexAttribI4ivEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4ivEXT) (GET_by_offset(disp, _gloffset_VertexAttribI4ivEXT));
}

static inline void SET_VertexAttribI4ivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4ivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4uiEXT)(GLuint, GLuint, GLuint, GLuint, GLuint);
#define CALL_VertexAttribI4uiEXT(disp, parameters) \
    (* GET_VertexAttribI4uiEXT(disp)) parameters
static inline _glptr_VertexAttribI4uiEXT GET_VertexAttribI4uiEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4uiEXT) (GET_by_offset(disp, _gloffset_VertexAttribI4uiEXT));
}

static inline void SET_VertexAttribI4uiEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4uiEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_VertexAttribI4uivEXT)(GLuint, const GLuint *);
#define CALL_VertexAttribI4uivEXT(disp, parameters) \
    (* GET_VertexAttribI4uivEXT(disp)) parameters
static inline _glptr_VertexAttribI4uivEXT GET_VertexAttribI4uivEXT(struct _glapi_table *disp) {
   return (_glptr_VertexAttribI4uivEXT) (GET_by_offset(disp, _gloffset_VertexAttribI4uivEXT));
}

static inline void SET_VertexAttribI4uivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VertexAttribI4uivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearColorIiEXT)(GLint, GLint, GLint, GLint);
#define CALL_ClearColorIiEXT(disp, parameters) \
    (* GET_ClearColorIiEXT(disp)) parameters
static inline _glptr_ClearColorIiEXT GET_ClearColorIiEXT(struct _glapi_table *disp) {
   return (_glptr_ClearColorIiEXT) (GET_by_offset(disp, _gloffset_ClearColorIiEXT));
}

static inline void SET_ClearColorIiEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint, GLint, GLint, GLint)) {
   SET_by_offset(disp, _gloffset_ClearColorIiEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearColorIuiEXT)(GLuint, GLuint, GLuint, GLuint);
#define CALL_ClearColorIuiEXT(disp, parameters) \
    (* GET_ClearColorIuiEXT(disp)) parameters
static inline _glptr_ClearColorIuiEXT GET_ClearColorIuiEXT(struct _glapi_table *disp) {
   return (_glptr_ClearColorIuiEXT) (GET_by_offset(disp, _gloffset_ClearColorIuiEXT));
}

static inline void SET_ClearColorIuiEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLuint)) {
   SET_by_offset(disp, _gloffset_ClearColorIuiEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_BindBufferOffsetEXT)(GLenum, GLuint, GLuint, GLintptr);
#define CALL_BindBufferOffsetEXT(disp, parameters) \
    (* GET_BindBufferOffsetEXT(disp)) parameters
static inline _glptr_BindBufferOffsetEXT GET_BindBufferOffsetEXT(struct _glapi_table *disp) {
   return (_glptr_BindBufferOffsetEXT) (GET_by_offset(disp, _gloffset_BindBufferOffsetEXT));
}

static inline void SET_BindBufferOffsetEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLuint, GLintptr)) {
   SET_by_offset(disp, _gloffset_BindBufferOffsetEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginPerfMonitorAMD)(GLuint);
#define CALL_BeginPerfMonitorAMD(disp, parameters) \
    (* GET_BeginPerfMonitorAMD(disp)) parameters
static inline _glptr_BeginPerfMonitorAMD GET_BeginPerfMonitorAMD(struct _glapi_table *disp) {
   return (_glptr_BeginPerfMonitorAMD) (GET_by_offset(disp, _gloffset_BeginPerfMonitorAMD));
}

static inline void SET_BeginPerfMonitorAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_BeginPerfMonitorAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_DeletePerfMonitorsAMD)(GLsizei, GLuint *);
#define CALL_DeletePerfMonitorsAMD(disp, parameters) \
    (* GET_DeletePerfMonitorsAMD(disp)) parameters
static inline _glptr_DeletePerfMonitorsAMD GET_DeletePerfMonitorsAMD(struct _glapi_table *disp) {
   return (_glptr_DeletePerfMonitorsAMD) (GET_by_offset(disp, _gloffset_DeletePerfMonitorsAMD));
}

static inline void SET_DeletePerfMonitorsAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_DeletePerfMonitorsAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_EndPerfMonitorAMD)(GLuint);
#define CALL_EndPerfMonitorAMD(disp, parameters) \
    (* GET_EndPerfMonitorAMD(disp)) parameters
static inline _glptr_EndPerfMonitorAMD GET_EndPerfMonitorAMD(struct _glapi_table *disp) {
   return (_glptr_EndPerfMonitorAMD) (GET_by_offset(disp, _gloffset_EndPerfMonitorAMD));
}

static inline void SET_EndPerfMonitorAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_EndPerfMonitorAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GenPerfMonitorsAMD)(GLsizei, GLuint *);
#define CALL_GenPerfMonitorsAMD(disp, parameters) \
    (* GET_GenPerfMonitorsAMD(disp)) parameters
static inline _glptr_GenPerfMonitorsAMD GET_GenPerfMonitorsAMD(struct _glapi_table *disp) {
   return (_glptr_GenPerfMonitorsAMD) (GET_by_offset(disp, _gloffset_GenPerfMonitorsAMD));
}

static inline void SET_GenPerfMonitorsAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenPerfMonitorsAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfMonitorCounterDataAMD)(GLuint, GLenum, GLsizei, GLuint *, GLint *);
#define CALL_GetPerfMonitorCounterDataAMD(disp, parameters) \
    (* GET_GetPerfMonitorCounterDataAMD(disp)) parameters
static inline _glptr_GetPerfMonitorCounterDataAMD GET_GetPerfMonitorCounterDataAMD(struct _glapi_table *disp) {
   return (_glptr_GetPerfMonitorCounterDataAMD) (GET_by_offset(disp, _gloffset_GetPerfMonitorCounterDataAMD));
}

static inline void SET_GetPerfMonitorCounterDataAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLsizei, GLuint *, GLint *)) {
   SET_by_offset(disp, _gloffset_GetPerfMonitorCounterDataAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfMonitorCounterInfoAMD)(GLuint, GLuint, GLenum, GLvoid *);
#define CALL_GetPerfMonitorCounterInfoAMD(disp, parameters) \
    (* GET_GetPerfMonitorCounterInfoAMD(disp)) parameters
static inline _glptr_GetPerfMonitorCounterInfoAMD GET_GetPerfMonitorCounterInfoAMD(struct _glapi_table *disp) {
   return (_glptr_GetPerfMonitorCounterInfoAMD) (GET_by_offset(disp, _gloffset_GetPerfMonitorCounterInfoAMD));
}

static inline void SET_GetPerfMonitorCounterInfoAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_GetPerfMonitorCounterInfoAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfMonitorCounterStringAMD)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetPerfMonitorCounterStringAMD(disp, parameters) \
    (* GET_GetPerfMonitorCounterStringAMD(disp)) parameters
static inline _glptr_GetPerfMonitorCounterStringAMD GET_GetPerfMonitorCounterStringAMD(struct _glapi_table *disp) {
   return (_glptr_GetPerfMonitorCounterStringAMD) (GET_by_offset(disp, _gloffset_GetPerfMonitorCounterStringAMD));
}

static inline void SET_GetPerfMonitorCounterStringAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetPerfMonitorCounterStringAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfMonitorCountersAMD)(GLuint, GLint *, GLint *, GLsizei, GLuint *);
#define CALL_GetPerfMonitorCountersAMD(disp, parameters) \
    (* GET_GetPerfMonitorCountersAMD(disp)) parameters
static inline _glptr_GetPerfMonitorCountersAMD GET_GetPerfMonitorCountersAMD(struct _glapi_table *disp) {
   return (_glptr_GetPerfMonitorCountersAMD) (GET_by_offset(disp, _gloffset_GetPerfMonitorCountersAMD));
}

static inline void SET_GetPerfMonitorCountersAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLint *, GLint *, GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetPerfMonitorCountersAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfMonitorGroupStringAMD)(GLuint, GLsizei, GLsizei *, GLchar *);
#define CALL_GetPerfMonitorGroupStringAMD(disp, parameters) \
    (* GET_GetPerfMonitorGroupStringAMD(disp)) parameters
static inline _glptr_GetPerfMonitorGroupStringAMD GET_GetPerfMonitorGroupStringAMD(struct _glapi_table *disp) {
   return (_glptr_GetPerfMonitorGroupStringAMD) (GET_by_offset(disp, _gloffset_GetPerfMonitorGroupStringAMD));
}

static inline void SET_GetPerfMonitorGroupStringAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLsizei *, GLchar *)) {
   SET_by_offset(disp, _gloffset_GetPerfMonitorGroupStringAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfMonitorGroupsAMD)(GLint *, GLsizei, GLuint *);
#define CALL_GetPerfMonitorGroupsAMD(disp, parameters) \
    (* GET_GetPerfMonitorGroupsAMD(disp)) parameters
static inline _glptr_GetPerfMonitorGroupsAMD GET_GetPerfMonitorGroupsAMD(struct _glapi_table *disp) {
   return (_glptr_GetPerfMonitorGroupsAMD) (GET_by_offset(disp, _gloffset_GetPerfMonitorGroupsAMD));
}

static inline void SET_GetPerfMonitorGroupsAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLint *, GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetPerfMonitorGroupsAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_SelectPerfMonitorCountersAMD)(GLuint, GLboolean, GLuint, GLint, GLuint *);
#define CALL_SelectPerfMonitorCountersAMD(disp, parameters) \
    (* GET_SelectPerfMonitorCountersAMD(disp)) parameters
static inline _glptr_SelectPerfMonitorCountersAMD GET_SelectPerfMonitorCountersAMD(struct _glapi_table *disp) {
   return (_glptr_SelectPerfMonitorCountersAMD) (GET_by_offset(disp, _gloffset_SelectPerfMonitorCountersAMD));
}

static inline void SET_SelectPerfMonitorCountersAMD(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLboolean, GLuint, GLint, GLuint *)) {
   SET_by_offset(disp, _gloffset_SelectPerfMonitorCountersAMD, fn);
}

typedef void (GLAPIENTRYP _glptr_GetObjectParameterivAPPLE)(GLenum, GLuint, GLenum, GLint *);
#define CALL_GetObjectParameterivAPPLE(disp, parameters) \
    (* GET_GetObjectParameterivAPPLE(disp)) parameters
static inline _glptr_GetObjectParameterivAPPLE GET_GetObjectParameterivAPPLE(struct _glapi_table *disp) {
   return (_glptr_GetObjectParameterivAPPLE) (GET_by_offset(disp, _gloffset_GetObjectParameterivAPPLE));
}

static inline void SET_GetObjectParameterivAPPLE(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetObjectParameterivAPPLE, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_ObjectPurgeableAPPLE)(GLenum, GLuint, GLenum);
#define CALL_ObjectPurgeableAPPLE(disp, parameters) \
    (* GET_ObjectPurgeableAPPLE(disp)) parameters
static inline _glptr_ObjectPurgeableAPPLE GET_ObjectPurgeableAPPLE(struct _glapi_table *disp) {
   return (_glptr_ObjectPurgeableAPPLE) (GET_by_offset(disp, _gloffset_ObjectPurgeableAPPLE));
}

static inline void SET_ObjectPurgeableAPPLE(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(GLenum, GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_ObjectPurgeableAPPLE, fn);
}

typedef GLenum (GLAPIENTRYP _glptr_ObjectUnpurgeableAPPLE)(GLenum, GLuint, GLenum);
#define CALL_ObjectUnpurgeableAPPLE(disp, parameters) \
    (* GET_ObjectUnpurgeableAPPLE(disp)) parameters
static inline _glptr_ObjectUnpurgeableAPPLE GET_ObjectUnpurgeableAPPLE(struct _glapi_table *disp) {
   return (_glptr_ObjectUnpurgeableAPPLE) (GET_by_offset(disp, _gloffset_ObjectUnpurgeableAPPLE));
}

static inline void SET_ObjectUnpurgeableAPPLE(struct _glapi_table *disp, GLenum (GLAPIENTRYP fn)(GLenum, GLuint, GLenum)) {
   SET_by_offset(disp, _gloffset_ObjectUnpurgeableAPPLE, fn);
}

typedef void (GLAPIENTRYP _glptr_ActiveProgramEXT)(GLuint);
#define CALL_ActiveProgramEXT(disp, parameters) \
    (* GET_ActiveProgramEXT(disp)) parameters
static inline _glptr_ActiveProgramEXT GET_ActiveProgramEXT(struct _glapi_table *disp) {
   return (_glptr_ActiveProgramEXT) (GET_by_offset(disp, _gloffset_ActiveProgramEXT));
}

static inline void SET_ActiveProgramEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_ActiveProgramEXT, fn);
}

typedef GLuint (GLAPIENTRYP _glptr_CreateShaderProgramEXT)(GLenum, const GLchar *);
#define CALL_CreateShaderProgramEXT(disp, parameters) \
    (* GET_CreateShaderProgramEXT(disp)) parameters
static inline _glptr_CreateShaderProgramEXT GET_CreateShaderProgramEXT(struct _glapi_table *disp) {
   return (_glptr_CreateShaderProgramEXT) (GET_by_offset(disp, _gloffset_CreateShaderProgramEXT));
}

static inline void SET_CreateShaderProgramEXT(struct _glapi_table *disp, GLuint (GLAPIENTRYP fn)(GLenum, const GLchar *)) {
   SET_by_offset(disp, _gloffset_CreateShaderProgramEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_UseShaderProgramEXT)(GLenum, GLuint);
#define CALL_UseShaderProgramEXT(disp, parameters) \
    (* GET_UseShaderProgramEXT(disp)) parameters
static inline _glptr_UseShaderProgramEXT GET_UseShaderProgramEXT(struct _glapi_table *disp) {
   return (_glptr_UseShaderProgramEXT) (GET_by_offset(disp, _gloffset_UseShaderProgramEXT));
}

static inline void SET_UseShaderProgramEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint)) {
   SET_by_offset(disp, _gloffset_UseShaderProgramEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureBarrierNV)(void);
#define CALL_TextureBarrierNV(disp, parameters) \
    (* GET_TextureBarrierNV(disp)) parameters
static inline _glptr_TextureBarrierNV GET_TextureBarrierNV(struct _glapi_table *disp) {
   return (_glptr_TextureBarrierNV) (GET_by_offset(disp, _gloffset_TextureBarrierNV));
}

static inline void SET_TextureBarrierNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_TextureBarrierNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUFiniNV)(void);
#define CALL_VDPAUFiniNV(disp, parameters) \
    (* GET_VDPAUFiniNV(disp)) parameters
static inline _glptr_VDPAUFiniNV GET_VDPAUFiniNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUFiniNV) (GET_by_offset(disp, _gloffset_VDPAUFiniNV));
}

static inline void SET_VDPAUFiniNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_VDPAUFiniNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUGetSurfaceivNV)(GLintptr, GLenum, GLsizei, GLsizei *, GLint *);
#define CALL_VDPAUGetSurfaceivNV(disp, parameters) \
    (* GET_VDPAUGetSurfaceivNV(disp)) parameters
static inline _glptr_VDPAUGetSurfaceivNV GET_VDPAUGetSurfaceivNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUGetSurfaceivNV) (GET_by_offset(disp, _gloffset_VDPAUGetSurfaceivNV));
}

static inline void SET_VDPAUGetSurfaceivNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLintptr, GLenum, GLsizei, GLsizei *, GLint *)) {
   SET_by_offset(disp, _gloffset_VDPAUGetSurfaceivNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUInitNV)(const GLvoid *, const GLvoid *);
#define CALL_VDPAUInitNV(disp, parameters) \
    (* GET_VDPAUInitNV(disp)) parameters
static inline _glptr_VDPAUInitNV GET_VDPAUInitNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUInitNV) (GET_by_offset(disp, _gloffset_VDPAUInitNV));
}

static inline void SET_VDPAUInitNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLvoid *, const GLvoid *)) {
   SET_by_offset(disp, _gloffset_VDPAUInitNV, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_VDPAUIsSurfaceNV)(GLintptr);
#define CALL_VDPAUIsSurfaceNV(disp, parameters) \
    (* GET_VDPAUIsSurfaceNV(disp)) parameters
static inline _glptr_VDPAUIsSurfaceNV GET_VDPAUIsSurfaceNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUIsSurfaceNV) (GET_by_offset(disp, _gloffset_VDPAUIsSurfaceNV));
}

static inline void SET_VDPAUIsSurfaceNV(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLintptr)) {
   SET_by_offset(disp, _gloffset_VDPAUIsSurfaceNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUMapSurfacesNV)(GLsizei, const GLintptr *);
#define CALL_VDPAUMapSurfacesNV(disp, parameters) \
    (* GET_VDPAUMapSurfacesNV(disp)) parameters
static inline _glptr_VDPAUMapSurfacesNV GET_VDPAUMapSurfacesNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUMapSurfacesNV) (GET_by_offset(disp, _gloffset_VDPAUMapSurfacesNV));
}

static inline void SET_VDPAUMapSurfacesNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLintptr *)) {
   SET_by_offset(disp, _gloffset_VDPAUMapSurfacesNV, fn);
}

typedef GLintptr (GLAPIENTRYP _glptr_VDPAURegisterOutputSurfaceNV)(const GLvoid *, GLenum, GLsizei, const GLuint *);
#define CALL_VDPAURegisterOutputSurfaceNV(disp, parameters) \
    (* GET_VDPAURegisterOutputSurfaceNV(disp)) parameters
static inline _glptr_VDPAURegisterOutputSurfaceNV GET_VDPAURegisterOutputSurfaceNV(struct _glapi_table *disp) {
   return (_glptr_VDPAURegisterOutputSurfaceNV) (GET_by_offset(disp, _gloffset_VDPAURegisterOutputSurfaceNV));
}

static inline void SET_VDPAURegisterOutputSurfaceNV(struct _glapi_table *disp, GLintptr (GLAPIENTRYP fn)(const GLvoid *, GLenum, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VDPAURegisterOutputSurfaceNV, fn);
}

typedef GLintptr (GLAPIENTRYP _glptr_VDPAURegisterVideoSurfaceNV)(const GLvoid *, GLenum, GLsizei, const GLuint *);
#define CALL_VDPAURegisterVideoSurfaceNV(disp, parameters) \
    (* GET_VDPAURegisterVideoSurfaceNV(disp)) parameters
static inline _glptr_VDPAURegisterVideoSurfaceNV GET_VDPAURegisterVideoSurfaceNV(struct _glapi_table *disp) {
   return (_glptr_VDPAURegisterVideoSurfaceNV) (GET_by_offset(disp, _gloffset_VDPAURegisterVideoSurfaceNV));
}

static inline void SET_VDPAURegisterVideoSurfaceNV(struct _glapi_table *disp, GLintptr (GLAPIENTRYP fn)(const GLvoid *, GLenum, GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_VDPAURegisterVideoSurfaceNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUSurfaceAccessNV)(GLintptr, GLenum);
#define CALL_VDPAUSurfaceAccessNV(disp, parameters) \
    (* GET_VDPAUSurfaceAccessNV(disp)) parameters
static inline _glptr_VDPAUSurfaceAccessNV GET_VDPAUSurfaceAccessNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUSurfaceAccessNV) (GET_by_offset(disp, _gloffset_VDPAUSurfaceAccessNV));
}

static inline void SET_VDPAUSurfaceAccessNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLintptr, GLenum)) {
   SET_by_offset(disp, _gloffset_VDPAUSurfaceAccessNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUUnmapSurfacesNV)(GLsizei, const GLintptr *);
#define CALL_VDPAUUnmapSurfacesNV(disp, parameters) \
    (* GET_VDPAUUnmapSurfacesNV(disp)) parameters
static inline _glptr_VDPAUUnmapSurfacesNV GET_VDPAUUnmapSurfacesNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUUnmapSurfacesNV) (GET_by_offset(disp, _gloffset_VDPAUUnmapSurfacesNV));
}

static inline void SET_VDPAUUnmapSurfacesNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLintptr *)) {
   SET_by_offset(disp, _gloffset_VDPAUUnmapSurfacesNV, fn);
}

typedef void (GLAPIENTRYP _glptr_VDPAUUnregisterSurfaceNV)(GLintptr);
#define CALL_VDPAUUnregisterSurfaceNV(disp, parameters) \
    (* GET_VDPAUUnregisterSurfaceNV(disp)) parameters
static inline _glptr_VDPAUUnregisterSurfaceNV GET_VDPAUUnregisterSurfaceNV(struct _glapi_table *disp) {
   return (_glptr_VDPAUUnregisterSurfaceNV) (GET_by_offset(disp, _gloffset_VDPAUUnregisterSurfaceNV));
}

static inline void SET_VDPAUUnregisterSurfaceNV(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLintptr)) {
   SET_by_offset(disp, _gloffset_VDPAUUnregisterSurfaceNV, fn);
}

typedef void (GLAPIENTRYP _glptr_BeginPerfQueryINTEL)(GLuint);
#define CALL_BeginPerfQueryINTEL(disp, parameters) \
    (* GET_BeginPerfQueryINTEL(disp)) parameters
static inline _glptr_BeginPerfQueryINTEL GET_BeginPerfQueryINTEL(struct _glapi_table *disp) {
   return (_glptr_BeginPerfQueryINTEL) (GET_by_offset(disp, _gloffset_BeginPerfQueryINTEL));
}

static inline void SET_BeginPerfQueryINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_BeginPerfQueryINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_CreatePerfQueryINTEL)(GLuint, GLuint *);
#define CALL_CreatePerfQueryINTEL(disp, parameters) \
    (* GET_CreatePerfQueryINTEL(disp)) parameters
static inline _glptr_CreatePerfQueryINTEL GET_CreatePerfQueryINTEL(struct _glapi_table *disp) {
   return (_glptr_CreatePerfQueryINTEL) (GET_by_offset(disp, _gloffset_CreatePerfQueryINTEL));
}

static inline void SET_CreatePerfQueryINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreatePerfQueryINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_DeletePerfQueryINTEL)(GLuint);
#define CALL_DeletePerfQueryINTEL(disp, parameters) \
    (* GET_DeletePerfQueryINTEL(disp)) parameters
static inline _glptr_DeletePerfQueryINTEL GET_DeletePerfQueryINTEL(struct _glapi_table *disp) {
   return (_glptr_DeletePerfQueryINTEL) (GET_by_offset(disp, _gloffset_DeletePerfQueryINTEL));
}

static inline void SET_DeletePerfQueryINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_DeletePerfQueryINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_EndPerfQueryINTEL)(GLuint);
#define CALL_EndPerfQueryINTEL(disp, parameters) \
    (* GET_EndPerfQueryINTEL(disp)) parameters
static inline _glptr_EndPerfQueryINTEL GET_EndPerfQueryINTEL(struct _glapi_table *disp) {
   return (_glptr_EndPerfQueryINTEL) (GET_by_offset(disp, _gloffset_EndPerfQueryINTEL));
}

static inline void SET_EndPerfQueryINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_EndPerfQueryINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_GetFirstPerfQueryIdINTEL)(GLuint *);
#define CALL_GetFirstPerfQueryIdINTEL(disp, parameters) \
    (* GET_GetFirstPerfQueryIdINTEL(disp)) parameters
static inline _glptr_GetFirstPerfQueryIdINTEL GET_GetFirstPerfQueryIdINTEL(struct _glapi_table *disp) {
   return (_glptr_GetFirstPerfQueryIdINTEL) (GET_by_offset(disp, _gloffset_GetFirstPerfQueryIdINTEL));
}

static inline void SET_GetFirstPerfQueryIdINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint *)) {
   SET_by_offset(disp, _gloffset_GetFirstPerfQueryIdINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_GetNextPerfQueryIdINTEL)(GLuint, GLuint *);
#define CALL_GetNextPerfQueryIdINTEL(disp, parameters) \
    (* GET_GetNextPerfQueryIdINTEL(disp)) parameters
static inline _glptr_GetNextPerfQueryIdINTEL GET_GetNextPerfQueryIdINTEL(struct _glapi_table *disp) {
   return (_glptr_GetNextPerfQueryIdINTEL) (GET_by_offset(disp, _gloffset_GetNextPerfQueryIdINTEL));
}

static inline void SET_GetNextPerfQueryIdINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetNextPerfQueryIdINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfCounterInfoINTEL)(GLuint, GLuint, GLuint, GLchar *, GLuint, GLchar *, GLuint *, GLuint *, GLuint *, GLuint *, GLuint64 *);
#define CALL_GetPerfCounterInfoINTEL(disp, parameters) \
    (* GET_GetPerfCounterInfoINTEL(disp)) parameters
static inline _glptr_GetPerfCounterInfoINTEL GET_GetPerfCounterInfoINTEL(struct _glapi_table *disp) {
   return (_glptr_GetPerfCounterInfoINTEL) (GET_by_offset(disp, _gloffset_GetPerfCounterInfoINTEL));
}

static inline void SET_GetPerfCounterInfoINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLuint, GLchar *, GLuint, GLchar *, GLuint *, GLuint *, GLuint *, GLuint *, GLuint64 *)) {
   SET_by_offset(disp, _gloffset_GetPerfCounterInfoINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfQueryDataINTEL)(GLuint, GLuint, GLsizei, GLvoid *, GLuint *);
#define CALL_GetPerfQueryDataINTEL(disp, parameters) \
    (* GET_GetPerfQueryDataINTEL(disp)) parameters
static inline _glptr_GetPerfQueryDataINTEL GET_GetPerfQueryDataINTEL(struct _glapi_table *disp) {
   return (_glptr_GetPerfQueryDataINTEL) (GET_by_offset(disp, _gloffset_GetPerfQueryDataINTEL));
}

static inline void SET_GetPerfQueryDataINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLsizei, GLvoid *, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetPerfQueryDataINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfQueryIdByNameINTEL)(GLchar *, GLuint *);
#define CALL_GetPerfQueryIdByNameINTEL(disp, parameters) \
    (* GET_GetPerfQueryIdByNameINTEL(disp)) parameters
static inline _glptr_GetPerfQueryIdByNameINTEL GET_GetPerfQueryIdByNameINTEL(struct _glapi_table *disp) {
   return (_glptr_GetPerfQueryIdByNameINTEL) (GET_by_offset(disp, _gloffset_GetPerfQueryIdByNameINTEL));
}

static inline void SET_GetPerfQueryIdByNameINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLchar *, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetPerfQueryIdByNameINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_GetPerfQueryInfoINTEL)(GLuint, GLuint, GLchar *, GLuint *, GLuint *, GLuint *, GLuint *);
#define CALL_GetPerfQueryInfoINTEL(disp, parameters) \
    (* GET_GetPerfQueryInfoINTEL(disp)) parameters
static inline _glptr_GetPerfQueryInfoINTEL GET_GetPerfQueryInfoINTEL(struct _glapi_table *disp) {
   return (_glptr_GetPerfQueryInfoINTEL) (GET_by_offset(disp, _gloffset_GetPerfQueryInfoINTEL));
}

static inline void SET_GetPerfQueryInfoINTEL(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, GLchar *, GLuint *, GLuint *, GLuint *, GLuint *)) {
   SET_by_offset(disp, _gloffset_GetPerfQueryInfoINTEL, fn);
}

typedef void (GLAPIENTRYP _glptr_PolygonOffsetClampEXT)(GLfloat, GLfloat, GLfloat);
#define CALL_PolygonOffsetClampEXT(disp, parameters) \
    (* GET_PolygonOffsetClampEXT(disp)) parameters
static inline _glptr_PolygonOffsetClampEXT GET_PolygonOffsetClampEXT(struct _glapi_table *disp) {
   return (_glptr_PolygonOffsetClampEXT) (GET_by_offset(disp, _gloffset_PolygonOffsetClampEXT));
}

static inline void SET_PolygonOffsetClampEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_PolygonOffsetClampEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_WindowRectanglesEXT)(GLenum, GLsizei, const GLint *);
#define CALL_WindowRectanglesEXT(disp, parameters) \
    (* GET_WindowRectanglesEXT(disp)) parameters
static inline _glptr_WindowRectanglesEXT GET_WindowRectanglesEXT(struct _glapi_table *disp) {
   return (_glptr_WindowRectanglesEXT) (GET_by_offset(disp, _gloffset_WindowRectanglesEXT));
}

static inline void SET_WindowRectanglesEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, const GLint *)) {
   SET_by_offset(disp, _gloffset_WindowRectanglesEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_BufferStorageMemEXT)(GLenum, GLsizeiptr, GLuint, GLuint64);
#define CALL_BufferStorageMemEXT(disp, parameters) \
    (* GET_BufferStorageMemEXT(disp)) parameters
static inline _glptr_BufferStorageMemEXT GET_BufferStorageMemEXT(struct _glapi_table *disp) {
   return (_glptr_BufferStorageMemEXT) (GET_by_offset(disp, _gloffset_BufferStorageMemEXT));
}

static inline void SET_BufferStorageMemEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizeiptr, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_BufferStorageMemEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_CreateMemoryObjectsEXT)(GLsizei, GLuint *);
#define CALL_CreateMemoryObjectsEXT(disp, parameters) \
    (* GET_CreateMemoryObjectsEXT(disp)) parameters
static inline _glptr_CreateMemoryObjectsEXT GET_CreateMemoryObjectsEXT(struct _glapi_table *disp) {
   return (_glptr_CreateMemoryObjectsEXT) (GET_by_offset(disp, _gloffset_CreateMemoryObjectsEXT));
}

static inline void SET_CreateMemoryObjectsEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_CreateMemoryObjectsEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteMemoryObjectsEXT)(GLsizei, const GLuint *);
#define CALL_DeleteMemoryObjectsEXT(disp, parameters) \
    (* GET_DeleteMemoryObjectsEXT(disp)) parameters
static inline _glptr_DeleteMemoryObjectsEXT GET_DeleteMemoryObjectsEXT(struct _glapi_table *disp) {
   return (_glptr_DeleteMemoryObjectsEXT) (GET_by_offset(disp, _gloffset_DeleteMemoryObjectsEXT));
}

static inline void SET_DeleteMemoryObjectsEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteMemoryObjectsEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_DeleteSemaphoresEXT)(GLsizei, const GLuint *);
#define CALL_DeleteSemaphoresEXT(disp, parameters) \
    (* GET_DeleteSemaphoresEXT(disp)) parameters
static inline _glptr_DeleteSemaphoresEXT GET_DeleteSemaphoresEXT(struct _glapi_table *disp) {
   return (_glptr_DeleteSemaphoresEXT) (GET_by_offset(disp, _gloffset_DeleteSemaphoresEXT));
}

static inline void SET_DeleteSemaphoresEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, const GLuint *)) {
   SET_by_offset(disp, _gloffset_DeleteSemaphoresEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_GenSemaphoresEXT)(GLsizei, GLuint *);
#define CALL_GenSemaphoresEXT(disp, parameters) \
    (* GET_GenSemaphoresEXT(disp)) parameters
static inline _glptr_GenSemaphoresEXT GET_GenSemaphoresEXT(struct _glapi_table *disp) {
   return (_glptr_GenSemaphoresEXT) (GET_by_offset(disp, _gloffset_GenSemaphoresEXT));
}

static inline void SET_GenSemaphoresEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLsizei, GLuint *)) {
   SET_by_offset(disp, _gloffset_GenSemaphoresEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMemoryObjectParameterivEXT)(GLuint, GLenum, GLint *);
#define CALL_GetMemoryObjectParameterivEXT(disp, parameters) \
    (* GET_GetMemoryObjectParameterivEXT(disp)) parameters
static inline _glptr_GetMemoryObjectParameterivEXT GET_GetMemoryObjectParameterivEXT(struct _glapi_table *disp) {
   return (_glptr_GetMemoryObjectParameterivEXT) (GET_by_offset(disp, _gloffset_GetMemoryObjectParameterivEXT));
}

static inline void SET_GetMemoryObjectParameterivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint *)) {
   SET_by_offset(disp, _gloffset_GetMemoryObjectParameterivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_GetSemaphoreParameterui64vEXT)(GLuint, GLenum, GLuint64 *);
#define CALL_GetSemaphoreParameterui64vEXT(disp, parameters) \
    (* GET_GetSemaphoreParameterui64vEXT(disp)) parameters
static inline _glptr_GetSemaphoreParameterui64vEXT GET_GetSemaphoreParameterui64vEXT(struct _glapi_table *disp) {
   return (_glptr_GetSemaphoreParameterui64vEXT) (GET_by_offset(disp, _gloffset_GetSemaphoreParameterui64vEXT));
}

static inline void SET_GetSemaphoreParameterui64vEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLuint64 *)) {
   SET_by_offset(disp, _gloffset_GetSemaphoreParameterui64vEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUnsignedBytei_vEXT)(GLenum, GLuint, GLubyte *);
#define CALL_GetUnsignedBytei_vEXT(disp, parameters) \
    (* GET_GetUnsignedBytei_vEXT(disp)) parameters
static inline _glptr_GetUnsignedBytei_vEXT GET_GetUnsignedBytei_vEXT(struct _glapi_table *disp) {
   return (_glptr_GetUnsignedBytei_vEXT) (GET_by_offset(disp, _gloffset_GetUnsignedBytei_vEXT));
}

static inline void SET_GetUnsignedBytei_vEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLubyte *)) {
   SET_by_offset(disp, _gloffset_GetUnsignedBytei_vEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_GetUnsignedBytevEXT)(GLenum, GLubyte *);
#define CALL_GetUnsignedBytevEXT(disp, parameters) \
    (* GET_GetUnsignedBytevEXT(disp)) parameters
static inline _glptr_GetUnsignedBytevEXT GET_GetUnsignedBytevEXT(struct _glapi_table *disp) {
   return (_glptr_GetUnsignedBytevEXT) (GET_by_offset(disp, _gloffset_GetUnsignedBytevEXT));
}

static inline void SET_GetUnsignedBytevEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLubyte *)) {
   SET_by_offset(disp, _gloffset_GetUnsignedBytevEXT, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsMemoryObjectEXT)(GLuint);
#define CALL_IsMemoryObjectEXT(disp, parameters) \
    (* GET_IsMemoryObjectEXT(disp)) parameters
static inline _glptr_IsMemoryObjectEXT GET_IsMemoryObjectEXT(struct _glapi_table *disp) {
   return (_glptr_IsMemoryObjectEXT) (GET_by_offset(disp, _gloffset_IsMemoryObjectEXT));
}

static inline void SET_IsMemoryObjectEXT(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsMemoryObjectEXT, fn);
}

typedef GLboolean (GLAPIENTRYP _glptr_IsSemaphoreEXT)(GLuint);
#define CALL_IsSemaphoreEXT(disp, parameters) \
    (* GET_IsSemaphoreEXT(disp)) parameters
static inline _glptr_IsSemaphoreEXT GET_IsSemaphoreEXT(struct _glapi_table *disp) {
   return (_glptr_IsSemaphoreEXT) (GET_by_offset(disp, _gloffset_IsSemaphoreEXT));
}

static inline void SET_IsSemaphoreEXT(struct _glapi_table *disp, GLboolean (GLAPIENTRYP fn)(GLuint)) {
   SET_by_offset(disp, _gloffset_IsSemaphoreEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_MemoryObjectParameterivEXT)(GLuint, GLenum, const GLint *);
#define CALL_MemoryObjectParameterivEXT(disp, parameters) \
    (* GET_MemoryObjectParameterivEXT(disp)) parameters
static inline _glptr_MemoryObjectParameterivEXT GET_MemoryObjectParameterivEXT(struct _glapi_table *disp) {
   return (_glptr_MemoryObjectParameterivEXT) (GET_by_offset(disp, _gloffset_MemoryObjectParameterivEXT));
}

static inline void SET_MemoryObjectParameterivEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLint *)) {
   SET_by_offset(disp, _gloffset_MemoryObjectParameterivEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_NamedBufferStorageMemEXT)(GLuint, GLsizeiptr, GLuint, GLuint64);
#define CALL_NamedBufferStorageMemEXT(disp, parameters) \
    (* GET_NamedBufferStorageMemEXT(disp)) parameters
static inline _glptr_NamedBufferStorageMemEXT GET_NamedBufferStorageMemEXT(struct _glapi_table *disp) {
   return (_glptr_NamedBufferStorageMemEXT) (GET_by_offset(disp, _gloffset_NamedBufferStorageMemEXT));
}

static inline void SET_NamedBufferStorageMemEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizeiptr, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_NamedBufferStorageMemEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_SemaphoreParameterui64vEXT)(GLuint, GLenum, const GLuint64 *);
#define CALL_SemaphoreParameterui64vEXT(disp, parameters) \
    (* GET_SemaphoreParameterui64vEXT(disp)) parameters
static inline _glptr_SemaphoreParameterui64vEXT GET_SemaphoreParameterui64vEXT(struct _glapi_table *disp) {
   return (_glptr_SemaphoreParameterui64vEXT) (GET_by_offset(disp, _gloffset_SemaphoreParameterui64vEXT));
}

static inline void SET_SemaphoreParameterui64vEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, const GLuint64 *)) {
   SET_by_offset(disp, _gloffset_SemaphoreParameterui64vEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_SignalSemaphoreEXT)(GLuint, GLuint, const GLuint *, GLuint, const GLuint *, const GLenum *);
#define CALL_SignalSemaphoreEXT(disp, parameters) \
    (* GET_SignalSemaphoreEXT(disp)) parameters
static inline _glptr_SignalSemaphoreEXT GET_SignalSemaphoreEXT(struct _glapi_table *disp) {
   return (_glptr_SignalSemaphoreEXT) (GET_by_offset(disp, _gloffset_SignalSemaphoreEXT));
}

static inline void SET_SignalSemaphoreEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, const GLuint *, GLuint, const GLuint *, const GLenum *)) {
   SET_by_offset(disp, _gloffset_SignalSemaphoreEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorageMem1DEXT)(GLenum, GLsizei, GLenum, GLsizei, GLuint, GLuint64);
#define CALL_TexStorageMem1DEXT(disp, parameters) \
    (* GET_TexStorageMem1DEXT(disp)) parameters
static inline _glptr_TexStorageMem1DEXT GET_TexStorageMem1DEXT(struct _glapi_table *disp) {
   return (_glptr_TexStorageMem1DEXT) (GET_by_offset(disp, _gloffset_TexStorageMem1DEXT));
}

static inline void SET_TexStorageMem1DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TexStorageMem1DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorageMem2DEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64);
#define CALL_TexStorageMem2DEXT(disp, parameters) \
    (* GET_TexStorageMem2DEXT(disp)) parameters
static inline _glptr_TexStorageMem2DEXT GET_TexStorageMem2DEXT(struct _glapi_table *disp) {
   return (_glptr_TexStorageMem2DEXT) (GET_by_offset(disp, _gloffset_TexStorageMem2DEXT));
}

static inline void SET_TexStorageMem2DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TexStorageMem2DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorageMem2DMultisampleEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64);
#define CALL_TexStorageMem2DMultisampleEXT(disp, parameters) \
    (* GET_TexStorageMem2DMultisampleEXT(disp)) parameters
static inline _glptr_TexStorageMem2DMultisampleEXT GET_TexStorageMem2DMultisampleEXT(struct _glapi_table *disp) {
   return (_glptr_TexStorageMem2DMultisampleEXT) (GET_by_offset(disp, _gloffset_TexStorageMem2DMultisampleEXT));
}

static inline void SET_TexStorageMem2DMultisampleEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TexStorageMem2DMultisampleEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorageMem3DEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64);
#define CALL_TexStorageMem3DEXT(disp, parameters) \
    (* GET_TexStorageMem3DEXT(disp)) parameters
static inline _glptr_TexStorageMem3DEXT GET_TexStorageMem3DEXT(struct _glapi_table *disp) {
   return (_glptr_TexStorageMem3DEXT) (GET_by_offset(disp, _gloffset_TexStorageMem3DEXT));
}

static inline void SET_TexStorageMem3DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TexStorageMem3DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TexStorageMem3DMultisampleEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64);
#define CALL_TexStorageMem3DMultisampleEXT(disp, parameters) \
    (* GET_TexStorageMem3DMultisampleEXT(disp)) parameters
static inline _glptr_TexStorageMem3DMultisampleEXT GET_TexStorageMem3DMultisampleEXT(struct _glapi_table *disp) {
   return (_glptr_TexStorageMem3DMultisampleEXT) (GET_by_offset(disp, _gloffset_TexStorageMem3DMultisampleEXT));
}

static inline void SET_TexStorageMem3DMultisampleEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TexStorageMem3DMultisampleEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorageMem1DEXT)(GLuint, GLsizei, GLenum, GLsizei, GLuint, GLuint64);
#define CALL_TextureStorageMem1DEXT(disp, parameters) \
    (* GET_TextureStorageMem1DEXT(disp)) parameters
static inline _glptr_TextureStorageMem1DEXT GET_TextureStorageMem1DEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorageMem1DEXT) (GET_by_offset(disp, _gloffset_TextureStorageMem1DEXT));
}

static inline void SET_TextureStorageMem1DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TextureStorageMem1DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorageMem2DEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64);
#define CALL_TextureStorageMem2DEXT(disp, parameters) \
    (* GET_TextureStorageMem2DEXT(disp)) parameters
static inline _glptr_TextureStorageMem2DEXT GET_TextureStorageMem2DEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorageMem2DEXT) (GET_by_offset(disp, _gloffset_TextureStorageMem2DEXT));
}

static inline void SET_TextureStorageMem2DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TextureStorageMem2DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorageMem2DMultisampleEXT)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64);
#define CALL_TextureStorageMem2DMultisampleEXT(disp, parameters) \
    (* GET_TextureStorageMem2DMultisampleEXT(disp)) parameters
static inline _glptr_TextureStorageMem2DMultisampleEXT GET_TextureStorageMem2DMultisampleEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorageMem2DMultisampleEXT) (GET_by_offset(disp, _gloffset_TextureStorageMem2DMultisampleEXT));
}

static inline void SET_TextureStorageMem2DMultisampleEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TextureStorageMem2DMultisampleEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorageMem3DEXT)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64);
#define CALL_TextureStorageMem3DEXT(disp, parameters) \
    (* GET_TextureStorageMem3DEXT(disp)) parameters
static inline _glptr_TextureStorageMem3DEXT GET_TextureStorageMem3DEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorageMem3DEXT) (GET_by_offset(disp, _gloffset_TextureStorageMem3DEXT));
}

static inline void SET_TextureStorageMem3DEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TextureStorageMem3DEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_TextureStorageMem3DMultisampleEXT)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64);
#define CALL_TextureStorageMem3DMultisampleEXT(disp, parameters) \
    (* GET_TextureStorageMem3DMultisampleEXT(disp)) parameters
static inline _glptr_TextureStorageMem3DMultisampleEXT GET_TextureStorageMem3DMultisampleEXT(struct _glapi_table *disp) {
   return (_glptr_TextureStorageMem3DMultisampleEXT) (GET_by_offset(disp, _gloffset_TextureStorageMem3DMultisampleEXT));
}

static inline void SET_TextureStorageMem3DMultisampleEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean, GLuint, GLuint64)) {
   SET_by_offset(disp, _gloffset_TextureStorageMem3DMultisampleEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_WaitSemaphoreEXT)(GLuint, GLuint, const GLuint *, GLuint, const GLuint *, const GLenum *);
#define CALL_WaitSemaphoreEXT(disp, parameters) \
    (* GET_WaitSemaphoreEXT(disp)) parameters
static inline _glptr_WaitSemaphoreEXT GET_WaitSemaphoreEXT(struct _glapi_table *disp) {
   return (_glptr_WaitSemaphoreEXT) (GET_by_offset(disp, _gloffset_WaitSemaphoreEXT));
}

static inline void SET_WaitSemaphoreEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint, const GLuint *, GLuint, const GLuint *, const GLenum *)) {
   SET_by_offset(disp, _gloffset_WaitSemaphoreEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ImportMemoryFdEXT)(GLuint, GLuint64, GLenum, GLint);
#define CALL_ImportMemoryFdEXT(disp, parameters) \
    (* GET_ImportMemoryFdEXT(disp)) parameters
static inline _glptr_ImportMemoryFdEXT GET_ImportMemoryFdEXT(struct _glapi_table *disp) {
   return (_glptr_ImportMemoryFdEXT) (GET_by_offset(disp, _gloffset_ImportMemoryFdEXT));
}

static inline void SET_ImportMemoryFdEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLuint64, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_ImportMemoryFdEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ImportSemaphoreFdEXT)(GLuint, GLenum, GLint);
#define CALL_ImportSemaphoreFdEXT(disp, parameters) \
    (* GET_ImportSemaphoreFdEXT(disp)) parameters
static inline _glptr_ImportSemaphoreFdEXT GET_ImportSemaphoreFdEXT(struct _glapi_table *disp) {
   return (_glptr_ImportSemaphoreFdEXT) (GET_by_offset(disp, _gloffset_ImportSemaphoreFdEXT));
}

static inline void SET_ImportSemaphoreFdEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLuint, GLenum, GLint)) {
   SET_by_offset(disp, _gloffset_ImportSemaphoreFdEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_StencilFuncSeparateATI)(GLenum, GLenum, GLint, GLuint);
#define CALL_StencilFuncSeparateATI(disp, parameters) \
    (* GET_StencilFuncSeparateATI(disp)) parameters
static inline _glptr_StencilFuncSeparateATI GET_StencilFuncSeparateATI(struct _glapi_table *disp) {
   return (_glptr_StencilFuncSeparateATI) (GET_by_offset(disp, _gloffset_StencilFuncSeparateATI));
}

static inline void SET_StencilFuncSeparateATI(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLint, GLuint)) {
   SET_by_offset(disp, _gloffset_StencilFuncSeparateATI, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramEnvParameters4fvEXT)(GLenum, GLuint, GLsizei, const GLfloat *);
#define CALL_ProgramEnvParameters4fvEXT(disp, parameters) \
    (* GET_ProgramEnvParameters4fvEXT(disp)) parameters
static inline _glptr_ProgramEnvParameters4fvEXT GET_ProgramEnvParameters4fvEXT(struct _glapi_table *disp) {
   return (_glptr_ProgramEnvParameters4fvEXT) (GET_by_offset(disp, _gloffset_ProgramEnvParameters4fvEXT));
}

static inline void SET_ProgramEnvParameters4fvEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramEnvParameters4fvEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_ProgramLocalParameters4fvEXT)(GLenum, GLuint, GLsizei, const GLfloat *);
#define CALL_ProgramLocalParameters4fvEXT(disp, parameters) \
    (* GET_ProgramLocalParameters4fvEXT(disp)) parameters
static inline _glptr_ProgramLocalParameters4fvEXT GET_ProgramLocalParameters4fvEXT(struct _glapi_table *disp) {
   return (_glptr_ProgramLocalParameters4fvEXT) (GET_by_offset(disp, _gloffset_ProgramLocalParameters4fvEXT));
}

static inline void SET_ProgramLocalParameters4fvEXT(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLuint, GLsizei, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ProgramLocalParameters4fvEXT, fn);
}

typedef void (GLAPIENTRYP _glptr_EGLImageTargetRenderbufferStorageOES)(GLenum, GLvoid *);
#define CALL_EGLImageTargetRenderbufferStorageOES(disp, parameters) \
    (* GET_EGLImageTargetRenderbufferStorageOES(disp)) parameters
static inline _glptr_EGLImageTargetRenderbufferStorageOES GET_EGLImageTargetRenderbufferStorageOES(struct _glapi_table *disp) {
   return (_glptr_EGLImageTargetRenderbufferStorageOES) (GET_by_offset(disp, _gloffset_EGLImageTargetRenderbufferStorageOES));
}

static inline void SET_EGLImageTargetRenderbufferStorageOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_EGLImageTargetRenderbufferStorageOES, fn);
}

typedef void (GLAPIENTRYP _glptr_EGLImageTargetTexture2DOES)(GLenum, GLvoid *);
#define CALL_EGLImageTargetTexture2DOES(disp, parameters) \
    (* GET_EGLImageTargetTexture2DOES(disp)) parameters
static inline _glptr_EGLImageTargetTexture2DOES GET_EGLImageTargetTexture2DOES(struct _glapi_table *disp) {
   return (_glptr_EGLImageTargetTexture2DOES) (GET_by_offset(disp, _gloffset_EGLImageTargetTexture2DOES));
}

static inline void SET_EGLImageTargetTexture2DOES(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLvoid *)) {
   SET_by_offset(disp, _gloffset_EGLImageTargetTexture2DOES, fn);
}

typedef void (GLAPIENTRYP _glptr_AlphaFuncx)(GLenum, GLclampx);
#define CALL_AlphaFuncx(disp, parameters) \
    (* GET_AlphaFuncx(disp)) parameters
static inline _glptr_AlphaFuncx GET_AlphaFuncx(struct _glapi_table *disp) {
   return (_glptr_AlphaFuncx) (GET_by_offset(disp, _gloffset_AlphaFuncx));
}

static inline void SET_AlphaFuncx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLclampx)) {
   SET_by_offset(disp, _gloffset_AlphaFuncx, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearColorx)(GLclampx, GLclampx, GLclampx, GLclampx);
#define CALL_ClearColorx(disp, parameters) \
    (* GET_ClearColorx(disp)) parameters
static inline _glptr_ClearColorx GET_ClearColorx(struct _glapi_table *disp) {
   return (_glptr_ClearColorx) (GET_by_offset(disp, _gloffset_ClearColorx));
}

static inline void SET_ClearColorx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampx, GLclampx, GLclampx, GLclampx)) {
   SET_by_offset(disp, _gloffset_ClearColorx, fn);
}

typedef void (GLAPIENTRYP _glptr_ClearDepthx)(GLclampx);
#define CALL_ClearDepthx(disp, parameters) \
    (* GET_ClearDepthx(disp)) parameters
static inline _glptr_ClearDepthx GET_ClearDepthx(struct _glapi_table *disp) {
   return (_glptr_ClearDepthx) (GET_by_offset(disp, _gloffset_ClearDepthx));
}

static inline void SET_ClearDepthx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampx)) {
   SET_by_offset(disp, _gloffset_ClearDepthx, fn);
}

typedef void (GLAPIENTRYP _glptr_Color4x)(GLfixed, GLfixed, GLfixed, GLfixed);
#define CALL_Color4x(disp, parameters) \
    (* GET_Color4x(disp)) parameters
static inline _glptr_Color4x GET_Color4x(struct _glapi_table *disp) {
   return (_glptr_Color4x) (GET_by_offset(disp, _gloffset_Color4x));
}

static inline void SET_Color4x(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Color4x, fn);
}

typedef void (GLAPIENTRYP _glptr_DepthRangex)(GLclampx, GLclampx);
#define CALL_DepthRangex(disp, parameters) \
    (* GET_DepthRangex(disp)) parameters
static inline _glptr_DepthRangex GET_DepthRangex(struct _glapi_table *disp) {
   return (_glptr_DepthRangex) (GET_by_offset(disp, _gloffset_DepthRangex));
}

static inline void SET_DepthRangex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampx, GLclampx)) {
   SET_by_offset(disp, _gloffset_DepthRangex, fn);
}

typedef void (GLAPIENTRYP _glptr_Fogx)(GLenum, GLfixed);
#define CALL_Fogx(disp, parameters) \
    (* GET_Fogx(disp)) parameters
static inline _glptr_Fogx GET_Fogx(struct _glapi_table *disp) {
   return (_glptr_Fogx) (GET_by_offset(disp, _gloffset_Fogx));
}

static inline void SET_Fogx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_Fogx, fn);
}

typedef void (GLAPIENTRYP _glptr_Fogxv)(GLenum, const GLfixed *);
#define CALL_Fogxv(disp, parameters) \
    (* GET_Fogxv(disp)) parameters
static inline _glptr_Fogxv GET_Fogxv(struct _glapi_table *disp) {
   return (_glptr_Fogxv) (GET_by_offset(disp, _gloffset_Fogxv));
}

static inline void SET_Fogxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_Fogxv, fn);
}

typedef void (GLAPIENTRYP _glptr_Frustumf)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Frustumf(disp, parameters) \
    (* GET_Frustumf(disp)) parameters
static inline _glptr_Frustumf GET_Frustumf(struct _glapi_table *disp) {
   return (_glptr_Frustumf) (GET_by_offset(disp, _gloffset_Frustumf));
}

static inline void SET_Frustumf(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Frustumf, fn);
}

typedef void (GLAPIENTRYP _glptr_Frustumx)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed);
#define CALL_Frustumx(disp, parameters) \
    (* GET_Frustumx(disp)) parameters
static inline _glptr_Frustumx GET_Frustumx(struct _glapi_table *disp) {
   return (_glptr_Frustumx) (GET_by_offset(disp, _gloffset_Frustumx));
}

static inline void SET_Frustumx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Frustumx, fn);
}

typedef void (GLAPIENTRYP _glptr_LightModelx)(GLenum, GLfixed);
#define CALL_LightModelx(disp, parameters) \
    (* GET_LightModelx(disp)) parameters
static inline _glptr_LightModelx GET_LightModelx(struct _glapi_table *disp) {
   return (_glptr_LightModelx) (GET_by_offset(disp, _gloffset_LightModelx));
}

static inline void SET_LightModelx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_LightModelx, fn);
}

typedef void (GLAPIENTRYP _glptr_LightModelxv)(GLenum, const GLfixed *);
#define CALL_LightModelxv(disp, parameters) \
    (* GET_LightModelxv(disp)) parameters
static inline _glptr_LightModelxv GET_LightModelxv(struct _glapi_table *disp) {
   return (_glptr_LightModelxv) (GET_by_offset(disp, _gloffset_LightModelxv));
}

static inline void SET_LightModelxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_LightModelxv, fn);
}

typedef void (GLAPIENTRYP _glptr_Lightx)(GLenum, GLenum, GLfixed);
#define CALL_Lightx(disp, parameters) \
    (* GET_Lightx(disp)) parameters
static inline _glptr_Lightx GET_Lightx(struct _glapi_table *disp) {
   return (_glptr_Lightx) (GET_by_offset(disp, _gloffset_Lightx));
}

static inline void SET_Lightx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_Lightx, fn);
}

typedef void (GLAPIENTRYP _glptr_Lightxv)(GLenum, GLenum, const GLfixed *);
#define CALL_Lightxv(disp, parameters) \
    (* GET_Lightxv(disp)) parameters
static inline _glptr_Lightxv GET_Lightxv(struct _glapi_table *disp) {
   return (_glptr_Lightxv) (GET_by_offset(disp, _gloffset_Lightxv));
}

static inline void SET_Lightxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_Lightxv, fn);
}

typedef void (GLAPIENTRYP _glptr_LineWidthx)(GLfixed);
#define CALL_LineWidthx(disp, parameters) \
    (* GET_LineWidthx(disp)) parameters
static inline _glptr_LineWidthx GET_LineWidthx(struct _glapi_table *disp) {
   return (_glptr_LineWidthx) (GET_by_offset(disp, _gloffset_LineWidthx));
}

static inline void SET_LineWidthx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed)) {
   SET_by_offset(disp, _gloffset_LineWidthx, fn);
}

typedef void (GLAPIENTRYP _glptr_LoadMatrixx)(const GLfixed *);
#define CALL_LoadMatrixx(disp, parameters) \
    (* GET_LoadMatrixx(disp)) parameters
static inline _glptr_LoadMatrixx GET_LoadMatrixx(struct _glapi_table *disp) {
   return (_glptr_LoadMatrixx) (GET_by_offset(disp, _gloffset_LoadMatrixx));
}

static inline void SET_LoadMatrixx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfixed *)) {
   SET_by_offset(disp, _gloffset_LoadMatrixx, fn);
}

typedef void (GLAPIENTRYP _glptr_Materialx)(GLenum, GLenum, GLfixed);
#define CALL_Materialx(disp, parameters) \
    (* GET_Materialx(disp)) parameters
static inline _glptr_Materialx GET_Materialx(struct _glapi_table *disp) {
   return (_glptr_Materialx) (GET_by_offset(disp, _gloffset_Materialx));
}

static inline void SET_Materialx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_Materialx, fn);
}

typedef void (GLAPIENTRYP _glptr_Materialxv)(GLenum, GLenum, const GLfixed *);
#define CALL_Materialxv(disp, parameters) \
    (* GET_Materialxv(disp)) parameters
static inline _glptr_Materialxv GET_Materialxv(struct _glapi_table *disp) {
   return (_glptr_Materialxv) (GET_by_offset(disp, _gloffset_Materialxv));
}

static inline void SET_Materialxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_Materialxv, fn);
}

typedef void (GLAPIENTRYP _glptr_MultMatrixx)(const GLfixed *);
#define CALL_MultMatrixx(disp, parameters) \
    (* GET_MultMatrixx(disp)) parameters
static inline _glptr_MultMatrixx GET_MultMatrixx(struct _glapi_table *disp) {
   return (_glptr_MultMatrixx) (GET_by_offset(disp, _gloffset_MultMatrixx));
}

static inline void SET_MultMatrixx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(const GLfixed *)) {
   SET_by_offset(disp, _gloffset_MultMatrixx, fn);
}

typedef void (GLAPIENTRYP _glptr_MultiTexCoord4x)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed);
#define CALL_MultiTexCoord4x(disp, parameters) \
    (* GET_MultiTexCoord4x(disp)) parameters
static inline _glptr_MultiTexCoord4x GET_MultiTexCoord4x(struct _glapi_table *disp) {
   return (_glptr_MultiTexCoord4x) (GET_by_offset(disp, _gloffset_MultiTexCoord4x));
}

static inline void SET_MultiTexCoord4x(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_MultiTexCoord4x, fn);
}

typedef void (GLAPIENTRYP _glptr_Normal3x)(GLfixed, GLfixed, GLfixed);
#define CALL_Normal3x(disp, parameters) \
    (* GET_Normal3x(disp)) parameters
static inline _glptr_Normal3x GET_Normal3x(struct _glapi_table *disp) {
   return (_glptr_Normal3x) (GET_by_offset(disp, _gloffset_Normal3x));
}

static inline void SET_Normal3x(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Normal3x, fn);
}

typedef void (GLAPIENTRYP _glptr_Orthof)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_Orthof(disp, parameters) \
    (* GET_Orthof(disp)) parameters
static inline _glptr_Orthof GET_Orthof(struct _glapi_table *disp) {
   return (_glptr_Orthof) (GET_by_offset(disp, _gloffset_Orthof));
}

static inline void SET_Orthof(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_Orthof, fn);
}

typedef void (GLAPIENTRYP _glptr_Orthox)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed);
#define CALL_Orthox(disp, parameters) \
    (* GET_Orthox(disp)) parameters
static inline _glptr_Orthox GET_Orthox(struct _glapi_table *disp) {
   return (_glptr_Orthox) (GET_by_offset(disp, _gloffset_Orthox));
}

static inline void SET_Orthox(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Orthox, fn);
}

typedef void (GLAPIENTRYP _glptr_PointSizex)(GLfixed);
#define CALL_PointSizex(disp, parameters) \
    (* GET_PointSizex(disp)) parameters
static inline _glptr_PointSizex GET_PointSizex(struct _glapi_table *disp) {
   return (_glptr_PointSizex) (GET_by_offset(disp, _gloffset_PointSizex));
}

static inline void SET_PointSizex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed)) {
   SET_by_offset(disp, _gloffset_PointSizex, fn);
}

typedef void (GLAPIENTRYP _glptr_PolygonOffsetx)(GLfixed, GLfixed);
#define CALL_PolygonOffsetx(disp, parameters) \
    (* GET_PolygonOffsetx(disp)) parameters
static inline _glptr_PolygonOffsetx GET_PolygonOffsetx(struct _glapi_table *disp) {
   return (_glptr_PolygonOffsetx) (GET_by_offset(disp, _gloffset_PolygonOffsetx));
}

static inline void SET_PolygonOffsetx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_PolygonOffsetx, fn);
}

typedef void (GLAPIENTRYP _glptr_Rotatex)(GLfixed, GLfixed, GLfixed, GLfixed);
#define CALL_Rotatex(disp, parameters) \
    (* GET_Rotatex(disp)) parameters
static inline _glptr_Rotatex GET_Rotatex(struct _glapi_table *disp) {
   return (_glptr_Rotatex) (GET_by_offset(disp, _gloffset_Rotatex));
}

static inline void SET_Rotatex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Rotatex, fn);
}

typedef void (GLAPIENTRYP _glptr_SampleCoveragex)(GLclampx, GLboolean);
#define CALL_SampleCoveragex(disp, parameters) \
    (* GET_SampleCoveragex(disp)) parameters
static inline _glptr_SampleCoveragex GET_SampleCoveragex(struct _glapi_table *disp) {
   return (_glptr_SampleCoveragex) (GET_by_offset(disp, _gloffset_SampleCoveragex));
}

static inline void SET_SampleCoveragex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLclampx, GLboolean)) {
   SET_by_offset(disp, _gloffset_SampleCoveragex, fn);
}

typedef void (GLAPIENTRYP _glptr_Scalex)(GLfixed, GLfixed, GLfixed);
#define CALL_Scalex(disp, parameters) \
    (* GET_Scalex(disp)) parameters
static inline _glptr_Scalex GET_Scalex(struct _glapi_table *disp) {
   return (_glptr_Scalex) (GET_by_offset(disp, _gloffset_Scalex));
}

static inline void SET_Scalex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Scalex, fn);
}

typedef void (GLAPIENTRYP _glptr_TexEnvx)(GLenum, GLenum, GLfixed);
#define CALL_TexEnvx(disp, parameters) \
    (* GET_TexEnvx(disp)) parameters
static inline _glptr_TexEnvx GET_TexEnvx(struct _glapi_table *disp) {
   return (_glptr_TexEnvx) (GET_by_offset(disp, _gloffset_TexEnvx));
}

static inline void SET_TexEnvx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_TexEnvx, fn);
}

typedef void (GLAPIENTRYP _glptr_TexEnvxv)(GLenum, GLenum, const GLfixed *);
#define CALL_TexEnvxv(disp, parameters) \
    (* GET_TexEnvxv(disp)) parameters
static inline _glptr_TexEnvxv GET_TexEnvxv(struct _glapi_table *disp) {
   return (_glptr_TexEnvxv) (GET_by_offset(disp, _gloffset_TexEnvxv));
}

static inline void SET_TexEnvxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_TexEnvxv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameterx)(GLenum, GLenum, GLfixed);
#define CALL_TexParameterx(disp, parameters) \
    (* GET_TexParameterx(disp)) parameters
static inline _glptr_TexParameterx GET_TexParameterx(struct _glapi_table *disp) {
   return (_glptr_TexParameterx) (GET_by_offset(disp, _gloffset_TexParameterx));
}

static inline void SET_TexParameterx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_TexParameterx, fn);
}

typedef void (GLAPIENTRYP _glptr_Translatex)(GLfixed, GLfixed, GLfixed);
#define CALL_Translatex(disp, parameters) \
    (* GET_Translatex(disp)) parameters
static inline _glptr_Translatex GET_Translatex(struct _glapi_table *disp) {
   return (_glptr_Translatex) (GET_by_offset(disp, _gloffset_Translatex));
}

static inline void SET_Translatex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfixed, GLfixed, GLfixed)) {
   SET_by_offset(disp, _gloffset_Translatex, fn);
}

typedef void (GLAPIENTRYP _glptr_ClipPlanef)(GLenum, const GLfloat *);
#define CALL_ClipPlanef(disp, parameters) \
    (* GET_ClipPlanef(disp)) parameters
static inline _glptr_ClipPlanef GET_ClipPlanef(struct _glapi_table *disp) {
   return (_glptr_ClipPlanef) (GET_by_offset(disp, _gloffset_ClipPlanef));
}

static inline void SET_ClipPlanef(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfloat *)) {
   SET_by_offset(disp, _gloffset_ClipPlanef, fn);
}

typedef void (GLAPIENTRYP _glptr_ClipPlanex)(GLenum, const GLfixed *);
#define CALL_ClipPlanex(disp, parameters) \
    (* GET_ClipPlanex(disp)) parameters
static inline _glptr_ClipPlanex GET_ClipPlanex(struct _glapi_table *disp) {
   return (_glptr_ClipPlanex) (GET_by_offset(disp, _gloffset_ClipPlanex));
}

static inline void SET_ClipPlanex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_ClipPlanex, fn);
}

typedef void (GLAPIENTRYP _glptr_GetClipPlanef)(GLenum, GLfloat *);
#define CALL_GetClipPlanef(disp, parameters) \
    (* GET_GetClipPlanef(disp)) parameters
static inline _glptr_GetClipPlanef GET_GetClipPlanef(struct _glapi_table *disp) {
   return (_glptr_GetClipPlanef) (GET_by_offset(disp, _gloffset_GetClipPlanef));
}

static inline void SET_GetClipPlanef(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfloat *)) {
   SET_by_offset(disp, _gloffset_GetClipPlanef, fn);
}

typedef void (GLAPIENTRYP _glptr_GetClipPlanex)(GLenum, GLfixed *);
#define CALL_GetClipPlanex(disp, parameters) \
    (* GET_GetClipPlanex(disp)) parameters
static inline _glptr_GetClipPlanex GET_GetClipPlanex(struct _glapi_table *disp) {
   return (_glptr_GetClipPlanex) (GET_by_offset(disp, _gloffset_GetClipPlanex));
}

static inline void SET_GetClipPlanex(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetClipPlanex, fn);
}

typedef void (GLAPIENTRYP _glptr_GetFixedv)(GLenum, GLfixed *);
#define CALL_GetFixedv(disp, parameters) \
    (* GET_GetFixedv(disp)) parameters
static inline _glptr_GetFixedv GET_GetFixedv(struct _glapi_table *disp) {
   return (_glptr_GetFixedv) (GET_by_offset(disp, _gloffset_GetFixedv));
}

static inline void SET_GetFixedv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetFixedv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetLightxv)(GLenum, GLenum, GLfixed *);
#define CALL_GetLightxv(disp, parameters) \
    (* GET_GetLightxv(disp)) parameters
static inline _glptr_GetLightxv GET_GetLightxv(struct _glapi_table *disp) {
   return (_glptr_GetLightxv) (GET_by_offset(disp, _gloffset_GetLightxv));
}

static inline void SET_GetLightxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetLightxv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetMaterialxv)(GLenum, GLenum, GLfixed *);
#define CALL_GetMaterialxv(disp, parameters) \
    (* GET_GetMaterialxv(disp)) parameters
static inline _glptr_GetMaterialxv GET_GetMaterialxv(struct _glapi_table *disp) {
   return (_glptr_GetMaterialxv) (GET_by_offset(disp, _gloffset_GetMaterialxv));
}

static inline void SET_GetMaterialxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetMaterialxv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexEnvxv)(GLenum, GLenum, GLfixed *);
#define CALL_GetTexEnvxv(disp, parameters) \
    (* GET_GetTexEnvxv(disp)) parameters
static inline _glptr_GetTexEnvxv GET_GetTexEnvxv(struct _glapi_table *disp) {
   return (_glptr_GetTexEnvxv) (GET_by_offset(disp, _gloffset_GetTexEnvxv));
}

static inline void SET_GetTexEnvxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetTexEnvxv, fn);
}

typedef void (GLAPIENTRYP _glptr_GetTexParameterxv)(GLenum, GLenum, GLfixed *);
#define CALL_GetTexParameterxv(disp, parameters) \
    (* GET_GetTexParameterxv(disp)) parameters
static inline _glptr_GetTexParameterxv GET_GetTexParameterxv(struct _glapi_table *disp) {
   return (_glptr_GetTexParameterxv) (GET_by_offset(disp, _gloffset_GetTexParameterxv));
}

static inline void SET_GetTexParameterxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, GLfixed *)) {
   SET_by_offset(disp, _gloffset_GetTexParameterxv, fn);
}

typedef void (GLAPIENTRYP _glptr_PointParameterx)(GLenum, GLfixed);
#define CALL_PointParameterx(disp, parameters) \
    (* GET_PointParameterx(disp)) parameters
static inline _glptr_PointParameterx GET_PointParameterx(struct _glapi_table *disp) {
   return (_glptr_PointParameterx) (GET_by_offset(disp, _gloffset_PointParameterx));
}

static inline void SET_PointParameterx(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLfixed)) {
   SET_by_offset(disp, _gloffset_PointParameterx, fn);
}

typedef void (GLAPIENTRYP _glptr_PointParameterxv)(GLenum, const GLfixed *);
#define CALL_PointParameterxv(disp, parameters) \
    (* GET_PointParameterxv(disp)) parameters
static inline _glptr_PointParameterxv GET_PointParameterxv(struct _glapi_table *disp) {
   return (_glptr_PointParameterxv) (GET_by_offset(disp, _gloffset_PointParameterxv));
}

static inline void SET_PointParameterxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_PointParameterxv, fn);
}

typedef void (GLAPIENTRYP _glptr_TexParameterxv)(GLenum, GLenum, const GLfixed *);
#define CALL_TexParameterxv(disp, parameters) \
    (* GET_TexParameterxv(disp)) parameters
static inline _glptr_TexParameterxv GET_TexParameterxv(struct _glapi_table *disp) {
   return (_glptr_TexParameterxv) (GET_by_offset(disp, _gloffset_TexParameterxv));
}

static inline void SET_TexParameterxv(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLenum, GLenum, const GLfixed *)) {
   SET_by_offset(disp, _gloffset_TexParameterxv, fn);
}

typedef void (GLAPIENTRYP _glptr_BlendBarrier)(void);
#define CALL_BlendBarrier(disp, parameters) \
    (* GET_BlendBarrier(disp)) parameters
static inline _glptr_BlendBarrier GET_BlendBarrier(struct _glapi_table *disp) {
   return (_glptr_BlendBarrier) (GET_by_offset(disp, _gloffset_BlendBarrier));
}

static inline void SET_BlendBarrier(struct _glapi_table *disp, void (GLAPIENTRYP fn)(void)) {
   SET_by_offset(disp, _gloffset_BlendBarrier, fn);
}

typedef void (GLAPIENTRYP _glptr_PrimitiveBoundingBox)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define CALL_PrimitiveBoundingBox(disp, parameters) \
    (* GET_PrimitiveBoundingBox(disp)) parameters
static inline _glptr_PrimitiveBoundingBox GET_PrimitiveBoundingBox(struct _glapi_table *disp) {
   return (_glptr_PrimitiveBoundingBox) (GET_by_offset(disp, _gloffset_PrimitiveBoundingBox));
}

static inline void SET_PrimitiveBoundingBox(struct _glapi_table *disp, void (GLAPIENTRYP fn)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)) {
   SET_by_offset(disp, _gloffset_PrimitiveBoundingBox, fn);
}


#endif /* !defined( _DISPATCH_H_ ) */
