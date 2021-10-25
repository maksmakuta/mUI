#ifndef MUI_LINEARLAYOUT_H
#define MUI_LINEARLAYOUT_H

#include "../core/View.h"

class LinearLayout : public View{
private:
    bool v;
public:
    explicit LinearLayout(bool _v = true) : View(){
        this->v = _v;
        this->margin(10);
    }

    fun onDraw(Canvas *c) override{
        f32 _x = this->x,_y = this->y;

        for(View* view : getChild()){
            if(v) {
                _y = view->t;
                _x += view->l;
            }else{
                _x = view->l;
                _y += view->t;
            }

            view->x = _x;
            view->y = _y;

            view->onDraw(c);

            if(v) {
                _x += view->w + view->r;
            }else{
                _y += view->h + view->b;
            }
        }
    }

    fun onMeasure() override{
        f32 _w = 0.f,_h = 0.f;
        for(View *_v: getChild()){
            if(!v){
                if(_v->w + _v->l + _v->r > _w) _w = _v->w + _v->l + _v->r;
                _h += _v->h + _v->t + _v->b;
            }else{
                if(_v->h + _v->t + _v->b > _h) _h = _v->h + _v->b + _v->t;
                _w += _v->w + _v->r + _v->l;
            }
        }
        this->w = _w;
        this->h = _h;
        for(View* _v : getChild()){
            _v->onMeasure();
        }
    }
};

#endif
