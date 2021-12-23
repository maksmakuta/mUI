#ifndef MUI_BUTTON_H
#define MUI_BUTTON_H

#include "../view/View.h"
#include "../graphics/utils/ColorUtils.h"
#include "../graphics/utils/MaterialIcons.h"

/**
 * @brief The Button class
 * API 2.0.2
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
        Theme* t = getTheme();

        c->begin();
        if(vStyle != Text){
            i32 m = t->sizeMargin();
            if(vStyle != Icon)
                c->rect(r.x,r.y,r.w,r.h,r.h/2.f);
            else
                switch(vShape){
                    case SCircle:
                        c->circle(r.x + r.w/2,r.y + r.h/2,r.h / 2.f);
                    break;
                    case SRect:
                        c->rect(r.x + m,r.y,r.w - 2*m,r.h);
                    break;
                    case SRoundRect:
                        c->rect(r.x + m,r.y,r.w - 2*m,r.h,r.h/6.f);
                    break;
                }

            c->end(vStyle == Filled || vStyle == Icon,hover() ? t->colorSecondary() : t->colorPrimary());
        }
        str col = hover() ? vStyle == Outline || vStyle == Text ? t->colorSecondary() : t->colorBackground() : t->colorText();
        c->font(vStyle == Icon ? "icon" : "base",col,t->sizeText());
        c->fontAlign(vMiddle | hCenter);
        vec2 cc = c->text(r.x + r.w/2.f,r.y + r.h/2.f,text);
        this->content(cc.x,0);
    }

};

#endif
