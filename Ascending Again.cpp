#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("acsl5.txt", "r", stdin);
    for(int abc=0; abc<10; abc++)
    {
        int rep=0;
        scanf("%c", &rep);
        rep-='0';
        char cifre[129]; long long rezultat[257];
        for(int i=0; i<257; i++)
            rezultat[i]=0;
        memset(cifre, 0, 129);
        scanf("%s\n", &cifre);
        short fr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, nr=0;
        for(int i=0; i<strlen(cifre); i++)
            fr[cifre[i]-'0']++;
        for(int i=0; i<strlen(cifre)/rep; i++, nr++)
        {
            for(int j=0; j<rep; j++)
            {
                int x=0;
                if(j==0)
                    x++;
                for(; x<10; x++)
                {
                    if(fr[x]>0)
                    {
                        fr[x]--;
                        rezultat[nr]=rezultat[nr]*10+x;
                        if(nr>0)
                        {
                            if(rezultat[nr]==rezultat[nr-1])
                            {
                                fr[x]++;
                                rezultat[nr]/=10;
                                continue;
                            }
                        }
                        break;
                    }
                }
                if(j==rep-1 && rezultat[nr]<=rezultat[nr-1])
                {
                    rezultat[nr]=0;
                    nr--;
                }
            }
        }
        for(int i=0; i<nr; i++)
        {
            if(rezultat[i]!=0)
                cout<<rezultat[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
