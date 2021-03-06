#include "worker.h"
#include "cashRegister.h"
#include "supermarket.h"
Worker::Worker()
{
    //ctor
}

Worker::Worker(int a)
{
    this->set_number(a);
}

Worker::~Worker()
{
    //dtor
}

void Worker::set_number(int a)
{
    this->number = a;
}

int Worker::get_number()
{
    return this->number;
}

void Worker::setBusy(bool i)
{
    this->busy = i;
}

bool Worker::getBusy()
{
    return this->busy;
}

string Worker::answer(string question)
{
    string answer;
    if(question == "godziny otwarcia")
    {
        answer = "od 8 do 20";
    }
    else if(this->busy)
    {
        throw 0;
    }
    else
        answer = "nie wiem";

    return answer;

}

/*double Worker::answerPrice(Product* p)
{
    return p->getPrice();
}*/

int Worker::countProduct(vector<Product>* v)
{
    return v->size();
}

void Worker::setOpen(cashRegister& cash)
{
    cash.setOpen("open");
}

void Worker::setClosed(cashRegister* cash)
{
    cash->setOpen("closed");
}

void Worker::closeMarket(Supermarket* market)
{
    market->close();
}
