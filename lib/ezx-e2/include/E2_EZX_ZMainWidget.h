//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZWIDGET ���淲���ԣ���ͷ��ע�Ͷ��ǲ²����;��û�о�������
// ��ȫ����ӵ��࣬
// _ZN11ZMainWidgetC4EbP7QWidgetPKcj
// _ZN11ZMainWidgetC4EP7QWidgetPKcj
// _ZN11ZMainWidgetC4ERK7QStringbP7QWidgetPKcj
// _ZN11ZMainWidgetD4Ev


#ifndef _E2_EZX_ZMAINWIDGET_H
#define _E2_EZX_ZMAINWIDGET_H

#include <qrect.h>
#include <qwidget.h>
#include <quuid.h>
#include <qvaluelist.h>
#include <qstring.h>
#include <qobject.h>
#include <qevent.h>
#include <qlabel.h>
#include <qpalette.h>
#include <qlayout.h>



class ZMainWidget : public QWidget
{
	Q_OBJECT
	char tmp[4096];
public:
	ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned);
	ZMainWidget(QWidget*, char const*, unsigned);
	ZMainWidget(bool, QWidget*, char const*, unsigned);
	QWidget* getContentWidget(bool);		// �������� ����������ĵĿؼ���
	void setInputMethod(QUuid const&, int); // ע��ڶ����������ܺ�ZGlobal::KbFlags�й�
	void setInputMethod(QWidget*, QUuid const&, int, QString);// ע��������������ܺ�ZGlobal::KbFlags�й�
	void setInputMethods(QWidget*, QUuid const&, int, QString);//��������  ע��������������ܺ�ZGlobal::KbFlags�й�
	void setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString); // ��������  ע����ĸ��������ܺ�ZGlobal::KbFlags�й�
	void objectDestroyed();
	void kbStateChanged(bool);
	virtual void show();
	void setFullScreenMode(bool, bool);		// ����������������ȫ��ģʽ������Ϊ��Javaר�ſ���
	void setFavoriteInputMethods(QValueList<QUuid> const&);
	void setFavoriteInputMethods(QWidget*, QValueList<QUuid> const&);// ��������
	bool getEditMode();
	const QValueList<QUuid> getFavoriteInputMethods(); // ��������
	
	void showWithInputMethod(QUuid const&, int); // ע��ڶ����������ܺ�ZGlobal::KbFlags�й�
	virtual void fullScreenModeChanged(bool); // �������� ����Ϊȫ����Ӧ����
	void setTitleBarWidget(QWidget*); // ��������
	virtual void invokeInputWidget();
	QVBoxLayout* getVBoxLayout();			// ��������  ����ò��ַ�ʽ
	virtual void slotKbStateChanged(bool, QUuid const&, int); // ��������
//	const QCString className(); // ��������
	int getLRSBaseIndex(); // ��������
	void popupKBMenu();
	void kbStateChanged(bool, QUuid const&, int);
	
	virtual void slotPopupMenu(int);
	virtual bool eventFilter(QObject*, QEvent*); // ��������
	bool getKbState();
	virtual void slotKbWidgetSizeChanged(QRect const&, int, bool, bool); // ��������
	bool getFullScreenMode();	// ��������
	virtual void setupInputMethodsPopupMenu();
	virtual bool setCSTWidget(QWidget*);
	QWidget* getCSTWidget(bool);
	virtual void paletteChange(QPalette const&);
	QLabel* getTitleBarWidget();
	virtual bool setContentWidget(QWidget*);
	virtual bool mainWidgetSizeChanged(int, QRect const&);	// ��������
	virtual void hide();
	virtual void hideInputWidget();
	void init(bool, QString const&);
};
#endif
