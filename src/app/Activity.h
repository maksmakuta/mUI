#ifndef MUI_ACTIVITY_H
#define MUI_ACTIVITY_H

#include "../types.h"
#include "../view/View.h"


class Activity{
private:
    View* mContent = null;
public:
    Activity(){ }

    fun setContentView(View* v){
        this->mContent = v;
    }

    View* content(){return this->mContent;}

    virtual fun onCreate(){

    }

};

#endif
