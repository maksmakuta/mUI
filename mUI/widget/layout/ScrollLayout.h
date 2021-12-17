#ifndef MUI_SCROLLLAYOUT_H
#define MUI_SCROLLLAYOUT_H

#include "LinearLayout.h"

/**
 * ScrollLayout
 * API 2.0
 * @since 0.5.16
 */
class ScrollLayout : public View{
private:
    float s = 0;
public:
    explicit ScrollLayout(View* parent = null) : View(parent,true){ }

    fun onDraw(Canvas *c) override {
        Rect r = rect();
        View *v = at(0); // only first item draw
        //v->pos(v->rect().x, p);

        c->save();
        c->scissor(r.x,r.y,r.w,r.h);
        v->onDraw(c);
        v->pos(v->rect().x,v->rect().y + s);
        c->restore();
    }

    fun onMouseScroll(f64, f64 dy) override{

    }

    fun onMeasure(f32 w, f32 h) override{
        View *v = at(0);
        v->onMeasure(w,h);
        this->size(w,h);
    }
};

#endif
