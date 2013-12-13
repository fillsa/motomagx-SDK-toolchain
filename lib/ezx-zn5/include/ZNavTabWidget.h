//Fix for Motorola ZN5 by Ant-ON, 2009
//Fix for ZN5/U9 by Ant-ON, 25-10-2010
//Fix class size for ZN5 by Ant-ON, 26.09.2011

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZNAVTABWIDGET_H
#define ZNAVTABWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "qiconset.h"
#include "ZSkinBase.h"
#include "ZSkinService.h"
class ZNavTabBar;
class ZNavTabWidgetData;
class ZNavTab;
class ZNavWidgetStack;

//Size in ZN5: 0xF0

class ZNavTabWidget : public ZWidget
{
    Q_OBJECT

    unsigned char fix[0xF0-sizeof(ZWidget)];
public:
    enum TabPosition { TOP, BOTTOM };
    enum ButtonPos{NEIGHBOR,SEPARATE};

    ZNavTabWidget( QWidget *parent = 0, const char *name = 0,
        const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNavTabWidget);

    ZNavTabWidget(int nButtonPos,bool bHeaderVisible = false,bool bCountVisible = false,
       QWidget *parent=0, const char *name=0,
       const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNavTabWidget);

    void stopNextWhenKeyRepeat(bool bStop = FALSE);

    void setLabelCountVisible(bool bLabelCountVisible);

    void setSubHeaderVisible( bool bHeaderVisible);

    ~ZNavTabWidget();

    void addTab( QWidget *child, const QString &label);

    void addTab( QWidget *child, const QIconSet& iconset, const QString &label);

    void addTab( QWidget *child, ZNavTab *tab );

    void insertTab( QWidget *child, const QString &label, int index = -1);
    void insertTab( QWidget *child, const QIconSet& iconset, const QString &label, int index = -1);
    void insertTab( QWidget *child, ZNavTab *tab, int index = -1 );

    void changeTab( QWidget *w, const QString &label);

    void changeTab( QWidget *child, const QIconSet& iconset, const QString &label);

    bool isTabEnabled(  QWidget *w ) const;

    void setTabEnabled( QWidget *w, bool enable);

    void showPage( QWidget *w );

    void removePage( QWidget *w );

    QString tabLabel( QWidget *w ); 

    QWidget * currentPage() const;

    int currentPageIndex() const;

    void setCurrentPage( int id);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    TabPosition tabPosition() const;

    void setTabPosition( TabPosition pos);

    int margin() const;
    void setMargin( int w);

    QSizePolicy sizePolicy() const;

    void setSpacingH1(short nSpacing);

    short getSpacingH1()const;

    void  setEnabled(bool enable);

    bool  isZEnabled();
    bool  isZDisabled();
    
protected:
    void showEvent( QShowEvent * );
    void resizeEvent( QResizeEvent * );
    void setTabBar( ZNavTabBar* );

    ZNavTabBar* tabBar() const;
    void styleChange( QStyle& );
    void updateMask();
    bool eventFilter( QObject *, QEvent * );
    void paintEvent(QPaintEvent *);
    void updateSkin(bool redraw);
    virtual void setPalette(const QPalette &palette);

signals:
    void currentChanged( QWidget * );
    void selected( const QString& ); 

private slots:
    void showTab( int i );

    void scrollTabs();

//private:
//    ZNavTabWidgetData *d;
};
#endif 
