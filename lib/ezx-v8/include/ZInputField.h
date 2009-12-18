#ifndef Z_INPUT_FIELD_H
#define Z_INPUT_FIELD_H

//#include "ZKbGlobal.h"
#include "ZKbInputField.h"
#include <qobject.h>

class ZInputField;
class QWidget; 

class ZPoint;
class ZString;
class ZRect;
class ZEvent;

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
    virtual bool eventFilter(ZInputField* field, ZEvent * e)=0; 	
    virtual bool registerField(ZInputField* field)=0;
    virtual bool unregisterField(ZInputField* field)=0;

}; 

class InputField 
{
public:

    InputField(){};
    virtual ~InputField(){};


    virtual int getFieldType()=0;


    virtual void setDisplayAttr(ZPoint& pos, int length,int attr)=0;

    virtual bool isCompletionEnable()=0;

    virtual bool isUADEnable()=0;


    virtual ZString getSymbolList(bool bLongList)=0;

    virtual void  getEmoticonList(QStringList& r_iconsList)=0;

    virtual void getDelimiter(ZString&)=0;

    virtual int  getCapsState()=0;

    virtual void getChunkDelimiter(ZString&)=0;

    virtual void  filterStringList(QStringList&)=0;

    virtual int maxLength()=0;

public:

    virtual ZString getText(ZPoint pos , bool forward)=0;

    virtual void setText(ZString text)=0;

    virtual ZPoint getCursorPos()=0;

    virtual ZPoint setCursorPos(ZPoint start_pos, int offset, bool update = true)=0;


    virtual void setCursorType(int type)=0;

    virtual void setCursorFlag(int flag)=0;

    virtual void setCursorDirection(int direction)=0;

    virtual void setReverse(ZPoint pos, int len, bool update=true)=0;

    virtual void clearReverse(bool update=true)=0;


    virtual void setUnderline(ZPoint pos, int len, bool alternateAvailable, bool update=true)=0;


    virtual void clearUnderline(bool update=true)=0;

    virtual void deleteString(ZPoint start_pos, int len,  bool autoUpdate=true )=0;

    virtual void insertString(ZPoint start_pos, ZString text, bool update=true)=0;


    virtual void insertString(ZPoint start_pos , ZString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos )=0;

    virtual void insertImage(ZPoint start_pos, ZString icon)=0;

    virtual ZString format(ZString text)=0;

    virtual ZRect getFieldBounds()=0;

    virtual ZRect getCharBounds(ZPoint pos)=0;

    virtual ZRect getUnderlineBounds(ZPoint pos)=0;

    virtual bool  hasValidator(void) = 0;

    virtual bool  canInsertString(const ZString& string) = 0;

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
    // construction/destruction 
// default construction 
    ZInputField(QWidget * editWidget); 
    

    virtual ~ZInputField(); 

  public: 
    virtual void setDisplayAttr(ZPoint& pos, int length,int attr);

    virtual bool isCompletionEnable();
    virtual bool isUADEnable();
    virtual ZString getSymbolList(bool bLongList );
    virtual void getEmoticonList(QStringList& r_iconsList) ;
    virtual void getDelimiter(ZString&);
    virtual int  getCapsState();
    virtual void getChunkDelimiter(ZString&);
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
    
 
    virtual ZString getText(ZPoint pos , bool forward);
   
 
    virtual ZPoint getCursorPos(); 

    virtual void setText(ZString text);
  
    virtual ZPoint setCursorPos(ZPoint start_pos, int offset, bool update = true);

    virtual void setCursorType(int type);

    virtual void setCursorFlag(int flag);
    
    virtual void setCursorDirection(int direction);

    virtual void setReverse(ZPoint pos, int len, bool update=true);

    virtual void clearReverse(bool update=true);
   

    virtual void setUnderline(ZPoint pos, int len, bool alternateAvailable, bool update=true);


    virtual void clearUnderline(bool update=true);


    virtual void deleteString(ZPoint start_pos, int len,  bool autoUpdate=true );
    

    virtual void insertString(ZPoint start_pos, ZString text, bool update=true);

    virtual void insertString(ZPoint start_pos , ZString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos);

    virtual void insertImage(ZPoint start_pos, ZString icon);

    virtual ZString format(ZString text);

    virtual ZRect getFieldBounds();

    virtual ZRect getCharBounds(ZPoint pos);

    virtual ZRect getUnderlineBounds(ZPoint pos);

    virtual int maxLength(); 

    bool isReFocused();

    void setRefocusdFlag(bool flag);

    virtual bool  hasValidator(void);

    virtual bool  canInsertString(const QString& string);

    virtual void sendConfirmMessage(int charCode);
  
    virtual void forceKeyRelease(int keyCode);

    int getCursorDirection();

#ifdef FEAT_TOUCHSCREEN_SUPPORT 

    void autoSetType();
#endif

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
