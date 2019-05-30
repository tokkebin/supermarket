#ifndef CHECK_H
#define CHECK_H

#include <payment.h>


class Check : public Payment
{
    public:
        Check();
        string getName();
        void setNumber(int i){};
        int getNumber(){};
        ~Check();

    protected:

    private:
        string name = "PARAGON";
};

#endif // CHECK_H
