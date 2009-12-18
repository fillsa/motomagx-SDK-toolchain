#ifndef _E2_EZX_MP_VIDEOWIDGET_H
#define _E2_EZX_VIDEOWIDGET_H

#include <qwidget.h>
#include <qcstring.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qstring.h>

class MP_VideoWidget : public QWidget
{
	Q_OBJECT
public:
	char tmp[4096];
	MP_VideoWidget(QWidget*, char const*, unsigned);
	~MP_VideoWidget();
	void drawFrame();
	int getColorMode();
    	
protected:
	virtual void focusInEvent( QFocusEvent * );
    	virtual void focusOutEvent( QFocusEvent * );
    	virtual void mousePressEvent( QMouseEvent * );
    	virtual void mouseReleaseEvent( QMouseEvent * );
    	virtual void paintEvent( QPaintEvent * );
    	virtual void resizeEvent( QResizeEvent * );
/*
	int clear()
	int clicked()
	int focusGot()
	int focusLost()
	int getColorMode()
	int lock()
	int pressAndHolded(QPoint const&)
	int setFitForScreen(bool)
	int setRotateFlag(Ezx_VideoDevice::RotateFlag)
	int unlock()
*/
};

#endif
