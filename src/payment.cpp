#include "payment.h"

Payment::Payment()
{
    //ctor
}

Payment::~Payment()
{

}

void Payment::setPayment(double total)
{
    this->price = total;
}

double Payment::getPayment()
{
    return this->price;
}
/*payment* payment::choosePayment(payment* choose, typedef typ)
{
    if(typeid(choose)==invoice) //chyba ze sprawdzenie w kasie
        return invoice;
    if(typeid(choose)==check)
        return check;
}*/
