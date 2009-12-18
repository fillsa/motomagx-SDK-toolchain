#ifndef _ZMESSAGEDLG_H
#define _ZMESSAGEDLG_H

#include <ZPopup.h>

/* Size 216 = 54*4 */

class ZMessageDlg : public ZPopup
{
    Q_OBJECT
    unsigned int data[55 - sizeof(ZPopup)/4];

public:
	enum MessageDlgType
	{
		ok_cancel, //choose
  yes_no, //confirm
  just_ok, //ok
  NONE //custom
	};

  ZMessageDlg(QWidget* parent = NULL, char const* name = 0, bool modal, WFlags f = 0);
  ZMessageDlg(QString const& header, QString const& message, MessageDlgType type, int timeout_ms = 0, QWidget* parent = NULL, char const* name = 0, bool modal = TRUE,  WFlags f = 0); //TODO: fix if parent and name parameters are correct
	~ZMessageDlg();

	void initialize();
	void setMsgIcon(QString const&);
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void setType(ZMessageDlg::MessageDlgType);
};
#endif
