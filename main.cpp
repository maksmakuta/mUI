#include <sstream>
#include <ios>
#include <unistd.h>
#include <random>
#include "src/graphics/Window.h"
#include "src/widget/TextView.h"
#include "src/widget/Button.h"
#include "src/widget/layout/LinearLayout.h"
#include "src/app/App.h"

class MainActivity : pub Activity{
public:
    fun onCreate() override{
        setContentView(init());
    }

    View* init(){
        auto ll = new LinearLayout(Vertical);
        for(i32 x = 0;x < 15;x++){
            auto l = new LinearLayout(Horizontal);
            for(i32 y = 0;y < 5;y++){
                l->add(new Button(randColor()));
            }
            ll->add(l);
        }
        return ll;
    }

    i32 rand(i32 m){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,m);
        return (i32)dist6(rng);
    }

    str randColor(){
        i32 r = rand(256);
        i32 g = rand(256);
        i32 b = rand(256);
        std::stringstream ss;
        ss << "#" << std::hex << r << g << b;
        str col = ss.str();
        while(true){
            if(col.size() -1 >= 6)
                break;
            col.append("0");
        }
        return col;
    }

};

int main(){
    App a(640,480,"app");
    a.setActivity(new MainActivity());
    return a.exec();
}