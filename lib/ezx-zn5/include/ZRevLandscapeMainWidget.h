//
// This header writed by Ant-ON, <prozanton@gmail.com>, 2010
//

#ifndef ZREVLANDSCAPEMAINWIDGET_H
#define ZREVLANDSCAPEMAINWIDGET_H

#include "ZMainWidget.h"

#include "qwidget.h"
#include "qobject.h"
#include "qevent.h"

class ZRevLandscapeMainWidget: public ZWidget
{
	uint fix[20];
	
	Q_OBJECT
	
	public:
		ZRevLandscapeMainWidget(QWidget*parent);
		~ZRevLandscapeMainWidget();

		void createLowerLandscapeSoftkey();
		void createUpperLandscapeSoftkey();
		void setWidgetBackground(QWidget*);
		void showLandscapeWidgets(bool);
		void updateLandscapeW(QString, QPixmap*);
		
	protected:
		void paintEvent(QPaintEvent*);	
		
	public slots:
		void slotFadeTimerAction();	
		
	signals:
		void landscapeSKPressed(bool, bool);
};
#endif
