#ifndef MUI_DRAWABLE_H
#define MUI_DRAWABLE_H

#include "core/View.h"

class Drawable : public View{
private:
    struct NSVGimage* image;
public:

    Drawable(const std::string& svg);

    fun onResize(f32 _w, f32 _h) override;
    fun onDraw(Canvas *c) override;
};


#endif
