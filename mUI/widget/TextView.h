#ifndef MUI_TEXTVIEW_H
#define MUI_TEXTVIEW_H

#include "../view/View.h"

class TextView : public View{
priv:
    str text;
    vec2 p;
pub:
    explicit TextView(const str& t,View* parent) : View(parent){
        this->text = t;
    }

    fun setText(const str& _t){this->text = _t;}
    str getText(){return this->text;}

    fun onDraw(Canvas *c) override{
        c->useBaseFont(getTheme()->sizeText(),getTheme()->colorText().c_str());
        p = c->textSize(text.c_str());
        c->fontAlign(hLeft | vBaseline);
        c->text(rect().x,rect().y + rect().h / 1.3f,text.c_str());
    }

    fun onMeasure(f32 _w,f32 _h) override{
        this->size(p.x * 1.2f,p.y * 1.4f);
    }
};

#endif
