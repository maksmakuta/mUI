#include "src/app/Application.h"

class MaterialView : public View{
public :

    MaterialView() : View(){

    }

    fun onDraw(Canvas *c) override{
        c->begin();
        c->rect(getViewRect(),150);
        c->fill("#f0F");
        c->end(true);
    }
/*
    fun onResize(f32 _w, f32 _h) override{
        Rect r(0,0,_w,_h);
        this->setViewRect(r);
    }
*/
};

class MainActivity : public Activity{
public:
    MainActivity() : Activity(){
        this->setLayout(new MaterialView());
    }
};

int main(){
    Application app(640,480,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}