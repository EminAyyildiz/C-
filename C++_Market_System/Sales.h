
#ifndef SALES_H
#define SALES_H

#include <string> 

using namespace std;

class sales
{
private:
    double totalPrice;
public:
    sales(/* args */);
    ~sales();
    
    void addCart();
    void removeCart();
    void showcart();
    void completeSale();
    void ShowAllSales();
    void updateStock(const string& productID, int updatequant);
    string trim(const string& str);
};




#endif
