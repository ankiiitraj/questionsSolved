#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
	----------------------------------------------------------------------
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 1000000; // 1e15 +5

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n +1, INF);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	vector<vi> dp(n +1, vi(k +1, INF));
	for(int i = 1; i <= n; ++i) dp[i][0] = a[i];

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if(j <= a[i])
				dp[i][j] = a[i];
			else{
				if(dp[i -1][j - a[i]] == INF){
					dp[i][j] = INF;
				}else{
					dp[i][j] = min(dp[i -1][j], dp[i -1][j - a[i]] + a[i]);
				}
			}
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	vi pref(n +1, 0);
	for(int i = 1; i <= n; ++i) pref[i] = pref[i -1] + a[i];
	for(int i = 1; i <= n; ++i){
		if(pref[i] - dp[i][k] >= k){
			cout << i << endl;
			return;
		}
	}

	cout << "-1\n";
	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
		solve();
	return 0;
}


//Author : Ankit Raj
//Problem Link :

/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/
