
/* Size: v+8 */

class QPTF
{
    unsigned int data[8];

public:
	virtual int getPacketId();
	virtual int ptf_getState();
	virtual QRect globalRect();
	virtual bool sendPackage();
	virtual bool sendPackage(int, QRect, int, int, QString, QString);
	virtual int getPackageType();
	virtual QString getPtfText();
	virtual void setPtfText(QString const&);
	virtual QPixmap *getPtfPixmap();
	virtual QString getPtfIconId();
	virtual void setPtfIconId(QString const&);
};
