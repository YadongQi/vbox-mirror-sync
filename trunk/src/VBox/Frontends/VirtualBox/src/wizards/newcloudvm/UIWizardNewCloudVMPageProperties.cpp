/* $Id$ */
/** @file
 * VBox Qt GUI - UIWizardNewCloudVMPageProperties class implementation.
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
#include <QHeaderView>
#include <QVBoxLayout>

/* GUI includes: */
#include "QIRichTextLabel.h"
#include "UIFormEditorWidget.h"
#include "UIMessageCenter.h"
#include "UIWizardNewCloudVM.h"
#include "UIWizardNewCloudVMPageProperties.h"

/* Namespaces: */
using namespace UIWizardNewCloudVMProperties;


/*********************************************************************************************************************************
*   Namespace UIWizardNewCloudVMProperties implementation.                                                                       *
*********************************************************************************************************************************/

void UIWizardNewCloudVMProperties::refreshFormPropertiesTable(UIFormEditorWidget *pFormEditor,
                                                              const CVirtualSystemDescriptionForm &comForm)
{
    /* Sanity check: */
    AssertPtrReturnVoid(pFormEditor);
    AssertReturnVoid(comForm.isNotNull());

    /* Make sure the properties table get the new description form: */
    pFormEditor->setVirtualSystemDescriptionForm(comForm);
}


/*********************************************************************************************************************************
*   Class UIWizardNewCloudVMPageProperties implementation.                                                                       *
*********************************************************************************************************************************/

UIWizardNewCloudVMPageProperties::UIWizardNewCloudVMPageProperties()
    : m_pLabel(0)
    , m_pFormEditor(0)
{
    /* Prepare main layout: */
    QVBoxLayout *pLayoutMain = new QVBoxLayout(this);
    if (pLayoutMain)
    {
        /* Prepare label: */
        m_pLabel = new QIRichTextLabel(this);
        if (m_pLabel)
            pLayoutMain->addWidget(m_pLabel);

        /* Prepare form editor widget: */
        m_pFormEditor = new UIFormEditorWidget(this);
        if (m_pFormEditor)
        {
            /* Make form-editor fit 8 sections in height by default: */
            const int iDefaultSectionHeight = m_pFormEditor->verticalHeader()
                                            ? m_pFormEditor->verticalHeader()->defaultSectionSize()
                                            : 0;
            if (iDefaultSectionHeight > 0)
                m_pFormEditor->setMinimumHeight(8 * iDefaultSectionHeight);

            /* Add into layout: */
            pLayoutMain->addWidget(m_pFormEditor);
        }
    }

    /* Setup connections: */
    connect(m_pFormEditor, &UIFormEditorWidget::sigProgressStarted,
            this, &UIWizardNewCloudVMPageProperties::sigProgressStarted);
    connect(m_pFormEditor, &UIFormEditorWidget::sigProgressChange,
            this, &UIWizardNewCloudVMPageProperties::sigProgressChange);
    connect(m_pFormEditor, &UIFormEditorWidget::sigProgressFinished,
            this, &UIWizardNewCloudVMPageProperties::sigProgressFinished);
}

UIWizardNewCloudVM *UIWizardNewCloudVMPageProperties::wizard() const
{
    return qobject_cast<UIWizardNewCloudVM*>(UINativeWizardPage::wizard());
}

void UIWizardNewCloudVMPageProperties::retranslateUi()
{
    /* Translate page: */
    setTitle(UIWizardNewCloudVM::tr("Cloud Virtual Machine settings"));

    /* Translate description label: */
    m_pLabel->setText(UIWizardNewCloudVM::tr("These are the the suggested settings of the cloud VM creation procedure, they are "
                                             "influencing the resulting cloud VM instance.  You can change many of the "
                                             "properties shown by double-clicking on the items and disable others using the "
                                             "check boxes below."));
}

void UIWizardNewCloudVMPageProperties::initializePage()
{
    /* Generate VSD form, asynchronously: */
    QMetaObject::invokeMethod(this, "sltInitShortWizardForm", Qt::QueuedConnection);
}

bool UIWizardNewCloudVMPageProperties::isComplete() const
{
    /* Initial result: */
    bool fResult = true;

    /* Check cloud settings: */
    fResult =    wizard()->client().isNotNull()
              && wizard()->vsd().isNotNull();

    /* Return result: */
    return fResult;
}

bool UIWizardNewCloudVMPageProperties::validatePage()
{
    /* Initial result: */
    bool fResult = true;

    /* Make sure table has own data committed: */
    m_pFormEditor->makeSureEditorDataCommitted();

    /* Check whether we have proper VSD form: */
    CVirtualSystemDescriptionForm comForm = wizard()->vsdForm();
    /* Give changed VSD back: */
    if (comForm.isNotNull())
    {
        comForm.GetVirtualSystemDescription();
        fResult = comForm.isOk();
        if (!fResult)
            msgCenter().cannotAcquireVirtualSystemDescriptionFormProperty(comForm);
    }

    /* Try to create cloud VM: */
    if (fResult)
    {
        fResult = wizard()->createCloudVM();

        /* If the final step failed we could try
         * sugest user more valid form this time: */
        if (!fResult)
        {
            wizard()->setVSDForm(CVirtualSystemDescriptionForm());
            sltInitShortWizardForm();
        }
    }

    /* Return result: */
    return fResult;
}

void UIWizardNewCloudVMPageProperties::sltInitShortWizardForm()
{
    /* Create Virtual System Description Form: */
    if (wizard()->vsdForm().isNull())
        wizard()->createVSDForm();

    /* Refresh form properties table: */
    refreshFormPropertiesTable(m_pFormEditor, wizard()->vsdForm());
    emit completeChanged();
}
