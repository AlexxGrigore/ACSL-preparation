#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

struct node{int dept=-1, cl=-1, cr=-1; char val=0;};
char str[10000];
int len;

void stergere(int &len)
{
    int sterse=0;
    for(int i=0; i<=len; i++)
    {
        if(str[i]<65 || (str[i]>90 && str[i]<97) || str[i]>122)
            sterse++;
        else
            str[i-sterse]=str[i];
    }
    len-=sterse;
    return;
}

void formarb(node v[], char ins, int &n)
{
    int c=0, d=0;
    while(1)
    {
        if(ins>v[c].val)
        {
            if(v[c].cr==-1)
            {
                v[c].cr=n;
                v[n].val=ins;
                v[n].dept=v[c].dept+1;
                break;
            }
            else
                c=v[c].cr;
        }
        else if(ins<=v[c].val)
        {
            if(v[c].cl==-1)
            {
                v[c].cl=n;
                v[n].val=ins;
                v[n].dept=v[c].dept+1;
                break;
            }
            else
                c=v[c].cl;
        }
    }
    if(n+1<=len)
    {
        n++;
        formarb(v, str[n], n);
    }
    return;
}

int main()
{
    freopen("acsl8.in", "r", stdin);
    for(int abc=0; abc<2; abc++)
    {
        memset(str, 0, 10000);
        len=-1;
        do{
            len++;
            scanf("%c", &str[len]);
        }while(str[len]>31);
        stergere(len);
        node nodes[10000];
        int n=1;
        nodes[0].val=str[0];
        nodes[0].dept=0;
        formarb(nodes, str[1], n);
        int cer=0;
        for(int i=0; i<=n; i++)
            cer=max(cer, nodes[i].dept);
        cout<<cer<<endl;
        cer=0;
        for(int i=0; i<=n; i++)
        {
            if(nodes[i].cl==-1&&nodes[i].cr==-1)
                cer++;
        }
        cout<<cer<<endl;
        cer=0;
        for(int i=0; i<=n; i++)
        {
            if((nodes[i].cl==-1 && nodes[i].cr!=-1) || (nodes[i].cl!=-1 && nodes[i].cr==-1))
                cer++;
        }
        cout<<cer<<endl;
        cer=0;
        for(int i=0; i<=n; i++)
            cer+=nodes[i].dept;
        cout<<cer<<endl;
        cer=0;
        for(int i=0; i<=n; i++)
        {
            if(nodes[i].cl == -1)
                cer+=nodes[i].dept+1;
            if(nodes[i].cr == -1)
                cer+=nodes[i].dept+1;
        }
        cout<<cer<<endl;
    }
    return 0;
}
