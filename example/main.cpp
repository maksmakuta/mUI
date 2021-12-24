#include "../src/mUI.h"

class MainActivity : public Activity{
public:
    fun onCreate() override{

    }
};

// int argc, char *argv[]
int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
