#include "ortalama.h"
void ortalamabul(Ogrenci* ogrenciverileri, int n)
{
    system("clear");
    int toplam = 0;
    double ortalama = 0.0;

    for (int i = 0; i < n; i++) {
        int ogrenci_ortalama = (ogrenciverileri[i].vize * 0.4) + (ogrenciverileri[i].final * 0.6);
        toplam += ogrenci_ortalama;
    }

    ortalama = (double)toplam / n;  
    printf("Sinif Ortalamasi: %.2f\n", ortalama); 
}


void eniyiortbul(Ogrenci* ogrenciverileri, int n)
{
    system("clear");
    double enYuksekOrtalama = 0.0;
    int enYuksekIndeks = -1;  

    for (int i = 0; i < n; i++)
    {
        double ortalama = (ogrenciverileri[i].vize * 0.4) + (ogrenciverileri[i].final * 0.6);

        if (ortalama > enYuksekOrtalama)
        {
            enYuksekOrtalama = ortalama;
            enYuksekIndeks = i;  
        }
    }


    if (enYuksekIndeks != -1)
    {
        printf("En Yuksek Ortalama:\n");
        printf("Numara: %d\n", ogrenciverileri[enYuksekIndeks].numara);
        printf("Isim: %s\n", ogrenciverileri[enYuksekIndeks].isim);
        printf("Vize: %d\n", ogrenciverileri[enYuksekIndeks].vize);
        printf("Final: %d\n", ogrenciverileri[enYuksekIndeks].final);
        printf("Ortalama: %.2f\n", enYuksekOrtalama);
        printf("-------------------------\n");
    }
    else
    {
        printf("Ogrenci bulunamadi.\n");
    }
}