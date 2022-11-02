#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream f("sample.in");
int piese[15];
int n, m;
int board;
int k, l;
bool pieseFol[15];

void afisare(bool mat[10][10])
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

int aria(int i)
{
    int a = 0;
    if(i<100)
    {
        a = (i/10)*(i%10);
    }
    else
        a = (i/100)*((i/10)%10)-(i/100-i%10)*((i/10)%10-1);
    return a;
}

bool cmp(int i, int j)
{
    int a, b;
    a = aria(i);
    b = aria(j);
    if(a>b)
        return true;
    else if(a<b)
        return false;
    else
    {
        if(i<100)
        {
            a = (i/10);
        }
        else
            a = (i/100);
        if(j<100)
        {
            b = (j/10);
        }
        else
            b = (j/100);
        return a>b;
    }
}

void put(int i, int j, int nr, bool mat[10][10])
{
    if(nr<100)
    {
        int x = nr/10;
        int y = nr%10;
        for(int i1 = i; i1>i-x; i1--)
        {
            for(int j1 = j; j1<j+y; j1++)
            {
                mat[i1][j1] = 1;
            }
        }
    }
    else
    {
        int x = nr/100;
        int y = (nr/10)%10;
        for(int i1 = i; i1>i-x; i1--)
        {
            for(int j1 = j; j1<j+y; j1++)
            {
                mat[i1][j1] = 1;
            }
        }
        for(int i1 = i-nr%10; i1>=0; i1--)
        {
            for(int j1 = 1; j1<m; j1++)
            {
                mat[i1][j1] = 0;
            }
        }

    }
}

int add(int i, int j, int pp[15], bool mat[10][10])
{
    for(int k = 0; k<10; k++)
    {
        if(pieseFol[k] == 1)
            continue;
        int a = 100, b = 100;
        if(piese[k]<100)
        {
            a = (piese[k]/10);
            b = piese[k]%10;
        }
        else if(board>=5)
        {
            a = (piese[k]/100);
            b = (piese[k]/10)%10;
        }
        if(i+1>=a && m-j>=b && (!(a==n && b==m) || piese[k]>=100))
        {
            put(i, j, piese[k], mat);
            pp[l++] = piese[k];
            pieseFol[k] = 1;
            k++;
            return 1;
        }
    }
    cout<<"NONE"<<"\n";
    return 0;
}

void rez()
{
    f>>n;
    f.get();
    f>>m;
    f.get();
    bool mat[10][10] = {};
    memset(pieseFol, 0, sizeof(pieseFol));
    int pp[15] = {};
    l = 0;
    k = 0;
    for(int i = n-1; i>=0; i--)
    {
        for(int j = 0; j<m; j++)
        {
            if(mat[i][j] == 0)
            {
                if(add(i, j, pp, mat) == 0)
                {
                    return;
                }
                afisare(mat);
                j = -1;
            }
        }
    }
    for(int i = 0; i<l; i++)
        cout<<pp[i]<<" ";
    cout<<"\n";
    //afisare(mat);
}

int main()
{
    for(int i = 0; i<10; i++)
    {
        f>>piese[i];
        f.get();
    }
    sort(piese, piese+10, cmp);
    for(; board<10; board++)
    {
        rez();
    }
    return 0;
}
