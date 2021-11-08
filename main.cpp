#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/graphics/utils/MaterialIcons.h"
#include "src/widget/layout/LinearLayout.h"

class CircleButton : public View{
private:
    str t;
public:
    CircleButton(const str& _t,View* parent = null) : View(parent){
        this->t = _t;
        this->margin(10);
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();

        c->begin();
        c->circle(r.x + r.w/2.f,r.y + r.h/2.f,r.w/2.f);
        c->fill(this->hover() ? "#d28" :"#f4a");
        c->end(true);

        c->fontFace( "roboto");
        c->fontAlign(vMiddle | hCenter);
        c->fontFill("#fff");
        c->fontSize(r.h * 0.75f);
        c->text(r.x + r.w/2.f,r.y + r.h/2.f, t.c_str());
    }

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod) override{
        if(circleIn((f32)x,(f32)y))
            this->hover(true);
        else
            this->hover(false);
    }

    fun onMeasure() override{
        this->size(70,70);
    }

    bool circleIn(f32 mx,f32 my){
        Rect r = rect();
        f32 cx = r.x + r.w/2.f;
        f32 cy = r.y + r.h/2.f;
        return (mx - cx) * (mx - cx) + (my - cy) * (my - cy) < r.h/2.f * r.h/2.f;
    }
};

class CalcView : public View{
private:
    str expr;
public:
    CalcView(View* parent) : View(parent){
        this->expr = "0";
    }

    fun push(const str& t){
        expr.append(t);
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();

        c->begin();
        c->rect(r.x ,r.y ,r.w,r.h,0,0,15,15);
        c->fill("#f5f");
        c->end(true);

    }

    fun onMeasure() override{
        this->size(70*4,70);
    }
};

class GridLayout : public View{
private:
    i32 w,h;

public:
    GridLayout(i32 _w,i32 _h,View* parent = null) : View(parent,true){
        this->w = _w;
        this->h = _h;
    }

    fun onDraw(Canvas *c) override {
        Rect r = rect();

        vec2 view = vec2(r.w / w,r.h / h);

        for (i32 x = 0; x < w; x++){
            for (i32 y = 0; y < h; y++) {
                View* v = this->at(x+h*y);
                v->pos((f32)r.x + x * view.x,r.y + (f32)y * view.y);
                //v->size(view.x,view.y);
                v->onDraw(c);
            }
        }
    }

    fun onMeasure() override{
        f32 s;
        for(auto v : data()){
            v->onMeasure();
            s = v->rect().w;
        }
        this->size(s*(f32)w,s*(f32)h);
    }
};

class MainActivity : public Activity{
private:
    str l[16] = {
         "7","8","9",cpToUTF8(0x00f7),
         "4","5","6",cpToUTF8(0x00D7),
         "1","2","3",cpToUTF8(0x2212),
         "C","0","=",cpToUTF8(0x002b)
    };

public:
    fun onCreate() override{
        auto ll = new LinearLayout(Vertical,null);
        new CalcView(ll);
        auto g = new GridLayout(4,4,ll);
        for(const auto & i : l){
            g->push(new CircleButton(i));
        }
        setContentView(ll);
    }
};

int main(){
    App a(70*4,70*5,"Calc");
    a.setActivity(new MainActivity());
    return a.exec();
}
