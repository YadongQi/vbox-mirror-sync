/** @file
 * VM - The Virtual Machine, GVM/GVMCPU or VM/VMCPU depending on context.
 */

/*
 * Copyright (C) 2019-2022 Oracle Corporation
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

#ifndef VBOX_INCLUDED_vmm_vmcc_h
#define VBOX_INCLUDED_vmm_vmcc_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif


#include <VBox/vmm/vm.h>
#ifdef IN_RING0
# include <VBox/vmm/gvm.h>
#else
# include <VBox/vmm/uvm.h>
#endif

/** @typedef VMCC
 * Context specific VM derived structure.
 * This is plain VM in ring-3 and GVM (inherits from VM) in ring-0.  */
/** @typedef VMCPUCC
 * Context specific VMCPU derived structure.
 * This is plain VM in ring-3 and GVMCPU (inherits from VMCPU) in ring-0.  */
#ifdef IN_RING0
typedef GVM     VMCC;
typedef GVMCPU  VMCPUCC;
#else
typedef VM      VMCC;
typedef VMCPU   VMCPUCC;
#endif

/** @def VMCC_GET_CPU_0
 * Gets the context specfic pointer to virtual CPU \#0.
 * @param   a_pVM   The context specfic VM structure.
 */
#ifdef IN_RING0
# define VMCC_GET_CPU_0(a_pVM)          (&(a_pVM)->aCpus[0])
#else
# define VMCC_GET_CPU_0(a_pVM)          ((a_pVM)->CTX_SUFF(apCpus)[0])
#endif

/** @def VMCC_GET_CPU
 * Gets the context specfic pointer to a virtual CPU by index (ID).
 * @param   a_pVM   The context specfic VM structure.
 * @param   a_idCpu The CPU number to get (caller ensures validity).
 */
#ifdef IN_RING0
# define VMCC_GET_CPU(a_pVM, a_idCpu)   (&(a_pVM)->aCpus[(a_idCpu)])
#else
# define VMCC_GET_CPU(a_pVM, a_idCpu)   ((a_pVM)->CTX_SUFF(apCpus)[(a_idCpu)])
#endif

/** @def VMCC_FOR_EACH_VMCPU
 * For enumerating VCpus in ascending order, avoiding unnecessary apCpusR0
 * access in ring-0, caching the CPU count and not checking for CPU \#0.
 *
 * Defines local variables @c idCpu, @c pVCpu and @c cCpus.
 *
 * @param   a_pVM   The VM handle.
 *
 * @note    Close loop with VMCC_FOR_EACH_VMCPU_END.
 */
#define VMCC_FOR_EACH_VMCPU(a_pVM) \
    do { \
        VMCPUID         idCpu = 0; \
        VMCPUID const   cCpus = (a_pVM)->cCpus; \
        PVMCPUCC        pVCpu = VMCC_GET_CPU_0(a_pVM); \
        for (;;) \
        {

/** @def VMCC_FOR_EACH_VMCPU_END
 * Ends a VMCC_FOR_EACH_VMCPU loop.
 * @param   a_pVM   The VM handle.
 */
#define VMCC_FOR_EACH_VMCPU_END(a_pVM) \
            /* advance */ \
            if (++idCpu >= cCpus) \
                break; \
            pVCpu = VMCC_GET_CPU(pVM, idCpu); \
        } \
    } while (0)

/**
 * Execute the given statement for each virtual CPU in an environment with
 * @c pVCpu and @c idCpu variables.
 *
 * @param   a_pVM   The VM handle.
 * @param   a_Stmt  The statement to execute.
 */
#define VMCC_FOR_EACH_VMCPU_STMT(a_pVM, a_Stmt) VMCC_FOR_EACH_VMCPU(pVM) { a_Stmt; } VMCC_FOR_EACH_VMCPU_END(pVM)

/** @def VMCC_GET_VMR0_FOR_CALL(pVM)   */
#if   defined(IN_RING3)
# define VMCC_GET_VMR0_FOR_CALL(a_pVM)  ((a_pVM)->pVMR0ForCall)
#elif defined(IN_RING3)
# define VMCC_GET_VMR0_FOR_CALL(a_pVM)  ((a_pVM)->pVMR0)
#else
# define VMCC_GET_VMR0_FOR_CALL(a_pVM)  ((a_pVM)->ring3_only_macro)
#endif


#endif /* !VBOX_INCLUDED_vmm_vmcc_h */

