#include "src/window/Window.h"
#include "src/graphics/Color.h"



int main() {
    Window w(800,600,"Test");
    w.setBG(new Color("#faf"));
    w.draw();
    return 0;
}