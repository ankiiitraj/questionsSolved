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
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

int n, dp[MAXN];

int recurse(int k){
	if(k == n)
		return 1;

	if(dp[k] != -1)
		return dp[k];

	int ans = 0;
	if(k + 1 <= n)
		ans = (ans + recurse(k +1)) % MOD;

	if(k + 2 <= n)
		ans = (ans + recurse(k +2)) % MOD;

	if(k + 3 <= n)
		ans = (ans + recurse(k +3)) % MOD;

	return dp[k] = ans;

}

void solve(){
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << recurse(0) << endl;
	
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
	