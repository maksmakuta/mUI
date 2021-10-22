#ifndef MUI_PROGRESSVIEW_H
#define MUI_PROGRESSVIEW_H

#include "../core/View.h"

class ProgressView : public View{
private:
    f32 s,e,a;
public:
    ProgressView() : View(){ }
/*
    fun onDraw(Canvas *c) override{

        c->begin();
        c->circle(x +w/2,y+h/2,w/2);
        c->fill("#f0f");
        c->end(true);
    }
    */
};


#endif
