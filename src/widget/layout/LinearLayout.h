#ifndef MUI_LINEARLAYOUT_H
#define MUI_LINEARLAYOUT_H

#include "../../view/View.h"

enum Orientation{
    Horizontal,
    Vertical
};

class LinearLayout : pub View{
priv:
    Orientation o;
    vec2 sliders;
pub:
    explicit LinearLayout(Orientation _o) : View(){
        this->o = _o;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
//        if(this->isScrollableH()) {
//            c->begin();
//            c->rect(r.x, r.y, r.w, r.h);
//            c->fill("#f0f");
//            c->end(true);
//        }
        f32 x = r.x,y = r.y;
        for(View* v : data()){
            v->pos(x,y);
            v->onDraw(c);
            if(o == Horizontal)
                x += v->rect().w;
            else
                y += v->rect().h;
        }

        if(isScrollableH()){
            x += 5;
            slider(true,c);
        }
        if(isScrollableV()){
            y -= 5;
            slider(false,c);
        }
    }

    fun slider(bool t,Canvas* c){
        Rect r = rect();
        c->lineWidth(3);
        c->begin();
        if(t) {
            c->moveTo(r.x + sliders.x * getWinSize().x * (getWinSize().x / r.w), r.y + r.h);
            c->lineTo(r.x + getWinSize().x * (getWinSize().x / r.w), r.y + r.h);
        }else{
            c->moveTo(r.x + r.w, r.y+ sliders.y );
            c->lineTo(r.x + r.w, r.y + getWinSize().y * (getWinSize().y / r.h));
        }
        c->fill("#aaa");
        c->end(false);
    }

    fun onMeasure() override{
        f32 x = 0.f,y = 0.f;
        for(View* v : data()) {
            v->onMeasure();
            if (o == Horizontal) {
                x += v->rect().w;
                if(v->rect().h > y) y = v->rect().h;
            } else {
                y += v->rect().h;
                if(v->rect().w > x) x = v->rect().w;
            }
        }
        this->size(x,y);
    }

    fun onMouseScroll(f64 dx, f64 dy) override{
        Rect r = rect();
        f32 ddx = (f32)-dx * 2.56f;
        f32 ddy = (f32)-dy * 2.56f;
        if(isScrollableH() && r.x - ddx + r.w >= getWinSize().x && r.x - ddx <= 0){
            pos(r.x - (f32)ddx,r.y);
        }
        if(isScrollableV() && r.y - ddy + r.h >= getWinSize().y && r.y - ddy <= 0){
            pos(r.x ,r.y - (f32)ddy);
        }
        sliders += vec2(ddx,ddy);
    }
};

#endif
