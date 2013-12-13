#ifndef _ZCOLORPICKERDLG_H
#define _ZCOLORPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qcolor.h>

#include <ZPopup.h>

/* Size: 216=54*4 */

class ZColorPickerDlg : public ZPopup
{
	Q_OBJECT
	//unsigned int data[54 - sizeof(ZPopup)];
public:
	ZColorPickerDlg(QColor const&, unsigned* = NULL, int = 0, QWidget* = 0, char const* = 0, unsigned = 0);
	~ZColorPickerDlg();
	QColor getColor();
};

#endif
