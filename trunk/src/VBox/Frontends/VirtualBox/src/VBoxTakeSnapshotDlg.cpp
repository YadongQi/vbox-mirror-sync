/* $Id$ */
/** @file
 *
 * VBox frontends: Qt4 GUI ("VirtualBox"):
 * VBoxTakeSnapshotDlg class implementation
 */

/*
 * Copyright (C) 2006-2009 Sun Microsystems, Inc.
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

#ifdef VBOX_WITH_PRECOMPILED_HEADERS
# include "precomp.h"
#else  /* !VBOX_WITH_PRECOMPILED_HEADERS */
/* Global includes */
#include <QPushButton>

/* Local includes */
#include "VBoxTakeSnapshotDlg.h"
#include "VBoxProblemReporter.h"
#include "VBoxUtils.h"
#endif /* !VBOX_WITH_PRECOMPILED_HEADERS */

VBoxTakeSnapshotDlg::VBoxTakeSnapshotDlg(QWidget *pParent, const CMachine &machine)
    : QIWithRetranslateUI<QDialog>(pParent)
{
    /* Apply UI decorations */
    Ui::VBoxTakeSnapshotDlg::setupUi(this);

    /* Alt key filter */
    QIAltKeyFilter *altKeyFilter = new QIAltKeyFilter(this);
    altKeyFilter->watchOn(mLeName);

    /* Setup connections */
    connect (mButtonBox, SIGNAL(helpRequested()), &vboxProblem(), SLOT(showHelpHelpDialog()));
    connect (mLeName, SIGNAL(textChanged(const QString &)), this, SLOT(nameChanged(const QString &)));

    /* Check if machine have immutable attachments */
    int immutableMediums = 0;

    if (machine.GetState() == KMachineState_Paused)
    {
        foreach (const CMediumAttachment &attachment, machine.GetMediumAttachments())
        {
            CMedium medium = attachment.GetMedium();
            if (!medium.isNull() && !medium.GetParent().isNull() && medium.GetBase().GetType() == KMediumType_Immutable)
                ++ immutableMediums;
        }
    }

    if (immutableMediums)
    {
        mLbInfo->setText(tr("Warning: You are taking a snapshot of a running machine which has %n immutable image(s) "
                            "attached to it. As long as you are working from this snapshot the immutable image(s) "
                            "will not be reset to avoid loss of data.", "",
                            immutableMediums));
        mLbInfo->useSizeHintForWidth(400);
    }
    else
    {
        QGridLayout *lt = qobject_cast<QGridLayout*>(layout());
        lt->removeWidget (mLbInfo);
        mLbInfo->setHidden (true);

        lt->removeWidget (mButtonBox);
        lt->addWidget (mButtonBox, 2, 0, 1, 2);
    }

    retranslateUi();
}

void VBoxTakeSnapshotDlg::retranslateUi()
{
    /* Translate uic generated strings */
    Ui::VBoxTakeSnapshotDlg::retranslateUi(this);
}

void VBoxTakeSnapshotDlg::nameChanged(const QString &strName)
{
    mButtonBox->button(QDialogButtonBox::Ok)->setEnabled(!strName.trimmed().isEmpty());
}

