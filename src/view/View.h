#ifndef VIEW_H
#define VIEW_H

#include "../types.h"
#include "Rect.h"

class View{
private:
    Rect r;
public:
    View(){

    }

    // interface

    virtual fun onDraw();
    virtual fun onEvent();

};

#endif
