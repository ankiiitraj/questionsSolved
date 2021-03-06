#include <bits/stdc++.h>
#include <time.h>
// #define int long long int
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
const int INF = 1000000005; // 1e15 +5
int _max;

vector<vector<int>> dp;

int rec(int cost, int pos, int x, int n, vi &a){
	if(pos == n){
		if(is_sorted(all(a)))
			return cost;
		return INF;
	}
	if(dp[pos][x] != -1)
		return dp[pos][x];

	int two = INF;
	if(a[pos] > x){
		swap(a[pos], x);
		two = rec(cost +1, pos +1, x, n, a);
		swap(a[pos], x);
	}
	int one = rec(cost, pos +1, x, n, a);
	dp[pos][x] = min(one, two);
	return dp[pos][x];
}


void solve(){
	dp = vector<vi>(505, vi(505, -1));
	int n, x;
	cin >> n >> x;
	vi a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	_max = *max_element(all(a));
	int res = rec(0, 0, x, n, a);
	if(res > n){
		cout << "-1\n";
		return;
	}

	cout << res << endl;

	return;
}

int main()
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
