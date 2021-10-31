#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/widget/IconButton.h"
#include "src/widget/ToolBar.h"
#include "src/widget/TextView.h"

class MainActivity : pub Activity{
public:
    fun onCreate() override{
        View* ll = new LinearLayout(Vertical,null);
        new ToolBar("app",28,ll);
        ll->push(it());
        setContentView(ll);
    }

    View* it(){
        auto i = new TextView("Some Large Text",null);
        i->setFontSize(32.f);
        i->margin(10);
        return i;
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
