// _ZN16ZSingleSelectDlgC4EP7QWidgetPKcbj
// _ZN16ZSingleSelectDlgC4ERK7QStringS2_P7QWidgetPKcbji
// _ZN16ZSingleSelectDlgD4Ev

#ifndef _E2_EZX_ZSINGLESELECTDLG_H
#define _E2_EZX_ZSINGLESELECTDLG_H

#include <qstring.h>
#include <qlistbox.h>
#include <qwidget.h>
#include <E2_EZX_ZListBox.h>

class ZSingleSelectDlg :public QWidget
{	
	Q_OBJECT
public: 
	char tmp[512];

	ZSingleSelectDlg(QString const&, QString const&, QWidget*, char const*, bool, unsigned, int);
	ZSingleSelectDlg(QWidget*, char const*, bool, unsigned);
	~ZSingleSelectDlg();
	void addItemsList(QStringList&);
	ZListBox* getListBox();
	int getCheckedItemIndex();
/*
	int checkCurHighlightItem()
	int className() const
	int eventFilter(QObject*, QEvent*)
	int getCheckedItem()
	int getCheckedItemIndex()
	int initMetaObject()
	int initialize()
	int showEvent(QShowEvent*)
	int signalCenterSelKeyPressed()
	int slotLSKClicked()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int ~ZSingleSelectDlg [in-charge deleting]()
	int ~ZSingleSelectDlg [not-in-charge]()
	*/
};
#endif
