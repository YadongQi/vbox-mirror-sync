/** @file
 * IPRT / No-CRT - Our own minimal ctype.h header (needed by ntdefs.h).
 */

/*
 * Copyright (C) 2006-2022 Oracle and/or its affiliates.
 *
 * This file is part of VirtualBox base platform packages, as
 * available from https://www.virtualbox.org.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, in version 3 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses>.
 *
 * The contents of this file may alternatively be used under the terms
 * of the Common Development and Distribution License Version 1.0
 * (CDDL), a copy of it is provided in the "COPYING.CDDL" file included
 * in the VirtualBox distribution, in which case the provisions of the
 * CDDL are applicable instead of those of the GPL.
 *
 * You may elect to license modified versions of this file under the
 * terms and conditions of either the GPL or the CDDL or both.
 *
 * SPDX-License-Identifier: GPL-3.0-only OR CDDL-1.0
 */

#ifndef IPRT_INCLUDED_nocrt_ctype_h
#define IPRT_INCLUDED_nocrt_ctype_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

#include <iprt/ctype.h>

#define isspace(a_ch)       RT_C_IS_SPACE(a_ch)
#define isblank(a_ch)       RT_C_IS_BLANK(a_ch)
#define isdigit(a_ch)       RT_C_IS_DIGIT(a_ch)
#define isxdigit(a_ch)      RT_C_IS_XDIGIT(a_ch)
#define isalpha(a_ch)       RT_C_IS_ALPHA(a_ch)
#define isalnum(a_ch)       RT_C_IS_ALNUM(a_ch)
#define iscntrl(a_ch)       RT_C_IS_CNTRL(a_ch)
#define isgraph(a_ch)       RT_C_IS_GRAPH(a_ch)
#define ispunct(a_ch)       RT_C_IS_PUNCT(a_ch)
#define isprint(a_ch)       RT_C_IS_PRINT(a_ch)
#define isupper(a_ch)       RT_C_IS_UPPER(a_ch)
#define islower(a_ch)       RT_C_IS_LOWER(a_ch)

#define tolower(a_ch)       RT_C_TO_LOWER(a_ch)
#define toupper(a_ch)       RT_C_TO_UPPER(a_ch)

#endif /* !IPRT_INCLUDED_nocrt_ctype_h */

