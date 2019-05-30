#include "supermarket.h"
#include "cashRegister.h"
Supermarket::Supermarket()
{
    //ctor
}

Supermarket::~Supermarket()
{
    delete this;
    //dtor
}

Supermarket::Supermarket(int n,int m)
{
    createCash(n);
    createWorker(m);
    createApples(10);
    createBooks(10);
    createBottles(10);
    createBreads(10);
    createChocolates(10);
    createFlowers(10);
    createNewspapers(10);

    enter = true;
    cout<<"Otwarto sklep"<<endl;
}

void Supermarket::createCash(int n)
{
    for (int i=0;i<n;i++)
    {
        cashRegister* cash = new cashRegister(i+1);
        this->cashList.push_back(*cash);
        //tworzymy nowa kase i dodajemy do vectora
    }
    string text = "stworzono " + to_string(n) + " kas\n";
    cout<<text;
    this->akcja.append(text);
}


void Supermarket::createWorker(int m)
{
    for(int i=0;i<m;i++)
    {
        Worker* wor = new Worker();
        wor->set_number(i+1);
        this->workerList.push_back(*wor);
        //tworzymy nowego pracownika i dodajemy do wektora
    }


    string text = "stworzono " + to_string(m) + " pracownikow\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createBottles(int quantity)
{
    for(int i=1;i<=quantity;i++)
    {
        productVAT8* bottleofWater = new productVAT8(i, "butelka wody", 3.5 );
        bottleofWater->setValueVAT();
        this->bottlesofWater.push_back(*bottleofWater);
        //tworzymy butelke wody i dodajemy do vectora
    }
    string text = "stworzono " + to_string(quantity) + " butelek wody\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createApples(int quantity)
{
    for(int i=1;i<=quantity;i++)
    {
        productVAT8* apple = new productVAT8(i, "jablko", 0.5);
        apple->setValueVAT();
        this->apples.push_back(*apple);
        //tworzymy jablko i dodajemy do vectora
    }
    string text = "stworzono " + to_string(quantity) + " jablek\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createFlowers(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT8* flower = new productVAT8(i, "bukiet kwiatow", 5.0);
        flower->setValueVAT();
        this->flowers.push_back(*flower);
        //tworzymy bukiet kwiatow i dodajemy do vectora
    }
    string text = "stworzono " + to_string(quantity) + " bukietow kwiatow\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createBooks(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* book = new productVAT23(i, "ksiazka", 0);
        book->setValueVAT();
        this->books.push_back(*book);
        //tworzymy ksiazke i dodajemy do vectora
    }
    string text = "stworzono " + to_string(quantity) + " ksiazek\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createBreads(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* br = new productVAT23(i, "bochenek chleba", 2.5);
        br->setValueVAT();
        this->bread.push_back(*br);
        //tworzymy bochenek chleba i dodajemy do vectora
    }
    string text = "stworzono " + to_string(quantity) + " bochenkow chleba\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createChocolates(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* choco = new productVAT23(i, "tabliczka czekolady", 3.5);
        choco->setValueVAT();
        this->chocolate.push_back(*choco);
        //tworzymy czekolade i dodajemy do vectora
    }
    string text = "stworzono " + to_string(quantity) + " czekolad\n";
    cout<<text;
    this->akcja.append(text);
}

void Supermarket::createNewspapers(int quantity)
{
    for(int i=1; i<=quantity; i++)
    {
        productVAT23* news = new productVAT23(i, "gazeta", 4.9);
        news->setValueVAT();
        this->newspapers.push_back(*news);
    }
    string text = "stworzono " + to_string(quantity) + " gazet\n";
    cout<<text;
    this->akcja.append(text);
}

bool Supermarket::entrance()
{
    return this->enter;
}

void Supermarket::close()
{
    this->enter = false;
}
