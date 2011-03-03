#ifndef __ZHEADER_H__
#define __ZHEADER_H__

#include <ZWidget.h>
#include <qstring.h>
#include <qrect.h>
#include <qdatetime.h>

class ZHeaderSysStatus;
class ZHeaderMainDisplay;
class ZHeaderCLIIDL;
class ZHeaderMainDisplayIDL;
class ZHeaderCLI;
class ZHeaderDisplayWindow;
class ZHeaderIDL;
class QTimer;

#define MAINDISPLAY_HEADER FULL_TYPE

class ZHeader : public ZWidget
{
Q_OBJECT
public:

	enum HEADER_TYPE
	{
		NORMAL_TYPE,
		TIME_TYPE,
		TINY_TYPE,
		FULL_TYPE, INVALID_TYPE, HEADER_TYPE_NUM = INVALID_TYPE
	};

   // enum HEADER_TYPE {CLI_HEADER, CLI_IDL, MAINDISPLAY_IDL, MAINDISPLAY_HEADER, INVALID_TYPE, HEADER_TYPE_NUM = INVALID_TYPE};    
    enum HEADER_STATUS {AIRPLANE, ROAMING, SIGNAL, 
                        ACTIVE_CIRCUIT_DATA_CALL, ACTIVE_VOICE_CALL,
                        WIFI, GPRS, EDGE, THREEG, CDMAPDS, SERVICE,
                        CALLFORWARDING, ACTIVELINE, VOICEPRIVACY,
                        VR, BATTERY, IM, BT, NOTIFY,
                        PRESENCE,MESSAGE, 
                        LOCATION, ALERT, WIFISIGNAL, USB, AIM, YAHOO, ICQ, MSN,
                        SPEAKER, FDN, JAVA, NEWVOICE, UNHEARD_VOICE, EMAIL,
                        INVALID_MODE, STATUS_NUM};

    typedef struct AppStatus
    {
        Q_INT8 status;
        QString strResID[HEADER_TYPE_NUM]; //0: CLI_HEADER  1: CLI_IDL  2: MAINDISPLAY_IDL  3: MAINDISPLAY_HEADER
    } AppStatus_S;

    class AppStatusInfo_S
    {
    public:
        AppStatusInfo_S();
        ~AppStatusInfo_S();
        Q_INT8 status;
        Q_INT32 numStatus;    
        Q_INT32 priority;
        AppStatus_S* appStatus;

    };

    ZHeader(QWidget* parent = 0 , const char* name = 0, WFlags f = 0);

    ZHeader(ZHeader::HEADER_TYPE t, QWidget* parent = 0 , const char* name = 0, WFlags f = 0);
    QString getPrimTitle();

    QString getSecondTitle();

    void setPrimTitle(const QString &text);

    void setSecondTitle(const QString &text);

    bool setTitleIcon(const QPixmap& pmp);

    QPixmap getTitleIcon();

    void setAlignment(int alignment);

    int alignment();

    static QSize headerSize(ZHeader::HEADER_TYPE t);
    
    static bool registerInfo(const ZHeader::AppStatusInfo_S& as);

    static bool unregisterInfo(ZHeader::HEADER_STATUS s);

    bool switchHeader(ZHeader::HEADER_TYPE t);

    enum {EMPTY_STATUS = -1, START_BLINK = -3, END_BLINK = -4, START_ANIMATION = -5, END_ANIMATION = -6};

    static bool changeStatus(ZHeader::HEADER_STATUS s, int statusVal);

    void setPalette(const QPalette&);

    bool isZEnable();

    void setTruncEnable(bool bTrunc);

    bool isTruncEnable();

    ~ZHeader();

signals:
    void primTitleChanged(const QString&);
    void secondTitleChanged(const QString&);
protected slots:
    void slotChangePrimTitle(const QString& text);

    void slotChangeSecondTitle(const QString& text);

    void slotGetIcon(int nIdx);

    void slotDisplayTime();

    void slotPaletteChanged();
protected:
    void updateArea(int nIdx);
    void init();
    void initStatus(ZHeader::HEADER_TYPE t);
    virtual void paintEvent(QPaintEvent*);
    virtual void resizeEvent(QResizeEvent*);
    void setTimeString();    
    friend class ZHeaderDisplayWindow;
    friend class ZHeaderMainDisplay;
    friend class ZHeaderCLIIDL;
    friend class ZHeaderCLI;
    friend class ZHeaderMainDisplayIDL;
    friend class ZHeaderIDL;
private:
    enum {TIME_LEN = 5};
    int m_nAlignment;
    bool m_bHasTwoLine;
    ZHeaderSysStatus* m_pSysStatus;
    QTime m_headerTime;
    QTimer* m_pTimeTimer;
    QString m_strTime;
    QString m_strPrimTitle;
    QString m_strSecondTitle;
    QPixmap m_pmpTitle;
    ZHeaderDisplayWindow* m_pDisplay;
    bool m_bIsTruncEnable;
};

#endif

