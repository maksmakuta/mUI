#include "src/app/Application.h"

class MainActivity : public Activity{
public:
    MainActivity() : Activity(){
        this->setLayout(null);
    }


};

int main(){
    Application app(600,400,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}