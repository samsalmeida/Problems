#include <bits/stdc++.h>
using namespace std;

const int MAXN=550, INF=0x3f3f3f3f;
typedef pair<int, int> ii;

struct point{
    int x, y, D;
};

int n, m;
int dist[MAXN], dist_[MAXN];
int check[MAXN], check_[MAXN];

point ed[10010];
map<ii, bool> del;
vector<ii> graph[MAXN], graph_[MAXN];

void dijkstra(int u){
    
    memset(dist, INF, sizeof(dist));
    memset(check, 0, sizeof(check));
    
    dist[u]=0;
    priority_queue<ii> row;
    
    row.push(ii(0, u));
    
    while(true){
        
        int node=-1;
        
        while(!row.empty()){
            
            int a=row.top().second;
            row.pop();
            
            if(!check[a]){
                node=a;
                break;
            }
        }
        
        if(node==-1) break;
        
        check[node]=1;
        
        for(int i=0;i<graph[node].size();++i){
            
            int DIST=graph[node][i].first;
            int no=graph[node][i].second;
            
            if(dist[node]+DIST<dist[no] && del[ii(node, no)]==false){
                
                dist[no]=dist[node]+DIST;
                row.push(ii(-dist[no], no));
            }
        }
    }
}

void dijkstra_(int u){
    
    memset(dist_, INF, sizeof(dist_));
    memset(check_, 0, sizeof(check_));
    dist_[u]=0;
    priority_queue<ii> row;
    
    row.push(ii(0, u));
    
    while(true){
        
        int node=-1;
        
        while(!row.empty()){
            
            int a=row.top().second;
            row.pop();
            
            if(!check_[a]){
                node=a;
                break;
            }
        }
        
        if(node==-1) break;
        
        check_[node]=1;
        
        for(int i=0;i<graph_[node].size();++i){
            
            int DIST=graph_[node][i].first;
            int no=graph_[node][i].second;
            
            if(dist_[node]+DIST<dist_[no]){
                
                dist_[no]=dist_[node]+DIST;
                row.push(ii(-dist_[no], no));
            }
        }
    }
    
}

int main(){
    
    while(scanf("%d%d", &n, &m) && !(n==0 && m==0)){
        
        int s, c;
        scanf("%d%d", &s, &c);
        
        for(int i=1;i<=m;++i){
            
            scanf("%d%d%d", &ed[i].x, &ed[i].y, &ed[i].D);

            graph[ed[i].x].push_back(ii(ed[i].D, ed[i].y));
            graph_[ed[i].y].push_back(ii(ed[i].D, ed[i].x));
        }
        
        dijkstra(s);
        dijkstra_(c);
        
        for(int i=1;i<=m;++i){
            int u=ed[i].x;
            int v=ed[i].y;
            int w=ed[i].D;
            if(dist[u]+dist_[v]+w==dist[c]){
                del[ii(u, v)]=true;
            }
        }
        
        dijkstra(s);
        if(dist[c]==INF) printf("-1\n");
        else printf("%d\n", dist[c]);
        for(int i=0;i<n;++i){
            graph_[i].clear();
            graph[i].clear();
        }
        del.clear();
    }
    
    return 0;
}
