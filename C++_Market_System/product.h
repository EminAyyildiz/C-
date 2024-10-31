#ifndef PRODUCT_H
#define PRODUCT_H


class product
{
private:
    char ID[50];
    char NAME[50];
    float price;
    char quantity[50];
public:
    product(/* args */);
    ~product();
    product(char* ID, const char* name, float price, char* quant);

    void setID(char* ID);
    char* getID();

    void setName(const char* name);
    const char* getName() const ;

    void setPrice(float price);
    float getPrice();

    void setQuant(char* quantitiy);
    char* getQuant();
};







#endif