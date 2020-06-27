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
const int MAXN = 100005; // 1e6 +5

int k, dp[MAXN];

int recurse(int n){
	if(n == 0)
		return 1;
	if(dp[n] != -1)
		return dp[n];

	int ans = 0;
	if(n >= k){
		ans = (ans + recurse(n - k)) % MOD;
	}
	if(n > 0){
		ans = (ans + recurse(n -1)) % MOD;
	}

	return (dp[n] = ans);
}


signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif

	int t;
	cin >> t >> k;
	int a, b;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i < 100001; ++i){
		dp[i] = recurse(i);
	}
	for(int i = 1; i < 100001; ++i){
		dp[i] = (dp[i] + dp[i -1]) % MOD;
	}

	while(t--){
		cin >> a >> b;
		cout << ((MOD + dp[b] - dp[a -1])) % MOD << endl;
	}
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
	