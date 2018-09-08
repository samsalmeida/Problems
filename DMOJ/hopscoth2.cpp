// HOPSCOTH2 - DMOJ
// Complexity: O(n*log n)
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const int MAXN=(1<<23)+1e2;

int n, k;
ll v[MAXN], tree[2*MAXN+1], dist[MAXN];

ll query(int u, int l, int r, int a, int b){

	if(a<=l && r<=b) return tree[u];

	int mid=(l+r)/2;

	if(b<=mid) return query(2*u, l, mid, a, b);
	if(a>mid) return query(2*u+1, mid+1, r, a, b);

	return min(query(2*u, l, mid, a, b), query(2*u+1, mid+1, r, a, b));
}

void upd(int u, int l, int r, int i, ll val){

	if(l==r){
		tree[u]=val;
		return;
	}

	int mid=(l+r)/2;
	if(i<=mid) upd(2*u, l, mid, i, val);
	else upd(2*u+1, mid+1, r, i, val);

	tree[u]=min(tree[2*u], tree[2*u+1]);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> k;

	for(int i=1;i<=n;++i) cin >> v[i];

	upd(1, 0, n+1, 0, 0);

	for(int i=1;i<=n+1;++i){
		//int kra1=max(i-k, 0), kra2=max(i-1, 0);
		
		dist[i]=v[i]+query(1, 0, n+1, max(i-k, 0), max(i-1, 0));
		
		upd(1, 0, n+1, i, dist[i]);
	}
	
	vector<int> a;

	int id=n+1;
	ll D=dist[n+1];
	cout << D << "\n";

	for(int i=n;i>=1;--i){
		if(query(1, 0, n+1, i, i)==D){
			id=i;
			a.push_back(i);
			D=query(1, 0, n+1, i, i);
			break;
		}
	}

	for(int i=n;i>=1;--i){
		if(query(1, 0, n+1, i, i)+v[id]==D){
			id=i;
			a.push_back(i);
			D=query(1, 0, n+1, i, i);
		}	
	}
	
	for(int i=a.size()-1;i>=0;--i) cout << a[i] << " ";

	cout << "\n";
	return 0;
}
