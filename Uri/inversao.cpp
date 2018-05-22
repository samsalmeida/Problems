#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;
const int MAXN=100100;

int t, a, b;
int ck[MAXN];

int rev(int a){

	int reversed=0, ut=0;

	while(a!=0){

		ut=(a%10);
		reversed= reversed*10 +ut;
		a=a/10;
	}

	return reversed;
}

int bfs(int a, int b){

	queue<pii> row;
	row.push(pii(a, 0));

	while(!row.empty()){

		pii at=row.front();
		row.pop();

		if(at.F==b) return at.S;
		
		int r=rev(at.F);

		if(!ck[r]){
			row.push(pii(r, at.S+1));
			ck[r]=1;
		}

		if(!ck[at.F+1]){
			row.push(pii(at.F+1, at.S+1));
			ck[at.F+1]=1;
		}
	}
}

int main(){
	
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> t;

	for(int i=0;i<t;++i){
		memset(ck, 0, sizeof(ck));
		
		cin >> a >> b;

		cout << bfs(a, b) << "\n";
	}
	return 0;
}
