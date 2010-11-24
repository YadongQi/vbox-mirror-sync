/* $Id$ */
/** @file
 * VirtualBox Main - Extension Pack Helper Application, usually set-uid-to-root.
 */

/*
 * Copyright (C) 2010 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */


/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#include "include/ExtPackUtil.h"

#include <iprt/buildconfig.h>
//#include <iprt/ctype.h>
#include <iprt/dir.h>
//#include <iprt/env.h>
#include <iprt/file.h>
#include <iprt/fs.h>
#include <iprt/getopt.h>
#include <iprt/initterm.h>
#include <iprt/message.h>
#include <iprt/param.h>
#include <iprt/path.h>
//#include <iprt/pipe.h>
#include <iprt/process.h>
#include <iprt/string.h>
#include <iprt/stream.h>

#include <VBox/log.h>
#include <VBox/err.h>
#include <VBox/sup.h>
#include <VBox/version.h>


#ifdef IN_RT_R3
/* Override RTAssertShouldPanic to prevent gdb process creation. */
RTDECL(bool) RTAssertShouldPanic(void)
{
    return true;
}
#endif


/**
 * Handle the special standard options when these are specified after the
 * command.
 *
 * @param   ch          The option character.
 */
static RTEXITCODE DoStandardOption(int ch)
{
    switch (ch)
    {
        case 'h':
        {
            RTMsgInfo(VBOX_PRODUCT " Extension Pack Helper App\n"
                      "(C) " VBOX_C_YEAR " " VBOX_VENDOR "\n"
                      "All rights reserved.\n"
                      "\n"
                      "This NOT intended for general use, please use VBoxManage instead\n"
                      "or call the IExtPackManager API directly.\n"
                      "\n"
                      "Usage: %s <command> [options]\n"
                      "Commands:\n"
                      "    install --base-dir <dir> --certificate-dir <dir> --name <name> \\\n"
                      "        --tarball <tarball> --tarball-fd <fd>\n"
                      "    uninstall --base-dir <dir> --name <name>\n"
                      , RTProcShortName());
            return RTEXITCODE_SUCCESS;
        }

        case 'V':
            RTPrintf("%sr%d\n", VBOX_VERSION_STRING, RTBldCfgRevision());
            return RTEXITCODE_SUCCESS;

        default:
            AssertFailedReturn(RTEXITCODE_FAILURE);
    }
}


/**
 * Checks if the cerficiate directory is valid.
 *
 * @returns true if it is valid, false if it isn't.
 * @param   pszCertDir          The certificate directory to validate.
 */
static bool IsValidCertificateDir(const char *pszCertDir)
{
    /*
     * Just be darn strict for now.
     */
    char szCorrect[RTPATH_MAX];
    int rc = RTPathAppPrivateNoArch(szCorrect, sizeof(szCorrect));
    if (RT_FAILURE(rc))
        return false;
    rc = RTPathAppend(szCorrect, sizeof(szCorrect), VBOX_EXTPACK_CERT_DIR);
    if (RT_FAILURE(rc))
        return false;

    return RTPathCompare(szCorrect, pszCertDir) == 0;
}


/**
 * Checks if the base directory is valid.
 *
 * @returns true if it is valid, false if it isn't.
 * @param   pszBaesDir          The base directory to validate.
 */
static bool IsValidBaseDir(const char *pszBaseDir)
{
    /*
     * Just be darn strict for now.
     */
    char szCorrect[RTPATH_MAX];
    int rc = RTPathAppPrivateArch(szCorrect, sizeof(szCorrect));
    if (RT_FAILURE(rc))
        return false;
    rc = RTPathAppend(szCorrect, sizeof(szCorrect), VBOX_EXTPACK_INSTALL_DIR);
    if (RT_FAILURE(rc))
        return false;

    return RTPathCompare(szCorrect, pszBaseDir) == 0;
}

/**
 * Cleans up a temporary extension pack directory.
 *
 * This is used by 'uninstall', 'cleanup' and in the failure path of 'install'.
 *
 * @returns The program exit code.
 * @param   pszDir          The directory to clean up.  The caller is
 *                          responsible for making sure this is valid.
 * @param   fTemporary      Whether this is a temporary install directory or
 *                          not.
 */
static RTEXITCODE RemoveExtPackDir(const char *pszDir, bool fTemporary)
{
    /** @todo May have to undo 555 modes here later.  */
    int rc = RTDirRemoveRecursive(pszDir, RTDIRRMREC_F_CONTENT_AND_DIR);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE,
                              "Failed to delete the %sextension pack directory: %Rrc ('%s')",
                              fTemporary ? "temporary " : "", rc, pszDir);
    return RTEXITCODE_SUCCESS;
}


/**
 * Sets the permissions of the temporary extension pack directory just before
 * renaming it.
 *
 * By default the temporary directory is only accessible by root, this function
 * will make it world readable and browseable.
 *
 * @returns The program exit code.
 * @param   pszDir              The temporary extension pack directory.
 */
static RTEXITCODE SetExtPackPermissions(const char *pszDir)
{
#if !defined(RT_OS_WINDOWS)
     int rc = RTPathSetMode(pszDir, 0755);
     if (RT_FAILURE(rc))
         return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed to set directory permissions: %Rrc ('%s')", rc, pszDir);
#else
        /** @todo  */
#endif

    return RTEXITCODE_SUCCESS;
}

/**
 * Validates the extension pack.
 *
 * Operations performed:
 *      - Manifest seal check.
 *      - Manifest check.
 *      - Recursive hardening check.
 *      - XML validity check.
 *      - Name check (against XML).
 *
 * @returns The program exit code.
 * @param   pszDir              The directory where the extension pack has been
 *                              unpacked.
 * @param   pszName             The expected extension pack name.
 * @param   pszTarball          The name of the tarball in case we have to
 *                              complain about something.
 */
static RTEXITCODE ValidateExtPack(const char *pszDir, const char *pszTarball, const char *pszName)
{
    /** @todo  */
    return RTEXITCODE_SUCCESS;
}


/**
 * Unpacks the extension pack into the specified directory.
 *
 * This will apply ownership and permission changes to all the content, the
 * exception is @a pszDirDst which will be handled by SetExtPackPermissions.
 *
 * @returns The program exit code.
 * @param   hTarballFile        The tarball to unpack.
 * @param   pszDirDst           Where to unpack it.
 * @param   pszTarball          The name of the tarball in case we have to
 *                              complain about something.
 */
static RTEXITCODE UnpackExtPack(RTFILE hTarballFile, const char *pszDirDst, const char *pszTarball)
{
    /** @todo  */
    return RTEXITCODE_SUCCESS;
}


/**
 * The 2nd part of the installation process.
 *
 * @returns The program exit code.
 * @param   pszBaseDir          The base directory.
 * @param   pszCertDir          The certificat directory.
 * @param   pszTarball          The tarball name.
 * @param   hTarballFile        The handle to open the @a pszTarball file.
 * @param   hTarballFileOpt     The tarball file handle (optional).
 * @param   pszName             The extension pack name.
 */
static RTEXITCODE DoInstall2(const char *pszBaseDir, const char *pszCertDir, const char *pszTarball,
                             RTFILE hTarballFile, RTFILE hTarballFileOpt, const char *pszName)
{
    /*
     * Do some basic validation of the tarball file.
     */
    RTFSOBJINFO ObjInfo;
    int rc = RTFileQueryInfo(hTarballFile, &ObjInfo, RTFSOBJATTRADD_UNIX);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "RTFileQueryInfo failed with %Rrc on '%s'", rc, pszTarball);
    if (!RTFS_IS_FILE(ObjInfo.Attr.fMode))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Not a regular file: %s", pszTarball);

    if (hTarballFileOpt != NIL_RTFILE)
    {
        RTFSOBJINFO ObjInfo2;
        rc = RTFileQueryInfo(hTarballFileOpt, &ObjInfo2, RTFSOBJATTRADD_UNIX);
        if (RT_FAILURE(rc))
            return RTMsgErrorExit(RTEXITCODE_FAILURE, "RTFileQueryInfo failed with %Rrc on --tarball-fd", rc);
        if (   ObjInfo.Attr.u.Unix.INodeIdDevice != ObjInfo2.Attr.u.Unix.INodeIdDevice
            || ObjInfo.Attr.u.Unix.INodeId       != ObjInfo2.Attr.u.Unix.INodeId)
            return RTMsgErrorExit(RTEXITCODE_FAILURE, "--tarball and --tarball-fd does not match");
    }

    /*
     * Construct the paths to the two directories we'll be using.
     */
    char szFinalPath[RTPATH_MAX];
    rc = RTPathJoin(szFinalPath, sizeof(szFinalPath), pszBaseDir, pszName);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE,
                              "Failed to construct the path to the final extension pack directory: %Rrc", rc);

    char szTmpPath[RTPATH_MAX];
    rc = RTPathJoin(szTmpPath, sizeof(szTmpPath) - 64, pszBaseDir, pszName);
    if (RT_SUCCESS(rc))
    {
        size_t cchTmpPath = strlen(szTmpPath);
        RTStrPrintf(&szTmpPath[cchTmpPath], sizeof(szTmpPath) - cchTmpPath, "-_-inst-%u", (uint32_t)RTProcSelf());
    }
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE,
                              "Failed to construct the path to the temporary extension pack directory: %Rrc", rc);

    /*
     * Check that they don't exist at this point in time.
     */
    rc = RTPathQueryInfoEx(szFinalPath, &ObjInfo, RTFSOBJATTRADD_NOTHING,  RTPATH_F_ON_LINK);
    if (RT_SUCCESS(rc) && RTFS_IS_DIRECTORY(ObjInfo.Attr.fMode))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "The extension pack is already installed. You must uninstall the old one first.");
    if (RT_SUCCESS(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE,
                              "Found non-directory file system object where the extension pack would be installed ('%s')",
                              szFinalPath);
    if (rc != VERR_FILE_NOT_FOUND && rc != VERR_PATH_NOT_FOUND)
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Unexpected RTPathQueryInfoEx status code %Rrc for '%s'", rc, szFinalPath);

    rc = RTPathQueryInfoEx(szTmpPath, &ObjInfo, RTFSOBJATTRADD_NOTHING,  RTPATH_F_ON_LINK);
    if (rc != VERR_FILE_NOT_FOUND && rc != VERR_PATH_NOT_FOUND)
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Unexpected RTPathQueryInfoEx status code %Rrc for '%s'", rc, szFinalPath);

    /*
     * Create the temporary directory and prepare the extension pack within it.
     * If all checks out correctly, rename it to the final directory.
     */
    rc = RTDirCreate(szTmpPath, 0700);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed to create temporary directory: %Rrc ('%s')", rc, szTmpPath);

    RTEXITCODE rcExit = UnpackExtPack(hTarballFile, szTmpPath, pszTarball);
    if (rcExit == RTEXITCODE_SUCCESS)
        rcExit = ValidateExtPack(szTmpPath, pszTarball, pszName);
    if (rcExit == RTEXITCODE_SUCCESS)
        rcExit = SetExtPackPermissions(szTmpPath);
    if (rcExit == RTEXITCODE_SUCCESS)
    {
        rc = RTDirRename(szTmpPath, szFinalPath, RTPATHRENAME_FLAGS_NO_REPLACE);
        if (RT_SUCCESS(rc))
            RTMsgInfo("Successfully installed '%s' (%s)", pszName, pszTarball);
        else
            rcExit = RTMsgErrorExit(RTEXITCODE_FAILURE,
                                    "Failed to rename the temporary directory to the final one: %Rrc ('%s' -> '%s')",
                                    rc, szTmpPath, szFinalPath);
    }

    /*
     * Clean up the temporary directory on failure.
     */
    if (rcExit != RTEXITCODE_SUCCESS)
        RemoveExtPackDir(szTmpPath, true /*fTemporary*/);

    return rcExit;
}


/**
 * Implements the 'install' command.
 *
 * @returns The program exit code.
 * @param   argc            The number of program arguments.
 * @param   argv            The program arguments.
 */
static RTEXITCODE DoInstall(int argc, char **argv)
{
    /*
     * Parse the parameters.
     *
     * Note! The --base-dir and --cert-dir are only for checking that the
     *       caller and this help applications have the same idea of where
     *       things are.  Likewise, the --name is for verifying assumptions
     *       the caller made about the name.  The optional --tarball-fd option
     *       is just for easing the paranoia on the user side.
     */
    static const RTGETOPTDEF s_aOptions[] =
    {
        { "--base-dir",     'b',   RTGETOPT_REQ_STRING },
        { "--cert-dir",     'c',   RTGETOPT_REQ_STRING },
        { "--name",         'n',   RTGETOPT_REQ_STRING },
        { "--tarball",      't',   RTGETOPT_REQ_STRING },
        { "--tarball-fd",   'f',   RTGETOPT_REQ_UINT64 }
    };
    RTGETOPTSTATE   GetState;
    int rc = RTGetOptInit(&GetState, argc, argv, s_aOptions, RT_ELEMENTS(s_aOptions), 0, 0 /*fFlags*/);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "RTGetOptInit failed: %Rrc\n", rc);

    const char     *pszBaseDir      = NULL;
    const char     *pszCertDir      = NULL;
    const char     *pszName         = NULL;
    const char     *pszTarball      = NULL;
    RTFILE          hTarballFileOpt = NIL_RTFILE;
    RTGETOPTUNION   ValueUnion;
    int             ch;
    while ((ch = RTGetOpt(&GetState, &ValueUnion)))
    {
        switch (ch)
        {
            case 'b':
                if (pszBaseDir)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --base-dir options");
                pszBaseDir = ValueUnion.psz;
                if (!IsValidBaseDir(pszBaseDir))
                    return RTMsgErrorExit(RTEXITCODE_FAILURE, "Invalid base directory: '%s'", pszBaseDir);
                break;

            case 'c':
                if (pszCertDir)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --cert-dir options");
                pszCertDir = ValueUnion.psz;
                if (!IsValidCertificateDir(pszCertDir))
                    return RTMsgErrorExit(RTEXITCODE_FAILURE, "Invalid certificate directory: '%s'", pszCertDir);
                break;

            case 'n':
                if (pszName)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --name options");
                pszName = ValueUnion.psz;
                if (!VBoxExtPackIsValidName(pszName))
                    return RTMsgErrorExit(RTEXITCODE_FAILURE, "Invalid extension pack name: '%s'", pszName);
                break;

            case 't':
                if (pszTarball)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --tarball options");
                pszTarball = ValueUnion.psz;
                break;

            case 'd':
            {
                if (hTarballFileOpt != NIL_RTFILE)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --tarball-fd options");
                RTHCUINTPTR hNative = (RTHCUINTPTR)ValueUnion.u64;
                if (hNative != ValueUnion.u64)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "The --tarball-fd value is out of range: %#RX64", ValueUnion.u64);
                rc = RTFileFromNative(&hTarballFileOpt, hNative);
                if (RT_FAILURE(rc))
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "RTFileFromNative failed on --target-fd value: %Rrc", rc);
                break;
            }

            case 'h':
            case 'V':
                return DoStandardOption(ch);

            default:
                return RTGetOptPrintError(ch, &ValueUnion);
        }
    }
    if (!pszName)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --name option");
    if (!pszBaseDir)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --base-dir option");
    if (!pszCertDir)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --cert-dir option");
    if (!pszTarball)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --tarball option");

    /*
     * Ok, down to business.
     */
    RTFILE hTarballFile;
    rc = RTFileOpen(&hTarballFile, pszTarball, RTFILE_O_READ | RTFILE_O_OPEN | RTFILE_O_DENY_WRITE);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed to open the extension pack tarball: %Rrc ('%s')", rc, pszTarball);

    RTEXITCODE rcExit = DoInstall2(pszBaseDir, pszCertDir, pszTarball, hTarballFile, hTarballFileOpt, pszName);
    RTFileClose(hTarballFile);
    return rcExit;
}


/**
 * Implements the 'uninstall' command.
 *
 * @returns The program exit code.
 * @param   argc            The number of program arguments.
 * @param   argv            The program arguments.
 */
static RTEXITCODE DoUninstall(int argc, char **argv)
{
    /*
     * Parse the parameters.
     *
     * Note! The --base-dir is only for checking that the caller and this help
     *       applications have the same idea of where things are.
     */
    static const RTGETOPTDEF s_aOptions[] =
    {
        { "--base-dir",     'b',   RTGETOPT_REQ_STRING },
        { "--name",         'n',   RTGETOPT_REQ_STRING }
    };
    RTGETOPTSTATE   GetState;
    int rc = RTGetOptInit(&GetState, argc, argv, s_aOptions, RT_ELEMENTS(s_aOptions), 0, 0 /*fFlags*/);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "RTGetOptInit failed: %Rrc\n", rc);

    const char     *pszBaseDir = NULL;
    const char     *pszName    = NULL;
    RTGETOPTUNION   ValueUnion;
    int             ch;
    while ((ch = RTGetOpt(&GetState, &ValueUnion)))
    {
        switch (ch)
        {
            case 'b':
                if (pszBaseDir)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --base-dir options");
                pszBaseDir = ValueUnion.psz;
                if (!IsValidBaseDir(pszBaseDir))
                    return RTMsgErrorExit(RTEXITCODE_FAILURE, "Invalid base directory: '%s'", pszBaseDir);
                break;

            case 'n':
                if (pszName)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --name options");
                pszName = ValueUnion.psz;
                if (!VBoxExtPackIsValidName(pszName))
                    return RTMsgErrorExit(RTEXITCODE_FAILURE, "Invalid extension pack name: '%s'", pszName);
                break;

            case 'h':
            case 'V':
                return DoStandardOption(ch);

            default:
                return RTGetOptPrintError(ch, &ValueUnion);
        }
    }
    if (!pszName)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --name option");
    if (!pszBaseDir)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --base-dir option");

    /*
     * Ok, down to business.
     */
    /* Check that it exists. */
    char szExtPackDir[RTPATH_MAX];
    rc = RTPathJoin(szExtPackDir, sizeof(szExtPackDir), pszBaseDir, pszName);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed to construct extension pack path: %Rrc", rc);

    if (!RTDirExists(szExtPackDir))
    {
        RTMsgInfo("Extension pack not installed. Nothing to do.");
        return RTEXITCODE_SUCCESS;
    }

    /* Rename the extension pack directory before deleting it to prevent new
       VM processes from picking it up. */
    char szExtPackUnInstDir[RTPATH_MAX];
    rc = RTPathJoin(szExtPackUnInstDir, sizeof(szExtPackUnInstDir), pszBaseDir, pszName);
    if (RT_SUCCESS(rc))
        rc = RTStrCat(szExtPackUnInstDir, sizeof(szExtPackUnInstDir), "-_-uninst");
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed to construct temporary extension pack path: %Rrc", rc);

    rc = RTDirRename(szExtPackDir, szExtPackUnInstDir, RTPATHRENAME_FLAGS_NO_REPLACE);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed to rename the extension pack directory: %Rrc", rc);

    /* Recursively delete the directory content. */
    RTEXITCODE rcExit = RemoveExtPackDir(szExtPackUnInstDir, false /*fTemporary*/);
    if (rcExit == RTEXITCODE_SUCCESS)
        RTMsgInfo("Successfully removed extension pack '%s'\n", pszName);

    return rcExit;
}

/**
 * Implements the 'cleanup' command.
 *
 * @returns The program exit code.
 * @param   argc            The number of program arguments.
 * @param   argv            The program arguments.
 */
static RTEXITCODE DoCleanup(int argc, char **argv)
{
    /*
     * Parse the parameters.
     *
     * Note! The --base-dir is only for checking that the caller and this help
     *       applications have the same idea of where things are.
     */
    static const RTGETOPTDEF s_aOptions[] =
    {
        { "--base-dir",     'b',   RTGETOPT_REQ_STRING },
    };
    RTGETOPTSTATE   GetState;
    int rc = RTGetOptInit(&GetState, argc, argv, s_aOptions, RT_ELEMENTS(s_aOptions), 0, 0 /*fFlags*/);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "RTGetOptInit failed: %Rrc\n", rc);

    const char     *pszBaseDir = NULL;
    RTGETOPTUNION   ValueUnion;
    int             ch;
    while ((ch = RTGetOpt(&GetState, &ValueUnion)))
    {
        switch (ch)
        {
            case 'b':
                if (pszBaseDir)
                    return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Too many --base-dir options");
                pszBaseDir = ValueUnion.psz;
                if (!IsValidBaseDir(pszBaseDir))
                    return RTMsgErrorExit(RTEXITCODE_FAILURE, "Invalid base directory: '%s'", pszBaseDir);
                break;

            case 'h':
            case 'V':
                return DoStandardOption(ch);

            default:
                return RTGetOptPrintError(ch, &ValueUnion);
        }
    }
    if (!pszBaseDir)
        return RTMsgErrorExit(RTEXITCODE_SYNTAX, "Missing --base-dir option");

    /*
     * Ok, down to business.
     */
    PRTDIR pDir;
    rc = RTDirOpen(&pDir, pszBaseDir);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "Failed open the base directory: %Rrc ('%s')", rc, pszBaseDir);

    uint32_t    cCleaned = 0;
    RTEXITCODE  rcExit = RTEXITCODE_SUCCESS;
    for (;;)
    {
        RTDIRENTRYEX Entry;
        rc = RTDirReadEx(pDir, &Entry, NULL /*pcbDirEntry*/, RTFSOBJATTRADD_NOTHING, RTPATH_F_ON_LINK);
        if (RT_FAILURE(rc))
        {
            if (rc != VERR_NO_MORE_FILES)
                rcExit = RTMsgErrorExit(RTEXITCODE_FAILURE, "RTDirReadEx returns %Rrc", rc);
            break;
        }
        if (   RTFS_IS_DIRECTORY(Entry.Info.Attr.fMode)
            && strcmp(Entry.szName, ".")  != 0
            && strcmp(Entry.szName, "..") != 0
            && !VBoxExtPackIsValidName(Entry.szName) )
        {
            char szPath[RTPATH_MAX];
            rc = RTPathJoin(szPath, sizeof(szPath), pszBaseDir, Entry.szName);
            if (RT_SUCCESS(rc))
            {
                RTEXITCODE rcExit2 = RemoveExtPackDir(szPath, true /*fTemporary*/);
                if (rcExit2 == RTEXITCODE_SUCCESS)
                    RTMsgInfo("Successfully removed '%s'.", Entry.szName);
                else if (rcExit == RTEXITCODE_SUCCESS)
                    rcExit = rcExit2;
            }
            else
                rcExit = RTMsgErrorExit(RTEXITCODE_FAILURE, "RTPathJoin failed with %Rrc for '%s'", rc, Entry.szName);
            cCleaned++;
        }
    }
    RTDirClose(pDir);
    if (!cCleaned)
        RTMsgInfo("Nothing to clean.");
    return rcExit;
}



int main(int argc, char **argv)
{
    /*
     * Initialize IPRT and check that we're correctly installed.
     */
    int rc = RTR3Init();
    if (RT_FAILURE(rc))
        return RTMsgInitFailure(rc);

    char szErr[2048];
    rc = SUPR3HardenedVerifySelf(argv[0], true /*fInternal*/, szErr, sizeof(szErr));
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "%s", szErr);

    /*
     * Parse the top level arguments until we find a command.
     */
    static const RTGETOPTDEF s_aOptions[] =
    {
#define CMD_INSTALL     1000
        { "install",    CMD_INSTALL,    RTGETOPT_REQ_NOTHING },
#define CMD_UNINSTALL   1001
        { "uninstall",  CMD_UNINSTALL,  RTGETOPT_REQ_NOTHING },
#define CMD_CLEANUP     1002
        { "cleanup",    CMD_CLEANUP,    RTGETOPT_REQ_NOTHING },
    };
    RTGETOPTSTATE GetState;
    rc = RTGetOptInit(&GetState, argc, argv, s_aOptions, RT_ELEMENTS(s_aOptions), 1, 0 /*fFlags*/);
    if (RT_FAILURE(rc))
        return RTMsgErrorExit(RTEXITCODE_FAILURE, "RTGetOptInit failed: %Rrc\n", rc);
    for (;;)
    {
        RTGETOPTUNION ValueUnion;
        int ch = RTGetOpt(&GetState, &ValueUnion);
        switch (ch)
        {
            case 0:
                return RTMsgErrorExit(RTEXITCODE_SYNTAX, "No command specified");

            case CMD_INSTALL:
                return DoInstall(  argc - GetState.iNext, argv + GetState.iNext);

            case CMD_UNINSTALL:
                return DoUninstall(argc - GetState.iNext, argv + GetState.iNext);

            case CMD_CLEANUP:
                return DoCleanup(  argc - GetState.iNext, argv + GetState.iNext);

            case 'h':
            case 'V':
                return DoStandardOption(ch);

            default:
                return RTGetOptPrintError(ch, &ValueUnion);
        }
        /* not currently reached */
    }
    /* not reached */
}

