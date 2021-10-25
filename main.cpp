#include "src/core/App.h"
#include "src/view/ProgressView.h"
#include "src/layout/LinearLayout.h"

View* ll(){
    auto m = new LinearLayout();
    m->add(new ProgressView("#fff"));
    return m;
}

int main(){
    App app(640,480,"Window");
    app.layout(ll());
    return app.run();
}