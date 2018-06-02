#include <bits/stdc++.h>

using namespace std;

//typedef long long ll;
const int MAXN=1010;

int n, m, v[MAXN];

int main(){
	scanf("%d%d", &n, &m);

	for(int i=1;i<=m;++i){
		scanf("%d", &v[i]);
	}
	int r=0x3f3f3f3f;
	sort(v+1,v+m+1);
      n--;
	for(int i=1;i<=(m-n);++i){
		r=min(v[n+i]-v[i], r);
	}
    printf("%d\n", r);
	return 0;
}
