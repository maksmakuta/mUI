#ifndef MUI_BUTTON_H
#define MUI_BUTTON_H

#include <functional>
#include "../view/View.h"

class Button : pub View{
priv:
    str text;
    vec2 p;
    f32 fontSize{};
    bool hover = false;
pub:
    explicit Button(const str& t) : View(){
        this->text = t;
        setFontSize(20.f);
    }

    fun setFontSize(f32 _f){this->fontSize = _f;}
    f32 getFontSize(){return this->fontSize;}

    fun setText(const str& _t){this->text = _t;}
    str getText(){return this->text;}

    fun onDraw(Canvas *c) override{
        c->fontSize(getFontSize());
        p = c->textSize(text.c_str());
        this->size(p.x * 1.3f,p.y * 1.5f);

        c->begin();
        c->rect(rect().x,rect().y,rect().w,rect().h,10);
        c->fill(hover ? "#f92" : "#333");
        c->end(true);

        c->fontAlign(hCenter | vMiddle);
        c->fontFill(hover? "#000" : "#fff");
        c->text(rect().x + rect().w /2.f,rect().y + rect().h / 2.f,text.c_str());
    }

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod) override {
        if (rect().in((f32)x, (f32)y)) {
            hover = true;
        } else {
            hover = false;
        }
    }

};

#endif
