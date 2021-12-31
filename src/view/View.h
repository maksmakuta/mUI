#ifndef VIEW_H
#define VIEW_H

#include "../types.h"

class View{

public:
    View(){

    }

    // interface

    virtual fun onDraw();
    virtual fun onEvent();

};

#endif
