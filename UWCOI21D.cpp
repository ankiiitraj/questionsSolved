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

void solve(){
	int n, m, k, xi, yi, xf, yf, res = 0;
	cin >> n >> m >> k;

	if(k <= 10){
		vector<vi> q(k, vi(4));
		for(int i = 0; i < k; ++i){
			for(int j = 0; j < 4; ++j)
				cin >> q[i][j];
		}
		int cur = INF;
		for(int i = 1; i <= m; ++i){
			int cur_res = 0;
			for(int j = 0; j < k; ++j){
				xi = q[j][0], yi = q[j][1], xf = q[j][2], yf = q[j][3];
				cur_res += min(
					abs(xi - xf) + 2 * (abs(yf - i) + abs(yi - i)),
					2 * abs(xi - xf) + 2 * (abs(yf - yi))
				);	
			}
			cur = min(cur, cur_res);
		}

		res = cur;
	}else{
		for(int i = 0; i < k; ++i){
			cin >> xi >> yi >> xf >> yf;
			res += (2 * abs(yf - yi) + abs(xi - xf));
		}
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
