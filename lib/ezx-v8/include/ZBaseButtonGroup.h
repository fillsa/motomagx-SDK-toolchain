#ifndef _ZBASEBUTTONGROUP_H_
#define _ZBASEBUTTONGROUP_H_ 1

#include <qgroupbox.h>

class ZBaseButton;

/* Size <= 284=71*4 */

class ZBaseButtonGroup : public QGroupBox
{
    Q_OBJECT
    unsigned int data[72 - sizeof(QGroupBox)/4];

public:
    virtual void setExclusive(bool);
    virtual void setRadioButtonExclusive(bool);
    virtual void setButton(int);
    virtual void moveFocus(int);

	ZBaseButtonGroup(QWidget*, char const*);
	ZBaseButtonGroup(QString const&, QWidget*, char const*);
	ZBaseButtonGroup(int, Qt::Orientation, QWidget*, char const*);
	ZBaseButtonGroup(int, Qt::Orientation, QString const&, QWidget*, char const*);
	~ZBaseButtonGroup();

	int buttonClicked();
	int buttonPressed();
	int buttonToggled(bool);
	int buttonReleased();
	void init();
	void insert(ZBaseButton*, int);
	void remove(ZBaseButton*);
	void clicked(int);
	void pressed(int);
	void released(int);
	int selected();
	int isExclusive() const;
	void id(ZBaseButton*) const;
	ZBaseButton* find(int) const;
	void count() const;
};

#endif
