
#ifndef _E2_EZX_ZCHECKBOX_H
#define _E2_EZX_ZCHECKBOX_H

#include <E2_EZX_ZComboBox.h>
#include <ZBaseButton.h>

class ZCheckBox: public ZBaseButton //public ZComboBox
{
	Q_OBJECT
	char tmp[4096];
public:
	ZCheckBox(QString const&, QWidget*, char const*);
	ZCheckBox(QWidget*, char const*);
	~ZCheckBox();
/*
	int className() const
	int drawButton(QPainter*)
	int focusInEvent(QFocusEvent*)
	int focusOutEvent(QFocusEvent*)
	int getCheckBtnRect() const
	int getContentRect() const
	int getFrameWidth(int&, int&, int&, int&) const
	int getTitleRect() const
	int getTitleSize() const
	int groupAlignment() const
	int heightForWidth(int) const
	int initMetaObject()
	int isTristate() const
	int isZDisabled() const
	int isZEnabled() const
	int keyPressEvent(QKeyEvent*)
	int keyReleaseEvent(QKeyEvent*)
	int pixmap() const
	int relativeAlignment() const
	int resize(int, int)
	int resizeEvent(QResizeEvent*)
	int setEnabled(bool)
	int setFormItemSpacing(int)
	int setGeometry(QRect const&)
	int setGeometry(int, int, int, int)
	int setGroupAlignment(Qt::AlignmentFlags)
	int setNoChange()
	int setPalette(QPalette const&)
	int setPixmap(QPixmap const&)
	int setRelativeAlignment(ZSkinBase::RelativeAlignment)
	int setSkinFocusEffect(QFocusEvent*)
	int setSpacing(int, int)
	int setTitle(QString const&)
	int setTitlePosition(ZCheckBox::TitlePosition)
	int setTristate(bool)
	int sizeHint() const
	int staticMetaObject()
	int title() const
	int titlePosition() const
	int tr(char const*)
	int tr(char const*, char const*)
	int updateSkin(bool)
	int ~ZCheckBox [in-charge deleting]()
	int ~ZCheckBox [in-charge]()
*/
};

#endif
