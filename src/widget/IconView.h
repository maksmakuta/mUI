#ifndef MUI_ICONVIEW_H
#define MUI_ICONVIEW_H

#include "../view/View.h"
#include "../graphics/utils/MaterialIcons.h"

class IconView : pub View{
priv:
    str text;
    f32 fontSize;
    vec2 p;
pub:
    explicit IconView(i32 i) : View(){
        this->setIcon(i);
        this->setFontSize(48.f);
    }

    fun setFontSize(f32 f){this->fontSize = f;}
    f32 getFontSize(){return this->fontSize;}

    fun setIcon(i32 i){
        this->text = cpToUTF8(i);
    }

    fun onDraw(Canvas *c) override{
        c->fontFace("icons");
        c->fontSize(fontSize);
        c->fontFill("#fff");
        p = c->textSize(text.c_str());
        c->fontAlign(hLeft | vBaseline);
        c->text(rect().x,rect().y + rect().h / 1.3f,text.c_str());
    }

    fun onMeasure() override{
        this->size(p.x * 1.2f,p.y * 1.4f);
    }
};

#endif
