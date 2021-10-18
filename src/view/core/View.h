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
        f32 x{0},y{0},w{0},h{0};
        f32 t{0},b{0},s{0},e{0}; // margins (top,bottom,start,end)
    } viewRect;
    struct Listeners{
        OnClickListener*        onClick     = null;
        OnLongClickListener*    onLongClick = null;
        OnHoverListener*        onHover     = null;
        OnMoveListener*         onMove      = null;
        OnKeyListener*          onKey       = null;
    } listeners;
    Gravity gravity = Center;
    Visibility visibility = Visible;
public:
    View();
    View(bool);

    virtual fun onDraw(Canvas* c) = 0;
    virtual fun onResize(f32 _w,f32 _h) = 0;

    bool container();

    fun setVisibility(Visibility);
    Visibility getVisibility();

    fun setGravity(Gravity);
    Gravity getGravity();

    Listener* getListener(LISTENER l);
    fun setListener(LISTENER l,Listener* _l);

    fun x(f32 _x);
    fun y(f32 _y);
    fun w(f32 _w);
    fun h(f32 _h);

    fun marginTop   (f32 _t);
    fun marginBottom(f32 _b);
    fun marginStart (f32 _s);
    fun marginEnd   (f32 _e);

    fun margin(f32 _a);

    f32 marginTop   ();
    f32 marginBottom();
    f32 marginStart ();
    f32 marginEnd   ();

    f32 x();
    f32 y();
    f32 w();
    f32 h();
};


#endif