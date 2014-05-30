#ifndef __ZSPINBOX_H_
#define __ZSPINBOX_H_

#include <qobject.h>
#include <qrangecontrol.h>

class QValidator;

/* Size 156=39*4 */

class ZSpinBox : public QObject, QRangeControl
{
    Q_OBJECT
    unsigned int data[39 - sizeof(QObject)/4 - sizeof(QRangeControl)/4];

public:
	virtual void setWrapping(bool);
	virtual void setSpecialValueText(QString const&);
	virtual void setSpecialValueTextMax(QString const&);
	virtual void setValue(int);
	virtual void stepUp(bool);
	virtual void stepDown(bool);
	virtual void setValidator(QValidator const*);
	virtual void mapValueToText(int);
	virtual void mapTextToValue(bool*);
	virtual void updateDisplay();
	virtual void interpretText();
	virtual void valueChange();
	virtual void rangeChange();

	ZSpinBox(QPixmap const&, QPixmap const&, QWidget*, char const*);
	~ZSpinBox();

	void updateText();
	bool eventFilter(QObject*, QEvent*);
	void getTabIndex();
	void setLineStep(int);
	void setMaxValue(int);
	void setMinValue(int);
	void setTabIndex(int);
	void slotTimeOut();
	void textChanged();
	void setSpacingV1(short);
	void setTWSmall10(int);
	void valueChanged(QString const&);
	void valueChanged(int);
	void destroySpinBox();
	void setEditorValue(int);
	void destroyLineEdit();
	void keyEventProcess(QEvent*, int);
	void currentValueText();
	void checkPatternMatch(int);
	void setEditorPreferredWidth(int);
	void init();
	void move(int, int);
	void paint(QPainter&, int, int, QPixmap const&, QPixmap const&);
	void getSpacingV1() const;
	void specialValueText() const;
	void specialValueTextMax() const;
	void text() const;
	void value() const;
	void width() const;
	void editor() const;
	void height() const;
	void lineStep() const;
	void maxValue() const;
	void minValue() const;
	void wrapping() const;
	void validator() const;
};

#endif
