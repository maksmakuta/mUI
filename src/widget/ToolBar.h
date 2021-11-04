#ifndef MUI_TOOLBAR_H
#define MUI_TOOLBAR_H

#include "../view/View.h"

class ToolBar : public View{
private:
    str title;
    f32 sf;
    bool m = false,mm = false;
public:
    ToolBar(const str& _t,f32 _s,View* p) : View(p){
        this->title = _t;
        this->sf = _s;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();

        c->begin();
        c->rect(r.x,r.y,r.w,r.h);
        c->fill("#333");
        c->end(true);

        c->fontFace("roboto");
        c->fontSize(sf);
        c->fontFill("#f84");
        c->fontAlign(hCenter |vMiddle);
        c->text(r.x + r.w/2.f,r.y + r.h/2.f,title.c_str());

        if(m){
            c->begin();
            c->circle(r.x + r.h/2.f,r.y + r.h/2.f,r.h/3.f);
            c->fill("#555");
            c->end(true);
        }

        if(mm){
            c->begin();
            c->circle(r.x + r.w -  r.h/2.f,r.y + r.h/2.f,r.h/3.f);
            c->fill("#555");
            c->end(true);
        }

        c->fontFace("icons");
        c->fontSize(sf);
        c->fontFill("#f84");
        c->fontAlign(hCenter |vMiddle);
        c->text(r.x + r.h/2.f,r.y + r.h/2.f, cpToUTF8(ic_menu));
        c->text(r.x + r.w -  r.h/2.f,r.y + r.h/2.f, cpToUTF8(ic_more_vert));
    }

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod) override{
        Rect r = rect();
        if(Rect(r.x ,r.y,r.h,r.h).in(x,y))
            m = true;
        else
            m = false;

        if(Rect(r.x + r.w - r.h,r.y,r.h,r.h).in(x,y))
            mm = true;
        else
            mm = false;

    }

    fun onMeasure() override{
        View* p = getParent();
        if(p!= null){
            this->size(p->rect().w,64);
        }else{
            this->size(640,64);
        }
    }
};

#endif
