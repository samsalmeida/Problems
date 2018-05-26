#include <bits/stdc++.h>
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> pii;
const int MAXN=8e+2;
 
int nc;
int n, m, c;
int vis[MAXN], ft[MAXN], t[MAXN], sub[MAXN];

vector<int> graph[MAXN];
vector<pii> edges;
 
void dfs(int u){
	vis[u]=1;
	t[u]=sub[u]=++c;
	for(int i=0;i<graph[u].size();++i){
 
		int v=graph[u][i];
 		
 		if(!vis[v]){
 			ft[v]=u;
 			dfs(v);
 			sub[u]=min(sub[u], sub[v]);
 			if(sub[v]>t[u]){
 				int x=u, y=v;
 				if(x>y) swap(x, y);
 				edges.push_back(pii(x, y));
 			}
 		}else if(v!=ft[u]){
 			sub[u]=min(sub[u], t[v]);
 		}
	}
}

bool comp(pii a, pii b){
	if(a.F!=b.F) return a.F<b.F;
	return a.S<b.S;
}

int main(){
	scanf("%d", &nc);
 
	for(int j=1;j<=nc;++j){
 
		scanf("%d %d", &n, &m);
 
		for(int i=0;i<m;++i){
			int u, v;
			scanf("%d %d", &u, &v);
 
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
 
		dfs(1);
		
		printf("Caso #%d\n", j);
		int s=edges.size();
		if(s!=0){
			printf("%d\n", s);
			sort(edges.begin(), edges.end(), comp);
			for(int i=0;i<s;++i){
				printf("%d %d\n", edges[i].F, edges[i].S);
			}
		}else{
			printf("Sin bloqueos\n");
		}

		memset(sub, 0, sizeof(sub));
		memset(vis, 0, sizeof(vis));
		memset(ft, 0, sizeof(ft));
		memset(t, 0, sizeof(t));

		for(int i=0;i<=n;++i){
			graph[i].clear();
		}
		edges.clear();
		c=0;
	}
 
	return 0;
}
