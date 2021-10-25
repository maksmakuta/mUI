#ifndef MUI_PROGRESSVIEW_H
#define MUI_PROGRESSVIEW_H

#include "../core/View.h"
#include <cmath>

class ProgressView : public View{
private:
    const char* col;
    f32 e,angle = 0.f;
    bool q = false;
public:
    ProgressView(const char* color) : ProgressView(100){
        this->col = color;
    }

    ProgressView(float s) : View(){
        this->rect(0,0,s,s);
        this->margin(20);
        e = 1.5f;
    }

    fun onDraw(Canvas *c) override{
        c->lineWidth(5.f);

        c->beginPath();
            for (f32 a = 0 + angle; a < e + angle; a += 0.1f) {
                c->moveTo(x + w / 2.0f + sinf(a) * (w / 2.f), y + h / 2.f + cosf(a) * (w / 2.f));
                c->lineTo(x + w / 2.0f + sinf(a + 0.15f) * (w / 2.f), y + h / 2.f + cosf(a + 0.15f) * (w / 2.f));
            }
        c->fill(this->col);
        c->end(false);

        if(q){
            e += 0.07f;
            if(e >= 2.8f * 2.0f) q = !q;
        }else{
            e -= 0.07f;
            if(e <= 0.7f) q = !q;
        }
        angle += 0.15f;
        if(angle >= NVG_PI * 2.f) angle = 0.f;
    }

    fun onMeasure() override{

    }
};


#endif
