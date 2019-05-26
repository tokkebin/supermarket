#include "client.h"

client::client()
{
    //ctor
}

client::~client()
{
    //dtor
}

void client::setNumber(int i)
{
    this->number = i;
}

int client::getNumber()
{
    return this->number;
}

bool client::entrence(string inout)
{
    if(inout == "in")
        return true;
    else
        return false;
}

string client::askWorker(string what,product* p, worker* w)
{
    if(what == "price")
        return  to_string( w->answerPrice(p));
    else
        return w->answer(what);
}

void client::toQueue(supermarket* market)
{
    int smallest = 100;
    int smallestQueue;

    for(int i=market.cashList.begin();i!=market.cashList.end();i++)
    {
        cashRegister temp = *i;
        if(temp.getOpen())
        {
            if(temp.queueLength<smallest)
            {
                smallest = temp.queueLength;
                smallestQueue = temp.getNumber();
            }

        }
    }



}

double client::checkPrice(product* p)
{
    return p.getPrice();
}
