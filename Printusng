#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("date.in");

int l_str=0,l_val=0;
char str[1000],val[1000];

bool are_chr(char caracter)
{
    for(int i=0; i<l_str; i++)
    {
        if(str[i]==caracter)
            return true;
    }
    return false;
}
void calc_l_zec_int(int &str_l_int, int &str_l_zec, int &val_l_int, int &val_l_zec)
{
    int i=0;

    ///str
    for(i=0; i<l_str && str[i]!='.'; i++)
    {
        if(str[i]=='&')
            str_l_int++;
    }
    i++;
    for(;i<l_str; i++)
    {
        if(str[i]=='&')
            str_l_zec++;
    }

    ///val
    for(i=0; i<l_val; i++)
    {
        if(val[i]!='.')
            val_l_int++;
        else
            break;
    }
    i++;
    for(;i<l_val; i++)
    {
        if(val[i]!='.')
            val_l_zec++;
    }
}

void calc_val_zec_int(int &val_int, int &val_zec, int str_l_zec)
{
    int i;
    for(i=0; i<l_val && val[i]!='.'; i++)
        val_int=val_int*10+val[i]-'0';
    i++;
    for(int j=0;i<l_val&&j<str_l_zec+1; i++,j++)
        val_zec=val_zec*10+val[i]-'0';
}
void rezolvare()
{
    if(are_chr(','))
    {
        for(int i=0; i<l_str-1-l_val; i++)
            cout<<"*";
        for(int i=0; i<l_str-1; i++)
        {
            cout<<val[i];
            if((i+1)%3==0 && i+2<l_str)
                cout<<",";
        }
        cout<<endl;
        return;
    }

    if(are_chr('.'))
    {
        int str_l_int=0,str_l_zec=0,val_l_int=0,val_l_zec=0;
        calc_l_zec_int(str_l_int,str_l_zec,val_l_int,val_l_zec);
        if(are_chr('$'))
        {
            if(are_chr('*'))
            {
                for(int i=0; i<str_l_int-val_l_int; i++)
                    cout<<"*";
            }
            cout<<'$';
        }
        else
        {
            for(int i=0; i<str_l_int-val_l_int; i++)
                cout<<"*";
        }


        for(int i=0; i<str_l_int; i++)
            cout<<val[i];
        if(str_l_zec>=val_l_zec)
        {
            int i;
            for(i=0; i<val_l_zec; i++)
                cout<<val[val_l_int+1+i];
            for(;i<str_l_zec; i++)
                cout<<"0";
        }
        else
        {
            int val_zec=0,val_int=0;
            calc_val_zec_int(val_int,val_zec, str_l_zec);
            if(val_zec%10>=5)
            {
                val_zec/=10;
                val_zec++;
            }
            else
                val_zec/=10;
            cout<<val_zec;
        }
        cout<<endl;
        return;
    }

    if(are_chr('E'))
    {
        int nr=0;
        for(int i=0; i<l_str; i++)
            if(str[i]=='&')
                nr++;
        cout<<val[0]<<".";
        for(int i=1; i<nr; i++)
            cout<<val[i];
        cout<<"E"<<nr;
        cout<<endl;
        return;
    }
    for(int i=0; i<l_str-l_val; i++)
        cout<<"*";
    cout<<val<<endl;
}

int main()
{
    for(int i=0; i<5; i++)
    {
        f>>str>>val;
        l_str=strlen(str)-1;
        l_val=strlen(val);
        rezolvare();
    }

    return 0;
}
