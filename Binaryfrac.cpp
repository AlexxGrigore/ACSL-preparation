#include <iostream>
#include <fstream>

using namespace std;

double x,y,rez;

int put_val(int a,int val)
{
    int nr=0;
    while(a%val==0)
        a/=val,nr++;
    return nr;
}

void convert()
{

    double rez_final=(int)rez;
    if((int)rez>0)
    {
        if((int)rez==1)
        {
            cout<<"1.";
        }
        else
        {
            int maxi=put_val((int)rez,2);
            cout<<maxi;
            int aux=1;
            for(int i=0; i<maxi; i++)
                aux*=2;
            for(int i=maxi; i>=1; i--,aux/=2)
            {
                if(rez>=aux)
                {
                    cout<<"1";
                }
                else
                    cout<<"0";

                rez-=aux;
            }
            cout<<".";
        }

    }
    else
    {
        cout<<"0.";

    }
    rez-=(int)rez;
    for(double i=2; i<=64; i*=2)
    {
        if(1/i<=rez)
        {
            rez_final+=1/i;
            cout<<"1";
            rez=rez - (1/i);
        }
        else
            cout<<"0";

    }
    int fr=(int)rez_final;
    double it=(double)rez_final-fr;
    it*=1000000;
    cout<<", "<<fr<<"."<<it<<endl;
}

int main()
{
    ifstream f("date.in");
    for(int i=0; i<5; i++)
    {
        char chr;
        f>>x>>chr>>y;
        rez=x/y;

        if(put_val((int)x,3)<put_val((int)y,3) && (int)(rez*1000000) %10>5)
            rez-=0.000001;
        convert();
    }

    return 0;
}
