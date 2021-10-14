#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include "../../graphics/Canvas.h"
#include "../listener/OnClickListener.h"
#include "../../app/Activity.h"

enum LISTENER{
    OnCLick     = 0,
    OnLongClick = 1,
    OnHover     = 2,
    OnMove      = 3,
    OnKey       = 4
};

enum Visibility{
    Visible,
    Invisible,
    Gone
};

enum Gravity{
    Start,
    End,
    Center,
    CenterVerticall,
    CenterHorizontal,
    Top,
    Bottom
};

class View {
private:
    f32 x,y,w,h;
public:
    View();

    virtual fun onDraw(Canvas* c) = 0;
};


#endif