#ifndef _ZAPPLICATION_H_
#define _ZAPPLICATION_H_

#include <qapplication.h>
#include <qrect.h>
#include <qcstring.h>
#include <qarray.h>
#include <qvaluelist.h>
#include <qobject.h>
#include <qevent.h>
#include <quuid.h>
#include <qglist.h>
#include <qwidget.h>
#include <qstring.h>
#include <qwsevent_qws.h>
#include <qwscursor_qws.h>
#include <qpixmap.h>
#include <ZWidget.h>
#include <KbInputFieldAdapter.h>

/* Size <= 104=26*4 bytes, good estimate */
class ZApplication : public QApplication
{ 
	Q_OBJECT
	unsigned int data[30 - sizeof(QApplication)/4];

public:
	ZApplication(int&, char**, QApplication::Type t = QApplication::GuiClient);
	virtual ~ZApplication ();

        virtual void tryQuit();

	void animationStatus(int);
	void animationTimeOut();
	void animationUpdate(QRect const&);
	void appMessage(QCString const&, QArray<char> const&);
	void applyPalette();
	void applyStyle();
	bool askDialogsDismiss(int);
	void askReturnToIdle(int);
	void clickAppIcon();
	void clientManipulateAppWindows(int, QValueList<int>&);
	void createChannel();
	void createTouchSoundMsgQueue();
	void enableTouchSound(bool);
	void endKeyClicked();
	virtual bool eventFilter(QObject*, QEvent*);
	int  exec();
	void flipStatusChanged(int);
	void flushMsgs();
	const char*  getAppChannelName();
	void getAppSysFSBAID();
	void getAutoHideKb();
	void getAutoInvokeKb();
	void getDefaultKbMethod(bool);
	void getEndTaskWhenCloseSlider();
	void getFSBA(ZWidget const*);
	void getFSBAImage(int);
	void getIMList();
	ZInputFieldAdapter * getInputFieldAdapter();
	void getKBState();
	void getKbInputField(QWidget*);
	void getMouseMode(QWidget*);
	void getSkinService(ZWidget const*) const;
	void getSkinnableProperties();
	void getTouchSoundMsgQueue();
	void initPalette();
	void kbStateChanged(bool, QUuid const&, int);
	void loadEZXFonts();
	void loadString(QString const&);
	void mainWidgetSizeChanged(int, QRect const&);
	void manipulateAppWindows(int);
	bool notify(QObject*, QEvent*);
	void pidMessage(QCString const&, QArray<char> const&);
	void processMessage(QCString const&, QArray<char> const&);
	bool qwsEventFilter(QWSEvent*);
	void raiseAppWindows();
	void registerEditableWidget(char const*);
	void removeEditableWidget(char const*);
	void resetMouseMode();
	void resetPHTimer();
	void resetPressHoldStatus();
	void serverManipulateAppWindows(int, QString const&);
	void setAppFSBA(QPixmap const&, int, int);
	void setAppLayoutDirection(ZWidget::LayoutDirection);
	void setAutoHideKb(bool);
	void setAutoInvokeKb(QWidget*, bool);
	void setAutoInvokeKb(bool);
	void setDefaultKbMethod(QUuid const&);
	void setEnv(QString const&);
	void setFocusToLatestWindow(int);
	void setInputMethod(QWidget*, QUuid const&, int, QString);
	void setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString);
	void setMouseMode(QWidget*, int);
	void showMainWidget(QWidget*);
	void shutdown();
	void sliderStatusChanged(int);
	void soundTouchPanel(QWSEvent*);
	void startShowPHCursor(int, QString const&);
	void startShowWaitCursor(int, QString const&);
	void stopShowPHCursor();
	void stopShowWaitCursor();
	void systemMessage(QCString const&, QArray<char> const&);
	void timerEvent(QTimerEvent*);
	void updateIMNameList();
	void usbStorageInOut(bool);
	void getAppLayoutDirection() const;

signals:
	void quickQuit();
	void signalAppKilled(QUuid);
	void signalAppLaunched(QUuid);
	void signalAppThemeChange();
	void signalBridgeMessage(QArray<char> const&);
	void signalBridgeMessage(QCString const&, QArray<char> const&);
	void signalBridgeMessageWithoutRaise(QCString const&, QArray<char> const&);
	void signalCmdLine(QString const&);
	void signalKbStateChanged(QRect const&, int, bool, bool);
	void signalKillactionByMassstorage();
	void signalLanguageChange();
	void signalLaunchactionByAnotherApp(QUuid const&);
	void signalLaunchactionByDedicatedkey(QUuid const&);
	void signalLaunchactionByIdlescreen(QUuid const&);
	void signalLaunchactionByMainscreen(QUuid const&);
	void signalLaunchactionByVoicecommand(QUuid const&);
	void signalMasterClear();
	void signalMasterReset();
	void signalOpenDoc(QString const&);
	void signalRaise();
	void signalRaiseWithPolicy(int);
	void signalTcmdMasterClear();
	void signalTcmdMasterReset();
	void signalThemeChange();

public slots:
        virtual void slotShutdown();
        virtual void slotQuickQuit();
        virtual int slotUsbStorageInOut(bool);
        virtual int slotClickAppIcon();
        virtual void slotRaise();
        virtual int slotLanguageChange();
        virtual int slotThemeChange();
        //virtual int slotReturnToIdle(int);
        virtual int slotLaunchactionByIdlescreen(QUuid const&);
        virtual int slotLaunchactionByMainscreen(QUuid const&);
        virtual int slotLaunchactionByVoicecommand(QUuid const&);
        virtual int slotLaunchactionByDedicatedkey(QUuid const&);
        virtual int slotLaunchactionByAnotherApp(QUuid const&);
        virtual int slotKillactionByMassstorage();

	void slotAppMessage(QCString const&, QArray<char> const&);
	void slotCursorSelected(QWSCursor*);
	void slotHKData(QCString const&, QArray<char> const&);
	void slotKbStateChanged(QRect const&, int, bool, bool);
	void slotServerMessage(QCString const&, QArray<char> const&);
	void slotSysSetupMessage(QCString const&, QArray<char> const&);
	void slotSystemMessage(QCString const&, QArray<char> const&);
};

#endif
