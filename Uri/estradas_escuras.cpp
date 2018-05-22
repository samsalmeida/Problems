#include <bits/stdc++.h>

using namespace std;

struct edges{
	
	int x, y, d;	
};

bool comp(edges a, edges b){
	return a.d<b.d;
}

int const MAXN = 200020;

int n, m, uf[MAXN], rk[MAXN];
edges ed[MAXN];

int find(int u){
	
	if(uf[u]==u) return u;
	return uf[u]=find(uf[u]);
}

void join(int u, int v){
	
	if((u=find(u))==(v=find(v))) return;
	
	if(rk[u]>rk[v]) swap(u, v);
	
	uf[u]=v;
	rk[v]=(rk[u]==rk[v]);
}

int main(){
	
	while(scanf("%d%d", &n, &m) && !(n==0 || m==0)){
		int t=0;
		for(int i=0;i<m;++i){
			scanf("%d%d%d", &ed[i].x, &ed[i].y, &ed[i].d);
			t+=ed[i].d;
		}
		
		for(int i=0;i<n;++i) uf[i]=i;
		
		sort(ed, ed+m, comp);
		int r=0;
		for(int i=0;i<m;++i){
			
			if(find(ed[i].x)!=find(ed[i].y)){
				r+=ed[i].d;
				join(ed[i].x, ed[i].y);
			}
		}
		
		printf("%d\n", t-r);
	}
	
	return 0;
}
