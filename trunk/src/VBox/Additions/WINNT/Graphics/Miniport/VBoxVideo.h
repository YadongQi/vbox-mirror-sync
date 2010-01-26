/** @file
 * VirtualBox Video miniport driver
 *
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
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 USA or visit http://www.sun.com if you need
 * additional information or have any questions.
 */

#ifndef VBOXVIDEO_H
#define VBOXVIDEO_H

#include <VBox/cdefs.h>
#include <VBox/types.h>
#include <iprt/assert.h>

#ifdef VBOX_WITH_HGSMI
//#include <iprt/thread.h>

#include <VBox/HGSMI/HGSMI.h>
#include <VBox/HGSMI/HGSMIChSetup.h>
#include "VBoxHGSMI.h"
#endif /* VBOX_WITH_HGSMI */

RT_C_DECLS_BEGIN
#ifndef VBOXWDDM
#include "dderror.h"
#include "devioctl.h"
#include "miniport.h"
#include "ntddvdeo.h"
#include "video.h"
#else
#   define VBOX_WITH_WORKAROUND_MISSING_PACK
#   if (_MSC_VER >= 1400) && !defined(VBOX_WITH_PATCHED_DDK)
#       define _InterlockedExchange           _InterlockedExchange_StupidDDKVsCompilerCrap
#       define _InterlockedExchangeAdd        _InterlockedExchangeAdd_StupidDDKVsCompilerCrap
#       define _InterlockedCompareExchange    _InterlockedCompareExchange_StupidDDKVsCompilerCrap
#       define _InterlockedAddLargeStatistic  _InterlockedAddLargeStatistic_StupidDDKVsCompilerCrap
#       define _interlockedbittestandset      _interlockedbittestandset_StupidDDKVsCompilerCrap
#       define _interlockedbittestandreset    _interlockedbittestandreset_StupidDDKVsCompilerCrap
#       define _interlockedbittestandset64    _interlockedbittestandset64_StupidDDKVsCompilerCrap
#       define _interlockedbittestandreset64  _interlockedbittestandreset64_StupidDDKVsCompilerCrap
#       pragma warning(disable : 4163)
#       ifdef VBOX_WITH_WORKAROUND_MISSING_PACK
#          pragma warning(disable : 4103)
#       endif
#       include <ntddk.h>
#       pragma warning(default : 4163)
#       ifdef VBOX_WITH_WORKAROUND_MISSING_PACK
#         pragma pack()
#         pragma warning(default : 4103)
#       endif
#       undef  _InterlockedExchange
#       undef  _InterlockedExchangeAdd
#       undef  _InterlockedCompareExchange
#       undef  _InterlockedAddLargeStatistic
#       undef  _interlockedbittestandset
#       undef  _interlockedbittestandreset
#       undef  _interlockedbittestandset64
#       undef  _interlockedbittestandreset64
#   else
#       include <ntddk.h>
#   endif
#include "dispmprt.h"
#include "ntddvdeo.h"
#include "dderror.h"
#endif
RT_C_DECLS_END

#define VBE_DISPI_IOPORT_INDEX          0x01CE
#define VBE_DISPI_IOPORT_DATA           0x01CF
#define VBE_DISPI_INDEX_ID              0x0
#define VBE_DISPI_INDEX_XRES            0x1
#define VBE_DISPI_INDEX_YRES            0x2
#define VBE_DISPI_INDEX_BPP             0x3
#define VBE_DISPI_INDEX_ENABLE          0x4
#define VBE_DISPI_INDEX_VIRT_WIDTH      0x6
#define VBE_DISPI_INDEX_VIRT_HEIGHT     0x7
#define VBE_DISPI_INDEX_VBOX_VIDEO      0xa

#define VBE_DISPI_ID2                   0xB0C2
/* The VBOX interface id. Indicates support for VBE_DISPI_INDEX_VBOX_VIDEO. */
#define VBE_DISPI_ID_VBOX_VIDEO         0xBE00
#ifdef VBOX_WITH_HGSMI
#define VBE_DISPI_ID_HGSMI              0xBE01
#endif /* VBOX_WITH_HGSMI */
#define VBE_DISPI_DISABLED              0x00
#define VBE_DISPI_ENABLED               0x01
#define VBE_DISPI_LFB_ENABLED           0x40
#define VBE_DISPI_LFB_PHYSICAL_ADDRESS  0xE0000000
#define VBE_DISPI_TOTAL_VIDEO_MEMORY_MB 4
#define VBE_DISPI_TOTAL_VIDEO_MEMORY_KB	        (VBE_DISPI_TOTAL_VIDEO_MEMORY_MB * 1024)
#define VBE_DISPI_TOTAL_VIDEO_MEMORY_BYTES      (VBE_DISPI_TOTAL_VIDEO_MEMORY_KB * 1024)

#ifdef VBOX_WITH_HGSMI
#define VGA_PORT_HGSMI_HOST  0x3b0
#define VGA_PORT_HGSMI_GUEST 0x3d0
#endif /* VBOX_WITH_HGSMI */

/* common API types */
#ifndef VBOXWDDM
typedef PSPIN_LOCK VBOXVCMNSPIN_LOCK, *PVBOXVCMNSPIN_LOCK;
typedef UCHAR VBOXVCMNIRQL, *PVBOXVCMNIRQL;

typedef PEVENT VBOXVCMNEVENT, *PVBOXVCMNEVENT;
#else
typedef KSPIN_LOCK VBOXVCMNSPIN_LOCK, *PVBOXVCMNSPIN_LOCK;
typedef KIRQL VBOXVCMNIRQL, *PVBOXVCMNIRQL;

typedef KEVENT VBOXVCMNEVENT, *PVBOXVCMNEVENT;
#endif

typedef struct _DEVICE_EXTENSION
{
   struct _DEVICE_EXTENSION *pNext;            /* Next extension in the DualView extension list.
                                                * The primary extension is the first one.
                                                */

   struct _DEVICE_EXTENSION *pPrimary;         /* Pointer to the primary device extension. */

   ULONG iDevice;                              /* Device index: 0 for primary, otherwise a secondary device. */


   ULONG CurrentMode;                          /* Saved information about video modes */
   ULONG CurrentModeWidth;
   ULONG CurrentModeHeight;
   ULONG CurrentModeBPP;

   ULONG ulFrameBufferOffset;                  /* The framebuffer position in the VRAM. */
   ULONG ulFrameBufferSize;                    /* The size of the current framebuffer. */

   union {
       /* Information that is only relevant to the primary device or is the same for all devices. */
       struct {

           void *pvReqFlush;                   /* Pointer to preallocated generic request structure for
                                                * VMMDevReq_VideoAccelFlush. Allocated when VBVA status
                                                * is changed. Deallocated on HwReset.
                                                */


           ULONG ulVbvaEnabled;                /* Indicates that VBVA mode is enabled. */

           BOOLEAN bVBoxVideoSupported;        /* TRUE if VBoxVideo extensions, including DualView, are supported by the host. */

           int cDisplays;                      /* Number of displays. */

           ULONG cbVRAM;                       /* The VRAM size. */

           ULONG cbMiniportHeap;               /* The size of reserved VRAM for miniport driver heap.
                                                * It is at offset:
                                                *   cbAdapterMemorySize - VBOX_VIDEO_ADAPTER_INFORMATION_SIZE - cbMiniportHeap
                                                */
           PVOID pvMiniportHeap;               /* The pointer to the miniport heap VRAM.
                                                * This is mapped by miniport separately.
                                                */
#ifdef VBOX_WITH_HGSMI
           volatile HGSMIHOSTFLAGS * pHostFlags; /* HGSMI host flags */
           volatile bool bHostCmdProcessing;
           VBOXVCMNSPIN_LOCK pSynchLock;
#endif

           PVOID pvAdapterInformation;         /* The pointer to the last 4K of VRAM.
                                                * This is mapped by miniport separately.
                                                */

           ULONG ulMaxFrameBufferSize;         /* The size of the VRAM allocated for the a single framebuffer. */

           BOOLEAN fMouseHidden;               /* Has the mouse cursor been hidden by the guest? */

#ifndef VBOX_WITH_HGSMI
           ULONG ulDisplayInformationSize;     /* The size of the Display information, which is at offset:
                                                * ulFrameBufferOffset + ulMaxFrameBufferSize.
                                                */
#endif /* !VBOX_WITH_HGSMI */

#ifdef VBOX_WITH_HGSMI
           BOOLEAN bHGSMI;                     /* Whether HGSMI is enabled. */

           HGSMIAREA areaHostHeap;             /* Host heap VRAM area. */

           HGSMICHANNELINFO channels;

           HGSMIHEAP hgsmiAdapterHeap;

           /* The IO Port Number for host commands. */
           RTIOPORT IOPortHost;

           /* The IO Port Number for guest commands. */
           RTIOPORT IOPortGuest;
# ifndef VBOXWDDM
           /* Video Port API dynamically picked up at runtime for binary backwards compatibility with older NT versions */
           VBOXVIDEOPORTPROCS VideoPortProcs;
# else
           /* Display Port handle and callbacks */
           DXGKRNL_INTERFACE DxgkInterface;
# endif
#endif /* VBOX_WITH_HGSMI */
       } primary;

       /* Secondary device information. */
       struct {
           BOOLEAN bEnabled;                   /* Device enabled flag */
       } secondary;
   } u;

#ifdef VBOX_WITH_HGSMI
   HGSMIAREA areaDisplay;                      /* Entire VRAM chunk for this display device. */
#endif /* VBOX_WITH_HGSMI */
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

#define DEV_MOUSE_HIDDEN(dev) ((dev)->pPrimary->u.primary.fMouseHidden)
#define DEV_SET_MOUSE_HIDDEN(dev)   \
do { \
    (dev)->pPrimary->u.primary.fMouseHidden = TRUE; \
} while (0)
#define DEV_SET_MOUSE_SHOWN(dev)   \
do { \
    (dev)->pPrimary->u.primary.fMouseHidden = FALSE; \
} while (0)

extern "C"
{
#ifndef VBOXWDDM
/* XPDM-WDDM common API */

typedef PEVENT VBOXVCMNEVENT, *PVBOXVCMNEVENT;

DECLINLINE(VOID) VBoxVideoCmnPortWriteUchar(IN PUCHAR Port, IN UCHAR Value)
{
    VideoPortWritePortUchar(Port,Value);
}

DECLINLINE(VOID) VBoxVideoCmnPortWriteUshort(IN PUSHORT Port, IN USHORT Value)
{
    VideoPortWritePortUshort(Port,Value);
}

DECLINLINE(VOID) VBoxVideoCmnPortWriteUlong(IN PULONG Port, IN ULONG Value)
{
    VideoPortWritePortUlong(Port,Value);
}

DECLINLINE(UCHAR) VBoxVideoCmnPortReadUchar(IN PUCHAR  Port)
{
    return VideoPortReadPortUchar(Port);
}

DECLINLINE(USHORT) VBoxVideoCmnPortReadUshort(IN PUSHORT Port)
{
    return VideoPortReadPortUshort(Port);
}

DECLINLINE(ULONG) VBoxVideoCmnPortReadUlong(IN PULONG Port)
{
    return VideoPortReadPortUlong(Port);
}

DECLINLINE(VOID) VBoxVideoCmnMemZero(PVOID pvMem, ULONG cbMem)
{
    VideoPortZeroMemory(pvMem, cbMem);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockAcquire(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock, OUT PVBOXVCMNIRQL OldIrql)
{
    pDeviceExtension->u.primary.VideoPortProcs.pfnAcquireSpinLock(pDeviceExtension, *SpinLock, OldIrql);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockAcquireAtDpcLevel(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    pDeviceExtension->u.primary.VideoPortProcs.pfnAcquireSpinLockAtDpcLevel(pDeviceExtension, *SpinLock);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockRelease(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock, IN VBOXVCMNIRQL NewIrql)
{
    pDeviceExtension->u.primary.VideoPortProcs.pfnReleaseSpinLock(pDeviceExtension, *SpinLock, NewIrql);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockReleaseFromDpcLevel(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    pDeviceExtension->u.primary.VideoPortProcs.pfnReleaseSpinLockFromDpcLevel(pDeviceExtension, *SpinLock);
}

DECLINLINE(VP_STATUS) VBoxVideoCmnSpinLockCreate(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    return pDeviceExtension->u.primary.VideoPortProcs.pfnCreateSpinLock(pDeviceExtension, SpinLock);
}

DECLINLINE(VP_STATUS) VBoxVideoCmnSpinLockDelete(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    return pDeviceExtension->u.primary.VideoPortProcs.pfnDeleteSpinLock(pDeviceExtension, *SpinLock);
}

DECLINLINE(LONG) VBoxVideoCmnEventSet(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNEVENT pEvent)
{
    return pDeviceExtension->u.primary.VideoPortProcs.pfnSetEvent(pDeviceExtension, *pEvent);
}

DECLINLINE(VP_STATUS) VBoxVideoCmnEventCreateNotification(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNEVENT pEvent, IN BOOLEAN bSignaled)
{
    ULONG fFlags = NOTIFICATION_EVENT;
    if(bSignaled)
        fFlags |= INITIAL_EVENT_SIGNALED;

    return pDeviceExtension->u.primary.VideoPortProcs.pfnCreateEvent(pDeviceExtension, fFlags, NULL, pEvent);
}

DECLINLINE(VP_STATUS) VBoxVideoCmnEventDelete(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNEVENT pEvent)
{
    return pDeviceExtension->u.primary.VideoPortProcs.pfnDeleteEvent(pDeviceExtension, *pEvent);
}

DECLINLINE(PVOID) VBoxVideoCmnMemAllocNonPaged(IN PDEVICE_EXTENSION pDeviceExtension, IN SIZE_T NumberOfBytes, IN ULONG Tag)
{
    return pDeviceExtension->u.primary.VideoPortProcs.pfnAllocatePool(pDeviceExtension, (VBOXVP_POOL_TYPE)VpNonPagedPool, NumberOfBytes, Tag);
}

DECLINLINE(VOID) VBoxVideoCmnMemFree(IN PDEVICE_EXTENSION pDeviceExtension, IN PVOID Ptr)
{
    pDeviceExtension->u.primary.VideoPortProcs.pfnFreePool(pDeviceExtension, Ptr);
}
/* */

RT_C_DECLS_BEGIN
ULONG DriverEntry(IN PVOID Context1, IN PVOID Context2);
RT_C_DECLS_END

VP_STATUS VBoxVideoFindAdapter(
   IN PVOID HwDeviceExtension,
   IN PVOID HwContext,
   IN PWSTR ArgumentString,
   IN OUT PVIDEO_PORT_CONFIG_INFO ConfigInfo,
   OUT PUCHAR Again);

BOOLEAN VBoxVideoInitialize(PVOID HwDeviceExtension);

BOOLEAN VBoxVideoStartIO(
   PVOID HwDeviceExtension,
   PVIDEO_REQUEST_PACKET RequestPacket);

#if defined(VBOX_WITH_HGSMI) && defined(VBOX_WITH_VIDEOHWACCEL)
BOOLEAN VBoxVideoInterrupt(PVOID  HwDeviceExtension);
#endif


BOOLEAN VBoxVideoResetHW(
   PVOID HwDeviceExtension,
   ULONG Columns,
   ULONG Rows);

VP_STATUS VBoxVideoGetPowerState(
   PVOID HwDeviceExtension,
   ULONG HwId,
   PVIDEO_POWER_MANAGEMENT VideoPowerControl);

VP_STATUS VBoxVideoSetPowerState(
   PVOID HwDeviceExtension,
   ULONG HwId,
   PVIDEO_POWER_MANAGEMENT VideoPowerControl);

VP_STATUS VBoxVideoGetChildDescriptor(
   PVOID HwDeviceExtension,
   PVIDEO_CHILD_ENUM_INFO ChildEnumInfo,
   PVIDEO_CHILD_TYPE VideoChildType,
   PUCHAR pChildDescriptor,
   PULONG pUId,
   PULONG pUnused);


void VBoxSetupVideoPortFunctions(PDEVICE_EXTENSION PrimaryExtension,
                                VBOXVIDEOPORTPROCS *pCallbacks,
                                PVIDEO_PORT_CONFIG_INFO pConfigInfo);

#else

/* XPDM-WDDM common API */
DECLINLINE(VOID) VBoxVideoCmnPortWriteUchar(IN PUCHAR Port, IN UCHAR Value)
{
    WRITE_PORT_UCHAR(Port,Value);
}

DECLINLINE(VOID) VBoxVideoCmnPortWriteUshort(IN PUSHORT Port, IN USHORT Value)
{
    WRITE_PORT_USHORT(Port,Value);
}

DECLINLINE(VOID) VBoxVideoCmnPortWriteUlong(IN PULONG Port, IN ULONG Value)
{
    WRITE_PORT_ULONG(Port,Value);
}

DECLINLINE(UCHAR) VBoxVideoCmnPortReadUchar(IN PUCHAR Port)
{
    return READ_PORT_UCHAR(Port);
}

DECLINLINE(USHORT) VBoxVideoCmnPortReadUshort(IN PUSHORT Port)
{
    return READ_PORT_USHORT(Port);
}

DECLINLINE(ULONG) VBoxVideoCmnPortReadUlong(IN PULONG Port)
{
    return READ_PORT_ULONG(Port);
}

DECLINLINE(VOID) VBoxVideoCmnMemZero(PVOID pvMem, ULONG cbMem)
{
    memset(pvMem, 0, cbMem);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockAcquire(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock, OUT PVBOXVCMNIRQL OldIrql)
{
    KeAcquireSpinLock(SpinLock, OldIrql);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockAcquireAtDpcLevel(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    KeAcquireSpinLockAtDpcLevel(SpinLock);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockRelease(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock, IN VBOXVCMNIRQL NewIrql)
{
    KeReleaseSpinLock(SpinLock, NewIrql);
}

DECLINLINE(VOID) VBoxVideoCmnSpinLockReleaseFromDpcLevel(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    KeReleaseSpinLockFromDpcLevel(SpinLock);
}

DECLINLINE(VP_STATUS) VBoxVideoCmnSpinLockCreate(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    KeInitializeSpinLock(SpinLock);
    return NO_ERROR;
}

DECLINLINE(VP_STATUS) VBoxVideoCmnSpinLockDelete(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNSPIN_LOCK SpinLock)
{
    return NO_ERROR;
}

DECLINLINE(LONG) VBoxVideoCmnEventSet(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNEVENT pEvent)
{
    return KeSetEvent(pEvent, 0, FALSE);
}

DECLINLINE(VP_STATUS) VBoxVideoCmnEventCreateNotification(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNEVENT pEvent, IN BOOLEAN bSignaled)
{
    KeInitializeEvent(pEvent, NotificationEvent, bSignaled);
    return NO_ERROR;
}

DECLINLINE(VP_STATUS) VBoxVideoCmnEventDelete(IN PDEVICE_EXTENSION pDeviceExtension, IN PVBOXVCMNEVENT pEvent)
{
    return NO_ERROR;
}

DECLINLINE(PVOID) VBoxVideoCmnMemAllocNonPaged(IN PDEVICE_EXTENSION pDeviceExtension, IN SIZE_T NumberOfBytes, IN ULONG Tag)
{
    return ExAllocatePoolWithTag(NonPagedPool, NumberOfBytes, Tag);
}

DECLINLINE(VOID) VBoxVideoCmnMemFree(IN PDEVICE_EXTENSION pDeviceExtension, IN PVOID Ptr)
{
    ExFreePool(Ptr);
}

/* */

RT_C_DECLS_BEGIN
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    );
RT_C_DECLS_END

NTSTATUS vboxVidPnCheckTopology(const D3DKMDT_HVIDPN hDesiredVidPn,
        D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology, const DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface,
        BOOLEAN *pbSupported);

NTSTATUS vboxVidPnCheckSourceModeInfo(const D3DKMDT_HVIDPN hDesiredVidPn,
        const D3DKMDT_VIDPN_SOURCE_MODE *pNewVidPnSourceModeInfo,
        BOOLEAN *pbSupported);

NTSTATUS vboxVidPnCheckSourceModeSet(const D3DKMDT_HVIDPN hDesiredVidPn,
        D3DKMDT_HVIDPNSOURCEMODESET hNewVidPnSourceModeSet, const DXGK_VIDPNSOURCEMODESET_INTERFACE *pVidPnSourceModeSetInterface,
        BOOLEAN *pbSupported);

NTSTATUS vboxVidPnCheckTargetModeInfo(const D3DKMDT_HVIDPN hDesiredVidPn,
        const D3DKMDT_VIDPN_TARGET_MODE *pNewVidPnTargetModeInfo,
        BOOLEAN *pbSupported);

NTSTATUS vboxVidPnCheckTargetModeSet(const D3DKMDT_HVIDPN hDesiredVidPn,
        D3DKMDT_HVIDPNTARGETMODESET hNewVidPnTargetModeSet, const DXGK_VIDPNTARGETMODESET_INTERFACE *pVidPnTargetModeSetInterface,
        BOOLEAN *pbSupported);

/* !!!NOTE: The callback is responsible for releasing the path */
typedef DECLCALLBACK(BOOLEAN) FNVBOXVIDPNENUMPATHS(PDEVICE_EXTENSION pDevExt, const D3DKMDT_HVIDPN hDesiredVidPn,
        D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology, const DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface,
        const D3DKMDT_VIDPN_PRESENT_PATH *pNewVidPnPresentPathInfo, PVOID pContext);
typedef FNVBOXVIDPNENUMPATHS *PFNVBOXVIDPNENUMPATHS;

DECLCALLBACK(BOOLEAN) vboxVidPnAdjustSourcesTargetsCallback(PDEVICE_EXTENSION pDevExt, const D3DKMDT_HVIDPN hDesiredVidPn,
        D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology, const DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface,
        const D3DKMDT_VIDPN_PRESENT_PATH *pNewVidPnPresentPathInfo, PVOID pContext);

NTSTATUS vboxVidPnEnumPaths(PDEVICE_EXTENSION pDevExt, const D3DKMDT_HVIDPN hDesiredVidPn,
        D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology, const DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface,
        PFNVBOXVIDPNENUMPATHS pfnCallback, PVOID pContext);
#endif

BOOLEAN FASTCALL VBoxVideoSetCurrentMode(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_MODE RequestedMode,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoResetDevice(
   PDEVICE_EXTENSION DeviceExtension,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoMapVideoMemory(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_MEMORY RequestedAddress,
   PVIDEO_MEMORY_INFORMATION MapInformation,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoUnmapVideoMemory(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_MEMORY VideoMemory,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoQueryNumAvailModes(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_NUM_MODES Modes,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoQueryAvailModes(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_MODE_INFORMATION ReturnedModes,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoQueryCurrentMode(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_MODE_INFORMATION VideoModeInfo,
   PSTATUS_BLOCK StatusBlock);

BOOLEAN FASTCALL VBoxVideoSetColorRegisters(
   PDEVICE_EXTENSION DeviceExtension,
   PVIDEO_CLUT ColorLookUpTable,
   PSTATUS_BLOCK StatusBlock);

int VBoxMapAdapterMemory (PDEVICE_EXTENSION PrimaryExtension,
                          void **ppv,
                          ULONG ulOffset,
                          ULONG ulSize);

void VBoxUnmapAdapterMemory (PDEVICE_EXTENSION PrimaryExtension,
                             void **ppv, ULONG ulSize);

void VBoxComputeFrameBufferSizes (PDEVICE_EXTENSION PrimaryExtension);

#ifdef VBOX_WITH_HGSMI

/*
 * Host and Guest port IO helpers.
 */
DECLINLINE(void) VBoxHGSMIHostWrite(PDEVICE_EXTENSION PrimaryExtension, ULONG data)
{
    VBoxVideoCmnPortWriteUlong((PULONG)PrimaryExtension->pPrimary->u.primary.IOPortHost, data);
}

DECLINLINE(ULONG) VBoxHGSMIHostRead(PDEVICE_EXTENSION PrimaryExtension)
{
    return VBoxVideoCmnPortReadUlong((PULONG)PrimaryExtension->pPrimary->u.primary.IOPortHost);
}

DECLINLINE(void) VBoxHGSMIGuestWrite(PDEVICE_EXTENSION PrimaryExtension, ULONG data)
{
    VBoxVideoCmnPortWriteUlong((PULONG)PrimaryExtension->pPrimary->u.primary.IOPortGuest, data);
}

DECLINLINE(ULONG) VBoxHGSMIGuestRead(PDEVICE_EXTENSION PrimaryExtension)
{
    return VBoxVideoCmnPortReadUlong((PULONG)PrimaryExtension->pPrimary->u.primary.IOPortGuest);
}

BOOLEAN VBoxHGSMIIsSupported (PDEVICE_EXTENSION PrimaryExtension);

VOID VBoxSetupDisplaysHGSMI (PDEVICE_EXTENSION PrimaryExtension,
#ifndef VBOXWDDM
                             PVIDEO_PORT_CONFIG_INFO pConfigInfo,
#endif
                             ULONG AdapterMemorySize);
BOOLEAN vboxUpdatePointerShape (PDEVICE_EXTENSION DeviceExtension,
                                PVIDEO_POINTER_ATTRIBUTES pointerAttr,
                                uint32_t cbLength);
DECLCALLBACK(void) hgsmiHostCmdComplete (HVBOXVIDEOHGSMI hHGSMI, struct _VBVAHOSTCMD * pCmd);
DECLCALLBACK(int) hgsmiHostCmdRequest (HVBOXVIDEOHGSMI hHGSMI, uint8_t u8Channel, struct _VBVAHOSTCMD ** ppCmd);


int vboxVBVAChannelDisplayEnable(PDEVICE_EXTENSION PrimaryExtension,
        int iDisplay, /* negative would mean this is a miniport handler */
        uint8_t u8Channel);

VOID VBoxVideoHGSMIDpc(
    IN PVOID  HwDeviceExtension,
    IN PVOID  Context
    );

void HGSMIClearIrq (PDEVICE_EXTENSION PrimaryExtension);

#endif /* VBOX_WITH_HGSMI */
} /* extern "C" */

#endif /* VBOXVIDEO_H */
