#ifndef IMETHOD_H
#define IMETHOD_H

#include <quuid.h>
#include <qmap.h>
#include <qstring.h>

#include "ZKbInputField.h"

#define WILDCARD     '^'

#ifndef IMID_ENGLISH_KB
#  define IMID_ENGLISH_KB  QUuid(0x200100d4,0x7206,0xe819,0x69,0x43,0xc7,0xa1,0xce,0xdd,0x91,0xd9)
#endif


# ifndef IMID_SYMBOL_KB
#  define IMID_SYMBOL_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0x02)
# endif


#ifndef IMID_SYMBOL_CN
#define  IMID_SYMBOL_CN  QUuid(0x220100a0,0x2c41,0x1002,0x19,0x4c,0xa6,0xa8,0x0c,0xff,0x16,0x4f)
#endif
#ifndef  IMID_SYMBOL_EMEA
#define  IMID_SYMBOL_EMEA   QUuid(0x220200a0,0x2c41,0x1002,0x19,0x4c,0xa6,0xa8,0x0c,0xff,0x16,0x4f)
#endif
#ifndef  IMID_SYMBOL_THAI
#define  IMID_SYMBOL_THAI   QUuid(0x220400a0,0x2c41,0x1002,0x19,0x4c,0xa6,0xa8,0x0c,0xff,0x16,0x4f)
#endif

#ifndef IMID_NUMBER_KB
#  define IMID_NUMBER_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0x10)
#endif

#ifndef IMID_PINYIN_KB
#  define IMID_PINYIN_KB  QUuid(0x220100a0,0x2c41,0x1002,0x19,0x4c,0xa6,0xa8,0x0c,0xff,0x16,0x50)
#endif

#ifndef IMID_ZHUYIN_KB
#  define IMID_ZHUYIN_KB QUuid(0x220100a0,0x2c42,0x1002,0x33,0x4c,0xa6,0xa8,0x0c,0xff,0x16,0x66)
#endif

#define HWRCLASS     0x220100a0  //0x6919720a
#ifndef IMID_HANDWRITING_KB
#  define IMID_HANDWRITING_KB  QUuid(HWRCLASS,0x2c41,0x1002,0x19,0x4c,0xa6,0xb4,0x0c,0xff,0x16,0x51)//QUuid( HWRCLASS, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa4, 0x10)
#endif

# ifndef IMID_FRENCH_KB
#  define IMID_FRENCH_KB QUuid(0x20010374,0x6a8f,0xd6bf,0x12,0x48,0x4a,0xbc,0x45,0xee,0x88,0x97)
#endif

# ifndef IMID_GERMAN_KB
#  define IMID_GERMAN_KB QUuid(0x20010174,0x6a8f,0xd6bf,0x12,0x48,0x4a,0xbc,0x45,0xee,0x88,0x97)
#endif

# ifndef IMID_ITALIAN_KB
#  define IMID_ITALIAN_KB QUuid(0x20010474,0x6a8f,0xd6bf,0x12,0x48,0x4a,0xbc,0x45,0xee,0x88,0x97)
#endif

# ifndef IMID_PORTUGUESE_KB
#  define IMID_PORTUGUESE_KB  QUuid(0x20010874,0x6a8f,0xd6bf,0x12,0x48,0x4a,0xbc,0x45,0xee,0x88,0x97)
#endif

# ifndef IMID_SPANISH_KB
#  define IMID_SPANISH_KB  QUuid(0x20010574,0x6a8f,0xd6bf,0x12,0x48,0x4a,0xbc,0x45,0xee,0x88,0x97)
#endif

# ifndef IMID_FINGERPAD_KB
#  define IMID_FINGERPAD_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0xac, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0xe2)
#endif

//   {637A8A88-AF98-41DA-969A-2BD16ECDEC10}
# ifndef IMID_ITAP6_KB
#  define IMID_ITAP6_KB QUuid( 0x637a8a88, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xec, 0x10)
# endif

# ifndef IMID_THAI_KB
#  define IMID_THAI_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xa8, 0x05)
#endif

# ifndef IMID_ITAP6_KB
#  define IMID_ITAP6_KB QUuid( 0x637a8a88, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0xec, 0x10)
# endif

#ifndef IMID_HWRCURSIVE_KB
#  define IMID_HWRCURSIVE_KB QUuid( 0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1,0xe9,0xc1,0x74,0x01)
#endif

# ifndef IMID_CROATIAN_KB
#  define IMID_CROATIAN_KB QUuid(0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x63, 0xf, 0x1a, 0xeb, 0x75, 0xf)
#endif

# ifndef IMID_CZECH_KB
#  define IMID_CZECH_KB QUuid(0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0xc2, 0x1e, 0xb8, 0x4e, 0x61, 0x31)
#endif

# ifndef IMID_DUTCH_KB
#  define IMID_DUTCH_KB QUuid(0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0xef, 0x9a, 0x4d, 0x3d, 0x42, 0x23)
#endif

# ifndef IMID_HUNGARIAN_KB
#  define IMID_HUNGARIAN_KB QUuid(0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x8, 0xcd, 0x9c, 0x41, 0xff, 0x63)
#endif

# ifndef IMID_POLISH_KB
#  define IMID_POLISH_KB QUuid(0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0xfa, 0x2, 0x7b, 0x22, 0xa0, 0x36)
#endif

# ifndef IMID_SLOVAKIAN_KB
#  define IMID_SLOVAKIAN_KB QUuid(0x637a8a14, 0xaf98, 0x41da, 0x96, 0x9a, 0x75, 0x42, 0xa5, 0x4d, 0xb4, 0xeb)
#endif

#ifndef IMID_MMSOBJECT_KB
#  define IMID_MMSOBJECT_KB QUuid( 0x637a8a00, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0x00, 0x00)
#endif

#ifndef IMID_EMSOBJECT_KB
#  define IMID_EMSOBJECT_KB QUuid( 0x637a8a00, 0xaf98, 0x41da, 0x96, 0x9a, 0x2b, 0xd1, 0x6e, 0xcd, 0x00, 0x10)
#endif

















/************************
 ************************
 *
 * Input Method IDs for keypad based input methods 
 * 
 */

// Input mode status for keypad 
//

/**
 * MultiTAP input mode 
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c12} 
 */
# ifndef ZKB_INPUT_MULTITAP 
#  define ZKB_INPUT_MULTITAP QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x12)
# endif

/**
 * PREDICTIVE input mode 
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c13} 
 */
# ifndef ZKB_INPUT_PREDICTIVE
#  define ZKB_INPUT_PREDICTIVE QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x13)
# endif


/**
 * Number input mode 
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c14} 
 */
# ifndef ZKB_INPUT_NUMERIC
#  define ZKB_INPUT_NUMERIC QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x14)
# endif


/**
 * Symbol input mode 
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c15} 
 */
# ifndef ZKB_INPUT_SYMBOL
#  define ZKB_INPUT_SYMBOL QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x15)
# endif


/**
 * Pinyin input mode
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c16}
 */
# ifndef ZKB_INPUT_PINYIN
#  define ZKB_INPUT_PINYIN QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x16)
# endif


/**
 * BOPOMOFO input mode
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c17}
 */
# ifndef ZKB_INPUT_BOPOMOFO
#  define ZKB_INPUT_BOPOMOFO QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x17)
# endif

/**
 * Strokes input mode
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c18}
 */
# ifndef ZKB_INPUT_STROKES
#  define ZKB_INPUT_STROKES QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x18)
# endif

/**
 * EMOTICON input mode
 *
 *   {637a8c00-1098-42ca-969a-2bf163cd3c19}
 */
# ifndef ZKB_INPUT_EMOTICON
#  define ZKB_INPUT_EMOTICON QUuid( 0x637a8c00, 0x1098, 0x42ca, 0x96, 0x9a, 0x2b, 0xf1, 0x63, 0xcd, 0x3c, 0x19)
# endif



#ifndef IMID_UNDEFINED
#define IMID_UNDEFINED QUuid()
#endif











typedef QMap<QUuid, QString> QIMMap;
class QWidget;

namespace ZGlobal
{

    /**
     * input method aux property
     */
    enum KbFlags
    {
        KB_NULL = (int)0,
        KB_DISABLE_PREDICT = 0x00000001, ///< \a \c disable word completion for password fields. 
        KB_FINDBAR         = 0x00000010, ///< \a \c show input widget with a find bar 
    };

    /**
     * Set the input method
     *
     * @param inputMethod the input method selected.  If the input method is not 
     * specified, the default input method will be used
     * @param flags
     *
     * @see ZApplication
     *
     * @see ZMainWidget
     *
     * @note the keyboard is widget related, so if the application has no focus widget,
     * the function will do nothing. 
     *
     * @note the function will be implemented in the A780
     */
    void setInputMethod( const QUuid& inputMethod = IMID_UNDEFINED, int flags = KB_NULL );

    /**
     * Hide the input method widget
     * @param editor the widget to hide the input method 
     * @note the function will be implemented in the A780
     */
    void hideInputWidget( QWidget * editor = NULL);

    /**
     * Show the input method widget
     *
     * @param mwId the id of the widget which is bound with input widget
     * @param show
     * @param local
     *
     * @internal
     */
    void showInputWidget( int mwId, int show, bool local = false, const QUuid& imid = IMID_UNDEFINED );
};



#endif //Z760_IMETHOD_H



