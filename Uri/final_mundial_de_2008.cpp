#include <bits/stdc++.h>
using namespace std;

int const MAXN = 110, INF=0x3f3f3f3f;
int n, m, c;
int mt[MAXN][MAXN][MAXN];

void debug(){
	
	for(int i=0;i<=n;++i){
		cout<< "i: " << i << "\n ";
		for(int j=1;j<=n;++j){
			cout << "j: " << j << "\n";
			for(int k=1;k<=n;++k){
				cout <<"  k: " << k << " mt: " << mt[j][k][i] << "\n";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int main() {
	int l=0;
	while(scanf("%d%d", &n, &m)!=EOF){
		memset(mt, INF, sizeof(mt));
		for(int i=0;i<m;++i){
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			mt[u][v][0]=min(d, mt[u][v][0]);
		}
		
		scanf("%d", &c);
		for(int i=0;i<=n;++i)
			for(int j=1;j<=n;++j)
				mt[j][j][i]=0;
		
		for(int k=1;k<=n;++k){
			
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					
					mt[i][j][k]=min(mt[i][j][k-1], mt[i][k][k-1]+mt[k][j][k-1]);
				}
			}
		}
		l++;
		printf("Instancia %d\n", l);
		for(int i=1;i<=c;++i){
			int u, v, t;
			scanf("%d%d%d", &u, &v, &t);
			
			if(mt[u][v][t]==INF) printf("-1\n");
			else printf("%d\n", mt[u][v][t]);
		}
		printf("\n");
		//debug();
		
	}
	return 0;
}
