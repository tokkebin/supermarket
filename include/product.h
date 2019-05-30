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
