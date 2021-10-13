#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include "../graphics/Canvas.h"
#include "../graphics/Rect.h"
#include "listener/OnClickListener.h"
#include "../app/Activity.h"

enum LISTENER{
    OnCLick
};

class View {
private:
    i32 id;
    Rect r;
    Listener* l = null;
public:
    View();
    explicit View(i32 _i);
    View(f32 x,f32 y,f32 w,f32 h);

    virtual fun onDraw(Canvas*) = 0;
    virtual fun onHover(Canvas*) = 0;

    fun setOnClickListener(Listener*);

    Listener* listeners(LISTENER);
    fun setViewRect(f32 x,f32 y,f32 w,f32 h);
    Rect getViewRect();

};


#endif