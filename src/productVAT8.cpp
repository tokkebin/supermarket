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

productVAT8::productVAT8(int n, string nazwa, double p)
{
    // konstruktor z parametrami
    //ustawiamy numer, nazwe i cene
    this->number = n;
    this->name = nazwa;
    if(p==0)
        setPrice();
    else
        this->price = p;
}

void productVAT8::setName(string s)
{
    this->name = s;
}

void productVAT8::setNumber(int i)
{
    this->number = i;
}


/*int productVAT8::getVAT()
{
    return this->VAT;
}*/
