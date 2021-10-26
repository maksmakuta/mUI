#include "src/core/App.h"

View* ll(){
    return new View();
}

int main(){
    App app(640,480,"Window");
    app.setTheme(Theme::Light());
    app.layout(ll());
    return app.run();
}