/* $Id$ */
/** @file
 * AudioTestService - Audio test execution server, Public Header.
 */

/*
 * Copyright (C) 2021 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef VBOX_INCLUDED_SRC_Audio_AudioTestService_h
#define VBOX_INCLUDED_SRC_Audio_AudioTestService_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

#include "AudioTestServiceInternal.h"

int AudioTestSvcInit(void);
int AudioTestSvcStart(void);

#endif /* !VBOX_INCLUDED_SRC_Audio_AudioTestService_h */

