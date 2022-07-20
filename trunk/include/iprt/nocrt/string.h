/** @file
 * IPRT / No-CRT - string.h.
 */

/*
 * Copyright (C) 2006-2022 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 *
 * The contents of this file may alternatively be used under the terms
 * of the Common Development and Distribution License Version 1.0
 * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
 * VirtualBox OSE distribution, in which case the provisions of the
 * CDDL are applicable instead of those of the GPL.
 *
 * You may elect to license modified versions of this file under the
 * terms and conditions of either the GPL or the CDDL or both.
 */

#ifndef IPRT_INCLUDED_nocrt_string_h
#define IPRT_INCLUDED_nocrt_string_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

#include <iprt/types.h>

RT_C_DECLS_BEGIN

void *  RT_NOCRT(memchr)(const void *pv, int ch, size_t cb);
int     RT_NOCRT(memcmp)(const void *pv1, const void *pv2, size_t cb);
void *  RT_NOCRT(memcpy)(void *pvDst, const void *pvSrc, size_t cb);
void *  RT_NOCRT(mempcpy)(void *pvDst, const void *pvSrc, size_t cb);
void *  RT_NOCRT(memrchr)(const void *pv, int ch, size_t cb);
void *  RT_NOCRT(memmove)(void *pvDst, const void *pvSrc, size_t cb);
void *  RT_NOCRT(memset)(void *pvDst, int ch, size_t cb);

char *  RT_NOCRT(strcat)(char *pszDst, const char *pszSrc);
char *  RT_NOCRT(strncat)(char *pszDst, const char *pszSrc, size_t cch);
char *  RT_NOCRT(strchr)(const char *psz, int ch);
int     RT_NOCRT(strcmp)(const char *psz1, const char *psz2);
int     RT_NOCRT(strncmp)(const char *psz1, const char *psz2, size_t cch);
int     RT_NOCRT(stricmp)(const char *psz1, const char *psz2);
int     RT_NOCRT(strnicmp)(const char *psz1, const char *psz2, size_t cch);
char *  RT_NOCRT(strcpy)(char *pszDst, const char *pszSrc);
char *  RT_NOCRT(strncpy)(char *pszDst, const char *pszSrc, size_t cch);
char *  RT_NOCRT(strcat)(char *pszDst, const char *pszSrc);
char *  RT_NOCRT(strncat)(char *pszDst, const char *pszSrc, size_t cch);
size_t  RT_NOCRT(strlen)(const char *psz);
size_t  RT_NOCRT(strnlen)(const char *psz, size_t cch);
size_t  RT_NOCRT(strcspn)(const char *psz, const char *pszBreakChars);
char *  RT_NOCRT(strpbrk)(const char *psz, const char *pszBreakChars);
char *  RT_NOCRT(strstr)(const char *psz, const char *pszSub);

size_t  RT_NOCRT(wcslen)(const wchar_t *pwsz);
wchar_t *RT_NOCRT(wcscat)(wchar_t *pwszDst, const wchar_t *pwszSrc);
wchar_t *RT_NOCRT(wcschr)(const wchar_t *pwszDst, wchar_t wc);
wchar_t *RT_NOCRT(wcscpy)(wchar_t *pwszDst, const wchar_t *pwszSrc);
int     RT_NOCRT(_wcsicmp)(const wchar_t *pwsz1, const wchar_t *pwsz2);

#if !defined(RT_WITHOUT_NOCRT_WRAPPERS) && !defined(RT_WITHOUT_NOCRT_WRAPPER_ALIASES)
# define memchr   RT_NOCRT(memchr)
# define memcmp   RT_NOCRT(memcmp)
# define memcpy   RT_NOCRT(memcpy)
# define mempcpy  RT_NOCRT(mempcpy)
# define memrchr  RT_NOCRT(memrchr)
# define memmove  RT_NOCRT(memmove)
# define memset   RT_NOCRT(memset)

# define strcat   RT_NOCRT(strcat)
# define strncat  RT_NOCRT(strncat)
# define strchr   RT_NOCRT(strchr)
# define strcmp   RT_NOCRT(strcmp)
# define strncmp  RT_NOCRT(strncmp)
# define stricmp  RT_NOCRT(stricmp)
# define strnicmp RT_NOCRT(strnicmp)
# define strcpy   RT_NOCRT(strcpy)
# define strncpy  RT_NOCRT(strncpy)
# define strcat   RT_NOCRT(strcat)
# define strncat  RT_NOCRT(strncat)
# define strlen   RT_NOCRT(strlen)
# define strnlen  RT_NOCRT(strnlen)
# define strcspn  RT_NOCRT(strcspn)
# define strpbrk  RT_NOCRT(strpbrk)
# define strstr   RT_NOCRT(strstr)

# define wcslen   RT_NOCRT(wcslen)
# define wcscat   RT_NOCRT(wcscat)
# define wcschr   RT_NOCRT(wcschr)
# define wcscpy   RT_NOCRT(wcscpy)
# define _wcsicmp RT_NOCRT(_wcsicmp)
#endif

RT_C_DECLS_END

#endif /* !IPRT_INCLUDED_nocrt_string_h */
