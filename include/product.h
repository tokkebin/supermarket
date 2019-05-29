#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class Product
{
    public:
        Product();
        void setPrice();
        virtual void setName(string n){};
        double getPrice();
        void setValueVAT();
        double getValueVAT();
        virtual string getName(){};
        virtual void setNumber(int i){};
        virtual int getNumber(){};
        virtual ~Product(){};

    protected:
        double valueVAT;
    private:
        int VAT;
        double price;
};

#endif // PRODUCT_H
