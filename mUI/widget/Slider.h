#ifndef MUI_SLIDER_H
#define MUI_SLIDER_H

#include "../view/View.h"
#include "../graphics/utils/MathUtils.h"

class OnSliderChangeListener{
public:
    virtual fun onSliderChange(f32 var) = 0;
};

class Slider : public View{
private:
    f32 min,max,curr,step;
    OnSliderChangeListener* onChange = null;
public:
    Slider(f32 _min,f32 _max,View* parent) : View(parent){
        this->min = _min;
        this->max = _max;
        this->curr = 0.f;
        this->margin(10);
        this->setStep(0.1f);
    }

    fun setOnSliderChangeListener(OnSliderChangeListener* l){
        if(l != null)
            this->onChange = l;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        f32 cr = r.h/2.f;
        c->begin();
        c->rect(r.x + cr,r.y + r.h/2,r.w - 2*cr,r.h * .1f);
        c->fill("#999");
        c->end(true);

        if(this->hover()) {
            c->begin();
            c->circle(r.x + r.w*curr + cr/2.f, r.y + cr, cr*1.5f);
            c->fill("#c78");
            c->end(true);
        }

        c->begin();
        c->circle(r.x + r.w*curr + cr/2.f,r.y + cr,cr);
        c->fill("#fab");
        c->end(true);
    }

    fun setStep(f32 s){this->step = s;}

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod) override{
        Rect r = rect();
        f32 cr = r.h/2.f;
        if (r.in((f32)x, (f32)y)) {
            this->hover(true);
            if(button == MOUSE_LEFT && action == MOUSE_CLICK){
                f32 p = (f32)x - (r.w - r.x) - cr;
                if(p < 0) p *= -1;
                this->curr = 1.f - (p / (r.w - r.x));
                if(this->onChange != null)
                    this->onChange->onSliderChange(this->current());
            }
        }else{
            this->hover(false);
        }
    }

    fun onKey(i32 key, i32 scancode, i32 action, i32 mods) override{
        if(this->hover()){
            f32 p = this->curr;
            if(key == GLFW_KEY_LEFT && action == GLFW_PRESS){
                p = this->curr - step;
            }

            if(key == GLFW_KEY_RIGHT && action == GLFW_PRESS){
                p = this->curr + step;
            }

            if(p < 0.f) p = 0.f;
            if(p > 1.f) p = 1.f;
            this->curr = p;
            if(this->onChange != null)
                this->onChange->onSliderChange(this->current());
        }
    }

    f32 current(){
        return MathUtils::range<f32>(0.f,1.f,min,max,curr);
    }


};

#endif
