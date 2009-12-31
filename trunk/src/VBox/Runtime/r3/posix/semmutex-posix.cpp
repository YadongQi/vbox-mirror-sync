/* $Id$ */
/** @file
 * IPRT - Mutex Semaphore, POSIX.
 */

/*
 * Copyright (C) 2006-2007 Sun Microsystems, Inc.
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
#include <iprt/semaphore.h>
#include "internal/iprt.h"

#include <iprt/alloc.h>
#include <iprt/asm.h>
#include <iprt/assert.h>
#include <iprt/err.h>
#include <iprt/lockvalidator.h>
#include <iprt/thread.h>
#include "internal/magics.h"
#include "internal/strict.h"

#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>


/*******************************************************************************
*   Structures and Typedefs                                                    *
*******************************************************************************/
/** Posix internal representation of a Mutex semaphore. */
struct RTSEMMUTEXINTERNAL
{
    /** pthread mutex. */
    pthread_mutex_t     Mutex;
    /** The owner of the mutex. */
    volatile pthread_t  Owner;
    /** Nesting count. */
    volatile uint32_t   cNesting;
    /** Magic value (RTSEMMUTEX_MAGIC). */
    uint32_t            u32Magic;
#ifdef RTSEMMUTEX_STRICT
    /** Lock validator record associated with this mutex. */
    RTLOCKVALRECEXCL    ValidatorRec;
#endif
};


/* Undefine debug mappings. */
#undef RTSemMutexRequest
#undef RTSemMutexRequestNoResume


RTDECL(int)  RTSemMutexCreate(PRTSEMMUTEX pMutexSem)
{
    int rc;

    /*
     * Allocate semaphore handle.
     */
    struct RTSEMMUTEXINTERNAL *pThis = (struct RTSEMMUTEXINTERNAL *)RTMemAlloc(sizeof(struct RTSEMMUTEXINTERNAL));
    if (pThis)
    {
        /*
         * Create the semaphore.
         */
        pthread_mutexattr_t MutexAttr;
        rc = pthread_mutexattr_init(&MutexAttr);
        if (!rc)
        {
            rc = pthread_mutex_init(&pThis->Mutex, &MutexAttr);
            if (!rc)
            {
                pthread_mutexattr_destroy(&MutexAttr);

                pThis->Owner    = (pthread_t)-1;
                pThis->cNesting = 0;
                pThis->u32Magic = RTSEMMUTEX_MAGIC;
#ifdef RTSEMMUTEX_STRICT
                RTLockValidatorRecExclInit(&pThis->ValidatorRec, NIL_RTLOCKVALIDATORCLASS, RTLOCKVALIDATOR_SUB_CLASS_NONE, "RTSemMutex", pThis);
#endif

                *pMutexSem = pThis;
                return VINF_SUCCESS;
            }
            pthread_mutexattr_destroy(&MutexAttr);
        }
        RTMemFree(pThis);
    }
    else
        rc = VERR_NO_MEMORY;

    return rc;
}


RTDECL(int)  RTSemMutexDestroy(RTSEMMUTEX MutexSem)
{
    /*
     * Validate input.
     */
    if (MutexSem == NIL_RTSEMMUTEX)
        return VINF_SUCCESS;
    struct RTSEMMUTEXINTERNAL *pThis = MutexSem;
    AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
    AssertReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, VERR_INVALID_HANDLE);

    /*
     * Try destroy it.
     */
    int rc = pthread_mutex_destroy(&pThis->Mutex);
    if (rc)
    {
        AssertMsgFailed(("Failed to destroy mutex sem %p, rc=%d.\n", MutexSem, rc));
        return RTErrConvertFromErrno(rc);
    }

    /*
     * Free the memory and be gone.
     */
    ASMAtomicWriteU32(&pThis->u32Magic, RTSEMMUTEX_MAGIC_DEAD);
    pThis->Owner    = (pthread_t)-1;
    pThis->cNesting = UINT32_MAX;
#ifdef RTSEMMUTEX_STRICT
    RTLockValidatorRecExclDelete(&pThis->ValidatorRec);
#endif
    RTMemTmpFree(pThis);

    return VINF_SUCCESS;
}


DECL_FORCE_INLINE(int) rtSemMutexRequest(RTSEMMUTEX MutexSem, unsigned cMillies, PCRTLOCKVALSRCPOS pSrcPos)
{
    /*
     * Validate input.
     */
    struct RTSEMMUTEXINTERNAL *pThis = MutexSem;
    AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
    AssertReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, VERR_INVALID_HANDLE);

#ifdef RTSEMMUTEX_STRICT
    RTTHREAD hThreadSelf = RTThreadSelfAutoAdopt();
    RTLockValidatorCheckOrder(&pThis->ValidatorRec, hThreadSelf, pSrcPos);
#endif

    /*
     * Check if nested request.
     */
    pthread_t Self = pthread_self();
    if (    pThis->Owner == Self
        &&  pThis->cNesting > 0)
    {
        ASMAtomicIncU32(&pThis->cNesting);
        return VINF_SUCCESS;
    }
#ifndef RTSEMMUTEX_STRICT
    RTTHREAD hThreadSelf = RTThreadSelf();
#endif

    /*
     * Lock it.
     */
    if (cMillies != 0)
    {
#ifdef RTSEMMUTEX_STRICT
        int rc9 = RTLockValidatorCheckBlocking(&pThis->ValidatorRec, hThreadSelf,
                                               RTTHREADSTATE_MUTEX, true, pSrcPos);
        if (RT_FAILURE(rc9))
            return rc9;
#endif
        RTThreadBlocking(hThreadSelf, RTTHREADSTATE_MUTEX);
    }

    if (cMillies == RT_INDEFINITE_WAIT)
    {
        /* take mutex */
        int rc = pthread_mutex_lock(&pThis->Mutex);
        RTThreadUnblocked(hThreadSelf, RTTHREADSTATE_MUTEX);
        if (rc)
        {
            AssertMsgFailed(("Failed to lock mutex sem %p, rc=%d.\n", MutexSem, rc)); NOREF(rc);
            return RTErrConvertFromErrno(rc);
        }
    }
    else
    {
#ifdef RT_OS_DARWIN
        AssertMsgFailed(("Not implemented on Darwin yet because of incomplete pthreads API."));
        return VERR_NOT_IMPLEMENTED;
#else /* !RT_OS_DARWIN */
        /*
         * Get current time and calc end of wait time.
         */
        struct timespec     ts = {0,0};
        clock_gettime(CLOCK_REALTIME, &ts);
        if (cMillies != 0)
        {
            ts.tv_nsec += (cMillies % 1000) * 1000000;
            ts.tv_sec  += cMillies / 1000;
            if (ts.tv_nsec >= 1000000000)
            {
                ts.tv_nsec -= 1000000000;
                ts.tv_sec++;
            }
        }

        /* take mutex */
        int rc = pthread_mutex_timedlock(&pThis->Mutex, &ts);
        RTThreadUnblocked(hThreadSelf, RTTHREADSTATE_MUTEX);
        if (rc)
        {
            AssertMsg(rc == ETIMEDOUT, ("Failed to lock mutex sem %p, rc=%d.\n", MutexSem, rc)); NOREF(rc);
            return RTErrConvertFromErrno(rc);
        }
#endif /* !RT_OS_DARWIN */
    }

    /*
     * Set the owner and nesting.
     */
    pThis->Owner = Self;
    ASMAtomicWriteU32(&pThis->cNesting, 1);
#ifdef RTSEMMUTEX_STRICT
    RTLockValidatorSetOwner(&pThis->ValidatorRec, hThreadSelf, pSrcPos);
#endif

    return VINF_SUCCESS;
}


RTDECL(int) RTSemMutexRequest(RTSEMMUTEX MutexSem, unsigned cMillies)
{
#ifndef RTSEMMUTEX_STRICT
    return rtSemMutexRequest(MutexSem, cMillies, NULL);
#else
    RTLOCKVALSRCPOS SrcPos = RTLOCKVALSRCPOS_INIT_NORMAL_API();
    return rtSemMutexRequest(MutexSem, cMillies, &SrcPos);
#endif
}


RTDECL(int) RTSemMutexRequestDebug(RTSEMMUTEX MutexSem, unsigned cMillies, RTHCUINTPTR uId, RT_SRC_POS_DECL)
{
    RTLOCKVALSRCPOS SrcPos = RTLOCKVALSRCPOS_INIT_DEBUG_API();
    return rtSemMutexRequest(MutexSem, cMillies, &SrcPos);
}


RTDECL(int) RTSemMutexRequestNoResume(RTSEMMUTEX MutexSem, unsigned cMillies)
{
    /* (EINTR isn't returned by the wait functions we're using.) */
#ifndef RTSEMMUTEX_STRICT
    return rtSemMutexRequest(MutexSem, cMillies, NULL);
#else
    RTLOCKVALSRCPOS SrcPos = RTLOCKVALSRCPOS_INIT_NORMAL_API();
    return rtSemMutexRequest(MutexSem, cMillies, &SrcPos);
#endif
}


RTDECL(int) RTSemMutexRequestNoResumeDebug(RTSEMMUTEX MutexSem, unsigned cMillies, RTHCUINTPTR uId, RT_SRC_POS_DECL)
{
    RTLOCKVALSRCPOS SrcPos = RTLOCKVALSRCPOS_INIT_DEBUG_API();
    return rtSemMutexRequest(MutexSem, cMillies, &SrcPos);
}


RTDECL(int)  RTSemMutexRelease(RTSEMMUTEX MutexSem)
{
    /*
     * Validate input.
     */
    struct RTSEMMUTEXINTERNAL *pThis = MutexSem;
    AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
    AssertReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, VERR_INVALID_HANDLE);

    /*
     * Check if nested.
     */
    pthread_t Self = pthread_self();
    if (RT_UNLIKELY(    pThis->Owner != Self
                    ||  pThis->cNesting == 0))
    {
        AssertMsgFailed(("Not owner of mutex %p!! Self=%08x Owner=%08x cNesting=%d\n",
                         pThis, Self, pThis->Owner, pThis->cNesting));
        return VERR_NOT_OWNER;
    }

    /*
     * If nested we'll just pop a nesting.
     */
    if (pThis->cNesting > 1)
    {
        ASMAtomicDecU32(&pThis->cNesting);
        return VINF_SUCCESS;
    }

    /*
     * Clear the state. (cNesting == 1)
     */
#ifdef RTSEMMUTEX_STRICT
    RTLockValidatorUnsetOwner(&pThis->ValidatorRec);
#endif
    pThis->Owner = (pthread_t)-1;
    ASMAtomicXchgU32(&pThis->cNesting, 0);

    /*
     * Unlock mutex semaphore.
     */
    int rc = pthread_mutex_unlock(&pThis->Mutex);
    if (RT_UNLIKELY(rc))
    {
        AssertMsgFailed(("Failed to unlock mutex sem %p, rc=%d.\n", MutexSem, rc)); NOREF(rc);
        return RTErrConvertFromErrno(rc);
    }

    return VINF_SUCCESS;
}

