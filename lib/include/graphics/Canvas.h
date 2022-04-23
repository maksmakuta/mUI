#ifndef CANVAS_H
#define CANVAS_H

#include <utils/TypeUtils.h>
#include <graphics/nanovg/nanovg.h>

class Canvas{
public:
    Canvas();

    fun beginFrame(f32 w,f32 h,f32 pRatio);
    fun cancelFrame();
    fun endFrame();

    fun globalCompositeOperation(int op);
    fun globalCompositeBlendFunc(int sfactor, int dfactor);
    fun globalCompositeBlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);

    void save();
    void restore();
    void reset();

    void shapeAntiAlias(int enabled);
    void strokeColor(NVGcolor color);
    void strokePaint(NVGpaint paint);
    void fillColor(NVGcolor color);
    void fillPaint(NVGpaint paint);
    void miterLimit(float limit);
    void strokeWidth(float size);
    void lineCap(int cap);
    void lineJoin(int join);
    void globalAlpha(float alpha);

    void resetTransform();
    void transform(float a, float b, float c, float d, float e, float f);
    void translate(float x, float y);
    void rotate(float angle);
    void skewX(float angle);
    void skewY(float angle);
    void scale(float x, float y);
    void currentTransform(float* xform);

    void transformIdentity(float* dst);
    void transformTranslate(float* dst, float tx, float ty);
    void transformScale(float* dst, float sx, float sy);
    void transformRotate(float* dst, float a);
    void transformSkewX(float* dst, float a);
    void transformSkewY(float* dst, float a);
    void transformMultiply(float* dst, const float* src);
    void transformPremultiply(float* dst, const float* src);
    int transformInverse(float* dst, const float* src);
    void transformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy);


    int createImage(const char* filename, int imageFlags);
    int createImageMem(int imageFlags, unsigned char* data, int ndata);
    int createImageRGBA(int w, int h, int imageFlags, const unsigned char* data);
    void updateImage(int image, const unsigned char* data);
    void imageSize(int image, int* w, int* h);
    void deleteImage(int image);

    NVGpaint linearGradient(float sx, float sy, float ex, float ey,
                               NVGcolor icol, NVGcolor ocol);
    NVGpaint boxGradient(float x, float y, float w, float h,
                            float r, float f, NVGcolor icol, NVGcolor ocol);
    NVGpaint radialGradient(float cx, float cy, float inr, float outr,
                               NVGcolor icol, NVGcolor ocol);
    NVGpaint imagePattern(float ox, float oy, float ex, float ey,
                             float angle, int image, float alpha);

    void scissor(float x, float y, float w, float h);
    void intersectScissor(float x, float y, float w, float h);
    void resetScissor();

    void begin();
    void moveTo(float x, float y);
    void lineTo(float x, float y);
    void bezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y);
    void quadTo(float cx, float cy, float x, float y);
    void arcTo(float x1, float y1, float x2, float y2, float radius);
    void close();

    void pathWinding(int dir);
    void arc(float cx, float cy, float r, float a0, float a1, int dir);
    void barc(float cx, float cy, float r, float a0, float a1, int dir, int join);
    void rect(float x, float y, float w, float h);
    void rect(float x, float y, float w, float h, float r);
    void rect(float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);
    void ellipse(float cx, float cy, float rx, float ry);
    void circle(float cx, float cy, float r);
    void fill();
    void stroke();


    int nvgCreateFont(const char* name, const char* filename);
    int nvgCreateFontAtIndex(const char* name, const char* filename, const int fontIndex);
    int nvgCreateFontMem(const char* name, unsigned char* data, int ndata, int freeData);
    int nvgCreateFontMemAtIndex(const char* name, unsigned char* data, int ndata, int freeData, const int fontIndex);
    int nvgFindFont(const char* name);
    int nvgAddFallbackFontId(int baseFont, int fallbackFont);
    int nvgAddFallbackFont(const char* baseFont, const char* fallbackFont);
    void nvgResetFallbackFontsId(int baseFont);
    void nvgResetFallbackFonts(const char* baseFont);
    void nvgFontSize(float size);
    void nvgFontBlur(float blur);
    void nvgTextLetterSpacing(float spacing);
    void nvgTextLineHeight(float lineHeight);
    void nvgTextAlign(int align);
    void nvgFontFaceId(int font);
    void nvgFontFace(const char* font);
    float nvgText(float x, float y, const char* string, const char* end);
    void nvgTextBox(float x, float y, float breakRowWidth, const char* string, const char* end);
    float nvgTextBounds(float x, float y, const char* string, const char* end, float* bounds);
    void nvgTextBoxBounds(float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds);
    int nvgTextGlyphPositions(float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions);
    void nvgTextMetrics(float* ascender, float* descender, float* lineh);
    int nvgTextBreakLines(const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows);

};

#endif // CANVAS_H
