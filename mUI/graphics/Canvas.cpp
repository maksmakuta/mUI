#define NANOVG_GL3_IMPLEMENTATION
#include "Canvas.h"
#include "utils/ColorUtils.h"

Canvas::Canvas(i32 flags){
    this->c = nvgCreateGL3(flags);
}

fun Canvas::beginFrame(f32 w, f32 h,f32 p){
    nvgBeginFrame(this->c,w,h,p);
}

fun Canvas::cancelFrame(){
    nvgCancelFrame(this->c);
}

fun Canvas::endFrame(){
    nvgEndFrame(this->c);
}

fun Canvas::fill(const char* col){
    nvgFillColor(this->c,ColorUtils::color(col));
    nvgFill(this->c);
}

fun Canvas::fill(const str& col){
    nvgFillColor(this->c,ColorUtils::color(col));
    nvgFill(this->c);
}

fun Canvas::stroke(const char* col){
    nvgStrokeColor(this->c,ColorUtils::color(col));
    nvgStroke(this->c);
}

fun Canvas::stroke(const str& col){
    nvgStrokeColor(this->c,ColorUtils::color(col));
    nvgStroke(this->c);
}

fun Canvas::save(){
    nvgSave(this->c);
}

fun Canvas::restore(){
    nvgRestore(this->c);
}

fun Canvas::reset(){
    nvgReset(this->c);
}

fun Canvas::antialias(bool a){
    nvgShapeAntiAlias(this->c,a);
}

fun Canvas::fillColor(Color color){
    nvgFillColor(this->c,color);
}

fun Canvas::fillPaint(Paint paint){
    nvgFillPaint(this->c,paint);
}

fun Canvas::strokeColor(Color color){
    nvgStrokeColor(this->c,color);
}

fun Canvas::strokePaint(Paint paint){
    nvgStrokePaint(this->c,paint);
}

fun Canvas::mitterLimit(f32 limit){
    nvgMiterLimit(this->c,limit);
}

fun Canvas::lineCap(i32 cap){
    nvgLineCap(this->c,cap);
}

fun Canvas::lineJoin(i32 join){
    nvgLineJoin(this->c,join);
}

fun Canvas::transform(f32 _a, f32 _b, f32 _c, f32 _d, f32 _e, f32 _f){
    nvgTransform(this->c,_a,_b,_c,_d,_e,_f);
}

fun Canvas::translate(f32 _x, f32 _y){
    nvgTranslate(this->c,_x,_y);
}

fun Canvas::rotate(float angle){
    nvgRotate(this->c,angle);
}

fun Canvas::skewX(f32 angle){
    nvgSkewX(this->c,angle);
}

fun Canvas::skewY(f32 angle){
    nvgSkewY(this->c,angle);
}

fun Canvas::scale(f32 _x, f32 _y){
    nvgScale(this->c,_x,_y);
}

fun Canvas::currentTransform(f32 *xform){
    nvgCurrentTransform(this->c,xform);
}

fun Canvas::transformIdentity(f32 *mat){
    nvgTransformIdentity(mat);
}

fun Canvas::transformTranslate(f32 *mat, f32 x, f32 y){
    nvgTransformTranslate(mat,x,y);
}

fun Canvas::transformScale(f32 *mat, f32 x, f32 y){
    nvgTransformScale(mat,x,y);
}

fun Canvas::transformRotate(f32 *mat, f32 angle){
    nvgTransformRotate(mat,angle);
}

fun Canvas::transformSkewX(f32 *mat, f32 angle){
    nvgTransformSkewX(mat,angle);
}

fun Canvas::transformSkewY(f32 *mat, f32 angle){
    nvgTransformSkewY(mat,angle);
}

fun Canvas::transformMultiply(f32 *matA, const f32 *matB){
    nvgTransformMultiply(matA,matB);
}

fun Canvas::transformPremultiply(f32 *matA, const f32 *matB){
    nvgTransformPremultiply(matA,matB);
}

i32 Canvas::transformInverse(f32* matA, const f32* matB){
   return nvgTransformInverse(matA,matB);
}

fun Canvas::transformPoint(f32 *dstx, f32 *dsty, const f32 *mat, f32 srcx, f32 srcy){
    nvgTransformPoint(dstx,dsty,mat,srcx,srcy);
}

i32 Canvas::createImage(const char *name, i32 flags){
    return nvgCreateImage(this->c,name,flags);
}

i32 Canvas::createImageMem(i32 flags, unsigned char* imgData, i32 ndata){
    return nvgCreateImageMem(this->c,flags,imgData,ndata);
}

i32 Canvas::createImageRGBA(i32 w, i32 h, i32 flags, unsigned char *data){
    return nvgCreateImageRGBA(this->c,w,h,flags,data);
}

fun Canvas::updateImage(i32 img, unsigned char *data){
    nvgUpdateImage(this->c,img,data);
}

fun Canvas::imageSize(i32 img, i32 *w, i32 *h){
    nvgImageSize(this->c,img,w,h);
}

fun Canvas::deleteImage(i32 img){
    nvgDeleteImage(this->c,img);
}

Paint Canvas::linearGradient(f32 sx, f32 sy, f32 ex, f32 ey, Color a, Color b){
    return nvgLinearGradient(this->c,sx,sy,ex,ey,a,b);
}

Paint Canvas::boxGradient(f32 x, f32 y, f32 w, f32 h, f32 r, f32 f, Color a, Color b){
    return nvgBoxGradient(this->c,x,y,w,h,r,f,a,b);
}

Paint Canvas::radialGradient(f32 cx, f32 cy, f32 ri, f32 ro, Color a, Color b){
    return nvgRadialGradient(this->c,cx,cy,ri,ro,a,b);
}

Paint Canvas::imagePaint(f32 x, f32 y, f32 w, f32 h, f32 angle, i32 img, f32 alpha){
    return nvgImagePattern(this->c,x,y,w,h,angle,img,alpha);
}

fun Canvas::scissor(f32 x, f32 y, f32 w, f32 h){
    nvgScissor(this->c,x,y,w,h);
}

fun Canvas::scissorIntersect(f32 x, f32 y, f32 w, f32 h){
    nvgIntersectScissor(this->c,x,y,w,h);
}

fun Canvas::scissorReset(){
    nvgResetScissor(this->c);
}

fun Canvas::begin(){
    nvgBeginPath(this->c);
}

fun Canvas::close(){
    nvgClosePath(this->c);
}

fun Canvas::moveTo(f32 x, f32 y){
    nvgMoveTo(this->c,x,y);
}

fun Canvas::lineTo(f32 x, f32 y){
    nvgLineTo(this->c,x,y);
}

fun Canvas::bezierTo(f32 c1x,f32 c1y,f32 c2x,f32 c2y,f32 x,f32 y){
    nvgBezierTo(this->c,c1x,c1y,c2x,c2y,x,y);
}

fun Canvas::quadTo(f32 cx, f32 cy, f32 x, f32 y){
    nvgQuadTo(this->c,cx,cy,x,y);
}

fun Canvas::arcTo(f32 x1, f32 y1, f32 x2, f32 y2, f32 r){
    nvgArcTo(this->c,x1,y1,x2,y2,r);
}

fun Canvas::winding(i32 w){
    nvgPathWinding(this->c,w);
}

fun Canvas::arc(f32 x, f32 y, f32 r, f32 s, f32 e, i32 dir){
    nvgArc(this->c,x,y,r,s,e,dir);
}

fun Canvas::rect(f32 x,f32 y,f32 w,f32 h){
    nvgRect(this->c,x,y,w,h);
}

fun Canvas::rect(f32 x,f32 y,f32 w,f32 h,f32 r){
    nvgRoundedRect(this->c,x,y,w,h,r);
}

fun Canvas::rect(f32 x,f32 y,f32 w,f32 h,f32 tl,f32 tr,f32 bl,f32 br){
    nvgRoundedRectVarying(this->c,x,y,w,h,tl,tr,bl,br);
}

fun Canvas::ellipse(f32 x, f32 y, f32 rw, f32 rh){
    nvgEllipse(this->c,x,y,rw,rh);
}

fun Canvas::circle(f32 x, f32 y, f32 r){
    nvgCircle(this->c,x,y,r);
}

i32 Canvas::createFont(const char *filename, const char *fontname){
    return nvgCreateFont(this->c,fontname,filename);
}

i32 Canvas::createFont(const char *filename, const char *fontname, const i32 pos){
    return nvgCreateFontAtIndex(this->c,fontname,filename,pos);
}

i32 Canvas::createFontMem(const char *name, unsigned char *mem, i32 ndata, i32 fdata){
    return nvgCreateFontMem(this->c,name,mem,ndata,fdata);
}

i32 Canvas::createFontMem(const char *name, unsigned char *mem, i32 ndata, i32 fdata,i32 pos){
    return nvgCreateFontMemAtIndex(this->c,name,mem,ndata,fdata,pos);
}

i32 Canvas::addFallbackFont(i32 base, i32 fall){
    return nvgAddFallbackFontId(this->c,base,fall);
}

i32 Canvas::addFallbackFont(const char* base,const char* fall){
    return nvgAddFallbackFont(this->c,base,fall);
}

fun Canvas::resetFallbackFont(i32 base){
    nvgResetFallbackFontsId(this->c,base);
}

fun Canvas::resetFallbackFont(const char* base){
    nvgResetFallbackFonts(this->c,base);
}

fun Canvas::fontSize(f32 s){
    nvgFontSize(this->c,s);
}

fun Canvas::fontBlur(f32 b){
    nvgFontBlur(this->c,b);
}

fun Canvas::fontSpacing(f32 s){
    nvgTextLetterSpacing(this->c,s);
}

fun Canvas::fontHeight(f32 h){
    nvgTextLineHeight(this->c,h);
}

fun Canvas::fontAlign(i32 a){
    nvgTextAlign(this->c,a);
}

fun Canvas::fontFace(i32 f){
    nvgFontFaceId(this->c,f);
}

fun Canvas::fontFace(const char* f){
    nvgFontFace(this->c,f);
}

fun Canvas::text(f32 x, f32 y, const char *text, const char *end){
    nvgText(this->c,x,y,text,end);
}

fun Canvas::text(f32 x, f32 y, f32 w, const char *text, const char *end){
    nvgTextBox(this->c,x,y,w,text,end);
}

f32 Canvas::textBounds(f32 *bounds, f32 x, f32 y, const char *text, const char *end){
    return nvgTextBounds(this->c,x,y,text,end,bounds);
}

fun Canvas::textBounds(f32 *bounds, f32 x, f32 y,f32 w, const char *text, const char *end){
    nvgTextBoxBounds(this->c,x,y,w,text,end,bounds);
}

fun Canvas::textMetrics(f32 *a, f32 *d, f32 *l){
    nvgTextMetrics(this->c,a,d,l);
}
