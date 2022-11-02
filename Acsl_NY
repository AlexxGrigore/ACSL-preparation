#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void delpoz(int poz, char s[], int l)
{
    for(int i=poz; i<l; i++)
        swap(s[i], s[i+1]);
    s[l-1]=0;
    return;
}

void step1(char s[])
{
    if((s[0]=='A' && s[1]=='E') || (s[0]=='G' && s[1]=='N') || (s[0]=='K' && s[1]=='N') || (s[0]=='P' && s[1]=='N') || (s[0]=='W' && s[1]=='R'))
        delpoz(0, s, strlen(s));
    else if(s[0]=='X')
        s[0]='S';
    else if(s[0]=='W' && s[1]=='H')
        delpoz(1, s, strlen(s));
    return;
}

void step2(char s[])
{
    char v[]="AEIOU";
    int l=strlen(s);
    TOP:
    if(s[l-1]=='B')
        if(s[l-2]=='M')
        {
            delpoz(l-1, s, l);
            l--;
            goto TOP;
        }
    for(int i=1; i<l-1; i++)
        if(s[i-1] == 'S' && s[i]== 'C' && (s[i+1]== 'Y' || s[i+1]=='I'))
        {
            delpoz(i, s, l);
            l--;
            goto TOP;
        }
    for(int i=0; i<l-1; i++)
        if(s[i]=='C' && strchr("HIEY", s[i+1])!=0)
        {
            s[i]='X';
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='C')
        {
            s[i]='K';
            goto TOP;
        }
    for(int i=0; i<l-1; i++)
        if(s[i]=='D' && s[i+1]=='G')
        {
            s[i]='J';
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='D')
        {
            s[i]='T';
            goto TOP;
        }
    for(int i=1; i<l-1; i++)
        if(strchr(v, s[i-1])!=0 && strchr(v, s[i+1])==0 && s[i]=='G')
        {
            delpoz(i, s, l);
            l--;
            goto TOP;
        }
    if(s[0]=='G' && strchr("IEY", s[1])!=0)
    {
        s[0]='J';
        goto TOP;
    }
    for(int i=1; i<l-1; i++)
        if(s[i-1]!='G' && s[i]=='G' && strchr("IEY", s[i+1])!=0)
        {
            s[i]='J';
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='G')
        {
            s[i]='K';
            goto TOP;
        }
    for(int i=1; i<l-1; i++)
        if(((strchr(v, s[i-1])!=0 && strchr(v, s[i+1])==0) || strchr("CSTPG", s[i-1])) && s[i]=='H')
        {
            delpoz(i, s, l);
            l--;
            goto TOP;
        }
    for(int i=0; i<l-1; i++)
        if(s[i]=='P' && s[i+1]=='H')
        {
            s[i]='F';
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='Q')
        {
            s[i]='K';
            goto TOP;
        }
    for(int i=0; i<l-1; i++)
        if(s[i]=='S' && (s[i+1]=='H' || (s[i+1]=='I' && (s[i+2]=='O' || s[i+2]=='A'))))
        {
            s[i]='X';
            goto TOP;
        }
    for(int i=0; i<l-2; i++)
        if(s[i]=='T' && s[i+1]=='I' && (s[i+2]=='O' || s[i+2]=='A'))
        {
            s[i]='X';
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='V')
        {
            s[i]='F';
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='W' && (strchr(v, s[i+1])==0 || s[i+1]==0))
        {
            delpoz(i, s, l);
            l--;
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='Y' && (strchr(v, s[i+1])==0 || s[i+1]==0))
        {
            delpoz(i, s, l);
            l--;
            goto TOP;
        }
    for(int i=0; i<l; i++)
        if(s[i]=='Z')
        {
            s[i]='S';
            goto TOP;
        }
    for(int i=0; i<l-1; i++)
        if(s[i]==s[i+1])
        {
            delpoz(i, s, l);
            l--;
            goto TOP;
        }
    return;
}

void step3(char s[])
{
    char v[]="AEIOU";
    int l=strlen(s);
    for(int i=0; i<l; i++)
        if(strchr(v, s[i])!=0)
        {
            delpoz(i, s, l);
            l--, i--;
        }
    return;
}

int main()
{
    ifstream f("data.in");
    for(int i=0; i<5; i++)
    {
        char s[100]="";
        f.getline(s, 99);
        step1(s);
        step2(s);
        step3(s);
        cout<<s<<endl;
    }
    return 0;
}
