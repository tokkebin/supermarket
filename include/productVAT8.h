#ifndef PRODUCTVAT8_H
#define PRODUCTVAT8_H
#include <cstdlib>
#include <product.h>

using namespace std;

class productVAT8 : public Product
{
    public:
        productVAT8();
        productVAT8(int n, string nazwa, double p);
        //void setVAT();
        void setName(string n);
        //void setPrice();
        void setNumber(int i);
        int getNumber();
        string getName();
        double getPrice();
        void setValueVAT();
        double getValueVAT();
        ~productVAT8();

    protected:

    private:
        int VAT = 8;//w procentach
        string name;
        double price;
        int number;
};

#endif // PRODUCTVAT8_H
