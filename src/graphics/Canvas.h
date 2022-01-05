#ifndef CANVAS_H
#define CANVAS_H

#include "../types.h"
#include "gl/GLRenderer.h"
#include "vk/VKRenderer.h"

enum Backend{
    GL,
    VK,
    Default = GL
};

class Canvas{
private:
    VKRenderer* vk = null;
    GLRenderer* gl = null;
    Backend backend;
public:
    explicit Canvas(Backend mBackend = Default);
    ~Canvas();

};

#endif
