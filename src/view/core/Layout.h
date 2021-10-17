#ifndef MUI_LAYOUT_H
#define MUI_LAYOUT_H

#include "View.h"
#include <vector>

class Layout : public View{
public:
    std::vector<View*> childs;
public:
    Layout();
    fun add(View* v);
    fun remove(View* v);
    fun update(View* v);

    std::vector<View*> child();

    virtual fun onDraw(Canvas *c) = 0;
    virtual fun onResize(f32 w,f32 h) = 0;

};

#endif
