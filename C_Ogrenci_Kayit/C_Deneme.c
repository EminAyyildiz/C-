

#include "main.h"
#include "ogrenciekle.h"
#include "ogrencilistele.h"
#include "ogrenciguncelle.h"
#include "ortalama.h"

int menu()
{
    int secim;
    printf("1-Yeni Ogrenci Ekleme \n");
    printf("2-Kayit Listele \n");
    printf("3-Kayit Güncelle \n");
    printf("4-Sinif Ortalama Hesabi\n");
    printf("5-En Basarili Ogrenci\n");
    printf("0-EXIT\n");
    scanf("%d",&secim);
    return secim;

}

int main()
{
    int dongukontrol;
    int n;
    printf("Kac Ogrenci Kaydedilecek : ");
    scanf("%d",&n);
    dongukontrol = menu();
    Ogrenci* ogrenciverileri = (Ogrenci*)malloc(n * sizeof(Ogrenci));

    if (ogrenciverileri == NULL)
    {
        printf("Bellek tahsisi basarisiz!\n");
    }
    while(dongukontrol !=0)
    {
        if(dongukontrol ==1)
        {
            ogrenciekle(ogrenciverileri, n);
        }
        else if (dongukontrol ==2)
        {
            ogrencilistele(ogrenciverileri,n);
        }
        else if (dongukontrol ==3)
        {
            ogrencguncelle(ogrenciverileri, n);
        }
        else if( dongukontrol == 4)
        {
            ortalamabul(ogrenciverileri,n);
        }
       else if( dongukontrol == 5)
        {
            eniyiortbul(ogrenciverileri,n);
        }
    dongukontrol = menu();
    }
    return 0;
}