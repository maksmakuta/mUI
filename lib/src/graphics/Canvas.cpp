#include <graphics/Canvas.h>

Canvas::Canvas(){

}
Canvas::~Canvas(){

}
fun Canvas::beginFrame(f32 w,f32 h,f32 pRatio){

}
fun Canvas::cancelFrame(){

}
fun Canvas::endFrame(){

}
fun Canvas::globalCompositeOperation(int op){

}
fun Canvas::globalCompositeBlendFunc(int sfactor, int dfactor){

}
fun Canvas::globalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha){

}
fun Canvas::save(){

}
fun Canvas::restore(){

}
fun Canvas::reset(){

}
fun Canvas::shapeAntiAlias(int enabled){

}
fun Canvas::strokeColor(NVGcolor color){

}
fun Canvas::strokePaint(NVGpaint paint){

}
fun Canvas::fillColor(NVGcolor color){

}
fun Canvas::fillPaint(NVGpaint paint){

}
fun Canvas::miterLimit(float limit){

}
fun Canvas::strokeWidth(float size){

}
fun Canvas::lineCap(int cap){

}
fun Canvas::lineJoin(int join){

}
fun Canvas::globalAlpha(float alpha){

}
fun Canvas::resetTransform(){

}
fun Canvas::transform(float a, float b, float c, float d, float e, float f){

}
fun Canvas::translate(float x, float y){

}
fun Canvas::rotate(float angle){

}
fun Canvas::skewX(float angle){

}
fun Canvas::skewY(float angle){

}
fun Canvas::scale(float x, float y){

}
fun Canvas::currentTransform(float* xform){

}
fun Canvas::transformIdentity(float* dst){

}
fun Canvas::transformTranslate(float* dst, float tx, float ty){

}
fun Canvas::transformScale(float* dst, float sx, float sy){

}
fun Canvas::transformRotate(float* dst, float a){

}
fun Canvas::transformSkewX(float* dst, float a){

}
fun Canvas::transformSkewY(float* dst, float a){

}
fun Canvas::transformMultiply(float* dst, const float* src){

}
fun Canvas::transformPremultiply(float* dst, const float* src){

}
i32 Canvas::transformInverse(float* dst, const float* src){

}
fun Canvas::transformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy){

}
i32 Canvas::createImage(const char* filename, int imageFlags){

}
i32 Canvas::createImageMem(int imageFlags, unsigned char* data, int ndata){

}
i32 Canvas::createImageRGBA(int w, int h, int imageFlags, const unsigned char* data){

}
fun Canvas::updateImage(int image, const unsigned char* data){

}
fun Canvas::imageSize(int image, int* w, int* h){

}
fun Canvas::deleteImage(int image){

}
NVGpaint Canvas::linearGradient(float sx, float sy, float ex, float ey,
                           NVGcolor icol, NVGcolor ocol){

}
NVGpaint Canvas::boxGradient(float x, float y, float w, float h,
                        float r, float f, NVGcolor icol, NVGcolor ocol){

}
NVGpaint Canvas::radialGradient(float cx, float cy, float inr, float outr,
                           NVGcolor icol, NVGcolor ocol){

}
NVGpaint Canvas::imagePattern(float ox, float oy, float ex, float ey,
                         float angle, int image, float alpha){

}

fun Canvas::scissor(float x, float y, float w, float h){

}
fun Canvas::intersectScissor(float x, float y, float w, float h){

}
fun Canvas::resetScissor(){

}

fun Canvas::begin(){

}
fun Canvas::moveTo(float x, float y){

}
fun Canvas::lineTo(float x, float y){

}
fun Canvas::bezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y){

}
fun Canvas::quadTo(float cx, float cy, float x, float y){

}
fun Canvas::arcTo(float x1, float y1, float x2, float y2, float radius){

}
fun Canvas::close(){

}
fun Canvas::pathWinding(int dir){

}
fun Canvas::arc(float cx, float cy, float r, float a0, float a1, int dir){

}
fun Canvas::barc(float cx, float cy, float r, float a0, float a1, int dir, int join){

}
fun Canvas::rect(float x, float y, float w, float h){

}
fun Canvas::rect(float x, float y, float w, float h, float r){

}
fun Canvas::rect(float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft){

}
fun Canvas::ellipse(float cx, float cy, float rx, float ry){

}
fun Canvas::circle(float cx, float cy, float r){

}
fun Canvas::fill(){

}
fun Canvas::stroke(){

}
i32 Canvas::createFont(const char* name, const char* filename){

}
i32 Canvas::createFontAtIndex(const char* name, const char* filename, const int fontIndex){

}
i32 Canvas::createFontMem(const char* name, unsigned char* data, int ndata, int freeData){

}
i32 Canvas::createFontMemAtIndex(const char* name, unsigned char* data, int ndata, int freeData, const int fontIndex){

}
i32 Canvas::findFont(const char* name){

}
i32 Canvas::addFallbackFontId(int baseFont, int fallbackFont){

}
i32 Canvas::addFallbackFont(const char* baseFont, const char* fallbackFont){

}
fun Canvas::resetFallbackFontsId(int baseFont){

}
fun Canvas::resetFallbackFonts(const char* baseFont){

}
fun Canvas::fontSize(float size){

}
fun Canvas::fontBlur(float blur){

}
fun Canvas::textLetterSpacing(float spacing){

}
fun Canvas::textLineHeight(float lineHeight){

}
fun Canvas::textAlign(int align){

}
fun Canvas::fontFaceId(int font){

}
fun Canvas::fontFace(const char* font){

}
f32 Canvas::text(float x, float y, const char* string, const char* end){

}
fun Canvas::textBox(float x, float y, float breakRowWidth, const char* string, const char* end){

}
f32 Canvas::textBounds(float x, float y, const char* string, const char* end, float* bounds){

}
fun Canvas::textBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds){

}
i32 Canvas::textGlyphPositions(float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions){

}
fun Canvas::textMetrics(float* ascender, float* descender, float* lineh){

}
i32 Canvas::textBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows){

}
