#ifndef MUI_THEME_H
#define MUI_THEME_H

#include "../types.h"

/**
 * Theme
 * API 1.0
 * @since 0.5.14
 */
class Theme{
private:
    str c_primary,c_secondary,c_accent;          // widget colors
    str c_text,c_error,c_background;             // other colors
    f32 s_text = 0.f,s_size = 0.f,s_margin = 0.f;// size
public:
    /**
     * default constructor
     */
    Theme() = default;
    /**
     * default dark theme
     * @return Theme*
     */
    static Theme* Dark(){
        auto t = new Theme();
        t->colorPrimary   ("#6200EE");
        t->colorSecondary ("#03DAC6");
        t->colorAccent    ("#F8CA99");
        t->colorText      ("#fff");
        t->colorError     ("#f41");
        t->colorBackground("#333");
        t->sizeText       (28.f);
        t->sizeDef        (28.f * 1.5f);
        t->sizeMargin     (10.f);
        return t;
    }
    /**
     * default light theme
     * @return Theme*
     */
    static Theme* Light(){
        auto t = new Theme();
        t->colorPrimary   ("#6200EE");
        t->colorSecondary ("#03DAC6");
        t->colorAccent    ("#F8CA99");
        t->colorText      ("#000");
        t->colorError     ("#f41");
        t->colorBackground("#fff");
        t->sizeText       (28.f);
        t->sizeDef        (28.f * 1.5f);
        t->sizeMargin     (10.f);
        return t;
    }

    /**
     *  methods to set colors
     */
    fun colorPrimary    (const str& c){this->c_primary    = c;} // primary          color
    fun colorSecondary  (const str& c){this->c_secondary  = c;} // secondary        color
    fun colorAccent     (const str& c){this->c_accent     = c;} // accent           color
    fun colorText       (const str& c){this->c_text       = c;} // text             color
    fun colorError      (const str& c){this->c_error      = c;} // error            color
    fun colorBackground (const str& c){this->c_background = c;} // background       color

    /**
     *  methods to set sizes
     */
    fun sizeText        (f32 s){this->s_text    = s;} // text       size
    fun sizeDef         (f32 s){this->s_size    = s;} // default    size
    fun sizeMargin      (f32 s){this->s_margin  = s;} // margin     size

    /**
     * methods to get colors
     */
    str colorPrimary    (){return this->c_primary   ;} // primary          color
    str colorSecondary  (){return this->c_secondary ;} // secondary        color
    str colorAccent     (){return this->c_accent    ;} // accent           color
    str colorText       (){return this->c_text      ;} // text             color
    str colorError      (){return this->c_error     ;} // error            color
    str colorBackground (){return this->c_background;} // background       color
    /**
     *  methods to get sizes
     */
    f32 sizeText        (){return this->s_text  ;} // text       size
    f32 sizeDef         (){return this->s_size  ;} // default    size
    f32 sizeMargin      (){return this->s_margin;} // margin     size

};

#endif
