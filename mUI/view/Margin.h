#ifndef MUI_MARGIN_H
#define MUI_MARGIN_H

#include "../types.h"

class Margin{
private:
    f32 t,b,l,r;
public:
    Margin() : Margin(0.f){ }
    explicit Margin(f32 a) : Margin(a,a,a,a){ }
    Margin(f32 _t,f32 _b,f32 _r,f32 _l){
        this->setMarginTop    (_t);
        this->setMarginBottom (_b);
        this->setMarginLeft   (_l);
        this->setMarginRight  (_r);
    }
    Margin(const Margin& m)
        : Margin(m.getMarginTop(),m.getMarginBottom(),m.getMarginRight(),m.getMarginLeft()){ }


    fun setMarginTop(f32 m){
        this->t = m;
    }

    fun setMarginBottom(f32 m){
        this->b = m;
    }

    fun setMarginLeft(f32 m){
        this->l = m;
    }

    fun setMarginRight(f32 m){
        this->r = m;
    }

    f32 getMarginTop   () const {return this->t;}
    f32 getMarginBottom() const {return this->b;}
    f32 getMarginLeft  () const {return this->l;}
    f32 getMarginRight () const {return this->r;}

    Margin operator =(const Margin& m){
        this->setMarginTop   (m.getMarginTop   ());
        this->setMarginBottom(m.getMarginBottom());
        this->setMarginLeft  (m.getMarginLeft  ());
        this->setMarginRight (m.getMarginRight ());
        return *this;
    }
};

#endif
