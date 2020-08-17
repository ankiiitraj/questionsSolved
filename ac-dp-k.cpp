#include <bits/stdc++.h>
using namespace std;

int solve(int k, bool turn, int n, vector<int> &a, vector<vector<int>> &dp){
	if(k == 0)
		return !turn;
	if(dp[k][turn] != -1)
		return dp[k][turn];

	bool res;
	if(turn){
		res = 0;
		for(int i = 1; i <= n; ++i){
			if(k - a[i] >= 0)
				res = res | solve(k - a[i], !turn, n, a, dp);
		}
	}else{
		res = 1;
		for(int i = 1; i <= n; ++i){
			if(k - a[i] >= 0)
				res = res & solve(k - a[i], !turn, n, a, dp);
		}
	}
	return dp[k][turn] = res;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;

	 vector<vector<int>> dp(k +1, vector<int>(2, -1));

	vector<int> a(n +1);
	for(int i = 0; i < n; ++i){
		cin >> a[i +1];
	}
	solve(k, 1, n, a, dp) ? puts("First") : puts("Second");
}