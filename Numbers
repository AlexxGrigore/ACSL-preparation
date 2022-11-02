#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void perm(char nr[], int k)
{
    for(int i=0; i<k-1; i++)
        next_permutation(nr, nr+strlen(nr));
    return;
}

void permReverse(char nr[])
{
    for(int i=0; i<49; i++)
        prev_permutation(nr, nr+strlen(nr));
    return;
}


void findClosest(long mean, char nr[])
{
    reverse(nr, nr+strlen(nr));
    char big[11];
    memset(big, 0, 11);
    strcpy(big, nr);
    while(atol(big)<mean)
        next_permutation(big, big+strlen(big));
    char small[11];
    memset(small, 0, 11);
    prev_permutation(big, big+strlen(big));
    strcpy(small, big);
    next_permutation(big, big+strlen(big));
    long n1=atol(small);
    long n2=atol(big);
    n1=mean-n1;
    n2=n2-mean;
    if(n1<n2)
        cout<<atol(small)<<endl;
    else if(n2<n1)
        cout<<atol(big)<<endl;
    return;

}

int main()
{
    freopen("acsl1.txt", "r", stdin);
    ///for(int abc=0; abc<2; abc++)
    {
        char nr[11]; int k;
        memset(nr, 0, 11);
        scanf("%s %d\n", &nr, &k);
        nr[strlen(nr)-1]=0;
        sort(nr, nr+strlen(nr));
        cout<<atol(nr);
        cout<<endl;
        reverse(nr, nr+strlen(nr));
        cout<<atol(nr);
        cout<<endl;
        permReverse(nr);
        cout<<atol(nr);
        cout<<endl;
        sort(nr, nr+strlen(nr));
        perm(nr, k);
        cout<<atol(nr);
        cout<<endl;
        sort(nr, nr+strlen(nr));
        long n1=atol(nr);
        reverse(nr, nr+strlen(nr));
        long n2=atol(nr);
        long mean=(n1+n2)/2;
        findClosest(mean, nr);
    }
    return 0;
}
