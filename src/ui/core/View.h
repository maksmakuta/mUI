#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include <vector>
#include "../../core/types.h"
#include "../../core/Canvas.h"
#include "../../core/Theme.h"
#include "../../core/utils/vec.h"
#include "Gravity.h"
#include "Visibility.h"


class View {
private:
    i32 id;
    bool inFocus;
    vec4 mRect ,mMargin;
    Gravity mGravity;
    Visibility mVisibility;
public:

    View();

    fun rect    (f32 x,f32 y,f32 w,f32 h);
    fun margin  (f32 l,f32 t,f32 r,f32 b);
    fun margin  (f32 a);
    fun size    (f32 w,f32 h);
    fun pos     (f32 x,f32 y);

    vec2 pos ();
    vec2 size();
    vec4 margin();
    vec4 rect();

    virtual fun onDraw    (Canvas* c);
    virtual fun onMeasure ();
    virtual fun onMouse(f32 x,f32 y,i32 button,i32 action,i32 mod);
    virtual fun onKeyboard(i32 key,i32 scancode,i32 action,i32 mod);
    virtual fun onKeyboard(u32 charcode);
    virtual fun onScroll(f32 x,f32 y);
};


#endif
