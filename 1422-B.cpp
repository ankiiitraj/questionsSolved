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

pii calc(vector<vi> &a, int i, int j, int n, int m){
	if(
		min({
				abs(a[i][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[i][j] - a[n - i -1][m - j -1]),
				abs(a[i][j] - a[i][m - j -1]) + abs(a[i][m - j -1] - a[n - i -1][j]) + abs(a[i][m - j -1] - a[n - i -1][m - j -1]),
				abs(a[n - i -1][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[n - i -1][j] - a[n - i -1][m - j -1]),
				abs(a[n - i -1][m - j -1] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][m - j -1]) + abs(a[n - i -1][m - j -1] - a[n - i -1][j])}
		) == abs(a[i][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[i][j] - a[n - i -1][m - j -1])

	){
		return {abs(a[i][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[i][j] - a[n - i -1][m - j -1]), a[i][j]};
	}else if(
		min(
		{abs(a[i][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[i][j] - a[n - i -1][m - j -1]),
				abs(a[i][j] - a[i][m - j -1]) + abs(a[i][m - j -1] - a[n - i -1][j]) + abs(a[i][m - j -1] - a[n - i -1][m - j -1]),
				abs(a[n - i -1][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[n - i -1][j] - a[n - i -1][m - j -1]),
				abs(a[n - i -1][m - j -1] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][m - j -1]) + abs(a[n - i -1][m - j -1] - a[n - i -1][j])}
		) == abs(a[i][j] - a[i][m - j -1]) + abs(a[i][m - j -1] - a[n - i -1][j]) + abs(a[i][m - j -1] - a[n - i -1][m - j -1])

	){
		return {abs(a[i][j] - a[i][m - j -1]) + abs(a[i][m - j -1] - a[n - i -1][j]) + abs(a[i][m - j -1] - a[n - i -1][m - j -1]), a[i][m - j -1]};
	}else if(
		min(
		{abs(a[i][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[i][j] - a[n - i -1][m - j -1]),
				abs(a[i][j] - a[i][m - j -1]) + abs(a[i][m - j -1] - a[n - i -1][j]) + abs(a[i][m - j -1] - a[n - i -1][m - j -1]),
				abs(a[n - i -1][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[n - i -1][j] - a[n - i -1][m - j -1]),
				abs(a[n - i -1][m - j -1] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][m - j -1]) + abs(a[n - i -1][m - j -1] - a[n - i -1][j])}
		) == abs(a[n - i -1][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[n - i -1][j] - a[n - i -1][m - j -1])
	){
		return {abs(a[n - i -1][j] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][j]) + abs(a[n - i -1][j] - a[n - i -1][m - j -1]), a[n - i -1][j]};
	}else{
		return {abs(a[n - i -1][m - j -1] - a[i][m - j -1]) + abs(a[i][j] - a[n - i -1][m - j -1]) + abs(a[n - i -1][m - j -1] - a[n - i -1][j]), a[n - i -1][m - j -1]};
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}

	int ans = 0;

	for(int i = 0; i < n/2; ++i){
		for(int j = 0; j < m/2; ++j){
			pii temp = calc(a, i, j, n, m);
			ans += temp.first;
			a[i][j] = a[i][m - j -1] = a[n - i -1][j] = a[n - i -1][m - j -1] = temp.second;
		}
	}

	if(n&1){
		for(int j = 0; j < m/2; ++j){
			ans += abs(a[n/2][j] - a[n/2][m - j -1]);
		}
	}

	if(m&1){
		for(int i = 0; i < n/2; ++i){
			ans += abs(a[i][m/2] - a[n - i -1][m/2]);
		}
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
	