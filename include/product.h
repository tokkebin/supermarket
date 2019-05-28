#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class product
{
    public:
        product();
        void setPrice();
        virtual void setName(string n)=0;
        double getPrice();
        virtual string getName()=0;
        virtual void setNumber(int i)=0;
        virtual int getNumber()=0;
        virtual ~product(){};

    protected:

    private:
        int VAT;
        double price;
};

#endif // PRODUCT_H
