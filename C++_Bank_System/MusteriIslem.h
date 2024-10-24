#ifndef MUSTERIISLEM_H
#define MUSTERIISLEM_H

#include "MusteriBilgi.h"


class MusteriIslem
{
private:
    MusteriBilgi musteri;
public:
    MusteriIslem();
    ~MusteriIslem();
    MusteriIslem(MusteriBilgi musteri);
    void paracek();
    void paraYatir();
    void bakiyeSorgula();
    void havaleyap();
    void hareketlerikaydet(char * dosyaAdi,float mik, char* msjks, char* kisi, char* mesaj, float baki);
    void hesaphareketleri();
    void sifredegis();
    int musterimenu();
    void musteriGiris(MusteriBilgi musteri);

 

};


#endif