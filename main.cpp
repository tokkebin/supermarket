#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "cashRegister.h"
#include "check.h"
#include "client.h"
#include "invoice.h"
#include "payment.h"
#include "product.h"
#include "productVAT23.h"
#include "productVAT8.h"
#include "simulation.h"
#include "supermarket.h"
#include "worker.h"

using namespace std;

int main()
{
    string text;
    string all[3][2];
    ifstream plik("plik.txt");

    //plik.open("plik", ios::in);

    if(plik.good() == true)
        {
            int i = 0;
            while(!plik.eof())
            {
                plik>>text;
                all[i][0] = text;
                plik>>text;
                all[i][1] = text;
                i++;

            }
            plik.close();
        }

    for(int i=0;i<2;i++)
    {
        cout<<all[i][0]<<"  "<<all[i][1]<<endl;
    }

    int m = stoi(all[0][1]); //liczba kas
    int n = stoi(all[1][1]); //liczba pracownikow
    int it = stoi(all[2][1]); //liczba iteracji

    if(n<it)
    {
        cout<<"liczba iteracji nie moze byc wieksza od liczby pracownikow"<<endl;
    }

    simulation(it,n,m);

    return 0;
}
