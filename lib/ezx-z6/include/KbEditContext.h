

#ifndef KB_EDITCONTEXT_H
#define KB_EDITCONTEXT_H

#include <qstring.h>
//#include "ZKbTypes.h"

class KbEditContextData; 

typedef QUuid KbInputModeId;

class KbEditContext
{
public:
    KbEditContext();
    ~KbEditContext(); 

public: 
    void connectKbServer();
    bool isUADEnabled()const;
    void setUADEnabled(bool enable);
 
    bool isCompletionEnabled()const;
    void setCompletionEnabled(bool enable);

    //KbInputMethodList getDefaultModeCycle();
 
    //KbInputMethod getFieldLastIm(int fieldType);
    //void setFieldLastIm(int fieldType, const KbInputMethod& im);

    QString getDefaultInputLang();
    void setDefaultInputLang(const QString& langCode);

    QString getFieldInputLang(int fieldType);
    void setFieldInputLang(int fieldType, const QString& langCode);

    KbInputModeId getFieldInputMode(int fieldType);
    void setFieldInputMode(int fieldType, const KbInputModeId& mode);
 
    static void appExit(void);
    void saveFieldInputMode();

public:
    void loadCompletionSetting();
    void loadModeCycle();

private:
    KbEditContextData *d; 
}; 

#endif //ZKB_CONTEXT_H
