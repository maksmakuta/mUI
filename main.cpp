#include "src/core/App.h"
#include "src/layout/LinearLayout.h"
#include <functional>

class RectView : public View{
private:
    std::function<fun()> callback;
    char* bg;
public:
    explicit RectView(f32 s) : View(false){
        this->size(s,s);
        this->margin(10);
        bg = "#fff";
    }

    fun onDraw(Canvas *c) override{
        c->begin();
        vec4 r = rect();
        c->rect(r.x,r.y,r.z,r.w);
        c->fill(bg);
        c->end(true);
    }

    fun onMouse(f32 x, f32 y,i32 button, i32 action, i32 mod) override {
        if (rect().in(x, y)) {
            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
                (fun) callback();
        }
    }


    fun onClick(const std::function<fun()>& f){
        this->callback = f;
    }
};

View* ll(){
    auto r = new RectView(50);
    r->onClick([](){
        printf("Rect clicked\n");
    });

    auto m = new LinearLayout();
    m->add(r);
    return m;
}

int main(){
    App app(640,480,"Window");
    app.layout(ll());
    return app.run();
}