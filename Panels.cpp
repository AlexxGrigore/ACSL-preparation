#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
ifstream f("sample.in");


int linie(double lungime, double lPlaca, double inaltime, double iPlaca, double procent)
{
    if(inaltime < 0)
        return 0;
    if(iPlaca < inaltime)
    {
        return (int)(lungime/lPlaca) + linie(lungime-lPlaca*procent/100, lPlaca, inaltime-iPlaca, iPlaca, procent);
    }
    return (int)(lungime/lPlaca);
}

void rez()
{
    double lungime = 0, inaltime = 0, lPlaca = 0, iPlaca = 0;

    f>>lungime;
    f.get();
    f>>inaltime;
    f.get();
    f>>lPlaca;
    f.get();
    f>>iPlaca;
    f.get();
    double arie = lungime*inaltime;
    int suma = (int)(lungime/lPlaca);
    inaltime = (inaltime-iPlaca)/2;
    suma += linie(lungime-lPlaca*25/100, lPlaca, inaltime-iPlaca, iPlaca, 25);
    suma += linie(lungime-lPlaca*50/100, lPlaca, inaltime-iPlaca, iPlaca, 50);
    cout<<arie-suma*lPlaca*iPlaca<<"\n";
}

int main()
{
    for(int i = 0; i<5; i++)
        rez();
    return 0;
}
