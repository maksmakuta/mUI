#ifndef CANVAS_H
#define CANVAS_H

#include <utils/TypeUtils.h>
#include <graphics/nanovg/nanovg.h>

class Canvas{
private:
    NVGcontext* ctx = null;
public:
    Canvas();
    ~Canvas();

    fun beginFrame(f32 w,f32 h,f32 pRatio);
    fun cancelFrame();
    fun endFrame();

    fun globalCompositeOperation(int op);
    fun globalCompositeBlendFunc(int sfactor, int dfactor);
    fun globalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);

    fun save();
    fun restore();
    fun reset();

    fun shapeAntiAlias(int enabled);
    fun strokeColor(NVGcolor color);
    fun strokePaint(NVGpaint paint);
    fun fillColor(NVGcolor color);
    fun fillPaint(NVGpaint paint);
    fun miterLimit(float limit);
    fun strokeWidth(float size);
    fun lineCap(int cap);
    fun lineJoin(int join);
    fun globalAlpha(float alpha);

    fun resetTransform();
    fun transform(float a, float b, float c, float d, float e, float f);
    fun translate(float x, float y);
    fun rotate(float angle);
    fun skewX(float angle);
    fun skewY(float angle);
    fun scale(float x, float y);
    fun currentTransform(float* xform);

    fun transformIdentity(float* dst);
    fun transformTranslate(float* dst, float tx, float ty);
    fun transformScale(float* dst, float sx, float sy);
    fun transformRotate(float* dst, float a);
    fun transformSkewX(float* dst, float a);
    fun transformSkewY(float* dst, float a);
    fun transformMultiply(float* dst, const float* src);
    fun transformPremultiply(float* dst, const float* src);
    i32 transformInverse(float* dst, const float* src);
    fun transformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy);


    i32 createImage(const char* filename, int imageFlags);
    i32 createImageMem(int imageFlags, unsigned char* data, int ndata);
    i32 createImageRGBA(int w, int h, int imageFlags, const unsigned char* data);
    fun updateImage(int image, const unsigned char* data);
    fun imageSize(int image, int* w, int* h);
    fun deleteImage(int image);

    NVGpaint linearGradient(float sx, float sy, float ex, float ey,
                               NVGcolor icol, NVGcolor ocol);
    NVGpaint boxGradient(float x, float y, float w, float h,
                            float r, float f, NVGcolor icol, NVGcolor ocol);
    NVGpaint radialGradient(float cx, float cy, float inr, float outr,
                               NVGcolor icol, NVGcolor ocol);
    NVGpaint imagePattern(float ox, float oy, float ex, float ey,
                             float angle, int image, float alpha);

    fun scissor(float x, float y, float w, float h);
    fun intersectScissor(float x, float y, float w, float h);
    fun resetScissor();

    fun begin();
    fun moveTo(float x, float y);
    fun lineTo(float x, float y);
    fun bezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y);
    fun quadTo(float cx, float cy, float x, float y);
    fun arcTo(float x1, float y1, float x2, float y2, float radius);
    fun close();

    fun pathWinding(int dir);
    fun arc(float cx, float cy, float r, float a0, float a1, int dir);
    fun barc(float cx, float cy, float r, float a0, float a1, int dir, int join);
    fun rect(float x, float y, float w, float h);
    fun rect(float x, float y, float w, float h, float r);
    fun rect(float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);
    fun ellipse(float cx, float cy, float rx, float ry);
    fun circle(float cx, float cy, float r);
    fun fill();
    fun stroke();

    i32 createFont(const char* name, const char* filename);
    i32 createFontAtIndex(const char* name, const char* filename, const int fontIndex);
    i32 createFontMem(const char* name, unsigned char* data, int ndata, int freeData);
    i32 createFontMemAtIndex(const char* name, unsigned char* data, int ndata, int freeData, const int fontIndex);
    i32 findFont(const char* name);
    i32 addFallbackFontId(int baseFont, int fallbackFont);
    i32 addFallbackFont(const char* baseFont, const char* fallbackFont);
    fun resetFallbackFontsId(int baseFont);
    fun resetFallbackFonts(const char* baseFont);
    fun fontSize(float size);
    fun fontBlur(float blur);
    fun textLetterSpacing(float spacing);
    fun textLineHeight(float lineHeight);
    fun textAlign(int align);
    fun fontFaceId(int font);
    fun fontFace(const char* font);
    f32 text(float x, float y, const char* string, const char* end);
    fun textBox(float x, float y, float breakRowWidth, const char* string, const char* end);
    f32 textBounds(float x, float y, const char* string, const char* end, float* bounds);
    fun textBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds);
    i32 textGlyphPositions(float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions);
    fun textMetrics(float* ascender, float* descender, float* lineh);
    i32 textBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows);

};

#endif // CANVAS_H
