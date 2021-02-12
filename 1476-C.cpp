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
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n;
	cin >> n;
	vi c(n), a(n), b(n);
	scnarr(c, n);
	scnarr(a, n);
	scnarr(b, n);

	vi dp(n, 0);
	dp[1] = abs(a[1] - b[1]) + c[1] +1;
	int res = dp[1];
	for(int i = 2; i < n; ++i){
		if(a[i] == b[i]){
			dp[i] = c[i] +1;
		}else{
			int temp = min(a[i], b[i]) -1 + c[i -1] - max(a[i], b[i]);
			dp[i] = max(
				dp[i -1] - (c[i -1] -1) + temp,
				abs(a[i] - b[i])  
			) + c[i] +1;
		}
		res = max(res, dp[i]);
	}

	
	cout << res << endl;

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
