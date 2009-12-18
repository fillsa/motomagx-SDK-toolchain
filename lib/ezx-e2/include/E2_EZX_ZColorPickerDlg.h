// _ZN15ZColorPickerDlgC4ERK6QColorPjiP7QWidgetPKcj
// _ZN15ZColorPickerDlgD4Ev

#ifndef _E2_EZX_ZCOLORPICKERDLG_H
#define _E2_EZX_ZCOLORPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qcolor.h>

class ZColorPickerDlg : public ZWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	ZColorPickerDlg(QColor const&, unsigned*, int, QWidget*, char const*, unsigned);
	~ZColorPickerDlg();
	QColor getColor();
/*
	int className() const
	int getColorModule()
	int initMetaObject()
	int initialize(QColor const&, unsigned*, int)
	int keyPressEvent(QKeyEvent*)
	int signalCenterSelKeyPressed()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int ~ZColorPickerDlg [in-charge deleting]()
	int ~ZColorPickerDlg [in-charge]()
*/
};

#endif
