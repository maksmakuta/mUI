#ifndef MUI_LINEARLAYOUT_H
#define MUI_LINEARLAYOUT_H

#include "core/Layout.h"

class LinearLayout : public Layout{
private:
    bool _v;
public:
    explicit LinearLayout(bool v = true) : Layout(){
        this->_v = v;
    }

    fun onDraw(Canvas *c) override{
        if(_v){
            f32 y = 0.f;
            for(auto& v : childs){
                v->y(y + v->marginTop());
                v->w(this->w());
                v->onDraw(c);
                y += v->h();
            }
        }else{
            f32 x = 0.f;
            for(auto& v : childs){
                v->x(x);
                v->onDraw(c);
                x += v->w();
            }
        }
    }

    fun onResize(f32 w,f32 h) override{
        this->w(w);
        this->h(h);
    }
};

#endif