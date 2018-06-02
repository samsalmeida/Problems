#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXK=10010;
const ll INF=9999999999;

ll K, mat[30][30];
ll dp[30][30][MAXK];

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> K;

	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			cin >> mat[i][j];
		}
	}

	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			for(int k=1;k<=K;++k){
				dp[i][j][k]=INF;
			}
		}
	}

	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			dp[i][j][2]=mat[i][j];
		}
	}

	for(int k=3;k<=K;++k){
		for(int j=1;j<=26;++j){
			for(int i=1;i<=26;++i){
				for(int s=1;s<=26;++s){
					dp[i][j][k]=min(dp[s][i][k-1]+mat[i][j], dp[i][j][k]);
				}
			}
		}
	}

	ll resp=INF;

	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			resp=min(resp, dp[i][j][K]);
		}
	}

	cout << resp << "\n";
	return 0;
}
