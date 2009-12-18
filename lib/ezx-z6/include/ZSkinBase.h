#ifndef __ZSKINBASE_H__
#define __ZSKINBASE_H__

#include <qstring.h>
#include <qpixmap.h>
#include <qfont.h>
#include <qpainter.h>
#include <qwidget.h>

#include <qlist.h>
#include <qmap.h>
#include <qfile.h>
#include <qapplication.h>
#include <ZConfig.h>
#include <qbitmap.h>

typedef enum
{
    fsNoStyle   = 0,
    fsBold      = 1,
    fsItalic    = 2,
    fsUnderline = 4,
    fsStrikeOut = 8,
    fsOutline = 16
} FONT_STYLE_E;

typedef enum
{
    spNone,
    spH,
    spV,
    spMidH,
    spMidV,
    spScale,
    spTile,
    spCenter
} PIXMAP_STRETCH_POLICY_E;

typedef struct ZWidgetPaddingInfo
{
    short left;
    short right;
    short top;
    short bottom;
} WIDGET_PADDING_INFO_T; 

typedef struct ZWidgetBorderInfo
{
    PIXMAP_STRETCH_POLICY_E leftPolicy;
    PIXMAP_STRETCH_POLICY_E rightPolicy;
    PIXMAP_STRETCH_POLICY_E topPolicy;
    PIXMAP_STRETCH_POLICY_E bottomPolicy;
    unsigned int color;
    short width;
    short type;
    short fg_percent;    
} WIDGET_BORDER_INFO_T; 

typedef struct ZFontInfo
{
    short family;       
    short size;
    short leading;
    FONT_STYLE_E style;
    unsigned int color;
    short decoration;     
    short outlinedSize;  
    unsigned int outlinedColor;
    int align;
} FONT_INFO_T; 

typedef struct ZWidgetBackgroundInfo
{
    PIXMAP_STRETCH_POLICY_E stretchPolicy;
    unsigned int color;
    short type;
    short fg_percent;    
} WIDGET_BACKGROUND_INFO_T; 

#define MAX_WIDGET_SKINNABLE_STATES 4

typedef struct ZBasicSkinProp
{
    WIDGET_BACKGROUND_INFO_T bgInfo[ MAX_WIDGET_SKINNABLE_STATES ];
    WIDGET_BORDER_INFO_T bdInfo[ MAX_WIDGET_SKINNABLE_STATES ];
    WIDGET_PADDING_INFO_T padding;
    unsigned short bgPercent;
} ZBASIC_SKINNABLE_PROP_T; 

typedef struct ZCheckBoxSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingH2;
} ZCHECKBOX_SKINNABLE_PROP_T; 

typedef ZCHECKBOX_SKINNABLE_PROP_T ZRADIOBUTTON_SKINNABLE_PROP_T;

typedef struct ZOptionsMenuSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingV1;
} ZOPTIONSMENU_SKINNABLE_PROP_T; 

typedef struct ZOptionsMenuItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
} ZOPTIONSMENUITEM_SKINNABLE_PROP_T; 

typedef struct ZListBoxSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short vSpace1;
    short vSpace2;
    short vSpace3;
} ZLISTBOX_SKINNABLE_PROP_T; 

typedef struct ZListItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    unsigned int dividerColor;
    short dividerWidth;
    short ImageContainerType;
    short hSpace1;
    short hSpace2;
    short hSpace3;
    short hSpace4;
    short hSpace5;
    short hSpace6;
    short vSpace1;
} ZLISTITEM_SKINNABLE_PROP_T; 

typedef struct ZAlternateChooserSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
} ZALTERNATESCHOOSER_SKINNABLE_PROP_T; 

typedef struct ZAlternateItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
} ZALTERNATESITEM_SKINNABLE_PROP_T; 

typedef struct ZAlternateListSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingV1;
} ZALTERNATESLIST_SKINNABLE_PROP_T; 

typedef struct ZAppInfoAreaSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingH2;
} ZAPPINFOAREA_SKINNABLE_PROP_T; 

typedef struct ZPressButtonSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short imageMaxSize;
} ZPRESSBUTTON_SKINNABLE_PROP_T; 


typedef struct ZCalendarModuleSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    ZBASIC_SKINNABLE_PROP_T day;
    ZBASIC_SKINNABLE_PROP_T curDay;
    ZBASIC_SKINNABLE_PROP_T dayHeader;
    ZBASIC_SKINNABLE_PROP_T curDayHeader;
    ZBASIC_SKINNABLE_PROP_T emptyDay;
    ZBASIC_SKINNABLE_PROP_T grid;
    short gridWidth;
    short spacingH1;
    short spacingV1;
    short spacingV2;
    short spacingV3;
} ZCALENDARMODULE_SKINNABLE_PROP_T; 

typedef struct ZColorModuleSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    ZBASIC_SKINNABLE_PROP_T cname;
    ZBASIC_SKINNABLE_PROP_T well;
    unsigned int highlightColor;
    short swatchHeight;
    short swatchWidth;
    short swatchBorderWidth;
    unsigned int swatchBorderColor;
    short spacingH1;
    short spacingH2;
    short spacingV1;
    short spacingV2;
} ZCOLORMODULE_SKINNABLE_PROP_T; 

typedef struct ZColorPickerSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    ZBASIC_SKINNABLE_PROP_T well;
    short spacingH1;
} ZCOLORPICKER_SKINNABLE_PROP_T; 

typedef struct ZComboBoxSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
} ZCOMBOBOX_SKINNABLE_PROP_T; 

typedef struct ZDateModuleSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
} ZDATEMODULE_SKINNABLE_PROP_T; 

typedef struct ZDatePickerSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingH2;
    short spacingV1;
} ZDATEPICKER_SKINNABLE_PROP_T; 

typedef struct ZExhibitButtonSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingV1;
} ZEXHIBITBUTTON_SKINNABLE_PROP_T; 

typedef struct ZLineEditSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
} ZLINEEDIT_SKINNABLE_PROP_T; 

typedef struct ZFivewayButtonSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingH2;
    short spacingV1;
    short spacingV2;
} ZFIVEWAYBUTTON_SKINNABLE_PROP_T ;

typedef struct ZFormContainerSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingV1;
    short spacingV2;
    short spacingV3;
} ZFORMCONTAINTER_SKINNABLE_PROP_T ;

typedef struct ZFormItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingV1;
    short spacingH1;
} ZFORMITEM_SKINNABLE_PROP_T ;

typedef struct ZIconViewSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short hSpace1;
    short vSpace1;
} ZICONVIEW_SKINNABLE_PROP_T ;

typedef struct ZIconViewItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    PIXMAP_STRETCH_POLICY_E highlightPolicy;
    unsigned int highlightColor;
    short ImageContainerType;
    short highlightWidth;
    short vSpace1;
} ZICONVIEWITEM_SKINNABLE_PROP_T ;

typedef struct ZGroupBoxSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingV1;
} ZGROUPBOX_SKINNABLE_PROP_T ;

typedef struct ZHeaderSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingV1;
} ZHEADER_SKINNABLE_PROP_T ;

typedef struct ZInputMatrixSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingV1;
} ZINPUTMATRIX_SKINNABLE_PROP_T ;

typedef struct ZInteractiveHighlightSkinProp
{
    unsigned int underlineColor;
    short underlineHeight;
    unsigned int highlightColor;
} ZINTERACTIVEHIGHLIGHT_SKINNABLE_PROP_T ;

typedef struct ZJumpBoxSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    ZBASIC_SKINNABLE_PROP_T field;
    short spacingH1;
    short spacingV1;
} ZJUMPBOX_SKINNABLE_PROP_T ;

typedef struct ZMatrixItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
} ZMATRIXITEM_SKINNABLE_PROP_T ;

typedef struct ZMeterSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    ZBASIC_SKINNABLE_PROP_T indicator;  
    short spacingS1;
    short spacingS2;
    short maxSize;
    short meterType;           
} ZMETER_SKINNABLE_PROP_T ;

typedef struct ZMeterModuleSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingV1;
} ZMETERMODULE_SKINNABLE_PROP_T ;

typedef struct ZMultiLineEditSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;     
    short lineType_HS;
    short lineType_Highlight;
    short lineType_Std;
    short lineType_Selected;
    unsigned int lineColor_HS;
    unsigned int lineColor_Highlight;
    unsigned int lineColor_Std;
    unsigned int lineColor_Selected;
    short lineHeight;
} ZMULTILINEEDIT_SKINNABLE_PROP_T ;

typedef struct ZNavtabWidgetSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;   
    ZBASIC_SKINNABLE_PROP_T tabArea;   
    unsigned int bgColor;
    short spacingH1;
} ZNAVTABWIDGET_SKINNABLE_PROP_T ;

typedef struct ZPanelSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
} ZPANEL_SKINNABLE_PROP_T ;

typedef struct ZPopupSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short paddingText_Left;
    short paddingText_Right;
    short paddingText_Top;
    short paddingText_Bottom;
    short spacingH1;
    short spacingV1;
} ZPOPUP_SKINNABLE_PROP_T ;

typedef struct ZScrollViewSkinProp
{
    char hVisible;
    char vVisible; 
} ZSCROLLVIEW_SKINNABLE_PROP_T ;

typedef struct ZSegmentFieldSkinProp
{
    short spacingH1;
} ZSEGMENTFIELD_SKINNABLE_PROP_T ;

typedef struct ZSeparatorSkinProp
{
    PIXMAP_STRETCH_POLICY_E leftStretch;
    PIXMAP_STRETCH_POLICY_E rightStretch;
    int height;  
    short hSpace1;
    short hSpace2;
    short leftStretchFlag;
    short rightStretchFlag;
} ZSEPARATOR_SKINNABLE_PROP_T ;

typedef struct ZSettingItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short hSpace1;
    short vSpace1;
} ZSETTINGITEM_SKINNABLE_PROP_T ;

typedef struct ZSliderSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    PIXMAP_STRETCH_POLICY_E trackCenterStretchPolicy;
    short maxSize;
    short spacingS1;
} ZSLIDER_SKINNABLE_PROP_T ;

typedef struct ZSoftkeySkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
} ZSOFTKEY_SKINNABLE_PROP_T ;

typedef struct ZSplitpaneSkinProp
{
    PIXMAP_STRETCH_POLICY_E dividerBgStretchPolicy;
    short dividerType;
    unsigned int dividerColor;
    short dividerHeight;
} ZSPLITPANE_SKINNABLE_PROP_T ;

typedef struct ZDetailViewSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingV1;
    short spacingV2;
    short spacingV3;
} ZDETAILVIEW_SKINNABLE_PROP_T ;

typedef struct DetailItemSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
} ZDETAILITEM_SKINNABLE_PROP_T ;

typedef struct ZMediaControlSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short spacingH1;
    short spacingV1;
} ZMEDIACONTROL_SKINNABLE_PROP_T ;

typedef struct ZImageContainerSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short bgSize_Std;
    short bgSize_Highlight;
} ZIMAGECONTAINER_SKINNABLE_PROP_T ;

typedef struct ZScrollbarSkinProp   
{
    short spacingS1;
} ZSCROLLBAR_SKINNABLE_PROP_T ;

typedef struct ZStructureDataSkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
    short disabled_status_type;
    unsigned int disabled_status_color;
    short disabled_status_percent;
} ZSTRUCTDATAIMAGE_SKINNABLE_PROP_T ;

typedef struct ZFSBASkinProp
{
    ZBASIC_SKINNABLE_PROP_T base;
} ZFSBA_SKINNABLE_PROP_T ;

typedef struct ZFSBA
{
    short int fsbaID;
    short int fsbaOpacity;
} FSBA_INFO_T ;

struct ZWidgetSkinProps
{
    ZALTERNATESCHOOSER_SKINNABLE_PROP_T zAlternatesChooser;
    ZALTERNATESITEM_SKINNABLE_PROP_T zAlternatesItem;
    ZALTERNATESLIST_SKINNABLE_PROP_T zAlternatesList;
    ZAPPINFOAREA_SKINNABLE_PROP_T zAppInfoArea;
    ZCALENDARMODULE_SKINNABLE_PROP_T zCalendarModule;
    ZCHECKBOX_SKINNABLE_PROP_T zCheckBox;
    ZCOLORMODULE_SKINNABLE_PROP_T zColorModule;
    ZCOLORPICKER_SKINNABLE_PROP_T zColorPicker;
    ZCOMBOBOX_SKINNABLE_PROP_T zComboBox;
    ZDATEMODULE_SKINNABLE_PROP_T zDateModule;
    ZDATEPICKER_SKINNABLE_PROP_T zDatePicker;
    ZEXHIBITBUTTON_SKINNABLE_PROP_T zExhibitButton;
    ZICONVIEW_SKINNABLE_PROP_T zIconView1;
    ZICONVIEW_SKINNABLE_PROP_T zIconView2;
    ZICONVIEWITEM_SKINNABLE_PROP_T zIconViewItem1;
    ZICONVIEWITEM_SKINNABLE_PROP_T zIconViewItem2;
    ZLINEEDIT_SKINNABLE_PROP_T zLineEdit;
    ZFIVEWAYBUTTON_SKINNABLE_PROP_T zFiveWayButton1;
    ZFIVEWAYBUTTON_SKINNABLE_PROP_T zFiveWayButton2;
    ZFORMCONTAINTER_SKINNABLE_PROP_T zFormContainer;
    ZFORMITEM_SKINNABLE_PROP_T zFormItem;
    ZGROUPBOX_SKINNABLE_PROP_T zGroupBox;
    ZHEADER_SKINNABLE_PROP_T zHeader1;
    ZHEADER_SKINNABLE_PROP_T zHeader2;
    ZHEADER_SKINNABLE_PROP_T zHeader3;
    ZHEADER_SKINNABLE_PROP_T zHeader4;
    ZHEADER_SKINNABLE_PROP_T zHeaderPopup;               
    ZINPUTMATRIX_SKINNABLE_PROP_T zInputMatrix;
    ZINTERACTIVEHIGHLIGHT_SKINNABLE_PROP_T zInteractiveHighlight;
    ZJUMPBOX_SKINNABLE_PROP_T zJumpBox;
    ZMATRIXITEM_SKINNABLE_PROP_T zMatrixItem;
    ZMETER_SKINNABLE_PROP_T zMeter1;
    ZMETER_SKINNABLE_PROP_T zMeter2;
    ZMETER_SKINNABLE_PROP_T zMeter3;
    ZMETERMODULE_SKINNABLE_PROP_T zMeterModule;
    ZMULTILINEEDIT_SKINNABLE_PROP_T zMultiLineEdit1;
    ZMULTILINEEDIT_SKINNABLE_PROP_T zMultiLineEdit2;                     
    ZNAVTABWIDGET_SKINNABLE_PROP_T zNavTabWidget;
    ZLISTBOX_SKINNABLE_PROP_T zListBox1;
    ZLISTBOX_SKINNABLE_PROP_T zListBox2;
    ZLISTITEM_SKINNABLE_PROP_T zListItem1;
    ZLISTITEM_SKINNABLE_PROP_T zListItem2;
    ZOPTIONSMENU_SKINNABLE_PROP_T zOptionsMenu;
    ZOPTIONSMENUITEM_SKINNABLE_PROP_T zOptionsMenuItem;
    ZPANEL_SKINNABLE_PROP_T zPanel1;
    ZPANEL_SKINNABLE_PROP_T zPanel2;
    ZPOPUP_SKINNABLE_PROP_T zPopup1;
    ZPOPUP_SKINNABLE_PROP_T zPopup2;                                    
    ZPRESSBUTTON_SKINNABLE_PROP_T zPressButton;
    ZRADIOBUTTON_SKINNABLE_PROP_T zRadioButton;
    ZSCROLLVIEW_SKINNABLE_PROP_T zScrollView;
    ZSEGMENTFIELD_SKINNABLE_PROP_T zSegmentField;
    ZSEPARATOR_SKINNABLE_PROP_T zSeparator1;
    ZSEPARATOR_SKINNABLE_PROP_T zSeparator2;
    ZSETTINGITEM_SKINNABLE_PROP_T zSettingItem;
    ZSLIDER_SKINNABLE_PROP_T zSlider;
    ZSOFTKEY_SKINNABLE_PROP_T zSoftKeyLeft;
    ZSOFTKEY_SKINNABLE_PROP_T zSoftKeyRight;
    ZSOFTKEY_SKINNABLE_PROP_T zSoftKeyMiddle;                                   
    ZSPLITPANE_SKINNABLE_PROP_T zSplitPane;
    ZDETAILVIEW_SKINNABLE_PROP_T zDetailView1;
    ZDETAILVIEW_SKINNABLE_PROP_T zDetailView2;
    ZDETAILITEM_SKINNABLE_PROP_T zDetailItem;
    ZIMAGECONTAINER_SKINNABLE_PROP_T zImageContainer;
    ZIMAGECONTAINER_SKINNABLE_PROP_T zImageContainer1;
    ZIMAGECONTAINER_SKINNABLE_PROP_T zImageContainer2;
    ZMEDIACONTROL_SKINNABLE_PROP_T zMediaControl;
    ZSCROLLBAR_SKINNABLE_PROP_T zScrollbar;
    ZSCROLLBAR_SKINNABLE_PROP_T zScrollbar_Input;
    ZSCROLLBAR_SKINNABLE_PROP_T zScrollbar_Field;
    ZSTRUCTDATAIMAGE_SKINNABLE_PROP_T zStructDataImage;
    ZFSBA_SKINNABLE_PROP_T zFsba1;
    ZFSBA_SKINNABLE_PROP_T zFsba2;
    ZBASIC_SKINNABLE_PROP_T zTotal;
    FONT_INFO_T fntDateHs;
    FONT_INFO_T fntDateH;
    FONT_INFO_T fntDateSel;
    FONT_INFO_T fntDateStd;
    FONT_INFO_T fntDateCurrStd;
    FONT_INFO_T fntDayHeaderCurrStd;
    FONT_INFO_T fntDayHeaderStd;
    FONT_INFO_T fntTitleAreaStd;
    FONT_INFO_T fntColormodNameStd;
    FONT_INFO_T fntHeaderAStd;
    FONT_INFO_T fntHeaderBStd;
    FONT_INFO_T fntSoftkeySel;
    FONT_INFO_T fntSoftkeyStd;
    FONT_INFO_T fntAiaStd;
    FONT_INFO_T fntAiaOverlayStd;
    FONT_INFO_T fntJumpboxStd;
    FONT_INFO_T fntFormitemHs;
    FONT_INFO_T fntFormitemH;
    FONT_INFO_T fntFormitemSel;
    FONT_INFO_T fntFormitemStd;
    FONT_INFO_T fntButtonHs;
    FONT_INFO_T fntButtonH;
    FONT_INFO_T fntButtonSel;
    FONT_INFO_T fntButtonStd;
    FONT_INFO_T fntFieldInthighlightHs;   
    FONT_INFO_T fntFieldHs;
    FONT_INFO_T fntFieldH;
    FONT_INFO_T fntFieldSel;
    FONT_INFO_T fntFieldStd;
    FONT_INFO_T fntGroupboxStd;
    FONT_INFO_T fntChkbxHs;
    FONT_INFO_T fntChkbxH;
    FONT_INFO_T fntChkbxPs;
    FONT_INFO_T fntChkbxSel;
    FONT_INFO_T fntChkbxStd;
    FONT_INFO_T fntGriditemHs;
    FONT_INFO_T fntGriditemH;
    FONT_INFO_T fntGriditemSel;
    FONT_INFO_T fntGriditemStd;
    FONT_INFO_T fntAlternateHs;
    FONT_INFO_T fntAlternateH;
    FONT_INFO_T fntAlternateSel;
    FONT_INFO_T fntAlternateStd;
    FONT_INFO_T fntMatrixitemContentHs;
    FONT_INFO_T fntMatrixitemNumberHs;
    FONT_INFO_T fntMatrixitemContentH;
    FONT_INFO_T fntMatrixitemNumberH;
    FONT_INFO_T fntMatrixitemContentStd;
    FONT_INFO_T fntMatrixitemNumberStd;
    FONT_INFO_T fntListitemAHs;
    FONT_INFO_T fntListitemAH;
    FONT_INFO_T fntListitemASel;
    FONT_INFO_T fntListitemAStd;
    FONT_INFO_T fntListitemBHs;
    FONT_INFO_T fntListitemBH;
    FONT_INFO_T fntListitemBSel;
    FONT_INFO_T fntListitemBStd;
    FONT_INFO_T fntListitemCHs;
    FONT_INFO_T fntListitemCH;
    FONT_INFO_T fntListitemCSel;
    FONT_INFO_T fntListitemCStd;
    FONT_INFO_T fntOptmenuItemHs;
    FONT_INFO_T fntOptmenuItemH;
    FONT_INFO_T fntOptmenuItemSel;
    FONT_INFO_T fntOptmenuItemStd;
    FONT_INFO_T fntPopupStd;
    FONT_INFO_T fntSettingAHs;
    FONT_INFO_T fntSettingAH;
    FONT_INFO_T fntSettingASel;  
    FONT_INFO_T fntSettingAStd;
    FONT_INFO_T fntSettingBHs;
    FONT_INFO_T fntSettingBH;
    FONT_INFO_T fntSettingBSel;
    FONT_INFO_T fntSettingBStd;
    FONT_INFO_T fntDividerStd;
    FONT_INFO_T fntMetersliderHs;
    FONT_INFO_T fntMetersliderH;
    FONT_INFO_T fntMetersliderStd;
    FONT_INFO_T fntMeterslidermodStd;
    FONT_INFO_T fntDatemodStd;
    FONT_INFO_T fntSeparatorStd;
    FONT_INFO_T fntCliHeaderStd;
    FONT_INFO_T fntStructureDataStd;
    FONT_INFO_T fntStructureDataH;
    FONT_INFO_T fntStructureDataSel;
    FONT_INFO_T fntDetailItemEmphasisStd;
    FONT_INFO_T fntDetailItemStandardStd;
    FONT_INFO_T fntDetailItemOverlayStd;
    FONT_INFO_T fntMediaControllerTimerStd;
    FONT_INFO_T fntMediaControllerTimerH;
    FONT_INFO_T fntMediaControllerAStd;
    FONT_INFO_T fntMediaControllerBStd;
    FSBA_INFO_T fsbaInfo;

};

class ZSkinTool;

struct SkinInfo
{
    QString name;
    QString dir;
    QPixmap previewPixmap;
};

struct WidgetSkinInfo
{
    QString backgroundPixmapID;
    QString borderPixmapID;
    void* extProps;
};

typedef QList<struct SkinInfo> SkinInfoList;
typedef QListIterator<struct SkinInfo> SkinInfoListIt;
typedef QMap<QString, ZBASIC_SKINNABLE_PROP_T *> ZBasicSkinPropsMap;

class ZConfig;
class QStringList;

class ZSkinService
{
public:
    ZSkinService(const char *app = NULL)
    {
        ref ++;
        if (app)
	    appName = new QCString(app);
        else
            appName = NULL;

	this->screenProps = NULL;
    }

    ~ZSkinService()
    {
        if(appName)
            delete appName;

        ref --;
        if (!ref)
        {   
            if (theme)
            {
                delete theme;
                theme = NULL;
            }
            if (device)
            {
                delete device;
                device = NULL;
            }
        }
	if (screenProps)
        {
	    delete screenProps;
	    screenProps = NULL;
        }
    }

    enum WidgetClsID
    {
        clsZAlternatesChooser,
        clsZAlternatesItem,
        clsZAlternatesList,
        clsZAppInfoArea,
        //modify by hongwei
        clsZCalendarModule,
        clsZCalendarModule_Day,
        clsZCalendarModule_CurDay,
        clsZCalendarModule_DayHeader,
        clsZCalendarModule_CurDayHeader,
        clsZCalendarModule_EmptyDay,
        clsZCalendarModule_Grid,
        //end by hongwei
        clsZCheckBox,
        clsZColorModule,
        clsZColorModule_Cname,
        clsZColorModule_Well,
        clsZColorPicker,
        clsZColorPicker_Well,
        clsZComboBox,
        clsZDateModule,
        clsZTimeModule = clsZDateModule,
        clsZNumModule = clsZDateModule,
        clsZDatePicker,
        clsZTimePicker = clsZDatePicker,
        clsZNumPicker = clsZDatePicker,
        clsZExhibitButton,
        clsZFiveWayButton1,
        clsZFiveWayButton2,
        clsZFormContainer,
        clsZFormItem,
        clsZGroupBox,
        clsZHeader1,
        clsZHeader2,
        clsZHeader3,
        clsZHeader4,
        clsZHeaderPopup,        // used by dialog, add by Zhang Rongkang - e2720c
        clsZIconView1,
        clsZIconView2,
        clsZIconViewItem1,
        clsZIconViewItem2,
        clsZInputMatrix,
        clsZInteractiveHighlight,
        clsZJumpBox,
        clsZJumpBox_Field,
        clsZLineEdit,
        clsZListBox1,
        clsZSettingView1 = clsZListBox1,
        clsZListBox2,
        clsZSettingView2 = clsZListBox2,
        clsZListItem1,
        clsZListItem2,
        clsZMatrixItem,
	//dy modified begin
        clsZMeter,
        clsZMeter_Indicator1,
        clsZMeter_Indicator2,
        clsZMeter_Indicator3,
	clsZMeter_Indicator4 = clsZMeter_Indicator3,  //same as indicator3, just change a pixmap for animation
	//dy modified end
        clsZMeterModule,
        clsZSliderModule = clsZMeterModule,
        clsZProgressSliderModule = clsZMeterModule,
        clsZMultiLineEdit1,
        clsZMultiLineEdit2,    //dy added
        clsZNavTabWidget,
	clsZNavTabWidget_TabArea,
        clsZOptionsMenu,
        clsZOptionsMenuItem,
        clsZPanel1,
        clsZPanel2,
        clsZPopup1,
        clsZPopup2,           //dy added
//      clsZPopup3,
        clsZPressButton,
        clsZRadioButton,
        clsZScrollPanel,
        clsZScrollView = clsZScrollPanel,
        clsZSegmentField,
        clsZSeparator1,
        clsZSeparator2,
        clsZSettingItem,
        clsZSlider,
        clsZProgressSlider = clsZSlider,
        clsZSoftKeyLeft,
        clsZSoftKeyRight,
	clsZSoftKeyMiddle,     //dy added
        clsZSplitPane,
	//dy added begin
        clsZDetailView1,
	clsZDetailView2,
	clsZDetailItem,
	clsZImageContainer,
        clsZImageContainer1,
	clsZImageContainer2,
	//clsZImageContainer4,
	clsZMediaControl,
	clsZScrollbar,
	clsZScrollbar_Input,
	clsZScrollbar_Field,
        clsZStructDataImage,
	clsZFsba1,
	clsZFsba2,
	//dy added end
        clsMax = clsZFsba2,
        clsTotal = clsMax + 1
    };

    typedef WidgetClsID SkinStyle;
    QString getAppThemeSkinFile( const QString & appName );
    QString getAppDeviceSkinFile( const QString & appName );
    const ZBASIC_SKINNABLE_PROP_T * const getBasicSkinnableProps(
        const enum WidgetClsID clsId ) const;
    void getSkinInfoList( SkinInfoList & list );
    QString getSkinName( const QString &dir = QString::null );
    QFont getSkinFont(const FONT_INFO_T & ftInfo);
    static const struct ZWidgetSkinProps * const getAllSkinnableProps();
    void updateThemeSkin(const QString themeSkinDir = QString::null);
     void updateAppCommonSkin( ZWidgetSkinProps *props );
     void updateAppScreenSkin( QString uScreenCfgName );
     ZWidgetSkinProps * getEntireSkinnableProps();
    int readNumEntryFromSkin(
        ZConfig & device,
        ZConfig & theme,
        const QString & section,
        const QString & tag,
        const int dft = -1 );
    int readNumEntryFromSkin(
        const QString & section,
        const QString & tag,
        const int dft = -1 );
    QString readStringEntryFromSkin(
        ZConfig & device,
        ZConfig & theme,
        const QString & section,
        const QString & tag,
        const QString & dft = QString::null );
    QString readStringEntryFromSkin(
        const QString & section,
        const QString & tag,
        const QString & dft = QString::null );
    QCString getAppName();
    void setAppName(const char * str);
    WidgetSkinInfo getWidgetSkinInfo(const WidgetClsID clsId);
    void updateAppThemeFile(); 
protected:

private:
    ZBASIC_SKINNABLE_PROP_T * internalGetBasicSkinnableProps(
        const enum WidgetClsID clsId,
        ZWidgetSkinProps * pProps = NULL ) const;
    ZConfig* ZSkinService::getThemeConfig();
    ZConfig* ZSkinService::getDeviceConfig();
    QCString *appName;
    static ZConfig *theme;
    static ZConfig *device;
    static QString oldThemeConfigFileName;
    static int ref;
    ZWidgetSkinProps * screenProps;
};

class QBitArray;
class ZWidget;

class ZSkinBase
{
  public:
    struct BorderPixmaps
    {
        QString id;
        QPixmap left;
        QPixmap right;
        QPixmap top;
        QPixmap bottom;
        QPixmap topLeft;
        QPixmap topRight;
        QPixmap bottomLeft;
        QPixmap bottomRight;
    };
    enum BorderType 
    {
       Empty_Border = 0, 
       Color_Border, 
       Pixmap_Border
    };
    enum BackgroundType 
    {
       Empty_Background = 0, 
       Color_Background, 
       Pixmap_Background
    };
    enum SelectionState
    {
        StStandard = 0,
        StHighlighted,
        StSelected,
        StHighlightSelected,
        StateCount = StHighlightSelected + 1
    };
    enum BorderSide
    {
       BorderLeft = 0,
       BorderTop,
       BorderRight,
       BorderBottom
    };
  public:    
     ZSkinBase(ZWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal, 
               bool isWidget = TRUE);
     virtual ~ZSkinBase();
     void updateSkin();   
     const WIDGET_PADDING_INFO_T padding() const;
     void setPadding( const WIDGET_PADDING_INFO_T & padding );
     const SelectionState selectionState() const;
     void setSelectionState( const SelectionState state );
     void setBlendingPercent(uint percent);
     uint getBlendingPercent();
     uint getBackgroundBlendingPercent();
     uint getBorderBlendingPercent();
     void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);
     void setZBorder( BorderPixmaps& pixmaps);
     int getBorderWidth(BorderSide side = BorderLeft) const; 
     void setZBackground(WIDGET_BACKGROUND_INFO_T bckgroundItems[StateCount]);
     void setZBackground(QPixmap& image);
     void unsetZBackground();
     void drawWithoutBackground(bool bDrawWithoutBg);
     bool isWithoutBackground();
     void drawBorder(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool realWidget = TRUE);
     void drawBackground(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool border = TRUE, bool realWidget = TRUE);
     void drawBackgroundAndBorder(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool realWidget = TRUE);
     void* getProps() const;
     void setBlendingTranslate(int x, int y) {dx = x; dy = y;}
     void setPixmapID(QString background, QString border);
     static void setPixmapPrefix(QString& prefix );
     void setWidgetPixmapPrefix(QString& prefix );
     BackgroundType getBackgroundType() const; 
     BorderType getBorderType() const;
     void enableCache(bool enable);
  protected:
     void stretchPixmap(QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type, bool must = false);
  private:
     QPixmap* getParentBackImage(ZWidget& widget, int x, int y, int& xBg, int& yBg, bool& freeImage);
     void drawBorder(QPainter& painter, QRect& rect, QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawBackground(QPainter& painter, QRect& rect, QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void initBorder();
     void initBorder(int width, const QColor & color);
     void initBorder(const QString & pixmapId);
     void initBackground();
     void initBackground(const QColor& color);
     void initBackground(const QString& pmID);
     const ZSkinService::WidgetClsID skinClsID() const;
     QString getPixmapNameByState() const;   
  private:
     void fillRect(QPainter& painter, QRect rect, QColor& color);
     void* getPixmapIDs(int&backgroundPixmapID, int&borderPixmapID);
     void loadBorderPixmaps(BorderPixmaps& border) const;
     void stretchAndDrawPixmap(QPainter& painter, QRect& rect, QPixmap& pixmap, PIXMAP_STRETCH_POLICY_E policy, 
                          QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawPixmap(QPainter& painter, int x, int y, int w, int h, QPixmap& pixmap, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawPixmap(QPainter& painter, QRect& rect, QPixmap& pixmap, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void fillRect(QPainter& painter, int x, int y, int w, int h, QColor& color, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void fillRect(QPainter& painter, QRect& rect, QColor& color, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     bool hasAlphaValue(QPixmap& pixmap);
     bool borderHasAlphaValue();
  public:
    struct Padding
    {
        int all;
        int left;
        int right;
        int top;
        int bottom;
    };
    enum RelativeAlignment
    {
       ImageLeft,
       ImageRight
    };
     ZSkinBase(QWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal, 
               bool isWidget = TRUE);
     void setSkinWidget(QWidget& w) {widget = &w;}
     QWidget* getSkinWidget() const {return widget;}
     void drawBorder(QPainter& painter, const QRect* rect = NULL);
     void drawBackground(QPainter& painter, const QRect* rect = NULL, bool border = TRUE);

  private:
     void drawPixmap(QPainter& painter, QRect rect, QPixmap& pixmap);
     void drawPixmap(QPainter& painter, int x, int y, QPixmap& pixmap);
     QPixmap* ZSkinBase::getWallPaper(QPainter& painter) const;
  protected:
    uint    own_padding : 1;
    uint    own_background : 1;
    uint    own_private_bg : 1;
    uint    own_border : 1;
    uint    own_private_border : 1;
    uint    own_percent : 1;
    uint    mIsWidget : 1;
    uint    mCachePixmap :1;
    ZSkinService::WidgetClsID mClsID;
    short mBgPercent;
    short mSelectionState;
    static QString mPrefix;
    QString mWidgetPrefix;
    QString backgroundPixmapID;
    QString borderPixmapID;
    WIDGET_BACKGROUND_INFO_T * ownBackgroundItems;
    WIDGET_BORDER_INFO_T * ownBorderItems;
    QPixmap* mBgPixmap;
    BorderPixmaps* mBorderPixmaps;
    WIDGET_PADDING_INFO_T* mPadding;
    short dx;
    short dy;
    bool mIsWithoutBackground;
    QWidget* widget;
};


#endif
