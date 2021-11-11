#ifndef MUI_THEME_H
#define MUI_THEME_H

/**
 * Theme
 * API 1.0
 * @since 0.5.14
 */
class Theme{
private:

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
        return new Theme();
    }
    /**
     * default light theme
     * @return Theme*
     */
    static Theme* Light(){
        return new Theme();
    }


    f32 size = 40.0f;
};

#endif
