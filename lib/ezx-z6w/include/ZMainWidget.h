

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZMAINWIDGET_H
#define ZMAINWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qscrollview.h>
#include <qlayout.h>
#include <qpopupmenu.h>
#include <qstringlist.h>
#include <qlayout.h>
#include "ZWidget.h"
#include "ZGlobal.h"

class QUuid;
class ZMainWidgetPrivate;


class ZMainWidget: public ZWidget
{
    Q_OBJECT

public:

    enum
    {
        INPUTWIDGET_HIDE = 0, 
        INPUTWIDGET_SHOW,     
    };
/*
41a0f76c T ZMainWidget::getKbState()
41a0ec60 T ZMainWidget::eventFilter(QObject*, QEvent*)

41a90da4 W ZMainWidget::hideToolBar()
41a90d94 W ZMainWidget::showToolBar()


41a0fc50 T ZMainWidget::getVBoxLayout()
41a0ee3c T ZMainWidget::paletteChange(QPalette const&)
41a0f604 T ZMainWidget::slotPopupMenu(int)
41a0fd74 T ZMainWidget::setInputMethod(QWidget*, QUuid const&, int, QString)
41a0f660 T ZMainWidget::setInputMethod(QUuid const&, int)
41a0fc48 T ZMainWidget::getLRSBaseIndex()
41a0f668 T ZMainWidget::hideInputWidget()
41a0f69c T ZMainWidget::setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString)
41a0fc5c T ZMainWidget::setInputMethods(QWidget*, QUuid const&, int, QString)



41a0fc04 T ZMainWidget::getFullScreenMode()

41a0f66c T ZMainWidget::invokeInputWidget()
41a0f7c8 T ZMainWidget::setFullScreenMode(bool, bool)

41a0f60c T ZMainWidget::showWithInputMethod(QUuid const&, int)
41a0f600 T ZMainWidget::setupInputMethodsPopupMenu()
41a0f5f0 T ZMainWidget::hide()
41a0f5ec T ZMainWidget::show()

41a0fe00 T ZMainWidget::~ZMainWidget()
41a0ff1c T ZMainWidget::~ZMainWidget()
41a10030 T ZMainWidget::~ZMainWidget()
*/

//ZMainWidget::ZMainWidget(bool, QWidget*, char const*, unsigned int)
    ZMainWidget(bool editorMode,
                QWidget* parent,
                const char* name = 0,
                WFlags f = 0);
//ZMainWidget::ZMainWidget(QWidget*, char const*, unsigned int)
    ZMainWidget( QWidget* parent, const char* name = 0, WFlags f = 0);
//ZMainWidget::ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned int)
    ZMainWidget( const QString& titleText, bool editorMode, QWidget* parent,
                 const char* name = 0, WFlags f = 0);

    virtual ~ZMainWidget();

public:
//ZMainWidget::getEditMode()
    virtual bool getEditMode();
//ZMainWidget::getContentWidget(bool)
    virtual QWidget* getContentWidget(bool createZScrollView = TRUE);
//ZMainWidget::setContentWidget(QWidget*)
    virtual bool setContentWidget(QWidget* w = NULL);
//ZMainWidget::getCSTWidget(bool)
    virtual QWidget* getCSTWidget( bool create = TRUE );
//ZMainWidget::setCSTWidget(QWidget*)
    virtual bool setCSTWidget( QWidget* w = NULL );
//ZMainWidget::setTitleBarWidget(QWidget*)
    virtual bool setTitleBarWidget( QWidget* w = NULL );
//ZMainWidget::getTitleBarWidget()
    virtual QWidget* getTitleBarWidget();

    int getKbState();

    void setInputMethod(QWidget* widget,
                        const QUuid& method = IMID_UNDEFINED,
                        int fieldType = 0,
                        QString fieldName = QString());

    void showWithInputMethod(const QUuid & method = IMID_UNDEFINED,
                             int flag = 0);

    void setFavoriteInputMethods(QWidget* widget,
                                 const QValueList<QUuid> & imList);

    void setFavoriteInputMethods(const QValueList<QUuid> & imList);

    void setInputMethods(QWidget* widget,
                         const QUuid& defaultIM,
                         const QValueList<QUuid> & favourIMList,
                         int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                         QString fieldName = QString());

    void setInputMethods(QWidget* widget,
                         const QUuid& defaultIM,
                         int fieldType = ZKbInputField::FIELD_TYPE_REGULAR,
                         QString fieldname = QString());

    void setInputMethod(const QUuid& method = IMID_UNDEFINED,
                        int flag = 0);

    QValueList<QUuid> &  getFavoriteInputMethods() const;

    virtual void setFullScreenMode(bool fullScreen, bool reserved = FALSE);

    virtual bool getFullScreenMode();

public:

    virtual void show();

    virtual void hide();

    virtual bool eventFilter(QObject*, QEvent*);

public slots:
    virtual void hideInputWidget();

    virtual void slotPopupMenu(int id);

    virtual void invokeInputWidget();

signals:

    void kbStateChanged( bool show, const QUuid& imName, int kbh );

    void kbStateChanged(bool show);

    void fullScreenModeChanged( bool show );

    void mainWidgetSizeChanged(int mwId, const QRect & resizeR);

protected slots:
/*
    virtual void slotKbWidgetSizeChanged(const QRect & resizeR,
                                 int topLevelWinId,
                                 bool show,
                                 bool changed);
*/
    void slotKbStateChanged( bool show, const QUuid& imName, int kbh );

protected:

    virtual void paletteChange( const QPalette &pal);

    virtual bool showToolBar() { return FALSE; }

    virtual bool setToolBar( const QUuid& t) { return FALSE; }

    virtual bool hideToolBar() { return FALSE; }

    virtual void setupInputMethodsPopupMenu();

    virtual int getLRSBaseIndex();

    QVBoxLayout* getVBoxLayout();

private:

    void init( bool hasTitleBar = FALSE, const QString& text = QString::null );

private slots:

    void popupKBMenu();
    void objectDestroyed();

private:
    ZMainWidgetPrivate* d;

};

#endif

