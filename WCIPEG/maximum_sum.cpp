// Maximum Sum - WCIPEG
// Complexity: O(n)
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=100100;

int n, v[MAXN];
int dp0[MAXN], dp1[MAXN];

int main(){
	
	scanf("%d", &n);

	for(int i=0;i<n;++i){
		scanf("%d", &v[i]);
	}
	dp0[0]=0;
	dp1[0]=v[0];

	for(int i=1;i<n;++i){

		dp0[i]=max(dp1[i-1], dp0[i-1]);
		dp1[i]=max(dp0[i-1]+v[i], dp0[i-2]+v[i]);
	}

	ll resp=0;
	
	for(int i=0;i<n;++i){

		ll r=max(dp1[i], dp0[i]);
		resp=max(resp, r);
	}

	printf("%d\n", resp);
	return 0;
}
