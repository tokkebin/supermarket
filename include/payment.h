#ifndef PAYMENT_H
#define PAYMENT_H

#include <typeinfo>
#include <string>
using namespace std;
class payment
{
    public:
        void set_payment();
        float get_payment();
        string listProducts();


        payment();
        virtual ~payment();

    protected:

    private:
};

#endif // PAYMENT_H
