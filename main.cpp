#include <iostream>
#include <string>
#include <fstream>
#include <chrono>


using namespace std;

int main()
{
    string text;
    string all[2][2];
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

    return 0;
}
