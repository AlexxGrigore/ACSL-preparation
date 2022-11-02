#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void transforma_plural(string &substantiv)
{
    int l=substantiv.length();
    if((substantiv[l-1]=='h' && (substantiv[l-2]=='c' || substantiv[l-2]=='s')) || substantiv[l-1]=='x' || substantiv[l-1]=='z')
    {
        substantiv+="es";
        return ;
    }
    if((substantiv[l-2]=='a' || substantiv[l-2]=='e' || substantiv[l-2]=='i' || substantiv[l-2]=='o' || substantiv[l-2]=='u') && substantiv[l-1]=='y')
    {
        substantiv+="s";
        return  ;
    }
    if((!(substantiv[l-2]=='a' || substantiv[l-2]=='e' || substantiv[l-2]=='i' || substantiv[l-2]=='o' || substantiv[l-2]=='u')) && substantiv[l-1]=='y')
    {
        substantiv[l-1]='i';
        substantiv+="es";
        return  ;
    }
    if(substantiv[l-1]=='f')
    {
        substantiv[l-1]='v';
        substantiv+="es";
        return;
    }
    if(substantiv[l-1]=='e' && substantiv[l-2]=='f')
    {
        substantiv[l-2]='v',substantiv[l-1]='e';
        substantiv+="s";
        return;
    }
    if((substantiv[l-2]=='a' || substantiv[l-2]=='e' || substantiv[l-2]=='i' || substantiv[l-2]=='o' || substantiv[l-2]=='u') && substantiv[l-1]=='s')
    {
        substantiv+="s";
        return  ;
    }
    if((!(substantiv[l-2]=='a' || substantiv[l-2]=='e' || substantiv[l-2]=='i' || substantiv[l-2]=='o' || substantiv[l-2]=='u')) && substantiv[l-1]=='o')
    {
        substantiv[l-1]='i';
        substantiv+="es";
        return  ;
    }
    substantiv+="s";
}

bool este_vocala(char lit)
{
    return lit=='a' || lit == 'e'|| lit == 'i'|| lit == 'o'|| lit == 'u';
}

void adauga_sufix(string &verb, string sufix)
{
    int l=verb.length();
    if(verb[l-1]=='e')
    {
        if(!este_vocala(sufix[0]))
            verb+=sufix;
        else
        {
            verb[l-1]=sufix[0];
            for(int i=1; i<sufix.length(); i++)
            {
                verb+=sufix[i];
            }
        }
        return;
    }
    if(verb[l-1]=='y')
    {
        if(sufix[0]=='i')
        {
            verb+=sufix;
        }
        else
        {
            verb[l-1]='i';
            for(int i=0; i<sufix.length(); i++)
            {
                verb+=sufix[i];
            }
        }
        return;
    }
    if(!este_vocala(verb[l-1]) && este_vocala(verb[l-2]))
    {
        if(!este_vocala(verb[l-3]))
        {
            verb+=verb[l-1];
            verb+=sufix;
        }
        else
            verb+=sufix;
        return;
    }
    verb+=sufix;
}

int main()
{
    ifstream f("date.in");
    string substantiv="";

    for(int i=0; i<5; i++)
    {
        f>>substantiv;
        transforma_plural(substantiv);
        cout<<substantiv<<endl;
    }
    string verb="", sufix="",auxiliar="";
    for(int j=0; j<5; j++)
    {
        f>>auxiliar>>sufix;

        verb="";
        for(int i=0; i<auxiliar.length()-1; i++)
            verb+=auxiliar[i];
        adauga_sufix(verb,sufix);
        cout<<verb<<endl;
    }


    return 0;
}
