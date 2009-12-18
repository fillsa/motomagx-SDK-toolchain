//Fix for Motorola ZN5 by Ant-ON

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef ZSCROLLPANEL_H
#define ZSCROLLPANEL_H

#include <ZWidget.h>
#include <ZScrollBar.h>

struct ZScrollPanelData;

class Q_EXPORT ZScrollPanel : public ZWidget
{
    Q_OBJECT

public:
    ZScrollPanel(QWidget *parent=0, const char *name=0, WFlags f=0, ZSkinService::WidgetClsID = ZSkinService::clsZScrollPanel);
    ~ZScrollPanel();
    virtual void updateSkin(bool redraw);
    virtual void removeChild(ZWidget* child);
    virtual void addChild( ZWidget* child, int x, int y );
    void addChild( QWidget* child, int x, int y )
	{
		addChild((ZWidget*)child,x,y);
	}
    virtual void moveChild( ZWidget* child, int x, int y );
    int childX(ZWidget* child);
    int childY(ZWidget* child);
    enum ScrollBarMode { Auto, AlwaysOff, AlwaysOn };
    virtual void  setVScrollBarMode( ScrollBarMode );
    virtual void  setHScrollBarMode( ScrollBarMode );
    ZScrollBar*  horizontalScrollBar() const;
    ZScrollBar*  verticalScrollBar() const;
    ZWidget*	 viewport() const;
    int		contentsWidth() const;
    int		contentsHeight() const;
    int		contentsX() const;
    int		contentsY() const;
    int		visibleWidth() const;
    int		visibleHeight() const;
    void	resize( int w, int h );
    void	resize( const QSize& );
    void	show();
    void	updateContents( int x, int y, int w, int h );
    void	updateContents( const QRect& r );
    void	repaintContents( int x, int y, int w, int h, bool erase=TRUE );
    void	repaintContents( const QRect& r, bool erase=TRUE );
    void	contentsToViewport(int x, int y, int& vx, int& vy);
    void	viewportToContents(int vx, int vy, int& x, int& y);
    QPoint	contentsToViewport(const QPoint&);
    QPoint	viewportToContents(const QPoint&);
    void	enableClipper(bool y);
    QSize	viewportSize( int, int ) const;
    QSizePolicy sizePolicy() const;
    QSize	sizeHint() const;
    QSize	minimumSizeHint() const;
    void setKeyScrollWrap(bool wrap);
    ZWidget* firstChild() const;
    ZWidget* lastChild() const;
    ZWidget* nextChild(ZWidget* child) const;
    void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);
    void setZBorder( BorderPixmaps& pixmaps);
     void setPalette( const QPalette & );

public:
    virtual bool  isScrollPanelTypeWidget() const;
    virtual void  resetFocusItem(bool);
    virtual QRect getCurrentFocusRect(bool) const;
	
	//???????
	void getLandscapeScroll() const;
	//???????
	
    virtual bool  hasNextPrevFocusItem(bool) const;
    void setNestScrollPanelMode(bool nest);
    virtual bool noFocusMode() const;
    void setAutoExpandInNestMode(bool expand);
    virtual QPixmap* getBgImageForTransparent(bool& freeImage);

public:
    virtual void setMargins(int left, int top, int right, int bottom);
    int leftMargin() const;
    int topMargin() const;
    int rightMargin() const;
    int bottomMargin() const;

signals:
    void	contentsResizing(ZScrollPanel*, int w, int h);

public slots:
    virtual void resizeContents( int w, int h );
    void	scrollBy( int dx, int dy );
    virtual void        setContentsPos( int x, int y );
    void	ensureVisible(int x, int y);
    void	ensureVisible(int x, int y, int xmargin, int ymargin);
    void	updateScrollBars();
    void	setEnabled( bool enable );

protected:
    void	resizeEvent(QResizeEvent*);
    void        keyPressEvent( QKeyEvent *e );
    bool	eventFilter( QObject *, QEvent *e );
    virtual void contentsMousePressEvent( QMouseEvent* );
    virtual void contentsMouseReleaseEvent( QMouseEvent* );
    virtual void contentsMouseDoubleClickEvent( QMouseEvent* );
    virtual void contentsMouseMoveEvent( QMouseEvent* );
    virtual void viewportPaintEvent( QPaintEvent* );
    virtual void viewportResizeEvent( QResizeEvent* );
    virtual void viewportMousePressEvent( QMouseEvent* );
    virtual void viewportMouseReleaseEvent( QMouseEvent* );
    virtual void viewportMouseDoubleClickEvent( QMouseEvent* );
    virtual void viewportMouseMoveEvent( QMouseEvent* );
    virtual void drawContentsOffset(QPainter*, int ox, int oy,
		    int cx, int cy, int cw, int ch);
    virtual void drawContents(QPainter*, int cx, int cy, int cw, int ch);
    bool focusNextPrevChild( bool next );
    enum ResizePolicy { Default, Manual, AutoOne, AutoOneFit  };
    virtual void setResizePolicy( ResizePolicy );
    ResizePolicy resizePolicy() const;
    virtual void setHBarGeometry(ZScrollBar& hbar, int x, int y, int w, int h);
    virtual void setVBarGeometry(ZScrollBar& vbar, int x, int y, int w, int h);
    virtual void insertFormItemChild(ZWidget *child,int x,int y,ZWidget *after = NULL);

private:
    void styleChange(QStyle&);

private:
    virtual void drawContents( QPainter* );
    void moveContents(int x, int y);
    ZScrollPanelData* d;

private slots:
    void slotContentsResizing(ZScrollPanel*, int, int);
    friend class ZScrollPanelData;
	
//private:
//	char data[100000];
};

#endif
