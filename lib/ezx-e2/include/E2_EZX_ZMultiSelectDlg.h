// _ZN15ZMultiSelectDlgC4EP7QWidgetPKcbj
// _ZN15ZMultiSelectDlgC4ERK7QStringS2_P7QWidgetPKcbji
// _ZN15ZMultiSelectDlgD4Ev


#ifndef _E2_EZX_ZMULTISELECTDLG_H
#define _E2_EZX_ZMULTISELECTDLG_H

#include <qstring.h>
#include <qwidget.h>
#include <E2_EZX_ZListBox.h>

class ZMultiSelectDlg : public QWidget
{
	Q_OBJECT
public: 
	char tmp[8096];
	ZMultiSelectDlg(QString const&, QString const&, QWidget*, char const*, bool, unsigned, int);
	ZMultiSelectDlg(QWidget*, char const*, bool, unsigned);
	~ZMultiSelectDlg();
	ZListBox* getListBox();
	void addItemsList(QStringList&);
	int getCheckedItemCount();
	/*
	int checkAllListBoxItem(bool)
	int className() const
	int enableMenuItem(ZMultiSelectDlg::MENU_INDEX_E, bool)
	int enableRSKdefaultBehavior(bool)
	int eventFilter(QObject*, QEvent*)
	int getCheckedItemCount()
	int getListBox()
	int initAIAinfo()
	int initBodyArea()
	int initMetaObject()
	int initSoftKeyArea()
	int initialize()
	int setMenuSlot(ZMultiSelectDlg::MENU_INDEX_E, QObject const*, char const*, bool)
	int setRightBtnPrompt(QString const&)
	int showEvent(QShowEvent*)
	int slotItemStateChanged()
	int slotMenuItemClick(int)
	int slotRSKClicked()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int updateAppInfoArea(int)
	int updateUI()
	int updateUIinfo()
	int ~ZMultiSelectDlg [in-charge deleting]()
	int ~ZMultiSelectDlg [in-charge]()
*/
};
#endif
