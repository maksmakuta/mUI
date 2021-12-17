#ifndef MUI_EDITTEXT_H
#define MUI_EDITTEXT_H

#include <sstream>
#include "../view/View.h"


class EditText : pub View {
priv:
    str text,label;
    f32 fontSize,x = 0.f;
    f32 bitPos;
pub:
    EditText(const str& _label,View* parent) : View(parent){
        this->setFontSize(24.f);
        this->setText("");
        this->margin(10);
        this->label = _label;
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
        /*
        Rect r = rect();
        c->save();
        c->scissor(r.x,r.y,r.w,r.h);

        c->begin();
        c->rect(r.x, r.y, r.w, r.h,r.h * .2f);
        c->fill("#aaa");

        if(!text.empty()) {
            c->begin();
            f32 b = (r.h - getFontSize()) / 2.f;
            c->rect(r.x + bitPos, r.y + b, 1, getFontSize());
            c->fill("#f00");
        }

        c->fontFace(getFontSize(),text.empty() ? "#aaa" : "#fff");
        if(!text.empty())
            c->textBounds(text.c_str());
        c->fontAlign(hLeft | vBaseline);
        c->text(r.x + x,r.y + r.h / 1.3f,text.empty() ? label.c_str() :text.c_str());
        c->restore();
        */
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

    }

    fun onMouse(f64 _x, f64 _y, i32 button, i32 action, i32 mod) override{
       // m = vec2((f32)_x,(f32)_y);
    }

    fun onMeasure(f32 _w,f32 _h) override{
        this->size(300,getFontSize() * 1.3f);
    }
};

#endif
