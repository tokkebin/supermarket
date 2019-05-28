#include "productVAT23.h"

productVAT23::productVAT23()
{
    //ctor
}

productVAT23::~productVAT23()
{
    //dtor
}

productVAT23::productVAT23(int n, string nazwa, double p)
{
    this->name = nazwa;
    this->number = n;
    if(p == 0.0)
        setPrice();
    else
        this->price = p;
        this->valueVAT = p*(this->VAT)/(100+this->VAT);
}

void productVAT23::setName(string n)
{
    this->name = n;
}

string productVAT23::getName()
{
    return this->name;
}

void productVAT23::setNumber(int i)
{
    this->number = i;
}

int productVAT23::getNumber()
{
    return this->number;
}
