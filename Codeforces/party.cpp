#include <bits/stdc++.h>

using namespace std;

const int MAXN=2020;

int n, v[MAXN], cp[MAXN];
vector<int> vec[MAXN];

int dfs(int u){
	int m=0;
	cp[u]=1;
	for(int i=0;i<vec[u].size();++i){

		int v=vec[u][i];

		if(!cp[v]){
			//cout << u << " . " << v << "\n";
			m=max(m, dfs(v)+1);
			
		}

	}
	return m;
}
int main(){
	scanf("%d", &n);

	for(int i=1;i<=n;++i){
		scanf("%d", &v[i]);
		if(v[i]!=-1){
			vec[v[i]].push_back(i);
			//cout <<  u << " . " << i << "\n";
		}
	}
	int r=0;
	for(int j=1;j<=n;++j){

		if(!cp[j] && v[j]==-1){
			r=max(r, dfs(j)+1);
			//cout << dfs(j) << "\n";
		}
	}

	printf("%d\n", r);
	return 0;
}
