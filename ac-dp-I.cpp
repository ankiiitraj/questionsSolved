#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	vector<double> a(n +1);
	scnarr(a, n);

	double dp[n +1][n +1];
	memset(dp, 0.0, sizeof dp);
	dp[0][0] = 1.0;
	for(int i = 1; i <= n; ++i){
		dp[i][0] = dp[i -1][0] * (1 - a[i]);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			dp[i][j] = dp[i -1][j -1]*a[i] + dp[i -1][j]*(1 - a[i]);
		}
	}

	double ans = 0.0;

	for(int i = n/2 +1; i <= n; ++i){
		ans += dp[n][i];
	}

	cout << ans << endl;
	
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
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
	