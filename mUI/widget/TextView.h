#ifndef MUI_TEXTVIEW_H
#define MUI_TEXTVIEW_H

#include "../view/View.h"

class TextView : public View{
priv:
    str text;
pub:
    explicit TextView(const str& t,View* parent) : View(parent){
        this->text = t;
    }

    fun setText(const str& _t){this->text = _t;}
    str getText(){return this->text;}

    fun onDraw(Canvas *c) override{
        c->useBaseFont(getTheme()->sizeText(),getTheme()->colorText().c_str());
        this->content(c->textSize(text.c_str()));
        c->fontAlign(hLeft | vBaseline);
        c->text(rect().x,rect().y + rect().h / 1.3f,text.c_str());
    }

    fun onMeasure(f32 w, f32 h) override{
        f32 s = this->getTheme() == null ? 0.0f : this->getTheme()->sizeDef();
        f32 vw,vh;
        vec2 contentSize = this->content();
        switch (this->measure().getW()) {
            case Parent  : vw = w;                  break;
            case Content : vw = contentSize.x + s;  break;
            case Fixed   : vw = fixed().x;          break;
        }
        switch (this->measure().getH()) {
            case Parent  : vh = h;                  break;
            case Content : vh = contentSize.y + s;  break;
            case Fixed   : vh = fixed().y;          break;
        }
        this->size(vw,vh);
    }
};

#endif
