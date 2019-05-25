#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <iostream>
#include <string>
#include "payment.h"
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
        //payment choosePayment(payment& pay);
        void countCost(int price);
        int getTotal();

        vector<client>* cashQueue;
        int queueLength; //dlugosz kolejki do kasy

    protected:

    private:
        int number;
        bool open;
        int total; //cena do zaplaty
};

#endif // CASHREGISTER_H
