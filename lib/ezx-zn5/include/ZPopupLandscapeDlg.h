//
// This header writed by Ant-ON, <prozanton@gmail.com>, 2010
//

#ifndef ZPOPUPLANDSCAPEDLG_H
#define ZPOPUPLANDSCAPEDLG_H

#include <qpixmap.h>

#include "ZPopupLandscape.h"

class ZPopupLandscapeDlg : public ZPopupLandscape
{
	Q_OBJECT
	
	public:
	
		enum POPUP_NOTICE_TYPE
		{
		};
		
		enum POPUP_DLG_TYPE
		{
			BUTTON_OK_CANCEL, //Confirmation Dialog
			BUTTON_YES_NO, //Choose an Action Dialog
			BUTTON_OK, //OK Dialog
			BUTTON_CANCEL, 
			BUTTON_CANCEL_HIDE, //Wait dlg
			BUTTON_NO,
			BUTTON_NO_PROGRESSBAR, //Wait + ProgressBar + No SoftKey Caption
			BUTTON_OK_INFORMATION, //OK Dialog + "i" icon
		};
	
		ZPopupLandscapeDlg(POPUP_NOTICE_TYPE, int, const QString& title = QString::null, const QString& text = QString::null, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0);
		ZPopupLandscapeDlg(POPUP_NOTICE_TYPE, const QString& str1 = QString::null, const QString& str2 = QString::null, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0, bool);	
		ZPopupLandscapeDlg(QPixmap const&, POPUP_NOTICE_TYPE, int, const QString& str1 = QString::null, const QString& str2 = QString::null, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0);
		ZPopupLandscapeDlg(const QString& str1 = QString::null, const QString& str2 = QString::null, POPUP_DLG_TYPE, int, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0);
		ZPopupLandscapeDlg(QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0);
		~ZPopupLandscapeDlg();
		
		void setInstructText(QString const&);
		void setTitle(QString const&);
		
		void setTitleIcon(QPixmap const&);
		void setTitleIcon(QString const&);
			
		void setMessage(QString const&);
		
		void setProgressAnimation();
		void setProgressBarStep(int);
		void setTitleAnimationIcon(QString const&);

		void connectCustomSoftkeys(bool, bool, QString const&, QString const&);
		
	private:
		void initDialogType(POPUP_DLG_TYPE);
		void initNoticeType(POPUP_NOTICE_TYPE);
		void initProgressBar(int);		
};

#endif

