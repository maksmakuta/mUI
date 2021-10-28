#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include <vector>
#include "Rect.h"
#include "../graphics/Canvas.h"
#include "listener/OnClickListener.h"

enum Visibility : i32{
    Gone     ,
    Visible  ,
    Invisible
};

enum Gravity : i32{
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
    OnClickListener* onClick = null;
    i32 ID = 0;

    Rect r;
    Visibility mVisibility;
    Gravity mGravity;

    std::vector<View*> mData{};

public:

    View() : r(0,0,1,1),mVisibility(Visible),mGravity(Center){ }

    fun add(View *v){
        mData.push_back(v);
        onMeasure();
    }

    fun add(View *v, i32 p){
        mData.insert(mData.begin() + p,v);
        onMeasure();
    }

    fun update(View *v, int p){
        if(mData[p] != v && mData[p] != null){
            mData[p] = v;
        }
        onMeasure();
    }

    fun remove(i32 p){
        mData.erase(mData.begin() + p);
        onMeasure();
    }

    fun setVisibility(Visibility v){
        this->mVisibility = v;
    }

    Visibility getVisibility(){
        return this->mVisibility;
    }

    fun setGravity(Gravity v){
        this->mGravity = v;
    }

    Gravity getGravity(){
        return this->mGravity;
    }

    Rect rect(){
        return this->r;
    }

    fun rect(f32 x,f32 y,f32 w,f32 h){
        this->r = Rect(x,y,w,h);
    }

    fun size(f32 w,f32 h){
        this->r.size(w,h);
    }

    fun pos(f32 x,f32 y){
        this->r.pos(x,y);
    }

    i32 id(){
        return this->ID;
    }

    fun id(i32 i){
        this->ID = i;
    }

    std::vector<View*> data(){
        return mData;
    }

    OnClickListener* getOnClickListener(){
        return this->onClick;
    }

    fun setOnClickListener(OnClickListener* l){
        this->onClick = l;
    }

    virtual fun onDraw(Canvas* c){
        if(!mData.empty()){
            for(auto v : mData){
                if(v != null)
                    v->onDraw(c);
            }
        }
    }
    virtual fun onMouse(f64 x, f64 y, i32 button, i32 action, i32 mod){
        if(!mData.empty()){
            for(auto v : mData) {
                if (v != null) {
                    v->onMouse(x, y, button, action, mod);
                    if (v->rect().in((f32)x, (f32)y)) {
                        if (button == MOUSE_LEFT && action == MOUSE_CLICK) {
                            if(v->getOnClickListener() != null)
                                v->getOnClickListener()->onClick(v);
                        }
                    }
                }
            }
        }
    }
    virtual fun onMeasure(){
        if(!mData.empty()){
            for(auto v : mData){
                if(v != null)
                    v->onMeasure();
            }
        }
    }
    virtual fun onKey(i32 key, i32 scancode, i32 action, i32 mods){
        if(!mData.empty()){
            for(auto v : mData){
                if(v != null)
                    v->onKey(key,scancode,action,mods);
            }
        }
    }
    virtual fun onKey(u32 codepoint){
        if(!mData.empty()){
            for(auto v : mData){
                if(v != null)
                    v->onKey(codepoint);
            }
        }
    }
    virtual fun onMouseScroll(f64 dx,f64 dy){
        if(!mData.empty()){
            for(auto v : mData){
                if(v != null)
                    v->onMouseScroll(dx,dy);
            }
        }
    }
};

#endif
