#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void DecToBin(char n, bool str[], int &currnr)
{
    int nr=n;
    for(int i=7; nr && i>=0; nr/=2, i--)
        str[i+currnr]=nr%2;
    currnr+=8;
    return;
}

int putere(short baza, short putere)
{
    int rez=1;
    for(int i=0; i<putere; i++, rez*=baza);
    return rez;
}

void BinToDec(bool str[], char conv[], int length)
{
    for(int i=0; i<length; i++)
        conv[i/6]+=str[i]*putere(2, (5-(i%6)));
    return;
}

int main()
{
    ifstream f("acsl4.txt");
    for(int abc=0; abc<10; abc++)
    {
        char str[101];
        memset(str, 0, 101);
        bool binstr[808]; 
        for(int i=0; i<808; i++)
            binstr[i]=0;
        int nrcurr=0;
        f.getline(str, 100);
        short len=strlen(str);
        for(; len%3!=0; len++)
            str[len]='0';
        for(int i=0; i<len; i++)
            DecToBin(str[i], binstr, nrcurr);
        memset(str, 32, 101);
        BinToDec(binstr, str, nrcurr);
        for(int i=0; i<nrcurr/6; i++)
        {
            if(str[i]!=32)
                cout<<str[i];
            else
                cout<<'~';
        }
        cout<<endl;
    }
    return 0;
}
