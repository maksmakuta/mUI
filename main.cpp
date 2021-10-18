#include "src/app/Application.h"
#include "src/view/LinearLayout.h"
#include "src/view/ToolBar.h"
#include "src/view/TextView.h"


class MainActivity : public Activity{
public:
    MainActivity() : Activity(){
        auto* t = new TextView("Hello World");
        t->setFontSize(32.f);
        t->marginTop(150.0f);
        Layout* ll = new LinearLayout(true);
        ll->add(new ToolBar("App"));
        ll->add(t);
        this->setLayout(ll->toView());
    }
};

int main(){
    Application app(600,400,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}