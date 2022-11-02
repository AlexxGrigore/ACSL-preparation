#include <iostream>
#include <fstream>

using namespace std;

int puteri[100],nr_put=0;

void rezolva(int x, int y)
{
    int v=1;
    nr_put=0;
    for(int i=1; 2*v<=x; i++)
        v*=2;
    for(int i=v; i>=1; i/=2)
    {
        if(x>=i)
        {
            puteri[nr_put++]=i*y;
            x-=i;
        }
    }
    for(int i=0; i<nr_put; i++)
        cout<<puteri[i]<<" ";
    cout<<endl;



}

int main()
{
    ifstream f("date.in");
    for(int i=0; i<10; i++)
    {
        int x=0, y=0;
        char chr;
        f>>x>>chr>>y;
        rezolva(x,y);
    }

    return 0;
}
