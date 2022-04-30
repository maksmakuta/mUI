#include <app/Application.h>
/*
class TestView : public View{
  public:
    TestView() : View(){}

    fun onDraw(Canvas* c) override{
        c->begin();
        c->rect(0,0,100,100,20,40,20,40);
        c->fillColor(nvgRGB(250,200,150));
        c->fill();
        c->close();
    }

    ~TestView(){

    }
};
*/
class Main : public Activity{
private:
    //TextView* tv = null;
public:
    Main(){
        //this->tv = new TextView("Hello, World!");
    }
    fun onCreate() override{
        // auto layout = new CenterLayout();
        // layout->addView(tv);
        //this->setContentView(layout);
    }
};

int main(){
    App app(640,480,"App",new Main());
    return app.exec();
}
