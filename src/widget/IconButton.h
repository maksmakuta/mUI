#ifndef MUI_ICONBUTTON_H
#define MUI_ICONBUTTON_H

#include "../view/View.h"
#include "../graphics/utils/MaterialIcons.h"

enum Shape{
    rect,
    circle,
    rrect
};

class IconButton : public View{
private:
    str text;
    f32 sF;
    Shape mShape;
public:
    IconButton(Shape sh, i32 icon,f32 s,View* p) : View(p){
        this->text = cpToUTF8(icon);
        this->sF = s;
        this->margin(10);
        this->mShape = sh;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        c->begin();
        switch (mShape) {
            case Shape::rect :
                c->rect(r.x,r.y,r.w,r.h);
                break;
            case Shape::circle :
                c->circle(r.x + r.w / 2.f,r.y + r.w / 2.f,r.w / 2.f);
                break;
            case Shape::rrect :
                c->rect(r.x,r.y,r.w,r.h,r.w * 0.2f);
                break;
        }
        c->fill(!hover() ? "#333" : "#f84");
        c->end(true);

        c->fontFace("icons");
        c->fontSize(this->sF);
        c->fontFill(!hover() ? "#aaa" : "#222");
        c->fontAlign(hCenter | vMiddle);
        c->text(r.x + r.w/2.f,r.y + r.h/2.f,text.c_str());
    }

    fun onMeasure() override{
        this->size(sF*2.f,sF*2.f);
    }

};

#endif
