#ifndef VIEW_H
#define VIEW_H

#include <types.h>
#include <view/Rect.h>
#include <view/event/Event.h>
#include <graphics/Canvas.h>

class View{
private:
    Rect r;
public:
    View(){

    }

    // interface

    virtual fun onDraw(Canvas*);
    virtual fun onEvent(Event*);

};

#endif
