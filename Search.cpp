#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char strings[10][100];

struct range{char low=0, high=0;};

void digRangRepl(char str[], range rng[], int &nrr)
{
    int l=strlen(str);
    if(l<5)
        return;
    for(int i=0; i<l-4; i++)
        if(str[i]=='[' && isdigit(str[i+1]) && str[i+2]=='-' && isdigit(str[i+3]) && str[i+4]==']')
        {
            str[i]='^';
            rng[nrr].low=str[i+1];
            rng[nrr++].high=str[i+3];
            for(int j=i+1; j<l; j++)
                str[j]=str[j+4];
            l-=4;
        }
    return;
}

bool match(char str1[], char str2[], range rng[])
{
    int l=strlen(str2), nrr=0;
    for(int i=0; i<l; i++)
        if(str2[i]=='?')
            continue;
        else if(str2[i]=='^')
        {
            if(str1[i]>rng[nrr].high || str1[i]<rng[nrr].low)
                return false;
            nrr++;
        }
        else if(str2[i]!=str1[i])
            return false;
    return true;
}

void searchSufix(char str[], bool rez[], range rng[])
{
    int l2=strlen(str);
    for(int i=0; i<10; i++)
    {
        rez[i]=0;
        int l1=strlen(strings[i]);
        if(l2>l1)
            continue;
        rez[i]=match(strings[i]+l1-l2, str, rng);
    }
    return;
}

void searchPrefix(char str[], bool rez[], range rng[])
{
    int l2=strlen(str)-1;
    str[l2]=0;
    for(int i=0; i<10; i++)
    {
        rez[i]=0;
        int l1=strlen(strings[i]);
        if(l2>l1)
            continue;
        rez[i]=match(strings[i], str, rng);
    }
    return;
}

void searchInside(char str[], bool rez[], range rng[])
{
    int l2=strlen(str)-1;
    str[l2]=0;
    for(int i=0; i<10; i++)
    {
        rez[i]=0;
        int l1=strlen(strings[i]);
        if(l2>l1)
            continue;
        for(int j=0; j<l1-l2+1; j++)
            if(match(strings[i]+j, str, rng))
            {
                rez[i]=1;
                break;
            }
    }
    return;
}

int main()
{
    fstream f("data.in");
    for(int i=0; i<9; i++)
    {
        f.getline(strings[i], 100, ' ');
        strings[i][strlen(strings[i])-1]=0;
    }
    f.getline(strings[9], 100);
    for(int abc=0; abc<5; abc++)
    {
        char str[100]="";
        f.getline(str, 100);
        range rng[25];
        int nrr=0;
        digRangRepl(str, rng, nrr);
        int l=strlen(str);
        bool rez[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        if(str[0]=='*' && str[l-1]!='*')
            searchSufix(str+1, rez, rng);
        else if(str[0]!='*' && str[l-1]=='*')
            searchPrefix(str, rez, rng);
        else if(str[0]=='*' && str[l-1]=='*')
            searchInside(str+1, rez, rng);
        else
        {
            str[l]='*';
            str[l+1]=0;
            searchInside(str, rez, rng);
        }
        int i;
        for(i=0; i<10; i++)
            if(rez[i])
            {
                cout<<strings[i];
                break;
            }
        for(i++; i<10; i++)
            if(rez[i])
                cout<<", "<<strings[i];
        cout<<endl;
    }
    return 0;
}
