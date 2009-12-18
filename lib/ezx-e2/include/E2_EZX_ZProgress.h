
// _ZN21ZProgressSliderModuleC4EiiiiN15ZProgressSlider9IndicatorEP7QWidgetPKcN12ZSkinService11WidgetClsIDE
// _ZN21ZProgressSliderModuleC4EN15ZProgressSlider9IndicatorEP7QWidgetPKcN12ZSkinService11WidgetClsIDE
// _ZN21ZProgressSliderModuleC4EP7QWidgetPKcN12ZSkinService11WidgetClsIDE
// _ZN21ZProgressSliderModuleD4Ev


class ZProgressSlider
{
public:
	int ZProgressSlider[in-charge](QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSlider[in-charge](ZProgressSlider::Indicator, Qt::Orientation, QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSlider[in-charge](int, int, int, int, ZProgressSlider::Indicator, Qt::Orientation, QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSlider[not-in-charge](QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSlider[not-in-charge](ZProgressSlider::Indicator, Qt::Orientation, QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSlider[not-in-charge](int, int, int, int, ZProgressSlider::Indicator, Qt::Orientation, QWidget*, char const*, ZSkinService::WidgetClsID)
	int addStep()
	int autoResize() const
	int className() const
	int focusInEvent(QFocusEvent*)
	int focusOutEvent(QFocusEvent*)
	int initMetaObject()
	int isZDisabled()
	int isZEnabled()
	int keyPressEvent(QKeyEvent*)
	int lineStep() const
	int maxValue() const
	int minValue() const
	int minimumSizeHint() const
	int pageStep() const
	int paintEvent(QPaintEvent*)
	int paintSlider(QPainter*, QRect const&)
	int progresssliderSizeChange()
	int rangeChange()
	int reset()
	int resizeEvent(QResizeEvent*)
	int setAutoResize(bool)
	int setEnabled(bool)
	int setLineStep(int)
	int setMaxValue(int)
	int setMinValue(int)
	int setOrientation(Qt::Orientation)
	int setPageStep(int)
	int setPalette(QPalette const&)
	int setPixmap(QPixmap, QPixmap)
	int setSelectionState(ZSkinBase::SelectionState)
	int setThickness(int)
	int setValue(int)
	int showThumb(bool)
	int signalSelect()
	int sizeHint() const
	int staticMetaObject()
	int subtractStep()
	int thickness() const
	int tr(char const*)
	int tr(char const*, char const*)
	int updateSkin(bool)
	int updateState()
	int value() const
	int valueChange()
	int valueChanged(int)
	int ~ZProgressSlider [in-charge deleting]()
	int ~ZProgressSlider [in-charge]()
	int ~ZProgressSlider [not-in-charge]()
}

class ZProgressSliderModule
{
public:
	int ZProgressSliderModule[in-charge](QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSliderModule[in-charge](ZProgressSlider::Indicator, QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSliderModule[in-charge](int, int, int, int, ZProgressSlider::Indicator, QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSliderModule[not-in-charge](QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSliderModule[not-in-charge](ZProgressSlider::Indicator, QWidget*, char const*, ZSkinService::WidgetClsID)
	int ZProgressSliderModule[not-in-charge](int, int, int, int, ZProgressSlider::Indicator, QWidget*, char const*, ZSkinService::WidgetClsID)
	int autoResize() const
	int className() const
	int focusInEvent(QFocusEvent*)
	int getSlider() const
	int initMetaObject()
	int keyPressEvent(QKeyEvent*)
	int minimumSizeHint() const
	int paintEvent(QPaintEvent*)
	int resizeAll()
	int resizeEvent(QResizeEvent*)
	int setAlignment(ZProgressSliderModule::Alignment)
	int setAutoResize(bool)
	int setOrientation(Qt::Orientation)
	int setPalette(QPalette const&)
	int setSpacingV1(short)
	int setThickness(int)
	int sizeHint() const
	int staticMetaObject()
	int timerDone()
	int tr(char const*)
	int tr(char const*, char const*)
	int updateLabel()
	int updateLabel(QString)
	int updateSkin(bool)
	int valueChange(int)
	int valueChanged(int)
	int ~ZProgressSliderModule [in-charge deleting]()
	int ~ZProgressSliderModule [in-charge]()
	int ~ZProgressSliderModule [not-in-charge]()
}