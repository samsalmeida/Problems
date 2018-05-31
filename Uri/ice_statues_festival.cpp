#include <bits/stdc++.h>

using namespace std;

const int MAXN=30, INF=0x3f3f3f3f;

int t;
int n, m;
int c[MAXN];

bool comp(int x, int y){
	return x>y;
}

int main(){
	scanf("%d", &t);

	for(int k=0;k<t;++k){

		scanf("%d %d", &n, &m);

		memset(c, 0, sizeof(c));
		
		vector<int> dp1, dp2;
		dp1 = vector<int> (2+m);
		dp2 = vector<int> (2+m);

		for(int i=1;i<=n;++i) scanf("%d", &c[i]);

		for(int i=0;i<=m;++i) dp1[i]=dp2[i]=INF;
		
		dp1[0]=dp2[0]=0;
		sort(c+1, c+n+1, comp);

		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){

				if(j>=c[i]){

					dp2[j]=min(dp1[j], dp2[j-c[i]]+1);
				}else{

					dp2[j]=dp1[j];
				}
			}

			dp1=dp2;
		}

		printf("%d\n", dp2[m]);
	}
	return 0;
}
