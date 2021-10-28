#ifndef MUI_TEXTVIEW_H
#define MUI_TEXTVIEW_H

#include "../view/View.h"

class TextView : public View{
priv:
    str text;
    f32 fontSize;
pub:

    explicit TextView(const str& t) : View(){
        this->text = t;
        this->setFontSize(24.f);
    }

    fun setFontSize(f32 f){this->fontSize = f;}
    f32 getFontSize(){return this->fontSize;}

    fun setText(const str& _t){this->text = _t;}
    str getText(){return this->text;}

    fun onDraw(Canvas *c) override{
        c->useBaseFont(getFontSize(),"#fff");
        vec2 p = c->textSize(text.c_str());
        this->size(p.x * 1.2f,p.y * 1.4f);
        c->fontAlign(hLeft | vBaseline);
        c->text(rect().x,rect().y + rect().h / 1.3f,text.c_str());
    }
};

#endif
