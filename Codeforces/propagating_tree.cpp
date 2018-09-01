// Propagating Tree - Codeforces Round #225 (Div. 2)
// Complexity: O(m*log n)
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e5+10;

int n, m, t, num[MAXN], h[MAXN], d[MAXN], in[MAXN], out[MAXN];
int o[4*MAXN], p[4*MAXN];
int lo[4*MAXN], lp[4*MAXN];
vector<int> graph[MAXN];

void dfs(int u, int f){
	d[++t]=u;
	in[u]=t;
	out[u]=t;
	h[u]=h[f]+1;
	for(auto v: graph[u]){
		if(v!=f){
			dfs(v, u);
			out[u]=max(out[u], out[v]);
		}
		
	}
}

void build(int u, int l, int r){

	if(l==r){
		if(h[d[l]]%2==1){
			
			o[u]=num[d[l]];
		}else{
			
			p[u]=num[d[l]];
		}
		return;
	}

	int mid=(l+r)/2;
	build(2*u, l, mid); build(2*u+1, mid+1, r);

	o[u]=o[2*u]+o[2*u+1];
	p[u]=p[2*u]+p[2*u+1];
}

void upd(int u, int l, int r, int a, int b, int val){
	if(lo[u]!=0){
		if(l!=r){
			lo[2*u]+=lo[u];
			lo[2*u+1]+=lo[u];
		}

		o[u]+=lo[u]*(r-l+1);
		lo[u]=0;
	}
	if(lp[u]!=0){
		if(l!=r){
			lp[2*u]+=lp[u];
			lp[2*u+1]+=lp[u];
		}

		p[u]+=lp[u]*(r-l+1);
		lp[u]=0;
	}
	if(l>b || r<a) return;

	if(a<=l && r<=b){
		
		if(r!=l){
			lo[2*u]+=val;
			lo[2*u+1]+=val;
			lp[2*u]+=(-val);
			lp[2*u+1]+=(-val);
		}
		o[u]+=val*(r-l+1);
		p[u]+=(-val)*(r-l+1);
		return;
	}

	int mid=(l+r)/2;

	upd(2*u, l, mid, a, b, val); upd(2*u+1, mid+1, r, a, b, val);
	o[u]=o[2*u]+o[2*u+1];
	p[u]=p[2*u]+p[2*u+1];	
}


int get(int u, int l, int r, int i){

	if(lo[u]!=0){
		if(l!=r){
			lo[2*u]+=lo[u];
			lo[2*u+1]+=lo[u];
		}

		o[u]+=lo[u]*(r-l+1);
		lo[u]=0;
	}
	if(lp[u]!=0){
		if(l!=r){
			lp[2*u]+=lp[u];
			lp[2*u+1]+=lp[u];
		}

		p[u]+=lp[u]*(r-l+1);
		lp[u]=0;
	}

	if(l==r){
		if(h[d[l]]%2==1){
			return o[u];
		}else{
			return p[u];
		}
	}

	int mid=(l+r)/2;

	if(i<=mid) return get(2*u, l, mid, i);
	else return get(2*u+1, mid+1, r, i);
}


int main(){
	
	scanf("%d%d", &n, &m);

	for(int i=1;i<=n;++i){

		scanf("%d", &num[i]);
	}

	for(int i=1;i<n;++i){

		int u, v;
		scanf("%d%d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 1);
	build(1, 1, t);
	for(int i=0;i<m;++i){

		int id;
		scanf("%d", &id);
		if(id==1){
			int x, val;
			scanf("%d%d", &x, &val);
			if(h[x]%2==0) val=-val;

			upd(1, 1, t, in[x], out[x], val);
		}else{
			int x;
			scanf("%d", &x);

			printf("%d\n", get(1, 1, t, in[x]));
		}
	}
	return 0;
}
