#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void convToArray(char sw[], int w[])
{
    int len=strlen(sw);
    for(int i=0; i<len; i++)
        if(sw[i]>='0' && sw[i]<='9')
            w[i]=sw[i]-'0';
        else
            w[i]=sw[i]-'A'+10;
    return;
}

void rounding(int number[], int place, int &fdp, int base=10)
{
    if((float)number[place+fdp]/(float)base>=0.5)
    {
        int rez[20];
        for(int i=0; i<20; i++)
            rez[i]=-2;
        int current=19;
        int prev=0;
        number[fdp+place-1]++;
        for(int i=fdp+place-1; i>=0; i--)
        {
            int cifra=prev;
            cifra+=number[i];
            if(i==fdp)
                fdp=current;
            rez[current--]=cifra%base;
            prev=cifra/base;
        }
        if(prev>0)
            rez[current--]=prev;
        for(int i=0; i<20; i++)
            number[i]=-2;
        for(int i=current+1; i<20; i++)
            number[i-current-1]=rez[i];
        fdp-=current+1;
    }
    else
        for(int i=place+fdp; i<20; i++)
            number[i]=-2;
    return;
}

void convToString(int nr[], char number[])
{
    for(int i=0; i<20 && nr[i]>=0; i++)
        if(nr[i]<10)
            number[i]=nr[i]+'0';
        else
            number[i]=nr[i]+'A'-10;
    return;
}

int main()
{
    ifstream f("acsl7.txt");
    for(int abc=0; abc<10; abc++)
    {
        char number[20];
        int rp, base, firstdecpoz;
        memset(number, 0, 20);
        f.getline(number, 10, '.');
        firstdecpoz=strlen(number);
        f.getline(number+firstdecpoz, 10, ',');
        f>>base;
        if(true)
        {
            char comma;
            f>>comma;
        }
        f>>rp;
        f.get();
        int nr[20];
        for(int i=0; i<20; i++)
            nr[i]=0;
        convToArray(number, nr);
        rounding(nr, rp, firstdecpoz, base);
        memset(number, 0, 20);
        convToString(nr, number);
        for(int i=0; i<firstdecpoz; i++)
            cout<<number[i];
        cout<<'.';
        for(int i=firstdecpoz; i<strlen(number); i++)
            cout<<number[i];
        cout<<endl;
    }
    return 0;
}
