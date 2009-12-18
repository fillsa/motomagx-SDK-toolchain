#ifndef Z_KBMAINWIDGET_H
#define Z_KBMAINWIDGET_H

#include "ZMainWidget.h"
#include "ZHeader.h"
#include "ZSoftKey.h"

//class ZSoftKey;
class ZAppInfoArea;
class ZKbMainWidgetData;

class ZKbMainWidget : public ZMainWidget
{
    Q_OBJECT
public:
    ZKbMainWidget( QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
    ZKbMainWidget( const QString &mwTitle, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
    ZKbMainWidget( ZHeader::HEADER_TYPE headerType, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
    virtual ~ZKbMainWidget();

  public:
    enum ENUM_CHILD{CHILD_HEADER=0,CHILD_AIA=1,CHILD_CONTENT=2,CHILD_CST=3,CHILD_NUM=4};
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
    void hideHeader() ;
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

private:
    void init(ZHeader::HEADER_TYPE headerType);
    
  private:
    ZKbMainWidgetData *data;

};

#endif

