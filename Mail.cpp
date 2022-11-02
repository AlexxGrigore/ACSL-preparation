#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct caselelelelele{
    char sect;
    int num;
};

char poarta;

bool comparaaa(caselelelelele a, caselelelelele b){
    if(a.num % 2 != 0 && b.num % 2 == 0)
        return true;
    else if(a.num % 2 == 0 && b.num % 2 != 0)
        return false;
    if(a.sect != b.sect){
        if(a.sect < poarta && b.sect >= poarta)
            return false;
        if(a.sect >= poarta && b.sect < poarta)
            return true;
        return a.sect < b.sect;
    }
    return a.num < b.num;
}

int main(){
    caselelelelele vilelelelele[105];
    freopen("date.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf(", %c%d", &vilelelelele[i].sect, &vilelelelele[i].num);
    for(int abc=0; abc<5; abc++){
        int added = 0;
        scanf("\n%d, ", &added);
        for(int i=0; i<added; i++)
            scanf("%c%d, ", &vilelelelele[i+n].sect, &vilelelelele[n+i].num);
        int k;
        n+=added;
        scanf("%c, %d", &poarta, &k);
        bool ok;
        do{
            ok = 1;
            for(int i=0; i<n-1; i++)
                if(!comparaaa(vilelelelele[i], vilelelelele[i+1])){
                    swap(vilelelelele[i], vilelelelele[i+1]);
                    ok = 0;
                }
        }while(!ok);
        cout<<vilelelelele[k-1].sect<<vilelelelele[k-1].num<<endl;
    }
    return 0;
}
