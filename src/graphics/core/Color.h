#ifndef COLOR_H
#define COLOR_H

#include "../../types.h"
#include <glm/glm.hpp>

class Color{
private:
    f32 r,g,b,a;
public:
    Color() : Color("#fff"){/* ... */}
    Color(f32 a) : Color(a,a,a){/* ... */}
    Color(f32 _r,f32 _g,f32 _b) : Color(_r,_g,_b,1.0f){/* ... */}
    Color(f32 _r,f32 _g,f32 _b,f32 _a){
        init(_r,_g,_b,_a);
    }

    Color(u32 a) : Color(a,a,a){/* ... */}
    Color(u32 _r,u32 _g,u32 _b) : Color(_r,_g,_b,255){/* ... */}
    Color(u32 _r,u32 _g,u32 _b,u32 _a){
        init(utof(_r),utof(_g),utof(_b),utof(_a));
    }

    Color(const str& hex){
        int data[4];
        int s = hex.size() - 1;
        for(int & i : data)
            i = 255;

        switch (s - 1) {
            case 3: // #abc | #rgb
                for(int i = 0;i < 3;i++){
                    data[i] = fHex(hex[i+1]) * 16 + 15;
                }
                break;
            case 4: // #abcd | #rgba
                for(int i = 0;i < 4;i++){
                    data[i] = fHex( hex[i+1]) * 16 + 15;
                }
                break;
            case 6: // #123456 | #rrggbb
                for(int i = 0;i < 3;i++){
                    data[i] = fHex(hex[2*i+1]) * 16 + fHex(hex[2*i+2]);
                }
                break;
            case 8: // #12345678 | #rrggbbaa
                for(int i = 0;i < 4;i++){
                    data[i] = fHex(hex[2*i+1]) * 16 + fHex(hex[2*i+2]);
                }
                break;
          }
          init(utof(data[0]),utof(data[1]),utof(data[2]),utof(data[3]));
    }

    glm::vec4 color(){
        return {r,g,b,a};
    }

private:
    f32 utof(u32 var){
        return (f32)(var % 256) / 255.f;
    }
    fun init(f32 a,f32 b,f32 c,f32 d){
        this->r = a;
        this->g = b;
        this->b = c;
        this->a = d;
    }
    u32 fHex(char _c){
        switch(_c) {
            case '0':           return  0;
            case '1':           return  1;
            case '2':           return  2;
            case '3':           return  3;
            case '4':           return  4;
            case '5':           return  5;
            case '6':           return  6;
            case '7':           return  7;
            case '8':           return  8;
            case '9':           return  9;
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
