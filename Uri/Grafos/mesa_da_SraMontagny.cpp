#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 110
 
int n, m, comp[MAXN], mesa[MAXN];
vector<int> friends[MAXN];
// em mesa 1 sig direita
// || ||  ||  || esquerda
 
bool dfs(int x){
    for(int i=0;i<friends[x].size();++i){
        int w=friends[x][i];
        if(!comp[w]){
            comp[w]=1;
 
            if(mesa[x]==1) mesa[w]=2;
            else if(mesa[x]==2) mesa[w]=1;
 
            if(!dfs(w)) return false;
        }else{
 
            if(mesa[x]==mesa[w]) return false;
 
        }
    }
    return true;
}
 
int main() {
    int cont=0;
    while(scanf("%d %d", &n, &m)!=EOF){
 
        for(int i=0;i<m;++i){
            int u, v;
            scanf("%d %d", &u, &v);
 
            friends[u].push_back(v);
            friends[v].push_back(u);
        }
        bool ok=true;
        for(int j=1;j<=n;++j){
            if(!comp[j]){
                comp[j]=1;
                mesa[j]=1;
                if(!dfs(j)){
                    ok=false;
                    break;
                }
            }
        }
        cont++;
        printf("Instancia %d\n", cont);
        if(ok){
            printf("sim\n\n");
        }else{
            printf("nao\n\n");
        }
 
        for(int i=1;i<=n;++i) friends[i].clear();
        memset(comp, 0, sizeof(comp));
        memset(mesa, 0, sizeof(mesa));
    }
 
    return 0;
}
