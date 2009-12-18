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
	void *data;
public:
	ZColorPickerDlg(QColor const&, unsigned*, int, QWidget*, char const*, unsigned);
	~ZColorPickerDlg();
	QColor getColor();
};

#endif
