#include <bits/stdc++.h>

using namespace std;

int const MAXN=10010, INF=0x3f3f3f3f;

typedef pair<int,int> ii;

int c, v;
vector<ii> grafo[MAXN];

int dijkstra(int x){
    ii dist[MAXN];

    memset(dist, INF, sizeof(dist));

    dist[1]=ii(0, INF);

    priority_queue< ii, vector<ii>, greater<ii> > fila;

    fila.push(ii(0, 1));
    while(!fila.empty()){

        int v=fila.top().second, d=fila.top().first;
        fila.pop();

        if(d>dist[v].first && d>dist[v].second) continue;

        for(int i=0;i<grafo[v].size();++i){
            ii u = grafo[v][i];

            if(dist[v].first+u.first<dist[u.second].second){
                dist[u.second].second=dist[v].first+u.first;
                fila.push(ii(dist[u.second].second, u.second));
            }

            if(dist[v].second+u.first<dist[u.second].first){
                dist[u.second].first=dist[v].second+u.first;
                fila.push(ii(dist[u.second].first, u.second));
            }

        }

    }

    if(dist[c].first>=INF) return -1;

    return dist[c].first;
}

int main(){

    scanf("%d %d", &c, &v);

    for(int i=0;i<v;++i){

        int u, v, D;

        scanf("%d %d %d", &u, &v, &D);

        grafo[v].push_back(ii(D, u));
        grafo[u].push_back(ii(D, v));
    }

    printf("%d\n", dijkstra(1));

    return 0;
}
