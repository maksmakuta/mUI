#include <sstream>
#include <ios>
#include <random>
#include "src/graphics/Window.h"
#include "src/widget/Button.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/app/App.h"
#include "src/widget/EditText.h"
#include "src/widget/TextView.h"

class MainActivity : pub Activity,pub OnClickListener{
private:
    Button*     clearBtn    = new Button("Clear");
    EditText*   ed          = new EditText();
    TextView*   tv          = new TextView("");
public:
    fun onCreate() override{
        clearBtn->setOnClickListener(this);
        setContentView(init());
    }

    fun onClick(View *v) override{
        if(v->id() == clearBtn->id()){
            tv->setText(ed->getText());
            ed->setText("");
        }
    }

    View* init(){
        auto l = new LinearLayout(Vertical);
        l->add(tv);
        auto ll = new LinearLayout(Horizontal);
        ll->add(clearBtn);
        ll->add(ed);
        l->add(ll);
        return l;
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}