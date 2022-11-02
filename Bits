#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void comb(char bts[][4], int n)
{
    char res[4]=""; int combinations=1;
    bool zeros[3]={0, 0, 0}, ones[3]={0, 0, 0};
    for(int i=0; i<n; i++)
    {
        for(int j=strlen(bts[i])-1, k=2; j>=0; j--, k--)
            if(bts[i][j]=='0')
                zeros[k]=1;
            else
                ones[k]=1;
    }
    for(int i=0; i<3; i++)
    {
        if(zeros[i] && ones[i])
            res[i]='*', combinations*=2;
        if(zeros[i] && !ones[i])
            res[i]='0';
        if(!zeros[i] && ones[i])
            res[i]='1';
    }
    if(combinations == n)
    {
        for(int i=0; i<3; i++)
            cout<<res[i];
        cout<<endl;
        return;
    }
    cout<<"NULL\n";
    return;
}

int main()
{
    freopen("data.in", "r", stdin);
    for(int abc=0; abc<5; abc++)
    {
        int n; char bts[8][4];
        scanf("%d, ", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%s", &bts[i]);
            if(i!=n-1)
                bts[i][strlen(bts[i])-1]=0;
        }
        comb(bts, n);
    }
    return 0;
}
