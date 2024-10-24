#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "fstream"
#include "AnaMenu.h"
#include "MusteriIslem.h"
#include "yetkili.h"

using namespace std;

AnaMenu::AnaMenu(/* args */)
{
}

AnaMenu::~AnaMenu()
{
}


void AnaMenu:: Yetkili_Kontrol()
{
    system("clear");
    char username[20], paswrd[20];
    cout <<"ADMIN CONTROL PANEL"<<endl<<endl;
    cout <<"USERNAME    : " ; scanf( " %[^\n]s", username);
    cout <<"PASSWORD    : " ; scanf( " %[^\n]s", paswrd);

    if((strcmp(username, "admin") == 0) && (strcmp(paswrd, "0000") == 0))
    {
        yetkili yet;
        yet.YetkiliGiris();
    }
    else
    {
       cout <<"Incorrect Username or Password..."<<endl<<endl; 
    }

    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();

}
void AnaMenu:: Musteri_Kontrol()
{
    char username[20], paswrd[20], DosyaAdi[20];
    cout <<"CUSTOMER CONTROL PANEL"<<endl<<endl;
    cout <<"USERNAME / ID NO  : " ; scanf( " %[^\n]s", username);
    cout <<"PASSWORD          : " ; scanf( " %[^\n]s", paswrd);

    strcpy(DosyaAdi, username);
    strcat(DosyaAdi, ".txt");
    ifstream file(DosyaAdi);
    file.read((char*)&bm, sizeof(MusteriBilgi));
    if(!file.is_open())
    {
        cout <<"Username/ID Number or Password is Incorrect.." <<endl;
    }
    else
    {
            if ((strcmp(username,bm.gettcNO()) == 0))
            {
                MusteriIslem mustislem;
                mustislem.musteriGiris(bm);
            }
            else
            {
                cout <<"Incorrect ID No or Password..." <<endl;
            }

    }


    

    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();

}
int  AnaMenu:: menu()
{
    system("clear");
    int choice;
    cout<<"WELCOME TO OUR BANK "<<endl<<endl;
 

    cout<<"[1] ADMIN CONTROL PANEL "<<endl;
    cout<<"[2] CUSTOMER CONTROL PANEL "<<endl;
    cout<<"[0] EXIT "<<endl;
    cout<<"Choice : ";
    cin>>choice;
    return choice;
}
void AnaMenu:: giris()
{
    int choice = menu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 1: Yetkili_Kontrol(); break;
        case 2: Musteri_Kontrol(); break;
        case 0: break;
        default: 
        cout<<"Invalid Choice"<< endl; 
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();
        break;

        }
        choice = menu();
    }
}