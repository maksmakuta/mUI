#ifndef MUI_TEXTVIEW_H
#define MUI_TEXTVIEW_H

#include "core/View.h"

class TextView : public View{
private:
    str t,f;
    f32 s;
public:

    explicit TextView(const str& _t) : TextView(){
        this->t = _t;
        this->setFontSize(16.f);
        this->setFontFace("roboto");
    }

    TextView() : View(){ }

    fun setFontSize(f32 _s){
        this->s = _s;
    }

    fun setFontFace(const str& _f){
        this->f = _f;
    }

    fun setText(const str& _t){
        this->t = _t;
    }

    f32 getFontSize(){return this->s;}
    str getFontFace(){return this->f;}
    str getText()    {return this->t;}

    fun onDraw(Canvas *c) override{
        c->fontAlign(NVG_ALIGN_MIDDLE | NVG_ALIGN_CENTER);
        c->fontFace(this->f.c_str());
        c->fontSize(this->s);
        c->fill("#fff");
        c->text(x() + w()/2.f,y() + this->s/2.f,this->t.c_str());
    }

    fun onResize(f32 _w, f32 _h) override{
        //this->w(_w);
        //this->h(_h);
    }
};


#endif