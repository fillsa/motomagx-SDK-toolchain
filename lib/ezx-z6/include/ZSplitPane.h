#ifndef _ZSPLITPANE_H_
#define _ZSPLITPANE_H_ 1

#include <ZWidget.h>

/* Size 264=66*4 */

class ZSplitPane : public ZWidget
{
    Q_OBJECT
    unsigned int data[66 - sizeof(ZWidget)/4];

public:
    enum Type {
    };

    ZSplitPane(QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZSplitPane);
	~ZSplitPane();

	void paintEvent(QPaintEvent*);
	void setPalette(QPalette const&);
	void updateSkin(bool);
	void resizeEvent(QResizeEvent*);
	void resizeByPixel();
	void setPaneHeightPixel(int, Type);
	void getPane(int);
	void setPane(QWidget*, QWidget*);
	void setHeight(int);
	void setPixmap(QPixmap const&);
	void minimumSizeHint() const;
	void hasFocus() const;
	void sizeHint() const;
};

#endif
