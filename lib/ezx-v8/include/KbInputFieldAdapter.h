#ifndef Z_INPUT_FIELD_ADAPTAR_H
#define Z_INPUT_FIELD_ADAPTAR_H

//#include "ZKbGlobal.h"
#include "ZInputField.h"
#include <qobject.h>


class ZInputEngine; 
class ZInputFieldAdapterData;
class KbEditContext; 
class QWidget;

class ZInputFieldEventFilter;

#ifdef FEAT_KEYPAD_SUPPORT
class KbUIControlInterface;
#endif

class ZInputFieldAdapter
  :public ZInputFieldEventFilter
{
    
Q_OBJECT
    
    public:
     ZInputFieldAdapter(QObject * parent = NULL);
     virtual ~ZInputFieldAdapter();
    

  public:
     ZInputField * currentField() ;

     ZInputEngine*         getProperInputEngine() ;

     KbEditContext  *      getEditContext();

     
     ZInputField *       getKbInputField(QWidget * edit);

#ifdef FEAT_TOUCHSCREEN_SUPPORT
     bool checkAppEvent(QObject *o, QEvent *e); 

     bool kbAutoInvoke();

     void setKbAutoInvoke(bool isAuto=TRUE);

     void setFavoriteInputMethods(const QValueList<QUuid> & kbList);

     QValueList<QUuid>& getFavoriteInputMethods();

     void registerEditableWidget(const char* className);
     
     void removeEditableWidget(const char* className);

     bool& autoFirstShow ();
     int & autoFirstShowMwId();
     void setAutoHideKb( bool hide = TRUE );
     bool getAutoHideKb();
    void setAutoInvokeKb( QWidget* editableWidget, bool invoke = true );
    void directHideInputWidget();


    bool& clientKbActived(); 

    void setDefaultKbMethod( const QUuid& method ); 
    const QUuid & getDefaultKbMethod( bool readConfig = false ); 
#endif
    void setInputMethods( QWidget* widget, const QUuid& defaultIM, 
                          const QValueList<QUuid> & favourIMList,
                          int fieldType,const QString & fieldName );
    void directShowInputWidget(QWidget* editor, const QUuid & kbId, int fieldType);


    
    
  public:
     virtual bool eventFilter(ZInputField* field, ZEvent * e);
     virtual bool registerField(ZInputField* field);
     virtual bool unregisterField(ZInputField* field); 

#ifdef FEAT_KEYPAD_SUPPORT
  public:
     void emitSignalKbStateChanged(int topLevelWinId, bool activated);
     KbUIControlInterface* getUIController() const;
     void setUIController(KbUIControlInterface* ccif);
#endif

     
  signals:
    void signalKbStateChanged(int topLevelWinId, bool activated);

  protected:
#ifdef FEAT_TOUCHSCREEN_SUPPORT
     bool checkWidgetEditable(QWidget * widget);
     void checkAutoHiding(QWidget * widget );
#endif
  protected:
      ZInputFieldAdapterData * d;

}; 
#endif
