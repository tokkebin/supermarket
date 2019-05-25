#include "supermarket.h"

supermarket::supermarket()
{
    //ctor
}

supermarket::~supermarket()
{
    //dtor
}

supermarket::supermarket(int n,int m)
{
    createCash(n);
    createWorker(m);
}

void supermarket::createCash(int n)
{
    for (int i=0;i<n;i++)
    {
        cashRegister* cash = new cashRegister(i);
        //tworzymy nowa kase i dodajemy do vectora
    }
}


void supermarket::createWorker(int m)
{
    for(int i=0;i<m;i++)
    {
        //tworzymy nowego pracownika i dodajemy do wektora
    }
}

void supermarket::createBottles(int quantity)
{
    for(int i=1;i<=quantity;i++)
    {
        //tworzymy butelke wody i dodajemy do vectora
    }
}

void supermarket::createApples(int quantity)
{
    for(int i=1;i<=quantity;i++)
    {
        //tworzymy jablko i dodajemy do vectora
    }
}

void supermarket::createFlowers(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        //tworzymy bukiet kwiatow i dodajemy do vectora
    }
}

void supermarket::createBooks(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        //tworzymy ksiazke i dodajemy do vectora
    }
}

void supermarket::createBreads(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        //tworzymy bochenek chleba i dodajemy do vectora
    }
}

void supermarket::createChocolates(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        //tworzymy czekolade i dodajemy do vectora
    }
}
