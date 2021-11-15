#ifndef MUI_COLORUTILS_H
#define MUI_COLORUTILS_H

#include "../nanovg/nanovg.h"
#include "../../types.h"
#include <cstring>
#include <sstream>

class ColorUtils{
public:
    static NVGcolor color3u(u32 r,u32 g,u32 b){
        return nvgRGB(r,g,b);
    }
    static NVGcolor color4u(u32 r,u32 g,u32 b,u32 a){
        return  nvgRGBA(r,g,b,a);
    }
    static NVGcolor color3f(f32 r,f32 g,f32 b){
        return  nvgRGBf(r,g,b);
    }
    static NVGcolor color4f(f32 r,f32 g,f32 b,f32 a){
        return  nvgRGBAf(r,g,b,a);
    }

    static str inverse(const str& hex){
        u32 data[4];
        NVGcolor tmp = color(hex);
        data[0] = abs((i32)(255*(1.0f - tmp.r)));
        data[1] = abs((i32)(255*(1.0f - tmp.r)));
        data[2] = abs((i32)(255*(1.0f - tmp.b)));
        data[3] = abs((i32)(255*(1.0f - tmp.a)));
        std::stringstream ss;
        ss << "#" << std::hex << data[0] << data[1] << data[2] << data[3];
        return ss.str();
    }

    static NVGcolor color(const std::string &h) {
        return color(h.c_str());
    }
    static NVGcolor color(const char* hex){
        u32 data[4];

        for(u32 & i : data)
            i = 255;

        switch (strlen(hex) - 1) {
            case 3: // #abc
                for(i32 i = 0;i < 3;i++){
                    data[i] = fHex(hex[i+1]) * 16 + 15;
                }
                break;
            case 4: // #abcd
                for(i32 i = 0;i < 4;i++){
                    data[i] = fHex( hex[i+1]) * 16 + 15;
                }
                break;
            case 6: // #123456
                for(i32 i = 0;i < 3;i++){
                    data[i] = fHex(hex[2*i+1]) * 16 + fHex(hex[2*i+2]);
                }
                break;
            case 8: // #12345678
                for(i32 i = 0;i < 4;i++){
                    data[i] = fHex(hex[2*i+1]) * 16 + fHex(hex[2*i+2]);
                }
                break;
        }

        return color4u(data[0],data[1],data[2],data[3]);
    }

private:
    static u32 fHex(char _c){
        switch(_c) {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            case 'a': case 'A': return 10;
            case 'b': case 'B': return 11;
            case 'c': case 'C': return 12;
            case 'd': case 'D': return 13;
            case 'e': case 'E': return 14;
            case 'f': case 'F': return 15;
            default: return  -1;
        }
    }
};

#endif
