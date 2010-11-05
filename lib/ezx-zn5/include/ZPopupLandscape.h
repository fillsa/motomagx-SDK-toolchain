//
// This header writed by Ant-ON, <prozanton@gmail.com>, 2010
//

#ifndef ZPOPUPLANDSCAPE_H
#define ZPOPUPLANDSCAPE_H

#include <qdialog.h>
#include <qobject.h>
#include <qevent.h>
#include "ZListBoxLandscape.h"

class ZPopupLandscape : public QDialog
{
	Q_OBJECT
	
	public:
	
		enum DIALOG_TYPE_E
		{
		};
	
		enum POPUP_ACTION_E
		{
		};
		
		enum NOTICE_TYPE_E
		{
		};	
		
		enum POPUP_TYPE_E
		{
			DIALOG,
			NOTICE
		};
		
		ZPopupLandscape(POPUP_TYPE_E type = DIALOG, QWidget* parent = 0, char const* name = 0, bool modal = true, int dismiss_time = 0, WFlags f = 0);
		~ZPopupLandscape();
			
		int exec();
		void hide();
		void show();
		
		void setAutoDismissTimer(int);
		void setDismissTimer(int);
		void dlgDismissed();
		
		void setDialogType(DIALOG_TYPE_E);
		void setNoticeType(NOTICE_TYPE_E);
		
		void setContentMessage(QString const&);
		void setContentPixmap(QPixmap const&);
		void setContentProgressAnimation(QPixmap const&);
		void setContentProgressAnimation(QString const&);
		void setContentProgressBar(int, int);
		void setContentProgress(int);
		
		void setHeaderAnimationIcon(QString const&);
		void setHeaderIcon(QPixmap const&);
		void setHeaderIcon(QString const&);
		void setHeaderText(QString const&);
		
		void createLandscapeSoftkeys();
		void connectSoftkeySlot(bool, bool);
		void disableSoftkeys(bool, bool, bool);
		void hideSoftkeys(bool, bool, bool);
		void setSoftkeyLowerText(QString const&);
		void setSoftkeyText(QString const&, QString const&);
		void setSoftkeyUpperText(QString const&);
		
		ZListBoxLandscape * /*???*/ getLandscapeListBox();
		void getListBox();
		void updateListBox();
		
		bool hasInputFocus();
		
		void installDlgEventFilter(QObject const*);
			
		void updateFullScreenGeometry();
		void updateGeometry();
		
		void updateMask();

	public slots:
		void accept();
		void reject();
		void done(POPUP_ACTION_E);
		
	signals:
		void askReturnToIdle(int);	
		void leftSoftkeyClicked();
		void rightSoftkeyClicked();
		void signalCenterSelKeyPressed();
		void signalClearKeyPressed();
						
	protected:
		virtual void customEvent(QCustomEvent*);
		virtual void keyPressEvent(QKeyEvent*);
		virtual void keyReleaseEvent(QKeyEvent*);
		virtual void paintEvent(QPaintEvent*);	
		
	protected slots:
		void slotAutoTimerAction();
		void slotLowerSoftkeyClicked();
		void slotTimerAction();
		void slotUpperSoftkeyClicked();			
};

#endif
