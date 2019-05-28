#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <vector>


#include "supermarket.h"

using namespace std;
class Client
{
    public:
        Client();
        Client(int i);
        void setNumber(int i);
        int getNumber();
        string askWorker(string what,Product* p,Worker* w);
        double checkPrice(Product* p);
        bool entrence(string inout);
        Product* choose();
        void toQueue(Supermarket* market);
        void toBasket(Product* pr);
        vector<Product>* basket;
        ~Client();

    protected:

    private:
        int number;
};

#endif // CLIENT_H
