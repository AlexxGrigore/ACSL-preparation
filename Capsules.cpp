#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>

using namespace std;

struct mystructure
{
    int val, subarr, prefilled=-1;
} table[500][500];

int generare[70][5040];
short a[70], b, rez;
int pre[1000];
bool found = 0;

void generarecomb(int last[], int gencr, int nrgen)
{
    for(int i=1; i<=nrgen; i++)
    {
        bool ok=1;
        for(int j=0; j<gencr; j++)
        {
            if(i==last[j])
                ok=0;
        }
        if(ok==0)
            continue;
        else if(gencr+1<nrgen)
        {
            last[gencr]=i;
            generarecomb(last, gencr+1, nrgen);
            last[gencr]=0;
        }
        else
        {
            last[gencr]=i;
            for(int j=0, p=1; j<nrgen; j++, p*=10)
                generare[b][a[b]]+=last[j]*p;
            last[gencr]=0;
            a[b]++;
            return;
        }
    }
    return;
}

void filling(short table[][1000], int si=0, int sj=0, int fillno=1, int r=0, int c=0)
{
    queue<pair<int, int>>Q;
    short vi[]= {0, 1, -1, 0};
    short vj[]= {1, 0, 0, -1};
    Q.push({si*2+1, sj*2+1});
    while(!Q.empty())
    {
        int i=Q.front().first, j=Q.front().second;
        Q.pop();
        if(table[i][j]==0)
        {
            table[i][j]=fillno;
            pre[fillno-1]++;
            for(int k=0; k<4; k++)
                if(table[i+vi[k]][j+vj[k]]==0 && i+vi[k]*2>=0 && j+vj[k]*2>=0 && i+vi[k]*2<=2*r && j+vj[k]*2<=2*c)
                    if(table[i+vi[k]*2][j+vj[k]*2]==0)
                        Q.push({i+vi[k]*2, j+vj[k]*2});
        }
    }
    return;
}

void generarematr(char e[], int r, int c)
{
    int nr=0;
    rez=0;
    short matr[1000][1000];
    for(int i=0; i<1000; i++)
        for(int j=0; j<1000; j++)
            matr[i][j]=0;
    for(int i=0; i<=r; i++)
        for(int j=0; j<=c; j++)
            matr[i*2][j*2]=1;
    short d[500];
    for(int i=0; i<strlen(e)-1; i++)
    {
        if(e[i]>='0' && e[i]<='9')
            d[i]=e[i]-'0';
        else
            d[i]=10+e[i]-'A';
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++, nr++)
        {
            if((d[nr]&1)==1)
                matr[i*2+1][j*2]=1;
            if((d[nr]&2)==2)
                matr[i*2][j*2+1]=1;
            if((d[nr]&4)==4)
                matr[i*2+1][(j+1)*2]=1;
            if((d[nr]&8)==8)
                matr[(i+1)*2][j*2+1]=1;
        }
    }
    nr=1;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(matr[i*2+1][j*2+1]==0)
                filling(matr, i, j, nr++, r, c);
        }
    }
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++)
            if(matr[2*i-1][2*j]==0 && matr[2*i][2*j-1]==0 && matr[2*i+1][2*j]==0 && matr[2*i][2*j+1]==0)
                rez++;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            table[i][j].subarr=matr[i*2+1][j*2+1];
    return;
}

bool checkforrepetition(int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(table[i][j].prefilled!=-1 && table[i][j].prefilled!=table[i][j].val)
                return 0;
            if(i>0)
            {
                if(j>0)
                    if(table[i][j].val==table[i-1][j-1].val)
                        return 0;
                if(table[i][j].val==table[i-1][j].val)
                    return 0;
                if(j<c-1)
                    if(table[i][j].val==table[i-1][j+1].val)
                        return 0;
            }
            if(i<r-1)
            {
                if(j>0)
                    if(table[i][j].val==table[i+1][j-1].val)
                        return 0;
                if(table[i][j].val==table[i+1][j].val)
                    return 0;
                if(j<c-1)
                    if(table[i][j].val==table[i+1][j+1].val)
                        return 0;
            }
            if(j>0)
                if(table[i][j].val==table[i][j-1].val)
                    return 0;
            if(j<c-1)
                if(table[i][j].val==table[i][j+1].val)
                    return 0;
        }
    }
    return 1;
}

void verfTot(int r, int c, int gencr=0)
{
    for(int i=0; i<a[gencr]; i++)
    {
        if(found == 0)
        {
            long long last=generare[gencr][i];
            bool ok=1;
            for(int j=0; j<r && ok==1; j++)
                for(int k=0; k<c && ok==1; k++)
                {
                    if(table[j][k].subarr==gencr+1)
                    {
                        table[j][k].val=last%10;
                        last/=10;
                        if(table[j][k].prefilled!=-1 && table[j][k].val!=table[j][k].prefilled)
                            ok=0;
                    }
                }
            if(ok==0)
                continue;
        }
        if(gencr+1<b && found == 0)
        {
            verfTot(r, c, gencr+1);
        }
        else if(found == 0)
        {
            if(checkforrepetition(r, c))
            {
                found = 1;
                return;
            }
        }
    }
    return;
}

int main()
{
    freopen("acsl9.in", "r", stdin);
    for(int abc=0; abc<2; abc++)
    {
        found = 0;
        for(int i=0; i<500; i++)
            for(int j=0; j<500; j++)
            {
                table[i][j].prefilled=-1;
                table[i][j].val=0;
                table[i][j].subarr=0;
            }
        for(int i=0; i<70; i++)
            for(int j=0; j<5040; j++)
                generare[i][j]=0;
        for(int i=0; i<70; i++)
            a[i]=0;
        b=0;
        int r, c, n;
        char aranjament[500];
        scanf("%d, %d, %s %d", &r, &c, &aranjament, &n);
        for(int i=0; i<n; i++)
        {
            scanf(", %d", &pre[i]);
            int val=0, x, y, p=1;
            while(pre[i]>99)
            {
                val+=(pre[i]%10)*p;
                pre[i]/=10;
                p*=10;
            }
            y=pre[i]%10;
            pre[i]/=10;
            x=pre[i];
            y--;
            x--;
            table[x][y].prefilled=val;
        }
        for(int i=0; i<1000; i++)
            pre[i]=0;
        generarematr(aranjament, r, c);
        for(b=0; pre[b]!=0; b++)
        {
            int last[500];
            for(int j=0; j<pre[b]; j++)
                last[j]=0;
            generarecomb(last, 0, pre[b]);
        }
        int last[500];
        for(int i=0; i<500; i++)
            last[i]=0;
        cout<<rez<<endl<<b<<endl;
        rez=0;
        for(int i=0; i<b; i++)
            pre[i]=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(table[i][j].prefilled!=-1)
                    pre[table[i][j].subarr-1]=1;
        for(int i=0; i<b; i++)
            if(pre[i]==0)
                rez++;
        cout<<rez<<endl;
        rez=0;
        verfTot(r, c, 0);
        for(int i=0; i<c; i++)
            rez+=table[r-1][i].val;
        cout<<rez<<endl;
        rez=0;
        for(int i=0; i<r; i++)
            rez+=table[i][0].val;
        cout<<rez<<endl;
    }
    return 0;
}
