#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class product
{
    public:
        product();
        virtual void setPrice();
        virtual void setName()=0;
        virtual double getPrice();
        virtual string getName()=0;
        virtual void setNumber();
        virtual int getNumber();
        virtual void setVAT();
        virtual ~product(){};

    protected:

    private:
        int VAT;
        double price;
};

#endif // PRODUCT_H
