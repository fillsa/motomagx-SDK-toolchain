#ifndef Z_KEYDEF_H
#define Z_KEYDEF_H

#include  <qnamespace.h>
#include  <qcstring.h>
#define EAT_KEY_BROADCAST_CHANNEL "eatkey/bc"
#define EAT_KEY_IN_FLIPOFF_MESSAGE "eatkey_in_flipoff"
#define HARDKEY_LCDSTATUS_NOTIFY_CHANNEL "/hardkey/lcdstatus"
#define EAT_KEY_NOTIFY_CHANNEL HARDKEY_LCDSTATUS_NOTIFY_CHANNEL
#define EAT_KEY_NOTIFY_LCD_STATUS_MESSAGE "lcd_status_in_flipoff"
#define HARDKEY_LCD_BACKLIGHTSTATUS_MESSAGE "lcd_backlight_status_in_flipoff"
#define KEYLOCK_BYPASS_CHANNEL "keylock_bypass_channel"
#define KEYLOCK_KEY_LOCK_MESSAGE "KeyLocked"
#define KEYLOCK_KEY_UNLOCK_MESSAGE "KeyUnlocked"
#define KEYLOCK_FEEDBACK_SOUNDKEY "soundKey(int,int)"
#define EZX_KEY_0                       Qt::Key_0           // 0
#define EZX_KEY_1                       Qt::Key_1           // 1
#define EZX_KEY_2                       Qt::Key_2           // 2
#define EZX_KEY_3                       Qt::Key_3           // 3
#define EZX_KEY_4                       Qt::Key_4           // 4
#define EZX_KEY_5                       Qt::Key_5           // 5
#define EZX_KEY_6                       Qt::Key_6           // 6
#define EZX_KEY_7                       Qt::Key_7           // 7
#define EZX_KEY_8                       Qt::Key_8           // 8
#define EZX_KEY_9                       Qt::Key_9           // 9 
#define EZX_KEY_STAR                    Qt::Key_Asterisk    // *
#define EZX_KEY_POUND                   Qt::Key_NumberSign  // #

#define EZX_KEY_UP                      Qt::Key_Up          // Navi up
#define EZX_KEY_DOWN                    Qt::Key_Down        // Navi down
#define EZX_KEY_LEFT                    Qt::Key_Left        // Navi left
#define EZX_KEY_RIGHT                   Qt::Key_Right       // Navi right
#define EZX_KEY_CENTER_SELECT           Qt::Key_Return          // Center select

#define EZX_KEY_SIDE_UP                 Qt::Key_PageUp      // side up
#define EZX_KEY_SIDE_DOWN               Qt::Key_PageDown    // side down
#define EZX_KEY_SIDE_SELECT             Qt::Key_Enter       // side select

#define EZX_KEY_CLEAR                   Qt::Key_F3          //  Qt::Key_Backspace   // Back/Clear key

#define EZX_KEY_SEND                    Qt::Key_F1          // Send key
#define EZX_KEY_END                     Qt::Key_F2          // End key

#define EZX_KEY_MSG                     Qt::Key_F20          // Messaging key
#define EZX_KEY_CARRIER                 Qt::Key_F4          // Carrier key
#define EZX_KEY_IMAGING                 Qt::Key_F5          // Imaging key 
#define EZX_KEY_VR                      Qt::Key_F6          // VR key
#define EZX_KEY_PTX                     Qt::Key_F7          // Push to X key
#define EZX_KEY_TASK                    Qt::Key_F14          // Task manager key.
#define EZX_KEY_LSK                     Qt::Key_F9          // Left soft key
#define EZX_KEY_MSK                     Qt::Key_F10         // Middle soft key
#define EZX_KEY_RSK                     Qt::Key_F11         // Right soft key

#define EZX_KEY_HOME                    Qt::Key_F12         // Home key

#define EZX_KEY_FLIP                    Qt::Key_F13         // Lid for clamshell device

#define EZX_KEY_POWER                   Qt::Key_F16         // Power key

#define EZX_KEY_HEADSET_ANSWER          Qt::Key_F21         // Headset answer
#define EZX_KEY_HEADSET_INSERT          Qt::Key_F22         // Headset insert

#define EZX_KEY_FM                   
#define EZX_KEY_JUMP                    Qt::Key_F25
#define EZX_KEY_PLAY_PAUSE              Qt::Key_F26
#define EZX_KEY_STOP                    Qt::Key_F27
#define EZX_KEY_PREV                    Qt::Key_F28
#define EZX_KEY_NEXT                    Qt::Key_F29
#define EZX_KEY_LOCK                    Qt::Key_F15

#define KEYCODE_TS_PREV                 0x104d              //Prev and Rewind of Touch Sensitive keys
#define KEYCODE_TS_PLAY_PAUSE           0x104e              //Play and Pause of Touch Sensitive Keys
#define KEYCODE_TS_NEXT                 0x104f              //Next and Forward of Touch Sensitive Keys

#define EZX_KEY_SLIDER                  Qt::Key_F23

#define KEYCODE_UNKNOWN                 0xffff              //Qt::Key_unknown

typedef enum {
    SYSTEM_FLIP_OPEN = 0,
    SYSTEM_FLIP_CLOSE
} FLIP_STATUS;

typedef enum {
    KEY_SLIDER_OPEN = 0, // Release event.
    KEY_SLIDER_CLOSE     // Press event.
} KEY_SLIDER_STATUS;

	


typedef enum {
    KEY_MSG_PRESS             = 0x00000001,
    KEY_MSG_RELEASE           = 0x00000002,
    KEY_MSG_PRESS_AND_HOLD    = 0x00000004,
    KEY_MSG_AUTO_REPEAT_FLAG  = 0x10000000
} KEY_MSG_T;


#define KEY_PRESS_AND_HOLD_TIME         1500
#define KEY_FIRST_REPEAT_TIME           300
#define KEY_TIME_BETWEEN_REPEAT         150

void UTIL_BroadcastKeyMsg(int key, int type);
QCString UTIL_GetKeyEventChannel();
QCString UTIL_GetKeySoundChannel();

#endif  // UTIL_KEYDEF_H
