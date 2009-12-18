
#ifndef _E2_EZX_ZCOMBOBOX_H
#define _E2_EZX_ZCOMBOBOX_H

#include <E2_EZX_ZWidget.h>

class ZComboBox : public ZWidget
{
	Q_OBJECT
	char tmp[4096];
public:
	enum DlgType
	{
		NONE,
		TEXT
	};
	ZComboBox(QWidget*, char const*, bool);
	ZComboBox(bool, QWidget*, char const*, bool);
	~ZComboBox();
	void insertItem(QString const&, int);
	void setCurrentItem(int);
	void setDlgTitle(QString const&, ZComboBox::DlgType);
	QRect getContentRect() const;
	void setGeometry(QRect const&);
	virtual void textChanged(QString const&);
	virtual void titleChanged(QString const&);
	int getBtnHSpacing() const;
	int currentItem() const;
	void setSizeLimit(int);
	void clear();
/*
	int activated(QString const&)
	int activated(int)
	int autoCompletion() const
	int changeItem(QPixmap const&, QString const&, int)
	int changeItem(QPixmap const&, int)
	int changeItem(QString const&, int)
	int className() const
	int clear()
	int clearValidator()
	int count() const
	int currentItem() const
	int currentText() const
	int customEvent(QCustomEvent*)
	int drawBackgroundEx(ZButton::ItemType, QPainter*, QRect const*)
	int drawBorderEx(ZButton::ItemType, QPainter*, QRect const*)
	int duplicatesEnabled() const
	int editable() const
	int eventFilter(QObject*, QEvent*)
	int getBtnFrameWidth(int&, int&, int&, int&) const
	int getContentRect() const
	int getCurrentFont(QFont&, QColor&, ZButton::ItemType) const
	int getFrameWidth(int&, int&, int&, int&) const
	int getItemType(ZListBoxItem*) const
	int getLabelFrameWidth(int&, int&, int&, int&) const
	int getTitleSpacing(ZButton::TitlePosition) const
	int highlighted(QString const&)
	int highlighted(int)
	int initMetaObject()
	int insertItem(QPixmap const&, QString const&, int)
	int insertItem(QPixmap const&, int)
	int insertItem(QString const&, int)
	int insertStrList(QStrList const&, int)
	int insertStrList(QStrList const*, int)
	int insertStrList(char const**, int, int)
	int insertStringList(QStringList const&, int)
	int insertZItem(QPixmap const&, QString const&, int, int)
	int insertZItem(QPixmap const&, int, int)
	int insertZItem(QString const&, int, int)
	int insertionPolicy() const
	int keyPressEvent(QKeyEvent*)
	int lineEdit() const
	int listBox() const
	int maxCount() const
	int pixmap(int) const
	int popup(bool)
	int removeItem(int)
	int resize(QSize const&)
	int resize(int, int)
	int resizeEvent(QResizeEvent*)
	int setAutoCompletion(bool)
	int setDlgInstructText(QString const&, ZComboBox::DlgType)
	int setDlgTitle(QString const&, ZComboBox::DlgType)
	int setDuplicatesEnabled(bool)
	int setEditable(bool)
	int setGeometry(QRect const&)
	int setGeometry(int, int, int, int)
	int setInsertionPolicy(ZComboBox::Policy)
	int setMaxCount(int)
	int setPalette(QPalette const&)
	int setSizeLimit(int)
	int setSoftkeyText(QString const&, QString const&, ZComboBox::DlgType)
	int setSoftkeyTextLeft(QString const&, ZComboBox::DlgType)
	int setSoftkeyTextRight(QString const&, ZComboBox::DlgType)
	int setValidator(QValidator const*)
	int showEvent(QShowEvent*)
	int sigInsertData(QWidget*, bool)
	int sizeLimit() const
	int slotClearKeyClick()
	int stateChanged(ZButton::StateChangeReason)
	int staticMetaObject()
	int styleChange(QStyle&)
	int text(int) const

	int tr(char const*)
	int tr(char const*, char const*)
	int updateSkin(bool)
	int validator() const
	int ~ZComboBox [in-charge deleting]()
	int ~ZComboBox [in-charge]()
	int ~ZComboBox [not-in-charge]()
*/
};

#endif

