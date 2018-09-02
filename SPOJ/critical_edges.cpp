// Critical Edges - SPOJ
// Complexity: O(nc*(n + m'*log m')) , m' = number of critical edges
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

const int MAXN=7e2+10;

struct ed{
	int x, y;

	bool operator<(const ed& o) const{
		if(o.x!=x){
			return x<o.x;
		}
		return y<o.y;
	}
};

int n, m, nc;
int t, mk[MAXN], ft[MAXN], low[MAXN], s[MAXN];
vector<int> graph[MAXN];
vector<ed> bridges;

void dfs(int u){
	mk[u]=1;
	low[u]=s[u]=++t;

	for(auto v: graph[u]){

		if(!mk[v]){
			ft[v]=u;
			dfs(v);
			low[u]=min(low[u], low[v]);
			if(low[v]>s[u]){
			
				if(v>u) bridges.push_back({u, v});
				else bridges.push_back({v, u});
			}
		}else if(v!=ft[u]){
			low[u]=min(low[u], s[v]);
		}
	}
}

void clear(int tam){
	t=0;
	memset(ft, 0, sizeof ft);
	memset(mk, 0, sizeof mk);
	memset(low, 0, sizeof low);
	memset(s, 0, sizeof s);
	bridges.clear();
	for(int i=1;i<=tam;++i) graph[i].clear();
}

int main(){

	scanf("%d", &nc);
	
	for(int j=1;j<=nc;++j){
		
		scanf("%d%d", &n, &m);
	
		for(int i=0;i<m;++i){
			int u, v;
			scanf("%d%d", &u, &v);
	
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(1);
		printf("Caso #%d\n", j);
		if(bridges.size()>0){
			printf("%d\n", bridges.size());
			sort(bridges.begin(), bridges.end());

			for(ed at: bridges){
				printf("%d %d\n", at.x, at.y);
			}
		}

		else printf("Sin bloqueos\n");

		clear(n);
	}
	return 0;
}
