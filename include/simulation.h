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

Client* clientEntrence(Supermarket* market)
{
    if(!market->entrance())
    {
        throw market->entrance();//zmakniêty sklep nie mozna wejsc
    }
    Client* client = new Client();

    market->akcja.append("\nKlient wszedl do sklepu\n");

    return client;
}

string clientChoose()
{
    string wynik;
    int last = rand()%100;
    int first = 1;

    random_device rd;
    minstd_rand0 generator(rd());
    uniform_int_distribution<int> uniform_dist(first, last);
    int choose =  uniform_dist(generator);
    choose = (choose%6)+1;
    //cout<<choose<<"randomowo"<<endl;

    switch(choose)
    {
    case 1:
        //wybor butelki wody
        wynik = "klient wybral wode\n";
        break;
    case 2:
        //wybor jablka
        wynik = "klient wybral jablko\n";
        break;
    case 3:
        //wybor bukietu kwiatow
        wynik = "klient wybral kwiaty\n";
        break;
    case 4:
        //wybor gazety
        wynik = "klient wybral gazete\n";
        break;
    case 5:
        //wybor ksiazki
        wynik = "klient wybral ksiazke\n";
        break;
    case 6:
        //wybor chleba
        wynik = "klient wybral chleb\n";
        break;
    case 7:
        //wybor czekolady
        wynik = "klient wybral czekolade\n";
        break;
    }

    return wynik;
}

string clientAsk()
{

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
    Supermarket* market = new Supermarket(n,m);
    plik<<market->akcja;
    cout<<market->akcja<<endl;
    market->akcja.clear();
    string wynik;
    this_thread::sleep_for(std::chrono::seconds(2));
    for(int i=0; i<iter;i++)
    {

        try
        {
            Client* client = clientEntrence(market);
        }
        catch(bool)
        {
            cout<<"Zamkniety sklep"<<endl;
        }
        plik<<market->akcja<<endl;
        cout<<market->akcja<<"cos tam"<<endl;
        this_thread::sleep_for(std::chrono::seconds(2));


        market->akcja.clear();
        market->akcja = clientChoose();
        cout<<market->akcja<<endl;
        plik<<market->akcja;
        market->akcja.clear();
        this_thread::sleep_for(std::chrono::seconds(2));
    }
}





