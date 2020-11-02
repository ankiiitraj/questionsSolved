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

int max_dep, node;

void dfs(int s, int par, int dep, vi adj[]){
	if(dep > max_dep){
		node = s;
		max_dep = dep;
	}
	for(auto itr :adj[s]){
		if(itr != par){
			dfs(itr, s, dep +1, adj);
		}
	}
}

void solve(){
	int n, u, v;
	cin >> n;
	vi adj[n +1];
	for(int i = 0; i < n -1; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	node = 1, max_dep = 0;
	dfs(1, -1, 0, adj);
	max_dep = 0;
	dfs(node, -1, 0, adj);
	
	if(max_dep &1){
		cout << (int)(max_dep/2 +1) << endl;
	}else{
		cout << (int)(max_dep/2) << endl;
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
