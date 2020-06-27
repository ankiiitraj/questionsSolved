#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 100000000; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

int k1_max, k2_max, dp[101][101][11][11];

int recurse(int n1, int n2, int k1, int k2){
	if(n1 + n2 == 0)
		return 1;

	if(dp[n1][n2][k1][k2] != -1)
		return dp[n1][n2][k1][k2];

	int ans = 0;
	if(n1 > 0 and k1 > 0)
		ans = (ans + recurse(n1 -1, n2, k1 -1, k2_max)) % MOD;
	if(n2 > 0 and k2 > 0)
		ans = (ans + recurse(n1, n2 -1, k1_max, k2 -1)) % MOD;

	return dp[n1][n2][k1][k2] = ans;
}

void solve(){
	int n1, n2, k1, k2;
	memset(dp, -1, sizeof(dp));
	cin >> n1 >> n2 >> k1 >> k2;
	k1_max = k1;
	k2_max = k2;

	cout << recurse(n1, n2, k1, k2);
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
	