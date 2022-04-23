#include <app/Application.h>

class TestView : public View{
  public:
    TestView() : View(){}

    fun onDraw(Canvas* c) override{

    }

    ~TestView(){

    }
};

class Main : public Activity{
private:
    //TextView* tv = null;
public:
    Main(){
        //this->tv = new TextView("Hello, World!");
    }
    fun onCreate() override{
        //this->setContentView(this->tv);
    }
};

int main(){
    App app(640,480,"App",new Main());
    return app.exec();
}
