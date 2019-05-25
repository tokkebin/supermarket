#ifndef WORKER_H
#define WORKER_H
#include <string>
//#include "client.h"
#include "product.h"
using namespace std;

class worker
{
    public:
        worker();
        void set_number(int a);
        int get_number();
        virtual ~worker();
        void setBusy(bool i);
        bool getBusy();
        string answer(string question);
        double answerPrice(product* p); //zdefiniowac cialo funkcji

    protected:

    private:
        int number;
        bool busy;
};

#endif // WORKER_H