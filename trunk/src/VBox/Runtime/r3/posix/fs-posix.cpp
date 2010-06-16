/* $Id$ */
/** @file
 * IPRT - File System, Linux.
 */

/*
 * Copyright (C) 2006-2007 Oracle Corporation
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


/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#define LOG_GROUP RTLOGGROUP_FS
#include <sys/statvfs.h>
#include <errno.h>
#include <stdio.h>
#ifdef RT_OS_LINUX
# include <mntent.h>
#endif

#include <iprt/fs.h>
#include "internal/iprt.h"

#include <iprt/assert.h>
#include <iprt/err.h>
#include <iprt/log.h>
#include <iprt/string.h>
#include "internal/fs.h"
#include "internal/path.h"



RTR3DECL(int) RTFsQuerySizes(const char *pszFsPath, RTFOFF *pcbTotal, RTFOFF *pcbFree,
                             uint32_t *pcbBlock, uint32_t *pcbSector)
{
    /*
     * Validate input.
     */
    AssertMsgReturn(VALID_PTR(pszFsPath) && *pszFsPath, ("%p", pszFsPath), VERR_INVALID_PARAMETER);

    /*
     * Convert the path and query the information.
     */
    char const *pszNativeFsPath;
    int rc = rtPathToNative(&pszNativeFsPath, pszFsPath, NULL);
    if (RT_SUCCESS(rc))
    {
        /** @todo I'm not quite sure if statvfs was properly specified by SuS, I have to check my own
         * implementation and FreeBSD before this can eventually be promoted to posix. */
        struct statvfs StatVFS;
        RT_ZERO(StatVFS);
        if (!statvfs(pszNativeFsPath, &StatVFS))
        {
            /*
             * Calc the returned values.
             */
            if (pcbTotal)
                *pcbTotal = (RTFOFF)StatVFS.f_blocks * StatVFS.f_frsize;
            if (pcbFree)
                *pcbFree = (RTFOFF)StatVFS.f_bavail * StatVFS.f_frsize;
            if (pcbBlock)
                *pcbBlock = StatVFS.f_frsize;
            /* no idea how to get the sector... */
            if (pcbSector)
                *pcbSector = 512;
        }
        else
            rc = RTErrConvertFromErrno(errno);
        rtPathFreeNative(pszNativeFsPath, pszFsPath);
    }

    LogFlow(("RTFsQuerySizes(%p:{%s}, %p:{%RTfoff}, %p:{%RTfoff}, %p:{%RX32}, %p:{%RX32}): returns %Rrc\n",
             pszFsPath, pszFsPath, pcbTotal, pcbTotal ? *pcbTotal : 0, pcbFree, pcbFree ? *pcbFree : 0,
             pcbBlock, pcbBlock ? *pcbBlock : 0, pcbSector, pcbSector ? *pcbSector : 0, rc));
    return rc;
}


RTR3DECL(int) RTFsQuerySerial(const char *pszFsPath, uint32_t *pu32Serial)
{
    /*
     * Validate input.
     */
    AssertMsgReturn(VALID_PTR(pszFsPath) && *pszFsPath, ("%p", pszFsPath), VERR_INVALID_PARAMETER);
    AssertMsgReturn(VALID_PTR(pu32Serial), ("%p", pu32Serial), VERR_INVALID_PARAMETER);

    /*
     * Conver the path and query the stats.
     * We're simply return the device id.
     */
    char const *pszNativeFsPath;
    int rc = rtPathToNative(&pszNativeFsPath, pszFsPath, NULL);
    if (RT_SUCCESS(rc))
    {
        struct stat Stat;
        if (!stat(pszNativeFsPath, &Stat))
        {
            if (pu32Serial)
                *pu32Serial = (uint32_t)Stat.st_dev;
        }
        else
            rc = RTErrConvertFromErrno(errno);
        rtPathFreeNative(pszNativeFsPath, pszFsPath);
    }
    LogFlow(("RTFsQuerySerial(%p:{%s}, %p:{%RX32}: returns %Rrc\n",
             pszFsPath, pszFsPath, pu32Serial, pu32Serial ? *pu32Serial : 0, rc));
    return rc;
}


RTR3DECL(int) RTFsQueryProperties(const char *pszFsPath, PRTFSPROPERTIES pProperties)
{
    /*
     * Validate.
     */
    AssertMsgReturn(VALID_PTR(pszFsPath) && *pszFsPath, ("%p", pszFsPath), VERR_INVALID_PARAMETER);
    AssertMsgReturn(VALID_PTR(pProperties), ("%p", pProperties), VERR_INVALID_PARAMETER);

    /*
     * Convert the path and query the information.
     */
    char const *pszNativeFsPath;
    int rc = rtPathToNative(&pszNativeFsPath, pszFsPath, NULL);
    if (RT_SUCCESS(rc))
    {
        struct statvfs StatVFS;
        RT_ZERO(StatVFS);
        if (!statvfs(pszNativeFsPath, &StatVFS))
        {
            /*
             * Calc/fake the returned values.
             */
            pProperties->cbMaxComponent = StatVFS.f_namemax;
            pProperties->fCaseSensitive = true;
            pProperties->fCompressed = false;
            pProperties->fFileCompression = false;
            pProperties->fReadOnly = !!(StatVFS.f_flag & ST_RDONLY);
            pProperties->fRemote = false;
            pProperties->fSupportsUnicode = true;
        }
        else
            rc = RTErrConvertFromErrno(errno);
        rtPathFreeNative(pszNativeFsPath, pszFsPath);
    }

    LogFlow(("RTFsQueryProperties(%p:{%s}, %p:{.cbMaxComponent=%u, .fCaseSensitive=%RTbool}): returns %Rrc\n",
             pszFsPath, pszFsPath, pProperties, pProperties->cbMaxComponent, pProperties->fReadOnly));
    return VINF_SUCCESS;
}


RTR3DECL(int) RTFsQueryType(const char *pszFsPath, uint32_t *pu32Type)
{
    /*
     * Validate input.
     */
    AssertMsgReturn(VALID_PTR(pszFsPath) && *pszFsPath, ("%p", pszFsPath), VERR_INVALID_PARAMETER);

    /*
     * Convert the path and query the stats.
     * We're simply return the device id.
     */
    char const *pszNativeFsPath;
    int rc = rtPathToNative(&pszNativeFsPath, pszFsPath, NULL);
    if (RT_SUCCESS(rc))
    {
        *pu32Type = RTFS_FS_TYPE_UNKNOWN;

        struct stat Stat;
        if (!stat(pszNativeFsPath, &Stat))
        {
#if defined(RT_OS_LINUX)
            FILE *mounted = setmntent("/proc/mounts", "r");
            if (!mounted)
                mounted = setmntent("/etc/mtab", "r");
            if (mounted)
            {
                char szBuf[1024];
                struct stat mntStat;
                struct mntent mntEnt;
                while (getmntent_r(mounted, &mntEnt, szBuf, sizeof(szBuf)))
                {
                    if (!stat(mntEnt.mnt_dir, &mntStat))
                    {
                        if (mntStat.st_dev == Stat.st_dev)
                        {
                            if (!strcmp("ext4", mntEnt.mnt_type))
                                *pu32Type = RTFS_FS_TYPE_EXT4;
                            else if (!strcmp("ext3", mntEnt.mnt_type))
                                *pu32Type = RTFS_FS_TYPE_EXT3;
                            else if (!strcmp("ext2", mntEnt.mnt_type))
                                *pu32Type = RTFS_FS_TYPE_EXT2;
                            else if (   !strcmp("vfat", mntEnt.mnt_type)
                                     || !strcmp("msdos", mntEnt.mnt_type))
                                *pu32Type = RTFS_FS_TYPE_FAT;
                            else if (!strcmp("tmpfs", mntEnt.mnt_type))
                                *pu32Type = RTFS_FS_TYPE_TMPFS;
                            else
                            {
                                /* sometimes there are more than one entry for the same partition */
                                continue;
                            }
                            break;
                        }
                    }
                }
                endmntent(mounted);
            }
#elif defined(RT_OS_SOLARIS)
            if (!strcmp("zfs", Stat.st_fstype))
                *pu32Type = RTFS_FS_TYPE_ZFS;
#endif
        }
        else
            rc = RTErrConvertFromErrno(errno);
        rtPathFreeNative(pszNativeFsPath, pszFsPath);
    }

    return rc;
}
