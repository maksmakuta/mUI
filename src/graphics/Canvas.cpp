#define NANOVG_GL3_IMPLEMENTATION
#include "Canvas.h"

Canvas::Canvas(){
    this->c = nvgCreateGL3(NVGcreateFlags::NVG_STENCIL_STROKES);
    this->setupText("/usr/share/fonts/TTF/JetBrainsMono-Regular.ttf","font");
}

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

fun Canvas::beginFrame(f32 w, f32 h,f32 p){
    nvgBeginFrame(this->c,w,h,p);
}
fun Canvas::endFrame(){
    nvgEndFrame(this->c);
}


fun Canvas::setupText(const char* face,const char* name){
    // /usr/share/fonts/TTF/JetBrainsMono-Regular.ttf
    this->font = nvgCreateFont(c, name, face);
    if (this->font == -1) {
        printf("Could not add font icons.\n");
    }
}

fun Canvas::color3u(u32 r,u32 g,u32 b)          {this->col = ColorUtils::color3u(r,g,b);    }
fun Canvas::color4u(u32 r,u32 g,u32 b,u32 a)    {this->col = ColorUtils::color4u(r,g,b,a);  }
fun Canvas::color3f(f32 r,f32 g,f32 b)          {this->col = ColorUtils::color3f(r,g,b);    }
fun Canvas::color4f(f32 r,f32 g,f32 b,f32 a)    {this->col = ColorUtils::color4f(r,g,b,a);  }
fun Canvas::color(const char* hex)              {this->col = ColorUtils::color(hex);        }

fun Canvas::drawCircle(f32 x,f32 y,f32 r){
    nvgBeginPath(this->c);
    nvgCircle(this->c, x,y,r);
    nvgFillColor(this->c, this->col);
    nvgFill(this->c);
}

fun Canvas::drawEllipse(f32 x, f32 y, f32 cx, f32 cy) {
    nvgBeginPath(this->c);
    nvgEllipse(this->c, x,y,cx,cy);
    nvgFillColor(this->c, this->col);
    nvgFill(this->c);
}
fun Canvas::drawArc(f32 x,f32 y,f32 r,f32 s,f32 e){
    nvgBeginPath(this->c);
    nvgArc(this->c,x,y,r,s,e,NVG_CCW);
    nvgFillColor(this->c, this->col);
    nvgFill(this->c);
}
fun Canvas::drawRRect(f32 x, f32 y, f32 w,f32 h,f32 r){
    nvgBeginPath(this->c);
    nvgRoundedRect(this->c,x,y,w,h,r);
    nvgFillColor(this->c, this->col);
    nvgFill(this->c);

}
fun Canvas::drawRRect(f32 x, f32 y, f32 w,f32 h,f32 tl,f32 tr, f32 bl, f32 br){
    nvgBeginPath(this->c);
    nvgRoundedRectVarying(this->c,x,y,w,h,tl,tr,br,bl);
    nvgFillColor(this->c, this->col);
    nvgFill(this->c);
}

fun Canvas::drawText(f32 x,f32 y,const char* data,const char* fnt,f32 s = 16.0f){
    nvgFontSize(c, s);
    nvgFontFace(c, fnt);
    nvgFillColor(c, this->col);

    nvgTextAlign(c,NVG_ALIGN_CENTER);
    nvgText(c, x,y+s*0.5f,data, NULL);
}

fun Canvas::drawRect(f32 x, f32 y, f32 w,f32 h){
    nvgBeginPath(this->c);
    nvgRect(this->c, x,y,w,h);
    nvgFillColor(this->c, this->col);
    nvgFill(this->c);
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