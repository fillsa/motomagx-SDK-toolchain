// _ZN14ZTimePickerDlgC4EP11ZTimeModuleP7QWidgetPKcj
// _ZN14ZTimePickerDlgD4Ev

#ifndef _E2_EZX_ZTIMEPICKERDLG_H
#define _E2_EZX_ZTIMEPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qdatetime.h>
#include <E2_EZX_ZWidget.h>

class ZTimeModule : public ZWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	ZTimeModule(QTime, QWidget*, char const*, unsigned, ZSkinService::WidgetClsID);
	void setStartTime(QTime);
/*	int ZTimeModule(QTime, QTime, QTime, QWidget*, char const*, unsigned, ZSkinService::WidgetClsID)
	int ZTimeModule(QWidget*, char const*, unsigned, ZSkinService::WidgetClsID)
	int autoResize() const
	int className() const
	int focusInEvent(QFocusEvent*)
	int getPicker()
	int getTime()
	int hasFocus() const
	int hourLineStep()
	int initMetaObject()
	int minimumSizeHint() const
	int minuteLineStep()
	int paintEvent(QPaintEvent*)
	int resizeAll()
	int resizeEvent(QResizeEvent*)
	int setAutoResize(bool)
	int setEndTime(QTime)
	int setHourLineStep(int)
	int setLabel(ZLabel*, ZTimeModule::RelativeAlignment)
	int setMinuteLineStep(int)
	int setPalette(QPalette const&)
	int setSeparatorString(QString)
	int setTimeValue(QTime)
	int setWrapping(bool)
	int sizeHint() const
	int staticMetaObject()
	int timeModuleSizeChange()
	int tr(char const*)
	int tr(char const*, char const*)
	int updateSkin(bool)
	int ~ZTimeModule [in-charge deleting]()
	int ~ZTimeModule [in-charge]()
	int ~ZTimeModule [not-in-charge]()
*/
};

class ZTimePickerDlg : public QWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	ZTimePickerDlg(ZTimeModule*, QWidget*, char const*, unsigned);
	~ZTimePickerDlg();
	QTime getTime();
	ZTimeModule* getTimeModule();
	void initialize(ZTimeModule*);
	virtual void keyPressEvent(QKeyEvent*);
	void setTimeModule(ZTimeModule*);
signals:
	void signalCenterSelKeyPressed();
public slots:
	void slotCenterSelKeyPressed();
	void slotResizeAllChild(int);
};

#endif
