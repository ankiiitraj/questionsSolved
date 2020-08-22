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
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

int res = 0;

void num_paths(int src, int sink, vi adj[]){
	if(src == sink){
		res++;
	}
	for(auto itr: adj[src]){
		num_paths(itr, sink, adj);
	}
}

void solve(){
	int n, m, x, y;
	cin >> n >> m;
	int src = 1, sink = 130;
	vi adj[n +1];

	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	num_paths(1, sink, adj);
	cout << "1\n" << res +1 << endl;

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("op.txt", "r", stdin);
	freopen("ip.txt", "w", stdout);
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
	