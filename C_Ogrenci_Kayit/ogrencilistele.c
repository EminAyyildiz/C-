
#include "ogrencilistele.h"

void ogrencilistele(Ogrenci* ogrenciverileri, int n)
{
    system("clear");
    printf("\nOgrenci Bilgileri:\n");
    for (int i = 0; i < n; i++) {
        printf("Numara: %d\n", ogrenciverileri[i].numara);
        printf("Isim: %s\n", ogrenciverileri[i].isim);
        printf("Vize: %d\n", ogrenciverileri[i].vize);
        printf("Final: %d\n", ogrenciverileri[i].final);
        printf("-------------------------\n");
    }
}