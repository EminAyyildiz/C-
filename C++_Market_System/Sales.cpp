#include "Sales.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;


sales::sales(): totalPrice(0.0) {}

sales::~sales()
{
}


void sales::addCart() {
    string searchID, salesquant;
    bool found = false;
    bool stockokey = false;
    ostringstream updatedContent;

    cout << "--- PRODUCT SALES ---" << endl;
    cout << "Product ID : "; 
    cin >> searchID;

    ifstream file("Market.txt");
    if (!file) 
    {
        cout << "Error: Could not open the Market.txt file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        istringstream ss(line);
        string id, name, quantity, price;
        getline(ss, id, '/'); 
        getline(ss, name, '/');
        getline(ss, quantity, '/'); 
        getline(ss, price, '/');

        if (trim(id) == searchID) 
        {
            found = true;
            cout << "Product found:\nID: " << id << "\nName: " << trim(name)<< "\nQuantity: " << trim(quantity) << "\nPrice: " << trim(price) << endl;

            cout << "Quantity to add to cart: ";
            cin >> salesquant;

            int currentQty = stoi(trim(quantity));
            int qtyToSell = stoi(salesquant);

            if (qtyToSell > currentQty or qtyToSell<= 0) 
            {
                cout << "Error: Not enough stock available!" << endl;
                return;
            }

            stockokey = true;
            if(stockokey &&found)
            {
                ofstream tempCart("tempCart.txt", ios::app); 
                if (!tempCart) 
                {
                    cout << "Error: Could not create tempCart.txt." << endl;
                    return;
                }
                int newQty = currentQty - qtyToSell;
                updatedContent << id << '/' << name << '/' << newQty << '/' << price << '\n';
                tempCart << id << '/' << name << '/' << qtyToSell << '/' << price << '\n';
                tempCart.close();
            }
        } 

        else {  updatedContent << line << '\n'; }
    }

    file.close();

    if (found && stockokey) 
    {
        ofstream file("Market.txt");
        file << updatedContent.str();
        cout << "Product successfully added to cart!" << endl;
    } 

    else { cout << "Product with ID " << searchID << " not found." << endl;  }
    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}


void sales::removeCart() 
{
    ifstream inputfile("tempCart.txt");
    ofstream outputfile("newtemp.txt");

    if (!inputfile.is_open() || !outputfile.is_open()) 
    {
        cout << "Error: Could not open files." << endl;
        return;
    }

    string inID;
    cout << "Enter the ID of the product you want to remove: ";
    cin >> inID;

    string line;
    bool found = false;
    int removedQuantity = 0;

    while (getline(inputfile, line)) 
    {
        istringstream ss(line);
        string ID, name, quantity, price;

        getline(ss, ID, '/');
        getline(ss, name, '/');
        getline(ss, quantity, '/');
        getline(ss, price, '/');

        if (trim(ID) == trim(inID)) 
        {
            found = true;
            removedQuantity = stoi(trim(quantity));  
        } 
        else { outputfile << line << endl;  }
    }

    inputfile.close();
    outputfile.close();

    if (found) 
    {
        remove("tempCart.txt");
        rename("newtemp.txt", "tempCart.txt");

        cout << "Product with ID " << inID << " has been removed." << endl;
        updateStock(inID, removedQuantity);  
    } 
    else 
    {
        remove("newtemp.txt");
        cout << "No product found with ID " << inID << "." << endl;
    }
    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();

}


void sales::updateStock(const string& productID, int updatequant) 
{
    ifstream file("Market.txt");
    ofstream file2("NewMarket.txt");

    if (!file.is_open() || !file2.is_open()) 
    {
        cout << "Error: Could not open Market files." << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        istringstream ss(line);
        string id, name, quantity, price;
  
        if (trim(id) == productID) 
        {
            int newQuantity = stoi(trim(quantity)) + updatequant;
            file2 << id << '/' << name << '/' << newQuantity << '/' << price << '\n';
        } 
        else 
        {
            file2 << line << '\n'; 
        }
    }

    file.close();
    file2.close();

    remove("Market.txt");
    rename("NewMarket.txt", "Market.txt");

    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}

void sales::showcart()
{
   ifstream file("tempCart.txt");  
    if (!file.is_open()) 
    {
        cout << "Error: Could not open the cart file." << endl;
        return;
    }

    string line;
    totalPrice = 0.0;  

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

        int qty = stoi(trim(quantity));  
        double prc = stod(trim(price)); 

        totalPrice += qty * prc; 

        cout << left << setw(10) << trim(id) << setw(20) << trim(name) << setw(10) << qty << setw(10) << fixed << setprecision(2) << prc << endl;
    }

    file.close();  
    cout << string(50, '-') << endl;
    cout << "TOTAL PRICE: " << fixed << setprecision(2) << totalPrice << endl;

    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}

void sales::completeSale()
{
    ofstream file("allSales.txt", ios::app);
    if(!file) { cout<< "Error: Could not open allSales File."<< endl;  }

    if (remove("tempCart.txt") != 0) { cout << "Error: Could not delete the tempCart file." << endl;  } 

    else 
    {
        if (totalPrice >0)
        { 
            file << "Sale #" << to_string(time(0))
             << " - Total Amount: "
            << fixed << setprecision(2) << totalPrice << " TL" << endl;
            file.close();
            cout << "--- SALE COMPLETED ---" << endl;
            cout << "Total Amount: " << fixed << setprecision(2) << totalPrice << " TL" << endl;
        }
    }
    totalPrice = 0.0;
    
    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}

void sales:: ShowAllSales()
{
    ifstream file("allSales.txt");  
    if (!file.is_open()) 
    {
        cout << "Error: Could not open the cart file." << endl;
        return;
    }
    cout << "--- ALL SALES RECORDS ---" << endl;

    string line;
    while (getline(file, line)) 
    {
        cout << line << endl; 
    }

    file.close();  

    cout << "Press Any Key to Continue...." << endl;
    cin.ignore();
    cin.get();
}


string sales::trim(const string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

