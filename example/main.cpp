#include <mUI/widget/layout/GridLayout.h>
#include "mUI/mUI.h"

class MainActivity : public Activity{
public:
    fun onCreate() override{
        auto ll = new GridLayout(2,2);
        auto b = new Button("Button",ll);
        b->style(Button::Outline);
        b->margin(10);

        auto b1 = new Slider(-5,15,ll);
        b1->measure(Parent,Content);

        auto b2 = new Switch("Switch",ll);


        auto b3 = new Button(ic_signal_wifi_4_bar,ll);
        b3->style(Button::Icon);
        b3->margin(10);

        auto t = new TextView("Text",ll);
        t->margin(10);
        auto t2 = new TextView("Text2",ll);
        t2->margin(10);

        setContentView(ll);
    }
};

int main(int argc, char *argv[]) {
    App app(640,480,"App");
    app.setActivity(new MainActivity(),Theme::Light());
    return app.exec();
}
