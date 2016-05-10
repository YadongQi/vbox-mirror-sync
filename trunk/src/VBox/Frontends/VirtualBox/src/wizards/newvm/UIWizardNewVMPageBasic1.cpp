/* $Id$ */
/** @file
 * VBox Qt GUI - UIWizardNewVMPageBasic1 class implementation.
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

#ifdef VBOX_WITH_PRECOMPILED_HEADERS
# include <precomp.h>
#else  /* !VBOX_WITH_PRECOMPILED_HEADERS */

/* Qt includes: */
# include <QDir>
# include <QVBoxLayout>
# include <QHBoxLayout>
# include <QLineEdit>

/* GUI includes: */
# include "UIWizardNewVMPageBasic1.h"
# include "UIWizardNewVM.h"
# include "UIMessageCenter.h"
# include "UINameAndSystemEditor.h"
# include "UIFilePathSelector.h"
# include "QIRichTextLabel.h"

/* COM includes: */
# include "CSystemProperties.h"

#endif /* !VBOX_WITH_PRECOMPILED_HEADERS */


/* Defines some patterns to guess the right OS type. Should be in sync with
 * VirtualBox-settings-common.xsd in Main. The list is sorted by priority. The
 * first matching string found, will be used. */
struct osTypePattern
{
    QRegExp pattern;
    const char *pcstId;
};

static const osTypePattern gs_OSTypePattern[] =
{
    /* DOS: */
    { QRegExp("DOS", Qt::CaseInsensitive), "DOS" },

    /* Windows: */
    { QRegExp(  "Wi.*98",                         Qt::CaseInsensitive), "Windows98" },
    { QRegExp(  "Wi.*95",                         Qt::CaseInsensitive), "Windows95" },
    { QRegExp(  "Wi.*Me",                         Qt::CaseInsensitive), "WindowsMe" },
    { QRegExp( "(Wi.*NT)|(NT4)",                  Qt::CaseInsensitive), "WindowsNT4" },
    /* Note: Do not automatically set WindowsXP_64 on 64-bit hosts, as Windows XP 64-bit
     *       is extremely rare -- most users never heard of it even. So always default to 32-bit. */
    { QRegExp("((Wi.*XP)|(XP)).*",                Qt::CaseInsensitive), "WindowsXP" },
    { QRegExp("((Wi.*2003)|(W2K3)|(Win2K3)).*64", Qt::CaseInsensitive), "Windows2003_64" },
    { QRegExp("((Wi.*2003)|(W2K3)|(Win2K3)).*32", Qt::CaseInsensitive), "Windows2003" },
    { QRegExp("((Wi.*Vis)|(Vista)).*64",          Qt::CaseInsensitive), "WindowsVista_64" },
    { QRegExp("((Wi.*Vis)|(Vista)).*32",          Qt::CaseInsensitive), "WindowsVista" },
    { QRegExp( "(Wi.*2012)|(W2K12)|(Win2K12)",    Qt::CaseInsensitive), "Windows2012_64" },
    { QRegExp("((Wi.*2008)|(W2K8)|(Win2k8)).*64", Qt::CaseInsensitive), "Windows2008_64" },
    { QRegExp("((Wi.*2008)|(W2K8)|(Win2K8)).*32", Qt::CaseInsensitive), "Windows2008" },
    { QRegExp( "(Wi.*2000)|(W2K)|(Win2K)",        Qt::CaseInsensitive), "Windows2000" },
    { QRegExp( "(Wi.*7.*64)|(W7.*64)",            Qt::CaseInsensitive), "Windows7_64" },
    { QRegExp( "(Wi.*7.*32)|(W7.*32)",            Qt::CaseInsensitive), "Windows7" },
    { QRegExp( "(Wi.*8.*1.*64)|(W8.*64)",         Qt::CaseInsensitive), "Windows81_64" },
    { QRegExp( "(Wi.*8.*1.*32)|(W8.*32)",         Qt::CaseInsensitive), "Windows81" },
    { QRegExp( "(Wi.*8.*64)|(W8.*64)",            Qt::CaseInsensitive), "Windows8_64" },
    { QRegExp( "(Wi.*8.*32)|(W8.*32)",            Qt::CaseInsensitive), "Windows8" },
    { QRegExp( "(Wi.*10.*64)|(W10.*64)",          Qt::CaseInsensitive), "Windows10_64" },
    { QRegExp( "(Wi.*10.*32)|(W10.*32)",          Qt::CaseInsensitive), "Windows10" },
    { QRegExp(  "Wi.*3.*1",                       Qt::CaseInsensitive), "Windows31" },
    /* Set Windows 7 as default for "Windows". */
    { QRegExp(  "Wi.*64",                         Qt::CaseInsensitive), "Windows7_64" },
    { QRegExp(  "Wi.*32",                         Qt::CaseInsensitive), "Windows7" },

    /* Solaris: */
    { QRegExp("So.*11",                                                 Qt::CaseInsensitive), "Solaris11_64" },
    { QRegExp("((Op.*So)|(os20[01][0-9])|(So.*10)|(India)|(Neva)).*64", Qt::CaseInsensitive), "OpenSolaris_64" },
    { QRegExp("((Op.*So)|(os20[01][0-9])|(So.*10)|(India)|(Neva)).*32", Qt::CaseInsensitive), "OpenSolaris" },
    { QRegExp("So.*64",                                                 Qt::CaseInsensitive), "Solaris_64" },
    { QRegExp("So.*32",                                                 Qt::CaseInsensitive), "Solaris" },

    /* OS/2: */
    { QRegExp( "OS[/|!-]{,1}2.*W.*4.?5",    Qt::CaseInsensitive), "OS2Warp45" },
    { QRegExp( "OS[/|!-]{,1}2.*W.*4",       Qt::CaseInsensitive), "OS2Warp4" },
    { QRegExp( "OS[/|!-]{,1}2.*W",          Qt::CaseInsensitive), "OS2Warp3" },
    { QRegExp("(OS[/|!-]{,1}2.*e)|(eCS.*)", Qt::CaseInsensitive), "OS2eCS" },
    { QRegExp( "OS[/|!-]{,1}2",             Qt::CaseInsensitive), "OS2" },
    { QRegExp( "eComS.*",                   Qt::CaseInsensitive), "OS2eCS" },

    /* Other: Must come before Ubuntu/Maverick and before Linux??? */
    { QRegExp("QN", Qt::CaseInsensitive), "QNX" },

    /* Mac OS X: Must come before Ubuntu/Maverick and before Linux: */
    { QRegExp("((mac.*10[.,]{0,1}4)|(os.*x.*10[.,]{0,1}4)|(mac.*ti)|(os.*x.*ti)|(Tig)).64",     Qt::CaseInsensitive), "MacOS_64" },
    { QRegExp("((mac.*10[.,]{0,1}4)|(os.*x.*10[.,]{0,1}4)|(mac.*ti)|(os.*x.*ti)|(Tig)).32",     Qt::CaseInsensitive), "MacOS" },
    { QRegExp("((mac.*10[.,]{0,1}5)|(os.*x.*10[.,]{0,1}5)|(mac.*leo)|(os.*x.*leo)|(Leop)).*64", Qt::CaseInsensitive), "MacOS_64" },
    { QRegExp("((mac.*10[.,]{0,1}5)|(os.*x.*10[.,]{0,1}5)|(mac.*leo)|(os.*x.*leo)|(Leop)).*32", Qt::CaseInsensitive), "MacOS" },
    { QRegExp("((mac.*10[.,]{0,1}6)|(os.*x.*10[.,]{0,1}6)|(mac.*SL)|(os.*x.*SL)|(Snow L)).*64", Qt::CaseInsensitive), "MacOS106_64" },
    { QRegExp("((mac.*10[.,]{0,1}6)|(os.*x.*10[.,]{0,1}6)|(mac.*SL)|(os.*x.*SL)|(Snow L)).*32", Qt::CaseInsensitive), "MacOS106" },
    { QRegExp( "(mac.*10[.,]{0,1}7)|(os.*x.*10[.,]{0,1}7)|(mac.*ML)|(os.*x.*ML)|(Mount)",       Qt::CaseInsensitive), "MacOS108_64" },
    { QRegExp( "(mac.*10[.,]{0,1}8)|(os.*x.*10[.,]{0,1}8)|(Lion)",                              Qt::CaseInsensitive), "MacOS107_64" },
    { QRegExp( "(mac.*10[.,]{0,1}9)|(os.*x.*10[.,]{0,1}9)|(mac.*mav)|(os.*x.*mav)|(Mavericks)", Qt::CaseInsensitive), "MacOS109_64" },
    { QRegExp( "(mac.*yos)|(os.*x.*yos)|(Yosemite)",                                            Qt::CaseInsensitive), "MacOS1010_64" },
    { QRegExp( "(mac.*yos)|(os.*x.*yos)|(Capitan)",                                             Qt::CaseInsensitive), "MacOS1011_64" },
    { QRegExp("((Mac)|(Tig)|(Leop)|(Yose)|(os[ ]*x)).*64",                                      Qt::CaseInsensitive), "MacOS_64" },
    { QRegExp("((Mac)|(Tig)|(Leop)|(Yose)|(os[ ]*x)).*32",                                      Qt::CaseInsensitive), "MacOS" },

    /* Code names for Linux distributions: */
    { QRegExp("((bianca)|(cassandra)|(celena)|(daryna)|(elyssa)|(felicia)|(gloria)|(helena)|(isadora)|(julia)|(katya)|(lisa)|(maya)|(nadia)|(olivia)|(petra)|(qiana)|(rebecca)|(rafaela)|(rosa)).*64",    Qt::CaseInsensitive), "Ubuntu_64" },
    { QRegExp("((bianca)|(cassandra)|(celena)|(daryna)|(elyssa)|(felicia)|(gloria)|(helena)|(isadora)|(julia)|(katya)|(lisa)|(maya)|(nadia)|(olivia)|(petra)|(qiana)|(rebecca)|(rafaela)|(rosa)).*32",    Qt::CaseInsensitive), "Ubuntu" },
    { QRegExp("((edgy)|(feisty)|(gutsy)|(hardy)|(intrepid)|(jaunty)|(karmic)|(lucid)|(maverick)|(natty)|(oneiric)|(precise)|(quantal)|(raring)|(saucy)|(trusty)|(utopic)|(vivid)|(wily)|(xenial)).*64",    Qt::CaseInsensitive), "Ubuntu_64" },
    { QRegExp("((edgy)|(feisty)|(gutsy)|(hardy)|(intrepid)|(jaunty)|(karmic)|(lucid)|(maverick)|(natty)|(oneiric)|(precise)|(quantal)|(raring)|(saucy)|(trusty)|(utopic)|(vivid)|(wily)|(xenial)).*32",    Qt::CaseInsensitive), "Ubuntu" },
    { QRegExp("((sarge)|(etch)|(lenny)|(squeeze)|(wheezy)|(jessie)|(sid)).*64",                                                                          Qt::CaseInsensitive), "Debian_64" },
    { QRegExp("((sarge)|(etch)|(lenny)|(squeeze)|(wheezy)|(jessie)|(sid)).*32",                                                                          Qt::CaseInsensitive), "Debian" },
    { QRegExp("((moonshine)|(werewolf)|(sulphur)|(cambridge)|(leonidas)|(constantine)|(goddard)|(laughlin)|(lovelock)|(verne)|(beefy)|(spherical)).*64", Qt::CaseInsensitive), "Fedora_64" },
    { QRegExp("((moonshine)|(werewolf)|(sulphur)|(cambridge)|(leonidas)|(constantine)|(goddard)|(laughlin)|(lovelock)|(verne)|(beefy)|(spherical)).*32", Qt::CaseInsensitive), "Fedora" },

    /* Regular names of Linux distributions: */
    { QRegExp("Arc.*64",                           Qt::CaseInsensitive), "ArchLinux_64" },
    { QRegExp("Arc.*32",                           Qt::CaseInsensitive), "ArchLinux" },
    { QRegExp("Deb.*64",                           Qt::CaseInsensitive), "Debian_64" },
    { QRegExp("Deb.*32",                           Qt::CaseInsensitive), "Debian" },
    { QRegExp("((SU)|(Nov)|(SLE)).*64",            Qt::CaseInsensitive), "OpenSUSE_64" },
    { QRegExp("((SU)|(Nov)|(SLE)).*32",            Qt::CaseInsensitive), "OpenSUSE" },
    { QRegExp("Fe.*64",                            Qt::CaseInsensitive), "Fedora_64" },
    { QRegExp("Fe.*32",                            Qt::CaseInsensitive), "Fedora" },
    { QRegExp("((Gen)|(Sab)).*64",                 Qt::CaseInsensitive), "Gentoo_64" },
    { QRegExp("((Gen)|(Sab)).*32",                 Qt::CaseInsensitive), "Gentoo" },
    { QRegExp("((Man)|(Mag)).*64",                 Qt::CaseInsensitive), "Mandriva_64" },
    { QRegExp("((Man)|(Mag)).*32",                 Qt::CaseInsensitive), "Mandriva" },
    { QRegExp("((Red)|(rhel)|(cen)).*64",          Qt::CaseInsensitive), "RedHat_64" },
    { QRegExp("((Red)|(rhel)|(cen)).*32",          Qt::CaseInsensitive), "RedHat" },
    { QRegExp("Tur.*64",                           Qt::CaseInsensitive), "Turbolinux_64" },
    { QRegExp("Tur.*32",                           Qt::CaseInsensitive), "Turbolinux" },
    { QRegExp("(Ub)|(Min).*64",                    Qt::CaseInsensitive), "Ubuntu_64" },
    { QRegExp("(Ub)|(Min).*32",                    Qt::CaseInsensitive), "Ubuntu" },
    { QRegExp("Xa.*64",                            Qt::CaseInsensitive), "Xandros_64" },
    { QRegExp("Xa.*32",                            Qt::CaseInsensitive), "Xandros" },
    { QRegExp("((Or)|(oel)|(ol)).*64",             Qt::CaseInsensitive), "Oracle_64" },
    { QRegExp("((Or)|(oel)|(ol)).*32",             Qt::CaseInsensitive), "Oracle" },
    { QRegExp("Knoppix",                           Qt::CaseInsensitive), "Linux26" },
    { QRegExp("Dsl",                               Qt::CaseInsensitive), "Linux24" },
    { QRegExp("((Lin)|(lnx)).*2.?2",               Qt::CaseInsensitive), "Linux22" },
    { QRegExp("((Lin)|(lnx)).*2.?4.*64",           Qt::CaseInsensitive), "Linux24_64" },
    { QRegExp("((Lin)|(lnx)).*2.?4.*32",           Qt::CaseInsensitive), "Linux24" },
    { QRegExp("((((Lin)|(lnx)).*2.?6)|(LFS)).*64", Qt::CaseInsensitive), "Linux26_64" },
    { QRegExp("((((Lin)|(lnx)).*2.?6)|(LFS)).*32", Qt::CaseInsensitive), "Linux26" },
    { QRegExp("((Lin)|(lnx)).*64",                 Qt::CaseInsensitive), "Linux26_64" },
    { QRegExp("((Lin)|(lnx)).*32",                 Qt::CaseInsensitive), "Linux26" },

    /* Other: */
    { QRegExp("L4",                   Qt::CaseInsensitive), "L4" },
    { QRegExp("((Fr.*B)|(fbsd)).*64", Qt::CaseInsensitive), "FreeBSD_64" },
    { QRegExp("((Fr.*B)|(fbsd)).*32", Qt::CaseInsensitive), "FreeBSD" },
    { QRegExp("Op.*B.*64",            Qt::CaseInsensitive), "OpenBSD_64" },
    { QRegExp("Op.*B.*32",            Qt::CaseInsensitive), "OpenBSD" },
    { QRegExp("Ne.*B.*64",            Qt::CaseInsensitive), "NetBSD_64" },
    { QRegExp("Ne.*B.*32",            Qt::CaseInsensitive), "NetBSD" },
    { QRegExp("Net",                  Qt::CaseInsensitive), "Netware" },
    { QRegExp("Rocki",                Qt::CaseInsensitive), "JRockitVE" },
    { QRegExp("bs[23]{0,1}-",         Qt::CaseInsensitive), "VBoxBS_64" }, /* bootsector tests */
    { QRegExp("Ot",                   Qt::CaseInsensitive), "Other" },
};

UIWizardNewVMPage1::UIWizardNewVMPage1(const QString &strGroup)
    : m_strGroup(strGroup)
{
    CHost host = vboxGlobal().host();
    m_fSupportsHWVirtEx = host.GetProcessorFeature(KProcessorFeature_HWVirtEx);
    m_fSupportsLongMode = host.GetProcessorFeature(KProcessorFeature_LongMode);
}

void UIWizardNewVMPage1::onNameChanged(QString strNewName)
{
    /* Do not forget about achitecture bits, if not yet specified: */
    if (!strNewName.contains("32") && !strNewName.contains("64"))
        strNewName += ARCH_BITS == 64 && m_fSupportsHWVirtEx && m_fSupportsLongMode ? "64" : "32";

    /* Search for a matching OS type based on the string the user typed already. */
    for (size_t i = 0; i < RT_ELEMENTS(gs_OSTypePattern); ++i)
        if (strNewName.contains(gs_OSTypePattern[i].pattern))
        {
            m_pNameAndSystemEditor->blockSignals(true);
            m_pNameAndSystemEditor->setType(vboxGlobal().vmGuestOSType(gs_OSTypePattern[i].pcstId));
            m_pNameAndSystemEditor->blockSignals(false);
            break;
        }
}

void UIWizardNewVMPage1::onOsTypeChanged()
{
    /* If the user manually edited the OS type, we didn't want our automatic OS type guessing anymore.
     * So simply disconnect the text-edit signal. */
    m_pNameAndSystemEditor->disconnect(SIGNAL(sigNameChanged(const QString &)), thisImp(), SLOT(sltNameChanged(const QString &)));
}

void UIWizardNewVMPage1::adjustToolTip(const QString &strNewName /* = QString() */)
{
    /* Compose tool-tip: */
    QString strToolTip;
    /* If name is empty: */
    if (strNewName.isEmpty())
    {
        /* We are just reseting the tool-tip to default: */
        strToolTip = UIWizardNewVM::tr("<p><nobr>Holds the name or full path to the virtual "
                                       "machine folder you are about to create.</nobr></p>");
    }
    /* If name is NOT empty: */
    else
    {
        /* Compose the machine file-path, acquire the machine folder from it: */
        const QString strMachineFilePath = composeMachineFilePath(strNewName);
        const QString strMachineFolder = QDir::toNativeSeparators(QFileInfo(strMachineFilePath).absolutePath());
        /* And compose the location-editor tool-tip accordingly: */
        strToolTip = UIWizardNewVM::tr("<p><nobr>You are about to create the virtual machine in the "
                                       "following folder:</nobr><br><nobr><b>%1</b></nobr></p>")
                                       .arg(strMachineFolder);
    }
    /* Assign tool-tip: */
    m_pNameAndSystemEditor->locationEditor()->setToolTip(strToolTip);
}

bool UIWizardNewVMPage1::machineFolderCreated()
{
    return !m_strMachineFolder.isEmpty();
}

bool UIWizardNewVMPage1::createMachineFolder()
{
    /* Cleanup previosly created folder if any: */
    if (machineFolderCreated() && !cleanupMachineFolder())
    {
        msgCenter().cannotRemoveMachineFolder(m_strMachineFolder, thisImp());
        return false;
    }

    /* Compose machine file-path, parse it to folder and base-name: */
    const QString strMachineFilePath = composeMachineFilePath(m_pNameAndSystemEditor->name());
    const QString strMachineFolder = QDir::toNativeSeparators(QFileInfo(strMachineFilePath).absolutePath());
    const QString strMachineBaseName = QFileInfo(strMachineFilePath).completeBaseName();

    /* Make sure that folder doesn't exists: */
    if (QDir(strMachineFolder).exists())
    {
        msgCenter().cannotRewriteMachineFolder(strMachineFolder, thisImp());
        return false;
    }

    /* Try to create new folder (and it's predecessors): */
    bool fMachineFolderCreated = QDir().mkpath(strMachineFolder);
    if (!fMachineFolderCreated)
    {
        msgCenter().cannotCreateMachineFolder(strMachineFolder, thisImp());
        return false;
    }

    /* Initialize fields: */
    m_strMachineFolder = strMachineFolder;
    m_strMachineBaseName = strMachineBaseName;
    m_strMachineFilePath = strMachineFilePath;
    return true;
}

bool UIWizardNewVMPage1::cleanupMachineFolder()
{
    /* Make sure folder was previosly created: */
    if (m_strMachineFolder.isEmpty())
        return false;
    /* Try to cleanup folder (and it's predecessors): */
    bool fMachineFolderRemoved = QDir().rmpath(m_strMachineFolder);
    /* Reset machine folder value: */
    if (fMachineFolderRemoved)
        m_strMachineFolder = QString();
    /* Return cleanup result: */
    return fMachineFolderRemoved;
}

QString UIWizardNewVMPage1::composeMachineFilePath(const QString &strUserMachineLocation)
{
    /* Get VBox: */
    CVirtualBox vbox = vboxGlobal().virtualBox();
    /* Get default machine folder: */
    const QString strDefaultMachineFolder = vbox.GetSystemProperties().GetDefaultMachineFolder();
    /* Fetch user's machine location: */
    const QString strUserMachineFolder = QFileInfo(strUserMachineLocation).absolutePath();
    const QString strUserMachineBaseName = QFileInfo(strUserMachineLocation).fileName();
    const bool fUseDefaultPath = strUserMachineLocation == strUserMachineBaseName;
    /* Compose machine filename: */
    return vbox.ComposeMachineFilename(strUserMachineBaseName,
                                       fUseDefaultPath ? m_strGroup : QString() /* no group in that case */,
                                       QString(),
                                       fUseDefaultPath ? strDefaultMachineFolder : strUserMachineFolder);
}

UIWizardNewVMPageBasic1::UIWizardNewVMPageBasic1(const QString &strGroup)
    : UIWizardNewVMPage1(strGroup)
{
    /* Create widgets: */
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
    {
        m_pLabel = new QIRichTextLabel(this);
        m_pNameAndSystemEditor = new UINameAndSystemEditor(this, true);
        pMainLayout->addWidget(m_pLabel);
        pMainLayout->addWidget(m_pNameAndSystemEditor);
        pMainLayout->addStretch();
    }

    /* Setup connections: */
    connect(m_pNameAndSystemEditor, SIGNAL(sigNameChanged(const QString &)), this, SLOT(sltNameChanged(const QString &)));
    connect(m_pNameAndSystemEditor, SIGNAL(sigNameChanged(const QString &)), this, SLOT(sltAdjustToolTip(const QString &)));
    connect(m_pNameAndSystemEditor, SIGNAL(sigOsTypeChanged()), this, SLOT(sltOsTypeChanged()));

    /* Register fields: */
    registerField("name*", m_pNameAndSystemEditor, "name", SIGNAL(sigNameChanged(const QString &)));
    registerField("type", m_pNameAndSystemEditor, "type", SIGNAL(sigOsTypeChanged()));
    registerField("machineFolder", this, "machineFolder");
    registerField("machineBaseName", this, "machineBaseName");
    registerField("machineFilePath", this, "machineFilePath");

    /* Initialize tool-tip: */
    adjustToolTip();
}

void UIWizardNewVMPageBasic1::sltNameChanged(const QString &strNewName)
{
    /* Call to base-class: */
    onNameChanged(strNewName);
}

void UIWizardNewVMPageBasic1::sltAdjustToolTip(const QString &strNewName)
{
    /* Call to base-class: */
    adjustToolTip(strNewName);
}

void UIWizardNewVMPageBasic1::sltOsTypeChanged()
{
    /* Call to base-class: */
    onOsTypeChanged();
}

void UIWizardNewVMPageBasic1::retranslateUi()
{
    /* Translate page: */
    setTitle(UIWizardNewVM::tr("Name and operating system"));

    /* Translate widgets: */
    m_pLabel->setText(UIWizardNewVM::tr("Please choose a descriptive name for the new virtual machine "
                                        "and select the type of operating system you intend to install on it. "
                                        "The name you choose will be used throughout VirtualBox "
                                        "to identify this machine."));
}

void UIWizardNewVMPageBasic1::initializePage()
{
    /* Translate page: */
    retranslateUi();
}

void UIWizardNewVMPageBasic1::cleanupPage()
{
    /* Cleanup: */
    cleanupMachineFolder();
    /* Call to base-class: */
    UIWizardPage::cleanupPage();
}

bool UIWizardNewVMPageBasic1::validatePage()
{
    /* Try to create machine folder: */
    return createMachineFolder();
}

