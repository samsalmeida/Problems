#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, int> ii;
const int MAXN=2e5+10;

int n, m;
ll a[MAXN], dist[MAXN];
vector<ii> graph[MAXN];
void bfs(){
	
	priority_queue<ii, vector<ii> , greater<ii> > row;

	for(int i=1;i<=n;++i){
		row.push({dist[i], i});
	}

	while(!row.empty()){

		int at;
		ll d;
		tie(d, at)=row.top();
		row.pop();

		if(d>dist[at]) continue;

		for(ii u: graph[at]){
			int v;
			ll D;
			tie(D, v)=u;

			if(dist[at]+D<dist[v]){
				dist[v]=dist[at]+D;
				row.push({dist[v], v});
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);

	for(int i=1;i<=m;++i){
		int u, v;
		ll w;
		scanf("%d%d%llu", &u, &v, &w);

		graph[u].push_back({w+w, v});
		graph[v].push_back({w+w, u});
	}
	for(int i=1;i<=n;++i){
		scanf("%llu", &a[i]);
		dist[i]=a[i];
	}
	bfs();
	for(int i=1;i<=n;++i){

		printf("%llu ", dist[i]);
	}
	printf("\n");
	return 0;
}
