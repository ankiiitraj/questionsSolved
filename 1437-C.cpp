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
const int MAXN = 405; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

int dp[205][405];

int rec(int pos, int t, int n, vi &a){
	if(pos > n)
		return 0;
	if(t > 2*n)
		return INF;
	if(dp[pos][t] != -1)
		return dp[pos][t];
	return dp[pos][t] = min(rec(pos, t +1, n, a), rec(pos +1, t +1, n, a) + abs(a[pos] - t));
}

void solve(){
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;
	vi a(n +1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	sort(all(a));

	bitset<MAXN> done(0);
	cout << rec(1, 1, n, a) << endl;

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
