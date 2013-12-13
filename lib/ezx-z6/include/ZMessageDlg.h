#ifndef _ZMESSAGEDLG_H
#define _ZMESSAGEDLG_H

#include <ZPopup.h>

/* Size 216 = 54*4 */

class ZMessageDlg : public ZPopup
{
    Q_OBJECT
    unsigned int data[54 - sizeof(ZPopup)/4];

public:
	enum MessageDlgType
    {
        TypeChoose=0,        
        TypeConfirm=1,       
        TypeOK=2,            
        TypeCustom=3,
        TypeNotice=4,
        
        ok_cancel=0, //choose
		yes_no=1, //confirm
		just_ok=2, //ok
		NONE=3 //custom        
    };

  ZMessageDlg(QWidget* parent = NULL, char const* name = 0, bool modal=true, WFlags f = 0);
  ZMessageDlg(QString const& header, QString const& message, MessageDlgType type, int timeout_ms = 0, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE,  WFlags f = 0); //TODO: fix if parent and name parameters are correct
	~ZMessageDlg();

	void initialize();
	void setMsgIcon(const QString& strIcon);
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void setType(ZMessageDlg::MessageDlgType);
};
#endif
