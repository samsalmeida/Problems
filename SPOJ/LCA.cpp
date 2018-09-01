// LCA - Lowest Common Ancestor - SPOJ
// Complexity: O(t*n*log m)
// By Samyra Almeida

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN=1010, MAXL=15;
 
int t, n, q;
int level[MAXN], ft[MAXN];
int anc[MAXN][MAXL];
 
vector<int> graph[MAXN];
 
void dfs(int u){
    
    for(int i=0;i<graph[u].size();++i){
        
        int w=graph[u][i];
        if(level[w]==-1){
            
            level[w]=level[u]+1;
            ft[w]=u;
            dfs(w);
        }
    }
}
 
int LCA(int u, int v){
    
    if(level[u]<level[v]) swap(u, v);
    
    for(int i=MAXL-1;i>=0;--i){
        
        if(level[u]-(1<<i)>=level[v]){
            u=anc[u][i];
        }
    }
    
    if(u==v) return u;
    
    for(int i=MAXL-1;i>=0;--i){
        
        if(anc[u][i]!=-1 && anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
        
    }
    
    return anc[u][0];
}

int main(){
    
    scanf("%d", &t);
    
    for(int cs=1;cs<=t;++cs){
        
        scanf("%d", &n);
        
        for(int id=1;id<=n;++id){
            
            int m;
            scanf("%d", &m);
            
            for(int ib=1;ib<=m;++ib){
                
                int u;
                scanf("%d", &u);
                
                graph[id].push_back(u);
                graph[u].push_back(id);
            }
        }
        
        memset(anc, -1, sizeof(anc));
        memset(level, -1, sizeof(level));
        
        level[1]=1;
        dfs(1);
        
        for(int i=2;i<=n;++i){
            anc[i][0]=ft[i];
        }
        
        for(int j=1;j<MAXL;++j){
            for(int i=1;i<=n;++i){
                if(anc[i][j-1]!=-1){
                    anc[i][j]=anc[anc[i][j-1]][j-1];
                }
            }
        }
        
        
        scanf("%d", &q);
        
        printf("Case %d:\n", cs);
        for(int id=1;id<=q;++id){
            int u, v;
            scanf("%d%d", &u, &v);
            
            printf("%d\n", LCA(u, v));
        }
        
        for(int i=0;i<=n;++i){
            graph[i].clear();
        }
        memset(ft, 0, sizeof(ft));
    }
    
	return 0;
} 
