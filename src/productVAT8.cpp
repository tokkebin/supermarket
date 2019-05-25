#include "productVAT8.h"

productVAT8::productVAT8()
{
    setVAT();
    //ctor
}

productVAT8::~productVAT8()
{
    //dtor
}

void productVAT8::setName(string s)
{
    this->name = s;
}

void productVAT8::setNumber(int i)
{
    this->number = i;
}

void productVAT8::setPrice()
{
    this->price = ((rand() % 50 ) + 7)*(this->VAT)/100;
}

/*int productVAT8::getVAT()
{
    return this->VAT;
}*/
