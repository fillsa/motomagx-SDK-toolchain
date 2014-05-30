#ifndef _ZFMWITEM_H
#define _ZFMWITEM_H

/* Size: UNKNOWN */

class QFontMetrics;
class QPixmap;
class QString;

class ZFmwItem
{
    unsigned int data[0];

public:
	enum Type {TEXT, ICON, WIDGET};

	ZFmwItem(Type, QString const&, int);
	ZFmwItem(Type, int);

	int  getAlignment();
	void setAlignment(int);
	void growToNoTrunc(QFontMetrics*);
	void getSteadyWidth();
	void setSteadyWidth(int);
	void getKey();
	void getIcon();
	QString getText();
	Type getType();
	void setIcon(QPixmap const&);
	void setIcon(QString const&);
	void setText(QString const&);
	void getWidth();
	void setWidth(int);
	QWidget * getWidget();
	void setWidget(QWidget*);
};

#endif
