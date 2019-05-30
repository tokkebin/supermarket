#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class ProductInter
{
    public:
        virtual void setPrice()=0;
        virtual void setName(string n)=0;
        virtual double getPrice()=0;
        virtual void setValueVAT()=0;
        virtual double getValueVAT()=0;
        virtual string getName()=0;
        virtual void setNumber(int i)=0;
        virtual int getNumber()=0;
        //virtual ~ProductInter()=0;
};

class Product: virtual ProductInter
{
    public:
        Product();
        void setPrice();
        virtual void setName(string n){};
        double getPrice();
        void setValueVAT();
        double getValueVAT();
        virtual string getName();
        virtual void setNumber(int i){};
        int getNumber();
        virtual ~Product(){};

    protected:
        double valueVAT;
        string name;
        int number;
        double price;
    private:
        int VAT;

};

#endif // PRODUCT_H
