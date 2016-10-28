/* $Id$ */
/** @file
 * VBox Qt GUI - VirtualBox Qt extensions: QITreeView class implementation.
 */

/*
 * Copyright (C) 2009-2016 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifdef VBOX_WITH_PRECOMPILED_HEADERS
# include <precomp.h>
#else  /* !VBOX_WITH_PRECOMPILED_HEADERS */

/* Qt includes: */
# include <QMouseEvent>
# include <QPainter>

/* GUI includes: */
# include "QITreeView.h"

#endif /* !VBOX_WITH_PRECOMPILED_HEADERS */


/*********************************************************************************************************************************
*   Class QITreeViewItem implementation.                                                                                         *
*********************************************************************************************************************************/

QRect QITreeViewItem::rect() const
{
    /* Redirect call to parent-tree: */
    return parentTree() ? parentTree()->visualRect(modelIndex()) : QRect();
}

QModelIndex QITreeViewItem::modelIndex() const
{
    /* Make sure it's not root model-index: */
    if (   parentTree()->rootIndex().internalPointer()
        && parentTree()->rootIndex().internalPointer() == this)
        return parentTree()->rootIndex();

    /* Determine our index inside parent: */
    int iIndexInParent = -1;
    if (parentItem())
    {
        for (int i = 0; i < parentItem()->childCount(); ++i)
            if (parentItem()->childItem(i) == this)
            {
                iIndexInParent = i;
                break;
            }
    }
    else
    {
        for (int i = 0; i < parentTree()->childCount(); ++i)
            if (parentTree()->childItem(i) == this)
            {
                iIndexInParent = i;
                break;
            }
    }
    if (iIndexInParent == -1)
        return QModelIndex();

    /* Get parent model-index: */
    QModelIndex parentModelIndex = parentItem() ? parentItem()->modelIndex() : parentTree()->rootIndex();

    /* Return model-index as child of parent model-index: */
    return parentModelIndex.child(iIndexInParent, 0);
}


/*********************************************************************************************************************************
*   Class QITreeView implementation.                                                                                             *
*********************************************************************************************************************************/

QITreeView::QITreeView(QWidget *pParent)
    : QTreeView(pParent)
{
    /* Prepare all: */
    prepare();
}

void QITreeView::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    /* Notify listeners about it: */
    emit currentItemChanged(current, previous);
    /* Call to base-class: */
    QTreeView::currentChanged(current, previous);
}

void QITreeView::drawBranches(QPainter *pPainter, const QRect &rect, const QModelIndex &index) const
{
    /* Notify listeners about it: */
    emit drawItemBranches(pPainter, rect, index);
    /* Call to base-class: */
    QTreeView::drawBranches(pPainter, rect, index);
}

void QITreeView::mouseMoveEvent(QMouseEvent *pEvent)
{
    /* Reject event initially: */
    pEvent->setAccepted(false);
    /* Notify listeners about event allowing them to handle it: */
    emit mouseMoved(pEvent);
    /* Call to base-class only if event was not yet accepted: */
    if (!pEvent->isAccepted())
        QTreeView::mouseMoveEvent(pEvent);
}

void QITreeView::mousePressEvent(QMouseEvent *pEvent)
{
    /* Reject event initially: */
    pEvent->setAccepted(false);
    /* Notify listeners about event allowing them to handle it: */
    emit mousePressed(pEvent);
    /* Call to base-class only if event was not yet accepted: */
    if (!pEvent->isAccepted())
        QTreeView::mousePressEvent(pEvent);
}

void QITreeView::mouseDoubleClickEvent(QMouseEvent *pEvent)
{
    /* Reject event initially: */
    pEvent->setAccepted(false);
    /* Notify listeners about event allowing them to handle it: */
    emit mouseDoubleClicked(pEvent);
    /* Call to base-class only if event was not yet accepted: */
    if (!pEvent->isAccepted())
        QTreeView::mouseDoubleClickEvent(pEvent);
}

void QITreeView::prepare()
{
    /* Mark header hidden: */
    setHeaderHidden(true);
    /* Mark root hidden: */
    setRootIsDecorated(false);
}

