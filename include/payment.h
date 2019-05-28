#ifndef PAYMENT_H
#define PAYMENT_H

#include <typeinfo>
#include <string>
#include <vector>
#include "product.h"
using namespace std;
class payment
{
    public:
        void setPayment();
        float getPayment();
        vector<Product>* listProducts;
        virtual string getName()=0;


        payment();
        virtual ~payment();

    protected:

    private:
};

#endif // PAYMENT_H
