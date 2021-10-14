#include <cstring>
#include "ColorUtils.h"

NVGcolor ColorUtils::color3u(u32 r,u32 g,u32 b){
    return nvgRGB(r,g,b);
}
NVGcolor ColorUtils::color4u(u32 r,u32 g,u32 b,u32 a){
    return  nvgRGBA(r,g,b,a);
}
NVGcolor ColorUtils::color3f(f32 r,f32 g,f32 b){
    return  nvgRGBf(r,g,b);
}
NVGcolor ColorUtils::color4f(f32 r,f32 g,f32 b,f32 a){
    return  nvgRGBAf(r,g,b,a);
}

NVGcolor ColorUtils::color(const std::string &h) {
    return color(h.c_str());
}
NVGcolor ColorUtils::color(const char* hex){
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


u32 ColorUtils::fHex(char _c){
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