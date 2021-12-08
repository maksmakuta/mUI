#ifndef RELATIVELAYOUT_H
#define RELATIVELAYOUT_H

#include "../../view/View.h"

/**
 * RelativeLayout
 * API beta 0.1.0
 * @since 0.6.0
 */
class RelativeLayout : public View{
public:
    /**
     * RelativeLayout
     * @param parent : View* -> parent view for this class
     */
    RelativeLayout(View* parent = null) : View(parent,true){

    }
    /**
     * onDraw -> method for draw child views
     * @param c : Canvas* -> renderer
     */
    fun onDraw(Canvas *c) override{

    }
    /**
     * onMeasure -> used for resize child view and this view (layout)
     * @param w : Float -> width  of parent view
     * @param h : Float -> height of parent view
     */
    fun onMeasure(f32 w, f32 h) override{

    }

};

#endif
