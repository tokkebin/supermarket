#include "product.h"

product::product()
{
    //ctor
}



void product::setPrice()
{
    int netto = (rand() % 50 ) + 7;
    this->price = double(netto) + (netto*(this->VAT)/100);
}

double product::getPrice()
{
    return this->price;
}
