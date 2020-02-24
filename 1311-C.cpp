// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Perform the combo
//         		Problem Link : https://codeforces.com/contest/1311/problem/C
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t;cin >> t;while (t--) {
		int n, m;
		string s;
		cin >> n >> m >> s;
		int p[m], alpha[26] = {0}, dp[n +1][26] = {0};
		for(int i = 0; i < m; ++i)
			cin >> p[i];

		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < 26; ++j){
				if(j == s[i -1] - 'a'){
					dp[i][j] = dp[i -1][j] +1;
				}else{
					dp[i][j] = dp[i -1][j];	
				}
			}
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < 26; ++j){
				alpha[j] += dp[p[i]][j];
			}
		}
		// for(int j = 0; j < 26; ++j){
		// 	for(int i = 1; i <= n; ++i){
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		for(int i = 0; i < 26; ++i){
			alpha[i] += dp[n][i];
		}
		for(int i = 0; i < 26; ++i)
			cout << alpha[i] << " ";	
		cout << endl;
	}

	return 0;
}