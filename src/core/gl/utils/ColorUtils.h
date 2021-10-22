#ifndef MUI_COLORUTILS_H
#define MUI_COLORUTILS_H


#include "../nanovg.h"
#include "../../types.h"
#include <string>

class ColorUtils{
public:
    static NVGcolor color3u(u32 r,u32 g,u32 b);
    static NVGcolor color4u(u32 r,u32 g,u32 b,u32 a);
    static NVGcolor color3f(f32 r,f32 g,f32 b);
    static NVGcolor color4f(f32 r,f32 g,f32 b,f32 a);
    static NVGcolor color(const char* hex);
    static NVGcolor color(const std::string& h);
private:
    static u32 fHex(char);
};

#endif
