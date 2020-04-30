#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int32_t main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	// int t; cin >> t; while(t--)
	{
		int n, q, l, r;
		string s;
		cin >> n >> s >> q;
		int pre[n +1][26];
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < 26; ++j){
				pre[i][j] = pre[i -1][j];
			}
			if(s[i -1] <= 'Z'){
				pre[i][s[i -1] - 'A']++;
			}else{
				pre[i][s[i -1] - 'a']++;
			}
		}
		
		int ans;
		while(q--){
			cin >> l >> r; ++l, ++r;
			int temp[26] = {0};
			for(int i = 0; i < 26; ++i){
				temp[i] = pre[r][i] - pre[l -1][i];
				if(temp[i] > 0){
					ans = temp[i];
				}
			}
			cout << ans << endl;

		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	