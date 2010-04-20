/* $Id$ */
/** @file
 * IPRT - Mutex Semaphores, Ring-0 Driver, Darwin.
 */

/*
 * Copyright (C) 2006-2010 Sun Microsystems, Inc.
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
#include "the-darwin-kernel.h"
#include "internal/iprt.h"
#include <iprt/semaphore.h>

#include <iprt/alloc.h>
#include <iprt/assert.h>
#include <iprt/asm.h>
#include <iprt/err.h>
#include <iprt/mp.h>
#include <iprt/thread.h>

#include "internal/magics.h"


/*******************************************************************************
*   Structures and Typedefs                                                    *
*******************************************************************************/
#if 0 /** @todo */
/**
 * Darwin mutex semaphore.
 */
typedef struct RTSEMMUTEXINTERNAL
{
    /** Magic value (RTSEMMUTEX_MAGIC). */
    uint32_t volatile   u32Magic;
    /** The mutex. */
    lck_mtx_t          *pMtx;
} RTSEMMUTEXINTERNAL, *PRTSEMMUTEXINTERNAL;

#endif




#if 0 /* need proper timeout lock function! */
RTDECL(int)  RTSemMutexCreate(PRTSEMMUTEX phFastMtx)
{
    RT_ASSERT_PREEMPTIBLE();
    AssertCompile(sizeof(RTSEMMUTEXINTERNAL) > sizeof(void *));
    PRTSEMMUTEXINTERNAL pThis = (PRTSEMMUTEXINTERNAL)RTMemAlloc(sizeof(*pThis));
    if (pThis)
    {
        pThis->u32Magic = RTSEMMUTEX_MAGIC;
        Assert(g_pDarwinLockGroup);
        pThis->pMtx = lck_mtx_alloc_init(g_pDarwinLockGroup, LCK_ATTR_NULL);
        if (pThis->pMtx)
        {
            *phFastMtx = pThis;
            return VINF_SUCCESS;
        }
        RTMemFree(pThis);
    }
    return VERR_NO_MEMORY;
}


RTDECL(int)  RTSemMutexDestroy(RTSEMMUTEX hMutexSem)
{
    /*
     * Validate input.
     */
    PRTSEMMUTEXINTERNAL pThis = (PRTSEMMUTEXINTERNAL)hMutexSem;
    if (!pThis)
        return VERR_INVALID_PARAMETER;
    AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
    AssertMsg(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("u32Magic=%RX32 pThis=%p\n", pThis->u32Magic, pThis), VERR_INVALID_HANDLE);
    RT_ASSERT_INTS_ON();

    /*
     * Invalidate it and signal the object just in case.
     */
    ASMAtomicIncU32(&pThis->u32Magic);

    Assert(g_pDarwinLockGroup);
    lck_mtx_free(pThis->pMtx, g_pDarwinLockGroup);
    pThis->pMtx = NULL;

    RTMemFree(pThis);
    return VINF_SUCCESS;
}


RTDECL(int)  RTSemMutexRequest(RTSEMMUTEX hMutexSem, RTMSINTERVAL cMillies)
{
    /*
     * Validate input.
     */
    PRTSEMMUTEXINTERNAL pThis = (PRTSEMMUTEXINTERNAL)hMutexSem;
    if (!pThis)
        return VERR_INVALID_PARAMETER;
    AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
    AssertMsg(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("u32Magic=%RX32 pThis=%p\n", pThis->u32Magic, pThis), VERR_INVALID_HANDLE);
    if (cMillies)
        RT_ASSERT_PREEMPTIBLE();

    /*
     * Get the mutex.
     */
    wait_result_t rc = lck_mtx_lock_deadlink
#if 1
#else
    NTSTATUS rcNt;
    if (cMillies == RT_INDEFINITE_WAIT)
        rcNt = KeWaitForSingleObject(&pThis->Mutex, Executive, KernelMode, TRUE, NULL);
    else
    {
        LARGE_INTEGER Timeout;
        Timeout.QuadPart = -(int64_t)cMillies * 10000;
        rcNt = KeWaitForSingleObject(&pThis->Mutex, Executive, KernelMode, TRUE, &Timeout);
    }
    switch (rcNt)
    {
        case STATUS_SUCCESS:
            if (pThis->u32Magic == RTSEMMUTEX_MAGIC)
                return VINF_SUCCESS;
            return VERR_SEM_DESTROYED;
        case STATUS_ALERTED:
            return VERR_INTERRUPTED; /** @todo VERR_INTERRUPTED isn't correct anylonger. please fix r0drv stuff! */
        case STATUS_USER_APC:
            return VERR_INTERRUPTED; /** @todo VERR_INTERRUPTED isn't correct anylonger. please fix r0drv stuff! */
        case STATUS_TIMEOUT:
            return VERR_TIMEOUT;
        default:
            AssertMsgFailed(("pThis->u32Magic=%RX32 pThis=%p: wait returned %lx!\n",
                             pThis->u32Magic, pThis, (long)rcNt));
            return VERR_INTERNAL_ERROR;
    }
#endif
    return VINF_SUCCESS;
}


RTDECL(int)  RTSemMutexRelease(RTSEMMUTEX hMutexSem)
{
    /*
     * Validate input.
     */
    PRTSEMMUTEXINTERNAL pThis = (PRTSEMMUTEXINTERNAL)hMutexSem;
    AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
    AssertMsg(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("u32Magic=%RX32 pThis=%p\n", pThis->u32Magic, pThis), VERR_INVALID_HANDLE);
    RT_ASSERT_PREEMPTIBLE();

    /*
     * Release the mutex.
     */
#ifdef RT_USE_FAST_MUTEX
    ExReleaseFastMutex(&pThis->Mutex);
#else
    KeReleaseMutex(&pThis->Mutex, FALSE);
#endif
    return VINF_SUCCESS;
}

#endif /* later */

