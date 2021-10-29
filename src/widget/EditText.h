#ifndef MUI_EDITTEXT_H
#define MUI_EDITTEXT_H

#include "../view/View.h"

enum EditType{
    Line,
    MultiLine,
    Scrollable
};

class EditText : pub View{
priv:
    str text;
    f32 fontSize;
    vec2 p;
    bool focus;
pub:

    explicit EditText() : View(){
        this->setFontSize(24.f);
        this->setText("");
        this->p = vec2(100,getFontSize());
    }

    fun setFontSize(f32 f){
        this->fontSize = f;
    }
    f32 getFontSize(){
        return this->fontSize;
    }

    fun setText(const str& _t){
        this->text = _t;
        onMeasure();
    }
    str getText(){
        return this->text;
    }

    fun onDraw(Canvas *c) override{
        c->begin();
        c->rect(rect().x,rect().y,rect().w,rect().h);
        c->fill("#666");
        c->end(true);

        c->useBaseFont(getFontSize(),"#fff");
        if(!text.empty() || text.size() > 1)
            p = c->textSize(text.c_str());
        c->fontAlign(hLeft | vBaseline);
        c->text(rect().x,rect().y + rect().h / 1.3f,text.c_str());
    }

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod) override{
        if(rect().in(x,y)){
            focus = true;
        }else{
            focus = false;
        }
    }

    fun onKey(u32 codepoint) override{
        if(this->focus){
            std::ostringstream ss;
            ss << (char)codepoint;
            this->text.append(ss.str());
        }
    }

    fun onKey(i32 key, i32 scancode, i32 action, i32 mods) override{
        if(this->focus){
            if(key == GLFW_KEY_BACKSPACE && (action == GLFW_PRESS or action == GLFW_REPEAT)){
                if(text.size() > 0)
                    text.erase(text.end() - 1);
            }
        }
    }

    fun onMeasure() override{
        this->size(p.x,p.y * 1.2f);
    }
};

#endif
