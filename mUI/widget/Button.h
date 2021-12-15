#ifndef MUI_BUTTON_H
#define MUI_BUTTON_H

#include "../view/View.h"
#include "../graphics/utils/ColorUtils.h"
#include "../graphics/utils/MaterialIcons.h"

/**
 * @brief The Button class
 * API 2.0
 * @since 0.4.0
 */
class Button : pub View{
public:
    enum Style{
        Filled  ,
        Outline ,
        Text    ,
        Icon
    };
    enum Shape{
        SRect,
        SCircle,
        SRoundRect
    };
private:
    str text;
    vec2 p;
    f32 fontSize{};
    Style vStyle;
    Shape vShape;
public:
    explicit Button(i32 icon,View* parent = null) : Button(cpToUTF8(icon),parent) {
        this->style(Icon);
        this->shape(SRoundRect);
    }
    explicit Button(const str& t,View* parent = null) : View(parent){
        this->text = t;
        this->style(Outline);
    }

    fun style(Style s){
        this->vStyle = s;
    }

    fun shape(Shape s){
        if(this->vStyle == Icon)
            this->vShape = s;
        else
            printf("Warning -> Button style != Icon\n");
    }

    fun setText(const str& _t){this->text = _t;}
    str getText(){return this->text;}

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        Theme *th = getTheme();

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
                switch (vShape) {
                    case Shape::SRect :
                        c->rect(r.x,r.y,r.w,r.h);
                        break;
                    case Shape::SCircle :
                        c->circle(r.x + r.w / 2.f,r.y + r.h / 2.f,r.h / 2.f);
                        break;
                    case Shape::SRoundRect :
                        c->rect(r.x,r.y,r.w,r.h,r.w * 0.2f);
                        break;
                }
            c->fill(hover() ? th->colorAccent() : th->colorSecondary());
            c->end(vStyle != Outline);
        }

        c->fontAlign(hCenter | vMiddle);
        str color;
        switch (vStyle) {
            case Filled : case Icon: color = hover() ? th->colorBackground() : th->colorText(); break;
            case Outline: case Text: color = hover() ? th->colorAccent()     : th->colorText(); break;
        }
        c->fontFill(color.c_str());
        c->text(r.x + r.w /2.f,r.y + r.h / 2.f,text.c_str());
    }

};

#endif
