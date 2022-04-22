#ifndef VIEW_H
#define VIEW_H

#include <graphics/Canvas.h>
#include <utils/TypeUtils.h>

class View{
public:
    View();

    virtual fun onDraw(Canvas*) = 0;
};

#endif // VIEW_H
