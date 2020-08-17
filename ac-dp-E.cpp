#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	long long n, w;
	cin >> n >> w;
	vector<long long> v(n +1), wt(n +1);
	long long max_val = 0;
	for(int i = 0; i < n; ++i){
		cin >> wt[i +1] >> v[i +1];
		max_val += v[i +1];
	}
	long long dp[n +1][max_val +1], res = 0;

	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= max_val; ++j){
			dp[i][j] = w +1;
			dp[i][0] = 0;
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i){
		for(long long j = 1; j <= max_val; ++j){
			if(v[i] <= j){
				dp[i][j] = min(dp[i -1][j], dp[i -1][j - v[i]] + wt[i]);
			}else{
				dp[i][j] = dp[i -1][j];
			}
			if(dp[i][j] <= w)
				res = max(j, res);
		}
	}

	cout << res << endl;
}