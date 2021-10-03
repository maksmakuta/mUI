#ifndef TT_FRAMEBUFFER_H
#define TT_FRAMEBUFFER_H

#include <sys/ioctl.h>
#include <unistd.h>

class Framebuffer {
private:
    winsize size{};
public:
    Framebuffer();
    void init();
    void info();
};


#endif
