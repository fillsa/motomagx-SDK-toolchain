#ifndef _ZGROUPBOX_H
#define _ZGROUPBOX_H

#include <ZWidget.h>

/* Size: 264=66*4 */

class ZGroupBox : public ZWidget
{
	Q_OBJECT

        unsigned int data[66 - sizeof(ZWidget)/4];

public:
  ZGroupBox(QString const&, QWidget *parent = 0, char const* name = 0, ZSkinService::WidgetClsID =  ZSkinService::clsZGroupBox);
  ZGroupBox(QWidget *parent = 0, bool noStyle = false, char const* name = 0, ZSkinService::WidgetClsID =  ZSkinService::clsZGroupBox);
	~ZGroupBox();

	void checkedList() const;
	void childEvent(QChildEvent*);
	void clear();
	void contentsResizing(ZGroupBox*, int, int);
	void count() const;
	void doLayout();
//	void eventFilter(QObject*, QEvent*);
	void eventFilter(QEvent*);
//	void getBgImageForTransparent(bool&);
	void getBgImageForTransparent();
	void getButton(int) const;
	void getId(ZWidget*) const;
	void insert(ZWidget *w,int id = -1);
	bool isZEnabled() const;
	void keyPressEvent(QKeyEvent*);
	void paintEvent(QPaintEvent*);
	void remove(ZWidget*);
	void remove(int);
	void resize(int, int);
	void resizeEvent(QResizeEvent*);
	void selected() const;
	void setEnabled(bool);
	void setNoStyle(bool);
	void setPalette(QPalette const&);
	void setSpacing(int, int);
	void setTitle(QString const&);
	void showEvent(QShowEvent*);
	//void sizeHint() const;
  void sizeHint();
	void slotLayoutTimer();
	void takeItem(ZWidget*);
	void takeItem(int);
	void title() const;
	void triggerUpdate(bool);

};


#endif

