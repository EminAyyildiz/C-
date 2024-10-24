#include "MusteriBilgi.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

MusteriBilgi::MusteriBilgi(/* args */)
{
    strcpy(tcNo, "");
    strcpy(adSoyad, "");
    strcpy(adress, "");
    strcpy(telefon, "");
    strcpy(sifre, "");
    bakiye = 0.0;

}

MusteriBilgi::~MusteriBilgi()
{
}


MusteriBilgi:: MusteriBilgi(char* tcNum, char* AdSoyad, char* adres, char* tel, char* pass, float bk)
{
    strcpy(tcNo, tcNum);
    strcpy(adSoyad, AdSoyad);
    strcpy(adress, adres);
    strcpy(telefon, tel);
    strcpy(sifre, pass);
    bakiye = bk;

}

void MusteriBilgi:: settcNO(char* ptr)
{
    strcpy(tcNo, ptr);
}
char* MusteriBilgi:: gettcNO()
{
    return tcNo;
}
void MusteriBilgi:: setadSoyad(char* ptr)
{
    strcpy(adSoyad, ptr);
}
char* MusteriBilgi:: getadSoyad()
{
    return adSoyad;
}
void MusteriBilgi:: setadres(char* ptr)
{
    strcpy(adress, ptr);
}
char* MusteriBilgi:: MusteriBilgi:: getadres()
{
    return adress;
}
void MusteriBilgi:: settel(char* ptr)
{
    strcpy(telefon, ptr);
}
char* MusteriBilgi:: gettel()
{
    return telefon;
}
void MusteriBilgi:: setsifre(char* ptr)
{
    strcpy(sifre, ptr);
}
char* MusteriBilgi:: getsifre()
{
    return sifre;
}
void MusteriBilgi:: setbakiye(float bk)
{
    bakiye = bk;
}
float MusteriBilgi:: getbakiye()
{
    return bakiye;
}