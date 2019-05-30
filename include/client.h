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
        string askWorker(string what,Worker& w);
        double checkPrice(Product& p);
        bool entrence(string inout);
        Product* choose();
        vector<cashRegister>::iterator toQueue(Supermarket* market);
        void toBasket(Product& pr);
        vector<Product> basket;
        vector<productVAT23> basket23;
        vector<productVAT8> basket8;
        ~Client();

    protected:

    private:
        int number;
};

#endif // CLIENT_H
