#ifndef MUI_LINEARLAYOUT_H
#define MUI_LINEARLAYOUT_H

#include "../core/View.h"

class LinearLayout : public View{
private:
    bool v;
public:
    explicit LinearLayout(bool _v = true) : View(true){
        this->v = _v;
        this->margin(10);
    }

    fun onDraw(Canvas *c) override{
        vec4 r = this->rect();
        f32 _x = r.x,_y = r.y;

        for(View* view : getChild()){
            vec4 rv = view->rect();
            vec4 mv = view->margin();

            //     x,y,z,w
            //vec4(x,y,w,h);
            //vec4(l,r,t,b);

            if(v) {
                _y  = mv.x;
                _x += mv.y;
            }else{
                _x  = mv.x;
                _y += mv.y;
            }

            view->pos(_x,_y);
            view->onDraw(c);

            if(v) {
                _x += rv.z + mv.y;
            }else{
                _y += rv.w + mv.w;
            }
        }
    }

    fun onMeasure() override{
        f32 _w = 0.f,_h = 0.f;
        for(View *_v: getChild()){
            vec4 rv = _v->rect();
            vec4 mv = _v->margin();
            if(!v){
                if(rv.z + mv.x + mv.y > _w) _w = rv.z + mv.x + mv.y;
                _h += rv.w + mv.z + mv.w;
            }else{
                if(rv.w + mv.z + mv.w > _h) _h = rv.w + mv.z + mv.w;
                _w += rv.z + mv.x + mv.y;
            }
        }
        this->size(_w,_h);
        for(View* _v : getChild()){
            _v->onMeasure();
        }
    }
};

#endif
