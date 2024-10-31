#include "Menu.h"
#include <iostream>
#include "Inventory.h"
#include "Sales.h"
using namespace std;

Menu::Menu(/* args */) {}

Menu::~Menu() {}

Inventory inv;
sales sls;
void Menu::product_control()
{
    int choice;
    
    while (true)  
    {
        system("clear");
        cout << "\n--- PRODUCT CONTROL PANEL --- " << endl;
        cout << "1. ADD PRODUCT " << endl;
        cout << "2. LIST PRODUCT " << endl;
        cout << "3. UPDATE PRODUCT " << endl;
        cout << "0. EXIT " << endl;
        cout << "Your Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1: inv.addProduct();             break;
            case 2: inv.listProducts();           break;
            case 3: inv.updateProduct();          break;

            case 0: cout << "Exiting..." << endl; return;  
            
            default:
                cout << "Invalid Choice" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
        }
    }
}

void Menu:: loginControl()
{
    system("clear");
    char username[20];
    char password[20];

    cout << "\n--- MARKET LOGIN CONTROL PANEL --- " << endl<<endl;
    cout << "USERNAME  : ";
    cin>>username;

    cout << "PASSWORD  : ";
    cin>>password;

    if ((strcmp(username, "admin") == 0) && (strcmp(password, "0000") == 0))
    {
        Menu menu;
        menu.menugiris();
    }
    else { cout <<"Incorrect Username or Password..."<<endl<<endl; }
    
}

void Menu::product_sales() 
{
    int choice;
    while (true) 
    {
        system("clear");
        cout << "\n--- SALES MENU ---\n";
        cout << "1. ADD TO CART " << endl;
        cout << "2. SHOW CART" << endl;
        cout << "3. REMOVE PRODUCT FROM CART" << endl;
        cout << "4. COMPLETE SALE" << endl;
        cout << "5. SHOW ALL SALES"<< endl;
        cout << "0. MAIN MENU " << endl;
        cout << "Your Choice : ";
        cin >> choice;

        switch (choice) 
        {
            case 1: sls.addCart();                 break;
            case 2: sls.showcart();                break;
            case 3: sls.removeCart();              break;
            case 4: sls.completeSale();            break;
            case 5: sls.ShowAllSales();            break;
            case 0: cout << "Exiting..." << endl;  return;

            default:
                cout << "Invalid Choice" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
        }
    }
}


int Menu::menu()
{
    system("clear");
    int choice;
    cout << "WELCOME TO MARKET SYSTEM " << endl << endl;
    cout << "[1] PRODUCT CONTROL PANEL " << endl;
    cout << "[2] PRODUCT SALES PANEL " << endl;
    cout << "[0] EXIT " << endl;
    cout << "Choice : ";
    cin >> choice;
    return choice;
}

void Menu::menugiris()
{
    int choice = menu();
    while (choice != 0)
    {
        switch (choice)
        {
            case 1: product_control(); break;
            case 2: product_sales();   break;
            case 0:                    return;

            default:
                cout << "Invalid Choice" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
        }
        choice = menu();
    }

}
