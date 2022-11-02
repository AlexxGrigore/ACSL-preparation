#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct table
{
    short color=-1, val, n=-1;
    bool used=0;
} board[10][10];

struct child
{
    short c, l;
};

void fillTable()
{
    short value=1;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            board[i][j].val=value++, board[i][j].color=-1;
    for(int i=0; i<=9; i++)
    {
        board[i][0].val=-1;
        board[i][0].color=1;
        board[0][i].val=-1;
        board[0][i].color=1;
        board[i][9].val=-1;
        board[i][9].color=1;
        board[9][i].val=-1;
        board[9][i].color=1; 
    }
    return;
}

void findTracks(int tracks[][64], int no[], int&n, int startx, int starty, child children[][8])
{
    short vi[]= {1, 1, -1, -1, -1, 1, -1, 1}, vj[]= {-1, 1, -1, 1, 1, 1, -1, -1};
    queue <pair<int, int> >Q;
    Q.push({startx, starty});
    while(!Q.empty())
    {
        int i=Q.front().first, j=Q.front().second;
        board[i][j].n=n;
        Q.pop();
        if(board[i][j].used==1)
            continue;
        else
            board[i][j].used=1;
        for(int v=0; v<4; v++)
        {
            bool directie=1;
            for(int ki=1; ki<=4 && directie == 1; ki++)
            {
                int aux1=board[i+vi[v]*ki][j].color, aux2=board[i+vi[v]*(ki-1)][j].color;
                board[i+vi[v]*(ki-1)][j].color=1;
                if(board[i+vi[v]*ki][j].val!=-1)
                {
                    if(board[i+vi[v]*ki][j].color==0)
                    {
                        if(board[i+vi[v]*(ki+1)][j].color!=-1 || board[i+vi[v]*(ki+1)][j].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*ki][j].val;
                        else if((board[i+vi[v]*ki][j+1].val==-1 || board[i+vi[v]*ki][j+1].color!=-1) && (board[i+vi[v]*ki][j-1].val==-1 || board[i+vi[v]*ki][j-1].color!=-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*ki][j].val;
                        else if(ki<=3)
                            directie=0;
                    }
                    board[i+vi[v]*ki][j].color=1;
                    if(board[i+vi[v]*(ki-1)][j+1].color==0)
                    {
                        if(board[i+vi[v]*ki][j+1].color!=-1 || board[i+vi[v]*ki][j+1].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j+1].val;
                        else if((board[i+vi[v]*(ki-1)][j+2].val==-1 || board[i+vi[v]*(ki-1)][j+2].color!=-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j+1].val;
                    }
                    if(board[i+vi[v]*(ki-1)][j-1].color==0)
                    {
                        if(board[i+vi[v]*ki][j-1].color!=-1 || board[i+vi[v]*ki][j-1].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j-1].val;
                        else if((board[i+vi[v]*(ki-1)][j].val==-1 || board[i+vi[v]*(ki-1)][j].color!=-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j-1].val;
                    }
                }
                else if(ki<=3)
                    directie=0;
                board[i+vi[v]*ki][j].color=aux1, board[i+vi[v]*(ki-1)][j].color=aux2;
            }
            for(int ki=1; ki<=3 && directie == 1; ki++)
            {
                int aux1=board[i+vi[v]*3][j+vj[v]*ki].color, aux2=board[i+vi[v]*3][j+vj[v]*(ki-1)].color;
                board[i+vi[v]*3][j+vj[v]*(ki-1)].color=1;
                if(board[i+vi[v]*3][j+vj[v]*ki].val!=-1)
                {
                    if(board[i+vi[v]*3][j+vj[v]*ki].color==0)
                    {
                        if(board[i+vi[v]*3][j+vj[v]*(ki+1)].color!=-1 || board[i+vi[v]*3][j+vj[v]*(ki+1)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*3][j+vj[v]*ki].val;
                        else if((board[i+vi[v]*(3+1)][j+vj[v]*ki].color!=-1 || board[i+vi[v]*(3+1)][j+vj[v]*ki].val==-1) && (board[i+vi[v]*(3-1)][j+vj[v]*ki].color!=-1 || board[i+vi[v]*(3-1)][j+vj[v]*ki].val==-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*3][j+vj[v]*ki].val;
                        else if(ki<=2)
                            directie=0;
                    }
                    board[i+vi[v]*3][j+vj[v]*ki].color=1;
                    if(board[i+vi[v]*(3+1)][j+vj[v]*(ki-1)].color==0)
                    {
                        if(board[i+vi[v]*(3+2)][j+vj[v]*(ki-1)].color!=-1 || board[i+vi[v]*(3+2)][j+vj[v]*(ki-1)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(3+1)][j+vj[v]*(ki-1)].val;
                        else if((board[i+vi[v]*(3+1)][j+vj[v]*(ki-2)].color!=-1 || board[i+vi[v]*(3+1)][j+vj[v]*(ki-2)].val==-1) && (board[i+vi[v]*(3+1)][j+vj[v]*ki].color!=-1 || board[i+vi[v]*(3+1)][j+vj[v]*ki].val==-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(3+1)][j+vj[v]*(ki-1)].val;
                    }
                    if(board[i+vi[v]*(3-1)][j+vj[v]*(ki-1)].color==0)
                    {
                        if(board[i+vi[v]*(3-2)][j+vj[v]*(ki-1)].color!=-1 || board[i+vi[v]*(3-2)][j+vj[v]*(ki-1)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(3-1)][j+vj[v]*(ki-1)].val;
                        else if((board[i+vi[v]*(3-1)][j+vj[v]*(ki-2)].color!=-1 || board[i+vi[v]*(3-1)][j+vj[v]*(ki-2)].val==-1) && (board[i+vi[v]*(3-1)][j+vj[v]*ki].color!=-1 || board[i+vi[v]*(3-1)][j+vj[v]*ki].val==-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(3-1)][j+vj[v]*(ki-1)].val;
                    }
                }
                else if(ki<=2)
                    directie=0;
                board[i+vi[v]*3][j+vj[v]*ki].color=aux1, board[i+vi[v]*3][j+vj[v]*(ki-1)].color=aux2;
            }
            if(directie==1)
            {
                Q.push({i+vi[v]*3, j+vj[v]*3});
                children[board[i][j].val][v].c=board[i+vi[v]*3][j+vj[v]*3].val;
            }
            children[board[i][j].val][v].l=no[n+v];
        }
        for(int v=4; v<8; v++)
        {
            bool directie=1;
            for(int ki=1; ki<=4 && directie==1; ki++)
            {
                int aux1=board[i][j+vj[v]*ki].color, aux2=board[i][j+vj[v]*(ki-1)].color;
                board[i][j+vj[v]*(ki-1)].color=1;
                if(board[i][j+vj[v]*ki].val!=-1)
                {
                    if(board[i][j+vj[v]*ki].color==0)
                    {
                        if(board[i][j+vj[v]*(ki+1)].color!=-1 || board[i][j+vj[v]*ki].val==-1)
                            tracks[n+v][no[n+v]++]=board[i][j+vj[v]*ki].val;
                        else if((board[i-1][j+vj[v]*ki].color!=-1 || board[i-1][j+vj[v]*ki].val==-1) && (board[i+1][j+vj[v]*ki].color!=-1 || board[i+1][j+vj[v]*ki].val==-1))
                                tracks[n+v][no[n+v]++]=board[i][j+vj[v]*ki].val;
                                else if(ki<=3)
                                    directie=0;
                        }
                    board[i][j+vj[v]*ki].color=1;
                    if(board[i+1][j+vj[v]*(ki-1)].color==0)
                    {
                        if(board[i+2][j+vj[v]*(ki-1)].color!=-1 || board[i+2][j+vj[v]*(ki-1)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+1][j+vj[v]*(ki-1)].val;
                        else if((board[i+1][j+vj[v]*ki].color!=-1 || board[i+1][j+vj[v]*ki].val==-1) && (board[i+1][j+vj[v]*(ki-2)].color!=-1 || board[i+1][j+vj[v]*(ki-2)].val==-1))
                            tracks[n+v][no[n+v]++]=board[i+1][j+vj[v]*(ki-1)].val;
                    }
                    if(board[i-1][j+vj[v]*(ki-1)].color==0)
                    {
                        if(board[i-2][j+vj[v]*(ki-1)].color!=-1 || board[i-2][j+vj[v]*(ki-1)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i-1][j+vj[v]*(ki-1)].val;
                        else if((board[i-1][j+vj[v]*(ki-2)].color!=-1 || board[i-1][j+vj[v]*(ki-2)].val==-1) && (board[i-1][j+vj[v]*ki].color!=-1 || board[i-1][j+vj[v]*ki].val==-1))
                                            tracks[n+v][no[n+v]++]=board[i-1][j+vj[v]*(ki-1)].val;

                    }
            }
                    else if(ki<=3)
                            directie=0;
                board[i][j+vj[v]*ki].color=aux1, board[i][j+vj[v]*(ki-1)].color=aux2;
            }
            for(int ki=1; ki<=3 && directie==1; ki++)
            {
                int aux1=board[i+vi[v]*ki][j+vj[v]*3].color, aux2=board[i+vi[v]*(ki-1)][j+vj[v]*3].color;
                board[i+vi[v]*(ki-1)][j+vj[v]*3].color=1;
                if(board[i+vi[v]*ki][j+vj[v]*3].val!=-1)
                {
                    if(board[i+vi[v]*ki][j+vj[v]*3].color==0)
                    {
                        if(board[i+vi[v]*(ki+1)][j+vj[v]*3].color!=-1 || board[i+vi[v]*(ki+1)][j+vj[v]*3].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*ki][j+vj[v]*3].val;
                        else if((board[i+vi[v]*ki][j+vj[v]*(3-1)].color!=-1 || board[i+vi[v]*ki][j+vj[v]*(3-1)].val==-1) && (board[i+vi[v]*ki][j+vj[v]*(3+1)].color!=-1 || board[i+vi[v]*ki][j+vj[v]*(3+1)].val==-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*ki][j+vj[v]*3].val;
                        else if(ki<=2)
                            directie=0;
                    }
                    board[i+vi[v]*ki][j+vj[v]*3].color=1;
                    if(board[i+vi[v]*(ki-1)][j+vj[v]*(3-1)].color==0)
                    {
                        if(board[i+vi[v]*(ki-1)][j+vj[v]*(3-2)].color!=-1 || board[i+vi[v]*(ki-1)][j+vj[v]*(3-2)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j+vj[v]*(3-1)].val;
                        else if((board[i+vi[v]*ki][j+vj[v]*(3-1)].color!=-1 || board[i+vi[v]*ki][j+vj[v]*(3-1)].val==-1) && (board[i+vi[v]*(ki-2)][j+vj[v]*(3-1)].color!=-1 || board[i+vi[v]*(ki-2)][j+vj[v]*(3-1)].val==-1))
                                tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j+vj[v]*(3-1)].val;
                    }
                if(board[i+vi[v]*(ki-1)][j+vj[v]*(3+1)].color==0)
                    {
                        if(board[i+vi[v]*(ki-1)][j+vj[v]*(3+2)].color!=-1 || board[i+vi[v]*(ki-1)][j+vj[v]*(3+2)].val==-1)
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j+vj[v]*(3+1)].val;
                        else if((board[i+vi[v]*ki][j+vj[v]*(3+1)].color!=-1 || board[i+vi[v]*ki][j+vj[v]*(3+1)].val==-1) && (board[i+vi[v]*(ki-2)][j+vj[v]*(3+1)].color!=-1 || board[i+vi[v]*(ki-2)][j+vj[v]*(3+1)].val==-1))
                            tracks[n+v][no[n+v]++]=board[i+vi[v]*(ki-1)][j+vj[v]*(3+1)].val;
                    }
                }
                else if(ki<=2)
                    directie=0;
                board[i+vi[v]*ki][j+vj[v]*3].color=aux1, board[i+vi[v]*(ki-1)][j+vj[v]*3].color=aux2;
            }
            if(directie==1)
            {
                Q.push({i+vi[v]*3, j+vj[v]*3});
                children[board[i][j].val][v].c=board[i+vi[v]*3][j+vj[v]*3].val;
            }
            children[board[i][j].val][v].l=no[n+v];
        }
        n+=8;
    }
    return;
}

void clearDoubles(int tracks[][64], int no[])
{
    for(int abc=0; abc<512; abc++)
    {
        int sterse=0;
        for(int i=0; i<no[abc]; i++)
        {
            bool gasit=0;
            for(int j=1+i; j<no[abc] && gasit==0; j++)
                if(tracks[abc][i]==tracks[abc][j])
                    gasit=1;
            if(gasit==1)
                sterse++;
            else
                tracks[abc][i-sterse]=tracks[abc][i];
        }
        no[abc]-=sterse;
    }
    return;
}

void maxLengthTrack(child maxTrack[][64], short &len, int tracks[][64], int no[], child children[][8], short parrent, child last[], short depth, short &tracksno, short sum, short lasti=0)
{
    last[depth].c=parrent;
    last[depth].l=lasti;
    for(int i=0; i<8; i++)
    {
        if(children[parrent][i].c!=0)
        {
            maxLengthTrack(maxTrack, len, tracks, no, children, children[parrent][i].c, last, depth+1, tracksno, sum+children[parrent][i].l, i);
        }
        else
        {
            if(sum+children[parrent][i].l>len)
            {
                tracksno=0;
                len=sum+children[parrent][i].l;
                for(int j=0; j<=depth; j++)
                    maxTrack[tracksno][j].c=last[j].c, maxTrack[tracksno][j].l=last[j+1].l;
            }
            else if(sum+children[parrent][i].l==len)
            {
                tracksno++;
                for(int j=0; j<=depth; j++)
                    maxTrack[tracksno][j].c=last[j].c, maxTrack[tracksno][j].l=last[j].l;
            }
        }
    }
    last[depth].c=0;
    last[depth].l=0;
    return;
}

int main()
{
    freopen("acsl6.txt", "r", stdin);
    for(short abc=0; abc<10; abc++)
    {
        fillTable();
        short b=0, w=0, pozb[64], pozw[64];
        scanf("%d", &w);
        for(int i=0; i<w; i++)
        {
            scanf(", %d", &pozw[i]);
            for(int k=1; k<9; k++)
                for(int j=1; j<9; j++)
                {
                    if(pozw[i]==board[k][j].val)
                    {
                        board[k][j].color=0;
                        break;
                    }
                }
        }
        scanf(", %d", &b);
        for(int i=0; i<b; i++)
        {
            scanf(", %d", &pozb[i]);
            for(int k=1; k<9; k++)
                for(int j=1; j<9; j++)
                {
                    if(pozb[i]==board[k][j].val)
                    {
                        board[k][j].color=1;
                        break;
                    }
                }
        }
        scanf("\n");
        for(int l=1; l<=8; l++)
        {
            for(int k=1; k<=8; k++)
            {
                if(board[l][k].color==1)
                {
                    for(int i=0; i<=9; i++)
                        for(int j=0; j<=9; j++)
                            board[i][j].used=0;
                    int tracks[1024][64], no[1024]; child children[64][8];
                    int n=0;
                    for(int i=0; i<1024; i++)
                        no[i]=0;
                    for(int i=0; i<64; i++)
                        for(int j=0; j<8; j++)
                            children[i][j].c=0;
                    findTracks(tracks, no, n, l, k, children);
                    clearDoubles(tracks, no);
                    child maxTrack[64][64], last[64];short len=0, tracksno=0;
                    for(int i=0; i<64; i++)
                        last[i].c=0;
                    maxLengthTrack(maxTrack, len, tracks, no, children, board[l][k].val, last, 0, tracksno, 0);
                    short trackstogo[64], trk=0;
                    for(int i=0; i<tracksno; i++)
                    {
                        trk=0;
                        for(int j=0; j<len; j++)
                        {
                            n=board[maxTrack[i][j].c/8][maxTrack[i][j].c%8].n;
                            for(int h=0; h<no[n+maxTrack[i][j].l]; h++)
                                trackstogo[trk++]=tracks[n+maxTrack[i][j].l][no[n+maxTrack[i][j].l]];
                        }
                        for(int j=0; j<trk; j++)
                        {
                            if(j>0)
                                printf(", ");
                            printf("%d", trackstogo[j]);
                        }
                        if(trk==0)
                            printf("NONE");
                        printf("\n");
                    }
                    printf("\n");

                }

            }
        }
    }
    return 0;
}
