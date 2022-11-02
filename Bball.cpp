#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

float median(int p[])
{
    float p1[10];
    for(int i=0; i<10; i++)
        p1[i]=p[i];
    sort(p1, p1+10);
    return (p1[4]+p1[5])/2;
}

int main()
{
    freopen("acsl6.txt", "r", stdin);
    char teamx[5][2][50], teamy[5][2][50];
    memset(teamx, 0, 500);
    memset(teamy, 0, 500);
    int points[10];
    float mean=0;
    for(int i=0; i<5; i++)
    {
        points[i]=0;
        scanf("%s %s\n", &teamx[i][0], &teamx[i][1]);
        for(int j=1; j<=4; j++)
        {
            mean+=(teamx[i][1][j-1]-'0')*j;
            points[i]+=(teamx[i][1][j-1]-'0')*j;
        }
    }
    for(int i=0; i<5; i++)
    {
        points[i+5]=0;
        scanf("%s %s\n", &teamy[i][0], &teamy[i][1]);
        for(int j=1; j<=4; j++)
        {
            mean+=(teamy[i][1][j-1]-'0')*j;
            points[i+5]+=(teamy[i][1][j-1]-'0')*j;
        }
    }
    mean/=10;
    printf("%.1f\n%.1f\n", mean, median(points));
    int maximx=-1, maxpozx, maximy=-1, maxpozy;
    for(int i=0; i<5; i++)
    {
        teamx[i][0][strlen(teamx[i][0])-1]=0;
        teamy[i][0][strlen(teamy[i][0])-1]=0;
        if(maximx<points[i])
            maximx=points[i], maxpozx=i;
        if(maximy<points[i+5])
            maximy=points[i+5], maxpozy=i;
    }
    cout<<teamx[maxpozx][0]<<", "<<teamy[maxpozy][0]<<endl;
    if(maximx>maximy)
    {
        cout<<teamx[maxpozx][0]<<", ";
        maximy=-1;
        for(int i=0; i<10; i++)
        {
            if(points[i]>maximy && points[i]<maximx)
                maximy=points[i], maxpozy=i;
        }
        if(maxpozy>=5)
            cout<<teamy[maxpozy-5][0]<<endl;
        else
            cout<<teamx[maxpozy][0]<<endl;
    }
    else if(maximx<maximy)
    {
        cout<<teamy[maxpozy][0]<<", ";
        maximx=-1;
        for(int i=0; i<10; i++)
        {
            if(points[i]>maximx && points[i]<maximy)
                maximx=points[i], maxpozx=i;
        }
        if(maxpozx>=5)
            cout<<teamy[maxpozx-5][0]<<endl;
        else
            cout<<teamx[maxpozx][0]<<endl;
    }
    else
        cout<<teamx[maxpozx][0]<<", "<<teamy[maxpozy][0]<<endl;
    int px=0, py=0;
    for(int i=0; i<5; i++)
        px+=points[i],py+=points[i+5];
    if(px>py)
        printf("%d, %d\n", px, py);
    else
        printf("%d, %d\n", py, px);
    int minim=INT_MAX;
    for(int i=0; i<10; i++)
        if(points[i]<minim)
            minim=points[i];
    for(int i=0; i<10; i++)
        if(points[i]==minim)
        {
            if(i<5)
                printf("%s ", teamx[i][0]);
            else
                printf("%s ", teamy[i-5][0]);
        }
    cout<<endl;
    int mingol=INT_MAX, maxgol=-1;
    for(int i=0; i<5; i++)
    {
        double currgolx=0, currgoly=0, attemptsx, attemptsy;
        if(teamx[i][1][4]<='9')
            attemptsx=teamx[i][1][4]-'0';
        else
            attemptsx=teamx[i][1][4]-'A'+10;
        if(teamy[i][1][4]<='9')
            attemptsy=teamy[i][1][4]-'0';
        else
            attemptsy=teamy[i][1][4]-'A'+10;
        for(int j=0; j<4; j++)
            currgolx+=teamx[i][1][j]-'0', currgoly+=teamy[i][1][j]-'0';
        int perx=currgolx/attemptsx*100;
        int pery=currgoly/attemptsy*100;
        if(pery<mingol)
            mingol=pery;
        if(perx>maxgol)
            maxgol=perx;
    }
    for(int i=0; i<5; i++)
    {
        double curr=0, attempts;
        if(teamx[i][1][4]<='9')
            attempts=teamx[i][1][4]-'0';
        else
            attempts=teamx[i][1][4]-'A'+10;
        for(int j=0; j<4; j++)
            curr+=teamx[i][1][j]-'0';
        if((int)(curr/attempts*100)==maxgol)
            printf("%s ", teamx[i][0]);
    }
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        double curr=0, attempts;
        if(teamy[i][1][4]<='9')
            attempts=teamy[i][1][4]-'0';
        else
            attempts=teamy[i][1][4]-'A'+10;
        for(int j=0; j<4; j++)
            curr+=teamy[i][1][j]-'0';
        if((int)(curr/attempts*100)==mingol)
            printf("%s ", teamy[i][0]);
    }
    cout<<endl;
    int maxz=0;
    for(int i=0; i<5; i++)
    {
        if(teamx[i][1][1]>maxz)
            maxz=teamx[i][1][1];
        if(teamy[i][1][1]>maxz)
            maxz=teamy[i][1][1];
    }
    for(int i=0; i<5; i++)
    {
        if(teamx[i][1][1]==maxz)
            cout<<teamx[i][0]<<' ';
        if(teamy[i][1][1]==maxz)
            cout<<teamy[i][0]<<' ';
    }
    cout<<endl;
    maxz=0;
    for(int i=0; i<5; i++)
    {
        if(teamx[i][1][0]>maxz)
            maxz=teamx[i][1][0];
        if(teamy[i][1][0]>maxz)
            maxz=teamy[i][1][0];
    }
    for(int i=0; i<5; i++)
    {
        if(teamx[i][1][0]==maxz)
            cout<<teamx[i][0]<<' ';
        if(teamy[i][1][0]==maxz)
            cout<<teamy[i][0]<<' ';
    }
    return 0;
}
