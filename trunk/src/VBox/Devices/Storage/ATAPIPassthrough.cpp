/* $Id$ */
/** @file
 * VBox storage devices: ATAPI emulation (common code for DevATA and DevAHCI).
 */

/*
 * Copyright (C) 2012-2023 Oracle and/or its affiliates.
 *
 * This file is part of VirtualBox base platform packages, as
 * available from https://www.virtualbox.org.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, in version 3 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */
#define LOG_GROUP LOG_GROUP_DEV_IDE
#include <iprt/log.h>
#include <iprt/assert.h>
#include <iprt/mem.h>
#include <iprt/string.h>

#include <VBox/log.h>
#include <iprt/errcore.h>
#include <VBox/cdefs.h>
#include <VBox/scsi.h>
#include <VBox/scsiinline.h>

#include "ATAPIPassthrough.h"

/** The track was not detected yet. */
#define TRACK_FLAGS_UNDETECTED   RT_BIT_32(0)
/** The track is the lead in track of the medium. */
#define TRACK_FLAGS_LEAD_IN      RT_BIT_32(1)
/** The track is the lead out track of the medium. */
#define TRACK_FLAGS_LEAD_OUT     RT_BIT_32(2)

/** Don't clear already detected tracks on the medium. */
#define ATAPI_TRACK_LIST_REALLOCATE_FLAGS_DONT_CLEAR RT_BIT_32(0)

/**
 * Track main data form.
 */
typedef enum TRACKDATAFORM
{
    /** Invalid data form. */
    TRACKDATAFORM_INVALID = 0,
    /** 2352 bytes of data. */
    TRACKDATAFORM_CDDA,
    /** CDDA data is pause. */
    TRACKDATAFORM_CDDA_PAUSE,
    /** Mode 1 with 2048 bytes sector size. */
    TRACKDATAFORM_MODE1_2048,
    /** Mode 1 with 2352 bytes sector size. */
    TRACKDATAFORM_MODE1_2352,
    /** Mode 1 with 0 bytes sector size (generated by the drive). */
    TRACKDATAFORM_MODE1_0,
    /** XA Mode with 2336 bytes sector size. */
    TRACKDATAFORM_XA_2336,
    /** XA Mode with 2352 bytes sector size. */
    TRACKDATAFORM_XA_2352,
    /** XA Mode with 0 bytes sector size (generated by the drive). */
    TRACKDATAFORM_XA_0,
    /** Mode 2 with 2336 bytes sector size. */
    TRACKDATAFORM_MODE2_2336,
    /** Mode 2 with 2352 bytes sector size. */
    TRACKDATAFORM_MODE2_2352,
    /** Mode 2 with 0 bytes sector size (generated by the drive). */
    TRACKDATAFORM_MODE2_0
} TRACKDATAFORM;

/**
 * Subchannel data form.
 */
typedef enum SUBCHNDATAFORM
{
    /** Invalid subchannel data form. */
    SUBCHNDATAFORM_INVALID = 0,
    /** 0 bytes for the subchannel (generated by the drive). */
    SUBCHNDATAFORM_0,
    /** 96 bytes of data for the subchannel. */
    SUBCHNDATAFORM_96
} SUBCHNDATAFORM;

/**
 * Track entry.
 */
typedef struct TRACK
{
    /** Start LBA of the track. */
    int64_t        iLbaStart;
    /** Number of sectors in the track. */
    uint32_t       cSectors;
    /** Data form of main data. */
    TRACKDATAFORM  enmMainDataForm;
    /** Data form of sub channel. */
    SUBCHNDATAFORM enmSubChnDataForm;
    /** Flags for the track. */
    uint32_t       fFlags;
} TRACK, *PTRACK;

/**
 * Media track list.
 */
typedef struct TRACKLIST
{
    /** Number of detected tracks of the current medium. */
    unsigned    cTracksCurrent;
    /** Maximum number of tracks the list can contain. */
    unsigned    cTracksMax;
    /** Variable list of tracks. */
    PTRACK      paTracks;
} TRACKLIST, *PTRACKLIST;


/**
 * Reallocate the given track list to be able to hold the given number of tracks.
 *
 * @returns VBox status code.
 * @param   pTrackList    The track list to reallocate.
 * @param   cTracks       Number of tracks the list must be able to hold.
 * @param   fFlags        Flags for the reallocation.
 */
static int atapiTrackListReallocate(PTRACKLIST pTrackList, unsigned cTracks, uint32_t fFlags)
{
    int rc = VINF_SUCCESS;

    if (!(fFlags & ATAPI_TRACK_LIST_REALLOCATE_FLAGS_DONT_CLEAR))
        ATAPIPassthroughTrackListClear(pTrackList);

    if (pTrackList->cTracksMax < cTracks)
    {
        PTRACK paTracksNew = (PTRACK)RTMemRealloc(pTrackList->paTracks, cTracks * sizeof(TRACK));
        if (paTracksNew)
        {
            pTrackList->paTracks = paTracksNew;

            /* Mark new tracks as undetected. */
            for (unsigned i = pTrackList->cTracksMax; i < cTracks; i++)
                pTrackList->paTracks[i].fFlags |= TRACK_FLAGS_UNDETECTED;

            pTrackList->cTracksMax = cTracks;
        }
        else
            rc = VERR_NO_MEMORY;
    }

    if (RT_SUCCESS(rc))
        pTrackList->cTracksCurrent = cTracks;

    return rc;
}

/**
 * Initilizes the given track from the given CUE sheet entry.
 *
 * @param   pTrack             The track to initialize.
 * @param   pbCueSheetEntry    CUE sheet entry to use.
 */
static void atapiTrackListEntryCreateFromCueSheetEntry(PTRACK pTrack, const uint8_t *pbCueSheetEntry)
{
    TRACKDATAFORM enmTrackDataForm = TRACKDATAFORM_INVALID;
    SUBCHNDATAFORM enmSubChnDataForm = SUBCHNDATAFORM_INVALID;

    /* Determine size of main data based on the data form field. */
    switch (pbCueSheetEntry[3] & 0x3f)
    {
        case 0x00: /* CD-DA with data. */
            enmTrackDataForm = TRACKDATAFORM_CDDA;
            break;
        case 0x01: /* CD-DA without data (used for pauses between tracks). */
            enmTrackDataForm = TRACKDATAFORM_CDDA_PAUSE;
            break;
        case 0x10: /* CD-ROM mode 1 */
        case 0x12:
            enmTrackDataForm = TRACKDATAFORM_MODE1_2048;
            break;
        case 0x11:
        case 0x13:
            enmTrackDataForm = TRACKDATAFORM_MODE1_2352;
            break;
        case 0x14:
            enmTrackDataForm = TRACKDATAFORM_MODE1_0;
            break;
        case 0x20: /* CD-ROM XA, CD-I */
        case 0x22:
            enmTrackDataForm = TRACKDATAFORM_XA_2336;
            break;
        case 0x21:
        case 0x23:
            enmTrackDataForm = TRACKDATAFORM_XA_2352;
            break;
        case 0x24:
            enmTrackDataForm = TRACKDATAFORM_XA_0;
            break;
        case 0x31: /* CD-ROM Mode 2 */
        case 0x33:
            enmTrackDataForm = TRACKDATAFORM_MODE2_2352;
            break;
        case 0x30:
        case 0x32:
            enmTrackDataForm = TRACKDATAFORM_MODE2_2336;
            break;
        case 0x34:
            enmTrackDataForm = TRACKDATAFORM_MODE2_0;
            break;
        default: /* Reserved, invalid mode. Log and leave default sector size. */
            LogRel(("ATA: Invalid data form mode %d for current CUE sheet\n",
                    pbCueSheetEntry[3] & 0x3f));
    }

    /* Determine size of sub channel data based on data form field. */
    switch ((pbCueSheetEntry[3] & 0xc0) >> 6)
    {
        case 0x00: /* Sub channel all zeroes, autogenerated by the drive. */
            enmSubChnDataForm = SUBCHNDATAFORM_0;
            break;
        case 0x01:
        case 0x03:
            enmSubChnDataForm = SUBCHNDATAFORM_96;
            break;
        default:
            LogRel(("ATA: Invalid sub-channel data form mode %u for current CUE sheet\n",
                    pbCueSheetEntry[3] & 0xc0));
    }

    pTrack->enmMainDataForm = enmTrackDataForm;
    pTrack->enmSubChnDataForm = enmSubChnDataForm;
    pTrack->iLbaStart = scsiMSF2LBA(&pbCueSheetEntry[5]);
    if (pbCueSheetEntry[1] != 0xaa)
    {
        /* Calculate number of sectors from the next entry. */
        int64_t iLbaNext = scsiMSF2LBA(&pbCueSheetEntry[5+8]);
        pTrack->cSectors = iLbaNext - pTrack->iLbaStart;
    }
    else
    {
        pTrack->fFlags |= TRACK_FLAGS_LEAD_OUT;
        pTrack->cSectors = 0;
    }
    pTrack->fFlags &= ~TRACK_FLAGS_UNDETECTED;
}

/**
 * Update the track list from a SEND CUE SHEET request.
 *
 * @returns VBox status code.
 * @param   pTrackList  Track list to update.
 * @param   pbCDB       CDB of the SEND CUE SHEET request.
 * @param   pvBuf       The CUE sheet.
 * @param   cbBuf       The buffer size (max).
 */
static int atapiTrackListUpdateFromSendCueSheet(PTRACKLIST pTrackList, const uint8_t *pbCDB, const void *pvBuf, size_t cbBuf)
{
    int rc;
    unsigned cbCueSheet = scsiBE2H_U24(pbCDB + 6);
    unsigned cTracks = cbCueSheet / 8;

    AssertReturn(cbCueSheet % 8 == 0 && cTracks, VERR_INVALID_PARAMETER);

    rc = atapiTrackListReallocate(pTrackList, cTracks, 0);
    if (RT_SUCCESS(rc))
    {
        const uint8_t *pbCueSheet = (uint8_t *)pvBuf;
        PTRACK pTrack = pTrackList->paTracks;
        AssertLogRelReturn(cTracks <= cbBuf, VERR_BUFFER_OVERFLOW);

        for (unsigned i = 0; i < cTracks; i++)
        {
            atapiTrackListEntryCreateFromCueSheetEntry(pTrack, pbCueSheet);
            if (i == 0)
                pTrack->fFlags |= TRACK_FLAGS_LEAD_IN;
            pTrack++;
            pbCueSheet += 8;
        }
    }

    return rc;
}

static int atapiTrackListUpdateFromSendDvdStructure(PTRACKLIST pTrackList, const uint8_t *pbCDB, const void *pvBuf, size_t cbBuf)
{
    RT_NOREF(pTrackList, pbCDB, pvBuf, cbBuf);
    return VERR_NOT_IMPLEMENTED;
}

/**
 * Update track list from formatted TOC data.
 *
 * @returns VBox status code.
 * @param   pTrackList    The track list to update.
 * @param   iTrack        The first track the TOC has data for.
 * @param   fMSF          Flag whether block addresses are in MSF or LBA format.
 * @param   pbBuf         Buffer holding the formatted TOC.
 * @param   cbBuffer      Size of the buffer.
 */
static int atapiTrackListUpdateFromFormattedToc(PTRACKLIST pTrackList, uint8_t iTrack,
                                                bool fMSF, const uint8_t *pbBuf, uint32_t cbBuffer)
{
    RT_NOREF(iTrack, cbBuffer); /** @todo unused parameters */
    int rc;
    unsigned cbToc = scsiBE2H_U16(pbBuf);
    uint8_t iTrackFirst = pbBuf[2];
    unsigned cTracks;

    cbToc -= 2;
    pbBuf += 4;
    AssertReturn(cbToc % 8 == 0, VERR_INVALID_PARAMETER);

    cTracks = cbToc / 8 + iTrackFirst;

    rc = atapiTrackListReallocate(pTrackList, iTrackFirst + cTracks, ATAPI_TRACK_LIST_REALLOCATE_FLAGS_DONT_CLEAR);
    if (RT_SUCCESS(rc))
    {
        PTRACK pTrack = &pTrackList->paTracks[iTrackFirst];

        for (unsigned i = iTrackFirst; i < cTracks; i++)
        {
            if (pbBuf[1] & 0x4)
                pTrack->enmMainDataForm = TRACKDATAFORM_MODE1_2048;
            else
                pTrack->enmMainDataForm = TRACKDATAFORM_CDDA;

            pTrack->enmSubChnDataForm = SUBCHNDATAFORM_0;
            if (fMSF)
                pTrack->iLbaStart = scsiMSF2LBA(&pbBuf[4]);
            else
                pTrack->iLbaStart = scsiBE2H_U32(&pbBuf[4]);

            if (pbBuf[2] != 0xaa)
            {
                /* Calculate number of sectors from the next entry. */
                int64_t iLbaNext;

                if (fMSF)
                    iLbaNext = scsiMSF2LBA(&pbBuf[4+8]);
                else
                    iLbaNext = scsiBE2H_U32(&pbBuf[4+8]);

                pTrack->cSectors = iLbaNext - pTrack->iLbaStart;
            }
            else
                pTrack->cSectors = 0;

            pTrack->fFlags &= ~TRACK_FLAGS_UNDETECTED;
            pbBuf += 8;
            pTrack++;
        }
    }

    return rc;
}

static int atapiTrackListUpdateFromReadTocPmaAtip(PTRACKLIST pTrackList, const uint8_t *pbCDB, const void *pvBuf, size_t cbBuf)
{
    int rc;
    uint16_t cbBuffer = (uint16_t)RT_MIN(scsiBE2H_U16(&pbCDB[7]), cbBuf);
    bool fMSF = (pbCDB[1] & 0x2) != 0;
    uint8_t uFmt = pbCDB[2] & 0xf;
    uint8_t iTrack = pbCDB[6];

    switch (uFmt)
    {
        case 0x00:
            rc = atapiTrackListUpdateFromFormattedToc(pTrackList, iTrack, fMSF, (uint8_t *)pvBuf, cbBuffer);
            break;
        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
            rc = VERR_NOT_IMPLEMENTED;
            break;
        case 0x05:
            rc = VINF_SUCCESS; /* Does not give information about the tracklist. */
            break;
        default:
            rc = VERR_INVALID_PARAMETER;
    }

    return rc;
}

static int atapiTrackListUpdateFromReadTrackInformation(PTRACKLIST pTrackList, const uint8_t *pbCDB,
                                                        const void *pvBuf, size_t cbBuf)
{
    RT_NOREF(pTrackList, pbCDB, pvBuf, cbBuf);
    return VERR_NOT_IMPLEMENTED;
}

static int atapiTrackListUpdateFromReadDvdStructure(PTRACKLIST pTrackList, const uint8_t *pbCDB,
                                                    const void *pvBuf, size_t cbBuf)
{
    RT_NOREF(pTrackList, pbCDB, pvBuf, cbBuf);
    return VERR_NOT_IMPLEMENTED;
}

static int atapiTrackListUpdateFromReadDiscInformation(PTRACKLIST pTrackList, const uint8_t *pbCDB,
                                                       const void *pvBuf, size_t cbBuf)
{
    RT_NOREF(pTrackList, pbCDB, pvBuf, cbBuf);
    return VERR_NOT_IMPLEMENTED;
}

#ifdef LOG_ENABLED

/**
 * Converts the given track data form to a string.
 *
 * @returns Track data form as a string.
 * @param   enmTrackDataForm    The track main data form.
 */
static const char *atapiTrackListMainDataFormToString(TRACKDATAFORM enmTrackDataForm)
{
    switch (enmTrackDataForm)
    {
        case TRACKDATAFORM_CDDA:
            return "CD-DA";
        case TRACKDATAFORM_CDDA_PAUSE:
            return "CD-DA Pause";
        case TRACKDATAFORM_MODE1_2048:
            return "Mode 1 (2048 bytes)";
        case TRACKDATAFORM_MODE1_2352:
            return "Mode 1 (2352 bytes)";
        case TRACKDATAFORM_MODE1_0:
            return "Mode 1 (0 bytes)";
        case TRACKDATAFORM_XA_2336:
            return "XA (2336 bytes)";
        case TRACKDATAFORM_XA_2352:
            return "XA (2352 bytes)";
        case TRACKDATAFORM_XA_0:
            return "XA (0 bytes)";
        case TRACKDATAFORM_MODE2_2336:
            return "Mode 2 (2336 bytes)";
        case TRACKDATAFORM_MODE2_2352:
            return "Mode 2 (2352 bytes)";
        case TRACKDATAFORM_MODE2_0:
            return "Mode 2 (0 bytes)";
        case TRACKDATAFORM_INVALID:
        default:
            return "Invalid";
    }
}

/**
 * Converts the given subchannel data form to a string.
 *
 * @returns Subchannel data form as a string.
 * @param   enmSubChnDataForm    The subchannel main data form.
 */
static const char *atapiTrackListSubChnDataFormToString(SUBCHNDATAFORM enmSubChnDataForm)
{
    switch (enmSubChnDataForm)
    {
        case SUBCHNDATAFORM_0:
            return "0";
        case SUBCHNDATAFORM_96:
            return "96";
        case SUBCHNDATAFORM_INVALID:
        default:
            return "Invalid";
    }
}

/**
 * Dump the complete track list to the release log.
 *
 * @param   pTrackList   The track list to dump.
 */
static void atapiTrackListDump(PTRACKLIST pTrackList)
{
    LogRel(("Track List: cTracks=%u\n", pTrackList->cTracksCurrent));
    for (unsigned i = 0; i < pTrackList->cTracksCurrent; i++)
    {
        PTRACK pTrack = &pTrackList->paTracks[i];

        LogRel(("    Track %u: LBAStart=%lld cSectors=%u enmMainDataForm=%s enmSubChnDataForm=%s fFlags=[%s%s%s]\n",
                i, pTrack->iLbaStart, pTrack->cSectors, atapiTrackListMainDataFormToString(pTrack->enmMainDataForm),
                atapiTrackListSubChnDataFormToString(pTrack->enmSubChnDataForm),
                pTrack->fFlags & TRACK_FLAGS_UNDETECTED ? "UNDETECTED " : "",
                pTrack->fFlags & TRACK_FLAGS_LEAD_IN ? "Lead-In " : "",
                pTrack->fFlags & TRACK_FLAGS_LEAD_OUT ? "Lead-Out" : ""));
    }
}

#endif /* LOG_ENABLED */

/**
 * Creates an empty track list handle.
 *
 * @returns VBox status code.
 * @param   ppTrackList Where to store the track list handle on success.
 */
DECLHIDDEN(int) ATAPIPassthroughTrackListCreateEmpty(PTRACKLIST *ppTrackList)
{
    PTRACKLIST pTrackList = (PTRACKLIST)RTMemAllocZ(sizeof(TRACKLIST));
    if (pTrackList)
    {
        *ppTrackList = pTrackList;
        return VINF_SUCCESS;
    }
    return VERR_NO_MEMORY;
}

/**
 * Destroys the allocated task list handle.
 *
 * @param   pTrackList  The track list handle to destroy.
 */
DECLHIDDEN(void) ATAPIPassthroughTrackListDestroy(PTRACKLIST pTrackList)
{
    if (pTrackList->paTracks)
        RTMemFree(pTrackList->paTracks);
    RTMemFree(pTrackList);
}

/**
 * Clears all tracks from the given task list.
 *
 * @param   pTrackList  The track list to clear.
 */
DECLHIDDEN(void) ATAPIPassthroughTrackListClear(PTRACKLIST pTrackList)
{
    AssertPtrReturnVoid(pTrackList);

    pTrackList->cTracksCurrent = 0;

    /* Mark all tracks as undetected. */
    for (unsigned i = 0; i < pTrackList->cTracksMax; i++)
        pTrackList->paTracks[i].fFlags |= TRACK_FLAGS_UNDETECTED;
}

/**
 * Updates the track list from the given CDB and data buffer.
 *
 * @returns VBox status code.
 * @param   pTrackList  The track list to update.
 * @param   pbCDB       The CDB buffer.
 * @param   pvBuf       The data buffer.
 * @param   cbBuf       The buffer isze.
 */
DECLHIDDEN(int) ATAPIPassthroughTrackListUpdate(PTRACKLIST pTrackList, const uint8_t *pbCDB, const void *pvBuf, size_t cbBuf)
{
    int rc;

    switch (pbCDB[0])
    {
        case SCSI_SEND_CUE_SHEET:
            rc = atapiTrackListUpdateFromSendCueSheet(pTrackList, pbCDB, pvBuf, cbBuf);
            break;
        case SCSI_SEND_DVD_STRUCTURE:
            rc = atapiTrackListUpdateFromSendDvdStructure(pTrackList, pbCDB, pvBuf, cbBuf);
            break;
        case SCSI_READ_TOC_PMA_ATIP:
            rc = atapiTrackListUpdateFromReadTocPmaAtip(pTrackList, pbCDB, pvBuf, cbBuf);
            break;
        case SCSI_READ_TRACK_INFORMATION:
            rc = atapiTrackListUpdateFromReadTrackInformation(pTrackList, pbCDB, pvBuf, cbBuf);
            break;
        case SCSI_READ_DVD_STRUCTURE:
            rc = atapiTrackListUpdateFromReadDvdStructure(pTrackList, pbCDB, pvBuf, cbBuf);
            break;
        case SCSI_READ_DISC_INFORMATION:
            rc = atapiTrackListUpdateFromReadDiscInformation(pTrackList, pbCDB, pvBuf, cbBuf);
            break;
        default:
            LogRel(("ATAPI: Invalid opcode %#x while determining media layout\n", pbCDB[0]));
            rc = VERR_INVALID_PARAMETER;
    }

#ifdef LOG_ENABLED
    atapiTrackListDump(pTrackList);
#endif

    return rc;
}

/**
 * Return the sector size from the track matching the LBA in the given track list.
 *
 * @returns Sector size.
 * @param   pTrackList  The track list to use.
 * @param   iAtapiLba   The start LBA to get the sector size for.
 */
DECLHIDDEN(uint32_t) ATAPIPassthroughTrackListGetSectorSizeFromLba(PTRACKLIST pTrackList, uint32_t iAtapiLba)
{
    PTRACK pTrack = NULL;
    uint32_t cbAtapiSector = 2048;

    if (pTrackList->cTracksCurrent)
    {
        if (   iAtapiLba > UINT32_C(0xffff4fa1)
            && (int32_t)iAtapiLba < -150)
        {
            /* Lead-In area, this is always the first entry in the cue sheet. */
            pTrack = pTrackList->paTracks;
            Assert(pTrack->fFlags & TRACK_FLAGS_LEAD_IN);
            LogFlowFunc(("Selected Lead-In area\n"));
        }
        else
        {
            int64_t iAtapiLba64 = (int32_t)iAtapiLba;
            pTrack = &pTrackList->paTracks[1];

            /* Go through the track list and find the correct entry. */
            for (unsigned i = 1; i < pTrackList->cTracksCurrent - 1; i++)
            {
                if (pTrack->fFlags & TRACK_FLAGS_UNDETECTED)
                    continue;

                if (   pTrack->iLbaStart <= iAtapiLba64
                    && iAtapiLba64 < pTrack->iLbaStart + pTrack->cSectors)
                    break;

                pTrack++;
            }
        }

        if (pTrack)
        {
            switch (pTrack->enmMainDataForm)
            {
                case TRACKDATAFORM_CDDA:
                case TRACKDATAFORM_MODE1_2352:
                case TRACKDATAFORM_XA_2352:
                case TRACKDATAFORM_MODE2_2352:
                    cbAtapiSector = 2352;
                    break;
                case TRACKDATAFORM_MODE1_2048:
                    cbAtapiSector = 2048;
                    break;
                case TRACKDATAFORM_CDDA_PAUSE:
                case TRACKDATAFORM_MODE1_0:
                case TRACKDATAFORM_XA_0:
                case TRACKDATAFORM_MODE2_0:
                    cbAtapiSector = 0;
                    break;
                case TRACKDATAFORM_XA_2336:
                case TRACKDATAFORM_MODE2_2336:
                    cbAtapiSector = 2336;
                    break;
                case TRACKDATAFORM_INVALID:
                default:
                    AssertMsgFailed(("Invalid track data form %d\n", pTrack->enmMainDataForm));
            }

            switch (pTrack->enmSubChnDataForm)
            {
                case SUBCHNDATAFORM_0:
                    break;
                case SUBCHNDATAFORM_96:
                    cbAtapiSector += 96;
                    break;
                case SUBCHNDATAFORM_INVALID:
                default:
                    AssertMsgFailed(("Invalid subchannel data form %d\n", pTrack->enmSubChnDataForm));
            }
        }
    }

    return cbAtapiSector;
}


static uint8_t atapiPassthroughCmdErrorSimple(uint8_t *pbSense, size_t cbSense, uint8_t uATAPISenseKey, uint8_t uATAPIASC)
{
    memset(pbSense, '\0', cbSense);
    if (RT_LIKELY(cbSense >= 13))
    {
        pbSense[0] = 0x70 | (1 << 7);
        pbSense[2] = uATAPISenseKey & 0x0f;
        pbSense[7] = 10;
        pbSense[12] = uATAPIASC;
    }
    return SCSI_STATUS_CHECK_CONDITION;
}


/**
 * Parses the given CDB and returns whether it is safe to pass it through to the host drive.
 *
 * @returns Flag whether passing the CDB through to the host drive is safe.
 * @param   pbCdb       The CDB to parse.
 * @param   cbCdb       Size of the CDB in bytes.
 * @param   cbBuf       Size of the guest buffer.
 * @param   pTrackList  The track list for the current medium if available (optional).
 * @param   pbSense     Pointer to the sense buffer.
 * @param   cbSense     Size of the sense buffer.
 * @param   penmTxDir   Where to store the transfer direction (guest to host or vice versa).
 * @param   pcbXfer     Where to store the transfer size encoded in the CDB.
 * @param   pcbSector   Where to store the sector size used for the transfer.
 * @param   pu8ScsiSts  Where to store the SCSI status code.
 */
DECLHIDDEN(bool) ATAPIPassthroughParseCdb(const uint8_t *pbCdb, size_t cbCdb, size_t cbBuf,
                                          PTRACKLIST pTrackList, uint8_t *pbSense, size_t cbSense,
                                          PDMMEDIATXDIR *penmTxDir, size_t *pcbXfer,
                                          size_t *pcbSector, uint8_t *pu8ScsiSts)
{
    uint32_t uLba = 0;
    uint32_t cSectors = 0;
    size_t cbSector = 0;
    size_t cbXfer = 0;
    bool fPassthrough = false;
    PDMMEDIATXDIR enmTxDir = PDMMEDIATXDIR_NONE;

    RT_NOREF(cbCdb);

    switch (pbCdb[0])
    {
        /* First the commands we can pass through without further processing. */
        case SCSI_BLANK:
        case SCSI_CLOSE_TRACK_SESSION:
        case SCSI_LOAD_UNLOAD_MEDIUM:
        case SCSI_PAUSE_RESUME:
        case SCSI_PLAY_AUDIO_10:
        case SCSI_PLAY_AUDIO_12:
        case SCSI_PLAY_AUDIO_MSF:
        case SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL:
        case SCSI_REPAIR_TRACK:
        case SCSI_RESERVE_TRACK:
        case SCSI_SCAN:
        case SCSI_SEEK_10:
        case SCSI_SET_CD_SPEED:
        case SCSI_SET_READ_AHEAD:
        case SCSI_START_STOP_UNIT:
        case SCSI_STOP_PLAY_SCAN:
        case SCSI_SYNCHRONIZE_CACHE:
        case SCSI_TEST_UNIT_READY:
        case SCSI_VERIFY_10:
            fPassthrough = true;
            break;
        case SCSI_ERASE_10:
            uLba = scsiBE2H_U32(pbCdb + 2);
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_FORMAT_UNIT:
            cbXfer = cbBuf;
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_GET_CONFIGURATION:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_GET_EVENT_STATUS_NOTIFICATION:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_GET_PERFORMANCE:
            cbXfer = cbBuf;
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_INQUIRY:
            cbXfer = scsiBE2H_U16(pbCdb + 3);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_MECHANISM_STATUS:
            cbXfer = scsiBE2H_U16(pbCdb + 8);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_MODE_SELECT_10:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_MODE_SENSE_10:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_10:
            uLba = scsiBE2H_U32(pbCdb + 2);
            cSectors = scsiBE2H_U16(pbCdb + 7);
            cbSector = 2048;
            cbXfer = cSectors * cbSector;
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_12:
            uLba = scsiBE2H_U32(pbCdb + 2);
            cSectors = scsiBE2H_U32(pbCdb + 6);
            cbSector = 2048;
            cbXfer = cSectors * cbSector;
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_BUFFER:
            cbXfer = scsiBE2H_U24(pbCdb + 6);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_BUFFER_CAPACITY:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_CAPACITY:
            cbXfer = 8;
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_CD:
        case SCSI_READ_CD_MSF:
        {
            /* Get sector size based on the expected sector type field. */
            switch ((pbCdb[1] >> 2) & 0x7)
            {
                case 0x0: /* All types. */
                {
                    uint32_t iLbaStart;

                    if (pbCdb[0] == SCSI_READ_CD)
                        iLbaStart = scsiBE2H_U32(&pbCdb[2]);
                    else
                        iLbaStart = scsiMSF2LBA(&pbCdb[3]);

                    if (pTrackList)
                        cbSector = ATAPIPassthroughTrackListGetSectorSizeFromLba(pTrackList, iLbaStart);
                    else
                        cbSector = 2048; /* Might be incorrect if we couldn't determine the type. */
                    break;
                }
                case 0x1: /* CD-DA */
                    cbSector = 2352;
                    break;
                case 0x2: /* Mode 1 */
                    cbSector = 2048;
                    break;
                case 0x3: /* Mode 2 formless */
                    cbSector = 2336;
                    break;
                case 0x4: /* Mode 2 form 1 */
                    cbSector = 2048;
                    break;
                case 0x5: /* Mode 2 form 2 */
                    cbSector = 2324;
                    break;
                default: /* Reserved */
                    AssertMsgFailed(("Unknown sector type\n"));
                    cbSector = 0; /** @todo we should probably fail the command here already. */
            }

            if (pbCdb[0] == SCSI_READ_CD)
                cbXfer = scsiBE2H_U24(pbCdb + 6) * cbSector;
            else /* SCSI_READ_MSF */
            {
                cSectors = scsiMSF2LBA(pbCdb + 6) - scsiMSF2LBA(pbCdb + 3);
                if (cSectors > 32)
                    cSectors = 32; /* Limit transfer size to 64~74K. Safety first. In any case this can only harm software doing CDDA extraction. */
                cbXfer = cSectors * cbSector;
            }
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        }
        case SCSI_READ_DISC_INFORMATION:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_DVD_STRUCTURE:
            cbXfer = scsiBE2H_U16(pbCdb + 8);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_FORMAT_CAPACITIES:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_SUBCHANNEL:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_TOC_PMA_ATIP:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_READ_TRACK_INFORMATION:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_REPORT_KEY:
            cbXfer = scsiBE2H_U16(pbCdb + 8);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_REQUEST_SENSE:
            cbXfer = pbCdb[4];
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_SEND_CUE_SHEET:
            cbXfer = scsiBE2H_U24(pbCdb + 6);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_SEND_DVD_STRUCTURE:
            cbXfer = scsiBE2H_U16(pbCdb + 8);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_SEND_EVENT:
            cbXfer = scsiBE2H_U16(pbCdb + 8);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_SEND_KEY:
            cbXfer = scsiBE2H_U16(pbCdb + 8);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_SEND_OPC_INFORMATION:
            cbXfer = scsiBE2H_U16(pbCdb + 7);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_SET_STREAMING:
            cbXfer = scsiBE2H_U16(pbCdb + 9);
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_WRITE_10:
        case SCSI_WRITE_AND_VERIFY_10:
            uLba = scsiBE2H_U32(pbCdb + 2);
            cSectors = scsiBE2H_U16(pbCdb + 7);
            if (pTrackList)
                cbSector = ATAPIPassthroughTrackListGetSectorSizeFromLba(pTrackList, uLba);
            else
                cbSector = 2048;
            cbXfer = cSectors * cbSector;
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_WRITE_12:
            uLba = scsiBE2H_U32(pbCdb + 2);
            cSectors = scsiBE2H_U32(pbCdb + 6);
            if (pTrackList)
                cbSector = ATAPIPassthroughTrackListGetSectorSizeFromLba(pTrackList, uLba);
            else
                cbSector = 2048;
            cbXfer = cSectors * cbSector;
            enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_WRITE_BUFFER:
            switch (pbCdb[1] & 0x1f)
            {
                case 0x04: /* download microcode */
                case 0x05: /* download microcode and save */
                case 0x06: /* download microcode with offsets */
                case 0x07: /* download microcode with offsets and save */
                case 0x0e: /* download microcode with offsets and defer activation */
                case 0x0f: /* activate deferred microcode */
                    LogRel(("ATAPI: CD-ROM passthrough command attempted to update firmware, blocked\n"));
                    *pu8ScsiSts = atapiPassthroughCmdErrorSimple(pbSense, cbSense, SCSI_SENSE_ILLEGAL_REQUEST, SCSI_ASC_INV_FIELD_IN_CMD_PACKET);
                    break;
                default:
                    cbXfer = scsiBE2H_U16(pbCdb + 6);
                    enmTxDir = PDMMEDIATXDIR_TO_DEVICE;
                    fPassthrough = true;
                    break;
            }
            break;
        case SCSI_REPORT_LUNS: /* Not part of MMC-3, but used by Windows. */
            cbXfer = scsiBE2H_U32(pbCdb + 6);
            enmTxDir = PDMMEDIATXDIR_FROM_DEVICE;
            fPassthrough = true;
            break;
        case SCSI_REZERO_UNIT:
            /* Obsolete command used by cdrecord. What else would one expect?
             * This command is not sent to the drive, it is handled internally,
             * as the Linux kernel doesn't like it (message "scsi: unknown
             * opcode 0x01" in syslog) and replies with a sense code of 0,
             * which sends cdrecord to an endless loop. */
            *pu8ScsiSts = atapiPassthroughCmdErrorSimple(pbSense, cbSense, SCSI_SENSE_ILLEGAL_REQUEST, SCSI_ASC_ILLEGAL_OPCODE);
            break;
        default:
            LogRel(("ATAPI: Passthrough unimplemented for command %#x\n", pbCdb[0]));
            *pu8ScsiSts = atapiPassthroughCmdErrorSimple(pbSense, cbSense, SCSI_SENSE_ILLEGAL_REQUEST, SCSI_ASC_ILLEGAL_OPCODE);
            break;
    }

    if (fPassthrough)
    {
        *penmTxDir = enmTxDir;
        *pcbXfer   = cbXfer;
        *pcbSector = cbSector;
    }

    return fPassthrough;
}

