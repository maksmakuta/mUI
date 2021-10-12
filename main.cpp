<<<<<<< HEAD
<<<<<<< HEAD
int main() {
=======
#include "src/window/Window.h"
#include "src/graphics/Color.h"

int main() {
    Window w(800,600,"Test");
    w.setBG(new Color("#954624"));
    w.draw();
>>>>>>> dev
=======
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

        c->color("#ffaa66");
        c->drawRect(x,y,w,h);
    }
};

class MainActivity : public Activity{
public:
    MainActivity() : Activity(){
        this->setLayout(new RectView(0,0,150,60));
    }
};

int main(){
    Application app(640,480,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
>>>>>>> dev
    return 0;
}
