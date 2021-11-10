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
    explicit LinearLayout(Orientation _o,View* parent) : View(parent,true){
        this->o = _o;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        f32 x = r.x,y = r.y;
        for(View* v : data()) {
            Visibility vv = v->visibility();
            Margin m = v->margin();
            if (vv == Visible || vv == Gone) {
                x += m.getMarginLeft();
                y += m.getMarginTop();
                v->pos(x, y);
                if(o == Horizontal)
                    y -= m.getMarginTop();
                else
                    x -= m.getMarginLeft();
            }
            if (vv == Visible)
                v->onDraw(c);
            if (vv == Visible || vv == Gone) {

                if (o == Horizontal) {
                    x += v->rect().w + m.getMarginRight();
                } else {
                    y += v->rect().h + m.getMarginBottom();
                }
            }
        }
    }

    fun onMeasure(f32 w,f32 h) override{
        f32 x = 0.f,y = 0.f;
        for(View* v : data()) {
            Measure _m = v->measure();
            if(o == Horizontal) {
                if (_m.getW() == Parent && _m.getH() == Parent)
                    v->onMeasure(w - x, h);
                else if (_m.getW() == Parent)
                    v->onMeasure(w - x, UNSIZE);
                else if (_m.getH() == Parent)
                    v->onMeasure(UNSIZE, h);
                else
                    v->onMeasure(UNSIZE, UNSIZE);
            }else{
                if (_m.getW() == Parent && _m.getH() == Parent)
                    v->onMeasure(w, h - y);
                else if (_m.getW() == Parent)
                    v->onMeasure(w, UNSIZE);
                else if (_m.getH() == Parent)
                    v->onMeasure(UNSIZE, h - y);
                else
                    v->onMeasure(UNSIZE, UNSIZE);
            }
            Margin m = v->margin();
            f32 marginH = m.getMarginLeft() + m.getMarginRight();
            f32 marginV = m.getMarginBottom() + m.getMarginTop();
            if (o == Horizontal) {
                x += v->rect().w + marginH;
                if(v->rect().h + marginV > y) y = v->rect().h + marginV;
            } else {
                y += v->rect().h + marginV;
                if(v->rect().w + marginH > x) x = v->rect().w + marginH;
            }
        }
        this->size(x,y);
    }

};

#endif
