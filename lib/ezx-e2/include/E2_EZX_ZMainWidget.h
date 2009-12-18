//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZWIDGET 下面凡是以？开头的注释都是猜测的用途，没有经过测试
// 完全新添加的类，
// _ZN11ZMainWidgetC4EbP7QWidgetPKcj
// _ZN11ZMainWidgetC4EP7QWidgetPKcj
// _ZN11ZMainWidgetC4ERK7QStringbP7QWidgetPKcj
// _ZN11ZMainWidgetD4Ev


#ifndef _E2_EZX_ZMAINWIDGET_H
#define _E2_EZX_ZMAINWIDGET_H

#include <qrect.h>
#include <qwidget.h>
#include <quuid.h>
#include <qvaluelist.h>
#include <qstring.h>
#include <qobject.h>
#include <qevent.h>
#include <qlabel.h>
#include <qpalette.h>
#include <qlayout.h>



class ZMainWidget : public QWidget
{
	Q_OBJECT
	char tmp[4096];
public:
	ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned);
	ZMainWidget(QWidget*, char const*, unsigned);
	ZMainWidget(bool, QWidget*, char const*, unsigned);
	QWidget* getContentWidget(bool);		// 新增参数 ？获得上下文的控件，
	void setInputMethod(QUuid const&, int); // 注意第二个参数可能和ZGlobal::KbFlags有关
	void setInputMethod(QWidget*, QUuid const&, int, QString);// 注意第三个参数可能和ZGlobal::KbFlags有关
	void setInputMethods(QWidget*, QUuid const&, int, QString);//新增函数  注意第三个参数可能和ZGlobal::KbFlags有关
	void setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString); // 新增函数  注意第四个参数可能和ZGlobal::KbFlags有关
	void objectDestroyed();
	void kbStateChanged(bool);
	virtual void show();
	void setFullScreenMode(bool, bool);		// 新增函数，？增加全屏模式，估计为了Java专门开设
	void setFavoriteInputMethods(QValueList<QUuid> const&);
	void setFavoriteInputMethods(QWidget*, QValueList<QUuid> const&);// 新增函数
	bool getEditMode();
	const QValueList<QUuid> getFavoriteInputMethods(); // 新增函数
	
	void showWithInputMethod(QUuid const&, int); // 注意第二个参数可能和ZGlobal::KbFlags有关
	virtual void fullScreenModeChanged(bool); // 新增函数 ？疑为全屏相应函数
	void setTitleBarWidget(QWidget*); // 新增函数
	virtual void invokeInputWidget();
	QVBoxLayout* getVBoxLayout();			// 新增函数  ？获得布局方式
	virtual void slotKbStateChanged(bool, QUuid const&, int); // 新增函数
//	const QCString className(); // 新增函数
	int getLRSBaseIndex(); // 新增函数
	void popupKBMenu();
	void kbStateChanged(bool, QUuid const&, int);
	
	virtual void slotPopupMenu(int);
	virtual bool eventFilter(QObject*, QEvent*); // 新增函数
	bool getKbState();
	virtual void slotKbWidgetSizeChanged(QRect const&, int, bool, bool); // 新增函数
	bool getFullScreenMode();	// 新增函数
	virtual void setupInputMethodsPopupMenu();
	virtual bool setCSTWidget(QWidget*);
	QWidget* getCSTWidget(bool);
	virtual void paletteChange(QPalette const&);
	QLabel* getTitleBarWidget();
	virtual bool setContentWidget(QWidget*);
	virtual bool mainWidgetSizeChanged(int, QRect const&);	// 新增函数
	virtual void hide();
	virtual void hideInputWidget();
	void init(bool, QString const&);
};
#endif
