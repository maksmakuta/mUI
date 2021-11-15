#include <mUI/mUI.h>

class MainActivity : public Activity{
private:
    str* data = null;
public:
    fun onCreate() override{
        const i32 s = 32;
        init(s);
        auto ss = new ScrollLayout();
        auto ll = new LinearLayout(Vertical,ss);
        for(i32 i = 0;i < s;i++)
            new TextView(data[i],ll);
        setContentView(ss);
    }

    fun init(i32 s){
        data = new str[s];
        for(i32 i = 0;i < s;i++){
            data[i] = "Item " + (str)(i <= 9 ? "0" : "") + std::to_string(i);
        }
    }
};

int main(/*int argc, char *argv[]*/) {
    App app(640,480,"App");
    app.setActivity(new MainActivity(),Theme::Light());
    return app.exec();
}
