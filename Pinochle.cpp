#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("data.in", "r", stdin);
    for(int abc=0; abc<5; abc++)
    {
        char trumpc, d[12]="", c[12]="", s[12]="", h[12]="", *trump, trumpl=0;
        scanf("%c, %s %s %s %s\n", &trumpc, &d, &c, &s, &h);
        d[strlen(d)-1]=c[strlen(c)-1]=s[strlen(s)-1]=0;
        switch(trumpc)
        {
            case 'D': {trump=d; trumpl=strlen(d); break;}
            case 'C': {trump=c; trumpl=strlen(c); break;}
            case 'S': {trump=s; trumpl=strlen(s); break;}
            case 'H': {trump=h; trumpl=strlen(h); break;}
        }
        int ld=strlen(d), lc=strlen(c), ls=strlen(s), lh=strlen(h);
        for(int i=0; i<ld; i++)
        {
            switch(d[i])
            {
                case 'A': {d[i]=6; break;}
                case 'K': {d[i]=5; break;}
                case 'Q': {d[i]=4; break;}
                case 'J': {d[i]=3; break;}
                case 'T': {d[i]=2; break;}
                case 'N': {d[i]=1; break;}
            }
        }
        for(int i=0; i<lc; i++)
        {
            switch(c[i])
            {
                case 'A': {c[i]=6; break;}
                case 'K': {c[i]=5; break;}
                case 'Q': {c[i]=4; break;}
                case 'J': {c[i]=3; break;}
                case 'T': {c[i]=2; break;}
                case 'N': {c[i]=1; break;}
            }
        }
        for(int i=0; i<ls; i++)
        {
            switch(s[i])
            {
                case 'A': {s[i]=6; break;}
                case 'K': {s[i]=5; break;}
                case 'Q': {s[i]=4; break;}
                case 'J': {s[i]=3; break;}
                case 'T': {s[i]=2; break;}
                case 'N': {s[i]=1; break;}
            }
        }
        for(int i=0; i<lh; i++)
        {
            switch(h[i])
            {
                case 'A': {h[i]=6; break;}
                case 'K': {h[i]=5; break;}
                case 'Q': {h[i]=4; break;}
                case 'J': {h[i]=3; break;}
                case 'T': {h[i]=2; break;}
                case 'N': {h[i]=1; break;}
            }
        }
        sort(d, d+ld);
        sort(c, c+lc);
        sort(s, s+ls);
        sort(h, h+lh);
        int score=0;
        if(true)
        {
            int check[6]={0, 0, 0, 0, 0, 0}, c=2;
            for(int i=0; i<trumpl; i++)
                check[*(trump+i)-1]++;
            for(int i=0; i<6; i++)
                if(check[i]==0)
                {
                    c=0;
                    break;
                }
                else if(check[i]==1)
                    c=1;
            if(c==1)
                score+=15;
            else if(c==2)
                score+=180;
            if((c==1 && check[3]==2 && check[4]==2) || (c==0 && check[3]>0 && check[4]>0))
                score+=4;
        }
        if(true)
        {
            int jod=0, qos=0;
            for(int i=0; i<ld; i++)
                if(d[i]==3)
                    jod++;
            for(int i=0; i<ls; i++)
                if(s[i]==4)
                    qos++;
            if(jod==qos && jod==2)
                score+=38;
            else if(jod>0 && qos>0)
                score+=4;
        }
        if(true)
        {
            bool faces=true, eaces=true, fjacks=true, ejacks=true, fkings=true, ekings=true, fqueens=true, equeens=true;
            for(int i=0, j=0, a=0, k=0, q=0; i<ld; i++)
            {
                switch(d[i])
                {
                    case 3: {j++; break;}
                    case 4: {q++; break;}
                    case 5: {k++; break;}
                    case 6: {a++; break;}
                }
                if(i==ld-1)
                {
                    if(faces && a<1)
                        faces=false;
                    if(fjacks && j<1)
                        fjacks=false;
                    if(fqueens && q<1)
                        fqueens=false;
                    if(fkings && k<1)
                        fkings=false;
                    if(eaces && a<2)
                        eaces=false;
                    if(ejacks && j<2)
                        ejacks=false;
                    if(equeens && q<2)
                        equeens=false;
                    if(ekings && k<2)
                        ekings=false;
                }
            }
            for(int i=0, j=0, a=0, k=0, q=0; i<lc; i++)
            {
                switch(c[i])
                {
                    case 3: {j++; break;}
                    case 4: {q++; break;}
                    case 5: {k++; break;}
                    case 6: {a++; break;}
                }
                if(i==lc-1)
                {
                    if(faces && a<1)
                        faces=false;
                    if(fjacks && j<1)
                        fjacks=false;
                    if(fqueens && q<1)
                        fqueens=false;
                    if(fkings && k<1)
                        fkings=false;
                    if(eaces && a<2)
                        eaces=false;
                    if(ejacks && j<2)
                        ejacks=false;
                    if(equeens && q<2)
                        equeens=false;
                    if(ekings && k<2)
                        ekings=false;
                }
            }
            for(int i=0, j=0, a=0, k=0, q=0; i<ls; i++)
            {
                switch(s[i])
                {
                    case 3: {j++; break;}
                    case 4: {q++; break;}
                    case 5: {k++; break;}
                    case 6: {a++; break;}
                }
                if(i==ls-1)
                {
                    if(faces && a<1)
                        faces=false;
                    if(fjacks && j<1)
                        fjacks=false;
                    if(fqueens && q<1)
                        fqueens=false;
                    if(fkings && k<1)
                        fkings=false;
                    if(eaces && a<2)
                        eaces=false;
                    if(ejacks && j<2)
                        ejacks=false;
                    if(equeens && q<2)
                        equeens=false;
                    if(ekings && k<2)
                        ekings=false;
                }
            }
            for(int i=0, j=0, a=0, k=0, q=0; i<lh; i++)
            {
                switch(h[i])
                {
                    case 3: {j++; break;}
                    case 4: {q++; break;}
                    case 5: {k++; break;}
                    case 6: {a++; break;}
                }
                if(i==lh-1)
                {
                    if(faces && a<1)
                        faces=false;
                    if(fjacks && j<1)
                        fjacks=false;
                    if(fqueens && q<1)
                        fqueens=false;
                    if(fkings && k<1)
                        fkings=false;
                    if(eaces && a<2)
                        eaces=false;
                    if(ejacks && j<2)
                        ejacks=false;
                    if(equeens && q<2)
                        equeens=false;
                    if(ekings && k<2)
                        ekings=false;
                }
            }
            if(faces)
                score+=10;
            if(eaces)
                score+=110;
            if(fjacks)
                score+=4;
            if(ejacks)
                score+=44;
            if(fqueens)
                score+=6;
            if(equeens)
                score+=66;
            if(fkings)
                score+=8;
            if(ekings)
                score+=88;
        }
        for(int i=0, k=0, q=0; i<ld && trump != d; i++)
        {
            if(d[i]==5)
                k++;
            else if(d[i]==4)
                q++;
            if(k>0 && q>0 && i==ld-1)
                score+=2;
            if(k>1 && q>1 && i==ld-1)
                score+=2;
        }
        for(int i=0, k=0, q=0; i<lc && trump != c; i++)
        {
            if(c[i]==5)
                k++;
            else if(c[i]==4)
                q++;
            if(k>0 && q>0 && i==lc-1)
                score+=2;
            if(k>1 && q>1 && i==lc-1)
                score+=2;
        }
        for(int i=0, k=0, q=0; i<ls && trump != s; i++)
        {
            if(s[i]==5)
                k++;
            else if(s[i]==4)
                q++;
            if(k>0 && q>0 && i==ls-1)
                score+=2;
            if(k>1 && q>1 && i==ls-1)
                score+=2;
        }
        for(int i=0, k=0, q=0; i<lh && trump != h; i++)
        {
            if(h[i]==5)
                k++;
            else if(h[i]==4)
                q++;
            if(k>0 && q>0 && i==lh-1)
                score+=2;
            if(k>1 && q>1 && i==lh-1)
                score+=2;
        }
        cout<<score<<endl;
    }
    return 0;
}
