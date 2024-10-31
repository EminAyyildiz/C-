#include "product.h"
#include <cstring> 
#include <iostream>


product::product(/* args */)
{
    strcpy(ID, "");
    strcpy(NAME, "");
    price = 0.0;
    strcpy(quantity, "");
}

product::~product(){}

product::product(char* Id, const char* name, float prc, char* quant)
{
    strcpy(ID,Id);
    strcpy(NAME, name);   
    price = prc;
    strcpy(quantity, quant);
}


void product::setID(char* ptr)
{
    strcpy(ID,ptr);
}
char* product::getID()
{
    return ID;
}

void product::setName(const char* name)
{
    strcpy(NAME,name);
}
const char* product::getName() const
{
    return NAME;
}

void product::setPrice(float prc)
{
    price = prc;
}
float product::getPrice()
{
    return price;
}

void product::setQuant(char* ptr)
{
    strcpy(quantity, ptr);
}
char* product::getQuant()
{
    return quantity;
}