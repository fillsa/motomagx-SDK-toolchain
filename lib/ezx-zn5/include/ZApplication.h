//Fix for Z6W compobility by Ant-ON, 04.03.2010
//Fix class size for ZN5 by Ant-ON, 25.09.2011

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZAPPLICATION_H
#define ZAPPLICATION_H

#include <qapplication.h>
#include <qwindowsystem_qws.h>
#include <qcopchannel_qws.h>
#include <qwsevent_qws.h>
#include <qvaluelist.h>
#ifdef EZX_ZN5
#include "ZMorphingModeDef.h"
#endif
#include "ZIMethod.h"
#include "ZKeyDef.h"

//For change SDK for ZN5/U9/Z6W
#include "ZMyConfig.h"

class ZApplicationData;
class QUuid;
struct ZWidgetSkinProps;

struct ZKbInputField;
class KbTouchInputEngine;

#include <ZWidget.h>
class ZSkinService;

//Size in ZN5: 0x3C

class ZApplication : public QApplication
{
    Q_OBJECT
    
	unsigned char fix[0x3C-sizeof(QApplication)];
public:
    ZApplication( int& argc, char **argv, Type = GuiClient );
    virtual ~ZApplication();
    
    #ifdef EZX_Z6W
    int getEndTaskWhenCloseSlider();
    #endif
    
    void showMainWidget( QWidget* wMain)
    {
		setMainWidget( wMain );
		wMain->show();
	}
    
    ZWidgetSkinProps * getSkinnableProperties();
    int exec();
    void setAutoInvokeKb( bool invoke = true );
    bool getAutoInvokeKb();
    void setAutoInvokeKb( QWidget* editableWidget, bool invoke = true );
    bool getAutoHideKb();
    QUuid getDefaultKbMethod( bool readConfig = false );
    void registerEditableWidget(const char* className);
    void setInputMethods( QWidget* widget, const QUuid& defaultIM,
                          const QValueList<QUuid> & favourIMList,
                          int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                          QString fieldName = QString() );
    void setInputMethod( QWidget* widget, const QUuid& defaultIM,
                         int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                         QString fieldName = QString() );
    ZKbInputField * getKbInputField(QWidget * edit);
    bool getKBState();
    QIMMap getIMList();
    void updateIMNameList();
    enum
    {
        LEFT_ONLY = 0,
        PRESS_HOLD
    };
    static void setMouseMode( QWidget* widget, int mode );
    static int getMouseMode( QWidget* widget );
    void startShowWaitCursor( int startTime = 0,const QString& resId = QString::null );
    void stopShowWaitCursor();
    void loadString( const QString& strFileName );
    const QString& getAppName();
    const char*  getAppChannelName();
    void raiseAppWindows();
    void flushMsgs();
    int getTouchSoundMsgQueue();
    bool notify(QObject *, QEvent *);
    void setAppFSBA(const QPixmap& pmapFSBA, int opacity = 100, int stretchPolicy = 0);
    QPixmap* getFSBAImage(int fsbaID);
    QPixmap* getFSBA(const ZWidget* pWidget);
    int getAppSysFSBAID();
    ZSkinService& getSkinService(const ZWidget* pWidget = NULL) const;
    ZWidget::LayoutDirection getAppLayoutDirection() const;

signals:
    void shutdown();
    void quickQuit();
    void signalAppThemeChange();
    void signalAppLaunched( const QUuid appID );
    void signalCmdLine( const QString &cmdLine );
    void signalBridgeMessage( const QByteArray &data );
    void signalBridgeMessage( const QCString &action, const QByteArray &data );
    void signalBridgeMessageWithoutRaise( const QCString &action, const QByteArray &data );
    void systemMessage( const QCString &msg, const QByteArray &data );

protected:
    bool qwsEventFilter( QWSEvent* e );
    virtual bool eventFilter( QObject* o, QEvent* e);
    virtual void timerEvent( QTimerEvent* e);
    virtual void tryQuit();
    bool askDialogsDismiss( int reason );

protected slots:
    virtual void slotShutdown();
    virtual void slotQuickQuit();
    virtual void slotUsbStorageInOut(bool storagIn );
    virtual void slotClickAppIcon();
    virtual void slotRaise();
    virtual void slotLanguageChange();
    virtual void slotThemeChange();
    virtual void slotReturnToIdle( int reason );
    virtual void slotLaunchactionByIdlescreen(const QUuid&);
    virtual void slotLaunchactionByMainscreen(const QUuid&);
    virtual void slotLaunchactionByVoicecommand(const QUuid&);
    virtual void slotLaunchactionByDedicatedkey(const QUuid&);
    virtual void slotLaunchactionByAnotherApp(const QUuid&);
    virtual void slotKillactionByMassstorage();

private:
    QCopChannel*  getAppChannel();

private:
//    ZApplicationData* d;
    friend class ZMainWidget;
    friend class KbTouchInputEngine;
};

#endif
