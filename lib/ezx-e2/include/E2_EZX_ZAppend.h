//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// 这个类保存在导出文件中没有但是编译时必须用到的类 , 这些类全空，不能使用！！

#ifndef _E2_EZX_ZAPPEND_H
#define _E2_EZX_ZAPPEND_H

enum PIXMAP_STRETCH_POLICY_E
{
	NONE = 0
};

class ZSkinService
{
public:
	enum WidgetClsID
	{
        clsZAlternatesChooser,
        clsZAlternatesItem,
        clsZAlternatesList,
        clsZAppInfoArea,
        clsZCalendarModule,
        clsZCalendarModule_Day,
        clsZCalendarModule_CurDay,
        clsZCalendarModule_DayHeader,
        clsZCalendarModule_CurDayHeader,
        clsZCalendarModule_EmptyDay,
        clsZCalendarModule_Grid,
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
        clsZHeaderPopup,       
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
        clsZMeter,
        clsZMeter_Indicator1,
        clsZMeter_Indicator2,
        clsZMeter_Indicator3,
	clsZMeter_Indicator4 = clsZMeter_Indicator3,  
        clsZMeterModule,
        clsZSliderModule = clsZMeterModule,
        clsZProgressSliderModule = clsZMeterModule,
        clsZMultiLineEdit1,
        clsZMultiLineEdit2,   
        clsZNavTabWidget,
	clsZNavTabWidget_TabArea,
        clsZOptionsMenu,
        clsZOptionsMenuItem,
        clsZPanel1,
        clsZPanel2,
        clsZPopup1,
        clsZPopup2,       
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
	clsZSoftKeyMiddle,     
        clsZSplitPane,
        clsZDetailView1,
	clsZDetailView2,
	clsZDetailItem,
	clsZImageContainer,
        clsZImageContainer1,
	clsZImageContainer2,
	clsZMediaControl,
	clsZScrollbar,
	clsZScrollbar_Input,
	clsZScrollbar_Field,
        clsZStructDataImage,
	clsZFsba1,
	clsZFsba2,
        clsMax = clsZFsba2,
        clsTotal = clsMax + 1,
        NONE = 0
    };
};	

class ZSkinBase
{
public:
    enum SelectionState
    {
        StStandard = 0,
        StHighlighted,
        StSelected,
        StHighlightSelected,
        StateCount = StHighlightSelected + 1
    };
    enum RelativeAlignment
    {
       ImageLeft,
       ImageRight
    };	
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
};

#endif
