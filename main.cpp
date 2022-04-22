#include <app/Application.h>

class Main : public Activity{
public:
    Main(){

    }
    fun onCreate() override{

    }
};

int main(){
    App app(640,480,"App",new Main());
    return 0;
}
