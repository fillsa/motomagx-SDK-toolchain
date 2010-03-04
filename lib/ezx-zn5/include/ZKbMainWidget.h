//Fix for ZN5/U9 by Ant-ON, 25-01-2010
//Fix for Z6W compobility by Ant-ON, 04.03.2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef Z_KBMAINWIDGET_H
#define Z_KBMAINWIDGET_H

#include <ZMyConfig.h>
#include "ZMainWidget.h"
#include "ZHeader.h"
#include "ZSoftKey.h"

//For change SDK for ZN5/U9/Z6W
#include "ZMyConfig.h"

//class ZSoftKey;
class ZAppInfoArea;
class ZKbMainWidgetData;

class ZKbMainWidget : public ZMainWidget
{
	unsigned int data[90 - sizeof(ZMainWidget)/4];
    Q_OBJECT
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
    ZSoftKey* getSoftKey( bool createZSoftKey = TRUE );
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
    
  private:
    ZKbMainWidgetData *d;

};

#endif

