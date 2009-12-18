#ifndef __ZGLOBAL_H__
#define __ZGLOBAL_H__ 1

#include <qrect.h>
#include <qwidget.h>
#include <quuid.h>

#define ZKB_INPUT_MULTITAP QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x12) ///< MultiTAP input mode {637a8c00-1098-42ca-969a-2bf163cd3c12}
#define ZKB_INPUT_PREDICTIVE QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x13) ///< PREDICTIVE input mode {637a8c00-1098-42ca-969a-2bf163cd3c13}
#define ZKB_INPUT_NUMERIC QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x14) ///< Number input mode {637a8c00-1098-42ca-969a-2bf163cd3c14}
#define ZKB_INPUT_SYMBOL QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x15) ///<  Symbol input mode {637a8c00-1098-42ca-969a-2bf163cd3c15}
#define ZKB_INPUT_PINYIN QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x16) ///< Pinyin input mode {637a8c00-1098-42ca-969a-2bf163cd3c16}
#define ZKB_INPUT_BOPOMOFO QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x17) ///< BOPOMOFO input mode {637a8c00-1098-42ca-969a-2bf163cd3c17}
#define ZKB_INPUT_STROKES QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x18) ///< Strokes input mode {637a8c00-1098-42ca-969a-2bf163cd3c18}
#define ZKB_INPUT_EMOTICON QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x19) ///< EMOTICON input mode {637a8c00-1098-42ca-969a-2bf163cd3c19}
#define ZKB_INPUT_TESTPLUGIN QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0xff) ///< EMOTICON input mode {637a8c00-1098-42ca-969a-2bf163cd3c19}
#define IMID_UNDEFINED QUuid() ///< undefined input mode

#define ZSetLayout(widgetPtr, globalR) widgetPtr->setGeometry(ZGlobal::mapFromGlobalR(widgetPtr, globalR))

enum EZX_FONT_SIZE_T {
};

namespace ZGlobal
{
    enum PaddingType {
    };
    enum VSpacingType {
    };

	QRect diffRect(QRect, QRect);
	QRect getAIAR();
	QRect getContentR( bool hasSecondTitle = FALSE );
	QRect getCst1_1R();
	QRect getCst2a_1R();
	QRect getCst2a_2R();
	QRect getCst2b_1R();
	QRect getCst2b_2R();
	QRect getCst2c_2R();
	QRect getCst3_1R();
	QRect getCst3_2R();
	QRect getCst3_3R();
	QRect getCst3a_1R();
	QRect getCst3a_2R();
	QRect getCst3a_3R();
	QRect getCst3b_1R();
	QRect getCst3b_2R();
	QRect getCst3b_3R();
	QRect getCst3c_1R();
	QRect getCst3c_2R();
	QRect getCst3c_3R();
	QRect getCst4a_1R();
	QRect getCst4a_2R();
	QRect getCst4a_3R();
	QRect getCst4a_4R();
	QRect getCst4b_1R();
	QRect getCst4b_2R();
	QRect getCst4b_4R();
	QRect getCstR();
	QRect getDesktopRect();
	QRect getDlgA1_1R();
	QRect getDlgA2a_1R();
	QRect getDlgA2b_1R();
	QRect getDlgA3a_1R();
	QRect getDlgA3a_3R();
	QRect getDlgA3b_1R();
	QRect getDlgA3b_3R();
	QRect getDlgA3c_1R();
	QRect getDlgA3c_3R();
	QRect getDlgB1_1R();
	QRect getDlgB2_1R();
	QRect getDlgCstLR();
	QRect getDlgCstMR();
	QRect getDlgCstSR();
	QRect getDlgLargeConR();
	QRect getDlgLargeR();
	QRect getDlgMiddleConR();
	QRect getDlgSmallConR();
	QRect getDlgSmallR();
	QRect getDlgTitleLR();
	QRect getDlgTitleMR();
	QRect getDlgTitleSR();
	QRect getFontSize(EZX_FONT_SIZE_T);
	QRect getGNBRect();
	QRect getHeaderR( bool hasSecondTitle = FALSE );
	QRect getHomeR( bool hasSecondTitle = FALSE );
	QRect getLineHeight();
	QRect getLineSpace();
	QRect getMainWidgetRect();
	QRect getPadding(PaddingType);
	QRect getScreenR();
	QRect getStatusBarR();
	QRect getSubContentR();
	QRect getVSpacing(VSpacingType);
	void hideInputWidget(QWidget*);
	QRect mapFromGlobalR(QWidget*, QRect);
	void setInputMethod(QUuid const&, int);
	void showInputWidget(int, int, bool, QUuid const&);
};

#endif
