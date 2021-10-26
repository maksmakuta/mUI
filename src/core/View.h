#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include <vector>
#include "types.h"
#include "Canvas.h"
#include "Theme.h"
#include "utils/vec.h"

class View {
private:
    std::vector<View*> child;
    Theme *mTheme = null;
    vec4 mRect ,mMargin;
    bool isContainer = false;
public:

    View(bool container);

    fun add(View* v);
    fun del(i32 pos);
    fun del(View* v);

    std::vector<View*> getChild();

    fun rect    (f32 x,f32 y,f32 w,f32 h);
    fun margin  (f32 l,f32 t,f32 r,f32 b);
    fun margin  (f32 a);
    fun size    (f32 w,f32 h);
    fun pos     (f32 x,f32 y);

    vec2 pos ();
    vec2 size();
    vec4 margin();
    vec4 rect();

    fun applyTheme(Theme*);
    Theme* getTheme();

    virtual fun onDraw    (Canvas* c);
    virtual fun onMeasure ();
    virtual fun onMouse(f32 x,f32 y,i32 button,i32 action,i32 mod);
    virtual fun onKeyboard(i32 key,i32 scancode,i32 action,i32 mod);
    virtual fun onKeyboard(u32 charcode);
    virtual fun onScroll(f32 x,f32 y);
};


#endif
