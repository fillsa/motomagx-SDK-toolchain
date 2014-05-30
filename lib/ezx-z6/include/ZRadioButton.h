#ifndef __ZRADIOBUTTON_H_
#define __ZRADIOBUTTON_H_

#include <ZBaseButton.h>
#include <ZSkinBase.h>
#include <ZBaseButtonGroup.h>

/* Size: 284=71*4 */

class ZRadioButton: public ZBaseButton
{
	Q_OBJECT
	//unsigned int data[71-sizeof(ZBaseButton)/4];
public:
	virtual void ZRadioButton::setChecked(bool);

  ZRadioButton(const QString& text, QWidget*parent , char const* name = 0, ZSkinService::WidgetClsID = ZSkinService::clsZRadioButton);
  ZRadioButton(QWidget* parent, char const* name = 0, ZSkinService::WidgetClsID = ZSkinService::clsZRadioButton);
	~ZRadioButton();

	int checked(ZRadioButton*);
	void drawButton(QPainter*);
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void groupAlignment() const;
	int heightForWidth(int) const;
	bool hitButton(QPoint const&) const;
	int isZDisabled() const;
	int isZEnabled() const;
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void pixmap() const;
	void relativeAlignment() const;
	void resizeEvent(QResizeEvent*);
	void setEnabled(bool);
	void setGroupAlignment(Qt::AlignmentFlags);
	void setPalette(QPalette const&);
	void setPixmap(QPixmap const&);
	void setRelativeAlignment(ZSkinBase::RelativeAlignment);
	void setSkinFocusEffect(QFocusEvent*);
	void setSpacing(int, int);
	QSize sizeHint() const;
	QSizePolicy sizePolicy() const;
	void updateMask();
	void updateSkin(bool);
	
	//Add by Ant-ON. For compobility
	bool isChecked(){ return (state() == ZBaseButton::On);};
	
};

#endif
