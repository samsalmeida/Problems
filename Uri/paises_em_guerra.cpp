#include <bits/stdc++.h>
using namespace std;

int const MAXN = 510, INF=0x3f3f3f3f;
int n, m, e, mt[MAXN][MAXN];

int main() {
	
    while(scanf("%d%d", &n, &m) && !(n==0 && m==0)){
        memset(mt, INF, sizeof(mt));
	
        for(int i=0;i<m;++i){
            int u, v;
            scanf("%d%d", &u, &v);
            scanf("%d", &mt[u][v]);			
            if(mt[v][u]!=INF)  mt[v][u]=mt[u][v]=0;
        }		
        scanf("%d", &e);		
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    mt[i][j]=min(mt[i][j], mt[i][k]+mt[k][j]);
                }
            }
        }		
        for(int i=1;i<=e;++i){
            int u, v;
            scanf("%d%d", &u, &v);
            if(mt[u][v]!=INF) printf("%d\n", mt[u][v]);
            else printf("Nao e possivel entregar a carta\n");
        }		
        printf("\n");
    }
    return 0;
}
