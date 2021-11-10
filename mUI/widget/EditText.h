#ifndef MUI_EDITTEXT_H
#define MUI_EDITTEXT_H

#include <sstream>
#include "../view/View.h"

enum EditStyle{
    Filled,
    OutLine
};

class EditText : pub View {
priv:
    str text,label;
    f32 fontSize,x = 0.f;
    vec2 p,m;
    f32 bitPos;
    EditStyle style;
pub:
    EditText(const str& _label,View* parent,EditStyle s = Filled) : View(parent){
        this->setFontSize(24.f);
        this->setText("");
        this->p = vec2(100,getFontSize());
        this->margin(10);
        this->label = _label;
        this->style = s;
    }

    fun setFontSize(f32 f){
        this->fontSize = f;
    }
    f32 getFontSize(){
        return this->fontSize;
    }
    fun setText(const str& _t){
        this->text = _t;
    }
    str getText(){
        return this->text;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();
        c->save();
        c->scissor(r.x,r.y,r.w,r.h);

        if(style == Filled) {
            c->begin();
            c->rect(r.x, r.y, r.w, r.h);
            c->fill("#666");
            c->end(true);

            c->begin();
            c->rect(r.x, r.y + r.h - 1, r.w, 1);
            c->fill("#aaa");
            c->end(true);
        }else{
            c->begin();
            c->rect(r.x, r.y, r.w, r.h,r.h * .2f);
            c->fill("#aaa");
            c->end(false);
        }

        if(!text.empty()) {
            c->begin();
            f32 b = (r.h - getFontSize()) / 2.f;
            c->rect(r.x + bitPos, r.y + b, 1, getFontSize());
            c->fill("#f00");
            c->end(true);
        }

        c->useBaseFont(getFontSize(),text.empty() ? "#aaa" : "#fff");
        if(!text.empty())
            p = c->textSize(text.c_str());
        c->fontAlign(hLeft | vBaseline);
        c->text(r.x + x,r.y + r.h / 1.3f,text.empty() ? label.c_str() :text.c_str());
        c->restore();

    }

    fun onKey(u32 codepoint) override{
        if(this->hover()){
            std::ostringstream ss;
            ss << (char)codepoint;
            this->text.append(ss.str());
            bitPos++;
        }
    }

    fun onKey(i32 key, i32 scancode, i32 action, i32 mods) override{
        if(this->hover()){
            if(key == GLFW_KEY_BACKSPACE && (action == GLFW_PRESS or action == GLFW_REPEAT)) {
                if (!text.empty()) {
                    text.erase(text.end() - 1);
                    bitPos--;
                }
            }
            if(key == GLFW_KEY_ENTER && action == GLFW_PRESS){
                this->hover(false);
            }
        }
    }

    fun onMouseScroll(f64 dx, f64 dy) override{
        if(p.x > rect().w){
            this-> x += (f32)dx * 5.f;
        }

        if(x > 0.f)
            x = 0.f;
        if(x < rect().w - p.x)
            x = rect().w - p.x;
    }

    fun onMouse(f64 _x, f64 _y, i32 button, i32 action, i32 mod) override{
        m = vec2((f32)_x,(f32)_y);
    }

    fun onMeasure() override{
        this->size(300,getFontSize() * 1.3f);
    }
};

#endif
