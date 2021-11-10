#include "mUI/mUI.h"

class MainActivity : public Activity{
public:
    fun onCreate() override{
        setContentView(null);
    }
};

int main(int argc, char *argv[]) {
    App app(640,480,"App");
    app.setActivity(new MainActivity());
    return app.exec();
}
