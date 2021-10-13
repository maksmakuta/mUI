#include "src/app/Application.h"

class RectView : public View{
private:
    f32 x,y,w,h;
public:
    RectView(f32 _x,f32 _y,f32 _w,f32 _h) : View(){
        this->x = _x;
        this->y = _y;
        this->w = _w;
        this->h = _h;
    }

    fun onDraw(Canvas *c) override{
<<<<<<< Updated upstream
<<<<<<< HEAD
<<<<<<< HEAD

        c->color("#ffaa66");
        c->drawRect(x,y,w,h);
=======
=======
>>>>>>> Stashed changes
        c->color("#ffaa66");
        c->drawRect(x,y,w,h);
    }

    fun onHover(Canvas *c) override{
        this->onDraw(c);
        c->color("#f00");
        c->drawText(x + w/2,y +h/2,"HOVER","font",10);
    }
=======

        c->color("#ffaa66");
        c->drawRect(x,y,w,h);
    }
>>>>>>> parent of 9481cdf... [1.3.3] ad mouse callbacks
};

class MainActivity : public Activity{
public:
<<<<<<< Updated upstream
<<<<<<< HEAD
<<<<<<< HEAD
    MainActivity() : Activity(){
        this->setLayout(new RectView(0,0,150,60));
=======
=======
>>>>>>> Stashed changes

    int s = 0;

    MainActivity() : Activity(),OnClickListener(){
        auto v = new RectView(0,0,150,60);
        v->setOnClickListener(this);
        this->setLayout(v);
    }

    fun onClick() override{
        printf("Clicked : %i\n",s);
        s++;
<<<<<<< Updated upstream
>>>>>>> stable
=======
    MainActivity() : Activity(){
        this->setLayout(new RectView(0,0,150,60));
>>>>>>> parent of 9481cdf... [1.3.3] ad mouse callbacks
=======
>>>>>>> Stashed changes
    }
};

int main(){
    Application app(640,480,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}