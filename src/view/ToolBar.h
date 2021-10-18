#ifndef MUI_TOOLBAR_H
#define MUI_TOOLBAR_H

#include "core/View.h"

class ToolBar : public View{
private:
    str _t;
public:

    ToolBar(const str& title) : View(){
        this->_t = title;
        this->h(64.f);
    }

    fun onDraw(Canvas *c) override{
        c->begin();
        c->rect(x(),y(),w(),h());
        c->fill("#fa91cd");
        c->end(true);

        c->fontAlign(NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE); //TODO align font cast to own names
        c->fontFace("noto");
        c->fontSize(32);
        c->fill("#000");
        c->text(x() + w()/2,y() + h() / 2.f,_t.c_str());
    }

    fun onResize(f32 _w, f32 _h) override{
        this->w(_w);
    }

};

#endif
