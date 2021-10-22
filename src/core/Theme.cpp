#include "Theme.h"


Theme Theme::Dark (){
    return {};
}
Theme Theme::Light(){
    return {};
}

fun Theme::setPrimaryColor     (const str& h){this->primary     = h;}
fun Theme::setSecondaryColor   (const str& h){this->secondary   = h;}
fun Theme::setTextColor        (const str& h){this->text        = h;}
fun Theme::setBaseFont         (const str& h){this->base        = h;}
fun Theme::setFallFont         (const str& h){this->fall        = h;}
fun Theme::setDefaultFontSize  (f32 h){this->def                = h;}
fun Theme::setHeaderFontSize   (f32 h){this->header             = h;}
fun Theme::setRadiusSize       (f32 h){this->radius             = h;}

str Theme::getPrimaryColor     (){return this->primary  ;}
str Theme::getSecondaryColor   (){return this->secondary;}
str Theme::getTextColor        (){return this->text     ;}
str Theme::getBaseFont         (){return this->base     ;}
str Theme::getFallFont         (){return this->fall     ;}
f32 Theme::getDefaultFontSize  (){return this->def      ;}
f32 Theme::getHeaderFontSize   (){return this->header   ;}
f32 Theme::getRadiusSize       (){return this->radius   ;}

f32 Theme::getDefaultFontSize  ()const {return this->def      ;}
f32 Theme::getHeaderFontSize   ()const {return this->header   ;}
f32 Theme::getRadiusSize       ()const {return this->radius   ;}