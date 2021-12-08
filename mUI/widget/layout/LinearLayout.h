#ifndef MUI_LINEARLAYOUT_H
#define MUI_LINEARLAYOUT_H

#include "../../view/View.h"

/**
 * set orientation of LinearLayout
 */
enum Orientation{
    Horizontal,
    Vertical
};

/**
 * LinearLayout
 * API 1.3
 * @since 0.4.0
 */
class LinearLayout : pub View{
priv:
    Orientation o;
pub:
    /**
     * Constructor
     * @param _o     : Orientation  -> orientation for layout
     * @param parent : View*        -> parent view
     */
    explicit LinearLayout(Orientation _o = Vertical,View* parent = null) : View(parent,true){
        this->o = _o;
    }

    /**
     * onDraw -> method for draw child views
     * @param c : Canvas*
     */
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
    /**
     * onMeasure -> used for resize child view and this view (layout)
     * @param w : Float -> width  of parent view
     * @param h : Float -> height of parent view
     */
    fun onMeasure(f32 w,f32 h) override{
        f32 x = 0.f,y = 0.f;
        for(View* v : data()) {
            f32 mw,mh;

            Margin m = v->margin();
            f32 marginH = m.getMarginLeft() + m.getMarginRight();
            f32 marginV = m.getMarginBottom() + m.getMarginTop();
            Measure _m = v->measure();
            switch (_m.getW()) {
                case Parent  : mw = o == Horizontal ? w - x - marginH : w - marginH ; break;
                case Content : mw = UNSIZE;                                           break;
                case Fixed   : mw = 0;                                                break;
            }
            switch (_m.getH()) {
                case Parent  : mh = o == Horizontal ? h - marginV : h - y - marginV ; break;
                case Content : mh = UNSIZE;                                           break;
                case Fixed   : mh = 0;                                                break;
            }
            v->onMeasure(mw,mh);

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
