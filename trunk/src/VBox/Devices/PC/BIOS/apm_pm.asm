;;
;; Copyright (C) 2006-2012 Oracle Corporation
;;
;; This file is part of VirtualBox Open Source Edition (OSE), as
;; available from http://www.virtualbox.org. This file is free software;
;; you can redistribute it and/or modify it under the terms of the GNU
;; General Public License (GPL) as published by the Free Software
;; Foundation, in version 2 as it comes in the "COPYING" file of the
;; VirtualBox OSE distribution. VirtualBox OSE is distributed in the
;; hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
;;
;; --------------------------------------------------------------------
;;
;; Protected-mode APM implementation.
;;


;; 16-bit protected mode APM entry point

_TEXT		segment public 'CODE'

extern		_apm_function:near	; implemented in C code


public		apm_pm16_entry

.286


; APM function dispatch table
apm_disp:
		dw	offset apmf_disconnect	; 04h
		dw	offset apmf_idle	; 05h
		dw	offset apmf_busy	; 06h
		dw	offset apmf_set_state	; 07h
		dw	offset apmf_enable	; 08h
		dw	offset apmf_restore	; 09h
		dw	offset apmf_get_status	; 0Ah
		dw	offset apmf_get_event	; 0Bh
		dw	offset apmf_pwr_state	; 0Ch
		dw	offset apmf_dev_pm	; 0Dh
		dw	offset apmf_version	; 0Eh
		dw	offset apmf_engage	; 0Fh
		dw	offset apmf_get_caps	; 10h
apm_disp_end:

;
; APM worker routine. Function code in AL; it is assumed that AL >= 4.
; Caller must preserve BP.
;
apm_worker	proc	near

		sti			; TODO ?? necessary ??

		push	ax		; check if function is supported...
		xor	ah, ah
		sub	al, 4
		mov	bp, ax
		shl	bp, 1
		cmp	al, (apm_disp_end - apm_disp) / 2
		pop	ax
		mov	ah, 53h		; put back APM function
		jae	apmw_bad_func	; validate function range

		jmp	apm_disp[bp]	; and dispatch

apmf_disconnect:			; function 04h
		jmp	apmw_success

apmf_idle:				; function 05h
		sti
		hlt
		jmp	apmw_success

apmf_busy:				; function 06h
;		jmp	apmw_success

apmf_set_state:				; function 07h
;		jmp	apmw_success

apmf_enable:				; function 08h
		jmp	apmw_success

apmf_restore:				; function 09h
;		jmp	apmw_success

apmf_get_status:			; function 0Ah
		jmp	apmw_bad_func

apmf_get_event:				; function 0Bh
		mov	ah, 80h
		jmp	apmw_failure

apmf_pwr_state:				; function 0Ch

apmf_dev_pm:				; function 0Dh
		jmp	apmw_bad_func

apmf_version:				; function 0Eh
		mov	ax, 0102h
		jmp	apmw_success

apmf_engage:				; function 0Fh
		; TODO do something?
		jmp	apmw_success

apmf_get_caps:				; function 10h
		mov	bl, 0		; no batteries
		mov	cx, 0		; no special caps
		jmp	apmw_success

apmw_success:
		clc			; successful return
		ret

apmw_bad_func:
		mov	ah, 09h		; unrecognized device ID - generic

apmw_failure:
		stc			; error for unsupported functions
		ret

apm_worker	endp



apm_pm16_entry:
		stc
		retf			; return to 16-bit caller

apm_pm16_entry_from_32:

		push	ds		; save registers
		push	bp

		push	cs
		pop	bp
		add	bp, 8		; calculate data selector
		mov	ds, bp		; load data segment

		call	apm_worker	; call APM handler

		pop	bp
		pop	ds		; restore registers

.386
		retfd			; return to 32-bit code

_TEXT		ends


.386

BIOS32		segment	public 'CODE' use32

public		apm_pm32_entry

;; 32-bit protected mode APM entry point and thunk

;; According to the APM spec, only CS (32-bit) is defined. 16-bit code
;; selector and the data selector can be derived from it.

apm_pm32_entry:

;		cli
;		hlt

		push	ebp		; ebp is not used by APM

		push	cs		; return address for 16-bit code
		push	apm_pm32_back

		push	cs
		pop	ebp
		add	ebp, 8		; calculate 16-bit code selector
		push	ebp		; push 16-bit code selector

		xor	ebp, ebp	; manually pad 16-bit offset
		push	bp		; to a 32-bit value
		push	apm_pm16_entry_from_32

		mov	ah, 3		; mark as originating in 32-bit PM
		retf			; off to 16-bit code...

apm_pm32_back:				; return here from 16-bit code

		pop	ebp		; restore scratch register
		retf

BIOS32		ends

		end
