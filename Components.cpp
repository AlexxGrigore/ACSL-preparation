#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void genTable(bool table[][1000], char str[], short vertices)
{
    bool bits[1000];
    short len=0;
    for(int i=0; i<1000; i++)
        bits[i]=0;
    for(int i=0; i<strlen(str); i++)
    {
        switch(str[i])
        {
            case '0':{ bits[len++]=0; bits[len++]=0; bits[len++]=0; bits[len++]=0; break;}
            case '1':{ bits[len++]=0; bits[len++]=0; bits[len++]=0; bits[len++]=1; break;}
            case '2':{ bits[len++]=0; bits[len++]=0; bits[len++]=1; bits[len++]=0; break;}
            case '3':{ bits[len++]=0; bits[len++]=0; bits[len++]=1; bits[len++]=1; break;}
            case '4':{ bits[len++]=0; bits[len++]=1; bits[len++]=0; bits[len++]=0; break;}
            case '5':{ bits[len++]=0; bits[len++]=1; bits[len++]=0; bits[len++]=1; break;}
            case '6':{ bits[len++]=0; bits[len++]=1; bits[len++]=1; bits[len++]=0; break;}
            case '7':{ bits[len++]=0; bits[len++]=1; bits[len++]=1; bits[len++]=1; break;}
            case '8':{ bits[len++]=1; bits[len++]=0; bits[len++]=0; bits[len++]=0; break;}
            case '9':{ bits[len++]=1; bits[len++]=0; bits[len++]=0; bits[len++]=1; break;}
            case 'A':{ bits[len++]=1; bits[len++]=0; bits[len++]=1; bits[len++]=0; break;}
            case 'B':{ bits[len++]=1; bits[len++]=0; bits[len++]=1; bits[len++]=1; break;}
            case 'C':{ bits[len++]=1; bits[len++]=1; bits[len++]=0; bits[len++]=0; break;}
            case 'D':{ bits[len++]=1; bits[len++]=1; bits[len++]=0; bits[len++]=1; break;}
            case 'E':{ bits[len++]=1; bits[len++]=1; bits[len++]=1; bits[len++]=1; break;}
            case 'F':{ bits[len++]=1; bits[len++]=1; bits[len++]=1; bits[len++]=1; break;}
        }
    }
    short current=0;
    for(int i=0; i<vertices; i++)
        table[i][i]=1;
    for(int i=0; i<len && vertices >=0; i++, vertices--, current++)
    {
        int j;
        for(j=0; j<vertices-1; j++)
        {
            if(bits[i+j])
                table[current][current+j+1]=1, table[current+j+1][current]=1;
        }
        i+=j-1;
    }
    return;
}

void modTable(bool table[][1000], short vertices)
{
    for(int i=0; i<vertices; i++)
        for(int j=0; j<vertices; j++)
        {
            if(table[i][j])
            {
                for(int k=0; k<vertices; k++)
                {
                    if(table[j][k])
                        table[i][k]=1, table[k][j]=1;
                }
            }
        }
    return;
}

void disEqual(bool table[][1000], int vertices, bool enabled[])
{
    for(int i=0; i<vertices; i++)
    {
        if(enabled[i])
        {
            for(int j=i+1; j<vertices; j++)
            {
                bool egal=1;
                for(int k=0; k<vertices && egal==1; k++)
                    if(table[i][k]!=table[j][k])
                        egal=0;
                if(egal)
                    enabled[j]=0;
            }
        }
    }
    return;
}

int main()
{
    freopen("acsl4.txt", "r", stdin);
    for(int abc=0; abc<10; abc++)
    {
        bool adiac[1000][1000];
        for(int i=0; i<1000; i++)
            for(int j=0; j<1000; j++)
                adiac[i][j]=0;
        int nodes=0;
        char conect[1000];
        memset(conect, 0, 1000);
        scanf("%d, %s", &nodes, &conect);
        genTable(adiac, conect, nodes);
        modTable(adiac, nodes);
        bool enabled[1000];
        short nr=0;
        for(int i=0; i<nodes; i++)
            enabled[i]=1;
        disEqual(adiac, nodes, enabled);
        for(int i=0; i<nodes; i++)
            if(enabled[i])
                nr++;
        cout<<nr<<' ';
        for(int i=0; i<nodes; i++)
            if(adiac[0][i]==1)
            {
                char output;
                output='A'+i;
                cout<<output;
            }
        cout<<endl;
    }
    return 0;
}
