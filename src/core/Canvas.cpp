#define NANOVG_GL3_IMPLEMENTATION
#include "Canvas.h"

Canvas::Canvas(i32 flags){
    this->c = nvgCreateGL3(flags);
    this->initFont("../assets/fonts/Roboto/Roboto-Regular.ttf","roboto");
    this->initFont("../assets/fonts/Noto_Sans/NotoSans-Regular.ttf","noto");
}

fun Canvas::beginFrame(f32 w, f32 h,f32 p){
    nvgBeginFrame(this->c,w,h,p);
}
fun Canvas::endFrame(){
    nvgEndFrame(this->c);
}

fun Canvas::rect(f32 x, f32 y, f32 w,f32 h){
    nvgRect(this->c, x,y,w,h);
}
fun Canvas::circle(f32 x,f32 y,f32 r){
    nvgCircle(this->c,x,y,r);
}
fun Canvas::ellipse(f32 x,f32 y,f32 cx,f32 cy){
    nvgEllipse(this->c,x,y,cx,cy);
}
fun Canvas::arc(f32 x,f32 y,f32 r,f32 s,f32 e,bool _c = true){
    nvgArc(this->c,x,y,r,s,e,_c ? NVG_CW : NVG_CCW);
}
fun Canvas::rect(f32 x, f32 y, f32 w,f32 h,f32 r){
    nvgRoundedRect(this->c,x,y,w,h,r);
}
fun Canvas::rect(f32 x, f32 y, f32 w,f32 h,f32 tl,f32 tr, f32 bl, f32 br){
    nvgRoundedRectVarying(this->c,x,y,w,h,tl,tr,br,bl);
}

fun Canvas::begin(){
    nvgBeginPath(this->c);
}
fun Canvas::end(bool f = true) {
    if (f) {
        nvgFillColor(this->c, this->col);
        nvgFill(this->c);
    }else{
        nvgStrokeColor(this->c, this->col);
        nvgStroke(this->c);
    }
}

fun Canvas::lineWidth(f32 w){
    nvgStrokeWidth(this->c,w);
}

fun Canvas::beginPath(){
    nvgBeginPath(this->c);
}
fun Canvas::moveTo(f32 x,f32 y){
    nvgMoveTo(this->c,x,y);
}
fun Canvas::lineTo(f32 x,f32 y){
    nvgLineTo(this->c,x,y);
}
fun Canvas::bezierTo(f32 c1x, f32 c1y, f32 c2x, f32 c2y, f32 x, f32 y){
    nvgBezierTo(this->c,c1x,c1y,c2x,c2y,x,y);
}
fun Canvas::quadTo(f32 cx, f32 cy, f32 x, f32 y){
    nvgQuadTo(this->c,cx,cy,x,y);
}
fun Canvas::arcTo(f32 x1, f32 y1, f32 x2, f32 y2, f32 radius){
    nvgArcTo(this->c,x1,y1,x2,y2,radius);
}
fun Canvas::endPath(){
    nvgClosePath(this->c);
}

fun Canvas::windingPath(int v){
    nvgPathWinding(this->c,v);
}

fun Canvas::fill(const char* hex){
    this->col = ColorUtils::color(hex);
}
fun Canvas::fill(NVGcolor color){
    this->col = color;
}

fun Canvas::fontFill(const char* col){
    nvgFillColor(this->c,ColorUtils::color(col));
}


fun Canvas::initFont(const char* f,const char* n){
    nvgCreateFont(this->c,n,f);
}
fun Canvas::allocateFont(i32 size){
    this->fontN = size;
    this->font = new i32[size];
}
fun Canvas::initFont(const char* f,i32 id){
    if(this->font != null && (id >= 0 && id < fontN) ){
        str n = "font" + std::to_string(id);
        this->font[id] = nvgCreateFont(this->c, n.c_str(), f);
    }
}

fun Canvas::fontFace(const char* fontname){
    nvgFontFace(this->c,fontname);
}
fun Canvas::fontFace(i32 fontID){
    if(this->font != null && (fontID >= 0 && fontID < fontN) )
        nvgFontFaceId(this->c,font[fontID]);
}

fun Canvas::fontSize(f32 s){
    nvgFontSize(this->c,s);
}
fun Canvas::fontBlur(f32 b){
    nvgFontBlur(this->c,b);
}
fun Canvas::fontAlign(i32 e){
    nvgTextAlign(this->c,e);
}

fun Canvas::text    (f32 x,f32 y,const char* _text){
    nvgText(this->c,x,y,_text,null);
}
fun Canvas::textBox (f32 x,f32 y,f32 w,const char* _text){
    nvgTextBox(this->c,x,y,w,_text,null);
}

f32* Canvas::textBounds(f32 x,f32 y,const char* _text){
    f32 *bound = new f32[4];
    nvgTextBounds(this->c,x,y,_text,null,bound);
    return bound;
}
f32* Canvas::textBoxBounds(f32 x,f32 y,f32 w,const char* _text){
    f32* bound = new f32[4];
    nvgTextBoxBounds(this->c,x,y,w,_text,null,bound);
    return bound;
}
fun Canvas::rotateRad(f32 rad){
    nvgRotate(this->c,rad);
}
fun Canvas::rotateDeg(f32 deg){
    nvgRotate(this->c, nvgDegToRad(deg));
}
fun Canvas::translate(f32 x,f32 y){
    nvgTranslate(this->c,x,y);
}
fun Canvas::scale(f32 x,f32 y){
    nvgScale(this->c,x,y);
}
fun Canvas::reset(){
    nvgResetTransform(this->c);
}

fun Canvas::apply(Theme* t){this->theme = t;}
Theme* Canvas::getTheme(){return this->theme;}

fun Canvas::save(){
    nvgSave(this->c);
}
fun Canvas::restore(){
    nvgRestore(this->c);
}