#ifndef MUI_IMAGEVIEW_H
#define MUI_IMAGEVIEW_H

#include "../view/View.h"

class ImageView : public View{
priv:
    str imgL;
    i32 img;
    vec2 p;
pub:
    explicit ImageView(const str& img,View* parent) : ImageView(img,100,100,parent){ }
    explicit ImageView(const str& img,f32 w,f32 h,View* parent) : View(parent){
        this->imgL = img;
        this->p = vec2(w,h);
    }

    fun setImage(const str& _t){this->imgL = _t;}

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        img = c->image(imgL.c_str());
        c->begin();
        c->rect(r.x,r.y,r.w,r.h);
        c->img(r.x,r.y,r.w,r.h,img);
    }

    fun onMeasure() override{
        this->size(p.x,p.y);
    }
};

#endif
