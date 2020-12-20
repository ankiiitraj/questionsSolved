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
	int n, m, sum = 0, _min = INF, zero_flag = 0, cnt = 0;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j){
	 		cin >> a[i][j];
	 		if(a[i][j] == 0)
	 			zero_flag = 1;
	 		if(a[i][j] < 0)
	 			cnt++;
	 		_min = min(_min, abs(a[i][j]));
	 		sum += abs(a[i][j]);
		}
	}

	if(zero_flag){
		cout << sum << endl;
	}else if(cnt % 2 == 0){
		cout << sum << endl;
	}else{
		cout << sum - 2* _min << endl;
	}

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
