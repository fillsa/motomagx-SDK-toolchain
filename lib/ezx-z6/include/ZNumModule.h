#ifndef ZNUMMODULE_H
#define ZNUMMODULE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZSkinBase.h"
#include "ZLabel.h"

class ZNumPicker;

struct ZNumModuleData;
class ZLabel;

class ZNumModule : public ZWidget
{
Q_OBJECT

public:
   enum RelativeAlignment{
	   LEFT,
	   RIGHT
	};
	ZNumModule( 
		int nMaxLen,
		QWidget *parent = 0, 
		const char *name = 0,  
		WFlags f = 0 ,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNumModule);   
	~ZNumModule();
	void setLabel(ZLabel *pLabel,RelativeAlignment alignment);
	int getValue();
	void setMaxValue( int nValue );
	void setMinValue( int nValue );
	void setValue( int nValue );
    void setLineStep( int nStep);
    void setWrapping(bool bOn);
	int maxValue();
    int minValue();
	bool wrapping();
    int lineStep();
    ZNumPicker *getPicker();
	QSize sizeHint() const;
	QSize minimumSizeHint() const;
	bool autoResize() const;
	void setAutoResize( bool enable );

public slots:
   void valueChange(int);
   void resizeAll();

signals:
   void valueChanged(int);
   void numModuleSizeChange();
private:
	ZNumModuleData * d;
	void init();
	void  setSpacingH1( short nSpacing );
	short getSpacingH1() const;

protected:
	void resizeEvent(QResizeEvent *);
	void paintEvent(QPaintEvent *);
	void updateSkin(bool redraw);
	virtual void setPalette(const QPalette &palette);
	void  focusInEvent( QFocusEvent * e);
};

#endif 

