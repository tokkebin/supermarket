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
}
