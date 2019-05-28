#ifndef INVOICE_H
#define INVOICE_H

#include <payment.h>


class Invoice : public payment
{
    public:
        Invoice();
        double getVAT();
        string getName();
        ~Invoice();

    protected:

    private:
        string name = "FAKTURA";
};

#endif // INVOICE_H
