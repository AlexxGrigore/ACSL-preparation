#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct board{int no=-1, w=0, b=0;}table[7][7];
int cap, pin, stackh, ccap, cpin, vi[]={0, -1, 0, 1}, vj[]={-1, 0, 1, 0}, v, n, towerb;

void initiateTable()
{
    int c=1;
    for(int i=1; i<6; i++)
        for(int j=1; j<6; j++)
            table[i][j].no=c++, table[i][j].b=0, table[i][j].w=0;
    return;
}

void findSolutions(int loc, int depth=0)
{
    int ci=(loc-1)/5+1+vi[v], cj=(loc-1)%5+1+vj[v];
    if(depth==n || depth>=5 || towerb<=0 || table[ci][cj].no==-1)
    {
        int cstackh=0;
        for(int i=1; i<=5; i++)
            for(int j=1; j<=5; j++)
                if(table[i][j].b>cstackh)
                    cstackh=table[i][j].b;
        if(ccap>cap)
            cap=ccap, pin=cpin, stackh=cstackh;
        else if(ccap==cap && cpin>pin)
            pin=cpin, stackh=cstackh;
        else if(ccap==cap && cpin==pin && cstackh>stackh)
            stackh=cstackh;
        return;
    }
    if(table[ci][cj].b!=0)
    {
        for(int i=1; i<table[ci][cj].b && i<towerb; i++)
        {
            towerb+=i;
            table[ci][cj].b-=i;
            findSolutions(table[ci][cj].no, depth+1);
            towerb-=2*i;
            table[ci][cj].b+=2*i;
            findSolutions(table[ci][cj].no, depth+1);
            towerb+=i;
            table[ci][cj].b-=i;
        }
    }
    else if(table[ci][cj].w!=0)
    {
        int i;
        for(i=1; i<table[ci][cj].w && i<=towerb; i++)
        {
            towerb-=i;
            cpin+=table[ci][cj].w;
            table[ci][cj].b+=i;
            findSolutions(table[ci][cj].no, depth+1);
            towerb+=i;
            cpin-=table[ci][cj].w;
            table[ci][cj].b-=i;
        }
        if(i==table[ci][cj].w && i<=towerb)
        {
            towerb-=i;
            ccap+=i;
            table[ci][cj].b=table[ci][cj].w;
            table[ci][cj].w=0;
            findSolutions(table[ci][cj].no, depth+1);
            table[ci][cj].w=table[ci][cj].b;
            table[ci][cj].b=0;
            ccap-=i;
            towerb+=i;
        }
    }
    else
    {
        for(int i=1; i<towerb; i++)
        {
            towerb-=i;
            findSolutions(table[ci][cj].no, depth+1);
            towerb+=i;
        }
    }
    findSolutions(table[ci][cj].no, depth+1);
    return;
}

int main()
{
    freopen("acsl9.txt", "r", stdin);
    for(int abc=0; abc<10; abc++)
    {
        int loc[25], k=0;
        char data[25][3];
        memset(data, 0, 25*3);
        scanf("%d, %c%c", &loc[0], &data[0][0], &data[0][1]);
        initiateTable();
        if(data[k][1]=='B')
            table[(loc[k]-1)/5+1][(loc[k]-1)%5+1].b=data[k][0]-'0';
        else if(data[k][1]=='W')
            table[(loc[k]-1)/5+1][(loc[k]-1)%5+1].w=data[k][0]-'0';
        while(loc[k]!=0)
        {
            k++;
            scanf(", %d", &loc[k]);
            scanf(", %c%c", &data[k][0], &data[k][1]);
            if(data[k][1]=='B')
                table[(loc[k]-1)/5+1][(loc[k]-1)%5+1].b=data[k][0]-'0';
            else if(data[k][1]=='W')
                table[(loc[k]-1)/5+1][(loc[k]-1)%5+1].w=data[k][0]-'0';
        }
        scanf("\n");
        cap=0, pin=0, stackh=0;
        for(int i=0; i<k; i++)
        {
            if(data[i][1]=='B')
            {
                towerb=data[i][0]-'0';
                n=towerb;
                int aux=table[(loc[i]-1)/5+1][(loc[i]-1)%5+1].b;
                table[(loc[i]-1)/5+1][(loc[i]-1)%5+1].b=0;
                for(v=0; v<4; v++)
                    findSolutions(loc[i]);
                table[(loc[i]-1)/5+1][(loc[i]-1)%5+1].b=aux;
            }
        }
        printf("%d, %d, %d\n", cap, pin, stackh);
    }
    return 0;
}
