#ifndef MUI_BUTTON_H
#define MUI_BUTTON_H

#include "../view/View.h"

class Button : pub View{
public:
    enum Style{
        Filled  ,
        Outline ,
        Text    ,
        Icon
    };
priv:
    str text;
    vec2 p;
    f32 fontSize{};
    Style vStyle;
pub:
    explicit Button(const str& t,View* parent = null) : View(parent){
        this->text = t;
        style(Filled);
    }

    fun style(Style s){
        this->vStyle = s;
    }

    fun setText(const str& _t){this->text = _t;}
    str getText(){return this->text;}

    fun onDraw(Canvas *c) override{
        Rect r = rect();

        c->fontFace(vStyle == Icon ? "icons" : "roboto");
        c->fontSize(24.f);
        p = c->textSize(text.c_str());

        if(vStyle != Text) {
            c->begin();
            c->rect(r.x, r.y, r.w, r.h, r.h / 2.f);
            c->fill(hover() ? "#f92" : "#222");
            c->end(vStyle != Outline);
        }

        c->fontAlign(hCenter | vMiddle);
        str color;
        switch (vStyle) {
            case Filled  : case Icon: color = hover() ? "#000" : "#fff"; break;
            case Outline : case Text: color = hover() ? "#f92" : "#fff"; break;
        }
        c->fontFill(color.c_str());
        c->text(rect().x + rect().w /2.f,rect().y + rect().h / 2.f,text.c_str());
    }

    fun onMeasure(f32 _w,f32 _h) override {
        f32 s = this->getTheme()->size;
        f32 w,h;

        switch (this->measure().getW()) {
            case Parent  : w = _w ;           break;
            case Content : w = this->p.x + s; break;
            case Fixed   : w = fixed().x;     break;
        }
        switch (this->measure().getH()) {
            case Parent  : h = _h ;           break;
            case Content : h = s;             break;
            case Fixed   : h = fixed().x;     break;
        }

        this->size(w,h);

    }


};

#endif
