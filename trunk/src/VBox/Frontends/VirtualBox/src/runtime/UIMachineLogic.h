/** @file
 * VBox Qt GUI - UIMachineLogic class declaration.
 */

/*
 * Copyright (C) 2010-2013 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef ___UIMachineLogic_h___
#define ___UIMachineLogic_h___

/* GUI includes: */
#include "UIExtraDataDefs.h"
#include <QIWithRetranslateUI.h>
#ifdef VBOX_WITH_DEBUGGER_GUI
# include <VBox/dbggui.h>
#endif /* VBOX_WITH_DEBUGGER_GUI */

/* COM includes: */
#include "COMEnums.h"

/* Forward declarations: */
class QAction;
class QActionGroup;
class UISession;
class UIKeyboardHandler;
class UIMouseHandler;
class UIMachineWindow;
class UIMachineView;
class UIDockIconPreview;
class CSession;
class CMachine;
class CSnapshot;
class CUSBDevice;
class CVirtualBoxErrorInfo;
#ifdef Q_WS_MAC
class QMenuBar;
class QMenu;
#endif /* Q_WS_MAC */

/* Machine logic interface: */
class UIMachineLogic : public QIWithRetranslateUI3<QObject>
{
    Q_OBJECT;

signals:

    /** Notifies about frame-buffer resize. */
    void sigFrameBufferResize();

    /** Notifies listeners about 3D overlay visibility change. */
    void sigNotifyAbout3DOverlayVisibilityChange(bool fVisible);

public:

    /* Factory functions to create/destroy required logic sub-child: */
    static UIMachineLogic* create(QObject *pParent, UISession *pSession, UIVisualStateType visualStateType);
    static void destroy(UIMachineLogic *pWhichLogic);

    /* Check if this logic is available: */
    virtual bool checkAvailability() = 0;

    /* Prepare/cleanup the logic: */
    virtual void prepare();
    virtual void cleanup();

    /* Main getters/setters: */
    UISession* uisession() const { return m_pSession; }
    CSession& session() const;
    UIVisualStateType visualStateType() const { return m_visualStateType; }
    const QList<UIMachineWindow*>& machineWindows() const { return m_machineWindowsList; }
    UIKeyboardHandler* keyboardHandler() const { return m_pKeyboardHandler; }
    UIMouseHandler* mouseHandler() const { return m_pMouseHandler; }
    UIMachineWindow* mainMachineWindow() const;
    UIMachineWindow* activeMachineWindow() const;

    /* Maintenance getters/setters: */
    bool isPreventAutoClose() const { return m_fIsPreventAutoClose; }
    void setPreventAutoClose(bool fIsPreventAutoClose) { m_fIsPreventAutoClose = fIsPreventAutoClose; }

    /** Returns the list of available menus. */
    virtual QList<QMenu*> menus() const;

    /* API: Guest screen size stuff: */
    virtual void maybeAdjustGuestScreenSize();

    /* Wrapper to open Machine settings / Network page: */
    void openNetworkAdaptersDialog() { sltOpenNetworkAdaptersDialog(); }

#ifdef Q_WS_MAC
    void updateDockIcon();
    void updateDockIconSize(int screenId, int width, int height);
    UIMachineView* dockPreviewView() const;
#endif /* Q_WS_MAC */

    /* API: Close actions: */
    void saveState();
    void shutdown();
    void powerOff(bool fDiscardingState);

    /* API: 3D overlay visibility stuff: */
    virtual void notifyAbout3DOverlayVisibilityChange(bool fVisible);

    /** Returns whether VM should perform HID LEDs synchronization. */
    bool isHidLedsSyncEnabled() const { return m_fIsHidLedsSyncEnabled; }

protected slots:

    /** Checks if some visual-state type was requested. */
    virtual void sltCheckForRequestedVisualStateType() {}

    /** Requests visual-state change to 'normal' (window). */
    virtual void sltChangeVisualStateToNormal();
    /** Requests visual-state change to 'fullscreen'. */
    virtual void sltChangeVisualStateToFullscreen();
    /** Requests visual-state change to 'seamless'. */
    virtual void sltChangeVisualStateToSeamless();
    /** Requests visual-state change to 'scale'. */
    virtual void sltChangeVisualStateToScale();

    /* Console callback handlers: */
    virtual void sltMachineStateChanged();
    virtual void sltAdditionsStateChanged();
    virtual void sltMouseCapabilityChanged();
    virtual void sltKeyboardLedsChanged();
    virtual void sltUSBDeviceStateChange(const CUSBDevice &device, bool fIsAttached, const CVirtualBoxErrorInfo &error);
    virtual void sltRuntimeError(bool fIsFatal, const QString &strErrorId, const QString &strMessage);
#ifdef RT_OS_DARWIN
    virtual void sltShowWindows();
#endif /* RT_OS_DARWIN */
    virtual void sltGuestMonitorChange(KGuestMonitorChangedEventType changeType, ulong uScreenId, QRect screenGeo);

    /* Qt callback handler: */
    virtual void sltHostScreenCountChanged();
    virtual void sltHostScreenGeometryChanged();

protected:

    /* Constructor: */
    UIMachineLogic(QObject *pParent, UISession *pSession, UIVisualStateType visualStateType);

    /* Protected getters/setters: */
    bool isMachineWindowsCreated() const { return m_fIsWindowsCreated; }
    void setMachineWindowsCreated(bool fIsWindowsCreated);

    /* Protected members: */
    void setKeyboardHandler(UIKeyboardHandler *pKeyboardHandler);
    void setMouseHandler(UIMouseHandler *pMouseHandler);
    void addMachineWindow(UIMachineWindow *pMachineWindow);
    void retranslateUi();
#ifdef Q_WS_MAC
    bool isDockIconPreviewEnabled() const { return m_fIsDockIconEnabled; }
    void setDockIconPreviewEnabled(bool fIsDockIconPreviewEnabled) { m_fIsDockIconEnabled = fIsDockIconPreviewEnabled; }
    void updateDockOverlay();
#endif /* Q_WS_MAC */

    /* Prepare helpers: */
    virtual void prepareRequiredFeatures();
    virtual void prepareSessionConnections();
    virtual void prepareActionGroups();
    virtual void prepareActionConnections();
    virtual void prepareOtherConnections() {}
    virtual void prepareHandlers();
    virtual void prepareMachineWindows() = 0;
    virtual void prepareMenu();
#ifdef Q_WS_MAC
    virtual void prepareDock();
#endif /* Q_WS_MAC */
#ifdef VBOX_WITH_DEBUGGER_GUI
    virtual void prepareDebugger();
#endif /* VBOX_WITH_DEBUGGER_GUI */
    virtual void loadSettings();

    /* Cleanup helpers: */
    virtual void saveSettings();
#ifdef VBOX_WITH_DEBUGGER_GUI
    virtual void cleanupDebugger();
#endif /* VBOX_WITH_DEBUGGER_GUI */
#ifdef Q_WS_MAC
    virtual void cleanupDock();
#endif /* Q_WS_MAC */
    virtual void cleanupMenu();
    virtual void cleanupMachineWindows() = 0;
    virtual void cleanupHandlers();
    //virtual void cleanupOtherConnections() {}
    virtual void cleanupActionConnections() {}
    virtual void cleanupActionGroups();
    //virtual void cleanupSessionConnections() {}
    //virtual void cleanupRequiredFeatures() {}

    /** Updates the 'Machine' menu. */
    virtual void updateMenuMachine();
    /** Updates the 'View' menu. */
    virtual void updateMenuView();
    /** Updates the 'Devices' menu. */
    virtual void updateMenuDevices();
    /** Updates the 'Devices' : 'Network' menu. */
    virtual void updateMenuDevicesNetwork();
#ifdef VBOX_WITH_DEBUGGER_GUI
    virtual void updateMenuDebug();
#endif /* VBOX_WITH_DEBUGGER_GUI */
    /** Updates the 'Help' menu. */
    virtual void updateMenuHelp();

    /* Handler: Event-filter stuff: */
    bool eventFilter(QObject *pWatched, QEvent *pEvent);

private slots:

    /* "Machine" menu functionality: */
    void sltToggleGuestAutoresize(bool fEnabled);
    void sltAdjustWindow();
    void sltShowKeyboardSettings();
    void sltToggleMouseIntegration(bool fDisabled);
    void sltTypeCAD();
#ifdef Q_WS_X11
    void sltTypeCABS();
#endif /* Q_WS_X11 */
    void sltTakeSnapshot();
    void sltTakeScreenshot();
    void sltShowInformationDialog();
    void sltReset();
    void sltPause(bool fOn);
    void sltSaveState();
    void sltShutdown();
    void sltPowerOff();
    void sltClose();

    /* "Device" menu functionality: */
    void sltOpenVMSettingsDialog(const QString &strCategory = QString(), const QString &strControl = QString());
    void sltOpenStorageSettingsDialog();
    void sltOpenNetworkAdaptersDialog();
    void sltOpenSharedFoldersDialog();
    void sltPrepareStorageMenu();
    void sltMountStorageMedium();
    void sltPrepareUSBMenu();
    void sltPrepareWebCamMenu();
    void sltAttachUSBDevice();
    void sltAttachWebCamDevice();
    void sltPrepareSharedClipboardMenu();
    void sltChangeSharedClipboardType(QAction *pAction);
    void sltPrepareDragAndDropMenu();
    void sltPrepareNetworkMenu();
    void sltToggleNetworkAdapterConnection();
    void sltChangeDragAndDropType(QAction *pAction);
    void sltToggleVRDE(bool fEnabled);
    void sltToggleVideoCapture(bool fEnabled);
    void sltOpenVideoCaptureOptions();
    void sltInstallGuestAdditions();

#ifdef VBOX_WITH_DEBUGGER_GUI
    /* "Debug" menu functionality: */
    void sltPrepareDebugMenu();
    void sltShowDebugStatistics();
    void sltShowDebugCommandLine();
    void sltLoggingToggled(bool);
    void sltShowLogDialog();
#endif /* VBOX_WITH_DEBUGGER_GUI */

#ifdef RT_OS_DARWIN /* Something is *really* broken in regards of the moc here */
    void sltDockPreviewModeChanged(QAction *pAction);
    void sltDockPreviewMonitorChanged(QAction *pAction);
    void sltChangeDockIconUpdate(bool fEnabled);
#endif /* RT_OS_DARWIN */

    /* Handlers: Keyboard LEDs sync logic: */
    void sltHidLedsSyncStateChanged(bool fEnabled);
    void sltSwitchKeyboardLedsToGuestLeds();
    void sltSwitchKeyboardLedsToPreviousLeds();

    /** Show Global Preferences. */
    void sltShowGlobalPreferences();

private:

    /** Show Global Preferences on the page defined by @a strCategory and tab defined by @a strControl. */
    void showGlobalPreferences(const QString &strCategory = QString(), const QString &strControl = QString());

    /* Helpers: */
    static int searchMaxSnapshotIndex(const CMachine &machine, const CSnapshot &snapshot, const QString &strNameTemplate);
    void takeScreenshot(const QString &strFile, const QString &strFormat /* = "png" */) const;

    /* Private variables: */
    UISession *m_pSession;
    UIVisualStateType m_visualStateType;
    UIKeyboardHandler *m_pKeyboardHandler;
    UIMouseHandler *m_pMouseHandler;
    QList<UIMachineWindow*> m_machineWindowsList;

    QActionGroup *m_pRunningActions;
    QActionGroup *m_pRunningOrPausedActions;
    QActionGroup *m_pRunningOrPausedOrStackedActions;
    QActionGroup *m_pSharedClipboardActions;
    QActionGroup *m_pDragAndDropActions;

    bool m_fIsWindowsCreated : 1;
    bool m_fIsPreventAutoClose : 1;

#ifdef VBOX_WITH_DEBUGGER_GUI
    /* Debugger functionality: */
    bool dbgCreated();
    void dbgDestroy();
    void dbgAdjustRelativePos();
    /* The handle to the debugger GUI: */
    PDBGGUI m_pDbgGui;
    /* The virtual method table for the debugger GUI: */
    PCDBGGUIVT m_pDbgGuiVT;
#endif /* VBOX_WITH_DEBUGGER_GUI */

#ifdef Q_WS_MAC
    QMenuBar *m_pMenuBar;
    bool m_fIsDockIconEnabled;
    UIDockIconPreview *m_pDockIconPreview;
    QActionGroup *m_pDockPreviewSelectMonitorGroup;
    int m_DockIconPreviewMonitor;
#endif /* Q_WS_MAC */

    void *m_pHostLedsState;

    /** Holds whether VM should perform HID LEDs synchronization. */
    bool m_fIsHidLedsSyncEnabled;

    /* Friend classes: */
    friend class UIMachineWindow;
};

#endif /* !___UIMachineLogic_h___ */

