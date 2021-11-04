#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/widget/RadioButton.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/widget/ToolBar.h"
#include "src/widget/TextView.h"

class MainActivity : public Activity,public OnCheckedChangeListener{
private:
    TextView* t = new TextView("",null);
public:
    fun onCreate() override{
        t->margin(10);
        View* ll = new LinearLayout(Vertical,null);
        new ToolBar("app",28,ll);
        ll->push(rb());
        ll->push(t);
        setContentView(ll);
    }

    fun onCheckedChange(View *v, View *cView) override{
        t->setText(((RadioButton*)cView)->getText());
    }

    fun onCheckedChange(View *v, bool checked) override{
        if(checked)
            t->setText("Item \"Three\" is checked");
    }

    View* rb(){
        auto rB = new RadioGroup(null);
        rB->setOnCheckedChangeListener(this);
        rB->add(new RadioButton("One",null));
        rB->add(new RadioButton("Two",null));
        auto three = new RadioButton("Three",null);
        three->setOnCheckedChangeListener(this);
        rB->add(three);
        rB->add(new RadioButton("Four",null));
        rB->add(new RadioButton("Five",null));
        return rB;
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
