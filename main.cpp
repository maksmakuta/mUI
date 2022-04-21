#include <mUI.h>

class TestView : public View{
  public:
    TestView() : View(){

    }
    fun onEvent(Event*){}
    fun onDraw(Canvas* c){
        c->begin();
        c->circle(100,100,20);
        c->fillColor("#f00");
        c->fill();
    }
};

class Main : public Activity{
  public:
    fun onCreate() override{
        this->setContextView(new TestView());
    }
};

int main(){
    App a(640,480,"App",new Main());
    return a.run();
}
