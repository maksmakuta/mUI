#include "src/graphics/Window.h"
#include "src/app/App.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/widget/IconButton.h"

class ToolBar : public View{
private:
    str title;
    f32 sf;
public:
    ToolBar(const str& _t,f32 _s,View* p) : View(p){
        this->title = _t;
        this->sf = _s;
    }

    fun onDraw(Canvas *c) override{
        Rect r = rect();

        c->begin();
        c->rect(r.x,r.y,r.w,r.h);
        c->fill("#333");
        c->end(true);

        c->fontFace("roboto");
        c->fontSize(sf);
        c->fontFill("#f84");
        c->fontAlign(hCenter |vMiddle);
        c->text(r.x + r.w/2.f,r.y + r.h/2.f,title.c_str());

        c->fontFace("icons");
        c->fontSize(sf);
        c->fontFill("#f84");
        c->fontAlign(hCenter |vMiddle);
        c->text(r.x + r.h/2.f,r.y + r.h/2.f, cpToUTF8(ic_menu));
    }

    fun onMeasure() override{
        View* p = getParent();
        if(p!= null){
            this->size(p->rect().w,64);
        }else{
            this->size(640,64);
        }
    }
};

class MainActivity : pub Activity{
public:
    fun onCreate() override{
        View* ll = new LinearLayout(Vertical,null);
        new ToolBar("app",28,ll);
        View *a = new LinearLayout(Horizontal,ll);
        new IconButton(rrect    ,ic_verified_user   ,32,a);
        new IconButton(circle   ,ic_add_call        ,32,a);
        new IconButton(rect     ,ic_mail            ,32,a);
        new IconButton(rrect    ,ic_star            ,32,a);
        new IconButton(circle   ,ic_account_circle  ,32,a);
        new IconButton(rect     ,ic_add_comment     ,32,a);
        new IconButton(rrect    ,ic_share           ,32,a);
        setContentView(ll);
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}
