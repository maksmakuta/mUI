#ifndef MUI_VIEW_H
#define MUI_VIEW_H

#include <vector>
#include "types.h"
#include "Canvas.h"
#include "Theme.h"

class View {
private:
    std::vector<View*> child;
    Theme *mTheme = null;
public:

    View();

    fun add(View* v);
    fun del(i32 pos);
    fun del(View* v);

    std::vector<View*> getChild();

    fun applyTheme(Theme*);
    Theme* getTheme();

    fun rect  (f32 _x,f32 _y,f32 _w,f32 _h);
    fun margin(f32 _t,f32 _b,f32 _l,f32 _r);
    fun margin(f32 all);

    virtual fun  onDraw         (Canvas* c);
    virtual fun  onMeasure      ();

    f32 x,y,w,h; // rect
    f32 t,b,l,r; // margins

};


#endif
