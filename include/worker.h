#ifndef WORKER_H
#define WORKER_H
#include <string>
#include <vector>


#include "product.h"
#include "productVAT23.h"
#include "productVAT8.h"
//#include "cashRegister.h"



using namespace std;
class cashRegister;
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
        int countProduct(vector<product>* v);
        void setOpen(cashRegister* cash);
        void setClosed(cashRegister* cash);


    protected:

    private:
        int number;
        bool busy;
};

#endif // WORKER_H
