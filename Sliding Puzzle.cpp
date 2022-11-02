#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

void muta(short table[][1000],short pozmut, short &ei, short &ej, int &e, int n)
{
    short dir=0, dist=1;
    while(true)
    {
        if(ej-dist>=0)
            if(table[ei][ej-dist]==pozmut)
            {
                dir=1;
                break;
            }
        if(ej+dist<n)
            if(table[ei][ej+dist]==pozmut)
            {
                dir=2;
                break;
            }
        if(ei-dist>=0)
            if(table[ei-dist][ej]==pozmut)
            {
                dir=3;
                break;
            }
        if(ei+dist<n)
            if(table[ei+dist][ej]==pozmut)
            {
                dir=4;
                break;
            }
        dist++;
    }
    for(int i=0; i<dist && dir!=0; i++)
    {
        switch(dir)
        {
            case 1:{ table[ei][ej-i]=table[ei][ej-i-1]; break;}
            case 2:{table[ei][ej+i]=table[ei][ej+i+1]; break;}
            case 3:{table[ei-i][ej]=table[ei-i-1][ej]; break;}
            case 4:{table[ei+i][ej]=table[ei+i+1][ej]; break;}
        }
    }
    switch(dir)
        {
            case 1:{ table[ei][ej-dist]=-1; ej-=dist; break;}
            case 2:{table[ei][ej+dist]=-1; ej+=dist; break;}
            case 3:{table[ei-dist][ej]=-1; ei-=dist; break;}
            case 4:{table[ei+dist][ej]=-1; ei+=dist; break;}
        }
    return;
}

int main()
{
    freopen("acsl10.in", "r", stdin);
    for(int abc=0; abc<10; abc++)
    {
        int n, e;
        queue<int>Q;
        scanf("%d %d ", &n, &e);
        char c=65;
        short nr=0;
        while(c!=10)
        {
            scanf("%c", &c);
            if(c>=48&&c<=57)
                nr=nr*10+(c-48);
            else{
                Q.push(nr);
                nr=0;
            }
        }
        short table[1000][1000], ei=0, ej=0; nr=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(nr+1==e)
                    table[i][j]=-1, e=-1, ei=i, ej=j;
                else
                    table[i][j]=++nr;
            }
        while(!Q.empty())
        {
            muta(table, Q.front(), ei, ej, e, n);
            Q.pop();
            e=0;
            bool ok = 1;
            for(int i=0; i<n && ok==1; i++)
                for(int j=0; j<n && ok==1; j++)
                {
                    if(table[i][j]==-1)
                        ok=0;
                    e++;
                }
        }
        cout<<e<<endl;
    }
    return 0;
}
