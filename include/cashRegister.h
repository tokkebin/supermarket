#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "check.h"
#include "invoice.h"
#include "client.h"
using namespace std;
class cashRegister
{
    public:
        cashRegister();
        ~cashRegister();
        cashRegister(int i);
        int getNumber();
        void setNumber(int i);
        void setOpen(string s);
        bool getOpen();
        double getPriceVAT();
        void countCost(double price);
        void countVAT(Product& p);
        double getTotal();
        string createPayment(Payment& pay, Client& cl);//stworzymy potwierdzenie zaplaty o wybranej formie dla danego klienta


        vector<Client>* cashQueue;
        //void clientQueue(client* cl);
        int queueLength; //dlugosz kolejki do kasy

    protected:

    private:
        int number;
        bool open;
        double total; //cena do zaplaty
        double priceVAT;
};

#endif // CASHREGISTER_H
