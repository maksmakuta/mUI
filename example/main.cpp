#include <mUI/mUI.h>

class MainActivity : public Activity{
public:
    fun onCreate() override{
        auto ll = new LinearLayout(Vertical);
        auto btn = new Button(ic_add,ll);
        btn->style(Button::Icon);
        btn->margin(10);
        auto btn1 = new Button("OutLine",ll);
        btn1->style(Button::Outline);
        btn1->margin(10);
        auto btn2 = new Button("Filled",ll);
        btn2->style(Button::Filled);
        btn2->margin(10);
        auto btn3 = new Button("Text",ll);
        btn3->style(Button::Text);
        btn3->margin(10);
        setContentView(ll);
    }
};

int main(/*int argc, char *argv[]*/) {
    App app(640,480,"App");
    app.setActivity(new MainActivity(),Theme::Light());
    return app.exec();
}
