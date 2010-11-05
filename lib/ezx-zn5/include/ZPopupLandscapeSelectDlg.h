//
// This header writed by Ant-ON, <prozanton@gmail.com>, 2010
//

#ifndef ZPOPUPLANDSCAPESELECTDLG_H
#define ZPOPUPLANDSCAPESELECTDLG_H

#include "ZPopupLandscape.h"

class ZListItem;

class ZPopupLandscapeSelectDlg : public ZPopupLandscape
{
	Q_OBJECT
	
	public:
		ZPopupLandscapeSelectDlg(const QString& strDlgTitle, const QString& strInstructText, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0, int auto_dismiss_time = 0);
		ZPopupLandscapeSelectDlg(QWidget* parent = NULL, char const* name = 0, bool modal = TRUE, WFlags f = 0);
		~ZPopupLandscapeSelectDlg();	
	
		void addItemsList(QStringList&);
		int getCheckedItemIndex();
		ZListItem* getCheckedItem();
		
		void setTitle(QString const&);
		void setInstructText(QString const&);
		
		void setSoftkeyText(QString const&, QString const&);
		
		void initializeListBox();
		
	private:
		void checkCurHighlightItem();

	signals:
		void signalCenterSelKeyPressed();
		
	protected:
		virtual bool eventFilter(QObject*, QEvent*);
		virtual void showEvent(QShowEvent*);
		
	protected slots:
		void slotLowerSoftkeyClicked();
		void slotUpperSoftkeyClicked();	
};

#endif
