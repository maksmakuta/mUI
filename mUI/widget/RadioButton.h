#ifndef MUI_RADIOBUTTON_H
#define MUI_RADIOBUTTON_H

#include "../view/View.h"
#include "../graphics/utils/MaterialIcons.h"

class OnCheckedChangeListener{
public:
    virtual fun onCheckedChange(View* v,bool checked) = 0; // for RadioButton
    virtual fun onCheckedChange(View* v,View* cView) = 0; // for RadioGroup
};

class RadioButton : public View{
private:
    bool checked = false;
    str text;
    vec2 p;
    OnCheckedChangeListener* l = null;
public:
    RadioButton(const str& t,View* parent) : View(parent){
        this->setText(t);
        this->setChecked(true);
        this->margin(10);
    }

    fun setText(const str& _t){
        this->text = _t;
    }
    str getText(){
        return this->text;
    }
    fun setChecked(bool c){
        this->checked = c;
        if(this->l != null)
            l->onCheckedChange(this,c);
    }

    fun setOnCheckedChangeListener(OnCheckedChangeListener* cl){
        if(cl != null)
            this->l = cl;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();

        if(this->hover()) {
            c->begin();
            c->circle(r.x + r.h / 2.f, r.y + r.h / 2.f, r.h / 2.f);
            c->fill("#099");
            c->end(true);
        }

        Theme *t = getTheme();

        c->fontFace("icons");
        c->fontSize(t->sizeText());
        c->fontFill(t->colorPrimary().c_str());
        c->fontAlign(vMiddle | hCenter);
        c->text(r.x +r.h/2.f,r.y + r.h/2.f, cpToUTF8(checked ? ic_radio_button_on : ic_radio_button_off));

        c->fontFace("roboto");
        c->fontSize(t->sizeText());
        c->fontFill(t->colorText().c_str());
        c->fontAlign(vMiddle | hLeft);
        p = c->textSize(text.c_str());
        c->text(r.x + r.h + 5.f,r.y + r.h/2.f,text.c_str());
    }

    fun onMeasure(f32 _w,f32 _h) override{
        this->size(p.x+48.f,p.y);
    }
};

class RadioGroup : public View{
private:
    OnCheckedChangeListener* l = null;
    i32 selected;
public:
    explicit RadioGroup(View* parent = null) : View(parent,true){
        this->selected = 0;
    }

    fun setOnCheckedChangeListener(OnCheckedChangeListener* cl){
        if(cl != null)
            this->l = cl;
    }

    fun onDraw(Canvas *c) override{
        f32 x = rect().x,y = rect().y;
        for(i32 a = 0;a < (i32)data().size();a++){
            RadioButton* v = (RadioButton*)data()[a];
            Margin m = v->margin();

            x += m.getMarginLeft();
            y += m.getMarginTop();

            v->pos(x,y);
            v->setChecked(a == selected);
            v->onDraw(c);

            x -= m.getMarginLeft();
            y += v->rect().h + m.getMarginBottom();
        }
    }

    fun onMouse(f64 x, f64 y, i32 button, i32 action, i32) override{
        for(i32 a = 0;a < (i32)data().size();a++){
            RadioButton* v = (RadioButton*)data()[a];
            if(v->rect().in(x,y)){
                v->hover(true);
                if(button == MOUSE_LEFT && action == MOUSE_CLICK) {
                    this->selected = a;
                    if(l != null){
                        l->onCheckedChange(this,v);
                    }
                }
            }else{
                v->hover(false);
            }
        }
    }

    fun onMeasure(f32 _w,f32 _h) override{
        f32 w = 0.0f,h = 0.0f;
        if(!data().empty()) {
            for (auto v: data()) {
                v->onMeasure(_w,_h);
                Margin m = v->margin();
                h += m.getMarginTop() + v->rect().h + m.getMarginBottom();
                if(v->rect().w + m.getMarginRight() + m.getMarginLeft()> w)
                    w = v->rect().w + m.getMarginRight() + m.getMarginLeft();
            }
        }
        this->size(w,h);
    }
};

#endif
