#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class Product
{
    public:
        Product();
        void setPrice();
        virtual void setName(string n)=0;
        double getPrice();
        void setValueVAT();
        double getValueVAT();
        virtual string getName()=0;
        virtual void setNumber(int i)=0;
        virtual int getNumber()=0;
        virtual ~Product(){};

    protected:
        double valueVAT;
    private:
        int VAT;
        double price;
};

#endif // PRODUCT_H
