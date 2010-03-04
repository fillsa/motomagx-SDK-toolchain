//
// Writen by Ant-ON, 2010
//
// email: prozanton@gmail.com
//

#ifndef PUBLIC_JUMPBOX_H 
#define PUBLIC_JUMPBOX_H

#include "ZSkinService.h"
#include "ZWidget.h"
#include "ZLineEdit.h"
#include "qstring.h"

class ZInputField;
class ZJumpBoxPrivate;

class Q_EXPORT ZJumpBox: public ZWidget
{
	uint fix[10];
    Q_OBJECT
public:
	ZJumpBox(QWidget* parent, char const* name=0, WFlags f=0, ZSkinService::WidgetClsID = ZSkinService::clsZJumpBox, bool b=true);
	~ZJumpBox();
	
	void activate(QKeyEvent*);
	QRect getContentRect() const;
	void  getFrameWidth(int&, int&, int&, int&) const;
	QRect getIndicatorRect() const;
	ZInputField * getInputField();
	QSize getJumpBoxSize(int);
	QSize getJumpBoxSize(QSize const&) const;
	int   getLabelWidth();
	int   getLineEditHeight() const;
	ZLineEdit * lineEdit();
	void setLabelText(QString const&);
	void setMaxLength(int);

private:
    ZJumpBoxPrivate * d;
};

#endif
