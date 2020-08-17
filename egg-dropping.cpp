#include<bits/stdc++.h>
using namespace std;

int dp[15][55];
int solve(int n, int k){
	if(k == 1 or k == 0){
		return k;
	}else if(n == 1){
		return k;
	}
	if(dp[n][k] != -1)
		return dp[n][k];

	int res = INT_MAX;
	for(int i = 2; i < k; ++i){
		res = min(res, max(solve(n -1, i -1) +1, solve(n, k - i) +1));
	}
	return dp[n][k] = res;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		memset(dp, -1, sizeof dp);
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}