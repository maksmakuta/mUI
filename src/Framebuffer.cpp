#include "Framebuffer.h"
#include <iostream>

Framebuffer::Framebuffer(){
    init();
}
void Framebuffer::init(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
}
void Framebuffer::info(){
    std::cout << "Size = " << size.ws_col << "x" << size.ws_row << "\n";
}