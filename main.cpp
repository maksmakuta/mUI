#include "src/app/Application.h"

class RectView : public View{
private:
    f32 x,y,w,h;
public:
    RectView(f32 _x,f32 _y,f32 _w,f32 _h) : View(_x,_y,_w,_h){
        this->x = _x;
        this->y = _y;
        this->w = _w;
        this->h = _h;
    }

    fun onDraw(Canvas *c) override{
        c->color("#ffaa66");
        c->drawRect(x,y,w,h);
    }

    fun onHover(Canvas *c) override{
        this->onDraw(c);
        c->color("#f00");
        c->drawText(x + w/2,y +h/2,"HOVER","font",10);
    }
};

class MainActivity : public Activity,public OnClickListener{
public:

    int s = 0;

    MainActivity() : Activity(),OnClickListener(){
        auto v = new RectView(0,0,150,60);
        v->setOnClickListener(this);
        this->setLayout(v);
    }

    fun onClick() override{
        printf("Clicked : %i\n",s);
        s++;
    }
};

int main(){
    Application app(640,480,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}