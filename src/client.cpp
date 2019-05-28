#include "client.h"
#include "cashRegister.h"
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
    cashRegister smallestQueue;

    vector<cashRegister>::iterator it;

    for(it=market->cashList.begin();it!=market->cashList.end();it++)
    {
        //szukamy najmniejszej kolejki wsrod otwartych kas
        cashRegister temp = *it;
        if(temp.getOpen())
        {
            if(temp.queueLength<smallest)
            {
                smallest = temp.queueLength;
                smallestQueue = *it;
            }

        }
    }
    //po znalezieniu stajemy w kolejce

    smallestQueue.cashQueue->push_back(*this);


}

double client::checkPrice(product* p)
{
    return p->getPrice();
}
