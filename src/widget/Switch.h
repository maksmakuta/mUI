#ifndef MUI_SWITCH_H
#define MUI_SWITCH_H

#include "../view/View.h"

class Switch : public View{
private:
    str _text;
    bool state = true;
    vec2 textSize;
public:
    explicit Switch(const str& text = "", View* parent = null) : View(parent){
        this->_text = text;
        this->margin(10);
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        f32 cr = r.h / 3.f;

        c->fontFace("roboto");
        c->fontSize(20.f);
        c->fontAlign(hCenter | vMiddle);
        textSize = c->textSize(_text.c_str());
        c->fontFill("#fff");
        c->text(r.x + textSize.x/2.f + 20.f,r.y + r.h/2.f,_text.c_str());

        c->begin();
        f32 rad = MathUtils::max<f32>(textSize.y/2.f,cr);
        c->rect(r.x + 45 + textSize.x,r.y + rad,cr*2.f,rad,rad/2.f);
        c->fill("#999");
        c->end(true);

        c->begin();
        c->circle(state ? r.x + r.w - r.h/2.f : r.x + r.w - r.h,r.y + r.h/2.f,cr);
        c->fill("#faa");
        c->end(true);

    }

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod) override{
        if(rect().in(x,y)){
            if(button == MOUSE_LEFT && action == GLFW_PRESS){
                state = !state;
            }
        }
    }

    fun onMeasure() override{
        this->size(textSize.x + 100,MathUtils::max<f32>(textSize.y,50));
    }
};

#endif