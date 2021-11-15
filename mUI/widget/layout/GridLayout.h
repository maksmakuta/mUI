#ifndef MUI_GRIDLAYOUT_H
#define MUI_GRIDLAYOUT_H

#include "../../view/View.h"

/**
 * GridLayout
 *
 */
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
        for (i32 x = 0; x < w; x++){
            for (i32 y = 0; y < h; y++) {
                f32 _x = 0.f,_y = 0.f;
                View* v = this->at(x+h*y);
                Visibility vv = v->visibility();
                Margin m = v->margin();
                if (vv == Visible || vv == Gone) {
                    _x += m.getMarginLeft();
                    _y += m.getMarginTop();
                    v->pos(_x, _y);
                    //if(o == Horizontal)
                    //    _y -= m.getMarginTop();
                    //else
                    //    _x -= m.getMarginLeft();
                }
                if (vv == Visible)
                    v->onDraw(c);
                if (vv == Visible || vv == Gone) {
                    //if (o == Horizontal) {
                    //    _x += v->rect().w + m.getMarginRight();
                    //} else {
                    //    _y += v->rect().h + m.getMarginBottom();
                    //}
                }
            }
        }
    }

    fun onMeasure(f32 _w,f32 _h) override{
        for(auto v : data()){
            v->onMeasure(_w/w,_h/h);
        }

        this->size(w,h);
    }
};

#endif
