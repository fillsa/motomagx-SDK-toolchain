#ifndef _ZScrollView_H
#define _ZScrollView_H

#include <qscrollview.h>

/* Size: 240=60*4, size of QScrollView 58*4 is not confirmed. */

class ZScrollView : public QScrollView
{
	Q_OBJECT
	unsigned int data[60-sizeof(QScrollView)/4];

public:
  ZScrollView(QWidget* parent = 0, const char* name = 0, WFlags f = 0);
	~ZScrollView();

	virtual void addChild(QWidget*, int x, int y, bool);
	virtual void moveChild(QWidget*, int x, int y, bool);
	virtual void doLayout(QWidget*, QSize, QPoint, int);

	void addChild(QWidget*, int x, int y);
	void drawContents(QPainter*, int, int, int, int);
	void enableClipper(bool);
	bool event(QEvent*);
	bool eventFilter(QObject*, QEvent*);
	bool focusNextPrevChild(bool);
	void getAutoLayout() const;
	void getFlushEvents() const;
	void hide();
	void keyPressEvent(QKeyEvent*);
	void makeFocusWidgetVisible(bool);
	void nextFocusWidget(bool);
	void nextFocusWidgetVisible(bool);
	void removeSVChild(QWidget*);
	void resizeContents(int, int);
	void resizeEvent(QResizeEvent*);
	void setAutoLayout(bool);
	void setAutoScroll(bool);
	void setBackGroundPixmap(QPixmap const&);
	void setFlushEvents(bool);
	void setMargins(int, int, int, int);
	void setNoFocusChange(bool);
	void show();
	void updateContentSize();
	void updateFieldsWidth(int);
	void vScrollBarStateChanged(int);

};
#endif
