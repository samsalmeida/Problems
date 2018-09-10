// Edit Distance - SPOJ
// Complexity: O(n²)
// By Samyra Vitória

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN=2e3+10;
 
int t;
int dp[MAXN][MAXN];
int main(){
	cin >> t;
 
	while(t--){
 
		string s1, s2;
		cin >> s1 >> s2;
 
		memset(dp, 0, sizeof dp);
 
		for(int i=1;i<=s1.size();++i){
			dp[0][i]=i;
		}
		for(int i=1;i<=s2.size();++i){
			dp[i][0]=i;
		}
		for(int i=1;i<=s1.size();++i){
			for(int j=1;j<=s2.size();++j){
				dp[i][j]=min(dp[i-1][j-1]+(s1[i-1]!=s2[j-1]), 1+ min(dp[i-1][j], dp[i][j-1]));
			}
		}
		printf("%d\n", dp[s1.size()][s2.size()]);
	}
	return 0;
}
