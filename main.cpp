#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/widget/ToolBar.h"
#include "src/widget/EditText.h"

class MainActivity : public Activity{
public:
    fun onCreate() override{
        View* ll = new LinearLayout(Vertical,null);
        new ToolBar("app",28,ll);
        new EditText("Label",ll);
        setContentView(ll);
    }
};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
