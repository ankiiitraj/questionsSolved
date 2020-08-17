#include<bits/stdc++.h>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int dp[n +1] = {0};
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);
	for(int i = 2; i < n; ++i){
		dp[i] = min(abs(a[i -1] - a[i]) + dp[i -1], abs(a[i -2] - a[i]) + dp[i -2]);
	}

	cout << dp[n -1] << endl;
}
