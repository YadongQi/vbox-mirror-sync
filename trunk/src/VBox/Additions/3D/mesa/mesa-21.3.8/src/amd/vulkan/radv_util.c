/*
 * Copyright © 2015 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "radv_debug.h"
#include "radv_private.h"
#include "vk_enum_to_str.h"

#include "util/u_math.h"

/** Log an error message.  */
void radv_printflike(1, 2) radv_loge(const char *format, ...)
{
   va_list va;

   va_start(va, format);
   radv_loge_v(format, va);
   va_end(va);
}

/** \see radv_loge() */
void
radv_loge_v(const char *format, va_list va)
{
   fprintf(stderr, "vk: error: ");
   vfprintf(stderr, format, va);
   fprintf(stderr, "\n");
}

/** Log an error message.  */
void radv_printflike(1, 2) radv_logi(const char *format, ...)
{
   va_list va;

   va_start(va, format);
   radv_logi_v(format, va);
   va_end(va);
}

/** \see radv_logi() */
void
radv_logi_v(const char *format, va_list va)
{
   fprintf(stderr, "radv: info: ");
   vfprintf(stderr, format, va);
   fprintf(stderr, "\n");
}
