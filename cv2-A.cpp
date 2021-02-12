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


int helper(int n, int cur, vi &dp){
	if(cur == n) return 1;

	if(dp[cur] != -1)
		return dp[cur];

	int one = 0, two = 0, three = 0;

	if(cur +1 <= n) one = helper(n, cur +1, dp);
	if(cur +2 <= n) two = helper(n, cur +2, dp);
	if(cur +3 <= n) three = helper(n, cur +3, dp);

	return dp[cur] = one + two + three;
}

void solve(){
	int n;
	cin >> n;
	vi dp(n +2, -1);
	cout << helper(n +1, 0, dp);


	return;
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	int t; cin >> t; while(t--){
		solve();
		if(t != 0) cout << endl;
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
