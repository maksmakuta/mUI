#ifndef MUI_TOOLBAR_H
#define MUI_TOOLBAR_H

#include "../view/View.h"

class ToolBar : public View{
private:
    str title;
public:
    explicit ToolBar(const str& _t,View* p = null) : View(p){
        this->title = _t;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        Theme* t = getTheme();
        c->begin();
        c->rect(r.x,r.y,r.w,r.h);
        c->fill(t->colorSecondary().c_str());
        c->end(true);

        c->fontFace("roboto");
        c->fontSize(t->sizeText());
        c->fontFill(t->colorText().c_str());
        c->fontAlign(hCenter |vMiddle);
        c->text(r.x + r.w/2.f,r.y + r.h/2.f,title.c_str());
    }

    fun onMeasure(f32 _w,f32 _h) override{
        View* p = getParent();
        if(p!= null){
            this->size(p->rect().w,64);
        }else{
            this->size(_w,64);
        }
    }
};

#endif
