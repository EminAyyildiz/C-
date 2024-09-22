#include "ogrenciguncelle.h"

  
void ogrencguncelle(Ogrenci* ogrenciverileri, int n)
{
    system("clear");
    int numara;
    int i = 0;
    int bulundu = 0;

    printf("Kaydini Guncellemek Istediginiz Ogrencinin Numarasini Griniz : ");
    scanf("%d", &numara);

    while (i < n)
    {
        if (ogrenciverileri[i].numara == numara)
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
            bulundu = 1;

            break;
        }
        i++;
    }

    
    if (bulundu == 0)
    {
        printf("%d Numarali Ogrenci Bulunamadi...\n", numara);
    }
}