#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("date.in");

char linie[1000], op_initiala[100];
int nr_subliste=0;

struct sublista
{
    char operatie[10];
    int l_operatie=0;
    int nr_elemente;
    int elemente[20];
}subliste[20];

void generare_date()
{
    int i=1;
    for(int j=0; i<strlen(linie); i++)
    {
        if(linie[i]=='(')
            break;
        op_initiala[j++]=linie[i];
    }
    for(; i<strlen(linie);nr_subliste++)
    {
        i++;
       // cout<<"operatie: "<<i<<endl;
        while(linie[i]>='A' && linie[i]<='Z')
        {
            subliste[nr_subliste].operatie[subliste[nr_subliste].l_operatie++]=linie[i];
            i++;
        }

        i++;
       // cout<<"numar:"<<i<<endl;
        while(linie[i]!=')'&&i<strlen(linie))
        {

            bool minu=false;
            int nr=0;
            while(linie[i]>='0' && linie[i]<='9' || linie[i]=='-')
            {
          //      cout<<"         CICLU2"<<endl;
                if(linie[i]=='-')
                    minu=true;
                else
                    nr=nr*10+linie[i]-'0';
                i++;
            }
            if(minu)
                nr*=(-1);
            if(linie[i]==' ')
                i++;
            subliste[nr_subliste].elemente[subliste[nr_subliste].nr_elemente++]=nr;
        }
       // cout<<"REZULTATE:    "<<subliste[nr_subliste].elemente[0]<<" "<<subliste[nr_subliste].elemente[1]<<endl;
       // cout<<"sfarsit:"<<i<<endl;
        i+=2;

    }
}
void COUNT()
{
    cout<<nr_subliste<<endl;
}
void REMOVE()
{
    int j, k;
    f>>j>>k;
    j--,k--;
    cout<<"("<<op_initiala;
    for(int i=0; i<nr_subliste; i++)
    {
        if(i==j)
            i=k;
        else
        {
            cout<<" ("<<subliste[i].operatie<<" ";
            cout<<subliste[i].elemente[0];
            for(int j=1; j<subliste[i].nr_elemente; j++)
                cout<<" "<<subliste[i].elemente[j];
            cout<<")";
        }
    }
    cout<<")"<<endl;
}
void SORT()
{
    int j, k;
    bool a_mai_fost[1000]={ false };
    f>>j>>k;
    j--,k--;
    cout<<"("<<op_initiala;
    for(int i=0; i<nr_subliste; i++)
    {
        if(i==j)
        {
            char maxi;
            int index;
            for(int a=j; a<=k; a++)
            {
                maxi='Z', index=0;
                for(int b=j; b<=k; b++)
                {
                    if(subliste[b].operatie[0]<maxi && !a_mai_fost[subliste[b].operatie[0]-'A'])
                    {
                        maxi=subliste[a].operatie[0];
                        index=b;
                    }
                }
                a_mai_fost[subliste[index].operatie[0]-'A']=true;
                cout<<" ("<<subliste[index].operatie<<" ";
                cout<<subliste[index].elemente[0];
                for(int x=1; x<subliste[index].nr_elemente; x++)
                    cout<<" "<<subliste[index].elemente[x];
                cout<<")";
            }
            i=k;
        }
        else
        {
            cout<<" ("<<subliste[i].operatie<<" ";
            cout<<subliste[i].elemente[0];
            for(int j=1; j<subliste[i].nr_elemente; j++)
                cout<<" "<<subliste[i].elemente[j];
            cout<<")";
        }
    }
    cout<<")"<<endl;
}
void REVERSE()
{
    int j, k;
    f>>j>>k;
    j--,k--;
    cout<<"("<<op_initiala;
    for(int i=0; i<nr_subliste; i++)
    {
        if(i==j)
        {
            i=k;
            for(;i>=j; i--)
            {
                cout<<" ("<<subliste[i].operatie<<" ";
                cout<<subliste[i].elemente[0];
                for(int j=1; j<subliste[i].nr_elemente; j++)
                    cout<<" "<<subliste[i].elemente[j];
                cout<<")";
            }
            i=k;
        }
        else
        {
            cout<<" ("<<subliste[i].operatie<<" ";
            cout<<subliste[i].elemente[0];
            for(int j=1; j<subliste[i].nr_elemente; j++)
                cout<<" "<<subliste[i].elemente[j];
            cout<<")";
        }
    }
    cout<<")"<<endl;
}
void MAXIMUM()
{
    int maxi=0,aux=0;
    for(int i=0; i<nr_subliste; i++)
    {
        if(subliste[i].nr_elemente>maxi)
            maxi=subliste[i].nr_elemente,aux=i;
    }
    cout<<"("<<subliste[aux].operatie;
    for(int i=0; i<subliste[aux].nr_elemente; i++)
        cout<<" "<<subliste[aux].elemente[i];
    cout<<")"<<endl;
}

int main()
{
    f.getline(linie,999);
    nr_subliste=0;
    generare_date();
    cout<<"rezultate: "<<endl;
    for(int i=0; i<nr_subliste; i++)
    {
        cout<<subliste[i].operatie;
        for(int j=0; j<subliste[i].nr_elemente; j++)
            cout<<" "<<subliste[i].elemente[j];
        cout<<endl;
    }

    cout<<endl<<endl<<"TESTE:"<<endl;
    for(int i=0; i<5; i++)
    {
        char cerinta[100];
        f>>cerinta;
       // SORT();
        switch(cerinta[0])
        {
            case 'C':
                COUNT();
                break;
            case 'R':
                if(cerinta[2]=='M')
                    REMOVE();
                else
                    REVERSE();
                break;
            case 'S':
                SORT();
                break;
            case 'M':
                MAXIMUM();
                break;
        }
    }


    return 0;
}
