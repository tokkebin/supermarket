#include "product.h"

Product::Product()
{
    //ctor
}

void Product::setPrice()
{
    int netto = (rand() % 50 ) + 7;
    this->valueVAT = netto*(this->VAT)/100;
    this->price = double(netto) + (netto*(this->VAT)/100);
}

double Product::getPrice()
{
    return this->price;
}

void Product::setValueVAT()
{
    this->valueVAT = (this->price)*(this->VAT)/((this->VAT)+100);
}

double Product::getValueVAT()
{
    return this->valueVAT;
}
//void product::
