#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	string s, t, ans;
	cin >> s >> t;
	int n = s.length(), m = t.length();

	int dp[n +1][m +1];
	memset(dp, 0, sizeof dp);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(s[i -1] == t[j -1]){
				dp[i][j] = 1 + dp[i -1][j -1];
			}else{
				dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
			}
		}
	}

	int i = n, j = m;
	while(i > 0 and j > 0){	
		if(s[i -1] == t[j -1]){
			ans += s[i -1];
			--i, --j;
		}else if(dp[i -1][j] > dp[i][j -1]){
			--i;
		}else{
			--j;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}