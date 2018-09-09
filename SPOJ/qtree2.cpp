// Query on a tree II (QTREE2) - SPOJ
// Complexity: O(t*n*log n)

#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int MAXN=10010, MAXL=20;
typedef pair<int, int> pii;

int t, n;
int ans[MAXN][MAXL];
int dist[MAXN], h[MAXN];
vector<pii> graph[MAXN];

void dfs(int u, int p){

	if(p!=-1) h[u]=h[p]+1;
	ans[u][0]=p;

	for(auto v: graph[u]){

		if(v.S==p) continue;

		dist[v.S]=dist[u]+v.F;
		dfs(v.S, u);
	}
}

void build(){
	memset(ans, -1, sizeof ans);
	memset(dist, 0, sizeof dist);
	memset(h, 0, sizeof h);

	dfs(1, -1);

	for(int j=1;j<=MAXL;++j){
		for(int i=1;i<=n;++i){
			if(ans[i][j-1]!=-1){
				ans[i][j]=ans[ans[i][j-1]][j-1];
			}
		}
	}
}

int LCA(int u, int v){

	if(h[u]<h[v]) swap(u, v);

	for(int i=MAXL-1;i>=0;--i){
		if(h[u]-(1<<i)>=h[v]){
			u=ans[u][i];
		}
	}

	if(u==v) return u;


	for(int i=MAXL-1;i>=0;--i){
		if(ans[u][i]!=-1 && ans[v][i]!=ans[u][i]){
			u=ans[u][i];
			v=ans[v][i];
		}
	}

	return ans[u][0];
}

void delete_graph(int t){
	for(int i=0;i<=t;++i){
		graph[i].clear();
	}
}

int search(int u, int k){
	for(int i=MAXL-1;i>=0;--i){
		if(k-(1<<i)>=0){
			
			u=ans[u][i];
			k-=(1<<i);
		}
	}

	return u;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	scanf("%d", &t);
	while(t--){

		scanf("%d", &n);

		for(int i=1;i<n;++i){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);

			graph[u].push_back(pii(c, v));
			graph[v].push_back(pii(c, u));
		}
		build();
		string s;

		while(cin>>s && s!="DONE"){

			if(s=="DIST"){
				int a, b;
				scanf("%d%d", &a, &b);
				printf("%d\n", dist[a]+dist[b]-2*dist[LCA(a, b)]);
			}else{

				int a, b, kra;
				scanf("%d%d%d", &a, &b, &kra);
				int lca=LCA(a, b);
				int Au_lca=h[a]-h[lca]+1;

				if(kra==Au_lca){ 
					printf("%d\n", lca);
				}else if(kra<Au_lca){
					printf("%d\n", search(a, kra-1));
				}else{
					printf("%d\n", search(b, Au_lca+h[b]-h[lca]-kra));
				}
			}
		}

		delete_graph(n);
	}
	return 0;
}
