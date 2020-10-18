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
const int MAXN = 200005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vector<vi> dp;
int rec(vi &a, int pos, bool player){
	if(pos >= a.size()){
		return 0;
	}
	if(dp[pos][player] != -1){
		return dp[pos][player];
	}
	if(!player){
		int one = INF, two = INF;
		if(pos +2 <= a.size()){
			one = rec(a, pos +2, !player) + a[pos] + a[pos +1];
		}
		two = rec(a, pos +1, !player) + a[pos];
		return dp[pos][player] = min(one, two);
	}
	int one = INF, two = INF;
	if(pos +2 <= a.size()){
		one = rec(a, pos +2, !player);
	}
	two = rec(a, pos +1, !player);
	return dp[pos][player] = min(one, two);
}

void solve(){
	int n, ans = 0;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	dp = vector<vi>(n +1, vi(2, -1));
	int res = rec(a, 0, 0);
	cout << res << endl;
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
	