#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;
bool solve(string a, string b){
	if(a == b){
		return 1;
	}else if(a.length() == 1){
		return 0;
	}
	string key = a + '!' + b;
	if(dp.find(key) != dp.end())
		return dp[key];
	bool res = 0;
	for(int k = 0; k < a.length() -1; ++k){
		bool one = (solve(a.substr(0, k +1), b.substr(0, k +1)) and solve(a.substr(k +1, a.length() - k -1), b.substr(k +1, b.length() - k -1)));
		bool two = (solve(a.substr(a.length() - k -1, k +1), b.substr(0, k +1)) and solve(a.substr(0, a.length() - k -1), b.substr(k +1, a.length() - k -1)));
		res = (res or (one or two));
	}

	return dp[key] = res;

}


int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		dp.clear();
		string a, b;
		cin >> a >> b;
		int n = a.length();
		cout << (solve(a, b) ? "True" : "False") << endl;
	}
}