/* $Id$ */
/** @file
 * VBoxDTraceTLibCWrappers.h - IPRT wrappers/fake for lib C stuff.
 *
 * Contributed by: bird
 */

/*
 * Copyright (C) 2012-2015 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the Common
 * Development and Distribution License Version 1.0 (CDDL) only, as it
 * comes in the "COPYING.CDDL" file of the VirtualBox OSE distribution.
 * VirtualBox OSE is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY of any kind.
 *
 */

#ifndef ___VBoxDTraceLibCWrappers_h___
#define ___VBoxDTraceLibCWrappers_h___

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#ifdef RT_OS_WINDOWS
# include <process.h>
#else
# include <sys/types.h>
# include <limits.h>        /* Workaround for syslimit.h bug in gcc 4.8.3 on gentoo. */
# include <syslimits.h>     /* PATH_MAX */
# include <libgen.h>        /* basename */
# include <unistd.h>
# include <strings.h>       /* bzero & bcopy.*/
#endif

#include <iprt/mem.h>
#include <iprt/process.h>
#include <iprt/param.h>
#include <iprt/alloca.h>
#include <iprt/assert.h>
#include <iprt/mem.h>
#include <iprt/string.h>
#include <iprt/time.h>


#undef gethrtime
#define gethrtime()                RTTimeNanoTS()
#undef strcasecmp
#define strcasecmp(a_psz1, a_psz2) RTStrICmp(a_psz1, a_psz2)
#undef strncasecmp
#define strncasecmp(a_psz1, a_psz2, a_cch) RTStrNICmp(a_psz1, a_psz2, a_cch)
#undef strlcpy
#define strlcpy(a_pszDst, a_pszSrc, a_cbDst) ((void)RTStrCopy(a_pszDst, a_cbDst, a_pszSrc))

#undef assert
#define assert(expr)               Assert(expr)

#undef PATH_MAX
#define PATH_MAX                    RTPATH_MAX

#undef getpid
#define getpid                      RTProcSelf

#undef basename
#define basename(a_pszPath)         RTPathFilename(a_pszPath)

#undef malloc
#define malloc(a_cb)                RTMemAlloc(a_cb)
#undef calloc
#define calloc(a_cItems, a_cb)      RTMemAllocZ((size_t)(a_cb) * (a_cItems))
#undef realloc
#define realloc(a_pvOld, a_cbNew)   RTMemRealloc(a_pvOld, a_cbNew)
#undef free
#define free(a_pv)                  RTMemFree(a_pv)

/* Not using RTStrDup and RTStrNDup here because the allocation won't be freed
   by RTStrFree and thus may cause trouble when using the efence. */
#undef strdup
#define strdup(a_psz)               ((char *)RTMemDup(a_psz, strlen(a_psz) + 1))
#undef strndup
#define strndup(a_psz, a_cchMax)    ((char *)RTMemDupEx(a_psz, RTStrNLen(a_psz, a_cchMax), 1))

#endif

