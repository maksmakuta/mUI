#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include "../../graphics/Canvas.h"
#include "../listener/OnClickListener.h"
#include "../listener/OnHoverListener.h"
#include "../listener/OnLongClickListener.h"
#include "../listener/OnKeyListener.h"
#include "../listener/OnMoveListener.h"

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
    bool isContainer;
    struct Rect{
        f32 x,y,w,h;
    }viewRect;
    struct Listeners{
        OnClickListener*        onClick     = null;
        OnLongClickListener*    onLongClick = null;
        OnHoverListener*        onHover     = null;
        OnMoveListener*         onMove      = null;
        OnKeyListener*          onKey       = null;
    } listeners;
    Gravity gravity;
public:
    View();
    View(bool);
    virtual fun onDraw(Canvas* c) = 0;
    virtual fun onResize(f32 _w,f32 _h) = 0;

    bool container();

    Listener* getListener(LISTENER l);

    fun x(f32 _x);
    fun y(f32 _y);
    fun w(f32 _w);
    fun h(f32 _h);

    f32 x();
    f32 y();
    f32 w();
    f32 h();
};


#endif