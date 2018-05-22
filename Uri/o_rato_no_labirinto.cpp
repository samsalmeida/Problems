#include <bits/stdc++.h>

using namespace std;

const int MAXN=4040, INF=0x3f3f3f3f;

int p, l, c;
int dist[MAXN];
bool vis[MAXN];

vector<int> graph[MAXN];
map<string, int> point;

void bfs(int u){
	
	memset(dist, -1, sizeof(dist));
	
	queue<int> row;
	dist[u]=0;
	row.push(u);

	while(!row.empty()){

		int node=row.front();
		row.pop();
		for(int i=0;i<graph[node].size();++i){

			int v=graph[node][i];

			if(dist[v]==-1){
				dist[v]=dist[node]+1;
				row.push(v);
			}
		}
	}
}

int main(){
	
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> p >> l;
	//cout << p << " " << l << "\n";
	for(int i=0;i<l;++i){

		string a, b;
		cin >> a >> b;
		if(point.find(a)==point.end()){
			c++;
			point[a]=c;
		}
		
		if(point.find(b)==point.end()){
			c++;
			point[b]=c;
		}
		
		graph[point[a]].push_back(point[b]);
		graph[point[b]].push_back(point[a]);

	}
	int resp=0;
	bfs(point["Entrada"]);
	resp=dist[point["*"]];
	bfs(point["*"]);
	cout << resp+dist[point["Saida"]] << "\n";
	return 0;
}
