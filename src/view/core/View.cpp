#include "View.h"

View::View() : View(false){}
View::View(bool b){this->isContainer = b;}
bool View::container(){return isContainer;}

Rect View::getViewRect()    {return this->viewRect;  }
Rect View::getMarginRect()  {return this->marginRect;}

fun View::setViewRect  (const Rect& r){this->viewRect   = r;}
fun View::setMarginRect(const Rect& r){this->marginRect = r;}

fun View::setOnClickListener    (OnClickListener        *_l){this->listeners.onClick      = _l;}
fun View::setOnLongClickListener(OnLongClickListener    *_l){this->listeners.onLongClick  = _l;}
fun View::setOnMoveListener     (OnMoveListener         *_l){this->listeners.onMove       = _l;}
fun View::setOnKeyListener      (OnKeyListener          *_l){this->listeners.onKey        = _l;}

OnClickListener    * View::getOnClickListener    (){return this->listeners.onClick;       }
OnLongClickListener* View::getOnLongClickListener(){return this->listeners.onLongClick;   }
OnMoveListener     * View::getOnMoveListener     (){return this->listeners.onMove;        }
OnKeyListener      * View::getOnKeyListener      (){return this->listeners.onKey;         }

fun         View::setVisibility(Visibility v)   {this->visibility = v;}
fun         View::setGravity(Gravity g)         {this->gravity = g;}
Visibility  View::getVisibility()               {return this->visibility;}
Gravity     View::getGravity()                  {return this->gravity;}

fun View::margin(f32 a){
    this->marginRect.set(a);
}
