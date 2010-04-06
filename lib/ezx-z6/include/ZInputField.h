#ifndef Z_INPUT_FIELD_H
#define Z_INPUT_FIELD_H

#include "ZKbInputField.h"
#include <qobject.h>

class ZInputField;
class QWidget; 

#define INPUT_FIELD_DEFAULT_LEN 50 
#define INPUT_FIELD_GAP_BETWEEN_CHAR_AND_UNDERLINE 1 

typedef ZInputField ZKbCommonInputField;

struct ZInputFieldEventFilter
: public QObject
{
    
    ZInputFieldEventFilter(QObject * parent=NULL): QObject(parent)
    {
    }
    
    virtual ~ZInputFieldEventFilter() {}
    virtual bool eventFilter(ZInputField* field, QEvent * e)=0; 	
    virtual bool registerField(ZInputField* field)=0;
    virtual bool unregisterField(ZInputField* field)=0;

}; 

class InputField 
{
public:

    InputField(){};
    virtual ~InputField(){};
    virtual int getFieldType()=0;
    virtual void setDisplayAttr(QPoint& pos, int length,int attr)=0;
    virtual bool isCompletionEnable()=0;
    virtual bool isUADEnable()=0;
    virtual QString getSymbolList(bool bLongList)=0;
    virtual void  getEmoticonList(QStringList& r_iconsList)=0;
    virtual void getDelimiter(QString&)=0;
    virtual int  getCapsState()=0;
    virtual void getChunkDelimiter(QString&)=0;
    virtual void  filterStringList(QStringList&)=0;
    virtual int maxLength()=0;

public:
    virtual QString getText(QPoint pos , bool forward)=0;
    virtual void setText(QString text)=0;
    virtual QPoint getCursorPos()=0;
    virtual QPoint setCursorPos(QPoint start_pos, int offset, bool update = true)=0;
    virtual void setCursorType(int type)=0;
    virtual void setCursorFlag(int flag)=0;
    virtual void setCursorDirection(int direction)=0;
    virtual void setReverse(QPoint pos, int len, bool update=true)=0;
    virtual void clearReverse(bool update=true)=0;
    virtual void setUnderline(QPoint pos, int len, bool alternateAvailable, bool update=true)=0;
    virtual void clearUnderline(bool update=true)=0;
    virtual void deleteString(QPoint start_pos, int len,  bool autoUpdate=true )=0;
    virtual void insertString(QPoint start_pos, QString text, bool update=true)=0;
    virtual void insertString(QPoint start_pos , QString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos )=0;
    virtual void insertImage(QPoint start_pos, QString icon)=0;
    virtual QString format(QString text)=0;
    virtual QRect getFieldBounds()=0;
    virtual QRect getCharBounds(QPoint pos)=0;
    virtual QRect getUnderlineBounds(QPoint pos)=0;
    virtual bool  hasValidator(void) = 0;
    virtual bool  canInsertString(const QString& string) = 0;
    virtual void sendConfirmMessage(int charCode) = 0;
    virtual const char* getFieldName() = 0;
    virtual void forceKeyRelease(int keyCode) = 0;
};

class ZInlineEditInfo
{ 
public:
    ZInlineEditInfo(){};
    virtual ~ZInlineEditInfo(){};
    virtual QWidget * getEditorWidget()=0;
    virtual int getWinId()=0;
    virtual int getTopWidgetWinId()=0; 
    virtual void  enableFilter(bool enable)=0; 
}; 


struct ZInputFieldData;
typedef InputField ZInlineEditing;

class ZInputField:
    public QObject, 
    public ZKbInputField,
    public ZInlineEditing,
    public ZInlineEditInfo
{
    
  public:
    ZInputField(QWidget * editWidget); 
    virtual ~ZInputField(); 

  public: 
    virtual void setDisplayAttr(QPoint& pos, int length,int attr);
    virtual bool isCompletionEnable();
    virtual bool isUADEnable();
    virtual QString getSymbolList(bool bLongList );
    virtual void getEmoticonList(QStringList& r_iconsList) ;
    virtual void getDelimiter(QString&);
    virtual int  getCapsState();
    virtual void getChunkDelimiter(QString&);
    virtual void  filterStringList(QStringList&);

  public: 
    virtual void setFieldName(const char* fieldName);
    virtual const char* getFieldName();
    virtual int getType() const;
    virtual int getFieldType() ;
    virtual void setType(int fieldType);
    virtual void setOptions(int fieldOptions, long optionData = 0);
    virtual long getOptions(int optionType = FIELD_OPTION_COMPOSITE_OPTIONS) const;
    virtual void setPreferredInputModes(const QValueList<QUuid> & preferredKbList, const QUuid & defaultKb); 
    virtual bool getPreferredInputModes( QValueList<QUuid> & preferredKbList, QUuid & defaultKb) const; 
    virtual int editType() const;  
    virtual int getWinId();
    virtual int getTopWidgetWinId(); 
    virtual void  enableFilter(bool enable); 
    virtual QWidget * getEditorWidget();
    virtual QString getText(QPoint pos , bool forward);
    virtual QPoint getCursorPos(); 
    virtual void setText(QString text);
    virtual QPoint setCursorPos(QPoint start_pos, int offset, bool update = true);
    virtual void setCursorType(int type);
    virtual void setCursorFlag(int flag);
    virtual void setCursorDirection(int direction);
    virtual void setReverse(QPoint pos, int len, bool update=true);
    virtual void clearReverse(bool update=true);
    virtual void setUnderline(QPoint pos, int len, bool alternateAvailable, bool update=true);
    virtual void clearUnderline(bool update=true);
    virtual void deleteString(QPoint start_pos, int len,  bool autoUpdate=true );
    virtual void insertString(QPoint start_pos, QString text, bool update=true);
    virtual void insertString(QPoint start_pos , QString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos);
    virtual void insertImage(QPoint start_pos, QString icon);
    virtual QString format(QString text);
    virtual QRect getFieldBounds();
    virtual QRect getCharBounds(QPoint pos);
    virtual QRect getUnderlineBounds(QPoint pos);
    virtual int maxLength(); 
    bool isReFocused();
    void setRefocusdFlag(bool flag);
    virtual bool  hasValidator(void);
    virtual bool  canInsertString(const QString& string);
    virtual void sendConfirmMessage(int charCode);
    virtual void forceKeyRelease(int keyCode);
    int getCursorDirection();

protected:

    virtual bool eventFilter ( QObject * o, QEvent * e);

protected: 

    ZInputFieldData * d; 
};

class KbNullInputField : public ZInputField
{
public:
    static KbNullInputField *instance();
    virtual ~KbNullInputField();

protected:
    KbNullInputField();

private:
    static KbNullInputField *asp_nullField;
};

#endif
