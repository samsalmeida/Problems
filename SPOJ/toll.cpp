#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100
 
typedef pair<int, int> ii;
int c, e, l, p, comp[MAXN];
 
vector<int> v[MAXN];
set<int> resp;
void d(int x){
 
  queue<ii> row;
  row.push(ii(x, 0));
 
  while(true){
    
    int node=-1;
    int dist=0;
    while(!row.empty()){
      
      int a=row.front().first;
      int d=row.front().second;
      row.pop();
      
      if(!comp[a]){
        comp[a]=1;
        resp.insert(a);
        node=a;
        dist=d;
        break;
      }
    }
    if(node==-1) break;
    comp[node]=1;
    
    for(int i=0;i<v[node].size();++i){
      
      int u=v[node][i];
      
      if(dist+1<=p){
        resp.insert(u);
        row.push(ii(u, dist+1));
      }
    }
  }
 
}
 
 
int main(){
 
  int cont=1;
  while(scanf("%d %d %d %d", &c, &e, &l, &p) && c && e && l && p){
   
    for(int i=0;i<e;++i){
      int u, w;
      scanf("%d %d", &u, &w);

      v[u].push_back(w);
      v[w].push_back(u);
    }
    memset(comp, 0, sizeof(comp));
    
    d(l);
    printf("Teste %d\n", cont);

    if(resp.find(l)!=resp.end()) resp.erase(l);
    for(set<int>::iterator it=resp.begin(); it!=resp.end(); ++it){
      printf("%d ", *it);
    }
    printf("\n\n");

    for(int i=1;i<=c;++i){
      v[i].clear();
    }
    resp.clear();
    cont++;
  }
  return 0;
}
