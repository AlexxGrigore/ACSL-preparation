#include <iostream>
#include <stdio.h>

using namespace std;

int matr_1[1000][10000];
bool matr_2[1000][1000];
int n, m;
int vi[5] = {-1, 0, 1, 0}, vj[5] = {0, 1, 0, -1};

void VerificaVector(int i, int j)
{
    if(matr_1[i][j] != -1)
    {
        int nrMin = 0;
        for(int v = 0; v<4; v++)
        {
            if(matr_1[i+vi[v]][j+vj[v]] == -1)
            {
                nrMin++;
            }
        }
        if(nrMin == matr_1[i][j])
            matr_2[i][j] = 1;
        else
            matr_2[i][j] = 0;
    }
    return;
}

void Rezolvare()
{
    bool modif = true;
    while(modif)
    {
        modif = false;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(matr_1[i][j] != -1)
                {
                    int nrMin = 0;
                    for(int v = 0; v<4; v++)
                    {
                        if(matr_1[i+vi[v]][j+vj[v]] == -1)
                        {
                            nrMin++;
                        }
                    }
                    if(nrMin > matr_1[i][j])
                    {
                        matr_1[i][j] = -1;
                        modif = true;
                        matr_2[i][j] = 0;
                    }
                    if(nrMin == matr_1[i][j])
                        matr_2[i][j] = 1;
                    else
                        matr_2[i][j] = 0;
                }
            }
        }
    }
    modif = true;
    while(modif)
    {
        modif = false;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(matr_1[i][j] != -1)
                {
                    int nrMin = 0, nrMin2 = 0;
                    bool o = true;
                    for(int v = 0; v<4; v++)
                    {
                        if(matr_1[i+vi[v]][j+vj[v]] == -1)
                        {
                            nrMin++;
                        }
                        else
                        {
                            nrMin2++;
                        }
                        if(matr_2[i+vi[v]][j+vj[v]] == 1)
                        {
                            o = false;
                        }
                    }
                    if(nrMin < matr_1[i][j] && nrMin2 == matr_1[i][j] && o && nrMin2 != 4)
                    {
                        matr_1[i][j] = -1;
                        modif = true;
                        matr_2[i][j] = false;
                        for(int v = 0; v<4; v++)
                        {
                            VerificaVector(i+vi[v], j+vj[v]);
                        }
                    }
                    if(nrMin == matr_1[i][j])
                        matr_2[i][j] = 1;
                    else
                        matr_2[i][j] = 0;
                }
            }
        }
    }
    modif = true;
    while(modif)
    {
        modif = false;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(matr_1[i][j] != -1)
                {
                    int nrMin = 0, nrMin2 = 0;
                    bool o = true;
                    for(int v = 0; v<4; v++)
                    {
                        if(matr_1[i+vi[v]][j+vj[v]] == -1)
                        {
                            nrMin++;
                        }
                        else
                        {
                            nrMin2++;
                        }
                        if(matr_2[i+vi[v]][j+vj[v]] == 1)
                        {
                            o = false;
                        }
                    }
                    if(nrMin <= matr_1[i][j] && nrMin2 >= matr_1[i][j] && o && nrMin2 != 4)
                    {
                        matr_1[i][j] = -1;
                        modif = true;
                        matr_2[i][j] = false;
                        for(int v = 0; v<4; v++)
                        {
                            VerificaVector(i+vi[v], j+vj[v]);
                        }
                    }
                    if(nrMin == matr_1[i][j])
                        matr_2[i][j] = 1;
                    else
                        matr_2[i][j] = 0;
                }
            }
        }
    }
    int suma = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(matr_1[i][j] != -1)
            {
                suma+=matr_1[i][j];
            }
        }
    }
    printf("%d\n", suma);
}

int main()
{
    freopen("asin.txt", "r", stdin);
    for(int i = 0; i<10; i++)
    {
        scanf("%d %d ", &n, &m);
        for(int i = 1; i<=n; i++)
        {
            int nr = 0;
            scanf("%x ", &nr);
            int j = m;
            while(nr)
            {
                matr_1[i][j] = nr%10;
                nr/=10;
                j--;
            }
            while(j>=1)
            {
                matr_1[i][j] = 0;
                j--;
            }
        }
        for(int i = 0; i<=n+1; i++)
        {
            matr_1[i][0] = -1;
            matr_1[i][m+1] = -1;
        }
        for(int j = 0; j<=m+1; j++)
        {
            matr_1[0][j] = -1;
            matr_1[n+1][j] = -1;
        }

        Rezolvare();
    }
    return 0;
}
