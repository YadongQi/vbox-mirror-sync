/** @file
 * IPRT - C++ Utilities (useful templates, defines and such).
 */

/*
 * Copyright (C) 2006-2011 Oracle Corporation
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

#ifndef ___iprt_cpputils_h
#define ___iprt_cpputils_h

/** @defgroup grp_rt_cpp        IPRT C++ APIs */

/** @defgroup grp_rt_cpp_util   C++ Utilities
 * @ingroup grp_rt_cpp
 * @{
 */

/**
 * A simple class used to prevent copying and assignment.
 *
 * Inherit from this class in order to prevent automatic generation
 * of the copy constructor and assignment operator in your class.
 *
 * @addtogroup grp_rt_cpp_util
 */
class RTCNonCopyable
{
protected:
    RTCNonCopyable() {}
    ~RTCNonCopyable() {}
private:
    RTCNonCopyable(RTCNonCopyable const &);
    RTCNonCopyable const &operator=(RTCNonCopyable const &);
};


/**
 * Shortcut to |const_cast<C &>()| that automatically derives the correct
 * type (class) for the const_cast template's argument from its own argument.
 *
 * Can be used to temporarily cancel the |const| modifier on the left-hand side
 * of assignment expressions, like this:
 * @code
 *      const Class That;
 *      ...
 *      unconst(That) = SomeValue;
 * @endcode
 *
 * @todo What to do about the prefix here?
 */
template <class C>
inline C &unconst(const C &that)
{
    return const_cast<C &>(that);
}


/**
 * Shortcut to |const_cast<C *>()| that automatically derives the correct
 * type (class) for the const_cast template's argument from its own argument.
 *
 * Can be used to temporarily cancel the |const| modifier on the left-hand side
 * of assignment expressions, like this:
 * @code
 *      const Class *pThat;
 *      ...
 *      unconst(pThat) = SomeValue;
 * @endcode
 *
 * @todo What to do about the prefix here?
 */
template <class C>
inline C *unconst(const C *that)
{
    return const_cast<C *>(that);
}

/** @} */

#endif

