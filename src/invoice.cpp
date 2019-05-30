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


    return this->vat;
}

string Invoice::getName()
{
    return this->name;
}

void Invoice::setNumber(int i)
{
    this->number = i;
}

int Invoice::getNumber()
{
    return this->number;
}
