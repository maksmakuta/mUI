#include "src/core/App.h"
#include "src/layout/LinearLayout.h"
#include <functional>
#include <sstream>

class RectView : public View{
private:
    std::function<fun()> callback;
    i32 p = 0;
    str text;
public:
    explicit RectView(f32 s) : View(false){
        this->size(s,s);
        this->margin(10);
    }

    fun onDraw(Canvas *c) override{
        c->begin();
        vec4 r = rect();
        c->rect(r.x,r.y,r.z,r.w);
        c->fill("#fff");
        c->end(true);


        c->fontFill("#000");
        c->fontFace("roboto");
        c->fontSize(20.f);
        c->fontAlign(NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
        c->text(r.x,r.y,this->text.c_str());
    }

    fun onMouse(f32 x, f32 y,i32 button, i32 action, i32 mod) override {
        if (rect().in(x, y)) {
            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
                (fun) callback();
        }
    }

    fun onKeyboard(u32 charcode) override{
        std::ostringstream c;
        c << (char)charcode;
        this->text.insert(p,c.str());
        p++;
    }

    fun onClick(const std::function<fun()>& f){
        this->callback = f;
    }
};

int x = 0;

fun onClick(){
    printf("Rect clicked : %i times\n",x);
    x++;
}

View* ll(){
    auto r = new RectView(50);
    r->onClick(onClick);

    auto m = new LinearLayout();
    m->add(r);
    return m;
}

int main(){
    App app(640,480,"Window");
    app.setTheme(Theme::Dark());
    app.layout(ll());
    return app.run();
}