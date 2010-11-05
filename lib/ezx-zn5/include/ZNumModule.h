//Chenge fix by Ant-ON, 11.08.2010

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZNUMMODULE_H
#define PUBLIC_API_WIDGET_ZNUMMODULE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZNumPicker.h"
#include "ZSkinBase.h"
#include "ZLabel.h"

/*
vtable for ZNumModule@@VERSION		 // OBJECT
ZNumModule::getPicker()@@VERSION		 // FUNC
ZNumModule::getSpacingH1() const@@VERSION		 // FUNC
ZNumModule::getValue()@@VERSION		 // FUNC
ZNumModule::setLabel(ZLabel*, ZNumModule::RelativeAlignment)@@VERSION		 // FUNC
ZNumModule::setMaxValue(int)@@VERSION		 // FUNC
ZNumModule::setMinValue(int)@@VERSION		 // FUNC
ZNumModule::setValue(int)@@VERSION		 // FUNC
ZNumModule::ZNumModule(int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID)@@VERSION		 // FUNC
ZNumModule::ZNumModule(int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID)@@VERSION		 // FUNC
*/

struct ZNumModuleData;
class ZLabel;

class ZNumModule : public ZWidget
{
	uint fix[5];
//Q_OBJECT

public:
       enum RelativeAlignment
       {
           LEFT,
           RIGHT
        };

	ZNumModule( 
		int nMaxLen,
		QWidget *parent = 0, 
		const char *name = 0,  
		WFlags f = 0 ,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNumModule);

	~ZNumModule() {};

	void setLabel(ZLabel *pLabel,RelativeAlignment alignment);

	int getValue();

	void setMaxValue( int nValue );

	void setMinValue( int nValue );

	void setValue( int nValue );

	//void setLineStep( int nStep);
    void setPageStep( int nStep);
    int lineStep();
    int pageStep();
    void setWrapping(bool bOn);
    bool wrapping();

	int maxValue();

	int minValue();

    ZNumPicker *getPicker();

    //QSize sizeHint() const;

	//void updateSkin(bool redraw);

    //virtual void setPalette(const QPalette &palette);

    //virtual void setOmegaInput(bool arg);

public:
	//QSize minimumSizeHint() const;
    bool autoResize() const;
    void setAutoResize( bool enable );

public slots:
    void valueChange(int value);
    void resizeAll();

signals:
    void valueChanged(int value);
    void numModuleSizeChange();

protected:
	//void resizeEvent(QResizeEvent * e);
    //void paintEvent(QPaintEvent * e);
    void  focusInEvent( QFocusEvent * e);

private:
	void init();
    void  setSpacingH1( short nSpacing );
    short getSpacingH1() const;

private:
    ZNumModuleData * d;
};

#endif  

