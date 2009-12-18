// _ZN14ZDatePickerDlgC4EP11ZDateModuleP7QWidgetPKcbj
// _ZN14ZDatePickerDlgD4Ev

#ifndef _E2_EZX_ZDATAPICKERDLG_H
#define _E2_EZX_ZDATAPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qdatetime.h>
#include <E2_EZX_ZWidget.h>

class ZDateModule : public ZWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	ZDateModule(QWidget*, char const*, unsigned, ZSkinService::WidgetClsID);
	void setDateValue(QDate);
/*
	ZDateModule(QDate, QDate, QDate, QWidget*, char const*, unsigned, ZSkinService::WidgetClsID)
	int ZDateModule[not-in-charge](QDate, QDate, QDate, QWidget*, char const*, unsigned, ZSkinService::WidgetClsID)
	int ZDateModule[not-in-charge](QWidget*, char const*, unsigned, ZSkinService::WidgetClsID)
	int autoResize() const
	int className() const
	int dateModuleSizeChange()
	int focusInEvent(QFocusEvent*)
	int getDate()
	int getPicker()
	int hasFocus() const
	int initMetaObject()
	int minimumSizeHint() const
	int paintEvent(QPaintEvent*)
	int resizeAll()
	int resizeEvent(QResizeEvent*)
	int setAutoResize(bool)
	int setEndDate(QDate)
	int setLabel(ZLabel*, ZDateModule::RelativeAlignment)
	int setPalette(QPalette const&)
	int setSeparatorString(QString, QString)
	int setStartDate(QDate)
	int setWrapping(bool)
	int sizeHint() const
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int updateSkin(bool)
	int ~ZDateModule [in-charge deleting]()
	int ~ZDateModule [in-charge]()
	int ~ZDateModule [not-in-charge]()
*/
};

class ZDatePickerDlg : public QWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	ZDatePickerDlg(ZDateModule*, QWidget*, char const*, bool, unsigned);
	QDate getResultDate();
/*
	int getDateModule()
	int className() const
	int initMetaObject()
	int signalCenterSelKeyPressed()
	int slotCenterSelKeyPressed()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int ~ZDatePickerDlg [in-charge deleting]()
	int ~ZDatePickerDlg [in-charge]()
	int ~ZDatePickerDlg [not-in-charge]()
*/
};

#endif

