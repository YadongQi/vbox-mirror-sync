/* $Id$ */
/** @file
 * RegCleanup - Remove "InvalidDisplay" and "NewDisplay" keys on NT4,
 *              run via HKLM/.../Windows/CurrentVersion/RunOnce.
 *
 * Delete the "InvalidDisplay" key which causes the display applet to be
 * started on every boot. For some reason this key isn't removed after
 * setting the proper resolution and even not when * doing a driver reinstall.
 * Removing it doesn't seem to do any harm.  The key is inserted by windows on
 * first reboot after installing the VBox video driver using the VirtualBox
 * utility. It's not inserted when using the Display applet for installation.
 * There seems to be a subtle problem with the VirtualBox util.
 */

/*
 * Copyright (C) 2006-2022 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */


/*********************************************************************************************************************************
*   Header Files                                                                                                                 *
*********************************************************************************************************************************/
#include <iprt/win/windows.h>
#include <iprt/cdefs.h> /* RT_STR_TUPLE */
#include <iprt/types.h> /* RTEXITCODE_FAILURE */


static bool IsNt4(void)
{
    OSVERSIONINFOW VerInfo = { sizeof(VerInfo), 0 };
    GetVersionExW(&VerInfo);
    return VerInfo.dwPlatformId  == VER_PLATFORM_WIN32_NT
        && VerInfo.dwMajorVersion == 4;
}


int main()
{
    if (!IsNt4())
    {
        DWORD cbIgn;
        WriteFile(GetStdHandle(STD_ERROR_HANDLE), RT_STR_TUPLE("This program only runs on NT4\r\n"), &cbIgn, NULL);
        return RTEXITCODE_FAILURE;
    }

    /* Delete the "InvalidDisplay" key which causes the display
       applet to be started on every boot. For some reason this key
       isn't removed after setting the proper resolution and even not when
       doing a driverreinstall.  */
    RegDeleteKeyW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\InvalidDisplay");
    RegDeleteKeyW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\NewDisplay");
    return RTEXITCODE_SUCCESS;
}

