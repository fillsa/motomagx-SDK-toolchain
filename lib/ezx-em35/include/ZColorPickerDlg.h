//Fix for EM35/VE66 by Ant-ON, 30-08-2011

#ifndef _ZCOLORPICKERDLG_H
#define _ZCOLORPICKERDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qcolor.h>

#include <ZPopup.h>

class ZColorModule;

class ZColorPickerDlg : public ZPopup
{
	Q_OBJECT
	void *data;
	
public:
	ZColorPickerDlg(QColor const&, unsigned*, int, QWidget* parent = 0, char const* name = 0, WFlags f = 0, Qt::DisplayID dislayId = MainDisplay);
	virtual ~ZColorPickerDlg();
	
	ZColorModule* getColorModule();
	
	QColor getColor();

protected:
    virtual void keyPressEvent(QKeyEvent*);
    
signals:	
	void signalCenterSelKeyPressed();
};

#endif
