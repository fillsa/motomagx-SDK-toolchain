#ifndef __EZXSOUND_H_
#define __EZXSOUND_H_ 1

#include <stdlib.h>

#define DIVECE_OK 0

enum SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T {
	used_by_flashclient = 0x405
};

enum SOUNDM_AUDIO_SYSTEMDEV_TYPE_ENUM_T {
};


enum AAL_STATUS_ENUM_T {
};


class AM_VIRTUAL_CODEC_CLASS
{
public:
	AM_VIRTUAL_CODEC_CLASS();
	~AM_VIRTUAL_CODEC_CLASS();    

	int setGEQStatus(bool);
	int getGEQStatus(bool);
	int setGEQGainProfile(int);
	int getGEQGainProfile(int&);
	int setBassboostStatus(bool);
	int setBassboostValue(int, int);
	int getBassboostStatus(bool&);
	int getBassboostValue(int&, int&);
	int setAIEStatus(bool);
	int setAIEValue(int, int);
	int getAIEStatus(bool);
	int getAIEValue(int&, int&);
	int setCodecType(int);
	int getCodecType(int&);

private:
	uint fix[9];
};

class AM_VIRTUAL_DEV_BASE_CLASS
{
private:
	uint fix[5];

public:
	AM_VIRTUAL_CODEC_CLASS *codec;

	AM_VIRTUAL_DEV_BASE_CLASS();
	virtual ~AM_VIRTUAL_DEV_BASE_CLASS();

	virtual int  read(short*, unsigned int);
	virtual int  write(short*, unsigned int);
	virtual int  canWrite() = 0;
	virtual int  canRead() = 0;
	virtual int  bytesWritten() const;
	virtual int  channels() const;
	virtual int  frequency() const;
	virtual int  bytesPerSample() const;
	virtual int  bufferSize() const = 0;
	virtual void getVolume(unsigned int&, unsigned int&, bool&) = 0;
	virtual int  isMuted() = 0;
	virtual void increaseVolume() = 0;
	virtual void decreaseVolume() = 0;
	virtual void setVolume(int) = 0;
	virtual void volumeChanged(bool) = 0;
	virtual void setAudioDevice(unsigned int, unsigned int, unsigned int) = 0;
	virtual void checkDevState();
	virtual void flush();
	virtual int  bytesRendered() const;
	virtual void refresh();
	virtual int  open();
	virtual void close();
	virtual void lock();
	virtual void unlock();
	virtual void pause();
	virtual void resume();
};

/* Size: 124=31*4 */

class AM_NORMAL_DEV_INTERFACE : public AM_VIRTUAL_DEV_BASE_CLASS
{
private:
	uint fix[30];
	
public:
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T);
	AM_NORMAL_DEV_INTERFACE(SOUNDM_AUDIO_SYSTEMDEV_TYPE_ENUM_T, unsigned int, unsigned int, unsigned int);
	/* arg1 = SOUNDM_AUDIO_SYSTEMDEV_NORMAL - devType 
	 * arg2 = 8000	- sample rate
	 * arg3 = 1	- channels
	 * arg4 = 2	- bytes per sample
	 */
	AM_NORMAL_DEV_INTERFACE();

	virtual ~AM_NORMAL_DEV_INTERFACE();

	virtual int  read(short*, unsigned int);
	virtual int  write(short*, unsigned int);
	virtual int  canWrite();
	virtual int  canRead();
	virtual int  bytesWritten() const;
	virtual int  channels() const;
	virtual int  frequency() const;
	virtual int  bytesPerSample() const;
	virtual int  bufferSize() const;
	virtual void getVolume(unsigned int&, unsigned int&, bool&);
	virtual int  isMuted();
	virtual void increaseVolume();
	virtual void decreaseVolume();
	virtual void setVolume(int);
	virtual void volumeChanged(bool);
	virtual void setAudioDevice(unsigned int, unsigned int, unsigned int);
	virtual void checkDevState();
	virtual void flush();
	virtual int  bytesRendered() const;
	virtual void refresh();
	virtual int  open();
	virtual void close();
	virtual void lock();
	virtual void unlock();
	virtual void pause();
	virtual void resume();

	void VRSetHWIGain(int);
	void VRDuringRecord(bool);
	void am_normdev_init(SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T, unsigned int, unsigned int, unsigned int);
	void recordStartTime(timeval&);
	void adjustDataLength(short*, unsigned int, unsigned int*, unsigned int*);
	void writeAlignedData(short*, unsigned int, AAL_STATUS_ENUM_T*);
	void vr_notify_enabled(bool);
	void am_normdev_verify_freq(unsigned int);

};

#endif
