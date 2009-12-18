#ifndef _ZSINGLESELECTDLG_H
#define _ZSINGLESELECTDLG_H

#include <ZPopup.h>

class ZListBox;

/* Size:216=54*4 */

class ZSingleSelectDlg : public ZPopup
{	
	Q_OBJECT
	unsigned int data[55-sizeof(ZPopup)/4];
public: 
	ZSingleSelectDlg(QWidget*, char const*, bool, unsigned int);
	ZSingleSelectDlg(QString const&, QString const&, QWidget* parent = NULL, const char* name = 0, bool modal = TRUE, WFlags f = 0, int auto_dismiss_time = 0);
	~ZSingleSelectDlg();

	ZListBox* getListBox();
	void initialize();
	bool eventFilter(QObject*, QEvent*);
	void addItemsList(QStringList&);
	int getCheckedItem();
	int getCheckedItemIndex();
	int checkCurHighlightItem();
	void showEvent(QShowEvent*);

public slots:
    virtual void slotLSKClicked();
	virtual void slotResizeAllChild(int);
signals:
	void signalCenterSelKeyPressed();
};
#endif

