#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

void generateTable(int table[][7])
{
    /*
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            table[i][j]=0;
    table[1][0]=table[2][0]=table[4][0]=table[5][0]=table[1][6]=table[2][6]=table[4][6]=table[5][6]=table[0][1]=table[0][2]=table[0][4]=table[0][5]=table[6][1]=table[6][2]=table[6][4]=table[6][5]=-4;
    table[2][1]=table[4][1]=table[2][5]=table[4][5]=table[1][2]=table[1][4]=table[5][2]=table[5][4]=-4;
    table[3][3]=-4;
    */
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            if(!((i==j) || (i==7-j-1) || (i==3) || (j==3)))
                table[i][j]=-4;
            else
                table[i][j]=0;
    table[3][3]=-4;

    return;
}

void fillTable(int table[][7], int nw, int nb, char w[][3], char b[][3])
{
    for(int i=0; i<nb; i++)
        table[b[i][1]-'1'][b[i][0]-'a']=1;
    for(int i=0; i<nw; i++)
        table[w[i][1]-'1'][w[i][0]-'a']=2;
    return;
}

void possibleCombinations(int table[][7])
{
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            if(table[i][j]==0)
            {
                int depth=1;
                if(!(i>=2 && i<=4 && j>=2 && i<=4))
                    depth++;
                if(!(i>=1 && i<=5 && j>=1 && i<=5))
                    depth++;
                int veb=0, vew=0, hob=0, how=0;
                for(int k=3-depth; k<7-(2-depth); k+=depth)
                {
                    if(i!=3)
                    {
                        if(table[i][k]==2)
                            how++;
                        else if(table[i][k]==1)
                            hob++;
                    }
                    if(j!=3)
                    {
                        if(table[k][j]==2 && k!=i)
                            vew++;
                        else if(table[k][j]==1 && k!=i)
                            veb++;
                    }
                }
                if(how==2 || vew==2)
                    table[i][j]=-2;
                if(hob==2 || veb==2)
                    table[i][j]--;
                how=hob=vew=veb=0;
                if(i==3)
                {
                    for(int k=0; k<3; k++)
                        if(j<=2)
                        {
                            if(table[i][k]==1)
                                hob++;
                            else if(table[i][k]==2)
                                how++;
                        }
                        else if(j>=4)
                        {
                            if(table[i][k+4]==1)
                                hob++;
                            else if(table[i][k+4]==2)
                                how++;
                        }
                }
                if(j==3)
                {
                    for(int k=0; k<3; k++)
                        if(i<=2)
                        {
                            if(table[k][j]==1)
                                veb++;
                            else if(table[k][j]==2)
                                vew++;
                        }
                        else if(i>=4)
                        {
                            if(table[k+4][j]==1)
                                veb++;
                            else if(table[k+4][j]==2)
                                vew++;
                        }
                }
                if(how==2 || vew==2)
                    table[i][j]=-2;
                if(hob==2 || veb==2)
                    table[i][j]--;
            }
    return;
}

int main()
{
    freopen("acsl8.txt", "r", stdin);
    for(int abc=0; abc<2; abc++)
    {
        int nw, nb;
        char w[24][3], b[24][3];
        memset(w, 0, 24*3);
        memset(b, 0, 24*3);
        scanf("%d", &nb);
        for(int i=0; i<nb; i++)
            scanf(", %c%c", &b[i][0], &b[i][1]);
        scanf("\n");
        scanf("%d", &nw);
        for(int i=0; i<nw; i++)
            scanf(", %c%c", &w[i][0], &w[i][1]);
        scanf("\n");
        int table[7][7];
        generateTable(table);
        fillTable(table, nw, nb, w, b);
        for(int ab=0; ab<5; ab++)
        {
            char ln[3];
            memset(ln, 0, 3);
            scanf("%s\n", &ln);
            char c1[3], c2[3], c3[3];
            memset(c1, 0, 3);
            memset(c2, 0, 3);
            memset(c3, 0, 3);
            int side=table[ln[1]-'1'][ln[0]-'a'];
            int copie[7][7];
            for(int i=0; i<7; i++)
                for(int j=0; j<7; j++)
                    copie[i][j]=table[i][j];
            table[ln[1]-'1'][ln[0]-'a']=-4;
            possibleCombinations(table);
            for(int i=0; i<7; i++)
                for(int j=0; j<7; j++)
                {
                    if(table[i][j]==0 && c3[0]==0)
                        c3[0]=j+'a', c3[1]=i+'1';
                    if(side==1)
                    {
                        if(table[i][j]==-1 && c1[0]==0)
                            c1[0]=j+'a', c1[1]=i+'1';
                        else if(table[i][j]==-2 && c2[0]==0)
                            c2[0]=j+'a', c2[1]=i+'1';
                        else if(table[i][j]==-3)
                        {
                            if(c1[0]==0)
                                c1[0]=j+'a', c1[1]=i+'1';
                            else if(c2[0]==0)
                                c2[0]=j+'a', c2[1]=i+'1';
                        }
                    }
                    else if(side==2)
                    {
                        if(table[i][j]==-2 && c1[0]==0)
                            c1[0]=j+'a', c1[1]=i+'1';
                        else if(table[i][j]==-1 && c2[0]==0)
                            c2[0]=j+'a', c2[1]=i+'1';
                        else if(table[i][j]==-3)
                        {
                            if(c1[0]==0)
                                c1[0]=j+'a', c1[1]=i+'1';
                            else if(c2[0]==0)
                                c2[0]=j+'a', c2[1]=i+'1';
                        }
                    }
                }
            if(c1[0]!=0)
                cout<<c1<<endl;
            else if(c2[0]!=0)
                cout<<c2<<endl;
            else
                cout<<c3<<endl;
            for(int i=0; i<7; i++)
                for(int j=0; j<7; j++)
                    table[i][j]=copie[i][j];
        }
    }
    return 0;
}
