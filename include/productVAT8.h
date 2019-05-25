#ifndef PRODUCTVAT8_H
#define PRODUCTVAT8_H
#include <cstdlib>
#include <product.h>

using namespace std;

class productVAT8 : public product
{
    public:
        productVAT8();

        //void setVAT();
        void setName(string n);
        void setPrice();
        void setNumber(int i);
        int getNumber();
        string getName();
        double getPrice();
        virtual ~productVAT8();

    protected:

    private:
        int VAT = 8;//w procentach
        string name;
        double price;
        int number;
};

#endif // PRODUCTVAT8_H