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
pub:
    explicit LinearLayout(Orientation _o) : View(){
        this->o = _o;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        c->begin();
        c->rect(r.x,r.y,r.w,r.h);
        c->fill("#111");
        c->end(true);

        f32 x = r.x,y = r.y;
        for(View* v : data()){
            v->pos(x,y);
            v->onDraw(c);
            if(o == Horizontal)
                x += v->rect().w;
            else
                y += v->rect().h;
        }
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
};

#endif
