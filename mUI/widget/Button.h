#ifndef MUI_BUTTON_H
#define MUI_BUTTON_H

#include "../view/View.h"
#include "../graphics/utils/MaterialIcons.h"

class Button : pub View{
public:
    enum Style{
        Filled  ,
        Outline ,
        Text    ,
        Icon
    };
private:
    str text;
    vec2 p;
    f32 fontSize{};
    Style vStyle = Filled;
public:
    explicit Button(i32 icon,View* parent = null) : Button(cpToUTF8(icon),parent) { }
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
        vec2 cc = c->textSize(text.c_str());
        cc.y = 0.f;
        this->content(cc);

        if(vStyle != Text) {
            c->begin();
            if(vStyle != Icon)
                c->rect(r.x, r.y, r.w, r.h, r.h / 2.f);
            else
                c->circle(r.x + r.w /2.f, r.y + r.h / 2.f,r.h / 2.f);
            c->fill(hover() ? "#f92" : "#222");
            c->end(vStyle != Outline);
        }

        c->fontAlign(hCenter | vMiddle);
        str color;
        switch (vStyle) {
            case Filled : case Icon: color = hover() ? "#000" : getTheme()->colorBackground(); break;
            case Outline: case Text: color = hover() ? "#f92" : getTheme()->colorText();       break;
        }
        c->fontFill(color.c_str());
        c->text(rect().x + rect().w /2.f,rect().y + rect().h / 2.f,text.c_str());
    }

};

#endif
