
//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZApplication

// _ZN12ZApplicationC4ERiPPcN12QApplication4TypeE
// _ZN12ZApplicationD4Ev

#ifndef _E2_EZX_ZAPPLICATION_H
#define _E2_EZX_ZAPPLICATION_H

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
#include <E2_EZX_ZWidget.h>

class ZApplication : public QApplication
{ 
	Q_OBJECT
	char tmp[8096];
public:
	ZApplication(int&, char**, QApplication::Type t = QApplication::GuiClient); 
	virtual ~ZApplication ();
	                               	
	void animationStatus(int);
	void animationTimeOut();
	void animationUpdate(QRect const&);
	
	
	void appMessage(QCString const&, QArray<char> const&);
	int applyPalette();
	int applyStyle();
	
	void askDialogsDismiss(int); 
	void askReturnToIdle(int);
	
	void clickAppIcon();		
	void clientManipulateAppWindows(int, QValueList<int>&); 
	
	bool createChannel();
	
	void createTouchSoundMsgQueue();
	void enableTouchSound(bool);	
		
	void endKeyClicked();		
		
	virtual bool eventFilter(QObject*, QEvent*); 
	int exec();
	
	void flipStatusChanged(int);	
	void flushMsgs();	
	
	QCString getAppChannelName();	
	int getAppSysFSBAID();	
	bool getAutoHideKb();	
	bool getAutoInvokeKb();
	QUuid getDefaultKbMethod(bool);
	int getFSBA(ZWidget const*);
	int getFSBAImage(int);
	QGList* getIMList();
	int getInputFieldAdapter();
	bool getKBState();
	int getKbInputField(QWidget*);
	int getMouseMode(QWidget*);
	const int getSkinService(ZWidget const*);	
	int getSkinnableProperties();	
	int getTouchSoundMsgQueue();
	int initPalette();
	void kbStateChanged(bool, QUuid const&, int);
	void loadEZXFonts();
	void loadString(QString const&);
	void mainWidgetSizeChanged(int, QRect const&);
	void manipulateAppWindows(int);
	virtual bool notify(QObject*, QEvent*);	
	void pidMessage(QCString const&, QArray<char> const&);
	void processMessage(QCString const&, QArray<char> const&);
	void quickQuit();
	virtual bool qwsEventFilter(QWSEvent*);
	void raiseAppWindows();
	void registerEditableWidget(char const*);
	void removeEditableWidget(char const*);
	void resetMouseMode();
	int resetPHTimer();
	void resetPressHoldStatus();
	void serverManipulateAppWindows(int, QString const&);
	void setAppFSBA(QPixmap const&, int, int);
	void setAutoHideKb(bool);
	void setAutoInvokeKb(QWidget*, bool);
	void setAutoInvokeKb(bool);
	void setDefaultKbMethod(QUuid const&);
	void setEnv(QString const&);
	void setFocusToLatestWindow(int);
	void setInputMethod(QWidget*, QUuid const&, int, QString);
	void setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString);
	bool setMouseMode(QWidget*, int);
	void showMainWidget(QWidget*);
	void shutdown();
	void signalAppKilled(QUuid);
	void signalAppLaunched(QUuid);
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
	void slotAppMessage(QCString const&, QArray<char> const&);
	virtual void slotClickAppIcon();
	void slotCursorSelected(QWSCursor*);
	void slotHKData(QCString const&, QArray<char> const&);	
	void slotKbStateChanged(QRect const&, int, bool, bool);	
	virtual void slotKillactionByMassstorage();	
	virtual void slotLanguageChange();
	virtual void slotLaunchactionByAnotherApp(QUuid const&);
	virtual void slotLaunchactionByDedicatedkey(QUuid const&);
	virtual void slotLaunchactionByIdlescreen(QUuid const&);
	virtual void slotLaunchactionByMainscreen(QUuid const&);
	virtual void slotLaunchactionByVoicecommand(QUuid const&);
	virtual void slotQuickQuit();
	virtual void slotRaise();
	virtual void slotReturnToIdle(int);
	void slotServerMessage(QCString const&, QArray<char> const&);
	virtual void slotShutdown();
	void slotSystemMessage(QCString const&, QArray<char> const&);
	virtual void slotThemeChange();
	virtual void slotUsbStorageInOut(bool);
	void soundTouchPanel(QWSEvent*);
	void startShowPHCursor(int, QString const&);
	void startShowWaitCursor(int, QString const&);
	void stopShowPHCursor();
	void stopShowWaitCursor();
	void systemMessage(QCString const&, QArray<char> const&);
	virtual void timerEvent(QTimerEvent*);
 	virtual void tryQuit();
	void updateIMNameList();
	void usbStorageInOut(bool);
};

#endif
