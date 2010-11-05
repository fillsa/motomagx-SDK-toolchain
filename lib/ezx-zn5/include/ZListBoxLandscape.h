//
// This header writed by Ant-ON, <prozanton@gmail.com>, 2010
//

#ifndef ZLISTBOXLANDSCAPE_H
#define ZLISTBOXLANDSCAPE_H

#include "ZScrollPanel.h"
#include "ZSkinService.h"
#include "ZListItem.h"
#include "ZListBox.h"

#include <qwidget.h>
#include <qstring.h>

class ZListBoxLandscape : public ZListBox
{
	uint fix[40];
	
	Q_OBJECT	
	
	public:
	
		enum DIALOG_TYPE_E
		{
			DIALOG,    // chameleon dialog
			NOTICE     // chameloen Notice
		};
	
		ZListBoxLandscape( QString type, QWidget* parent=0, WFlags f = 0, ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1);
		~ZListBoxLandscape();

		virtual void setCurrentItem(int);
		int radioItemChecked();
		ZListItem *item( int index ) const;
		void insertItem( const ZListItem * item, int index=-1, bool autoHighlighted = TRUE );
		void checkItem( int index, bool select);
		int currentItem() const;

		void resize( int w, int h );
		void resize( const QSize& );
		
		virtual void setHScrollBarMode(ZScrollPanel::ScrollBarMode);

		//??
		QString getContentText() const;
		void setContentText(QString const&);
		
		void getInstructHeight();
		void getListBox();
		void setGeometry ( int x, int y, int w, int h );
		void setTextColor(QColor const&);
		//
		
	protected:
		void paintEvent(QPaintEvent*);
		bool eventFilter(QObject*, QEvent*);
};

#endif
