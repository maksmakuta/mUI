#ifndef MUI_ACTIVITY_H
#define MUI_ACTIVITY_H

#include "../types.h"
#include "../view/View.h"

class Activity{
private:
    View* mContent = null;
    View* mToast = null;
    vec2 wp;
public:
    Activity(){ }

    fun size(const vec2& p){this->wp = p;}
    vec2 size(){return this->wp;}

    fun setContentView(View* v){
        this->mContent = v;
    }

    fun toast(View* v){
        this->mToast = v;
    }

    View* toast(){
        return this->mToast;
    }

    View* content(){return this->mContent;}

    virtual fun onCreate() = 0;

};

#endif
