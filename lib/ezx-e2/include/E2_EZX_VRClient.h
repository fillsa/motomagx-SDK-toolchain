//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly

#ifndef _E2_EZX_VRCLIENT_H
#define _E2_EZX_VRCLIENT_H

#include <qstring.h>

enum VR_PLAYTTS_T
{
	TTS
};
class VRClient
{
	char tmp[4096];
public:
	void SDVR_playVoiceTag(QString const&);
	void VR_startVR();
	void VR_TTS_play_Text(QString const&, VR_PLAYTTS_T);
/*
	int SDVR_confirmTraining(QString const&)
	int SDVR_deleteAllVoiceTag()
	int SDVR_deleteVoiceTag(QString const&)
	int SDVR_training(QString&)
	int VR_TTS_play_Text(QString const&, VR_PLAYTTS_T)
	int VR_getVRType()
	int VR_interruptVR()
	int getTTSVolumn()
*/
};
#endif
