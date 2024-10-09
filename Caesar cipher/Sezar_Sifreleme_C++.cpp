#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <string>

using namespace std;

class Sezar{

    private:
    char metin[1024];
    char SifreliMetin[1024];
    char DesifreliMetin[1024];
    char alfabe[27] = "abcdefghijklmnopqrstuvywxz";
    public:
    void sifrele();
    void desifrele();
};

void strlower(char* metin)
{
    for (int i = 0; metin[i] != '\0'; i++)
    {
       metin[i] = tolower(metin[i]);
    }
}

void Sezar :: sifrele()
{
    cout << "Sifrelemek Istediginiz Metin : ";
    cin.getline(metin,1024);
    strlower(metin);
    int length = strlen(metin);
    metin[length] = '\0';
    cout << "Girilen Metin                : "<<metin<< endl;
    int i = 0, j;
    while (i<length)
    {
        int sonuc =0;
        for(j = 0; j <26; j++)
        {
            int indis = j;
            if (metin[i] == alfabe[j])
            {
                sonuc =1;
                indis += 3;
                if (indis >= 26)
                {
                   indis = indis%26;
                }
                SifreliMetin[i] = alfabe[indis];
                break;
                
            }  
        }
        if (sonuc == 0) SifreliMetin[i] = metin[i];

        i++;
    }
    cout << "Metnin Sifrelenmis Hali      : " <<SifreliMetin<< endl;
}


void Sezar ::desifrele()
{
    int length = strlen(SifreliMetin);
    SifreliMetin[length] = '\0';
    int i = 0, j;
    while (i<length)
    {
        int sonuc =0;

        for(j = 0; j <26; j++)
        {
            int indis = j;
            if (SifreliMetin[i] == alfabe[j])
            {
                sonuc =1;
                indis -=3;
                if (indis <0)
                {
                   indis = (indis+26)%26;
                }
                DesifreliMetin[i] = alfabe[indis];
                break;
            }   
        }
        if (sonuc == 0) DesifreliMetin[i] = SifreliMetin[i];
        i++;
    }
    cout << "Desifreli Metin              : " <<DesifreliMetin<< endl;
}

int main(int argc, char** argv)
{
    Sezar s1;
    s1.sifrele();
    s1.desifrele();

    return 0;
}