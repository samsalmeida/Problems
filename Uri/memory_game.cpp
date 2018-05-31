#include <bits/stdc++.h>

using namespace std;

const int MAXN=50050, MAXL=20;

int n;
int c[MAXN], p[MAXN];
int level[MAXN], ft[MAXN];
int anc[MAXN][MAXL];

vector<int> graph[MAXN];

void dfs(int u){

	for(int i=0 ; i<graph[u].size() ; ++i){

		int v=graph[u][i];

		if(level[v]==-1){

			level[v]=level[u]+1;
			ft[v]=u;

			dfs(v);
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
		
	scanf("%d", &n);

	for(int i=1;i<=n;++i){

		int k;
		scanf("%d", &k);

		if(c[k]){
			p[i]=c[k];
			p[c[k]]=i;
		}
		c[k]=i;
	}

	for(int i=1;i<n;++i){

		int u, v;
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	memset(anc, -1, sizeof(anc));
	memset(level, -1, sizeof(level));

	level[1]=1;
	dfs(1);

	for(int i=1;i<=n;++i) anc[i][0]=ft[i];

	for(int j=1;j<MAXL;++j){

		for(int i=1;i<=n;++i){

			if(anc[i][j-1]!=-1){
				anc[i][j]=anc[anc[i][j-1]][j-1];
			}
		}
	}

	long long resp=0LL;

	for(int i=1;i<=n;++i){
		resp+=(long long)(level[i]+level[p[i]]-2*level[LCA(i, p[i])]);
	}

	printf("%lld\n", resp/2);
	return 0;
}
