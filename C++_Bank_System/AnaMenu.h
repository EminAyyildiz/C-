#ifndef ANAMENU_H
#define ANAMENU_H

#include "MusteriBilgi.h"
#include "MusteriIslem.h"
#include "yetkili.h"



class AnaMenu
{
private:
    MusteriBilgi bm;
public:
    AnaMenu(/* args */);
    ~AnaMenu();

void Yetkili_Kontrol();
void Musteri_Kontrol();
int  menu();
void giris();
};




#endif