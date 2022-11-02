#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define sz 2574
using namespace std;

bool adia[sz][sz];

void gen_ad()
{
    for(int i=0; i<sz; i++)
    {
        adia[i][i]=0;
        if(i>=26)
            adia[i][i-26]=1;
        if(i%26>0 && i<sz-26 && i%2==0)
            adia[i][i+25]=1;
        if(i<sz-26)
            adia[i][i+26]=1;
        if(i%26!=25 && i<sz-27 && i%2==0)
            adia[i][i+27]=1;
        if(i%26>0)
            adia[i][i-1]=1;
        if(i%26!=25)
            adia[i][i+1]=1;
        if(i%26!=25 && i>25 && i%2 == 1)
            adia[i][i-25]=1;
        if(i%26>0 && i>25 && i%2==1)
            adia[i][i-27]=1;
    }
    return;
}

int numara(int start, int fin, int n)
{
    if (n == 0 && start == fin)
        return 1;
    if (n == 1 && adia[start][fin])
        return 1;
    if (n <= 0)
        return 0;
    queue<int>Q;
    queue<pair<int, int> >P;
    int nr = 0;
    for (int i = 0; i < sz; i++)
        if (adia[start][i] == 1)
        {
            Q.push(i);
        }
    for(int i=0; i<sz; i++)
    {
        if(adia[start][i]==1)
        {
            P.push({start, i});
            adia[start][i]=0;
        }
        if(adia[i][start]==1)
        {
            P.push({i, start});
            adia[i][start]=0;
        }
    }
    while(!Q.empty())
    {
        int st=Q.front();
        Q.pop();
        nr+=numara(st, fin, n-1);
    }
    while(!P.empty())
    {
        int i=P.front().first, j=P.front().second;
        P.pop();
        adia[i][j]=1;
    }
    return nr;
}

int main()
{
    freopen("hex.in", "r", stdin);
    for(int abc=0; abc<10; abc++)
    gen_ad();
    for(int abc=0; abc<10; abc++)
    {
        char st[4]= {0, 0, 0, 0}, fn[4]= {0, 0, 0, 0};
        int n;
        scanf("%s %s %d\n", &st, &fn, &n);
        int start=0, fin=0;
        start+=st[1]-'0';
        if(st[2]!=0)
        {
            start*=10;
            start+=st[2]-'0';
        }
        start--;
        start*=26;
        start+=st[0]-'A';
        fin+=fn[1]-'0';
        if(fn[2]!=0)
        {
            fin*=10;
            fin+=fn[2]-'0';
        }
        fin--;
        fin*=26;
        fin+=fn[0]-'A';
        cout<<numara(start, fin, n)<<endl;
    }
    return 0;
}
