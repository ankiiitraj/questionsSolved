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

int dfs(int src, int par, vi adj[], map<pii,int> &edge_freq, int n){
	int cnt = 0;
	for(auto itr: adj[src]){
		if(itr != par){
			int cur = dfs(itr, src, adj, edge_freq, n);
			edge_freq[{min(itr, src), max(itr, src)}] = cur*(n - cur);
			cnt += cur;
		}
	}
	return cnt +1;
}

void solve(){
	int n, m, x, y, res = 0;
	cin >> n;
	vi adj[n +1];
	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> m;
	vi p(m), new_vals;
	for(int i = 0; i < m; ++i){
		cin >> p[i];
	}
	if(m < n -1){
		while(m < n -1){
			p.push_back(1);
			++m;
		}
	}else{
		vi new_p = p;
		p.clear();
		sort(all(new_p));
		for(int i = 0; i < n -2; ++i){
			p.push_back(new_p[i]);
		}
		int new_num = 1;
		for(int i = n -2; i < m; ++i){
			new_num = new_num * new_p[i] % MOD;
		}

		p.push_back(new_num);
	}
	
	map<pii, int> edge_freq;
	dfs(1, -1, adj, edge_freq, n);

	for(auto itr: edge_freq){
		new_vals.push_back(itr.second);
	}
	sort(all(new_vals));
	sort(all(p));
	
	for(int i = 0; i < n -1; ++i){
		res = (res + (new_vals[i]*p[i] % MOD))%MOD;
	}
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
	