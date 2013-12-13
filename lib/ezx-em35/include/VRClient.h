//
//Writed for VE66 by Ant-ON, 04.07.2011
//

#ifndef VRCLIENT_H
#define VRCLIENT_H

enum VR_PLAYTTS_T
{
	VR_UNKNOWN,
};

class VRClient
{
public:
	static int VR_getVRType();
	static void VR_interruptVR();
	static void VR_interruptVR_ToIdle();
	static bool VR_startVR();
	
	static int getTTSVolumn();
	static bool VR_TTS_play_Text(const QString &text, VR_PLAYTTS_T = VR_UNKNOWN);

	static void SDVR_confirmTraining(QString const&);
	static void SDVR_deleteAllVoiceTag();
	static void SDVR_deleteVoiceTag(QString const&);
	static void SDVR_playVoiceTag(QString const&);
	static void SDVR_training(QString&);
};

#endif
