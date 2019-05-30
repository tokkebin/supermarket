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

string Client::askWorker(string what, Worker& w)
{
    string answer;
    try
    {
        answer = w.answer(what);
    }
    catch(int i)
    {
        return "pracownik zajety";
    }

    return answer;

}

vector<cashRegister>::iterator Client::toQueue(Supermarket* market)
{
    int smallest = 100;
    cashRegister smallestQueue;

    vector<cashRegister>::iterator it,small;

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
                small = it;
            }

        }
    }
    //po znalezieniu stajemy w kolejce

    smallestQueue.cashQueue.push_back(*this);
    //market->cashList.erase(small);
    *it = smallestQueue;
    //market->cashList.push_back(smallestQueue);

    return small;

}

double Client::checkPrice(Product& p)
{
    return p.getPrice();
}

void Client::toBasket(Product& p)
{
    this->basket.push_back(p);
}
