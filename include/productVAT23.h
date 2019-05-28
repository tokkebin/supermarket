#ifndef PRODUCTVAT23_H
#define PRODUCTVAT23_H

#include <product.h>


class productVAT23 : public Product
{
    public:
        productVAT23();
        productVAT23(int n, string nazwa, double p); //konstruktor z parametrami
        void setName(string n);
        //void setPrice();
        void setNumber(int i);
        int getNumber();
        string getName();
        //double getPrice();
        ~productVAT23();

    protected:

    private:
        int VAT = 23;//w procentach
        string name;
        double price;
        int number;
};

#endif // PRODUCTVAT23_H
