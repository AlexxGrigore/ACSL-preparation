#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

void permutari(char s[], char permu[], char ords[], int depth, long long last[], long long &n, bool &done, char facute[][16], int depthcurr=0)
{
    for(int i=0; i<depth && done==0; i++)
    {
        bool cont=0;
        for(int j=0; j<depthcurr && cont==0; j++)
            if(last[j]==i)
                cont=1;
        if(cont==1)
            continue;
        last[depthcurr]=i;
        if(depthcurr+1<depth)
            permutari(s, permu, ords, depth, last, n, done, facute, depthcurr+1);
        else
        {
            for(int j=0; j<depth; j++)
                permu[j]=ords[last[j]];
            bool gasit=0;
            for(int j=0; j<n && gasit==0; j++)
            {
                if(strcmp(permu, facute[j])==0)
                    gasit=1;
            }
            if(gasit==0)
            {
                strcpy(facute[n], permu);
                n++;
            }
            if(strcmp(permu, s)==0)
            {
                done=1;
                return;
            }
        }
    }
    return;
}

void sorting(char permu[][100], int n)
{
    bool ok=0;
    do
    {
        ok=0;
        for(int i=0; i<n-1; i++)
            if(strcmp(permu[i], permu[i+1])>0)
            {
                swap(permu[i], permu[i+1]);
                ok=1;
            }
    }while(ok==1);
    return;
}

int main()
{
    ifstream f("acsl7.txt");
    for(int abc=0; abc<10; abc++)
    {
        char s[100], ords[100], permu[16], facute[100000][16];
        memset(s, 0, 100);
        memset(ords, 0, 100);
        memset(facute, 0, sizeof(facute));
        f.getline(s, 99);
        strcpy(ords, s);
        sort(ords, ords+strlen(ords));
        long long last[10000], n=0;
        for(int i=0; i<10000; i++)
            last[i]=-1;
        bool done=0;
        permutari(s, permu, ords, strlen(s), last, n, done, facute);
        cout<<n<<endl;
        ///sorting(permu, n);
        ///for(int i=0; i<n; i++)
          ///  if(strcmp(s, permu[i])==0)
          ///      cout<<i+1<<endl;
    }
    return 0;
}
