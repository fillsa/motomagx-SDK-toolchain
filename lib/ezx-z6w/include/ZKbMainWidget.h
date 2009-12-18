

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_KBMAINWIDGET_H
#define Z_KBMAINWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include "ZMainWidget.h"
#include "ZHeader.h"
#include "ZSoftKey.h"

//class ZSoftKey;
//class ZCLISoftKey;
class ZAppInfoArea;
class ZKbMainWidgetData;


class ZKbMainWidget : public ZMainWidget
{
    Q_OBJECT
public:
/*
41a0ea84 T ZKbMainWidget::HideHeader()
41a0e7e0 T ZKbMainWidget::getSoftKey(bool)
41a0ea00 T ZKbMainWidget::headerSize()
41a0e668 T ZKbMainWidget::setSoftKey(ZSoftKey*)
41a0e8b4 T ZKbMainWidget::eventFilter(QObject*, QEvent*)

41a0e9d4 T ZKbMainWidget::updateHeader()
41a0e8c8 T ZKbMainWidget::keyPressEvent(QKeyEvent*)
41a0e89c T ZKbMainWidget::getAppInfoArea()
41a90c48 T ZKbMainWidget::initMetaObject()
41a0e840 T ZKbMainWidget::setAppInfoArea(ZAppInfoArea*)
41a0e8e4 T ZKbMainWidget::slotAppMessage(QCString const&, QArray<char> const&)
41a90cd4 T ZKbMainWidget::clearKeyClicked()
41a0e8a0 T ZKbMainWidget::getLRSBaseIndex()
41a90a8c T ZKbMainWidget::staticMetaObject()
41a90cf8 T ZKbMainWidget::serverInitialized()
41a0e4d4 T ZKbMainWidget::getMainWidgetTitle()
41a0e9b8 T ZKbMainWidget::isTitleTruncEnable()
41a0e3bc T ZKbMainWidget::setMainWidgetTitle(QString const&)
41a0e99c T ZKbMainWidget::setTitleTruncEnable(bool)
41a0e5bc T ZKbMainWidget::getMainWidgetTitleIcon()
41a0e58c T ZKbMainWidget::setMainWidgetTitleIcon(QPixmap const&)
41a0e628 T ZKbMainWidget::slotFullScreenModeChanged(bool)
41a909e8 T ZKbMainWidget::tr(char const*)
41a90a3c T ZKbMainWidget::tr(char const*, char const*)
41a0df34 T ZKbMainWidget::init(ZHeader::HEADER_TYPE)
41a0e614 T ZKbMainWidget::event(QEvent*)
41ad2ab8 B ZKbMainWidget::metaObj
41a0ea7c T ZKbMainWidget::getHeader()
*/
/*
ZMainWidget::className() const@@VERSION		 // FUNC
ZMainWidget::eventFilter(QObject*, QEvent*)@@VERSION		 // FUNC
ZMainWidget::getContentWidget(bool)@@VERSION		 // FUNC
ZMainWidget::getCSTWidget(bool)@@VERSION		 // FUNC
ZMainWidget::getEditMode()@@VERSION		 // FUNC
ZMainWidget::getFavoriteInputMethods() const@@VERSION		 // FUNC
ZMainWidget::getFullScreenMode()@@VERSION		 // FUNC
ZMainWidget::getKbState()@@VERSION		 // FUNC
ZMainWidget::getLRSBaseIndex()@@VERSION		 // FUNC
ZMainWidget::getTitleBarWidget()@@VERSION		 // FUNC
ZMainWidget::getVBoxLayout()@@VERSION		 // FUNC
ZMainWidget::hideInputWidget()@@VERSION		 // FUNC
ZMainWidget::hideToolBar()@@VERSION		 // FUNC
ZMainWidget::hide()@@VERSION		 // FUNC
ZMainWidget::invokeInputWidget()@@VERSION		 // FUNC
ZMainWidget::paletteChange(QPalette const&)@@VERSION		 // FUNC
ZMainWidget::setContentWidget(QWidget*)@@VERSION		 // FUNC
ZMainWidget::setCSTWidget(QWidget*)@@VERSION		 // FUNC
ZMainWidget::setFullScreenMode(bool, bool)@@VERSION		 // FUNC
ZMainWidget::setInputMethod(QUuid const&, int)@@VERSION		 // FUNC
ZMainWidget::setInputMethod(QWidget*, QUuid const&, int, QString)@@VERSION	 // FUNC
ZMainWidget::setInputMethods(QWidget*, QUuid const&, int, QString)@@VERSION	 // FUNC
ZMainWidget::setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString)@@VERSION		 // FUNC
ZMainWidget::setTitleBarWidget(QWidget*)@@VERSION		 // FUNC
ZMainWidget::setupInputMethodsPopupMenu()@@VERSION		 // FUNC
ZMainWidget::showToolBar()@@VERSION		 // FUNC
ZMainWidget::show()@@VERSION		 // FUNC
ZMainWidget::showWithInputMethod(QUuid const&, int)@@VERSION		 // FUNC
ZMainWidget::slotPopupMenu(int)@@VERSION		 // FUNC
ZMainWidget::staticMetaObject()@@VERSION		 // FUNC
ZMainWidget::ZMainWidget(bool, QWidget*, char const*, unsigned int)@@VERSION	 // FUNC
ZMainWidget::ZMainWidget(bool, QWidget*, char const*, unsigned int)@@VERSION	 // FUNC
ZMainWidget::ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned int)@@VERSION		 // FUNC
ZMainWidget::ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned int)@@VERSION		 // FUNC
ZMainWidget::ZMainWidget(QWidget*, char const*, unsigned int)@@VERSION		 // FUNC
ZMainWidget::ZMainWidget(QWidget*, char const*, unsigned int)@@VERSION		 // FUNC
ZMainWidget::~ZMainWidget()@@VERSION		 // FUNC
ZMainWidget::~ZMainWidget()@@VERSION		 // FUNC
ZMainWidget::~ZMainWidget()@@VERSION		 // FUNC
*/

//ZKbMainWidget::ZKbMainWidget(QWidget*, char const*, unsigned int)
    ZKbMainWidget( QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
//ZKbMainWidget::ZKbMainWidget(QString const&, QWidget*, char const*, unsigned int)
    ZKbMainWidget( const QString &mwTitle, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
//ZKbMainWidget::ZKbMainWidget(ZHeader::HEADER_TYPE, QWidget*, char const*, unsigned int)
    ZKbMainWidget( ZHeader::HEADER_TYPE headerType, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

    virtual ~ZKbMainWidget();

  public:
//ZKbMainWidget::setHeaderType(ZHeader::HEADER_TYPE)
    void setHeaderType(ZHeader::HEADER_TYPE headerType);

//ZKbMainWidget::setAppTitle(QString const&)
    static bool setAppTitle( const QString &appTitle );
//ZKbMainWidget::getAppTitle()
    static QString getAppTitle();

	//bool setContentWidget(QWidget *widget);
	//{
	//	QVBoxLayout* layout = getVBoxLayout();
	//	layout->addWidget(widget);
	//	return true;
	//};
	

    QPixmap getTitlePixmap(int nIdx);

    bool setMainWidgetTitle( const QString &mwTitle );

    QString getMainWidgetTitle();

    bool setMainWidgetTitleIcon(const QPixmap& pmp);

    QPixmap getMainWidgetTitleIcon();

    bool setAppInfoArea( ZAppInfoArea *aia );

    ZAppInfoArea* getAppInfoArea();

    bool setSoftKey( ZSoftKey *cstWidget );

    ZSoftKey* getSoftKey( bool createZSoftKey = TRUE )
	{
		ZSoftKey* newSoftKey = new ZSoftKey("CST_2A", this, this);
		setSoftKey(newSoftKey);
		return newSoftKey;
	};

    //bool setCLISoftKey(ZCLISoftKey* cliSoftKey);

    //ZCLISoftKey* getCLISoftKey(bool createZCLISoftKey = TRUE);

    virtual bool eventFilter(QObject*, QEvent*);
  //  virtual void show();
    void setTitleTruncEnable(bool bTrunc);

    bool isTitleTruncEnable();

    void updateHeader();

    QSize headerSize();

    void setWidgetPixmapPrefix(QString& prefix );
    void setHeaderPixmapPrefix(QString& prefix);
    //void hideHeader() ;

    void showHeader() ;
//    virtual QWidget* getContentWidget(bool createZScrollView = TRUE);

//    virtual bool setContentWidget(QWidget* w = NULL);

//    virtual void setFullScreenMode(bool fullScreen, bool reserved = FALSE);

    //virtual bool getFullScreenMode();

    QSize getContentSize();

    //virtual bool getEditMode();
    //virtual QWidget* getCSTWidget( bool create = TRUE );
    //virtual bool setCSTWidget( QWidget* w = NULL );
    //virtual bool setTitleBarWidget( QWidget* w = NULL );
    //virtual QWidget* getTitleBarWidget();
 signals:

    void clearKeyClicked( );

    void serverInitialized();

    void TitlePixmapChanged(int nIdx);
protected slots:
/*
    virtual void slotKbWidgetSizeChanged(const QRect & resizeR,
                                 int topLevelWinId,
                                 bool show,
                                 bool changed);
*/
  protected:

    virtual bool event( QEvent *e );

    int getLRSBaseIndex();

    void keyPressEvent( QKeyEvent * e);

  //  virtual void migrateEvent(QMigrateEvent*);

//    virtual void resizeEvent( QResizeEvent * e);


  private slots:  
    void slotAppMessage(const QCString &msg, const QByteArray &);
    void childDestroyed();

  private:

     void init(ZHeader::HEADER_TYPE headerType);

    void initMainWidget();

  private:
    ZKbMainWidgetData *data;
};

#endif

