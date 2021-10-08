/* $Id$ */
/** @file
 * VBox Qt GUI - UIWizardImportAppPageBasic2 class declaration.
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

#ifndef FEQT_INCLUDED_SRC_wizards_importappliance_UIWizardImportAppPageBasic2_h
#define FEQT_INCLUDED_SRC_wizards_importappliance_UIWizardImportAppPageBasic2_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

/* GUI includes: */
#include "UINativeWizardPage.h"
#include "UIWizardImportApp.h"

/* Forward declarations: */
class QCheckBox;
class QIComboBox;
class QLabel;
class QStackedWidget;
class QIRichTextLabel;
class UIApplianceImportEditorWidget;
class UIFilePathSelector;
class UIFormEditorWidget;

/** Certificate text template types. */
enum kCertText
{
    kCertText_Uninitialized = 0,
    kCertText_Unsigned,
    kCertText_IssuedTrusted,
    kCertText_IssuedExpired,
    kCertText_IssuedUnverified,
    kCertText_SelfSignedTrusted,
    kCertText_SelfSignedExpired,
    kCertText_SelfSignedUnverified
};

/** Namespace for 2nd basic page of the Import Appliance wizard. */
namespace UIWizardImportAppPage2
{
    /** Refresh stacked widget. */
    void refreshStackedWidget(QStackedWidget *pStackedWidget,
                              bool fIsSourceCloudOne);

    /** Refreshes appliance widget. */
    void refreshApplianceWidget(UIApplianceImportEditorWidget *pApplianceWidget,
                                const CAppliance &comAppliance,
                                bool fIsSourceCloudOne);
    /** Refresh MAC address import policies. */
    void refreshMACAddressImportPolicies(QIComboBox *pCombo,
                                         bool fIsSourceCloudOne);

    /** Refreshes form properties table. */
    void refreshFormPropertiesTable(UIFormEditorWidget *pFormEditor,
                                    const CVirtualSystemDescriptionForm &comForm,
                                    bool fIsSourceCloudOne);

    /** Returns MAC address import policy. */
    MACAddressImportPolicy macAddressImportPolicy(QIComboBox *pCombo);
    /** Returns whether hard disks should be imported as VDIs. */
    bool isImportHDsAsVDI(QCheckBox *pCheckBox);

    /** Translates MAC import policy combo. */
    void retranslateMACImportPolicyCombo(QIComboBox *pCombo);
    /** Translates certificate label. */
    void retranslateCertificateLabel(QLabel *pLabel, const kCertText &enmType, const QString &strSignedBy);

    /** Updates MAC import policy combo tool-tips. */
    void updateMACImportPolicyComboToolTip(QIComboBox *pCombo);
}

/** UINativeWizardPage extension for 2nd basic page of the Import Appliance wizard,
  * based on UIWizardImportAppPage2 namespace functions. */
class UIWizardImportAppPageBasic2 : public UINativeWizardPage
{
    Q_OBJECT;

public:

    /** Constructs 2nd basic page.
      * @param  strFileName  Brings appliance file name. */
    UIWizardImportAppPageBasic2(const QString &strFileName);

protected:

    /** Returns wizard this page belongs to. */
    UIWizardImportApp *wizard() const;

    /** Handles translation event. */
    virtual void retranslateUi() /* override final */;

    /** Performs page initialization. */
    virtual void initializePage() /* override final */;

    /** Performs page validation. */
    virtual bool validatePage() /* override final */;

private slots:

    /** Inits page async way. */
    void sltAsyncInit();

    /** Handles import path editor change. */
    void sltHandleImportPathEditorChange();
    /** Handles MAC address import policy combo change. */
    void sltHandleMACImportPolicyComboChange();
    /** Handles import HDs as VDI check-box change. */
    void sltHandleImportHDsAsVDICheckBoxChange();

private:

    /** Handles appliance certificate. */
    void handleApplianceCertificate();

    /** Handles the appliance file name. */
    QString  m_strFileName;

    /** Holds the description label instance. */
    QIRichTextLabel *m_pLabelDescription;

    /** Holds the settings widget 2 instance. */
    QStackedWidget *m_pSettingsWidget2;

    /** Holds the appliance widget instance. */
    UIApplianceImportEditorWidget *m_pApplianceWidget;
    /** Holds the import file-path label instance. */
    QLabel                        *m_pLabelImportFilePath;
    /** Holds the import file-path editor instance. */
    UIFilePathSelector            *m_pEditorImportFilePath;
    /** Holds the MAC address label instance. */
    QLabel                        *m_pLabelMACImportPolicy;
    /** Holds the MAC address combo instance. */
    QIComboBox                    *m_pComboMACImportPolicy;
    /** Holds the additional options label instance. */
    QLabel                        *m_pLabelAdditionalOptions;
    /** Holds the 'import HDs as VDI' checkbox instance. */
    QCheckBox                     *m_pCheckboxImportHDsAsVDI;
    /** Holds the signature/certificate info label instance. */
    QLabel                        *m_pCertLabel;

    /** Holds the certificate text template type. */
    kCertText  m_enmCertText;

    /** Holds the "signed by" information. */
    QString  m_strSignedBy;

    /** Holds the Form Editor widget instance. */
    UIFormEditorWidget *m_pFormEditor;
};

#endif /* !FEQT_INCLUDED_SRC_wizards_importappliance_UIWizardImportAppPageBasic2_h */
