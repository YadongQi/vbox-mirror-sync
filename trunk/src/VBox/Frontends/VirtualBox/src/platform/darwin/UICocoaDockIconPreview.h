/* $Id$ */
/** @file
 * VBox Qt GUI - UICocoaDockIconPreview class declaration.
 */

/*
 * Copyright (C) 2009-2023 Oracle and/or its affiliates.
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

#ifndef FEQT_INCLUDED_SRC_platform_darwin_UICocoaDockIconPreview_h
#define FEQT_INCLUDED_SRC_platform_darwin_UICocoaDockIconPreview_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

/* Qt includes */
#include "UIAbstractDockIconPreview.h"

class UICocoaDockIconPreviewPrivate;

class UICocoaDockIconPreview: public UIAbstractDockIconPreview
{
public:
    UICocoaDockIconPreview(UISession *pSession, const QPixmap& overlayImage);
    ~UICocoaDockIconPreview();

    virtual void updateDockOverlay();
    virtual void updateDockPreview(CGImageRef VMImage);
    virtual void updateDockPreview(UIFrameBuffer *pFrameBuffer);

    virtual void setOriginalSize(int aWidth, int aHeight);

private:
    UICocoaDockIconPreviewPrivate *d;
};

#endif /* !FEQT_INCLUDED_SRC_platform_darwin_UICocoaDockIconPreview_h */

