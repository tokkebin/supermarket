#include "client.h"
#include "cashRegister.h"
Client::Client()
{
    //ctor
}

Client::Client(int i)
{
    this->setNumber(i);
}

Client::~Client()
{
    //dtor
}

void Client::setNumber(int i)
{
    this->number = i;
}

int Client::getNumber()
{
    return this->number;
}

bool Client::entrence(string inout)
{
    if(inout == "in")
        return true;
    else
        return false;
}

string Client::askWorker(string what,Product* p, Worker* w)
{
    if(what == "price")
        return  to_string( w->answerPrice(p));
    else
        return w->answer(what);
}

void Client::toQueue(Supermarket* market)
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

double Client::checkPrice(Product* p)
{
    return p->getPrice();
}

void Client::toBasket(Product* p)
{
    //this->basket.push_back(*p);
}
