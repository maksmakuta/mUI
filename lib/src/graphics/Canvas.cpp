#include <graphics/Canvas.h>
#define NANOVG_GL3
#include <graphics/nanovg/nanovg_gl.h>

Canvas::Canvas(){
    this->ctx = nvgCreateGL3(NVG_ANTIALIAS);
}
Canvas::~Canvas(){
    nvgDeleteGL3(this->ctx);
}
fun Canvas::beginFrame(f32 w,f32 h,f32 pRatio){
//    nvgBeginFrame(this->ctx,w,h,pRatio);
}
fun Canvas::cancelFrame(){
//    nvgCancelFrame(this->ctx);
}
fun Canvas::endFrame(){
//    nvgEndFrame(this->ctx);
}/*
fun Canvas::globalCompositeOperation(int op){
    nvgGlobalCompositeOperation(this->ctx,op);
}
fun Canvas::globalCompositeBlendFunc(int sfactor, int dfactor){
    nvgGlobalCompositeBlendFunc(this->ctx,sfactor,dfactor);
}
fun Canvas::globalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha){
    nvgGlobalCompositeBlendFuncSeparate(this->ctx,srcRGB,dstRGB,srcAlpha,dstAlpha);
}
fun Canvas::save(){
    nvgSave(this->ctx);
}
fun Canvas::restore(){
    nvgRestore(this->ctx);
}
fun Canvas::reset(){
    nvgReset(this->ctx);
}
fun Canvas::shapeAntiAlias(int enabled){
    nvgShapeAntiAlias(this->ctx,enabled);
}
fun Canvas::strokeColor(NVGcolor color){
    nvgStrokeColor(this->ctx,color);
}
fun Canvas::strokePaint(NVGpaint paint){
    nvgStrokePaint(this->ctx,paint);
}
fun Canvas::fillColor(NVGcolor color){
    nvgFillColor(this->ctx,color);
}
fun Canvas::fillPaint(NVGpaint paint){
    nvgFillPaint(this->ctx,paint);
}
fun Canvas::miterLimit(float limit){
    nvgMiterLimit(this->ctx,limit);
}
fun Canvas::strokeWidth(float size){
    nvgStrokeWidth(this->ctx,size);
}
fun Canvas::lineCap(int cap){
    nvgLineCap(this->ctx,cap);
}
fun Canvas::lineJoin(int join){
    nvgLineJoin(this->ctx,join);
}
fun Canvas::globalAlpha(float alpha){
    nvgGlobalAlpha(this->ctx,alpha);
}
fun Canvas::resetTransform(){
    nvgResetTransform(this->ctx);
}
fun Canvas::transform(float a, float b, float c, float d, float e, float f){
    nvgTransform(this->ctx,a,b,c,d,e,f);
}
fun Canvas::translate(float x, float y){
    nvgTranslate(this->ctx,x,y);
}
fun Canvas::rotate(float angle){
    nvgRotate(this->ctx,angle);
}
fun Canvas::skewX(float angle){
    nvgSkewX(this->ctx,angle);
}
fun Canvas::skewY(float angle){
    nvgSkewY(this->ctx,angle);
}
fun Canvas::scale(float x, float y){
    nvgScale(this->ctx,x,y);
}
fun Canvas::currentTransform(float* xform){
    nvgCurrentTransform(this->ctx,xform);
}
fun Canvas::transformIdentity(float* dst){
    nvgTransformIdentity(dst);
}
fun Canvas::transformTranslate(float* dst, float tx, float ty){
    nvgTransformTranslate(dst,tx,ty);
}
fun Canvas::transformScale(float* dst, float sx, float sy){
    nvgTransformScale(dst,sx,sy);
}
fun Canvas::transformRotate(float* dst, float a){
    nvgTransformRotate(dst,a);
}
fun Canvas::transformSkewX(float* dst, float a){
    nvgTransformSkewX(dst,a);
}
fun Canvas::transformSkewY(float* dst, float a){
    nvgTransformSkewY(dst,a);
}
fun Canvas::transformMultiply(float* dst, const float* src){
    nvgTransformMultiply(dst,src);
}
fun Canvas::transformPremultiply(float* dst, const float* src){
    nvgTransformPremultiply(dst,src);
}
i32 Canvas::transformInverse(float* dst, const float* src){
    return nvgTransformInverse(dst,src);
}
fun Canvas::transformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy){
    nvgTransformPoint(dstx,dsty,xform,srcx,srcy);
}
i32 Canvas::createImage(const char* filename, int imageFlags){
    return nvgCreateImage(this->ctx,filename,imageFlags);
}
i32 Canvas::createImageMem(int imageFlags, unsigned char* data, int ndata){
    return nvgCreateImageMem(this->ctx,imageFlags,data,ndata);
}
i32 Canvas::createImageRGBA(int w, int h, int imageFlags, const unsigned char* data){
    return nvgCreateImageRGBA(this->ctx,w,h,imageFlags,data);
}
fun Canvas::updateImage(int image, const unsigned char* data){
    nvgUpdateImage(this->ctx,image,data);
}
fun Canvas::imageSize(int image, int* w, int* h){
    nvgImageSize(this->ctx,image,w,h);
}
fun Canvas::deleteImage(int image){
    nvgDeleteImage(this->ctx,image);
}
NVGpaint Canvas::linearGradient(float sx, float sy, float ex, float ey,
                           NVGcolor icol, NVGcolor ocol){
    return nvgLinearGradient(this->ctx,sx,sy,ex,ey,icol,ocol);
}
NVGpaint Canvas::boxGradient(float x, float y, float w, float h,
                        float r, float f, NVGcolor icol, NVGcolor ocol){
    return nvgBoxGradient(this->ctx,x,y,w,h,r,f,icol,ocol);
}
NVGpaint Canvas::radialGradient(float cx, float cy, float inr, float outr,
                           NVGcolor icol, NVGcolor ocol){
    return nvgRadialGradient(this->ctx,cx,cy,inr,outr,icol,ocol);
}
NVGpaint Canvas::imagePattern(float ox, float oy, float ex, float ey,
                         float angle, int image, float alpha){
    return nvgImagePattern(this->ctx,ox,oy,ex,ey,angle,image,alpha);
}
fun Canvas::scissor(float x, float y, float w, float h){
    nvgScissor(this->ctx,x,y,w,h);
}
fun Canvas::intersectScissor(float x, float y, float w, float h){
    nvgIntersectScissor(this->ctx,x,y,w,h);
}
fun Canvas::resetScissor(){
    nvgResetScissor(this->ctx);
}
fun Canvas::begin(){
    nvgBeginPath(this->ctx);
}
fun Canvas::moveTo(float x, float y){
    nvgMoveTo(this->ctx,x,y);
}
fun Canvas::lineTo(float x, float y){
    nvgLineTo(this->ctx,x,y);
}
fun Canvas::bezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y){
    nvgBezierTo(this->ctx,c1x,c1y,c2x,c2y,x,y);
}
fun Canvas::quadTo(float cx, float cy, float x, float y){
    nvgQuadTo(this->ctx,cx,cy,x,y);
}
fun Canvas::arcTo(float x1, float y1, float x2, float y2, float radius){
    nvgArcTo(this->ctx,x1,y1,x2,y2,radius);
}
fun Canvas::close(){
    nvgClosePath(this->ctx);
}
fun Canvas::pathWinding(int dir){
    nvgPathWinding(this->ctx,dir);
}
fun Canvas::arc(float cx, float cy, float r, float a0, float a1, int dir){
    nvgArc(this->ctx,cx,cy,r,a0,a1,dir);
}
fun Canvas::barc(float cx, float cy, float r, float a0, float a1, int dir, int join){
    nvgBarc(this->ctx,cx,cy,r,a0,a1,dir,join);
}
fun Canvas::rect(float x, float y, float w, float h){
    nvgRect(this->ctx,x,y,w,h);
}
fun Canvas::rect(float x, float y, float w, float h, float r){
    nvgRoundedRect(this->ctx,x,y,w,h,r);
}
fun Canvas::rect(float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft){
    nvgRoundedRectVarying(this->ctx,x,y,w,h,radTopLeft,radTopRight,radBottomRight,radBottomLeft);
}
fun Canvas::ellipse(float cx, float cy, float rx, float ry){
    nvgEllipse(this->ctx,cx,cy,rx,ry);
}
fun Canvas::circle(float cx, float cy, float r){
    nvgCircle(this->ctx,cx,cy,r);
}
fun Canvas::fill(){
    nvgFill(this->ctx);
}
fun Canvas::stroke(){
    nvgStroke(this->ctx);
}
i32 Canvas::createFont(const char* name, const char* filename){
    return nvgCreateFont(this->ctx,name,filename);
}
i32 Canvas::createFontAtIndex(const char* name, const char* filename, const int fontIndex){
    return nvgCreateFontAtIndex(this->ctx,name,filename,fontIndex);
}
i32 Canvas::createFontMem(const char* name, unsigned char* data, int ndata, int freeData){
    return nvgCreateFontMem(this->ctx,name,data,ndata,freeData);
}
i32 Canvas::createFontMemAtIndex(const char* name, unsigned char* data, int ndata, int freeData, const int fontIndex){
    return nvgCreateFontMemAtIndex(this->ctx,name,data,ndata,freeData,fontIndex);
}
i32 Canvas::findFont(const char* name){
    return nvgFindFont(this->ctx,name);
}
i32 Canvas::addFallbackFontId(int baseFont, int fallbackFont){
    return nvgAddFallbackFontId(this->ctx,baseFont,fallbackFont);
}
i32 Canvas::addFallbackFont(const char* baseFont, const char* fallbackFont){
    return nvgAddFallbackFont(this->ctx,baseFont,fallbackFont);
}
fun Canvas::resetFallbackFontsId(int baseFont){
    return nvgResetFallbackFontsId(this->ctx,baseFont);
}
fun Canvas::resetFallbackFonts(const char* baseFont){
    return nvgResetFallbackFonts(this->ctx,baseFont);
}
fun Canvas::fontSize(float size){
    nvgFontSize(this->ctx,size);
}
fun Canvas::fontBlur(float blur){
    nvgFontBlur(this->ctx,blur);
}
fun Canvas::textLetterSpacing(float spacing){
    nvgTextLetterSpacing(this->ctx,spacing);
}
fun Canvas::textLineHeight(float lineHeight){
    nvgTextLineHeight(this->ctx,lineHeight);
}
fun Canvas::textAlign(int align){
    nvgTextAlign(this->ctx,align);
}
fun Canvas::fontFaceId(int font){
    nvgFontFaceId(this->ctx,font);
}
fun Canvas::fontFace(const char* font){
    nvgFontFace(this->ctx,font);
}
f32 Canvas::text(float x, float y, const char* string, const char* end){
    return nvgText(this->ctx,x,y,string,end);
}
fun Canvas::textBox(float x, float y, float breakRowWidth, const char* string, const char* end){
    nvgTextBox(this->ctx,x,y,breakRowWidth,string,end);
}
f32 Canvas::textBounds(float x, float y, const char* string, const char* end, float* bounds){
    return nvgTextBounds(this->ctx,x,y,string,end,bounds);
}
fun Canvas::textBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds){
    nvgTextBoxBounds(this->ctx,x,y,breakRowWidth,string,end,bounds);
}
i32 Canvas::textGlyphPositions(float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions){
    return nvgTextGlyphPositions(this->ctx,x,y,string,end,positions,maxPositions);
}
fun Canvas::textMetrics(float* ascender, float* descender, float* lineh){
    nvgTextMetrics(this->ctx,ascender,descender,lineh);
}
i32 Canvas::textBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows){
    return nvgTextBreakLines(this->ctx,string,end,breakRowWidth,rows,maxRows);
}
*/
