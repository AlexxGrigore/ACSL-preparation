#include <iostream>
#include <fstream>

using namespace std;

#define LIMIT 30

int matr[100][1000000];

void genereaza()
{
    matr[0][0]=1,matr[0][1]=0;
    matr[1][0]=1,matr[1][1]=1,matr[1][2]=0;

    int j=0,anterior=matr[1][0],nr=0,k=0;

    for(int i=2; i<LIMIT; i++)
    {
        k=0;
        j=0;
        nr=0;
        anterior=matr[i-1][0];
        //cout<<"Anterior: "<<anterior<<endl;
        while(matr[i-1][j]!=0)
        {
            if(matr[i-1][j]!=anterior)
            {
                matr[i][k]=nr;
                k++;
                matr[i][k]=anterior;
                k++;
                nr=1;
                anterior=matr[i-1][j];
            }
            else
                nr++;
            j++;
        }
        {
            matr[i][k]=nr;
            k++;
            matr[i][k]=anterior;
            k++;
            nr=1;
            anterior=matr[i-1][j];
        }

        matr[i][k++]=0;

    }

}


int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    int m,n,p;
    genereaza();
    for(int i=0; i<10; i++)
    {
        f>>m>>n>>p;

        int j=n-1;
        while(j<n+p)
        {
            g<<matr[m-1][j];
            j++;
        }
        g<<endl;
    }


    return 0;
}
