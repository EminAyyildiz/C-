#ifndef MUSTERIBILGI_H
#define MUSTERIBILGI_H


class MusteriBilgi
{
private:
    char tcNo[20], adSoyad[40], adress[20], telefon[20], sifre[20];
    float bakiye;

public:
    MusteriBilgi();
    ~MusteriBilgi();

    MusteriBilgi(char* tcNo, char* adSoyad, char* adres, char* telefon, char* sifre, float bakiye);

    void settcNO(char* ptr);
    char* gettcNO();
    void setadSoyad(char* ptr);
    char* getadSoyad();
    void setadres(char* ptr);
    char* getadres();
    void settel(char* ptr);
    char* gettel();
    void setsifre(char* ptr);
    char* getsifre();
    void setbakiye(float bk);
    float getbakiye();


};






#endif