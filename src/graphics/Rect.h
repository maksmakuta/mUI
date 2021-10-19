#ifndef MUI_RECT_H
#define MUI_RECT_H

#include "../sTypes.h"
#include "../Object.h"

class Rect : public Object{
private:
    f32 rx{0},ry{0},rw{0},rh{0};
public:

    Rect();
    explicit Rect(f32 a);
    Rect(f32 _x,f32 _y,f32 _w,f32 _h);
    Rect(const Rect& r);

    fun set(f32 _a);

    fun x(f32 _x);
    fun y(f32 _y);
    fun w(f32 _w);
    fun h(f32 _h);

    f32 x();
    f32 y();
    f32 w();
    f32 h();

    f32 x()const;
    f32 y()const;
    f32 w()const;
    f32 h()const;

    bool point(f32 x,f32 y);

    virtual str toString();
};


#endif
