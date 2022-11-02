#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("data.in");
    for(int abc=0; abc<5; abc++)
    {
        char s[1000]="";
        f.getline(s, 999);
        char spl[100][100];
        char *split;
        int splcnt=0, len=strlen(s);
        int delim[12]={0}; char del[12]="";
        for(int i=0; i<len; i++)
            if(strchr(".,-_;:()!?`'", s[i])!=NULL)
                for(int j=0; j<12; j++)
                    if(del[j]==s[i])
                    {
                        delim[j]++;
                        break;
                    }
                    else if(del[j]==0)
                    {
                        del[j]=s[i];
                        delim[j]++;
                        break;
                    }
        split = strtok(s, ".,-_ ;:()!?`'");
        while(split != NULL)
        {
            strcpy(spl[splcnt], split);
            splcnt++;
            split = strtok(NULL, ".,-_ ;:()!?`'");
        }
        int wordcnt[100]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int i=0; i<splcnt; i++)
            if(wordcnt[i]>0)
                for(int j=i+1; j<splcnt; j++)
                    if(strcmp(spl[i], spl[j])==0)
                        wordcnt[i]++, wordcnt[j]=0;
        for(int i=0; i<splcnt; i++)
            if(wordcnt[i]>0)
                cout<<wordcnt[i]<<spl[i];
        for(int i=0; i<12; i++)
        {
            if(del[i]==0)
                break;
            cout<<delim[i]<<del[i];
        }
        cout<<endl;
    }
    return 0;
}
