/* $Id$ */
/** @file
 * VBox Qt GUI - UIWizardExportAppPageBasic1 class implementation.
 */

/*
 * Copyright (C) 2009-2021 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

/* Qt includes: */
#include <QListWidget>
#include <QVBoxLayout>

/* GUI includes: */
#include "QIRichTextLabel.h"
#include "UICommon.h"
#include "UIIconPool.h"
#include "UIMessageCenter.h"
#include "UIWizardExportApp.h"
#include "UIWizardExportAppPageBasic1.h"

/* COM includes: */
#include "CMachine.h"

/* Namespaces: */
using namespace UIWizardExportAppPage1;


/** QListWidgetItem subclass for Export Appliance wizard VM list. */
class UIVMListWidgetItem : public QListWidgetItem
{
public:

    /** Constructs VM list item passing @a pixIcon, @a strText and @a pParent to the base-class.
      * @param  strUuid       Brings the machine ID.
      * @param  fInSaveState  Brings whether machine is in Saved state. */
    UIVMListWidgetItem(QPixmap &pixIcon, QString &strText, QUuid uUuid, bool fInSaveState, QListWidget *pParent)
        : QListWidgetItem(pixIcon, strText, pParent)
        , m_uUuid(uUuid)
        , m_fInSaveState(fInSaveState)
    {}

    /** Returns whether this item is less than @a other. */
    bool operator<(const QListWidgetItem &other) const
    {
        return text().toLower() < other.text().toLower();
    }

    /** Returns the machine ID. */
    QUuid uuid() const { return m_uUuid; }
    /** Returns whether machine is in Saved state. */
    bool isInSaveState() const { return m_fInSaveState; }

private:

    /** Holds the machine ID. */
    QUuid  m_uUuid;
    /** Holds whether machine is in Saved state. */
    bool   m_fInSaveState;
};


/*********************************************************************************************************************************
*   Class UIWizardExportAppPage1 implementation.                                                                                 *
*********************************************************************************************************************************/

void UIWizardExportAppPage1::populateVMItems(QListWidget *pVMSelector, const QStringList &selectedVMNames)
{
    /* Add all VM items into VM selector: */
    foreach (const CMachine &comMachine, uiCommon().virtualBox().GetMachines())
    {
        QPixmap pixIcon;
        QString strName;
        QUuid uUuid;
        bool fInSaveState = false;
        bool fEnabled = false;
        const int iIconMetric = QApplication::style()->pixelMetric(QStyle::PM_SmallIconSize);
        if (comMachine.GetAccessible())
        {
            pixIcon = generalIconPool().userMachinePixmapDefault(comMachine);
            if (pixIcon.isNull())
                pixIcon = generalIconPool().guestOSTypePixmapDefault(comMachine.GetOSTypeId());
            strName = comMachine.GetName();
            uUuid = comMachine.GetId();
            fEnabled = comMachine.GetSessionState() == KSessionState_Unlocked;
            fInSaveState = comMachine.GetState() == KMachineState_Saved || comMachine.GetState() == KMachineState_AbortedSaved;
        }
        else
        {
            QFileInfo fi(comMachine.GetSettingsFilePath());
            strName = UICommon::hasAllowedExtension(fi.completeSuffix(), VBoxFileExts) ? fi.completeBaseName() : fi.fileName();
            pixIcon = QPixmap(":/os_other.png").scaled(iIconMetric, iIconMetric, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        }
        QListWidgetItem *pItem = new UIVMListWidgetItem(pixIcon, strName, uUuid, fInSaveState, pVMSelector);
        if (!fEnabled)
            pItem->setFlags(Qt::ItemFlags());
        pVMSelector->addItem(pItem);
    }
    pVMSelector->sortItems();

    /* Choose initially selected items (if passed): */
    foreach (const QString &strSelectedVMName, selectedVMNames)
    {
        const QList<QListWidgetItem*> list = pVMSelector->findItems(strSelectedVMName, Qt::MatchExactly);
        if (list.size() > 0)
        {
            if (pVMSelector->selectedItems().isEmpty())
                pVMSelector->setCurrentItem(list.first());
            else
                list.first()->setSelected(true);
        }
    }
}

void UIWizardExportAppPage1::refreshSavedMachines(QStringList &savedMachines, QListWidget *pVMSelector)
{
    savedMachines.clear();
    foreach (QListWidgetItem *pItem, pVMSelector->selectedItems())
        if (static_cast<UIVMListWidgetItem*>(pItem)->isInSaveState())
            savedMachines << pItem->text();
}

QStringList UIWizardExportAppPage1::machineNames(QListWidget *pVMSelector)
{
    /* Prepare list: */
    QStringList names;
    /* Iterate over all the selected items: */
    foreach (QListWidgetItem *pItem, pVMSelector->selectedItems())
        names << pItem->text();
    /* Return result list: */
    return names;
}

QList<QUuid> UIWizardExportAppPage1::machineIDs(QListWidget *pVMSelector)
{
    /* Prepare list: */
    QList<QUuid> ids;
    /* Iterate over all the selected items: */
    foreach (QListWidgetItem *pItem, pVMSelector->selectedItems())
        ids.append(static_cast<UIVMListWidgetItem*>(pItem)->uuid());
    /* Return result list: */
    return ids;
}


/*********************************************************************************************************************************
*   Class UIWizardExportAppPageBasic1 implementation.                                                                            *
*********************************************************************************************************************************/

UIWizardExportAppPageBasic1::UIWizardExportAppPageBasic1(const QStringList &selectedVMNames, bool fFastTravelToNextPage)
    : m_selectedVMNames(selectedVMNames)
    , m_fFastTravelToNextPage(fFastTravelToNextPage)
    , m_pLabelMain(0)
    , m_pVMSelector(0)
{
    /* Prepare main layout: */
    QVBoxLayout *pLayoutMain = new QVBoxLayout(this);
    if (pLayoutMain)
    {
        /* Prepare main label: */
        m_pLabelMain = new QIRichTextLabel(this);
        if (m_pLabelMain)
            pLayoutMain->addWidget(m_pLabelMain);

        /* Prepare VM selector: */
        m_pVMSelector = new QListWidget(this);
        if (m_pVMSelector)
        {
            m_pVMSelector->setAlternatingRowColors(true);
            m_pVMSelector->setSelectionMode(QAbstractItemView::ExtendedSelection);
            pLayoutMain->addWidget(m_pVMSelector);
        }
    }

    /* Setup connections: */
    connect(m_pVMSelector, &QListWidget::itemSelectionChanged,
            this, &UIWizardExportAppPageBasic1::sltHandleVMItemSelectionChanged);
}

UIWizardExportApp *UIWizardExportAppPageBasic1::wizard() const
{
    return qobject_cast<UIWizardExportApp*>(UINativeWizardPage::wizard());
}

void UIWizardExportAppPageBasic1::retranslateUi()
{
    /* Translate page: */
    setTitle(UIWizardExportApp::tr("Virtual machines to export"));

    /* Translate widgets: */
    m_pLabelMain->setText(UIWizardExportApp::tr("<p>Please select the virtual machines that should be added to the appliance. "
                                                "You can select more than one. Please note that these machines have to be "
                                                "turned off before they can be exported.</p>"));
}

void UIWizardExportAppPageBasic1::initializePage()
{
    /* Populate VM items: */
    populateVMItems(m_pVMSelector, m_selectedVMNames);
    /* Translate page: */
    retranslateUi();

    /* Now, when we are ready, we can
     * fast traver to page 2 if requested: */
    if (m_fFastTravelToNextPage)
        wizard()->goForward();
}

bool UIWizardExportAppPageBasic1::isComplete() const
{
    /* Initial result: */
    bool fResult = true;

    /* There should be at least one VM selected: */
    fResult = wizard()->machineNames().size() > 0;

    /* Return result: */
    return fResult;
}

bool UIWizardExportAppPageBasic1::validatePage()
{
    /* Initial result: */
    bool fResult = true;

    /* Ask user about machines which are in Saved state currently: */
    QStringList savedMachines;
    refreshSavedMachines(savedMachines, m_pVMSelector);
    if (!savedMachines.isEmpty())
        fResult = msgCenter().confirmExportMachinesInSaveState(savedMachines, this);

    /* Return result: */
    return fResult;
}

void UIWizardExportAppPageBasic1::sltHandleVMItemSelectionChanged()
{
    /* Update wizard fields: */
    wizard()->setMachineNames(machineNames(m_pVMSelector));
    wizard()->setMachineIDs(machineIDs(m_pVMSelector));

    /* Notify about changes: */
    emit completeChanged();
}
