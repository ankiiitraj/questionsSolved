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
const int MAXN = 300005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

int t = 1;
vi in_time(MAXN), out_time(MAXN), tree(2*MAXN), adj[MAXN], seg(4*MAXN), a(MAXN, 1);

void build(int l, int r, int node){
	if(l == r){
		seg[l] = a[tree[l]];
	}
}



void flatten_tree(int src, int par){
	tree[t] = src;
	in_time[src] = t++;
	for(auto itr: adj[src]){
		if(itr != par){
			flatten_tree(itr, src);
		}
	}
	tree[t] = src;
	out_time[src] = t++;
}


void solve(){
	int n, q, x, y, ty;
	cin >> n;

	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> q;

	flatten_tree(1, -1);

	while(q--){
		cin >> ty >> x >> y;
		if(ty == 1){

		}else{

		}
	}

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
	