#ifndef KB_EDITCONTEXT_H
#define KB_EDITCONTEXT_H

#include <qstring.h>
class KbEditContextData; 

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

    QUuid getFieldInputMode(int fieldType);
    void setFieldInputMode(int fieldType, const QUuid& mode);
 
    static void appExit(void);
    void saveFieldInputMode();

public:
    void loadCompletionSetting();
    void loadModeCycle();

private:
    KbEditContextData *d; 
}; 

#endif
