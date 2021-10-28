#include "src/graphics/Window.h"
#include "src/widget/TextView.h"
#include "src/widget/Button.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/app/App.h"

class MainActivity : pub Activity, pub OnClickListener{
private:
    Button* btn = new Button("Click me!");
    Button* btn2 = new Button("Reverse!!");
    TextView* t = new TextView("Hello, World!");
public:
    fun onCreate() override{
        btn->id(5);
        btn->setOnClickListener(this);

        btn2->id(8);
        btn2->setOnClickListener(this);
        
        setContentView(ll());
    }

    fun onClick(View *v) override{
        if(v->id() == btn->id()){
            t->setText("Text was changed!");
        }
        if(v->id() == btn2->id()){
            t->setText("Hello, User!!!");
        }
    }

    View* ll(){
        View* ll = new LinearLayout(Horizontal);
        ll->add(t);
        ll->add(btn);
        ll->add(btn2);
        ll->add(new Button("Hello, World!2"));
        return ll;
    }
};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}