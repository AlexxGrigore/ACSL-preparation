#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");

void rezolva(int cifre[], int nr_cifre, int limita, int suma)
{
    if(suma==0)
    {
        cout<<"NONE";
        return;
    }
    if(limita==2)
    {
        for(int i=0; i<nr_cifre-1; i++)
        {
            for(int j=i+1; j<nr_cifre; j++)
            {
                if(cifre[i] + cifre[j]==suma)
                {   //cout<<"i="<<cifre[i]<<"    j="<<cifre[j]<<endl;
                    for(int k=0; k<nr_cifre; k++)
                        if(k==i || k==j)
                            cout<<"1";
                        else
                            cout<<"0";
                    cout<<" ";
                }
            }
        }
        return;
    }
    for(int i=0; i<nr_cifre-2; i++)
    {
        for(int j=i+1; j<nr_cifre-1; j++)
        {//cout<<"intra"<<endl;
            for(int p=j+1; p<nr_cifre; p++)
            {

                //cout<<cifre[i]<<", "<<cifre[j]<<" "<<cifre[p]<<endl;
                if(cifre[i] + cifre[j] + cifre[p]==suma)
                {
                    //cout<<i<<", "<<i<<" "<<i<<endl;
                    //
                    for(int k=0; k<nr_cifre; k++)
                        if(k==i || k==j || k==p)
                            cout<<"1";
                        else
                            cout<<"0";
                    cout<<" ";
                }
            }

        }
    }
}

int main()
{

    char chr;
    int cifre[10], nr_cifre=0;
    for(int k=0; k<10; k++)
    {
        nr_cifre=0;
        f>>chr;
        while(chr!=',')
        {
            cifre[nr_cifre++]=chr-'0';
            f>>chr;
        }

        int limita,suma;
        f>>limita>>chr>>suma;
        rezolva(cifre,nr_cifre,limita,suma);
        cout<<endl;
        /*for(int i=0; i<nr_cifre; i++)
            cout<<cifre[i];
        cout<<" "<<limita<<" "<<suma;*/
    }


    return 0;
}
