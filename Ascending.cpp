#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

char str[1000];
int l_str=0;

void rezolva()
{
    int stg=0,dr=l_str-1,curent=0,anterior=0;
    do
    {
        anterior=curent;
        curent=0;
        while(curent<=anterior)
        {
            curent=curent*10+str[stg]-'0';
            stg++;
        }
        if(stg-1<=dr)
            g<<curent<<" ";
        else
            return;
        anterior=curent;
        curent=0;
        while(curent<=anterior)
        {
            curent=curent*10+str[dr]-'0';
            dr--;
        }
        if(stg-1<=dr)
            g<<curent<<" ";
        else
            return;
    }while(anterior<curent);
}

int main()
{
    for(int i=0; i<5; i++)
    {
        f.getline(str,999);
        l_str=strlen(str);
        rezolva();
        g<<endl;
    }

    return 0;
}
