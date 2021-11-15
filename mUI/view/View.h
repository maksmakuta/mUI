#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include <vector>
#include "Rect.h"
#include "Margin.h"
#include "../graphics/Canvas.h"
#include "listener/OnClickListener.h"
#include "Measure.h"

#include "../app/Theme.h"

#define UNSIZE -1

enum Visibility{
    Gone     ,
    Visible  ,
    Invisible
};

enum Gravity {
    Center            ,
    Center_Vertical   ,
    Center_Horizontal ,
    Top               ,
    Bottom            ,
    Left              ,
    Right             ,
    Start             ,
    End
};

class View{
private:
    Rect        vRect;
    Margin      vMargin;
    Gravity     vGravity;
    Visibility  vVisibility;
    Measure mMeasure;
    vec2 fixedSize,contentSize;
    i32 id;
    bool isLayout,isHover;

    std::vector<View*> child;
    View* parent = null;
    Theme* theme = null;
public:

    View(View *parent) : View(parent,false){ }

    View(View *parent, bool _layout){
        this->visibility(Visible);
        this->setParent(parent);
        this->layout(_layout);
        this->measure(Content,Content);
        this->hover(false);
        if(getParent() != null){
            getParent()->push(this);
        }
    }

    Theme* getTheme(){
        return this->theme;
    }

    fun setTheme(Theme* t){
        if(this->theme == null)
            this->theme = t;
        if(!child.empty() && layout()){
            for(auto v : child){
                if(v != null)
                    v->setTheme(t);
            }
        }
    }

    std::vector<View*> data(){return this->child;}

    fun push(View* v){
        if(this->layout())
            child.push_back(v);
    }

    View* at(i32 p){
        return child[p];
    }

    fun fixed(f32 w,f32 h){
        this->fixedSize = vec2(w,h);
    }

    fun content(f32 w,f32 h){
        this->contentSize = vec2(w,h);
    }
    fun content(vec2 s){
        this->contentSize = s;
    }
    vec2 fixed(){
        return this->fixedSize;
    }

    fun     setParent(View* p)  {
        this->parent = p;
    }
    View*   getParent()         {
        return this->parent;
    }
    Rect    rect()              {
        return this->vRect;
    }
    Margin  margin()            {
        return this->vMargin;
    }
    bool    layout()            {
        return this->isLayout;
    }
    fun     layout(bool l)      {
        this->isLayout = l;
    }
    Gravity gravity()           {
        return this->vGravity;
    }
    fun     gravity(Gravity g){
        this->vGravity = g;
    }
    Visibility  visibility(){
        return this->vVisibility;
    }
    fun         visibility(Visibility v){
        this->vVisibility = v;
    }
    fun measure(MeasureSize _w,MeasureSize _h){
        this->mMeasure = Measure(_w,_h);
    }
    Measure measure(){
        return this->mMeasure;
    }
    fun margin(f32 a){
        margin(a,a,a,a);
    }
    fun margin(f32 t,f32 b,f32 r,f32 l){
        this->vMargin = Margin(t,b,r,l);
    }

    fun marginTop(f32 t){
        this->vMargin.setMarginTop(t);
    }
    fun marginBottom(f32 b){
        this->vMargin.setMarginBottom(b);
    }
    fun marginLeft(f32 l){
        this->vMargin.setMarginLeft(l);
    }
    fun marginRight(f32 r){
        this->vMargin.setMarginRight(r);
    }

    f32 marginTop(){
        return this->vMargin.getMarginTop();
    }
    f32 marginBottom(){
        return this->vMargin.getMarginBottom();
    }
    f32 marginLeft(){
        return this->vMargin.getMarginLeft();
    }
    f32 marginRight(){
        return this->vMargin.getMarginRight();
    }

    fun size(f32 w,f32 h){
        this->vRect.size(w,h);
    }

    fun pos(f32 x,f32 y){
        this->vRect.pos(x,y);
    }

    bool hover(){
        return this->isHover;
    }
    fun hover(bool h){
        this->isHover = h;
    }

    virtual fun onDraw(Canvas* c){
        if(!child.empty() && layout()){
            for(auto v : child){
                if(v != null)
                    v->onDraw(c);
            }
        }
    }
    virtual fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod){
        if (this->rect().in((f32)x, (f32)y)) {
            this->isHover = true;
        }else{
            this->isHover = false;
        }

        if(!child.empty() && layout()){
            for(auto v : child) {
                if (v != null) {
                    v->onMouse(x, y, button, action, mod);
                    if (v->rect().in((f32)x, (f32)y)) {
                        this->hover(true);
                    //    if (button == MOUSE_LEFT && action == MOUSE_CLICK) {
                    //        if(v->getOnClickListener() != null)
                    //            v->getOnClickListener()->onClick(v);
                    //    }
                    }else{
                        this->hover(false);
                    }
                }
            }
        }
    }

    virtual fun onMeasure(f32 w,f32 h){
        f32 s = this->getTheme() == null ? 0.0f : this->getTheme()->sizeDef();
        f32 vw,vh;
        switch (this->measure().getW()) {
            case Parent  : vw = w;                  break;
            case Content : vw = contentSize.x + s;  break;
            case Fixed   : vw = fixed().x;          break;
        }
        switch (this->measure().getH()) {
            case Parent  : vh = h;                  break;
            case Content : vh = contentSize.y + s;  break;
            case Fixed   : vh = fixed().y;          break;
        }
        this->size(vw,vh);

        if(!child.empty() && layout()){
            for(auto v : child){
                if(v != null)
                    v->onMeasure(w,h);
            }
        }
    }
    virtual fun onKey(i32 key, i32 scancode, i32 action, i32 mods){
        if(!child.empty() && layout()){
            for(auto v : child){
                if(v != null)
                    v->onKey(key,scancode,action,mods);
            }
        }
    }
    virtual fun onKey(u32 codepoint){
        if(!child.empty() && layout()){
            for(auto v : child){
                if(v != null)
                    v->onKey(codepoint);
            }
        }
    }
    virtual fun onMouseScroll(f64 dx,f64 dy){
        if(!child.empty() && layout()){
            for(auto v : child){
                if(v != null)
                    v->onMouseScroll(dx,dy);
            }
        }
    }

    virtual ~View(){
        delete parent;
        delete theme;
    }
};

#endif
