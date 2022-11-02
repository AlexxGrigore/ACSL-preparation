#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool sir_iesire[1000];
int nr_lungime=0;

struct sirul
{
    int l;
    char sir[1000];
    bool litera_c=0;
};

void pas(sirul arb[], short &arblen)
{
    sirul arbore2[1000];
    sirul temp;
    temp.l=arb[0].l+arb[1].l;
    for(int i=0; i<arb[0].l; i++)
        temp.sir[i]=arb[0].sir[i];
    for(int i=0; i<arb[1].l; i++)
        temp.sir[i+arb[0].l]=arb[1].sir[i];
    temp.litera_c=arb[0].litera_c|arb[1].litera_c;
    if(arb[0].litera_c)
        sir_iesire[nr_lungime++]=0;
    else if(arb[1].litera_c)
        sir_iesire[nr_lungime++]=1;
    int i;
    for(i=2; i<arblen; i++)
    {
        if((arb[i].l==temp.l&&arb[i].sir[0]>=temp.sir[0])||arb[i].l>temp.l)
            break;
        arbore2[i-2]=arb[i];
    }
    arbore2[i-2]=temp;
    i++;
    for(; i<=arblen; i++)
    {
        arbore2[i-2]=arb[i-1];
    }
    arblen--;
    for(i=0; i<arblen; i++)
        arb[i]=arbore2[i];
    return;
}

int main()
{
    freopen("acsl8.in", "r", stdin);
    for(int abc=0; abc<10; abc++)
    {
        sirul arb[1000];
        short arblen=0;
        nr_lungime = 0;
        char word[10000], c;
        memset(word, 0, 10000);
        scanf("%s %c\n", &word, &c);
        short len = strlen(word);
        short frec[26];
        for(int i=0; i<26; i++)
            frec[i]=0;
        for(int i=0; i<len; i++)
            frec[word[i]-65]++;
        short maxim=0;
        for(int i=0; i<26; i++)
            maxim=max(maxim, frec[i]);
        arblen=0;
        for(int i=1; i<=maxim; i++)
        {
            for(int j=0; j<26; j++)
                if(frec[j]==i)
                {
                    arb[arblen].l=i;
                    arb[arblen++].sir[0]=j+65;
                    if(j+65==c)
                        arb[arblen-1].litera_c=1;
                }
        }
        while(arblen>1)
            pas(arb, arblen);
        for(int i=nr_lungime-1; i>=0; i--)
            cout<<sir_iesire[i];
        cout<<endl;
    }
    return 0;
}
