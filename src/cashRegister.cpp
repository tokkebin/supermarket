#include "cashRegister.h"

cashRegister::cashRegister()
{
    //ctor
}

cashRegister::~cashRegister()
{
    //dtor
}

cashRegister::cashRegister(int i)
{
    setNumber(i);
    setOpen("closed");
    this->total = 0;
}

void cashRegister::setNumber(int i)
{
    this->number = i;
}

int cashRegister::getNumber()
{
    return this->number;
}

void cashRegister::setOpen(string s)
{
    if(s == "open")
    {
        this->open = true;
        this->queueLength = 0;
    }

    if(s == "closed")
        this->open = false;
    else
        cout<<""<<endl;
}

bool cashRegister::getOpen()
{
    return this->open;
}

void cashRegister::countCost(double price)
{
    this->total = this->total + price;
}

double cashRegister::getTotal()
{
    return this->total;
}

void cashRegister::countVAT(Product& p)
{
    this->priceVAT = this->priceVAT + p.getValueVAT();
}

double cashRegister::getPriceVAT()
{
    return this->priceVAT;
}
string cashRegister::createPayment(Payment& pay, Client* cl)
{
    //stworzymy potwierdzenie zaplaty o wybranej formie dla danego klienta
    pay.listProducts = cl->basket;
    vector<Product>::iterator it;
    for(it=pay.listProducts->begin();it!= pay.listProducts->end();it++)
    {
        Product& temp = *it;

        this->countCost(temp.getPrice());
        //a tutaj liczymy w petli cene do zaplaty
        //oraz caly vat
        this->countVAT(temp);

    }
    string nazwa = "Klient nr " + to_string(cl->getNumber()) + " wybral " + pay.getName();

    if(typeid(pay)==typeid(Invoice))
    {
        string addition = " nr: "+ to_string(pay.getNumber()) +"\nDo zaplaty: " + to_string(this->getTotal()) + " w tym "+ to_string(this->getPriceVAT()) + " VAT\n";
        nazwa.append(addition);
        return nazwa;
    }
    else if(typeid(pay)==typeid(Check))
    {
        string addition = "\nDo zaplaty: " + to_string(this->getTotal()) + "\n";
        nazwa.append(addition);
        return nazwa;
    }
    else
        throw "ZLY TYP";


}

/*void cashRegister::clientQueue(client* cl)
{
    this->cashQueue.push_back(cl);
}*/
