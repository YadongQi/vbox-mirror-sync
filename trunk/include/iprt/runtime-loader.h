/** @file
 * IPRT - runtime loader generation
 */

/*
 * Copyright (C) 2008 Sun Microsystems, Inc.
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

/* How to use this loader generator
 *
 * This loader generator can be used to generate stub code for loading a shared
 * library and its functions at runtime, or for generating a header file with
 * the declaration of the loader function and optionally declarations for the
 * functions loaded.  It should be included in a header file or a C source
 * file, after defining certain macros which it makes use of.
 *
 * To generate the C source code for function proxy stubs and the library
 * loader function, you should define the following macros in your source file
 * before including this header:
 *
 *  RT_RUNTIME_LOADER_LIB_NAME       - the file name of the library to load
 *  RT_RUNTIME_LOADER_FUNCTION       - the name of the loader function
 *  RT_RUNTIME_LOADER_INSERT_SYMBOLS - a macro containing the names of the
 *                                     functions to be loaded, defined in the
 *                                     following pattern:
 *
 * #define RT_RUNTIME_LOADER_INSERT_SYMBOLS \
 *  RT_PROXY_STUB(func_name, ret_type, (long_param_list), (short_param_list)) \
 *  RT_PROXY_STUB(func_name2, ret_type2, (long_param_list2), (short_param_list2)) \
 *  ...
 *
 * where long_param_list is a paramter list for declaring the function of the
 * form (type1 arg1, type2 arg2, ...) and short_param_list for calling it, of
 * the form (arg1, arg2, ...).
 *
 * To generate the header file, you should define RT_RUNTIME_LOADER_FUNCTION
 * and if you wish to generate declarations for the functions you should
 * additionally define RT_RUNTIME_LOADER_INSERT_SYMBOLS as above and
 * RT_RUNTIME_LOADER_GENERATE_DECLS (without a value) before including this
 * file.
 */
/** @todo this is far too complicated.  A script for generating the files would
 * probably be preferable. */

#include <iprt/asm.h>
#include <iprt/assert.h>
#include <iprt/cdefs.h>
#include <iprt/err.h>
#include <iprt/ldr.h>
#include <iprt/log.h>
#include <iprt/thread.h>
#include <iprt/types.h>

#ifdef RT_RUNTIME_LOADER_GENERATE_BODY_STUBS
/** The following are the symbols which we need from the library. */
# define RT_PROXY_STUB(function, rettype, signature, shortsig) \
 void (*function ## _fn)(void); \
 RTR3DECL(rettype) function signature \
 { return ( (rettype (*) signature) function ## _fn ) shortsig; }

RT_RUNTIME_LOADER_INSERT_SYMBOLS

# undef RT_PROXY_STUB

/* Now comes a table of functions to be loaded from the library */
typedef struct
{
    const char *name;
    void (**fn)(void);
} SHARED_FUNC;

# define RT_PROXY_STUB(s, dummy1, dummy2, dummy3 ) { #s , & s ## _fn } ,
static SHARED_FUNC SharedFuncs[] =
{
RT_RUNTIME_LOADER_INSERT_SYMBOLS
    { NULL, NULL }
};
# undef RT_PROXY_STUB

enum RT_RTLDR_LOAD_STATE
{
    UNLOADED = 0,
    LOADING,
    DONE
};

static uint32_t rtldrState = UNLOADED;
static uint32_t rtldrRC = VERR_WRONG_ORDER;

/** Load the shared library RT_RUNTIME_LOADER_LIB_NAME and resolve the symbols
 * pointed to by RT_RUNTIME_LOADER_INSERT_SYMBOLS.  May safely be called from
 * multiple threads and will not return until the library is loaded or has
 * failed to load. */
RTR3DECL(int) RT_RUNTIME_LOADER_FUNCTION(void)
{
    int rc;

    LogFlowFunc(("\n"));
    if (ASMAtomicCmpXchgU32(&rtldrState, LOADING, UNLOADED))
    {
        RTLDRMOD hLib;

        rc = RTLdrLoad(RT_RUNTIME_LOADER_LIB_NAME, &hLib);
        for (unsigned i = 0; RT_SUCCESS(rc) && SharedFuncs[i].name != NULL; ++i)
            rc = RTLdrGetSymbol(hLib, SharedFuncs[i].name, (void**)SharedFuncs[i].fn);
        rtldrRC = rc;
        rtldrState = DONE;
    }
    else
    {
        while(rtldrState == LOADING)
            RTThreadYield();
        rc = rtldrRC;
    }
    Assert(rtldrState == DONE);
    LogFlowFunc(("rc = %Rrc\n", rc));
    return rc;
}
#elif defined(RT_RUNTIME_LOADER_GENERATE_HEADER)
# ifdef RT_RUNTIME_LOADER_GENERATE_DECLS
/* Declarations of the functions that we need from
 * RT_RUNTIME_LOADER_LIB_NAME */
#  define RT_PROXY_STUB(function, rettype, signature, shortsig) \
    RTR3DECL(rettype) ( function ) signature ;

RT_RUNTIME_LOADER_INSERT_SYMBOLS

#  undef RT_PROXY_STUB
# endif /* RT_RUNTIME_LOADER_GENERATE_DECLS */

/**
 * Try to dynamically load the library.  This function should be called before
 * attempting to use any of the library functions.  It is safe to call this
 * function multiple times.
 *
 * @returns iprt status code
 */
RTR3DECL(int) RT_RUNTIME_LOADER_FUNCTION(void);
#else
# error One of RT_RUNTIME_LOADER_GENERATE_HEADER or \
RT_RUNTIME_LOADER_GENERATE_BODY_STUBS must be defined when including this file
#endif
