// Familías de Troia - Programação Nível 2 - Fase 2 - OBI 2013
// Flood Fill 
// Complexidade: O(n + m)
// By Samyra Vitória

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100100
 
vector<int> v[MAXN];
int n, m, comp[MAXN];
 
void dfs(int x){
 
    for(int i=0;i<v[x].size();++i){
        int u=v[x][i];
        if(comp[u]==0){
            comp[u]=comp[x];
            dfs(u);
        }
    }
}
 
int main(){

    scanf("%d %d", &n, &m);
    memset(comp, 0, sizeof(comp));
    
    for(int i=0;i<m;++i){
        int u, w;
        scanf("%d %d", &u, &w);
        
        v[u].push_back(w);
        v[w].push_back(u);
    }

    int c=0;
    for(int j=1;j<=n;++j){
        if(comp[j]==0){
            c++;
            comp[j]=c;
 
            dfs(j);
        }
    }
    int resp=0;
    for(int i=1;i<=n;++i){
 
        if(comp[i]>resp) resp=comp[i];
 
    }
    printf("%d\n", resp);
    return 0;
}
