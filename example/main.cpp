#include <mUI/mUI.h>

class MainActivity : public Activity{
public:
    fun onCreate() override {
        auto l = new LinearLayout();
        new Button("Button",l);
        setContentView(l);
    }
};

int main() {
    App app(640,640,"App",true);
    app.setActivity(new MainActivity());
    return app.exec();
}
