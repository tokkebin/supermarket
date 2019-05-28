#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "worker.h"
//#include "client.h"

#include <vector>
#include <string>

using namespace std;

class Supermarket
{
    public:
        Supermarket();
        ~Supermarket();

        Supermarket(int cash, int worker);
        bool entrance();//zwraca otwarty lub zamkniety sklep
        void close();//zmykanie sklepu

        void createCash(int n);//tworzymy liste n kas
        void createWorker(int m); //tworzymy liste m pracownikow
        void setOpen(cashRegister* cash); //otwieranie kasy
        void setClose(cashRegister* cash); //zamykanie kasy
        void createBottles(int quantity);
        void createApples(int quantity);
        void createFlowers(int quantity);
        void createBooks(int quantity);
        void createNewspapers(int quantity);
        void createBreads(int quantity);
        void createChocolates(int quantity);

        vector<cashRegister> cashList;
        vector<Worker> workerList;

        vector<productVAT8> bottlesofWater;
        vector<productVAT8> apples;
        vector<productVAT8> flowers;

        vector<productVAT23> newspapers;
        vector<productVAT23> books;
        vector<productVAT23> bread;
        vector<productVAT23> chocolate;

        string akcja;

    protected:

    private:
        bool enter;

};

#endif // SUPERMARKET_H
