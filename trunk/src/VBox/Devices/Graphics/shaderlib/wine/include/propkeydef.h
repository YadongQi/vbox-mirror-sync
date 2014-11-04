/*
 * Copyright (C) 2009 Maarten Lankhorst
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/*
 * Oracle LGPL Disclaimer: For the avoidance of doubt, except that if any license choice
 * other than GPL or LGPL is available it will apply instead, Oracle elects to use only
 * the Lesser General Public License version 2.1 (LGPLv2) at this time for any software where
 * a choice of LGPL license versions is made available with the language indicating
 * that LGPLv2 or any later version may be used, or where a choice of which version
 * of the LGPL is applied is otherwise unspecified.
 */

#ifndef PID_FIRST_USABLE
#define PID_FIRST_USABLE 2
#endif

#ifndef REFPROPERTYKEY
#ifdef __cplusplus
#define REFPROPERTYKEY const PROPERTYKEY &
#else /*!__cplusplus*/
#define REFPROPERTYKEY const PROPERTYKEY * __MIDL_CONST
#endif
#endif

#undef DEFINE_PROPERTYKEY

#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
        EXTERN_C const PROPERTYKEY DECLSPEC_SELECTANY name DECLSPEC_HIDDEN = \
        { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
#else
#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
        const PROPERTYKEY DECLSPEC_SELECTANY name DECLSPEC_HIDDEN = \
        { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
#endif
#else
#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
    EXTERN_C const PROPERTYKEY name DECLSPEC_HIDDEN
#endif

#ifndef IsEqualPropertyKey
#ifdef __cplusplus
#define IsEqualPropertyKey(a,b) (((a).pid == (b).pid) && IsEqualIID((a).fmtid,(b).fmtid))
#else
#define IsEqualPropertyKey(a,b) (((a).pid == (b).pid) && IsEqualIID(&(a).fmtid,&(b).fmtid))
#endif
#endif

#ifndef _PROPERTYKEY_EQUALITY_OPERATORS_
#define _PROPERTYKEY_EQUALITY_OPERATORS_
#ifdef __cplusplus
extern "C++"
{

inline bool operator==(REFPROPERTYKEY guidOne, REFPROPERTYKEY guidOther)
{
    return IsEqualPropertyKey(guidOne, guidOther);
}
inline bool operator!=(REFPROPERTYKEY guidOne, REFPROPERTYKEY guidOther)
{
    return !(guidOne == guidOther);
}

}
#endif
#endif
