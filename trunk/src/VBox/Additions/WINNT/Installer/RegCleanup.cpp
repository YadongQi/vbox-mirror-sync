/** @file
 *
 * delinvalid - remove "InvalidDisplay" key on NT4
 *
 * Copyright (C) 2006-2007 Oracle Corporation
 *
 * Oracle Corporation confidential
 * All rights reserved
 */

/*
 Purpose:

 Delete the "InvalidDisplay" key which causes the display
 applet to be started on every boot. For some reason this key
 isn't removed after setting the proper resolution and even not when
 doing a driver reinstall. Removing it doesn't seem to do any harm.
 The key is inserted by windows on first reboot after installing
 the VBox video driver using the VirtualBox utility.
 It's not inserted when using the Display applet for installation.
 There seems to be a subtle problem with the VirtualBox util.
 */

//#define _UNICODE

#include <windows.h>
#include <setupapi.h>
#include <regstr.h>
#include <DEVGUID.h>
#include <stdio.h>

#include "tchar.h"
#include "string.h"

/*******************************************************************************
 *   Defined Constants And Macros                                               *
 *******************************************************************************/

/////////////////////////////////////////////////////////////////////////////


BOOL isNT4 (void)
{
    OSVERSIONINFO OSversion;

    OSversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    ::GetVersionEx(&OSversion);

    switch (OSversion.dwPlatformId)
    {
    case VER_PLATFORM_WIN32s:
    case VER_PLATFORM_WIN32_WINDOWS:
        return FALSE;
    case VER_PLATFORM_WIN32_NT:
        if (OSversion.dwMajorVersion == 4)
            return TRUE;
        else return FALSE;
    default:
        break;
    }
    return FALSE;
}

int main (int argc, char **argv)
{
    int rc = 0;

    /* This program is only for installing drivers on NT4 */
    if (!isNT4())
    {
        printf("This program only runs on NT4\n");
        return -1;
    }

    /* Delete the "InvalidDisplay" key which causes the display
     applet to be started on every boot. For some reason this key
     isn't removed after setting the proper resolution and even not when
     doing a driverreinstall.  */
    RegDeleteKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\InvalidDisplay"));
    RegDeleteKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\NewDisplay"));

    return rc;
}
