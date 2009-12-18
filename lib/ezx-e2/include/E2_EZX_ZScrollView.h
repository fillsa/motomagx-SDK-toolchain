//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// _ZN11ZScrollViewC4EP7QWidgetPKcj
// _ZN11ZScrollViewD4Ev 

#ifndef _E2_EZX_ZScrollView_H
#define _E2_EZX_ZScrollView_H

#include <qwidget.h>
#include <qstring.h>
#include <qscrollview.h>

class ZScrollView : public QScrollView
{
	Q_OBJECT
	char tmp[4096];
public:
	ZScrollView(QWidget* parent = 0, const char* name = 0, WFlags f = 0);
	~ZScrollView();	
	void addChild(QWidget*, int, int);
 	void setAutoLayout(bool);	
	void resizeContents(int, int);
	void doLayout(QWidget*, QSize, QPoint, int);
	void setMargins(int, int, int, int);
 	/*	int addChild(QWidget*, int, int, bool)
	int className() const
	int doLayout(QWidget*, QSize, QPoint, int)
	int drawContents(QPainter*, int, int, int, int)
	int enableClipper(bool)
	int event(QEvent*)
	int eventFilter(QObject*, QEvent*)
	int focusNextPrevChild(bool)
	int getAutoLayout() const
	int getFlushEvents() const
	int hide()
	int initMetaObject()
	int keyPressEvent(QKeyEvent*)
	int makeFocusWidgetVisible(bool)
	int moveChild(QWidget*, int, int, bool)
	int nextFocusWidget(bool)
	int nextFocusWidgetVisible(bool)
	int removeSVChild(QWidget*)
	int resizeEvent(QResizeEvent*)
	int setAutoScroll(bool)
	int setBackGroundPixmap(QPixmap const&)
	int setFlushEvents(bool)
	int setMargins(int, int, int, int)
	int setNoFocusChange(bool)
	int show()
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int updateContentSize()
	int updateFieldsWidth(int)
	int vScrollBarStateChanged(int)
	int ~ZScrollView [in-charge deleting]()
	int ~ZScrollView [in-charge]() 
	*/
};
#endif
