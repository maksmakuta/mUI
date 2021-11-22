#include <mUI/mUI.h>

class MainActivity : public Activity{
public:
    fun onCreate() override{
        const i32 s = 60;
        auto ss = new ScrollLayout();
        auto ll = new LinearLayout(Vertical,ss);
        auto gg = new GridLayout(6,ll);
        for(i32 i = 0;i < s;i++)
            new TextView("Item " + (str)(i < 9 ? "0" : "") + std::to_string(i+1),gg);
        auto cc = new RadioGroup(ll);
        for(i32 i = 0;i < 16;i++)
            new RadioButton("Button "+ std::to_string(i+1),cc);

        setContentView(ss);
    }


};

int main(/*int argc, char *argv[]*/) {
    App app(640,480,"App");
    app.setActivity(new MainActivity(),Theme::Light());
    return app.exec();
}
