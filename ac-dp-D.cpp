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
	for(int i = 0; i < n; ++i){
		cin >> wt[i +1] >> v[i +1];
	}

	long long dp[n +1][w +1];
	memset(dp, 0, sizeof dp);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= w; ++j){
			if(wt[i] <= j){
				dp[i][j] = max(dp[i -1][j], dp[i -1][j - wt[i]] + v[i]);
			}else{
				dp[i][j] = dp[i -1][j];
			}
		}
	}

	cout << dp[n][w] << endl;


}