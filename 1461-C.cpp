#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define fint double
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
const int MAXN = 100005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

/*------- sum of elements in range 1 to pos (1-Based Indexing) -------*/

void solve(){
	int n, m, x;
	fint y, res = 1.000;
	cin >> n >> m;
	vi a(n +1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}

	int idx = n;
	for(int i = n; i >= 1; --i){
		idx = i;
		if(a[i] != i)
			break;
	}
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		if(x >= idx)
			res *= (1.0 - y);
	}

	if(idx == 1){
		cout << (fint)(1.0000000) << endl;
		return;
	}

	cout << (1.0 - res) << endl;

	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	cout << fixed << setprecision(9);
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
