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

void cashRegister::countCost(int price)
{
    this->total = this->total + price;
}

int cashRegister::getTotal()
{
    return this->total;
}

string createPayment(payment* pay, Client* cl)
{
    //stworzymy potwierdzenie zaplaty o wybranej formie dla danego klienta
    pay->listProducts = cl->basket;
    vector<Product>::iterator it;
    for(it=pay->listProducts->begin();it!= pay->listProducts->end();it++)
    {
        //a tutaj liczymy w petli cene do zaplaty
        //oraz caly vat
    }

    if(typeid(pay)==typeid(Invoice))
    {
        string nazwa = pay->getName();
        return nazwa;
    }
    else if(typeid(pay)==typeid(Check))
    {
        string nazwa = pay->getName();
        return nazwa;
    }
    else
        throw "ZLY TYP";


}

/*void cashRegister::clientQueue(client* cl)
{
    this->cashQueue.push_back(cl);
}*/
