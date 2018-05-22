#include <bits/stdc++.h>

using namespace std;

#define INF 99999999
#define MAXN 300

typedef pair<int,int> pii;

vector<pii> cid[MAXN];
int n, m, c, k, distancia[MAXN], processado[MAXN];

void Dijkstra(int x){

    for(int i=0 ; i<=n ; ++i){
        distancia[i]=INF;
    }
    distancia[k]=0;

    priority_queue< pii, vector<pii>, greater<pii> > fila;

    fila.push(pii(distancia[k], k));


    while(true){

        int davez=-1;

        while(!fila.empty()){

            int atual=fila.top().second;
            fila.pop();


            if(!processado[atual]){

                davez=atual;
                break;

            }

        }

        if(davez==-1){
            break;
        }
        processado[davez]=1;

        for(int i=0;i<(int)cid[davez].size();++i){

            int dist=cid[davez][i].first;
            int atual=cid[davez][i].second;

            if((davez>=0) && davez<c && (atual!=davez+1)){
                continue;
            }

            if(distancia[atual]>distancia[davez]+dist){

                distancia[atual]=distancia[davez]+dist;
                fila.push(pii(distancia[atual], atual));

            }

        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    while(cin >> n >> m >> c >> k){

        if(n==0 && m==0 && c==0 && k==0){
            break;
        }

        for(int i=0;i<m;++i){
            int u, v, p;
            cin >> u >> v >> p;
            cid[u].push_back(pii(p, v));
            cid[v].push_back(pii(p, u));
        }
        Dijkstra(k);
        cout << distancia[c-1]<<"\n";

        for(int i=0;i<n;++i){
            cid[i].clear();
            processado[i]=0;
        }
    }
    return 0;
}
