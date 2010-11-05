//
// This header writed by Ant-ON, <prozanton@gmail.com>, 2010
//

#ifndef ZOPTIONSLANDSCAPEMENU_H
#define ZOPTIONSLANDSCAPEMENU_H

#include "ZOptionsMenu.h"

#include <qobject.h>
#include <qevent.h>
#include <qlist.h>
#include <qrect.h>
#include <qpoint.h>

class ZSoftKeyL;
class ZOptionsLandscapeMenuItem;
class MenuItem;
class ZOptMenuParser;

class ZOptionsLandscapeMenu : public ZWidget
{
    Q_OBJECT

	public:

		ZOptionsLandscapeMenu( QRect & limitRect, QWidget * parent = 0, const char * name = 0, WFlags f = 0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsZOptionsMenu );
		ZOptionsLandscapeMenu( QRect & limitRect, QWidget * parent, const char * name, WFlags f, const ZSkinService::WidgetClsID clsId, ZOptMenuParser * parserClass, QString menuName);
		~ZOptionsLandscapeMenu();

		void connectItem( int id, const QObject * receiver, const char * memberFunc );
		void disconnectItem( int id, const QObject * receiver, const char * memberFunc );		

		bool isItemEnabled(int id) const;
		void setActiveItem(int id);
		void setItemEnabled(int id, bool e);
		void setItemHide(int id, bool h);

		void setPosition(ZOptionsMenu::CornerE, QPoint&);

		// ???
		void backOneMenu();
		void removeMenu();
		void hideMainMenu();
		
		void genMenu(QRect&, QList<MenuItem>);
		void hideNestedMenu(ZOptionsLandscapeMenuItem*);
		void mainMenuParent();
		void positionSubmenus();
		
		void setUpSoftkeyL(ZSoftKeyL*);
		
		void keyReleaseKeyUp();
		void keyReleaseKeyDown();
		//
	
	private:
		void initShow();
		void updateSize();
		void updateMask();
		
	protected slots:
		void slotRestoreUpSoftkeyLText();
		void slotSetUpSoftkeyLText();
		void updateVisibleItems(int, bool);	
		void updateVisibleItemList(int, bool);
		
	
	protected:	
		void keyPressEvent(QKeyEvent*);
		void keyPressKeyLeft(QKeyEvent*);
		void keyPressKeyRight(QKeyEvent*);
		void keyReleaseEvent(QKeyEvent*);
		void keyReleaseKeyLeftSoftKey(QKeyEvent*);
		void focusInEvent(QFocusEvent*);
		void focusOutEvent(QFocusEvent*);
		void paintEvent(QPaintEvent*);
		void drawScrollIndicator(QPainter*);
};

#endif
