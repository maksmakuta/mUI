#include "mUI/mUI.h"

class MainActivity : public Activity{
public:
    fun onCreate() override{
        auto ll = new LinearLayout();
        auto b = new Button("Button",ll);
        b->style(Button::Outline);
        b->margin(10);

        auto b1 = new Button("Button 1",ll);
        b1->margin(10);

        auto b2 = new Button("Button 2",ll);
        b2->style(Button::Text);
        b2->margin(10);

        auto b3 = new Button(cpToUTF8(ic_signal_wifi_4_bar),ll);
        b3->style(Button::Icon);
        b3->margin(10);
        setContentView(ll);
    }
};

int main(int argc, char *argv[]) {
    App app(640,480,"App");
    app.setActivity(new MainActivity());
    return app.exec();
}
