#ifndef _ZMULTISELECTDLG_H
#define _ZMULTISELECTDLG_H

#include <ZPopup.h>

class ZListBox;

/* Size: 284=71*4 */

class ZMultiSelectDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[71 - sizeof(ZPopup)/4];
public:
	enum MENU_INDEX_E {
	};

	ZMultiSelectDlg(QString const&, QString const&, QWidget*, char const*, bool, unsigned, int);
	ZMultiSelectDlg(QWidget*, char const*, bool, unsigned);
	~ZMultiSelectDlg();

	ZListBox* getListBox();
	void initialize();
	bool eventFilter(QObject*, QEvent*);
	void initAIAinfo();
	void setMenuSlot(ZMultiSelectDlg::MENU_INDEX_E, QObject const*, char const*, bool);
	void addItemsList(QStringList&);
	void initBodyArea();
	void updateUIinfo();
	void enableMenuItem(ZMultiSelectDlg::MENU_INDEX_E, bool);
	virtual void slotRSKClicked();
	void initSoftKeyArea();
	void setRightBtnPrompt(QString const&);
	void slotMenuItemClick(int);
	void updateAppInfoArea(int);
	virtual void slotResizeAllChild(int);
	void checkAllListBoxItem(bool);
	int  getCheckedItemCount();
	void slotItemStateChanged();
	void enableRSKdefaultBehavior(bool);
	void updateUI();
	void showEvent(QShowEvent*);
};
#endif
