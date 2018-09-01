// Codeforces - Educational Codeforces Round 36 (Rated for Div. 2)
// Complexity: O(n)
// By Samyra Almeida

#include <bits/stdc++.h>
using  namespace std;

const int MAXN=110;

int n, k;
int a[MAXN];

int main(){
	scanf("%d %d", &n, &k);

	for(int i=0;i<n;++i) scanf("%d", &a[i]);

	int r=0x3f3f3f3f;

	for(int i=0;i<n;++i){
		if(k%a[i]==0){
			r=min(r, k/a[i]);
		}
	}

	printf("%d\n", r);
	return 0;
}
