#include "worker.h"

worker::worker()
{
    //ctor
}

worker::~worker()
{
    //dtor
}

void worker::set_number(int a)
{
    this->number = a;
}

int worker::get_number()
{
    return this->number;
}

void worker::setBusy(bool i)
{
    this->busy = i;
}

bool worker::getBusy()
{
    return this->busy;
}

string worker::answer(string question)
{
    string answer;
    switch(question)
    {
    case "":
        return answer="costam";
    }
}

double worker::answerPrice(product* p)
{
    return p->getPrice();
}

int worker::countProduct(vector<product>* v)
{
    return v.size();
}

void worker::setOpen(cashRegister* cash)
{
    cash.setOpen("open");
}

void worker::setClosed(cashRegister* cash)
{
    cash.setOpen("closed");
}
