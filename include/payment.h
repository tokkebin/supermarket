#ifndef PAYMENT_H
#define PAYMENT_H

#include <typeinfo>
#include <string>
#include <vector>
#include "product.h"
using namespace std;
class Payment
{
    public:
        void setPayment(double total);
        double getPayment();
        //vector<Product> listProducts;
        virtual string getName()=0;
        virtual void setNumber(int i)=0;
        virtual int getNumber()=0;


        Payment();
        virtual ~Payment();

    protected:
        double price;

    private:
};

#endif // PAYMENT_H
