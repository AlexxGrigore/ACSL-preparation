#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("acsl8.txt");
    for(int abc=0; abc<10; abc++)
    {
        char str[100];
        short len=10, dec=0;
        memset(str, 0, 100);
        float flt;
        f.get(str, 100, '\n'); f.get();
        bool ln=0;
        int poz=0;
        for(int i=0; i<strlen(str); i++)
        {
            if(ln==0 && str[i]==',')
            {
                ln=1; len=0; poz=i;
                for(int j=i+1; j<strlen(str) && str[j]!=','; j++)
                    if(str[j]>='0' && str[j]<='9')
                        len=len*10+str[j]-'0';
            }
            else if(str[i]==',')
            {
                dec=0;
                for(int j=i+1; j<strlen(str) || str[j]=='\n'; j++)
                    if(str[j]>='0' && str[j]<='9')
                        dec=dec*10+str[j]-'0';
            }
        }
        if(poz!=0)
            for(int i=poz; i<strlen(str); i++)
                str[i]=0;
        flt=atof(str);
        memset(str, 0, 100);
        bool neg=0;
        if(flt<0)
            flt*=-1, neg=1;
        int p=1; len--;
        for(int i=0; i<=dec; i++, p*=10);
        if(dec>=len)
        {
            cout<<"ERROR"<<endl;
            continue;
        }
        int zec=(int)(flt*p)%p;
        if(zec>10 && zec%10>=5)
        {
            if(zec/10==9)
                flt++;
            zec/=10, zec++;
        }
        else if(zec%10>=5)
            zec/=10, flt++; 
        else
            zec/=10;
        if(dec>0)
        {
                for(; dec; zec/=10, dec--)
                    str[len--]=zec%10+'0';
            str[len--]='.';
        }
        int nr=flt;
        for(; nr && len>=0; nr/=10)
        {
            str[len--]=nr%10+'0';
        }
        if(neg)
            str[len--]='-';
        for(; len>=0; len--)
            str[len]='#';
        if(nr)
        {
            for(int i=0; i<strlen(str); i++)
                if(str[i]>='0' && str[i]<='9')
                    str[i]='#';
        }
        cout<<str<<endl;

    }
    return 0;
}
