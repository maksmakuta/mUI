#ifndef CANVAS_H
#define CANVAS_H

#include "../types.h"

#define rad(x)      x*(NVG_PI/180)
#define deg(x)      x*(180/NVG_PI)

class Canvas{
public:
    explicit Canvas();
    ~Canvas();

};

#endif
