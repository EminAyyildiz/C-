#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "yetkili.h"
#include "fstream"
using namespace std;


yetkili::yetkili()
{
}

yetkili::~yetkili()
{

}


void yetkili:: MusteriEkle()
{
    system("clear");
    char inputs[100];
    float bakiye;
    cout<< "REGISTER CUSTOMER" << endl<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Customer ID Number    : "; cin.getline(inputs, sizeof(inputs)); musteri.settcNO(inputs);
    cout<<"Customer Name Surname : "; cin.getline(inputs, sizeof(inputs)); musteri.setadSoyad(inputs);
    cout<<"Customer Adress       : "; cin.getline(inputs, sizeof(inputs)); musteri.setadres(inputs);
    cout<<"Customer Phone        : "; cin.getline(inputs, sizeof(inputs)); musteri.settel(inputs);
    musteri.setsifre(musteri.gettcNO());
    cout<<"Customer Balance      : "; scanf(" %f", &bakiye); musteri.setbakiye(bakiye);

    char DosyaAdi[40];
    strcpy(DosyaAdi, +musteri.gettcNO());
    strcat(DosyaAdi, ".txt");

    ofstream file(DosyaAdi);
    file.write((char*)&musteri, sizeof(MusteriBilgi));
    file.close();

    cout<<"Customer Successfully Registered"<< endl<<endl;
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();

}

void yetkili:: MusteriSil()
{
    system("clear");
    char inputs[30];
    cout<<"DELETE CUSTOMER" << endl<<endl;
    cout<<"Customer ID Number    : "; scanf(" %[^\n]s", inputs);

    char DosyaAdi[40];
    strcpy(DosyaAdi, +inputs);
    strcat(DosyaAdi, ".txt");

    ifstream file(DosyaAdi);
    if(!file.is_open())
    {
        cout<< inputs<<" Customer ID Not Found...."<< endl;

    }
    else
    {
        char choicee;
        file.read((char*)&musteri, sizeof(MusteriBilgi));
        cout<<"Customer Name Surname : "<< musteri.getadSoyad()<<endl;
        cout<<"Customer Adress       : "<< musteri.getadres()<<endl;;
        cout<<"Customer Phone        : "<< musteri.gettel()<<endl;;
        cout<<"Customer Balance      : "<< musteri.getbakiye()<<endl<<endl;

        file.close();

        cout<<"Do You Want to Delete Customer?[Y/N] : ";
        cin >>choicee;
        if (choicee == 'Y' or choicee == 'y')
        {
            remove(DosyaAdi);
            cout<<"Customer Successfully Deleted.."<<endl<<endl;
        }
        else cout<<"Delete Operation Canceled..."<<endl<<endl;
        
    }

    file.close();
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

void yetkili:: MusteriAra()
{
    system("clear");
    char inputs[30];
    cout<< "SEARCH CUSTOMER" << endl<<endl;
    cout<<"Customer ID Number   : "; scanf(" %[^\n]s", inputs);

    char DosyaAdi[40];
    strcpy(DosyaAdi, +inputs);
    strcat(DosyaAdi, ".txt");

    ifstream file(DosyaAdi);
    if(!file.is_open())
    {
        cout<< inputs<<" Customer ID Not Found...."<< endl;

    }
    else
    {
        file.read((char*)&musteri, sizeof(MusteriBilgi));
        cout<<"Customer Name Surname : "<< musteri.getadSoyad()<<endl;
        cout<<"Customer Adress       : "<< musteri.getadres()<<endl;;
        cout<<"Customer Phone        : "<< musteri.gettel()<<endl;;
        cout<<"Customer Balance      : "<< musteri.getbakiye()<<endl;
    }

    file.close();
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

void yetkili:: MusteriGuncelle()
{
    system("clear");
    char inputs[30];
    cout<< "CUSTOMER UPDATE " << endl<<endl;
    cout<<"Customer ID No:   : "; scanf(" %[^\n]s", inputs);

    char DosyaAdi[40];
    strcpy(DosyaAdi, +inputs);
    strcat(DosyaAdi, ".txt");

    ifstream file(DosyaAdi);
    if(!file.is_open())
    {
        cout<< inputs<<" Customer ID Not Found...."<< endl;

    }
    else
    {
        cout<<"Customer Name Surname : "<< musteri.getadSoyad()<<endl;
        cout<<"Customer Adress       : "<< musteri.getadres()<<endl;;
        cout<<"Customer Phone        : "<< musteri.gettel()<<endl;;
        cout<<"Customer balance      : "<< musteri.getbakiye()<<endl<<endl;

        cout<<"UPDATE CUSTOMER INFORMATION"<<endl<<endl;

        cout<<"Customer Adres        : "; scanf(" %[^\n]s", inputs); musteri.setadres(inputs);
        cout<<"Customer Phone        : "; scanf(" %[^\n]s", inputs); musteri.settel(inputs);

        file.close();

        ofstream file(DosyaAdi);
        file.write((char*)&musteri, sizeof(MusteriBilgi));
        file.close();
        
    }

    file.close();
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

int  yetkili:: YetkiliMenu()
{
    system("clear");
    int choice;
    cout<<"ADMMIN CONTROL PAGE"<<endl<<endl;
    cout<<"[1] REGISTER CUSTOMER"<<endl;
    cout<<"[2] DELETE   CUSTOMER"<<endl;
    cout<<"[3] SEARCH   CUSTOMER"<<endl;
    cout<<"[4] UPDATE   CUSTOMER"<<endl;
    cout<<"[0] EXIT"<<endl;
    cout<<"Choice : ";
    cin>>choice;
    return choice;

}

void yetkili:: YetkiliGiris()
{
    int choice = YetkiliMenu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 1: MusteriEkle(); break;
        case 2: MusteriSil(); break;
        case 3: MusteriAra(); break;
        case 4: MusteriGuncelle(); break;

        default: 
        cout<<"Invalid Choice"<< endl; 
        cout << "Press Any Key to Continue...." << endl;
        cin.ignore();
        cin.get();
        break;

        }
        choice = YetkiliMenu();
    }
    
}