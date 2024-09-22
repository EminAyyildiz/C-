#include "ogrenciekle.h"

void ogrenciekle(Ogrenci* ogrenciverileri, int n)
{
    system("clear");
    int i = 0;
    printf("Ogrencilerin Bilgilerini Giriniz\n");

    while (i < n)
    {
        printf("%d. Ogrencinin Bilgilerini Giriniz \n", i + 1);
        printf("Numara: ");
        scanf("%d", &ogrenciverileri[i].numara);  
        printf("Ad: ");
        scanf("%s", ogrenciverileri[i].isim);     
        printf("Vize: ");
        scanf("%d", &ogrenciverileri[i].vize);    
        printf("Final: ");
        scanf("%d", &ogrenciverileri[i].final);  
        i++;
    }

    printf("Kayit Tamam\n");
    system("clear");
}