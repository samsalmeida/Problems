#include <bits/stdc++.h>

using namespace std;

int n;
map<string, bool> ok;

int main(){
	cin >> n;

	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		ok[s]=true;
	}
	cout << 6-n << "\n";
	if(!ok["purple"]){
		cout << "Power\n";
	}
	if(!ok["green"]){
		cout << "Time\n";
	}
	if(!ok["blue"]){
		cout << "Space\n";
	}
	if(!ok["orange"]){
		cout << "Soul\n";
	}
	if(!ok["red"]){
		cout << "Reality\n";
	}
	if(!ok["yellow"]){
		cout << "Mind\n";
	}
	return 0;
}
