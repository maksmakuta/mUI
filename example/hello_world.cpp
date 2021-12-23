#include <mUI/mUI.h>

class ActivityMain : public Activity{
public:
    void onCreate() override{
        auto l = new LinearLayout(Vertical);
        auto t = new TextView("Hello,World!",l);
        t->margin(20);
        setContentView(l);
    }
};

int main(){
    App application(640,480,"HelloWorldApp");
    application.setActivity(new ActivityMain(),Theme::Light());
    return application.exec();
}
