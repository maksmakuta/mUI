#ifndef MUI_GRIDLAYOUT_H
#define MUI_GRIDLAYOUT_H

#include "../../view/View.h"

/**
 * GridLayout
 * API 1.0.1
 * @since 0.5.15
 */
class GridLayout : public View{
private:
    i32 w;
    f32 iW,iH;
public:
    GridLayout(i32 _w,View* parent = null) : View(parent,true){
        this->w = _w;
    }

    fun onDraw(Canvas *c) override {
        Rect r = rect();

        c->begin();
        c->rect(r.x,r.y,r.w,r.h);
        c->fill("#faa");
        c->end(true);

        f32 _x = r.x ,_y = r.y;
        i32 p = 0;
        for (View* v : data()) {
            v->size(iW,iH);
            Visibility vv = v->visibility();
            Margin m = v->margin();
            if (p % w == 0 && p != 0) {
                _x = r.x;
                _y += iH + m.getMarginBottom();
            }
            if (vv == Visible || vv == Gone) {
                _x += m.getMarginLeft();
                _y += m.getMarginTop();
                v->pos(_x, _y);
                _y -= m.getMarginTop();
                _x -= m.getMarginLeft();
            }
            if (vv == Visible)
                v->onDraw(c);
            if (vv == Visible || vv == Gone) {
                _x += iW + m.getMarginRight();
            }

            p++;
        }
    }

    fun onMeasure(f32 _w, f32 _h) override{
        for(View *v : data())
            v->onMeasure(_w,_h);
        iW = at(0)->rect().w,iH = at(0)->rect().h;
        this->size(iW * (f32)w ,iH * (f32)((f32)data().size() / (f32)w) );
    }

};

#endif
