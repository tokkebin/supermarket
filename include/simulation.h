#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>

#include "supermarket.h"
//#include "check.h"
//#include "client.h"

using namespace std;


class Client;
class Check;






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
        market->akcja.clear();
        this_thread::sleep_for(std::chrono::seconds(2));


        //wybor produktu
        int modulo = rand();
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
        productVAT23 temp23;
        productVAT8 temp8;
        string wynik;
        double cena;
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
            wynik.append("nr: "+to_string(it8->getNumber())+"\n");
            client->basket8.push_back(*it8);
            market->bottlesofWater.erase(it8);


                //klient sprawdza cene czekolady
            it23 = market->chocolate.begin();
            wynik.append("Klient nr: "+to_string(client->getNumber())+"sprawdza cene czekolady nr: "+to_string(it23->getNumber())+"\n");

            cena = it23->getPrice();
            wynik.append("ktora wynosi: "+to_string(cena)+"\n");
            this_thread::sleep_for(std::chrono::seconds(1));

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
            wynik.append("nr: "+to_string(it8->getNumber())+"\n");
            client->basket8.push_back(*it8);
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
            wynik.append("nr: "+to_string(it8->getNumber())+"\n");
            client->basket8.push_back(*it8);
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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
            market->bread.erase(it23);

               //klient sprawdza cene kwiatow
            it8 = market->flowers.begin();
            wynik.append("Klient nr: "+to_string(client->getNumber())+"sprawdza cene czekolady nr: "+to_string(it8->getNumber())+"\n");

            cena = it8->getPrice();
            wynik.append("ktora wynosi: "+to_string(cena)+"\n");
            this_thread::sleep_for(std::chrono::seconds(2));

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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
            market->chocolate.erase(it23);

            break;
        }

        cout<<wynik<<endl;
        plik<<wynik;
        wynik.clear();


        vector<productVAT8>::iterator costam = client->basket8.begin();
        //cout<<costam->getPrice()<<" dupa "<<costam->getName()<<endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        //wybor drugiego produktu
        int modulo2 = rand();
        int last2 = rand()%modulo2;
        int first2 = 1;

        random_device rd2;
        minstd_rand0 generator2(rd2());
        uniform_int_distribution<int> uniform_dist2(first2, last2);
        int choose2 =  uniform_dist2(generator2);
        choose2 = (choose2%6)+1;
        //cout<<choose<<"randomowo"<<endl;

        //vector<productVAT8>::iterator it8;
        //vector<productVAT23>::iterator it23;
        //productVAT23 temp23;
        //productVAT8 temp8;
        //double cena;
        switch(choose2)
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
            wynik.append("nr: "+to_string(it8->getNumber())+"\n");
            client->basket8.push_back(*it8);
            market->bottlesofWater.erase(it8);


                //klient sprawdza cene czekolady
            it23 = market->chocolate.begin();
            wynik.append("Klient nr: "+to_string(client->getNumber())+"sprawdza cene czekolady nr: "+to_string(it23->getNumber())+"\n");

            cena = it23->getPrice();
            wynik.append("ktora wynosi: "+to_string(cena)+"\n");
            this_thread::sleep_for(std::chrono::seconds(1));


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
            wynik.append("nr: "+to_string(it8->getNumber())+"\n");
            client->basket8.push_back(*it8);
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
            wynik.append("nr: "+to_string(it8->getNumber())+"\n");
            client->basket8.push_back(*it8);
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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
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
            wynik.append("nr: "+to_string(it23->getNumber())+"\n");
            client->basket23.push_back(*it23);
            market->bread.erase(it23);

               //klient sprawdza cene kwiatow
            it8 = market->flowers.begin();
            wynik.append("Klient nr: "+to_string(client->getNumber())+"sprawdza cene czekolady nr: "+to_string(it8->getNumber())+"\n");

            cena = it8->getPrice();
            wynik.append("ktora wynosi: "+to_string(cena)+"\n");
            this_thread::sleep_for(std::chrono::seconds(1));

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
            wynik.append("nr: "+to_string(it23->getNumber()));
            client->basket23.push_back(*it23);
            market->chocolate.erase(it23);

            break;
        }
        cout<<wynik<<endl;
        plik<<wynik;
        wynik.clear();

        this_thread::sleep_for(std::chrono::seconds(4));

        //zapytanie do pracownika
        vector<Worker>::iterator it;
        it = market->workerList.end();
        string odp = client->askWorker("godziny otwarcia",*it);

        market->akcja = "Klient nr: "+to_string(client->getNumber())+" pyta pracownika nr: "+to_string(it->get_number())+" o godziny otwarcia\n";
        cout<<market->akcja;
        plik<<market->akcja;
        market->akcja.clear();
        this_thread::sleep_for(std::chrono::seconds(2));

        market->akcja = "Odpowiedz pracownika: " + odp + "\n";
        cout<<market->akcja;
        plik<<market->akcja;
        market->akcja.clear();
        this_thread::sleep_for(std::chrono::seconds(1));

        //otwieranie kasy


        it = market->workerList.begin();
        //Worker worker = *it;
        it->setBusy(true);

        vector<cashRegister>::iterator iterCash = market->cashList.begin();
        //cashRegister kasa = *iterCash;
        //market->cashList.erase(iterCash);
        it->setOpen(*iterCash);
        //market->cashList.push_back(kasa);

        market->akcja = "\nKasa nr: "+to_string(iterCash->getNumber())+"zostala otwarta";
        market->akcja.append(" przez pracownika nr: "+to_string(it->get_number())+"\n");
        plik<<market->akcja;
        cout<<market->akcja;
        market->akcja.clear();

        market->workerList.erase(it); //pracownik usuniety z dostepnych

        this_thread::sleep_for(std::chrono::seconds(2));


        //wybor kasy przez klienta
        iterCash = client->toQueue(market);

        //cashRegister kasa1 = *iterCash;

        market->akcja = "Klient nr: "+to_string(client->getNumber())+" wybral kase nr: "+to_string(iterCash->getNumber())+"\n";
        cout<<market->akcja;
        plik<<market->akcja;
        market->akcja.clear();

        this_thread::sleep_for(std::chrono::seconds(2));

        //wybor potwierdzenia platnosci
        if(i%2)
        {
            Invoice inv;
            //Client cl = *client;
            try
            {
                market->akcja = iterCash->createPayment(inv,client);
            }
            catch(...)
            {
                cout<<"Zly typ potwierdzenia zaplaty "<<endl;
            }

        }
        else
        {
            Check che;
            try
            {
                market->akcja = iterCash->createPayment(che,client);
            }
            catch(...)
            {
                cout<<"Zly typ potwierdzenia zaplaty "<<endl;
            }

        }

        plik<<market->akcja;
        market->akcja.clear();

        this_thread::sleep_for(std::chrono::seconds(2));

        //opuszczanie kolejki w kasie
        iterCash->cashQueue.pop_back();
        market->akcja = "Klient nr: "+to_string(client->getNumber())+"opuscil kase nr: "+to_string(iterCash->getNumber())+"\n";
        cout<<market->akcja;
        plik<<market->akcja;

        this_thread::sleep_for(std::chrono::seconds(1));


    }

    market->close();

}






