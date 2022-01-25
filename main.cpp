#include <mUI.h>

class Main : public Activity{
  public:
    fun onCreate() override{

    }
};

int main(){
    App a(640,480,"App",new Main());
    return a.run();
}
