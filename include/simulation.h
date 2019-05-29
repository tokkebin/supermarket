#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>

#include "supermarket.h"
//#include "client.h"

using namespace std;


class Client;


string clientChoose(Supermarket* market, Client* client, int modulo)
{
    //funkcja uzywa generatora liczb pseudolosowych do wyboru produktu
    //dla liczb od 1  do 7 przypisane sa produkty
    //po wyborze produktu, jezeli on istnieje, wkladamy go do koszyka
    string wynik;
    int last = rand()%modulo;
    int first = 1;

    random_device rd;
    minstd_rand0 generator(rd());
    uniform_int_distribution<int> uniform_dist(first, last);
    int choose =  uniform_dist(generator);
    choose = (choose%6)+1;
    //cout<<choose<<"randomowo"<<endl;

    vector<productVAT8>::iterator it8;
    vector<productVAT23>::iterator it23;

    switch(choose)
    {
    case 1:

        //wybor butelki wody
        it8 = market->bottlesofWater.begin();
        wynik = "klient wybral wode ";
        if(market->bottlesofWater.empty())
        {
            wynik.append("ale juz nie ma jej w sklepie\n");
            break;
        }

        client->basket.push_back(*it8);
        market->bottlesofWater.erase(it8);

        break;
    case 2:
        //wybor jablka
        it8 = market->apples.begin();
        wynik = "klient wybral jablko\n";
        if(market->apples.empty())
        {
            wynik.append(" ale juz ich nie ma\n");
            break;
        }
        client->basket.push_back(*it8);
        market->apples.erase(it8);
        break;
    case 3:
        //wybor bukietu kwiatow
        it8 = market->flowers.begin();
        wynik = "klient wybral kwiaty\n";
        if(market->flowers.empty())
        {
            wynik.append(" ale juz ich brak\n");
            break;
        }
        client->basket.push_back(*it8);
        market->flowers.erase(it8);
        break;
    case 4:
        //wybor gazety
        it23 = market->newspapers.begin();
        wynik = "klient wybral gazete\n";
        if(market->newspapers.empty())
        {
            wynik.append("ale juz nie ma\n");
            break;
        }
        client->basket.push_back(*it23);
        market->newspapers.erase(it23);
        break;
    case 5:
        //wybor ksiazki
        it23 = market->books.begin();
        wynik = "klient wybral ksiazke\n";
        if(market->books.empty())
        {
            wynik.append("ale juz nie ma\n");
            break;
        }
        client->basket.push_back(*it23);
        market->books.erase(it23);
        break;
    case 6:
        //wybor chleba
        it23 = market->bread.begin();
        wynik = "klient wybral chleb\n";
        if(market->bread.empty())
        {
            wynik.append("ale juz nie ma\n");
            break;
        }
        client->basket.push_back(*it23);
        market->bread.erase(it23);
        break;
    case 7:
        //wybor czekolady
        it23 = market->chocolate.end();
        wynik = "klient wybral czekolade\n";
        if(market->chocolate.empty())
        {
            wynik.append("ale juz nie ma\n");
            break;
        }
        client->basket.push_back(*it23);
        market->chocolate.erase(it23);

        break;
    }

    return wynik;
}

string clientAsk()
{

}

void wypiszWczytaj(string text, fstream plik)
{
    plik<<text<<endl;
    cout<<text<<endl;
}


void simulation(int iter, int n, int m, int water, int apples, int books)
{
    fstream plik;
    plik.open("wynik.txt",ios::out | ios::app);

    if(plik.good()==true)
    {
        string s = "Symulacja supermarketu\n";
        plik<<s<<endl;
        cout<<s<<endl;
    }

    this_thread::sleep_for(std::chrono::seconds(2));
    //inicjalizacja supermarketu
    Supermarket* market = new Supermarket(n,m);
    plik<<market->akcja;
    cout<<market->akcja<<endl;
    market->akcja.clear();
    string wynik;
    this_thread::sleep_for(std::chrono::seconds(2));
    //petla przebiegu dzialania supermarketu
    for(int i=0; i<iter;i++)
    {

        if(!market->entrance())
        {
            market->akcja.append("\nSklep zmkniety\n");

            continue;
        }
        Client* client = new Client(i+1);

        market->akcja.append("\nKlient nr: " + to_string(client->getNumber()) + " wszedl do sklepu\n");

        plik<<market->akcja<<endl;
        cout<<market->akcja<<endl;
        this_thread::sleep_for(std::chrono::seconds(2));


        market->akcja.clear();
        int modulo = rand();
        market->akcja = clientChoose(market, client, modulo);

        cout<<market->akcja<<endl;
        plik<<market->akcja;
        market->akcja.clear();

        this_thread::sleep_for(std::chrono::seconds(2));

        int modulo2 = rand();
        market->akcja = clientChoose(market, client, modulo2);
        cout<<market->akcja<<endl;
        plik<<market->akcja;
        market->akcja.clear();

        this_thread::sleep_for(std::chrono::seconds(2));

        //otwieranie kasy

        vector<Worker>::iterator it;
        it = market->workerList.begin();
        Worker worker = *it;
        worker.setBusy(true);

        vector<cashRegister>::iterator iterCash = market->cashList.begin();
        cashRegister kasa = *iterCash;
        market->cashList.erase(iterCash);
        worker.setOpen(&kasa);
        market->cashList.push_back(kasa);

        market->akcja = "\nKasa nr: "+to_string(kasa.getNumber())+"zostala otwarta";
        market->akcja.append(" przez pracownika nr: "+to_string(worker.get_number())+"\n");
        plik<<market->akcja;
        cout<<market->akcja;
        market->akcja.clear();
        market->workerList.erase(it); //pracownik usuniety z dostepnych

        this_thread::sleep_for(std::chrono::seconds(2));




    }



}






