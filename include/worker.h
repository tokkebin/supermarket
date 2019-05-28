#ifndef WORKER_H
#define WORKER_H
#include <string>
#include <vector>


#include "product.h"
#include "productVAT23.h"
#include "productVAT8.h"
//#include "cashRegister.h"
//#include "supermarket.h"



using namespace std;
class cashRegister;
class Supermarket;
class Worker
{
    public:
        Worker();
        void set_number(int a);
        int get_number();
        virtual ~Worker();
        void setBusy(bool i);
        bool getBusy();
        string answer(string question);
        double answerPrice(Product* p); //zdefiniowac cialo funkcji
        int countProduct(vector<Product>* v);
        void setOpen(cashRegister* cash);
        void setClosed(cashRegister* cash);
        void closeMarket(Supermarket* market);


    protected:

    private:
        int number;
        bool busy;
};

#endif // WORKER_H
