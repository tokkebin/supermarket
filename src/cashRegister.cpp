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

void cashRegister::countCost(double price)
{
    this->total = this->total + price;
}

double cashRegister::getTotal()
{
    return this->total;
}

void cashRegister::countVAT(double vat)
{
    this->priceVAT = (this->priceVAT) + vat;
}

double cashRegister::getPriceVAT()
{
    return this->priceVAT;
}
string cashRegister::createPayment(Payment& pay, Client* cl)
{
    //stworzymy potwierdzenie zaplaty o wybranej formie dla danego klienta
    //po kazdym wypisaniu akcji na konsole czekamy az uzytkownik przeczyta
    //(pay.listProducts) = (cl.basket);
    vector<productVAT8>::iterator it8;
    vector<productVAT23>::iterator it23;
    string nazwa;

    nazwa = "\nKlient nr: " + to_string(cl->getNumber()) + "kupil:\n";
    cout<<nazwa;
    this_thread::sleep_for(std::chrono::seconds(1));
    //wypisanie listy kupionych produktow i policzenie ceny
    for(it8=cl->basket8.begin();it8!= cl->basket8.end();it8++)
    {


        this->countCost(it8->getPrice());
        //a tutaj liczymy w petli cene do zaplaty
        //oraz caly vat
        this->countVAT(it8->getValueVAT());

        string text = it8->getName() + " nr: " + to_string(it8->getNumber())+"\n";
        nazwa.append(text);
        cout<<text;
        this_thread::sleep_for(std::chrono::seconds(1));

    }
    for(it23=cl->basket23.begin();it23!= cl->basket23.end();it23++)
    {


        this->countCost(it23->getPrice());
        //a tutaj liczymy w petli cene do zaplaty
        //oraz caly vat
        this->countVAT(it23->getValueVAT());

        string text = it23->getName() + " nr: " + to_string(it23->getNumber())+"\n";
        nazwa.append(text);
        cout<<text;
        this_thread::sleep_for(std::chrono::seconds(1));

    }
    string nazwaAdd = "\nKlient nr " + to_string(cl->getNumber()) + " wybral " + pay.getName();
    nazwa.append(nazwaAdd);
    cout<<nazwaAdd<<endl;
    this_thread::sleep_for(std::chrono::seconds(2));

    if(typeid(pay)==typeid(Invoice))
    {
        string addition = " nr: "+ to_string(pay.getNumber()) +"\nDo zaplaty: " + to_string(this->getTotal()) + " w tym "+ to_string(this->getPriceVAT()) + " VAT\n";
        nazwa.append(addition);
        cout<<addition;
        this_thread::sleep_for(std::chrono::seconds(2));
        return nazwa;
    }
    else if(typeid(pay)==typeid(Check))
    {
        string addition = "\nDo zaplaty: " + to_string(this->getTotal()) + "\n";
        nazwa.append(addition);
        cout<<addition;
        this_thread::sleep_for(std::chrono::seconds(2));
        return nazwa;
    }
    else
        throw "ZLY TYP";


}

/*void cashRegister::clientQueue(client* cl)
{
    this->cashQueue.push_back(cl);
}*/
