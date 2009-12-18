#ifndef _E2_EZX_ZSCROLLPANEL_H
#define _E2_EZX_ZSCROLLPANEL_H

#include <E2_EZX_ZPanel.h>


class ZScrollPanel  : public ZPanel
{ 
	Q_OBJECT
  char tmp[4096];
public:
	ZScrollPanel(QWidget*, char const* = 0, unsigned = 0, ZSkinService::WidgetClsID = ZSkinService::clsZScrollPanel );  
	~ZScrollPanel();
	void addChild(ZWidget*, int, int);
	int visibleHeight() const;
	int visibleWidth() const;
	void removeChild(ZWidget*);
    ZWidget* firstChild() const;
    ZWidget* lastChild() const;
/*
	int autoExpandInNestMode() const
	int bottomMargin() const
	int center(int, int)
	int center(int, int, float, float)
	int childX(ZWidget*)
	int childY(ZWidget*)
	int className() const
	int clipper() const
	int contentsHeight() const
	int contentsMouseDoubleClickEvent(QMouseEvent*)
	int contentsMouseMoveEvent(QMouseEvent*)
	int contentsMousePressEvent(QMouseEvent*)
	int contentsMouseReleaseEvent(QMouseEvent*)
	int contentsMoving(int, int)
	int contentsResizing(ZScrollPanel*, int, int)
	int contentsToViewport(QPoint const&)
	int contentsToViewport(int, int, int&, int&)
	int contentsWidth() const
	int contentsX() const
	int contentsY() const
	int drawContents(QPainter*)
	int drawContents(QPainter*, int, int, int, int)
	int drawContentsOffset(QPainter*, int, int, int, int, int, int)
	int editCursorMove(bool)
	int enableClipper(bool)
	int ensureVisible(int, int)
	int ensureVisible(int, int, int, int)
	int eventFilter(QObject*, QEvent*)
	int firstChild() const
	int focusAreaBottom() const
	int focusAreaLeft() const
	int focusAreaRight() const
	int focusAreaTop() const
	int focusNextPrevChild(bool)
	int focusOutRange() const
	int getBgImageForTransparent(bool&)
	int hScrollBarMode() const
	int hasStaticBackground() const
	int horizontalScrollBar() const
	int hslide(int)
	int initMetaObject()
	int keyPressEvent(QKeyEvent*)
	int keyScrollWrap() const
	int lastChild() const
	int leftMargin() const
	int minimumSizeHint() const
	int moveChild(ZWidget*, int, int)
	int moveContents(int, int)
	int nestScrollPanelMode() const
	int nextChild(ZWidget*) const
	int prevChild(ZWidget*) const
	int prevNextWidget(ZWidget*, bool, bool&)
	int removeChild(ZWidget*)
	int repaintContents(QRect const&, bool)
	int repaintContents(int, int, int, int, bool)
	int resize(QSize const&)
	int resize(int, int)
	int resizeContents(int, int)
	int resizeEvent(QResizeEvent*)
	int resizePolicy() const
	int rightMargin() const
	int scrollBy(int, int)
	int setAutoExpandInNestMode(bool)
	int setContentsPos(int, int)
	int setEnabled(bool)
	int setFocusArea(int, int, int, int)
	int setFramesWidth(int, int, int, int)
	int setHBarGeometry(ZScrollBar&, int, int, int, int)
	int setHScrollBarMode(ZScrollPanel::ScrollBarMode)
	int setKeyScrollWrap(bool)
	int setMargins(int, int, int, int)
	int setMoveFocusOutRange(bool)
	int setNestScrollPanelMode(bool)
	int setResizePolicy(ZScrollPanel::ResizePolicy)
	int setStaticBackground(bool)
	int setVBarGeometry(ZScrollBar&, int, int, int, int)
	int setVScrollBarMode(ZScrollPanel::ScrollBarMode)
	int setZBorder(ZSkinBase::BorderPixmaps&)
	int setZBorder(ZWidgetBorderInfo*)
	int show()
	int sizeHint() const
	int sizePolicy() const
	int slotContentsResizeTimer()
	int slotContentsResizing(ZGroupBox*, int, int)
	int slotContentsResizing(ZMultiLineEdit*, int, int)
	int slotContentsResizing(ZScrollPanel*, int, int)
	int staticMetaObject()
	int styleChange(QStyle&)
	int topMargin() const
	int tr(char const*)
	int tr(char const*, char const*)
	int updateContents(QRect const&)
	int updateContents(int, int, int, int)
	int updateScrollBars()
	int updateSkin(bool)
	int vScrollBarMode() const
	int verticalScrollBar() const
	int viewport() const
	int viewportMouseDoubleClickEvent(QMouseEvent*)
	int viewportMouseMoveEvent(QMouseEvent*)
	int viewportMousePressEvent(QMouseEvent*)
	int viewportMouseReleaseEvent(QMouseEvent*)
	int viewportPaintEvent(QPaintEvent*)
	int viewportResizeEvent(QResizeEvent*)
	int viewportSize(int, int) const
	int viewportToContents(QPoint const&)
	int viewportToContents(int, int, int&, int&)
	int vslide(int)
	int ~ZScrollPanel [in-charge deleting]()
	int ~ZScrollPanel [in-charge]()
	*/
};
#endif
