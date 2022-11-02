#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

void HexToBin(char val[], short length, char table[][6][4])
{
    bool bitseq[6]={0, 0, 0, 0, 0, 0};
    short bit=5, valc=strlen(val)-1;
    for(; valc>=0; valc--)
    {
        switch(val[valc])
        {
            case '0': { bitseq[bit--]=0; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=0;} break;}
            case '1': { bitseq[bit--]=1; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=0;} break;}
            case '2': { bitseq[bit--]=0; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=0;} break;}
            case '3': { bitseq[bit--]=1; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=0;} break;}
            case '4': { bitseq[bit--]=0; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=0;} break;}
            case '5': { bitseq[bit--]=1; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=0;} break;}
            case '6': { bitseq[bit--]=0; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=0;} break;}
            case '7': { bitseq[bit--]=1; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=0;} break;}
            case '8': { bitseq[bit--]=0; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=1;} break;}
            case '9': { bitseq[bit--]=1; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=1;} break;}
            case 'A': { bitseq[bit--]=0; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=1;} break;}
            case 'B': { bitseq[bit--]=1; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=0; bitseq[bit--]=1;} break;}
            case 'C': { bitseq[bit--]=0; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=1;} break;}
            case 'D': { bitseq[bit--]=1; bitseq[bit--]=0; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=1;} break;}
            case 'E': { bitseq[bit--]=0; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=1;} break;}
            case 'F': { bitseq[bit--]=1; bitseq[bit--]=1; if(bit>1){ bitseq[bit--]=1; bitseq[bit--]=1;} break;}
        }
    }
    for(bit=5; length>0; length--, bit--)
        if(bitseq[bit])
            table[0][length-1][1]='1';
        else
            table[0][length-1][1]='0';
    return;
}

bool charand(char val1, char val2)
{
    if(val1=='1' && val2=='1')
        return 1;
    return 0;
}

bool charor(char val1, char val2)
{
    if(val1=='1' || val2=='1')
        return 1;
    return 0;
}

bool charxor(char val1, char val2)
{
    if(val1=='1' && val2=='0')
        return 1;
    if(val1=='0' && val2=='1')
        return 1;
    return 0;
}

int findoperation(char val1, char val2, char result)
{
    if(val1=='0' && val2=='0' && result=='0')
        return 1;
    else if(val1=='1' && val2=='0' && result=='0')
        return 1;
    else if(val1=='0' && val2=='1' && result=='0')
        return 1;
    else if(val1=='1' && val2=='1' && result=='0')
        return 3;
    else if(val1=='0' && val2=='0' && result=='1')
        return 0;
    else if(val1=='1' && val2=='0' && result=='1')
        return 2;
    else if(val1=='0' && val2=='1' && result=='1')
        return 2;
    else if(val1=='1' && val2=='1' && result=='1')
        return 1;
    return 0;
}

int main()
{
    freopen("acsl5.txt", "r", stdin);
    for(int abc=0; abc<10; abc++)
    {
        char table[6][6][4], hexstr[4];
        memset(table, 0, 6*6*4);
        memset(hexstr, 0, 4);
        short length;
        scanf("%d, %s", &length, &hexstr);
        hexstr[strlen(hexstr)-1]=0;
        HexToBin(hexstr, length, table);
        for(int i=1; i<length; i++)
            for(int j=0; j<length-i; j++)
            {
                scanf("%s ", &table[i][j]);
                if(table[i][j][strlen(table[i][j])-1]==',')
                    table[i][j][strlen(table[i][j])-1]=0;
            }
        bool correct = 1, none=0;
        scanf("\n");
        for(int j=1; j<length && none==0; j++)
        {
            for(int i=0; i<length-j && none==0; i++)
            {
                switch(table[j][i][0])
                {
                    case 'R':{
                        if((charor(table[j-1][i][1], table[j-1][i+1][1])==1 && table[j][i][1]=='0')||(charor(table[j-1][i][1], table[j-1][i+1][1])==0 && table[j][i][1]=='1'))
                        {
                            correct = 0;
                            short res=findoperation(table[j-1][i][1], table[j-1][i+1][1], table[j][i][1]);
                            cout<<j+1<<", "<<i+1<<", ";
                            switch(res)
                            {
                                case 0: {cout<<"NONE"<<endl; none=1; break;}
                                case 1: {cout<<"AND"<<table[j][i][1]<<endl; break;}
                                case 2: {cout<<"OR"<<table[j][i][1]<<endl; break;}
                                case 3: {cout<<"XOR"<<table[j][i][1]<<endl; break;}
                            }
                        }
                        break;
                    }
                    case 'A':{
                        if((charand(table[j-1][i][1], table[j-1][i+1][1])==1 && table[j][i][1]=='0')||(charand(table[j-1][i][1], table[j-1][i+1][1])==0 && table[j][i][1]=='1'))
                        {
                            correct = 0;
                            short res=findoperation(table[j-1][i][1], table[j-1][i+1][1], table[j][i][1]);
                            cout<<j+1<<", "<<i+1<<", ";
                            switch(res)
                            {
                                case 0: {cout<<"NONE"<<endl; none=1; break;}
                                case 1: {cout<<"AND"<<table[j][i][1]<<endl; break;}
                                case 2: {cout<<"OR"<<table[j][i][1]<<endl; break;}
                                case 3: {cout<<"XOR"<<table[j][i][1]<<endl; break;}
                            }
                        }
                        break;
                    }
                    case 'X':{
                        if((charxor(table[j-1][i][1], table[j-1][i+1][1])==1 && table[j][i][1]=='0')||(charxor(table[j-1][i][1], table[j-1][i+1][1])==0 && table[j][i][1]=='1'))
                        {
                            correct = 0;
                            short res=findoperation(table[j-1][i][1], table[j-1][i+1][1], table[j][i][1]);
                            cout<<j+1<<", "<<i+1<<", ";
                            switch(res)
                            {
                                case 0: {cout<<"NONE"<<endl; none=1; break;}
                                case 1: {cout<<"AND"<<table[j][i][1]<<endl; break;}
                                case 2: {cout<<"OR"<<table[j][i][1]<<endl; break;}
                                case 3: {cout<<"XOR"<<table[j][i][1]<<endl; break;}
                            }
                        }
                        break;
                    }
                }
            }
        }
        if(correct == 1)
            cout<<"TRUE"<<endl;
        cout<<endl;
    }
    return 0;
}
