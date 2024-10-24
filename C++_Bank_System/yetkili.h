#ifndef YETKILI_H
#define YETKILI_H
#include "MusteriBilgi.h"

class yetkili
{
private:
    MusteriBilgi musteri;
public:
    yetkili();
    ~yetkili();

    void MusteriEkle();
    void MusteriSil();
    void MusteriAra();
    void MusteriGuncelle();

    int YetkiliMenu();
    void YetkiliGiris();


};




#endif