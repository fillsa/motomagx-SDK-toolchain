#ifndef __ZMAINWIDGET_H_
#define __ZMAINWIDGET_H_

#include <ZWidget.h>
#include <qlayout.h>
#include <ZIMethod.h>

class QUuid;

/* Size: UNKNOWN, < 348=87*4 */

class ZMainWidget : public ZWidget
{
	Q_OBJECT
	unsigned int data[87 - sizeof(ZWidget)/4];

public:

     ZMainWidget( bool editorMode, QWidget* parent, const char* name = 0, WFlags f = 0);
     ZMainWidget(bool kbMainWidget,bool editorMode,
                 QWidget* parent,
                 const char* name = 0,
                 WFlags f = 0);
    //ZMainWidget(bool, QWidget*, char const*, unsigned int);             
                 
     ZMainWidget( QWidget* parent, const char* name = 0, WFlags f = 0);
     //ZMainWidget(QWidget*, char const*, unsigned int);
     
     ZMainWidget( const QString& titleText, bool editorMode, QWidget* parent,
                  const char* name = 0, WFlags f = 0);
    //ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned int);
	
	~ZMainWidget();

        virtual bool setContentWidget(QWidget*);
        virtual QWidget* getCSTWidget(bool);
        virtual int setCSTWidget(QWidget*);
        virtual int setTitleBarWidget(QWidget*);
        virtual int setFullScreenMode(bool fullScreen, bool reserved = FALSE);
        virtual int hideInputWidget();
        virtual int slotPopupMenu(int);
        virtual int invokeInputWidget();
        virtual int showToolBar();
        virtual int setToolBar(QUuid const&);
        virtual int hideToolBar();
        virtual int setupInputMethodsPopupMenu();
        virtual int getLRSBaseIndex();

	bool eventFilter(QObject*, QEvent*);
	void fullScreenModeChanged(bool);
	QWidget * getContentWidget(bool createZScrollView = true);
	bool getEditMode();
	void getFavoriteInputMethods() const;
	bool getFullScreenMode();
	void getKbState();
	QWidget * getTitleBarWidget();
	QVBoxLayout * getVBoxLayout();
	void hide();
	void init(bool, QString const&);
	void kbStateChanged(bool);
	void kbStateChanged(bool, QUuid const&, int);
	void mainWidgetSizeChanged(int, QRect const&);
	void objectDestroyed();
	void paletteChange(QPalette const&);
	void popupKBMenu();
	void setFavoriteInputMethods(QValueList<QUuid> const&);
	void setFavoriteInputMethods(QWidget*, QValueList<QUuid> const&);
	void setInputMethod(QUuid const&, int);
	void setInputMethod(QWidget*, const QUuid& method = IMID_UNDEFINED, int fieldType=0, QString fieldName=QString());
    	void setInputMethods( QWidget* widget, const QUuid& defaultIM,                          const QValueList<QUuid> & favourIMList,int fieldType =ZKbInputField::FIELD_TYPE_REGULAR , QString fieldName=QString());
	void setInputMethods(QWidget*, QUuid const&, int, QString);
	void show();
	void showWithInputMethod(QUuid const&, int);

public slots:
	void slotKbStateChanged(bool, QUuid const&, int);
	void slotKbWidgetSizeChanged(QRect const&, int, bool, bool);
};
#endif
