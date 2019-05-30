#ifndef INVOICE_H
#define INVOICE_H

#include <payment.h>


class Invoice : public Payment
{
    public:
        Invoice();
        double getVAT();
        string getName();
        void setNumber(int i);
        int getNumber();
        ~Invoice();

    protected:

    private:
        double vat;
        string name = "FAKTURA";
        int number;
};

#endif // INVOICE_H
