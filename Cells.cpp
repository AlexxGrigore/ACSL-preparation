#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

char operatie[1000], numar[1000], numar2[1000];

ifstream f("date.in");

void DIVIDE()
{
    sort(numar,numar+4);
    for(int i=0; i<4; i++)
        cout<<numar[i];
    for(int i=0; i<4; i++)
        cout<<numar[i];
    cout<<" and ";
    sort(numar+4,numar+8);
    for(int i=4; i<8; i++)
        cout<<numar[i];
    for(int i=4; i<8; i++)
        cout<<numar[i];
    cout<<endl;
}

void ADDn(int n)
{
    if(n==0)
    {
        cout<<numar<<endl;
        return;
    }
    for(int i=0; i<n; i++)
        cout<<numar[i];
    sort(numar,numar+n);
    for(int i=0; i<n; i++)
        cout<<numar[i];
    for(int i=n; i<2*n-1; i++)
        cout<<numar[i];
    cout<<endl;
}

void SUBTRACTn(int n)
{
    for(int i=n; i<8; i++)
        cout<<numar[i];
    sort(numar+8-n, numar+8);
    for(int i=8-n; i<8; i++)
        cout<<numar[i];
        cout<<endl;
}

void UNION()
{
    strcpy(numar+8,"");
    sort(numar+4,numar+8);
    sort(numar2,numar2+4);
    cout<<numar+4;
    for(int i=0; i<4; i++)
        cout<<numar2[i];
    cout<<endl;
}

void INTERSECT()
{
    strcpy(numar+8,"");
    char aux1[100],aux2[100];

    for(int i=0; i<2; i++)
        aux1[i]=numar[i];
    for(int i=6; i<8; i++)
        aux1[i-4]=numar[i];
    sort(aux1,aux1+4);

    for(int i=0; i<2; i++)
        aux2[i]=numar2[i];
    for(int i=6; i<8; i++)
        aux2[i-4]=numar2[i];
    sort(aux2,aux2+4);

    ///afisare
    for(int i=0; i<4; i++)
        cout<<aux1[i];
    for(int i=0; i<4; i++)
        cout<<aux2[i];
    cout<<endl;
}

void rezolvare()
{
    switch(operatie[0])
    {
        case 'D':
            DIVIDE();
            break;

        case 'A':
            ADDn(operatie[3]-'0');
            break;

        case 'S':
            SUBTRACTn(operatie[8]-'0');
            break;

        case 'U':
            f>>numar2;
            UNION();
            break;

        case 'I':
            f>>numar2;
            INTERSECT();
            break;
    }
}

int main()
{
    for(int i=0; i<5; i++)
    {
        f>>operatie>>numar;
        rezolvare();
    }
    return 0;
}
