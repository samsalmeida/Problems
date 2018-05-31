#include <bits/stdc++.h>

using namespace std;

const int MAXN=100010;

struct point{
	int ip, op;	
};

int n, m, cp[MAXN], cp_[MAXN];
point deg[MAXN];
vector<int> graph[MAXN], graph_[MAXN];

void dfs(int node){
	cp[node]=1;
	for(int i=0;i<graph[node].size();++i){
		int w=graph[node][i];
		if(!cp[w]) dfs(w);
	}
}

void dfs_(int node){
	
	cp_[node]=1;
	for(int i=0;i<graph_[node].size();++i){
		int w=graph_[node][i];
		if(!cp_[w]) dfs_(w);
	}
}

int check(){
	dfs(1);
	dfs_(1);
	
	for(int j=1;j<=n;++j){
		if(!cp[j] && !cp_[j]) return 0;
	}
	return 1;
}
int main(){
	
	scanf("%d%d", &n, &m);
	
	for(int i=0;i<m;++i){
		
		int u, v;
		scanf("%d%d", &u, &v);
		
		graph[u].push_back(v);
		graph_[v].push_back(u);
		deg[v].ip++, deg[u].op++;
	}
	int c_i=0, c_o=0;
	for(int i=1;i<=n;++i){
		if(deg[i].ip==0) c_i++;
		if(deg[i].op==0) c_o++;
	}
	
	if((c_i+c_o)>2 || !check()) printf("Nao Bolada\n");
	else printf("Bolada\n");
	return 0;
}
