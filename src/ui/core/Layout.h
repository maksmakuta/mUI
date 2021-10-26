#ifndef MUI_LAYOUT_H
#define MUI_LAYOUT_H

#include "View.h"

class Layout {
private:
    std::vector<View*> child;
public:
    Layout(){

    }


    fun add(View* v);
    fun del(i32 pos);
    fun del(View* v);

    std::vector<View*> getChild();
};


#endif