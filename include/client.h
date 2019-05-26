#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <vector>


#include "supermarket.h"

using namespace std;
class client
{
    public:
        client();
        void setNumber(int i);
        int getNumber();
        string askWorker(string what,product* p,worker* w);
        double checkPrice(product* p);
        bool entrence(string inout);
        product* choose();
        void toQueue(supermarket* market);
        vector<product>* basket;
        ~client();

    protected:

    private:
        int number;
};

#endif // CLIENT_H
