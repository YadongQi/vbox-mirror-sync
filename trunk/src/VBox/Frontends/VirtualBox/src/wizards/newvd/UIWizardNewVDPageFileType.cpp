/* $Id$ */
/** @file
 * VBox Qt GUI - UIWizardNewVDPageFileType class implementation.
 */

/*
 * Copyright (C) 2006-2020 Oracle Corporation
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
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>

/* GUI includes: */
#include "UIConverter.h"
#include "UIWizardDiskEditors.h"
#include "UIWizardNewVDPageFileType.h"
#include "UIWizardNewVDPageSizeLocation.h"
#include "UIWizardNewVD.h"
#include "UICommon.h"
#include "QIRichTextLabel.h"

/* COM includes: */
#include "CSystemProperties.h"

// UIWizardNewVDPageBaseFileType::UIWizardNewVDPageBaseFileType()
//     : m_pFormatButtonGroup(0)
// {
// }

// void UIWizardNewVDPageBaseFileType::addFormatButton(QWidget *pParent, QVBoxLayout *pFormatLayout, CMediumFormat medFormat, bool fPreferred /* = false */)
// {
//     /* Check that medium format supports creation: */
//     ULONG uFormatCapabilities = 0;
//     QVector<KMediumFormatCapabilities> capabilities;
//     capabilities = medFormat.GetCapabilities();
//     for (int i = 0; i < capabilities.size(); i++)
//         uFormatCapabilities |= capabilities[i];

//     if (!(uFormatCapabilities & KMediumFormatCapabilities_CreateFixed ||
//           uFormatCapabilities & KMediumFormatCapabilities_CreateDynamic))
//         return;

//     /* Check that medium format supports creation of virtual hard-disks: */
//     QVector<QString> fileExtensions;
//     QVector<KDeviceType> deviceTypes;
//     medFormat.DescribeFileExtensions(fileExtensions, deviceTypes);
//     if (!deviceTypes.contains(KDeviceType_HardDisk))
//         return;

//     /* Create/add corresponding radio-button: */
//     QRadioButton *pFormatButton = new QRadioButton(pParent);
//     AssertPtrReturnVoid(pFormatButton);
//     {
//         /* Make the preferred button font bold: */
//         if (fPreferred)
//         {
//             QFont font = pFormatButton->font();
//             font.setBold(true);
//             pFormatButton->setFont(font);
//         }
//         pFormatLayout->addWidget(pFormatButton);
//         m_formats << medFormat;
//         m_formatNames << medFormat.GetName();
//         m_pFormatButtonGroup->addButton(pFormatButton, m_formatNames.size() - 1);
//         m_formatExtensions << UIWizardNewVDPageBaseSizeLocation::defaultExtension(medFormat);
//     }
// }


// CMediumFormat UIWizardNewVDPageBaseFileType::mediumFormat() const
// {
//     return m_pFormatButtonGroup && m_pFormatButtonGroup->checkedButton() ? m_formats[m_pFormatButtonGroup->checkedId()] : CMediumFormat();
// }

// void UIWizardNewVDPageBaseFileType::setMediumFormat(const CMediumFormat &mediumFormat)
// {
//     int iPosition = m_formats.indexOf(mediumFormat);
//     if (iPosition >= 0)
//     {
//         m_pFormatButtonGroup->button(iPosition)->click();
//         m_pFormatButtonGroup->button(iPosition)->setFocus();
//     }
// }

// void UIWizardNewVDPageBaseFileType::retranslateWidgets()
// {
//     if (m_pFormatButtonGroup)
//     {
//         QList<QAbstractButton*> buttons = m_pFormatButtonGroup->buttons();
//         for (int i = 0; i < buttons.size(); ++i)
//         {
//             QAbstractButton *pButton = buttons[i];
//             UIMediumFormat enmFormat = gpConverter->fromInternalString<UIMediumFormat>(m_formatNames[m_pFormatButtonGroup->id(pButton)]);
//             pButton->setText(gpConverter->toString(enmFormat));
//         }
//     }
// }

UIWizardNewVDPageFileType::UIWizardNewVDPageFileType()
    : m_pLabel(0)
    , m_pFormatButtonGroup(0)
{
    prepare();
    /* Create widgets: */

    // /* Setup connections: */
    // connect(m_pFormatButtonGroup, static_cast<void(QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked),
    //         this, &UIWizardNewVDPageFileType::completeChanged);

    // /* Register classes: */
    // qRegisterMetaType<CMediumFormat>();
    // /* Register fields: */
    // registerField("mediumFormat", this, "mediumFormat");
}

void UIWizardNewVDPageFileType::prepare()
{
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
    m_pLabel = new QIRichTextLabel(this);
    pMainLayout->addWidget(m_pLabel);
    m_pFormatButtonGroup = new UIDiskFormatsGroupBox(false, 0);
    pMainLayout->addWidget(m_pFormatButtonGroup, false);

    pMainLayout->addStretch();
    retranslateUi();
}

void UIWizardNewVDPageFileType::retranslateUi()
{
    setTitle(UIWizardNewVD::tr("Virtual Hard disk file type"));

    m_pLabel->setText(UIWizardNewVD::tr("Please choose the type of file that you would like to use "
                                        "for the new virtual hard disk. If you do not need to use it "
                                        "with other virtualization software you can leave this setting unchanged."));
}

void UIWizardNewVDPageFileType::initializePage()
{
    /* Translate page: */
    retranslateUi();
}

bool UIWizardNewVDPageFileType::isComplete() const
{
    /* Make sure medium format is correct: */
    //return !mediumFormat().isNull();
    return true;
}

// int UIWizardNewVDPageFileType::nextId() const
// {
//     /* Show variant page only if there is something to show: */
//     CMediumFormat mf = mediumFormat();
//     if (mf.isNull())
//     {
//         AssertMsgFailed(("No medium format set!"));
//     }
//     else
//     {
//         ULONG uCapabilities = 0;
//         QVector<KMediumFormatCapabilities> capabilities;
//         capabilities = mf.GetCapabilities();
//         for (int i = 0; i < capabilities.size(); i++)
//             uCapabilities |= capabilities[i];

//         int cTest = 0;
//         if (uCapabilities & KMediumFormatCapabilities_CreateDynamic)
//             ++cTest;
//         if (uCapabilities & KMediumFormatCapabilities_CreateFixed)
//             ++cTest;
//         if (uCapabilities & KMediumFormatCapabilities_CreateSplit2G)
//             ++cTest;
//         if (cTest > 1)
//             return UIWizardNewVD::Page2;
//     }
//     /* Skip otherwise: */
//     return UIWizardNewVD::Page3;
// }
