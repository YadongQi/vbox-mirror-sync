/** @file
 *
 * VBox frontends: Qt4 GUI ("VirtualBox"):
 * UIWizardNewVMPageBasic2 class declaration
 */

/*
 * Copyright (C) 2006-2012 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef __UIWizardNewVMPageBasic2_h__
#define __UIWizardNewVMPageBasic2_h__

/* Local includes: */
#include "UIWizardPage.h"

/* Forward declarations: */
class QIRichTextLabel;
class QGroupBox;
class QLineEdit;
class VBoxOSTypeSelectorWidget;

/* 2nd page of the New Virtual Machine wizard: */
class UIWizardNewVMPageBasic2 : public UIWizardPage
{
    Q_OBJECT;
    Q_PROPERTY(QString machineFolder READ machineFolder WRITE setMachineFolder);
    Q_PROPERTY(QString machineBaseName READ machineBaseName WRITE setMachineBaseName);

public:

    /* Constructor: */
    UIWizardNewVMPageBasic2();

private slots:

    /* Handlers: */
    void sltNameChanged(const QString &strNewText);
    void sltOsTypeChanged();

private:

    /* Translation stuff: */
    void retranslateUi();

    /* Prepare stuff: */
    void initializePage();
    void cleanupPage();

    /* Validation stuff: */
    bool validatePage();

    /* Helping stuff: */
    bool machineFolderCreated();
    bool createMachineFolder();
    bool cleanupMachineFolder();

    /* Stuff for 'machineFolder' field: */
    QString machineFolder() const;
    void setMachineFolder(const QString &strMachineFolder);
    QString m_strMachineFolder;

    /* Stuff for 'machineBaseName' field: */
    QString machineBaseName() const;
    void setMachineBaseName(const QString &strMachineBaseName);
    QString m_strMachineBaseName;

    /* Widgets: */
    QIRichTextLabel *m_pLabel;
    QGroupBox *m_pNameEditorCnt;
    QLineEdit *m_pNameEditor;
    QGroupBox *m_pTypeSelectorCnt;
    VBoxOSTypeSelectorWidget *m_pTypeSelector;
};

#endif // __UIWizardNewVMPageBasic2_h__

