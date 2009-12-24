//Writed by Ant-ON, 2009

#ifndef ZFREQMODULE
#define ZFREQMODULE

#include <ZWidget.h>
#include <ZLabel.h>

enum RelativeAlignment
{
}

class QPalette;

class ZFreqModule: public ZWidget
{
public:
	ZFreqModule(QWidget* parent, char const* name, unsigned int, ZSkinService::WidgetClsID);
	ZFreqModule(unsigned int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	ZFreqModule(unsigned int, unsigned int, unsigned int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	~ZFreqModule();	
	
	bool autoResize() const;
	void focusInEvent(QFocusEvent*);
	void getFreq();
	void getPicker();
	short getSpacingH1() const;
	bool hasFocus() const;
	void hourLineStep();
	void init();
	QSize minimumSizeHint() const;
	void minuteLineStep();
	void paintEvent(QPaintEvent*);
	void resizeAll();
	void resizeEvent(QResizeEvent*);
	void setAutoResize(bool);
	void setEndFreq(unsigned int);
	void setFreqValue(unsigned int);
	void setHourLineStep(int);
	void setLabel(ZLabel*, 	RelativeAlignment);
	void setMinuteLineStep(int);
	void setPalette(QPalette const&);
	void setSeparatorString(QString&);
	void setSpacingH1(short);
	void setStartFreq(unsigned int);
	void setWrapping(bool);
	QSize sizeHint() const;
	
protected:
	void updateSkin(bool redraw);
	
signals:
	void FreqModuleSizeChange();
};

#endif //ZFREQMODULE
