#include "src/app/Application.h"

class RectView : public View{
private:
    f32 w,h;
public:
    RectView(f32 _w,f32 _h) : View(){
        this->w = _w;
        this->h = _h;
    }

    fun onDraw(Canvas *c) override{
        c->begin();
        c->rect(0,0,w,h);
        c->fill("#f0f");
        c->end(true);

        c->begin();
        c->lineWidth(2.f);
        c->circle(w/2,h/2,w/3);
        c->fill("#f00");
        c->end(false);

    }
};

class MainActivity : public Activity{
public:
    MainActivity() : Activity(){
        this->setLayout(new RectView(100,100));
    }
};

int main(){
    Application app(600,400,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}