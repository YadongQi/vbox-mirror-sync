; $Id$
;; @file
; BS3Kit - Bs3SelFar32ToFlat32NoClobber.
;

;
; Copyright (C) 2007-2023 Oracle and/or its affiliates.
;
; This file is part of VirtualBox base platform packages, as
; available from https://www.virtualbox.org.
;
; This program is free software; you can redistribute it and/or
; modify it under the terms of the GNU General Public License
; as published by the Free Software Foundation, in version 3 of the
; License.
;
; This program is distributed in the hope that it will be useful, but
; WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
; General Public License for more details.
;
; You should have received a copy of the GNU General Public License
; along with this program; if not, see <https://www.gnu.org/licenses>.
;
; The contents of this file may alternatively be used under the terms
; of the Common Development and Distribution License Version 1.0
; (CDDL), a copy of it is provided in the "COPYING.CDDL" file included
; in the VirtualBox distribution, in which case the provisions of the
; CDDL are applicable instead of those of the GPL.
;
; You may elect to license modified versions of this file under the
; terms and conditions of either the GPL or the CDDL or both.
;
; SPDX-License-Identifier: GPL-3.0-only OR CDDL-1.0
;


;*********************************************************************************************************************************
;*      Header Files                                                                                                             *
;*********************************************************************************************************************************
%include "bs3kit-template-header.mac"


;*********************************************************************************************************************************
;*  External Symbols                                                                                                             *
;*********************************************************************************************************************************
BS3_EXTERN_CMN Bs3SelFar32ToFlat32
TMPL_BEGIN_TEXT


;;
; Wrapper around the Bs3SelFar32ToFlat32 C function that doesn't
; clobber any registers nor require 20h stack scratch area (64-bit).
;
; @uses     Only return registers (ax:dx, eax, eax)
; @remarks  No 20h scratch space required in 64-bit mode.
;
BS3_PROC_BEGIN_CMN Bs3SelFar32ToFlat32NoClobber, BS3_PBC_NEAR      ; Far stub generated by the makefile.
        push    xBP
        mov     xBP, xSP

%if TMPL_BITS == 16
        push    bx
        push    cx
        push    es

        push    word [xBP + xCB + cbCurRetAddr + 4] ; uSel
        push    word [xBP + xCB + cbCurRetAddr + 2] ; high off
        push    word [xBP + xCB + cbCurRetAddr]     ; low off
        call    Bs3SelFar32ToFlat32
        add     sp, 6

        pop     es
        pop     cx
        pop     bx
%else
        push    xDX
        push    xCX
 %if TMPL_BITS == 32
        push    es
        push    fs
        push    gs

        push    dword [xBP + xCB + cbCurRetAddr + 4] ; uSel
        push    dword [xBP + xCB + cbCurRetAddr]     ; off
        call    Bs3SelFar32ToFlat32
        add     esp, 8

        pop     gs
        pop     fs
        pop     es
 %else
        push    r8
        push    r9
        push    r10
        push    r11
        sub     rsp, 20h

        call    Bs3SelFar32ToFlat32     ; Just pass ECX and DX along as-is.

        add     rsp, 20h
        pop     r11
        pop     r10
        pop     r9
        pop     r8
 %endif
        pop     xCX
        pop     xDX
%endif

        pop     xBP
        BS3_HYBRID_RET
BS3_PROC_END_CMN   Bs3SelFar32ToFlat32NoClobber

