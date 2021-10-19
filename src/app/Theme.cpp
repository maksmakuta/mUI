#include "Theme.h"

Theme::Theme(){ }
Theme::Theme(const Theme& t){
    this->setPrimary    (t.getPrimary());
    this->setSecondary  (t.getSecondary());
    this->setText       (t.getText());
}

fun Theme::setPrimary  (const str& p){
    this->primary   = p;
}
fun Theme::setSecondary(const str& p){
    this->secondary = p;
}
fun Theme::setText     (const str& p){
    this->text      = p;
}

str Theme::getPrimary  (){return this->primary  ; }
str Theme::getSecondary(){return this->secondary; }
str Theme::getText     (){return this->text     ; }

str Theme::getPrimary  ()const{return this->primary  ; }
str Theme::getSecondary()const{return this->secondary; }
str Theme::getText     ()const{return this->text     ; }

str Theme::toString(){
    return "Theme(" + this->getPrimary()   + ","
                    + this->getSecondary() + ","
                    + this->getText()      + ")";
}
