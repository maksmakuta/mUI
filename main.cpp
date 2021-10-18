#include "src/app/Application.h"
#include "src/view/core/Layout.h"
#include "src/view/Drawable.h"

class RectView : public View{
private:
    const char* c;
public:
    RectView(f32 _w,f32 _h,const char* _c) : View(){
        this->w(_w);
        this->h(_h);
        this->c = _c;
    }

    fun onDraw(Canvas *canv) override{
        canv->begin();
        canv->rect(x(),y(),w(),h());
        canv->fill(this->c);
        canv->end(true);
    }

    fun onResize(f32 _w, f32 _h) override{
        // null
    }
};

class ToolBar : public View{
private:
    str _t;
    f32 w;
public:

    ToolBar(const str& title) : View(){
        this->_t = title;
    }

    fun onDraw(Canvas *c) override{
        c->begin();
        c->rect(0,0,w,64);
        c->fill("#fa91cd");
        c->end(true);

        c->fontAlign(NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE); //TODO align fonst cast to own names
        c->fontFace("noto");
        c->fontSize(32);
        c->fill("#000");
        c->text(w/2,32,_t.c_str());
    }

    fun onResize(f32 _w, f32 _h) override{
        this->w = _w;
    }

};

class LinearLayout : public Layout{
private:
    bool _v;
public:
    LinearLayout(bool v) : Layout(){
        this->_v = v;
    }

    fun onDraw(Canvas *c) override{
        if(_v){
            f32 y = 0.f;
            for(auto& v : childs){
                v->y(y);
                v->onDraw(c);
                y += v->h();
            }
        }else{
            f32 x = 0.f;
            for(auto& v : childs){
                v->x(x);
                v->onDraw(c);
                x += v->w();
            }
        }
    }

    fun onResize(f32 w,f32 h) override{
        this->w(w);
        this->h(h);
    }
};

class MainActivity : public Activity{
public:
    MainActivity() : Activity(){
        Layout* ll = new LinearLayout(false);
        ll->add(new RectView(100,200,"#fff"));
        ll->add(new RectView(100,50,"#f00"));
        this->setLayout(ll->toView());
    }
};

int main(){
    Application app(600,400,"App");
    app.setMainActivity(new MainActivity());
    app.exec();
    return 0;
}