#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "product.h"

using namespace std;

Inventory::Inventory(/* args */)
{
}

Inventory::~Inventory()
{
}

void Inventory::addProduct()
{
    system("clear");
    float input;
    char inputs[100];
    cout << "--- PRODUCT ADD ---" << endl << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Product ID        : "; cin.getline(inputs, sizeof(inputs)); prod.setID(inputs);
    cout << "Product Name      : "; cin.getline(inputs, sizeof(inputs)); prod.setName(inputs);
    cout << "Product Quantity  : "; cin.getline(inputs, sizeof(inputs)); prod.setQuant(inputs);
    cout << "Product Price     : "; cin >> input; prod.setPrice(input);

    ofstream file("Market.txt", ios::app);
    if (file.is_open()) 
    {
        file << prod.getID() << " / "<< prod.getName() << " / " << prod.getQuant() << " / "<< prod.getPrice() << " TL" << endl;
        file.close();
        cout << "Product Successfully Added" << endl << endl;
    } 
    else { cout << "Error: Could not open the file." << endl; }

    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}

void Inventory::listProducts()
{
    ifstream file("Market.txt");
    if (file.is_open()) 
    {
        string line;
        cout<<endl<<endl;
        cout << left << setw(10) << "ID" << setw(20) << "PRODUCT NAME" << setw(10) << "QUANTITY" << setw(10) << "PRICE" << endl;
        
        cout << string(50, '-') << endl;
        while (getline(file, line)) 
        {
            istringstream ss(line);
            string id, name, quantity, price;
            getline(ss, id, '/');
            getline(ss, name, '/');
            getline(ss, quantity, '/');
            getline(ss, price, '/');

            cout << left << setw(10) << trim(id) << setw(20) << trim(name) << setw(10) << trim(quantity) << setw(10) << trim(price)<< endl;
        }
        file.close();
    } 
    else {cout << "Error: Could not open the file." << endl; }
    
    cout <<endl;
    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}



void Inventory::updateProduct() 
{
    string searchID, newQuantity, newPrice;
    bool found = false;
    ostringstream updatedContent;

    cout << "--- PRODUCT UPDATE ---" << endl;
    cout << "Product ID: "; cin >> searchID;

    ifstream file("Market.txt");
    if (!file) 
    {
        cout << "Error: Could not open the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        istringstream ss(line);
        string id, name, quantity, price;
        getline(ss, id, '/'); getline(ss, name, '/');
        getline(ss, quantity, '/'); getline(ss, price, '/');
        
        if (trim(id) == searchID) 
        {
            found = true;
            cout << "Product found : \nID: " << id << "\nName: " << trim(name) << "\nQuantity: " << trim(quantity) << "\nPrice: " << trim(price) << endl;

            cout << "New Quantity  : "; cin >> newQuantity;
            cout << "New Price     : "; cin >> newPrice;
            updatedContent << id << " / " << name << " / " << newQuantity << " / " << newPrice << " TL\n";
        } 
        else { updatedContent << line << '\n';}
    }

    if (found) 
    {
        ofstream outFile("Market.txt");
        outFile << updatedContent.str();
        cout << "Product successfully updated!" << endl;
    } 
    else { cout << "Product with ID " << searchID << " not found." << endl;}

    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}

string Inventory::trim(const string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
