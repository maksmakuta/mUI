#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include "../graphics/Canvas.h"

class View {
private:
    i32 id;
public:
    View();
    View(i32 _i);

    virtual fun onDraw(Canvas*) = 0;

};


#endif
