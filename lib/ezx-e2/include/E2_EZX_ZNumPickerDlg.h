// _ZN13ZNumPickerDlgC4EiP7QWidgetPKcj
// _ZN13ZNumPickerDlgD4Ev

#ifndef _E2_EZX_ZNUMPICKERDLG_H
#define _E2_EZX_ZNUMPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <E2_EZX_ZWidget.h>

class ZNumModule : public ZWidget
{
	Q_OBJECT
public:
	char tmp[4096];
		ZNumModule( 
		int nMaxLen,
		QWidget *parent = 0, 
		const char *name = 0,  
		WFlags f = 0 ,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNumModule); 
	~ZNumModule();
	int getValue();
	int maxValue();
	int minValue();
	void setMaxValue(int);
	void setMinValue(int);
	void setValue(int);
/*
	int autoResize() const
	int className() const
	int focusInEvent(QFocusEvent*)
	int getPicker()
	int initMetaObject()
	int lineStep()
	int minimumSizeHint() const
	int numModuleSizeChange()
	int paintEvent(QPaintEvent*)
	int resizeAll()
	int resizeEvent(QResizeEvent*)
	int setAutoResize(bool)
	int setLabel(ZLabel*, ZNumModule::RelativeAlignment)
	int setLineStep(int)
	int setPalette(QPalette const&)
	int setWrapping(bool)
	int sizeHint() const
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int updateSkin(bool)
	int valueChange(int)
	int valueChanged(int)
	int wrapping()
	int ~ZNumModule [in-charge deleting]()
	int ~ZNumModule [in-charge]()
*/
};

class ZNumPickerDlg : public QWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	ZNumPickerDlg(int nMaxLen,QWidget* parent = 0, const char* name = 0, WFlags f = 0);
	~ZNumPickerDlg();
	int getNumValue();
	void initialize(int);
	ZNumModule* getNumModule();
/*
	int className() const
	int initMetaObject()
	int initialize(int)
	int keyPressEvent(QKeyEvent*)
	int signalCenterSelKeyPressed()
	int slotCenterSelKeyPressed()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int ~ZNumPickerDlg [in-charge deleting]()
	int ~ZNumPickerDlg [in-charge]()
*/
};
#endif
