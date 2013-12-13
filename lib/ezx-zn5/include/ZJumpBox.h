//
// Writen by Ant-ON, 2010
//
// email: prozanton@gmail.com
//
//Fix class size for ZN5 by Ant-ON, 26.09.2011


#ifndef PUBLIC_JUMPBOX_H 
#define PUBLIC_JUMPBOX_H

#include "ZSkinService.h"
#include "ZWidget.h"
#include "ZLineEdit.h"
#include "qstring.h"

class ZInputField;
class ZJumpBoxPrivate;

//Size in ZN5: 0xF0

class Q_EXPORT ZJumpBox: public ZWidget
{
    Q_OBJECT

	unsigned char fix[0xF0-sizeof(ZWidget)];
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

//private:
//    ZJumpBoxPrivate * d;
};

#endif
