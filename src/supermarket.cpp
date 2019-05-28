#include "supermarket.h"
#include "cashRegister.h"
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
    createApples(10);
    createBooks(10);
    createBottles(10);
    createBreads(10);
    createChocolates(10);
    createFlowers(10);
    //createNewspapers(10);
}

void supermarket::createCash(int n)
{
    for (int i=0;i<n;i++)
    {
        cashRegister* cash = new cashRegister(i);
        this->cashList.push_back(*cash);
        //tworzymy nowa kase i dodajemy do vectora
    }
}


void supermarket::createWorker(int m)
{
    for(int i=0;i<m;i++)
    {
        worker* wor = new worker();
        this->workerList->push_back(*wor);
        //tworzymy nowego pracownika i dodajemy do wektora
    }
}

void supermarket::createBottles(int quantity)
{
    for(int i=1;i<=quantity;i++)
    {
        productVAT8* bottleofWater = new productVAT8(i, "butelka wody", 3.5 );
        this->bottlesofWater->push_back(*bottleofWater);
        //tworzymy butelke wody i dodajemy do vectora
    }
}

void supermarket::createApples(int quantity)
{
    for(int i=1;i<=quantity;i++)
    {
        productVAT8* apple = new productVAT8(i, "jablko", 0.5);
        this->apples->push_back(*apple);
        //tworzymy jablko i dodajemy do vectora
    }
}

void supermarket::createFlowers(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT8* flower = new productVAT8(i, "bukiet kwiatow", 5.0);
        this->flowers->push_back(*flower);
        //tworzymy bukiet kwiatow i dodajemy do vectora
    }
}

void supermarket::createBooks(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* book = new productVAT23(i, "ksiazka", 0);
        this->books->push_back(*book);
        //tworzymy ksiazke i dodajemy do vectora
    }
}

void supermarket::createBreads(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* br = new productVAT23(i, "bochenek chleba", 2.5);
        this->bread->push_back(*br);
        //tworzymy bochenek chleba i dodajemy do vectora
    }
}

void supermarket::createChocolates(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* choco = new productVAT23(i, "tabliczka czekolady", 3.5);
        this->chocolate->push_back(*choco);
        //tworzymy czekolade i dodajemy do vectora
    }
}

void supermarket::createNewspapers(int quantiy)
{
    for(int i=1; i<=quantiy; i++)
    {
        productVAT23* news = new productVAT23(i, "gazeta", 4.9);
        this->newspapers->push_back(*news);
    }
}
