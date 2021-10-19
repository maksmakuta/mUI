#ifndef MUI_BUTTON_H
#define MUI_BUTTON_H

#include "core/View.h"

class Button : public View{
private:
    str t,f;
    f32 s,m;
public:
    explicit Button(const str& _t) : Button(){
        this->t = _t;
        this->setFontSize(16.f);
        this->setFontFace("roboto");
       // this->h(getFontSize() * 3.f);
        this->setM(15);
    }

    Button() : View(){ }

    fun setFontSize(f32 _s){
        this->s = _s;
    }

    fun setFontFace(const str& _f){
        this->f = _f;
    }

    fun setText(const str& _t){
        this->t = _t;
    }

    fun setM(f32 _m){
        this->m = _m;
    }

    f32 getFontSize(){return this->s;}
    str getFontFace(){return this->f;}
    str getText()    {return this->t;}

    fun onResize(f32 _w, f32 _h) override{}

    fun onDraw(Canvas *c) override{
/*
        f32 *b = c->textBounds(x() + w()/2.f,y() + this->getFontSize()/2.f,this->getText().c_str());

        auto *d = new f32[4]{
            b[0] - m,
            b[1] - m ,
            b[2] - b[0] + 2*m,
            b[3] - b[1] + 2*m,
        };

        c->begin();
        c->fill("#131313");
        c->rect(d[0],d[1],d[2],d[3],m);
        c->end(true);

        h(this->getFontSize() / 2.f + m);
        w(d[2] / 2.f);

        c->fontAlign(NVG_ALIGN_MIDDLE | NVG_ALIGN_CENTER);
        c->fontFace(this->getFontFace().c_str());
        c->fontSize(this->getFontSize());
        c->fill("#fff");
        c->text(d[0] + d[2]/2.f,d[1] + m + this->getFontSize()/2.f,this->getText().c_str());*/
    }


};

#endif
