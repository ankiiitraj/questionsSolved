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


int n, dp[3001][3001];

int recurse(vii &a, int pos, int prev_fixed){
	if(pos >= n)
		return 0;

	if(dp[pos][prev_fixed] != -1)
		return dp[pos][prev_fixed];

	return dp[pos][prev_fixed] = min(recurse(a, pos +1, prev_fixed) + a[pos].first - a[prev_fixed].first, recurse(a, pos +1, pos) + a[pos].second);

}

void solve(){
	cin >> n;
	vii a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(all(a));
	memset(dp, -1, sizeof(dp));
	cout << recurse(a, 1, 0) + a[0].second << endl;

	
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
	