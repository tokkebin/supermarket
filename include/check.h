#ifndef CHECK_H
#define CHECK_H

#include <payment.h>


class Check : public payment
{
    public:
        Check();
        string getName();
        ~Check();

    protected:

    private:
        string name = "PARAGON";
};

#endif // CHECK_H
