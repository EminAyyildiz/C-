#include "MusteriIslem.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "fstream"

using namespace std;

MusteriIslem::MusteriIslem()
{
}

MusteriIslem::~MusteriIslem()
{
} 


MusteriIslem:: MusteriIslem(MusteriBilgi musteriptr)
{
    musteri = musteriptr;
}

void MusteriIslem:: paracek()
{
    system("clear");
    float miktar;
    char DosyaAdi[20];
    cout <<"Withdraw Money"<<endl<<endl;
    cout <<"Balance : " <<musteri.getbakiye()<<"TL"<<endl<<endl;

    cout <<"Enter the Amount You Want to Withdraw : "; cin>> miktar;

    if (miktar >musteri.getbakiye())
    {
        cout <<"Insufficient Balance" <<endl;
    }
    else
    {
        musteri.setbakiye(musteri.getbakiye()-miktar);
        strcpy(DosyaAdi, musteri.gettcNO());
        strcat(DosyaAdi, ".txt");
        ofstream file(DosyaAdi);
        file.write((char*)&musteri, sizeof(MusteriBilgi));
        file.close();
        cout <<"Withdrawal Successfully Completed..."<<endl;
        hareketlerikaydet(musteri.gettcNO(),miktar, nullptr, nullptr, " TL -- WITHDRAWAL -- NEW BALANCE : ",musteri.getbakiye());


    }

    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

void MusteriIslem:: paraYatir()
{
    system("clear");
    float miktar;
    char DosyaAdi[20];
    cout <<"INVESTMENT.."<<endl<<endl;
    cout <<"BALANCE : " <<musteri.getbakiye()<<"TL"<<endl<<endl;

    cout <<"Enter the Amount You Want to Investment : "; cin>> miktar;

    musteri.setbakiye(musteri.getbakiye()+miktar);
    strcpy(DosyaAdi, musteri.gettcNO());
    strcat(DosyaAdi, ".txt");
    ofstream file(DosyaAdi);
    file.write((char*)&musteri, sizeof(MusteriBilgi));
    file.close();
    cout <<"Investment Completed Successfully..."<<endl;
    hareketlerikaydet(musteri.gettcNO(),miktar, nullptr, nullptr, " TL -- Investment -- New Balance : ", musteri.getbakiye());

    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

void MusteriIslem:: bakiyeSorgula()
{
    system("clear");
    cout <<"BALANCE INQUIRY"<<endl<<endl;
    cout <<"BALANCE : " <<musteri.getbakiye()<<"TL"<<endl<<endl;
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

void MusteriIslem::havaleyap() {
    system("clear");

    float miktar;
    char DosyaAdi[20], DosyaAdi2[20];  
    char hesap[20];                    

    cout << "TRANSFER/EFT" << endl << endl;
    cout << "BALANCE : " << musteri.getbakiye() << " TL" << endl << endl;

    cout << "Enter the Amount You Want to Send : ";
    cin >> miktar;

    if (miktar <= 0) {
        cout << "Invalid Amount!" << endl;
        return;
    }

    if (miktar > musteri.getbakiye()) {
        cout << "Insufficient Balance" << endl;
        return;
    }

    cout << "Enter the Recipient's Account Number : ";
    cin >> hesap;


    strcpy(DosyaAdi2, hesap);
    strcat(DosyaAdi2, ".txt");

    
    ifstream aliciDosya(DosyaAdi2, ios::binary);
    if (!aliciDosya.is_open()) {
        cout << "Incorrect Account Number..." << endl;
        return;
    }

    MusteriBilgi alici;
    aliciDosya.read((char*)&alici, sizeof(MusteriBilgi));
    aliciDosya.close();

  
    alici.setbakiye(alici.getbakiye() + miktar);
    hareketlerikaydet(alici.gettcNO(),miktar, "TL TRANSFER/EFT Received by ",musteri.getadSoyad(), "New Balance : ", alici.getbakiye());

  
    ofstream aliciDosyaYaz(DosyaAdi2, ios::binary);
    if (!aliciDosyaYaz.is_open()) {
        cout << "Operation Failed! Recipient information could not be saved." << endl;
        return;
    }
    aliciDosyaYaz.write((char*)&alici, sizeof(MusteriBilgi));
    aliciDosyaYaz.close();

   
    musteri.setbakiye(musteri.getbakiye() - miktar);
    hareketlerikaydet(musteri.gettcNO(), miktar, "TL TRANSFER/EFT Made to",alici.getadSoyad(), " New Balance: ", musteri.getbakiye());
 
    strcpy(DosyaAdi, musteri.gettcNO());
    strcat(DosyaAdi, ".txt");

    ofstream gonderenDosya(DosyaAdi, ios::binary);
    if (!gonderenDosya.is_open()) {
        cout << "Operation Failed! Sender information could not be saved." << endl;
        return;
    }
    gonderenDosya.write((char*)&musteri, sizeof(MusteriBilgi));
    gonderenDosya.close();

    cout << "TRANSFER/EFT Successfully Completed.." << endl;

    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}

void MusteriIslem:: hareketlerikaydet(char* ptr, float miktar,  char* mesajkisi, char* kisi,  char* mesaj, float bakiy)
{

    
    char DosyaAdi[20];

    strcpy(DosyaAdi, ptr);
    strcat(DosyaAdi, "rapor.txt");
    
    ofstream file(DosyaAdi, ios:: app);
    if (kisi != nullptr && mesajkisi != nullptr) {
        file << miktar << " "<< mesajkisi << " " << kisi<<" "<< mesaj << bakiy << std::endl;
    } else {
        file << miktar << " " << mesaj <<" "<< bakiy << std::endl;
    }


    file.close();


}

void MusteriIslem:: hesaphareketleri()
{
    system("clear");
    char DosyaAdi[20];

    cout <<"ACCOUNT ACTIVITIES"<<endl<<endl;
    strcpy(DosyaAdi, musteri.gettcNO());
    strcat(DosyaAdi, "rapor.txt");
    
    ifstream file(DosyaAdi);
    char harf;
    while (file.get(harf))
    {
        cout << harf;
    }
    file.close();
    
    
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();
}

void MusteriIslem:: sifredegis()
{
    system("clear");
    char DosyaAdi[20], eskisifre[20], yenisifre[20];
    cout <<"CHANGE PASSWORD"<<endl<<endl;
    cout << "Enter the Password You Want to Change : "; scanf(" %[^\n]s", eskisifre);

    strcpy(DosyaAdi, musteri.gettcNO());
    strcat(DosyaAdi, ".txt");
    ifstream file(DosyaAdi);
    file.read((char*)&musteri, sizeof(MusteriBilgi));
   

    if (strcmp(eskisifre,musteri.getsifre()) !=0  )
    {
        cout <<"Password to be Changed Did Not Match"<<endl<<endl;
    }
    else
    {
        file.close();

        ofstream file(DosyaAdi);
        cout << "Enter Your New Password : "; scanf(" %[^\n]s", yenisifre);
        musteri.setsifre(yenisifre);
        file.write((char*)&musteri, sizeof(MusteriBilgi));
        file.close();
        cout<<"Password Changed Successfully"<< endl;


    }
    
    cout<<"Press Any Key to Continue...."<< endl;
    cin.ignore();
    cin.get();


}

int  MusteriIslem:: musterimenu()
{
    system("clear");
    int choice;
    cout<<"CUSTOMER CONTROL PAGE"<<endl<<endl;
    cout<<"DEAR "<<musteri.getadSoyad()<<" WELCOME"<<endl;
    cout<<"Account Number : "<<musteri.gettcNO()<<endl<<endl;

    cout<<"[1] WITHDRAW MONEY"<<endl;
    cout<<"[2] INVESTMENT MONEY"<<endl;
    cout<<"[3] BALANCE INQUIRY "<<endl;
    cout<<"[4] MAKE TRANSFER/EFT"<<endl;
    cout<<"[5] ACCOUNT ACTIVITIES "<<endl;
    cout<<"[6] CHANGE PASSWORD"<<endl;
    cout<<"[0] EXIT "<<endl;
    cout<<"Choice : ";
    cin>>choice;
    return choice;
}

void MusteriIslem:: musteriGiris(MusteriBilgi ptrmust)
{
    musteri = ptrmust;
    int choice = musterimenu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 1: paracek(); break;
        case 2: paraYatir(); break;
        case 3: bakiyeSorgula(); break;
        case 4: havaleyap(); break;
        case 5: hesaphareketleri(); break;
        case 6: sifredegis(); break;

        default: 
        cout<<"Invalid Choice"<< endl; 
        cout << "Press Any Key to Continue...." << endl;
        cin.ignore();
        cin.get();
        break;

        }
        choice = musterimenu();
    }
}
