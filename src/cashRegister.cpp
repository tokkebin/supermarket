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

/*void cashRegister::clientQueue(client* cl)
{
    this->cashQueue.push_back(cl);
}*/
