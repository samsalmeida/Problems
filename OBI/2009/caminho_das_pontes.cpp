// Pizza - Programação Nível 2 - Fase 2 - OBI 2007
// Menor Caminho - Dijkstra 
// Complexidade: O(m*log n)
// By Samyra Vitória

#include <bits/stdc++.h>
using namespace std;
     
typedef pair<int, int> pii;   
const int MAXN=1e4+10;
     
#define INFINITO 999999999
     
int n, m, dist[MAXN], proc[MAXN];
vector<pii> vis[MAXN];
     
void Dijkstra(int S){
    	
    for(int i = 1;i <=(n+1);i++) dist[i] = INFINITO; 
    dist[S] = 0;
    
    priority_queue< pii, vector<pii>, greater<pii> > row; 
    	
    row.push( pii(dist[S], S) );
    	
    while(true){ 
    		
    	int p = -1;
    	
    	while(!row.empty()){
    			
    		int a=row.top().second;
    		row.pop();
    			
    		if(!proc[a]){ 
    			p=a;
    			break;
    		}
    			
    	}
    		
    	if(p==-1) break; 
    		
    	proc[p]=true;
    		
    	for(int i=0;i<(int)vis[p].size();++i){
    			
    		int d=vis[p][i].first;
    		int a=vis[p][i].second;
    			
    			
    		if(dist[a]>dist[p]+d){  
     
    			dist[a]=dist[p]+d;   
    			row.push(pii(dist[a], a));
    		}
    	}
    }
}
     
int main(){
    	
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= m;i++){
    		
    	int x, y, t;
    	scanf("%d %d %d", &x, &y, &t);
     
    	vis[x].push_back(pii(t, y));
    	vis[y].push_back(pii(t, x));
    }
    	
    Dijkstra(0);
    cout << dist[n+1] << "\n"; 
    	
    return 0;
} 
