#include <mUI/mUI.h>

class MainActivity : public Activity{
public:
    fun onCreate() override{
        auto ll = new LinearLayout(Vertical);
        new TextView("Button style",ll);
        ll->push(btn(cpToUTF8(ic_account_box),Button::Icon      ,"Icon    -> "));
        ll->push(btn("Outline"               ,Button::Outline   ,"Outline -> "));
        ll->push(btn("Filled"                ,Button::Filled    ,"Filled  -> "));
        ll->push(btn("Text"                  ,Button::Text      ,"Text    -> "));
        setContentView(ll);
    }

    View* btn(const str& text,Button::Style style,const str& t){
        auto ll = new LinearLayout(Horizontal);
        new TextView(t,ll);
        auto btn = new Button(text,ll);
        btn->style(style);
        btn->margin(10);
        return ll;
    }
};

i32 main(/*int argc, char *argv[]*/) {
    App app(640,480,"App");
    app.setActivity(new MainActivity(),Theme::Light());
    return app.exec();
}
