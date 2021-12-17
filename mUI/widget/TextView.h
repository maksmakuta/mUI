#ifndef MUI_TEXTVIEW_H
#define MUI_TEXTVIEW_H

#include "../view/View.h"

/**
 * @brief The TextView class
 * API 2.0
 * @since 0.4.0
 */
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
        Theme *t = getTheme();
        c->font("base",t->colorText(),t->sizeText());
        c->fontAlign(hLeft | vBaseline);
        c->text(rect().x,rect().y + rect().h / 1.3f,text);
    }

};

#endif
