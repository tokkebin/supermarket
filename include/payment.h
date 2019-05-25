#ifndef PAYMENT_H
#define PAYMENT_H

#include <typeinfo>
#include <string>
using namespace std;
class payment
{
    public:
        virtual void set_payment()=0;
        virtual float get_payment()=0;
        virtual string listProducts();
        //virtual payment* choosePayment(payment* choose, typedef typ);

        payment();
        virtual ~payment();

    protected:

    private:
};

#endif // PAYMENT_H
