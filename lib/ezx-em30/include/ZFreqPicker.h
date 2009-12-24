//Writed by Ant-ON, 2009

#ifndef ZFREQPICKER
#define ZFREQPICKER

#include <ZSkinBase.h>
#include <ZWidget.h>

class ZFreqPicker: public ZWidget
{
	
public:
	ZFreqPicker(QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	ZFreqPicker(unsigned int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	ZFreqPicker(unsigned int, unsigned int, unsigned int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	~ZFreqPicker();	
	
	void init(unsigned int, unsigned int, unsigned int);
	
	bool autoResize() const;
	void checkValid();
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void getDownHighSelectedPixmap();
	void getFreq();
	void getHighSelectedPixmap();
	void getSelectedPixmap();
	short getSpacingH1() const;
	short getSpacingH2() const;
	short getSpacingV1() const;
	void getStandardPixmap();
	void getUpHighSelectedPixmap();
	bool hasFocus() const;
	void hourLineStep();
	void initFreqFormat();
	void initHour();
	void initMinutes();
	bool isMaxOrMin(int, bool);
	bool isZDisabled();
	bool isZEnabled();
	void keyEventProcess(QEvent*, int);
	void keyPressEvent(QKeyEvent*);
	QSize minimumSizeHint() const;
	void minuteLineStep();
	void moveDown(int, bool);
	void moveLeft(int, bool);
	void moveRight(int, bool);
	void moveUp(int, bool);
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent*);
	void setAutoResize(bool);
	void setEnabled(bool);
	void setEndFreq(unsigned int);
	void setFreqValue(unsigned int);
	void setHourLineStep(int);
	void setMinuteLineStep(int);
	void setPalette(QPalette const&);
	void setSelectionState(ZSkinBase::SelectionState);
	void setSeparatorString(QString&);
	void setSpacingH1(short);
	void setSpacingH2(short);
	void setSpacingV1(short);
	void setStartFreq(unsigned int);
	void setWrapping(bool);
	QSize sizeHint() const;
	void updateSpinBoxState();

protected:
	void updateSkin(bool redraw);

signals:
	void signalSelect();
	void valueChanged();	
	void FreqPickerSizeChange();
};

#endif //ZFREQPICKER
