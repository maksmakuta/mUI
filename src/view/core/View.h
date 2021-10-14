#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include "../../graphics/Canvas.h"
#include "../../graphics/Rect.h"
#include "../listener/OnClickListener.h"
#include "../../app/Activity.h"

enum LISTENER{
    OnCLick
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
    Bottom,
    Default = Center
};

class View {
private:

public:
    View();
};


#endif