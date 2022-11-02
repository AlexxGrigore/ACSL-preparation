#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

void fiftyeth(char nr[])
{
    for(int i=0; i<49; i++)
        prev_permutation(nr, nr+strlen(nr));
    return;
}

void kth(char nr[], int k)
{
    for(int i=0; i<k-1; i++)
        next_permutation(nr, nr+strlen(nr));
    return;
}

void findClosest(long long mean, char nr[])
{
    reverse(nr, nr+strlen(nr));
    char big[11];
    memset(big, 0, 11);
    strcpy(big, nr);
    char *p;
    while(strtoll(big, &p, 36)<=mean)
        next_permutation(big, big+strlen(big));
    char small[11];
    memset(small, 0, 11);
    prev_permutation(big, big+strlen(big));
    strcpy(small, big);
    next_permutation(big, big+strlen(big));
    long long n1=strtoll(small, &p, 36);
    long long n2=strtoll(big, &p, 36);
    n1=mean-n1;
    n2=n2-mean;
    if(n1<n2)
    {
        bool done=false;
        for(int i=0; i<strlen(small); i++)
            if(done==false && small[i]!='0')
            {
                cout<<small[i];
                done=true;
            }
            else if(done == true)
                cout<<small[i];
        cout<<endl;
    }
    else if(n2<n1)
    {
        bool done=false;
        for(int i=0; i<strlen(big); i++)
            if(done==false && big[i]!='0')
            {
                cout<<big[i];
                done=true;
            }
            else if(done == true)
                cout<<big[i];
        cout<<endl;
    }
    else if(n1==n2)
    {
        bool done=false;
        for(int i=0; i<strlen(small); i++)
            if(done==false && small[i]!='0')
            {
                cout<<small[i];
                done=true;
            }
            else if(done == true)
                cout<<small[i];
        cout<<" and ";
        done=false;
        for(int i=0; i<strlen(big); i++)
            if(done==false && big[i]!='0')
            {
                cout<<big[i];
                done=true;
            }
            else if(done == true)
                cout<<big[i];
        cout<<endl;
    }
    return;

}

int main()
{
    freopen("acsl6.txt", "r", stdin);
    for(int abc=0; abc<2; abc++)
    {
        char nr[11]; int k;
        memset(nr, 0, 11);
        scanf("%s %d\n", &nr, &k);
        nr[strlen(nr)-1]=0;
        sort(nr, nr+strlen(nr));
        bool done=false;
        for(int i=0; i<strlen(nr); i++)
            if(done==false && nr[i]!='0')
            {
                cout<<nr[i];
                done=true;
            }
            else if(done == true)
                cout<<nr[i];
        cout<<endl;
        reverse(nr, nr+strlen(nr));
        done=false;
        for(int i=0; i<strlen(nr); i++)
            if(done==false && nr[i]!='0')
            {
                cout<<nr[i];
                done=true;
            }
            else if(done == true)
                cout<<nr[i];
        cout<<endl;
        fiftyeth(nr);
        done=false;
        for(int i=0; i<strlen(nr); i++)
            if(done==false && nr[i]!='0')
            {
                cout<<nr[i];
                done=true;
            }
            else if(done == true)
                cout<<nr[i];
        cout<<endl;
        sort(nr, nr+strlen(nr));
        kth(nr, k);
        done=false;
        for(int i=0; i<strlen(nr); i++)
            if(done==false && nr[i]!='0')
            {
                cout<<nr[i];
                done=true;
            }
            else if(done == true)
                cout<<nr[i];
        cout<<endl;
        sort(nr, nr+strlen(nr));
        char *p;
        long long n1=strtoll(nr, &p, 36);
        reverse(nr, nr+strlen(nr));
        long long n2=strtoll(nr, &p, 36);
        long long mean=(n1+n2)/2;
        findClosest(mean, nr);
        cout<<endl;
    }
    return 0;
}
