#include <iostream>
#include <fstream>

using namespace std;

char cod[10];
void elimina_spatii(string &str)
{
    string nou="";
    for(int i=0; i<str.length(); i++)
        if(str[i] != ' ')
            nou+=str[i];
    str=nou;
}
void adauga_si_conv(int cifra, int i)
{
    switch(cifra)
    {
    case 0:
        cod[i]='-';
        cod[i+1]='-';
        cod[i+2]='-';
        break;
    case 1:
        cod[i]='-';
        cod[i+1]='-';
        cod[i+2]='x';
        break;
    case 2:
        cod[i]='-';
        cod[i+1]='w'; 
        cod[i+2]='-';
        break;
    case 3:
        cod[i]='-';
        cod[i+1]='w';
        cod[i+2]='x';
        break;
    case 4:
        cod[i]='r';
        cod[i+1]='-';
        cod[i+2]='-';
        break;
    case 5:
        cod[i]='r';
        cod[i+1]='-';
        cod[i+2]='x';
        break;
    case 6:
        cod[i]='r';
        cod[i+1]='w';
        cod[i+2]='-';
        break;
    case 7:
        cod[i]='r';
        cod[i+1]='w';
        cod[i+2]='x';
        break;
    }
}

void genereaza_initial(int n)
{
    for(int i=6; i>=0; i-=3)
    {
        cout<<n%10<<endl;
        adauga_si_conv(n%10,i);
        n/=10;
    }
}
void rezolva(string op, char operatie, int poz_operatie)
{
    if(operatie=='+')
    {
        for(int i=0; i<poz_operatie; i++)
        {
            if(op[i]=='a')
            {
                for(int j=poz_operatie+1; j<op.length(); j++)
                {
                    if(op[j]=='x')
                    {
                        cod[2]='x';
                        cod[5]='x';
                        cod[8]='x';
                    }
                    else if(op[j]=='r')
                    {
                        cod[0]='r';
                        cod[3]='r';
                        cod[6]='r';
                    }
                    else if(op[j]=='w')
                    {
                        cod[1]='w';
                        cod[4]='w';
                        cod[7]='w';
                    }
                }
            }
            if(op[i]=='u')
            {
                for(int j=poz_operatie+1; j<op.length(); j++)
                {
                    if(op[j]=='x')
                    {
                        cod[2]='x';
                    }
                    else if(op[j]=='r')
                    {
                        cod[0]='r';

                    }
                    else if(op[j]=='w')
                    {
                        cod[1]='w';

                    }
                }
            }
            if(op[i]=='g')
            {
                for(int j=poz_operatie+1; j<op.length(); j++)
                {
                    if(op[j]=='x')
                    {
                        cod[5]='x';
                    }
                    else if(op[j]=='r')
                    {
                        cod[3]='r';
                    }
                    else if(op[j]=='w')
                    {
                        cod[4]='w';
                    }
                }
            }
            if(op[i]=='o')
            {
                for(int j=poz_operatie+1; j<op.length(); j++)
                {
                    if(op[j]=='x')
                    {

                        cod[8]='x';
                    }
                    else if(op[j]=='r')
                    {

                        cod[6]='r';
                    }
                    else if(op[j]=='w')
                    {
                        cod[7]='w';
                    }
                }
            }
        }
    }
}
void procesare_modificare(string linie)
{
    elimina_spatii(linie);
    string op="";
    char operatie;
    int poz_operatie=0;
    for(int i=0; i<linie.length(); i++)
    {
        if(linie[i]==',')
        {
            rezolva(op,operatie,poz_operatie);
            cout<<op<<endl;
            op="";
        }
        else
        {
            if(linie[i]=='=' || linie[i]=='+' || linie[i]=='-')
                operatie=linie[i],poz_operatie=i;
            op+=linie[i];
        }
    }
    rezolva(op,operatie,poz_operatie);
    cout<<op<<endl;
}

int main()
{
    ifstream f("date.in");

    string linie="";
    int n;
    f>>n;
    f>>linie>>linie;
    genereaza_initial(n);    procesare_modificare(linie);
    for(int i=0; i<9; i++)
        cout<<cod[i];
    cout<<endl;

    return 0;
}
