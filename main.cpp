#include "src/graphics/Window.h"
#include "src/widget/Button.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/app/App.h"
#include "src/widget/EditText.h"
#include "src/widget/IconView.h"

class MainActivity : pub Activity,pub OnClickListener{
private:
    Button*     clearBtn    = new Button("Toast");
    EditText*   ed          = new EditText();
public:
    fun onCreate() override{
        clearBtn->setOnClickListener(this);
        setContentView(init());
    }

    fun onClick(View *v) override{
        if(v->id() == clearBtn->id()){

        }
    }

    View* init(){
        auto l = new LinearLayout(Vertical);
        auto ll = new LinearLayout(Horizontal);
        ll->add(clearBtn);
        ll->add(ed);
        l->add(ll);
        return new IconView(_10k);
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}