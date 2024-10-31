#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "product.h"

using namespace std;

class Inventory
{
private:
    vector<product> products;
    product prod;
public:
    Inventory(/* args */);
    ~Inventory();
    void addProduct();
    void listProducts();
    string trim(const string& str);
    void updateProduct();

};





#endif