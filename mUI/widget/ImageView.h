#ifndef MUI_IMAGEVIEW_H
#define MUI_IMAGEVIEW_H

#include "../view/View.h"

/**
 * @brief The ImageView class
 * API 2.0
 * @since 0.4.0
 */
class ImageView : public View{
public:
    enum Shape{
        SRect,
        SCircle,
        SRoundRect
    };
priv:
    Shape vShape;
    str imgL;
    i32 img;
pub:
    explicit ImageView(const str& img,View* parent) : ImageView(img,100,100,parent){ }
    explicit ImageView(const str& img,f32 w,f32 h,View* parent) : View(parent){
        this->imgL = img;
    }

    fun setImage(const str& _t){this->imgL = _t;}
    fun shape(Shape s){
        this->vShape = s;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        img = c->createImage(imgL.c_str(),0);
        c->begin();
        switch(vShape){
            case SRect:
                c->rect(r.x,r.y,r.w,r.h);
            break;
            case SCircle:
                c->circle(r.x + r.w/2,r.y +r.h/2,r.h/2);
            break;
            case SRoundRect:
                c->rect(r.x,r.y,r.w,r.h,10);
            break;
        }
        c->fillPaint(c->imagePaint(r.x,r.y,r.w,r.h,0.f,img,1.f));
        c->fill();
    }
};

#endif
