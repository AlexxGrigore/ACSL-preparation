#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int matr[100][100];

void convert(string numar,int index)
{
    for(int i=0,j=0; i<numar.length(); i++,j+=4)
    {
        if(numar[i]=='0')
        {
            matr[index][j]=0;
            matr[index][j+1]=0;
            matr[index][j+2]=0;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='1')
        {
            matr[index][j]=0;
            matr[index][j+1]=0;
            matr[index][j+2]=0;
            matr[index][j+3]=1;
            continue;
        }
        if(numar[i]=='2')
        {
            matr[index][j]=0;
            matr[index][j+1]=0;
            matr[index][j+2]=1;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='3')
        {
            matr[index][j]=0;
            matr[index][j+1]=0;
            matr[index][j+2]=1;
            matr[index][j+3]=1;
            continue;
        }
        if(numar[i]=='4')
        {
            matr[index][j]=0;
            matr[index][j+1]=1;
            matr[index][j+2]=0;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='5')
        {
            matr[index][j]=0;
            matr[index][j+1]=1;
            matr[index][j+2]=0;
            matr[index][j+3]=1;
            continue;
        }
        if(numar[i]=='6')
        {
            matr[index][j]=0;
            matr[index][j+1]=1;
            matr[index][j+2]=1;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='7')
        {
            matr[index][j]=0;
            matr[index][j+1]=1;
            matr[index][j+2]=1;
            matr[index][j+3]=1;
            continue;
        }
        if(numar[i]=='8')
        {
            matr[index][j]=1;
            matr[index][j+1]=0;
            matr[index][j+2]=0;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='9')
        {
            matr[index][j]=1;
            matr[index][j+1]=0;
            matr[index][j+2]=0;
            matr[index][j+3]=1;
            continue;
        }
        if(numar[i]=='A')
        {
            matr[index][j]=1;
            matr[index][j+1]=0;
            matr[index][j+2]=1;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='B')
        {
            matr[index][j]=1;
            matr[index][j+1]=0;
            matr[index][j+2]=1;
            matr[index][j+3]=1;
            continue;;
        }
        if(numar[i]=='C')
        {
            matr[index][j]=1;
            matr[index][j+1]=1;
            matr[index][j+2]=0;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='D')
        {
            matr[index][j]=1;
            matr[index][j+1]=1;
            matr[index][j+2]=0;
            matr[index][j+3]=1;
            continue;
        }
        if(numar[i]=='E')
        {
            matr[index][j]=1;
            matr[index][j+1]=1;
            matr[index][j+2]=1;
            matr[index][j+3]=0;
            continue;
        }
        if(numar[i]=='F')
        {
            matr[index][j]=1;
            matr[index][j+1]=1;
            matr[index][j+2]=1;
            matr[index][j+3]=1;
            continue;
        }

    }
}

void det_divizori(int div[], int &nr_div, int x)
{
    int d;
    nr_div=0;
    for(d=1; d*d<x; d++)
        if(x%d==0)
            div[nr_div++]=d,div[nr_div++]=x/d;
    if(d*d==x)
        div[nr_div++]=d;
}

bool este_tipar(int r, int c, int sr, int sc)
{
    for(int j=0; j<c; j++)
    {
        for(int i=0; i+sr<r; i++)
            if(matr[i][j]!=matr[i+sr][j])
                return false;
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j+sc<c; j++)
            if(matr[i][j]!=matr[i][j+sc])
                return 0;
    }
    return true;
}

void rezolvare(int n, int m,int nr_div_n, int nr_div_m, int div_n[], int div_m[], int &rez_lin, int &rez_col)
{
    sort(div_n,div_n+nr_div_n);
    sort(div_m,div_m+nr_div_m);

    int i,j;
    for(i=0; i<nr_div_n; i++)
    {
        for(j=0; j<nr_div_m; j++)
        {
            if(este_tipar(n,m,div_n[i],div_m[j]))
            {
                rez_lin=div_n[i],rez_col=div_m[j];
                return;
            }
        }
    }

    rez_lin=n,rez_col=m;

}
int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    int n, m, div_n[100], div_m[100],nr_div_n=0,nr_div_m=0,rez_linie=0,rez_coloana=0;
    string str;

    for(int k=0; k<10; k++)
    {
        f>>n>>m;
        det_divizori(div_n,nr_div_n,n);
        det_divizori(div_m,nr_div_m,m);
        for(int i=0; i<n; i++)
        {
            f>>str;
            convert(str,i);
        }

        rezolvare(n,m,nr_div_n,nr_div_m,div_n,div_m,rez_linie,rez_coloana);
        cout<<rez_linie<<" "<<rez_coloana<<endl;
    }

    return 0;
}
