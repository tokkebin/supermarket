#include "invoice.h"

Invoice::Invoice()
{
    //ctor
}

Invoice::~Invoice()
{
    //dtor
}

double Invoice::getVAT()
{
    //liczymy vat dla calej listy produktow
    double vat;
    this->listProducts;
    return vat;
}

string Invoice::getName()
{
    return this->name;
}
