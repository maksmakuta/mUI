#ifndef MUI_SCROLLLAYOUT_H
#define MUI_SCROLLLAYOUT_H

#include "LinearLayout.h"

#define SMOOTH 0.25f
#define SMin -0.5f
#define SMax  0.5f
#define MAX_SPEED 15.0f

/**
 * ScrollLayout
 * API 1.0
 * @since 0.5.16
 */
class ScrollLayout : public View{
private:
    f32 s = 0.0f,p = 0.0f;
public:
    explicit ScrollLayout(View* parent = null) : View(parent,true){ }

    fun onDraw(Canvas *c) override {
        View *v = at(0); // only 1 item draw
        v->pos(v->rect().x, p);

        if (p > 0) p = 0;
        if (p < rect().h - v->rect().h) p =  rect().h - v->rect().h;

        c->save();
        c->scissor(rect().x, rect().y, rect().w, rect().h);
        v->onDraw(c);
        c->restore();

        p += s;
        //printf("%f\n", s);

        if (s >= SMax + SMOOTH)
            s -= SMOOTH;
        else if (s <= SMin - SMOOTH)
            s += SMOOTH;
        else
            s = 0.0f;
    }

    fun onMouseScroll(f64, f64 dy) override{
        s += (f32)dy;
        if(s >=  MAX_SPEED) s =  MAX_SPEED;
        if(s <= -MAX_SPEED) s = -MAX_SPEED;
    }

    fun onMeasure(f32 w, f32 h) override{
        at(0)->onMeasure(w,h);
        this->size(w,h);
    }
};

#endif
