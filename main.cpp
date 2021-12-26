#include "src/mUI.h"

class Main : public Activity{
  public:

    fun onCreate() override {

    }
};

int main(){ // int argc, char *argv[]
    return App(640,480,"App",new Main()).run();
}
