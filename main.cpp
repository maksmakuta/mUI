#include "src/window/Window.h"

int main(){
    Window w(640,480,"App");
    w.setBG(new Color("#000"));
    w.draw();
    return 0;
}
