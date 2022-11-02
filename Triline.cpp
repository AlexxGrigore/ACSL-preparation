#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct point{float x, y;};

point gasinter(point a, point b, point c, point d)
{
    float fa=(a.y-b.y)/(a.x-b.x), fb=a.y-fa*a.x, ga=(c.y-d.y)/(c.x-d.x), gb=c.y-ga*c.x;
    point r;
    r.x=(gb-fb)/(fa-ga);
    r.y=fa*r.x+fb;
    if(a.x==b.x)
    {
        r.x=a.x;
        r.y=ga*r.x+gb;
    }
    else if(c.x==d.x)
    {
        r.x=c.x;
        r.y=fa*r.x+fb;
    }
    return r;
}

float distanta(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

float area(float a, float b, float c)
{
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    freopen("acsl7.txt", "r", stdin);
    short n;
    point po[26];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf(", %f, %f", &po[i].x, &po[i].y);
    }
    scanf("\n");
    for(int abc=0; abc<10; abc++)
    {
        char tr[3], dr[2];
        scanf("%c%c%c, %c%c\n", &tr[0], &tr[1], &tr[2], &dr[0], &dr[1]);
        point A, B, C, D, E;
        A=po[tr[0]-65];
        B=po[tr[1]-65];
        C=po[tr[2]-65];
        D=po[dr[0]-65];
        E=po[dr[1]-65];
        point int1=gasinter(A, B, D, E), int3=gasinter(A, C, D, E), int2=gasinter(B, C, D, E);
        bool ab=0, bc=0, ac=0;
        if(A.x<=B.x)
        {
            if(A.y<B.y)
            {
                if(int1.x>=A.x && int1.x<=B.x && int1.y>=A.y && int1.y<=B.y)
                    ab=1;
            }
            else
                if(int1.x>=A.x && int1.x<=B.x && int1.y<=A.y && int1.y>=B.y)
                    ab=1;
        }
        if(A.x>=B.x)
        {
            if(A.y<B.y)
            {
                if(int1.x<=A.x && int1.x>=B.x && int1.y>=A.y && int1.y<=B.y)
                    ab=1;
            }
            else
                if(int1.x<=A.x && int1.x>=B.x && int1.y<=A.y && int1.y>=B.y)
                    ab=1;
        }
        if(B.x<=C.x)
        {
            if(B.y<C.y)
            {
                if(int2.x>=B.x && int2.x<=C.x && int2.y>=B.y && int2.y<=C.y)
                    bc=1;
            }
            else
                if(int2.x>=B.x && int2.x<=C.x && int2.y<=B.y && int2.y>=C.y)
                    bc=1;
        }
        if(B.x>=C.x)
        {
            if(B.y<C.y)
            {
                if(int2.x<=B.x && int2.x>=C.x && int2.y>=B.y && int2.y<=C.y)
                    bc=1;
            }
            else
                if(int2.x<=B.x && int2.x>=C.x && int2.y<=B.y && int2.y>=C.y)
                    bc=1;
        }
        if(A.x<=C.x)
        {
            if(A.y<C.y)
            {
                if(int3.x>=A.x && int3.x<=C.x && int3.y>=A.y && int3.y<=C.y)
                    ac=1;
            }
            else
                if(int3.x>=A.x && int3.x<=C.x && int3.y<=A.y && int3.y>=C.y)
                    ac=1;
        }
        if(A.x>=C.x)
        {
            if(A.y<C.y)
            {
                if(int3.x<=A.x && int3.x>=C.x && int3.y>=A.y && int3.y<=C.y)
                    ac=1;
            }
            else
                if(int3.x<=A.x && int3.x>=C.x && int3.y<=A.y && int3.y>=C.y)
                    ac=1;
        }
        float r=0;
        if(ab && bc)
            r=area(distanta(B, int1), distanta(B, int2), distanta(int1, int2));
        else if(ab && ac)
            r=area(distanta(A, int1), distanta(A, int3), distanta(int1, int3));
        else if(bc && ac)
            r=area(distanta(C, int2), distanta(C, int3), distanta(int2, int3));
        cout<<r<<endl;
    }
    return 0;
}
