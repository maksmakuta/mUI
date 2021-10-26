#ifndef MUI_THEME_H
#define MUI_THEME_H

#include "types.h"

class Theme {
private:
    str primary,secondary,text;     // colors for renderer
    str base,fall;                  // fonts files
    f32 def,header;                 // fonts sizes
    f32 radius;                     // default radius for views
public:
    Theme(){}

    static Theme* Dark ();
    static Theme* Light();

    fun setPrimaryColor     (const str& h);
    fun setSecondaryColor   (const str& h);
    fun setTextColor        (const str& h);
    fun setBaseFont         (const str& h);
    fun setFallFont         (const str& h);
    fun setDefaultFontSize  (f32 h);
    fun setHeaderFontSize   (f32 h);
    fun setRadiusSize       (f32 h);

    str getPrimaryColor     ();
    str getSecondaryColor   ();
    str getTextColor        ();
    str getBaseFont         ();
    str getFallFont         ();
    f32 getDefaultFontSize  ();
    f32 getHeaderFontSize   ();
    f32 getRadiusSize       ();
    f32 getDefaultFontSize  ()const;
    f32 getHeaderFontSize   ()const;
    f32 getRadiusSize       ()const;

};


#endif
