#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

#include <sound/ZAudioNormalDev.h>

extern "C" {
 void * EZX_open(int rate, int channels, int format, int flags);
 int EZX_play(void *handle, void *data, int len);
 int EZX_ospace(void *handle);
 int EZX_written(void *handle);
 int EZX_rendered(void *handle);
 void EZX_flush(void *handle);
 void EZX_pause(void *handle);
 void EZX_resume(void *handle);
 void EZX_getvolume(void *handle, int * n1, int * n2, int * n3);
 void EZX_setvolume(void *handle, int);
 void EZX_changevolume(void *handle, int);
 void EZX_uninit(void *handle, int immed);
};

void * EZX_open(int rate, int channels, int format, int flags)
{
    ZAudioNormalDev * h = new ZAudioNormalDev();
    h->setAudioDevice(rate, channels, 2);
    return (void*)h;
}

void EZX_uninit(void *handle, int immed)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    if (!immed)
	h->flush();
    h->close();
    delete h;
}

void EZX_getvolume(void *handle, int *n1, int *n2, int *n3)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    unsigned int a, b;
    bool c;
    h->getVolume(a, b, c);
    *n1 = a;
    *n2 = b;
    *n3 = c;
}

void EZX_setvolume(void *handle, int n)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    h->setVolume(n);
}

void EZX_changevolume(void *handle, int n)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    if (n > 0)
	h->increaseVolume();
    else
	h->decreaseVolume();
    h->pVirtualCodec->setBassboostStatus(true);
    h->pVirtualCodec->setBassboostValue(7,7);
    h->pVirtualCodec->setCodecType(SM_CODEC_GROUP_MULTIMEDIA);
}


int EZX_play(void *handle, void *data, int len)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    int ret = 0;
    if (len > 0)
      ret = h->write((short*)data, len/2);
    return ret;
}

int EZX_ospace(void *handle)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    return h->bufferSize();
}

void EZX_pause(void *handle)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    h->pause();
}

void EZX_flush(void *handle)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    h->flush();
}

void EZX_resume(void *handle)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    h->resume();
}

int EZX_written(void *handle)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    return h->bytesWritten();
}

int EZX_rendered(void *handle)
{
    ZAudioNormalDev * h = (ZAudioNormalDev *)handle;
    return h->bytesRendered();
}
