//Fix for ZN5/U9 by Ant-ON, 25-01-2010
//Fix for Z6W compobility by Ant-ON, 04.03.2010
//Fix class size for ZN5 by Ant-ON, 26.09.2011

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef Z_KBMAINWIDGET_H
#define Z_KBMAINWIDGET_H

#include <ZMyConfig.h>
#include "ZMainWidget.h"
#include "ZHeader.h"
#include "ZSoftKey.h"

//For change SDK for ZN5/U9/Z6W
#include "ZMyConfig.h"

class ZAppInfoArea;
class ZKbMainWidgetData;

//0x3B8, 0x13C, 0x190, 0x118, 0x104, 0x100, 0xFC
// Size in ZN5: 0xFC (??)

class ZKbMainWidget : public ZMainWidget
{
    Q_OBJECT
    
    unsigned char fix[0xFC - sizeof(ZMainWidget)];
public:
    ZKbMainWidget( QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
    ZKbMainWidget( const QString &mwTitle, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
    ZKbMainWidget( ZHeader::HEADER_TYPE headerType, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
    virtual ~ZKbMainWidget();

    bool setContentWidget(QWidget *widget)
    {
        QVBoxLayout* layout = getVBoxLayout();
        layout->addWidget(widget);
        return true;
    };

public:
    void setHeaderType(ZHeader::HEADER_TYPE headerType);
    static bool setAppTitle( const QString &appTitle );
    static QString getAppTitle();
    bool setMainWidgetTitle( const QString &mwTitle );
    QString getMainWidgetTitle();
    bool setMainWidgetTitleIcon(const QPixmap& pmp);
    QPixmap getMainWidgetTitleIcon();
    bool setAppInfoArea( ZAppInfoArea *aia );
    ZAppInfoArea* getAppInfoArea();
    virtual bool setSoftKey( ZSoftKey *cstWidget );
    virtual ZSoftKey* getSoftKey( bool createZSoftKey = TRUE );
    virtual bool eventFilter(QObject*, QEvent*);
    void setTitleTruncEnable(bool bTrunc);
    bool isTitleTruncEnable();
    void updateHeader();
    QSize headerSize();
#ifdef EZX_ZN5
    void HideHeader();
#endif
    ZHeader* getHeader();
	
signals:
    void clearKeyClicked( );
    void serverInitialized();
	
protected:
    virtual bool event( QEvent *e );
    int getLRSBaseIndex();
    void keyPressEvent( QKeyEvent * e);

private slots:  
    void slotAppMessage(const QCString &msg, const QByteArray &);
    void slotFullScreenModeChanged(bool mobe);

private:
    void init(ZHeader::HEADER_TYPE headerType);
    
//private:
//    ZKbMainWidgetData *d;

};

#endif

