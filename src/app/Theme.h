#ifndef MUI_THEME_H
#define MUI_THEME_H

#include "../sTypes.h"
#include "../Object.h"

class Theme : public Object{
private:
    str primary,secondary,text;
public:
    Theme();
    Theme(const Theme& t);

    fun setPrimary  (const str& p);
    fun setSecondary(const str& p);
    fun setText     (const str& p);

    str getPrimary  ();
    str getSecondary();
    str getText     ();

    str getPrimary  ()const;
    str getSecondary()const;
    str getText     ()const;

    str toString() override;

};

#endif