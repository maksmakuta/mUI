#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/widget/IconButton.h"
#include "src/widget/ToolBar.h"
#include "src/widget/TextView.h"
#include "src/widget/Slider.h"

class MainActivity : public Activity, public OnSliderChangeListener{
private:
    TextView* i = new TextView("Some Large Text",null);
public:
    fun onCreate() override{
        View* ll = new LinearLayout(Vertical,null);
        new ToolBar("app",28,ll);
        i->setFontSize(32.f);
        i->margin(10);
        ll->push(i);
        auto s = new Slider(-10,10,ll);
        s->setOnSliderChangeListener(this);
        setContentView(ll);
    }

    fun onSliderChange(f32 var) override{
        i->setText("Data -> " + std::to_string((i32)var));
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
