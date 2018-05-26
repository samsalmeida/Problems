#include <bits/stdc++.h>

using namespace std;

int const MAXN=0x186aa;
int n, k, rk[MAXN], uf[MAXN];

int find(int u){
    if(uf[u]==u) return u;
    return uf[u]=find(uf[u]);
}

void join(int u, int v){
    if((u=find(u))==(v=find(v))) return ;

    if(rk[u]>rk[v]) swap(u, v);

    uf[u]=v;
    rk[v]+=(rk[u]==rk[v]);
}

int main(){
    scanf("%d%d", &n, &k);

    for(int i=1;i<=n;++i){
        uf[i]=i;
    }
    for(int i=0; i<k ; ++i){
        char a;
        scanf(" %c", &a);
        int x, y;
        scanf("%d%d", &x, &y);

        if(a=='C'){

            if(find(x)==find(y)) printf("S\n");
            else printf("N\n");
        }else{
            join(x, y);
        }
    }
    return 0;
}
