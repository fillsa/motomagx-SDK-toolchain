#ifndef __ZKBMAINWIDGET_H_
#define __ZKBMAINWIDGET_H_

#include <ZMainWidget.h>
#include <ZHeader.h>

class ZAppInfoArea;
class ZSoftKey;

/* Size: 348=87*4 */

class ZKbMainWidget : public ZMainWidget
{
	Q_OBJECT
	unsigned int data[87 - sizeof(ZMainWidget)/4];

public:
	//ZKbMainWidget(QString const&, QWidget*, char const* name, unsigned int f = 0);
	ZKbMainWidget( const QString &mwTitle, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
	ZKbMainWidget( QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
	ZKbMainWidget( ZHeader::HEADER_TYPE headerType, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );
	//ZKbMainWidget(QWidget* parent, char const* name, unsigned int f = 0);
	//ZKbMainWidget(ZHeader::HEADER_TYPE, QWidget*, char const*, unsigned int);
	virtual ~ZKbMainWidget();

	void clearKeyClicked();
	bool event(QEvent*);
	bool eventFilter(QObject*, QEvent*);
	ZAppInfoArea * getAppInfoArea();
	QString getAppTitle();
	int  getLRSBaseIndex();
	QString getMainWidgetTitle();
	void getMainWidgetTitleIcon();
	ZSoftKey * getSoftKey(bool createZSoftKey = TRUE);
	QSize headerSize();
	void init(ZHeader::HEADER_TYPE);
	void isTitleTruncEnable();
	void keyPressEvent(QKeyEvent*);
	void setAppInfoArea(ZAppInfoArea*);
	static bool setAppTitle(QString const& appTitle);
	void setHeaderType(ZHeader::HEADER_TYPE);
	void setMainWidgetTitle(QString const&);
	void setMainWidgetTitleIcon(QPixmap const&);
	bool setSoftKey(ZSoftKey*);
	void setTitleTruncEnable(bool);
	void updateHeader();

public slots:
	void slotAppMessage(QCString const&, QArray<char> const&);
	void slotFullScreenModeChanged(bool);
	void slotKbStateChanged(int, bool);
};

#endif
