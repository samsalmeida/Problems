// Codeforces - Codeforces Round #134 (Div. 1)
// Complexity: O(n²)
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

int const MAXN=110;
int n, comp[MAXN];
vector< pair<int, int> > mt;
vector<int> g[MAXN];

void dfs(int x){
	comp[x]=1;
	for(int i=0;i<g[x].size();++i){
		int w=g[x][i];
		if(!comp[w]){
			dfs(w);
		}
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		int x, y;
		scanf("%d%d", &x, &y);
		mt.push_back(make_pair(x, y));
	}
	
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if((mt[i].first==mt[j].first) || (mt[i].second==mt[j].second)){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int n_c=0;
	for(int k=0;k<n;++k){
		if(!comp[k]){
			n_c++;
			dfs(k);
		}
	}
	
	printf("%d\n", n_c-1);
	return 0;
}
