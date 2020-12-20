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
int _max;

bool isSorted(vi a){
	for(int i = 1; i < a.size(); ++i){
		if(a[i] < a[i -1]){
			return 0;
		}
	}
	return 1;
}

vector<vector<int>> dp;

int rec(int cost, int x, bool flag, int n, vi &a){
	if(flag)
		return cost;
	if(cost > n){
		return INF;
	}

	if(dp[cost][x][flag] != -1){
		return dp[cost][x][flag];
	}

	int _min = INF;

	if(isSorted(a)){
		return rec(cost, x, 1, n, a);
	}

	for(int i = 0; i < n; ++i){
		if(a[i] > x){
			swap(a[i], x);
			_min = min(_min, rec(cost +1, x, 0, n, a));
			swap(a[i], x);
		}
	}

	return dp[cost][x][flag] = _min;

}


void solve(){
	dp = vector<vector<vi>>(505, vector<vi>(505, vi(505, -1)));
	int n, x;
	cin >> n >> x;
	vi a(n);
	scnarr(a, n);
	_max = *max_element(all(a));
	int res = rec(0, x, 0, n, a);
	if(res == INF){
		cout << "-1\n";
		return;
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
