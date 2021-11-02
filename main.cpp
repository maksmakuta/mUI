#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/widget/IconButton.h"
#include "src/widget/ToolBar.h"
#include "src/widget/TextView.h"
#include "src/widget/Slider.h"
#include "src/widget/Switch.h"

class MainActivity : public Activity{
private:
    TextView* i = new TextView("Some Large Text",null);
public:
    fun onCreate() override{
        i->setFontSize(32.f);
        i->margin(10);

        View* ll = new LinearLayout(Vertical,null);
        new ToolBar("app",28,ll);
        ll->push(i);
        new Switch("Online",ll);
        setContentView(ll);
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
