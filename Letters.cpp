#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ifstream f("acsl5.txt");
    for(int abc=0; abc<2; abc++)
    {
        int fr[26];
        for(int i=0; i<26; i++)
            fr[i]=0;
        char s[100];
        memset(s, 0, 100);
        f.getline(s, 99);
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i]>='a' && s[i]<='z')
                s[i]-='a'-'A';
            if(s[i]>='A' && s[i]<='Z')
                fr[s[i]-'A']++;
        }
        int maxim=-1; char maxima;
        for(int i=0; i<26; i++)
            if(fr[i]>maxim)
                maxim=fr[i], maxima=i+'A';
        cout<<maxima<<' '<<maxim<<endl;
        for(int i=0; i<26; i++)
            fr[i]=0;
        bool lit[26];
        for(int i=0; i<26; i++)
            lit[i]=1;
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                if(lit[s[i]-'A']==1)
                    fr[s[i]-'A']++, lit[s[i]-'A']=0;
            if(i<strlen(s)-1)
                if(!(s[i]>='A' && s[i]<='Z') && (s[i+1]>='A' && s[i+1]<='Z'))
                    for(int j=0; j<26; j++)
                        lit[j]=1;

        }
        maxim=-1;
        for(int i=0; i<26; i++)
            if(fr[i]>maxim)
                maxim=fr[i], maxima=i+'A';
        cout<<maxima<<' '<<maxim<<endl;
        for(int i=25; i>=0; i--)
            if(fr[i]!=0)
                cout<<(char)(i+'A');
        cout<<endl;
        bool fr2[26];
        for(int i=0; i<26; i++)
            lit[i]=1, fr2[i]=0, fr[i]=0;
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                fr[s[i]-'A']++;
            if(lit[s[i]-'A']==1 && fr2[s[i]-'A']==0)
                fr2[s[i]-'A']=1;
            else if(lit[s[i]-'A']==1 && fr2[s[i]-'A']==1)
                lit[s[i]-'A']=0;
            if(i<strlen(s)-1)
            {
                if(!(s[i]>='A' && s[i]<='Z') && (s[i+1]>='A' && s[i+1]<='Z'))
                {
                    for(int j=0; j<26; j++)
                        if(lit[j]==1 && fr2[j]==1)
                            fr2[j]=0;
                }
            }
        }
        for(int i=0; i<26; i++)
            if(lit[i]==0 && fr2[i]==1)
                cout<<(char)(i+'A');
        cout<<endl;
        maxim=-1;
        for(int i=0; i<26; i++)
            if(fr[i]>maxim)
                maxim=fr[i];
        for(int i=maxim; i>1; i--)
        {
            for(int j=0; j<26; j++)
                if(fr[j]==i)
                    cout<<(char)(j+'A');
        }
        cout<<endl;
    }
    return 0;
}
