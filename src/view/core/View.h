#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include "../../graphics/Canvas.h"
#include "../listener/OnClickListener.h"
#include "../listener/OnLongClickListener.h"
#include "../listener/OnKeyListener.h"
#include "../listener/OnMoveListener.h"
#include "../../graphics/Rect.h"

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
    Rect viewRect ,marginRect;
    Gravity gravity = Center;
    Visibility visibility = Visible;

    struct Listeners{
        OnClickListener*        onClick     = null;
        OnLongClickListener*    onLongClick = null;
        OnMoveListener*         onMove      = null;
        OnKeyListener*          onKey       = null;
    } listeners;

public:
    View();
    View(bool);

    virtual fun onDraw(Canvas* c) = 0;
    virtual fun onHover(Canvas* c){ onDraw(c); }
    virtual fun onResize(f32 _w,f32 _h){
        this->viewRect.w(_w);
        this->viewRect.h(_h);
    }

    Rect getViewRect();
    Rect getMarginRect();
    fun setViewRect(const Rect& r);
    fun setMarginRect(const Rect& r);

    bool container();

    fun         setVisibility(Visibility);
    fun         setGravity(Gravity);
    Visibility  getVisibility();
    Gravity     getGravity();

    fun setOnClickListener    (OnClickListener        *_l);
    fun setOnLongClickListener(OnLongClickListener    *_l);
    fun setOnMoveListener     (OnMoveListener         *_l);
    fun setOnKeyListener      (OnKeyListener          *_l);

    OnClickListener    * getOnClickListener    ();
    OnLongClickListener* getOnLongClickListener();
    OnMoveListener     * getOnMoveListener     ();
    OnKeyListener      * getOnKeyListener      ();

    fun margin(f32 _a);
};


#endif