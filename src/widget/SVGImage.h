#ifndef MUI_SVGIMAGE_H
#define MUI_SVGIMAGE_H

#include "../types.h"
#include "../view/View.h"

#define NANOSVG_IMPLEMENTATION
#include "../graphics/nanovg/nanosvg.h"

class SVGImage : pub View{
private:
    NSVGimage* image;
public:
    SVGImage(const str& img){
        this->image = nsvgParseFromFile(img.c_str(), "px", 96);
    }

    fun onDraw(Canvas* c) override{
        c->begin();
        for (NSVGshape *shape = image->shapes; shape != NULL; shape = shape->next) {
            for (NSVGpath *path = shape->paths; path != NULL; path = path->next) {
                for (int i = 0; i < path->npts-1; i += 3) {
                    float* p = &path->pts[i*2];
                    c->moveTo(p[0],p[1]);
                    c->bezierTo(p[2],p[3], p[4],p[5], p[6],p[7]);
                }
            }
        }
        c->fill("#fff");
        c->end(false);
    }


};

#endif
