#ifndef MUI_CANVAS_H
#define MUI_CANVAS_H

#include <vector>
#include <GL/glew.h>
#include "nanovg/nanovg.h"
#include "nanovg/nanovg_gl.h"
#include "../types.h"

#define hLeft       NVG_ALIGN_LEFT
#define hCenter     NVG_ALIGN_CENTER
#define hRight      NVG_ALIGN_RIGHT

#define vTop        NVG_ALIGN_TOP
#define vMiddle     NVG_ALIGN_MIDDLE
#define vBottom     NVG_ALIGN_BOTTOM
#define vBaseline   NVG_ALIGN_BASELINE

#define rad(x) x*(NVG_PI/180)
#define deg(x) x*(180/NVG_PI)

typedef NVGcolor Color;
typedef NVGpaint Paint;

/**
 * The Canvas class
 * API 2.0
 * @since 0.2 (dev branch)
 *
 * Provides own API to nanovg API
 */
class Canvas {
private:
    NVGcontext *c = null;   // context for drawing
    std::vector<i32> fonts; // fonts allocators
public:
    explicit Canvas(i32 flags);

    /**
     * @brief beginFrame -> begin drawing a new frame
     * @param w : float -> window width
     * @param h : float -> window height
     * @param p : float -> pixel ratio
     */
    fun beginFrame(f32 w,f32 h,f32 p);

    /**
     * @brief cancelFrame -> cancel drawing current frame
     */
    fun cancelFrame();

    /**
     * @brief endFrame -> end drawing current frame
     */
    fun endFrame();

    /**
     * @brief fill -> fill current shape
     * @param color : const char* -> color string ("#f00f0a")
     */
    fun fill(const char* color);

    /**
     * @brief fill -> fill current shape
     * @param color : const str& -> color string ("#f00f0a")
     */
    fun fill(const  str& color);

    /**
     * @brief stroke -> draw stroked shape
     * @param color : const char* -> color string ("#fff")
     */
    fun stroke(const char* color);

    /**
     * @brief stroke -> draw stroked shape
     * @param color : const str& -> color string ("#fff")
     */
    fun stroke(const  str& color);

    /**
     * @brief save -> save current state
     */
    fun save();

    /**
     * @brief restore -> restore current state
     */
    fun restore();

    /**
     * @brief reset -> reset current state
     */
    fun reset();

    /**
     * @brief antialias -> draw antialias for fill() and stroke()
     * @param a : bool -> antialias state
     */
    fun antialias(bool a);

    /**
     * @brief fillColor -> fill current shape using Color
     * @param color : Color -> Color to fill
     */
    fun fillColor(Color color);

    /**
     * @brief fillPaint -> fill current shape using Paint
     * @param paint : Paint -> Paint to fill
     */
    fun fillPaint(Paint paint);

    /**
     * @brief strokeColor -> stroke surrent shape using Color
     * @param color : Color -> Color to stroke
     */
    fun strokeColor(Color color);

    /**
     * @brief strokePaint -> stroke surrent shape using Paint
     * @param paint : Paint -> Paint to stroke
     */
    fun strokePaint(Paint paint);

    /**
     * @brief mitterLimit -> set mitter limit for stroke style
     * @param limit : float -> limit value
     */
    fun mitterLimit(f32 limit);

    /**
     * @brief lineCap -> set end of the line style
     * @param cap : int -> can be {BUTT,ROUND,SQUARE}
     */
    fun lineCap (i32 cap);

    /**
     * @brief lineJoin -> set style to join lines
     * @param join : int -> can be {MITTER,ROUND,BEVEL}
     */
    fun lineJoin(i32 join);

    /**
     * @brief resetTransform -> reset current transform to identity matrix
     */
    fun resetTransform();

    /**
     *  Matrix looks like:
     *
     *  [a,b,c]
     *  [d,e,f]
     *  [0,0,1]
     *
     */

    /**
     * @brief transform -> premultiply current coordinate system by scecified matrix
     * @param _a : float -> a element of matrix
     * @param _b : float -> b element of matrix
     * @param _c : float -> c element of matrix
     * @param _d : float -> d element of matrix
     * @param _e : float -> e element of matrix
     * @param _f : float -> f element of matrix
     */
    fun transform(f32 _a,f32 _b,f32 _c,f32 _d,f32 _e,f32 _f);

    /**
     * @brief translate -> translate currrent coordinate system
     * @param _x : float -> x
     * @param _y : float -> y
     */
    fun translate(f32 _x,f32 _y);

    /**
     * @brief rotate -> rotate current coordinate system
     * @param angle : float -> angle (in radians)
     */
    fun rotate(f32 angle);

    /**
     * @brief skewX -> skew current coordinate system by X-axis
     * @param angle : float -> angle (in radians)
     */
    fun skewX(f32 angle);

    /**
     * @brief skewY -> skew current coordinate system by Y-axis
     * @param angle : float -> angle (in radians)
     */
    fun skewY(f32 angle);

    /**
     * @brief scale -> scale current coordinate system
     * @param _x : float -> x-axis
     * @param _y : float -> y-axis
     */
    fun scale(f32 _x,f32 _y);

    /**
     * @brief currentTransform -> stores current matrix to buffer
     * @param xform : float* -> matrix buffer (float[6])
     */
    fun currentTransform(f32* xform);

    /**
     * @brief transformIdentity -> set transform to identity matrix
     * @param mat : float* -> matrix buffer (float[6])
     */
    fun transformIdentity(f32* mat);

    /**
     * @brief transformTranslate -> set transform to translate matrix
     * @param mat : float* -> matrix buffer (float[6])
     * @param x : float -> x
     * @param y : float -> y
     */
    fun transformTranslate(f32* mat,f32 x,f32 y);

    /**
     * @brief transformRotate -> set transform to rotate matrix
     * @param mat : float* -> matrix buffer (float[6])
     * @param angle : float -> angle (in radians)
     */
    fun transformRotate(f32* mat,f32 angle);

    /**
     * @brief transformSkewX -> set transform to skewX matrix
     * @param mat : float* -> matrix buffer (float[6])
     * @param angle : float -> angle (in radians)
     */
    fun transformSkewX(f32* mat,f32 angle);

    /**
     * @brief transformSkewY -> set transform to skewY matrix
     * @param mat : float* -> matrix buffer (float[6])
     * @param angle : float -> angle (in radians)
     */
    fun transformSkewY(f32* mat,f32 angle);

    /**
     * @brief transformScale -> set transform to scale matrix
     * @param mat : float* -> matrix buffer (float[6])
     * @param x : float -> x
     * @param y : float -> y
     */
    fun transformScale(f32* mat,f32 x,f32 y);

    /**
     * @brief transformMultiply -> multiply matrices A = A*B
     * @param matA : float* -> matrixA (float[6])
     * @param matB : float* -> matrixB (float[6])
     */
    fun transformMultiply(f32* matA,const f32* matB);

    /**
     * @brief transformPremultiply-> multiply matrices A = B*A
     * @param matA : float* -> matrixA (float[6])
     * @param matB : float* -> matrixB (float[6])
     */
    fun transformPremultiply(f32* matA,const f32* matB);

    /**
     * @brief transformInverse -> set matA inverse of matB
     * @param matA : float* -> matrixA (float[6])
     * @param matB : float* -> matrixB (float[6])
     * @return int -> 1 if inverse is caculated , else 0
     */
    i32 transformInverse(f32* matA,const f32* matB);

    /**
     * @brief transformPoint -> transform point by given transform
     * @param dstx : float*
     * @param dsty : float*
     * @param mat  : float* -> matrix (float[6])
     * @param srcx : float
     * @param srcy : float
     */
    fun transformPoint(f32* dstx,f32* dsty,const f32* mat,f32 srcx,f32 srcy);

    /**
     * @brief createImage -> load image by name from disk
     * @param name : const char* -> path to file
     * @param flags : int -> images flags
     * @return int -> handle to image
     */
    i32 createImage(const char* name,i32 flags);

    /**
     * @brief createImageMem -> load images from memory
     * @param flags : int -> images flags
     * @param imgData : unsigned int* -> image data
     * @param ndata : int -> data size
     * @return int -> handle to image
     */
    i32 createImageMem(i32 flags,unsigned char* imgData,i32 ndata);

    /**
     * @brief createImageRGBA -> load image from image data
     * @param w : int -> width of image
     * @param h : int -> height of image
     * @param flags : int -> image flags
     * @param data : const unsigned int* -> image data
     * @return int -> handle to image
     */
    i32 createImageRGBA(i32 w,i32 h,i32 flags,unsigned char* data);

    /**
     * @brief updateImage -> set new image data in current image
     * @param img : int -> image handle
     * @param data : const unsigned int* -> image data
     */
    fun updateImage(i32 img,unsigned char* data);

    /**
     * @brief imageSize -> return width and height of image
     * @param img : int -> image handle
     * @param w : int* -> width of image
     * @param h : int* -> height of image
     */
    fun imageSize(i32 img,i32* w,i32* h);

    /**
     * @brief deleteImage -> safe delete image
     * @param img : int -> image handle
     */
    fun deleteImage(i32 img);

    /**
     * @brief linearGradient -> make linear gradient
     * @param sx : float -> start X
     * @param sy : float -> start Y
     * @param ex : float -> end X
     * @param ey : float -> end Y
     * @param a : Color -> color from
     * @param b : Color -> color to
     * @return Paint -> Paint instance
     */
    Paint linearGradient(f32 sx,f32 sy,f32 ex,f32 ey,Color a,Color b);

    /**
     * @brief boxGradient -> make box gradient
     * @param x : float -> x point of rectangle
     * @param y : float -> y point of rectangle
     * @param w : float -> width  of rectangle
     * @param h : float -> height of rectangle
     * @param r : float -> corner radius
     * @param f : float -> blurry
     * @param a : Color -> Color from
     * @param b : Color -> Color to
     * @return Paint -> Paint instance
     */
    Paint boxGradient(f32 x,f32 y,f32 w,f32 h,f32 r,f32 f,Color a,Color b);

    /**
     * @brief radialGradient -> make radial gradient
     * @param cx : float -> x point of center
     * @param cy : float -> y point of center
     * @param ri : float -> inner radius
     * @param ro : float -> outer radius
     * @param a : Color -> Color from
     * @param b : Color -> Color to
     * @return Paint -> Paint instance
     */
    Paint radialGradient(f32 cx,f32 cy,f32 ri,f32 ro,Color a,Color b);

    /**
     * @brief imagePaint -> make image paint
     * @param x : float -> x point of image
     * @param y : float -> y point of image
     * @param w : float -> width  of image
     * @param h : float -> height of image
     * @param angle : float -> angle (in radians)
     * @param img : int -> image handle
     * @param alpha : float -> set alpha for image
     * @return Paint -> Paint instance
     */
    Paint imagePaint(f32 x,f32 y,f32 w,f32 h,f32 angle,i32 img,f32 alpha);

    /**
     * @brief scissor -> set scissor rectangle
     * @param x : float -> x point of rectangle
     * @param y : float -> y point of rectangle
     * @param w : float -> width  of rectangle
     * @param h : float -> height of rectangle
     */
    fun scissor(f32 x,f32 y,f32 w,f32 h);

    /**
     * @brief scissorIntersect -> intersect current scissor with rectangle
     * @param x : float -> x point of rectangle
     * @param y : float -> y point of rectangle
     * @param w : float -> width  of rectangle
     * @param h : float -> height of rectangle
     */
    fun scissorIntersect(f32 x,f32 y,f32 w,f32 h);

    /**
     * @brief scissorReset -> reset scissor and disable scissoring
     */
    fun scissorReset();

    /**
     * @brief begin -> declare new shape
     */
    fun begin();

    /**
     * @brief close -> close sub-path for shape
     */
    fun close();

    /**
     * @brief moveTo -> start new sub-path in point (x,y)
     * @param x : float -> x point
     * @param y : float -> y point
     */
    fun moveTo(f32 x,f32 y);

    /**
     * @brief lineTo -> add line from last point to this (x,y)
     * @param x : float -> x point
     * @param y : float -> y point
     */
    fun lineTo(f32 x,f32 y);

    /**
     * @brief bezierTo -> draw cubic bezier curve from last point to (x,y) via (c1x,c1y) and (c2x,c2y)
     * @param c1x : float -> x of 1 point
     * @param c1y : float -> y of 1 point
     * @param c2x : float -> x of 2 point
     * @param c2y : float -> y of 2 point
     * @param x : float -> x of 3 point
     * @param y : float -> y of 3 point
     */
    fun bezierTo(f32 c1x,f32 c1y,f32 c2x,f32 c2y,f32 x,f32 y);

    /**
     * @brief quadTo -> draw quad bezier curve from last point to (x,y) via (cx,cy)
     * @param cx : float -> x of 1 point
     * @param cy : float -> y of 1 point
     * @param x : float -> x of 2 point
     * @param y : float -> y of 2 point
     * @return
     */
    fun quadTo(f32 cx,f32 cy,f32 x,f32 y);

    /**
     * @brief arcTo -> add arc segment to last point via 2 point (x1,y1) and (x2,y2)
     * @param x1 : float -> x of 1 point
     * @param y1 : float -> y of 1 point
     * @param x2 : float -> x of 2 point
     * @param y2 : float -> y of 2 point
     * @param r : float -> radius
     */
    fun arcTo(f32 x1,f32 y1,f32 x2,f32 y2,f32 r);

    /**
     * @brief winding -> set winding of sub-path
     * @param w : int -> can be {SOLID,HOLE}
     */
    fun winding(i32 w);

    /**
     * @brief arc -> draw arc
     * @param x : float -> x of center
     * @param y : float -> y of center
     * @param r : float -> radius
     * @param s : float -> start angle
     * @param e : float -> end engl
     * @param dir : int -> direction , can be{}
     */
    fun arc(f32 x,f32 y,f32 r, f32 s, f32 e,i32 dir);

    /**
     * @brief rect -> draw rect
     * @param x : float -> x position
     * @param y : float -> y position
     * @param w : float -> width
     * @param h : float -> height
     */
    fun rect(f32 x,f32 y,f32 w,f32 h);

    /**
     * @brief rect -> draw rect with same corner radius
     * @param x : float -> x position
     * @param y : float -> y position
     * @param w : float -> width
     * @param h : float -> height
     * @param r : float -> radius of corners
     */
    fun rect(f32 x,f32 y,f32 w,f32 h,f32 r);

    /**
     * @brief rect -> draw rect with corners
     * @param x : float -> x position
     * @param y : float -> y position
     * @param w : float -> width
     * @param h : float -> height
     * @param tl : float -> top left corner
     * @param tr : float -> top rigth corner
     * @param bl : float -> bottom left corner
     * @param br : float -> bottom rigth corner
     */
    fun rect(f32 x,f32 y,f32 w,f32 h,f32 tl,f32 tr,f32 bl,f32 br);

    /**
     * @brief ellipse -> draw ellipce
     * @param x : float -> x position
     * @param y : float -> y position
     * @param rw : float -> width
     * @param rh : float -> heigth
     */
    fun ellipse(f32 x,f32 y,f32 rw,f32 rh);

    /**
     * @brief circle -> draw circle
     * @param x : float -> x position
     * @param y : float -> y position
     * @param r : float -> radius
     */
    fun circle(f32 x,f32 y,f32 r);

    /**
     * @brief createFont -> load font file and make new font
     * @param filename : const char* -> file path
     * @param fontname : cosnt char* -> file name
     * @return int -> handle to font
     */
    i32 createFont(const char* filename,const char* fontname);

    /**
     * @brief createFont -> create font and save to vector
     * @param filename : const char* -> file path
     * @param fontname : cosnt char* -> file name
     * @param pos : int -> position in font vector
     * @return int -> handle to font
     */
    i32 createFont(const char* filename,const char* fontname,const i32 pos);

    /**
     * @brief createFontMem -> load font data from memory and make new font
     * @param name : const char* -> file path
     * @param mem : unsigned char* -> font data
     * @param ndata : int
     * @param fdata : int
     * @return int -> handle to font
     */
    i32 createFontMem(const char* name ,unsigned char* mem,i32 ndata,i32 fdata);

    /**
     * @brief createFontMem -> load font data from memory and make new font
     * @param name : const char* -> file path
     * @param mem : unsigned char* -> font data
     * @param ndata : int
     * @param fdata : int
     * @param pos : int -> position in font vector
     * @return int -> handle to font
     */
    i32 createFontMem(const char* name,unsigned char* mem,i32 ndata,i32 fdata,i32 pos);

    /**
     * @brief findFont -> find font by name
     * @param name : const char* -> name of font
     * @return int -> font handle if found, else -1
     */
    i32 findFont(const char* name);

    /**
     * @brief addFallbackFont -> add fallback font by handle
     * @param base : int -> base font
     * @param fall : int -> fallback font
     * @return int
     */
    i32 addFallbackFont(i32 base,i32 fall);

    /**
     * @brief addFallbackFont-> add fallback font by name
     * @param base : cosnt char* -> base font
     * @param fall : cosnt char* -> fallback font
     * @return int
     */
    i32 addFallbackFont(const char* base,const char* fall);

    /**
     * @brief resetFallbackFont -> reset fallback font by handle
     * @param base : int -> font
     */
    fun resetFallbackFont(i32 base);

    /**
     * @brief resetFallbackFont -> reset fallback font by name
     * @param base : const char* -> font
     */
    fun resetFallbackFont(const char*);

    /**
     * @brief fontSize -> set size of font
     * @param s : float -> size
     */
    fun fontSize(f32 s);

    /**
     * @brief fontBlur -> set blur of font
     * @param b : float -> blur size
     */
    fun fontBlur(f32 b);

    /**
     * @brief fontSpacing -> set font spacing
     * @param s : float -> spacing size
     */
    fun fontSpacing(f32 s);

    /**
     * @brief fontHeight -> set font height
     * @param h : float -> height size
     */
    fun fontHeight (f32 h);

    /**
     * @brief fontAlign -> set font align
     * @param a : int -> align
     */
    fun fontAlign(i32 a);

    /**
     * @brief fontFace -> set font face
     * @param f : int -> font handle
     */
    fun fontFace (i32 f);

    /**
     * @brief fontFace -> set font face
     * @param f : cosnt char* -> font name
     */
    fun fontFace (const char* f);

    /**
     * @brief text -> draw text using current font
     * @param x : float -> x position
     * @param y : float -> y position
     * @param text : const char* -> text
     * @param end  : const char* -> end text
     */
    fun text(f32 x,f32 y,const char* text,const char* end = null);

    /**
     * @brief text-> draw text using current font
     * @param x : float -> x position
     * @param y : float -> y position
     * @param w : float -> max width of text
     * @param text : const char* -> text
     * @param end  : const char* -> end text
     */
    fun text(f32 x,f32 y,f32 w,const char*text,const char* end = null);

    /**
     * @brief textBounds -> calc bounds of text
     * @param bounds : float[4] -> calc bounds [xmin,ymin,xmax,ymax]
     * @param x : float -> x position of text
     * @param y : float -> y position of text
     * @param text : const char* -> text
     * @param end  : const char* -> end text
     * @return float -> horizontal advance of text
     */
    f32 textBounds(f32* bounds,f32 x,f32 y,const char* text,const char* end = null);

    /**
     * @brief textBounds -> calc bounds of text
     * @param bounds : float[4] -> calc bounds [xmin,ymin,xmax,ymax]
     * @param x : float -> x position of text
     * @param y : float -> y position of text
     * @param w : float -> width of text
     * @param text : const char* -> text
     * @param end  : const char* -> end text
     */
    fun textBounds(f32* bounds,f32 x,f32 y,f32 w,const char* text,const char* end =null);

    /**
     * @brief textMetrics -> calc text matrics
     * @param a : float* -> ascender
     * @param d : float* -> descender
     * @param l : float* -> line height
     */
    fun textMetrics(f32* a,f32* d,f32* l);

};

#endif
