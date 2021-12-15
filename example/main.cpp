#include <mUI/mUI.h>

class MainActivity : public Activity{
public:
    fun onCreate() override {
        auto lv = new LinearLayout(Horizontal);
        auto l1 = new LinearLayout(Vertical,lv);
        auto t0 = new TextView("Button style",l1);
        t0->margin(20);
        l1->push(btn("Outline"               ,Button::Outline   ,"Outline -> "));
        l1->push(btn("Filled"                ,Button::Filled    ,"Filled  -> "));
        l1->push(btn("Text"                  ,Button::Text      ,"Text    -> "));

        auto l2 = new LinearLayout(Vertical,lv);
        auto t1 = new TextView("Button shape",l2);
        t1->margin(20);
        l2->push(icbtn(ic_account_box           ,Button::SRect     ,"Rect   -> "));
        l2->push(icbtn(ic_wifi_protected_setup  ,Button::SCircle   ,"Circle -> "));
        l2->push(icbtn(ic_now_wallpaper         ,Button::SRoundRect,"RRect  -> "));

        setContentView(lv);
    }

    View* btn(const str& text,Button::Style style,const str& t){
        auto ll = new LinearLayout(Horizontal);
        auto tv  = new TextView(t,ll);
        tv->fixed(150,30);
        tv->margin(15);
        tv->measure(Fixed,Fixed);
        auto btn = new Button(text,ll);
        btn->style(style);
        btn->margin(10);
        return ll;
    }

    View* icbtn(i32 icon,Button::Shape s,const str& t){
        auto ll = new LinearLayout(Horizontal);
        auto tv  = new TextView(t,ll);
        tv->margin(15);
        tv->fixed(150,30);
        tv->measure(Fixed,Fixed);
        auto btn = new Button(icon,ll);
        btn->shape(s);
        btn->margin(10);
        return ll;
    }
};

i32 main(/*int argc, char *argv[]*/) {
    App app(640,480,"App",true);
    app.setActivity(new MainActivity(),Theme::Dark());
    return app.exec();
}
