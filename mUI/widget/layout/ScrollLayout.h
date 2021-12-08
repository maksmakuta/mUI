#ifndef MUI_SCROLLLAYOUT_H
#define MUI_SCROLLLAYOUT_H

#include "LinearLayout.h"

#define SMOOTH 0.25f
#define SMin -0.5f
#define SMax  0.5f
#define MAX_SPEED 15.0f
#define BAR_SIZE 10.0f

/**
 * ScrollLayout
 * API 1.0.1
 * @since 0.5.16
 */
class ScrollLayout : public View{
private:
    f32 s = 0.0f,p = 0.0f,l = 50.f,sp = 0.0f;
    bool showBar = true;
public:
    explicit ScrollLayout(View* parent = null) : View(parent,true){ }

    fun onDraw(Canvas *c) override {
        Rect r = rect();
        View *v = at(0); // only 1 item draw
        v->pos(v->rect().x, p);

        if (p > 0) p = 0;
        if (p < rect().h - v->rect().h) p =  rect().h - v->rect().h;

        c->save();
        c->scissor(rect().x, rect().y, rect().w, rect().h);
        v->onDraw(c);
        c->restore();

        sp = p / (v->rect().h - (rect().h + l));
        if(sp < 0) sp *= -1;
        if(showBar) {
            c->begin();
            c->rect(r.x + r.w - BAR_SIZE, r.y, BAR_SIZE, r.h, 5);
            if (hover())
                c->fill(getTheme()->colorSecondary().c_str());
            else
                c->fill(getTheme()->colorBackground().c_str());
            c->end(true);

            c->begin();
            c->rect(r.x + r.w - BAR_SIZE, r.y + (r.h - l) * sp, BAR_SIZE, l, 5);
            c->fill(getTheme()->colorAccent().c_str());
            c->end(true);
        }
        p += s;

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
        View *v = at(0);
        v->onMeasure(w,h);
        this->size(w,h);

        l = (this->rect().h / v->rect().h) * this->rect().h;
        if(l < BAR_SIZE) l = BAR_SIZE;
        if(l <= 0.95f) showBar = false;
    }
};

#endif
