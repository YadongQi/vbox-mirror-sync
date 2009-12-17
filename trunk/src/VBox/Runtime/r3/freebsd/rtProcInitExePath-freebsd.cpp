/* $Id$ */
/** @file
 * IPRT - rtProcInitName, FreeBSD.
 */

/*
 * Copyright (C) 2006-2008 Sun Microsystems, Inc.
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
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 USA or visit http://www.sun.com if you need
 * additional information or have any questions.
 */

/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#define LOG_GROUP RTLOGGROUP_PROCESS
#include <sys/param.h>
#include <sys/sysctl.h>
#include <unistd.h>
#include <errno.h>
#include <dlfcn.h>
#include <link.h>

#include <iprt/string.h>
#include <iprt/assert.h>
#include <iprt/err.h>
#include <iprt/path.h>
#include "internal/process.h"
#include "internal/path.h"


DECLHIDDEN(int) rtProcInitExePath(char *pszPath, size_t cchPath)
{
    int aiName[4];
    size_t cchExePath;

    aiName[0] = CTL_KERN;
    aiName[1] = KERN_PROC;
    aiName[2] = KERN_PROC_PATHNAME;
    aiName[3] = getpid();

    cchExePath = cchPath - 1;
    if(sysctl(aiName, RT_ELEMENTS(aiName), pszPath, &cchExePath, NULL, 0) == 0)
    {
        char *pszTmp = NULL;
        int rc = rtPathFromNative(&pszTmp, pszPath);
        AssertMsgRCReturn(rc, ("rc=%Rrc pszLink=\"%s\"\nhex: %.*Rhsx\n", rc, pszPath, cchExePath, pszPath), rc);

        size_t cch = strlen(pszTmp);
        AssertReturn(cch <= cchPath, VERR_BUFFER_OVERFLOW);

        memcpy(pszPath, pszTmp, cch + 1);
        RTStrFree(pszTmp);

        return VINF_SUCCESS;
    }

    int rc = RTErrConvertFromErrno(errno);
    AssertMsgFailed(("rc=%Rrc errno=%d cchLink=%d\n", rc, errno, cchExePath));
    return rc;
}

