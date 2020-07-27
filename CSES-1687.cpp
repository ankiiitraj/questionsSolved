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
const int MAXN = 2000005; // 1e6 +5

vi a(MAXN), adj[MAXN],depth(MAXN, 0);
int up[MAXN][22];
bool visited[MAXN];

int lift(int u, int d){
	if(d == 0 or u == -1){
		return u;
	}

	for(int i = 20; i >= 0; --i){
		if(d >= (1<<i)){
			return lift(up[u][i], d - (1<<i));
		}
	}
	return -1;
}

void init_binary_lifting(int u, int par, int d){
	up[u][0] = par;
	for(int i = 1; i <= 20; ++i){
		if(up[u][i -1] != -1){
			up[u][i] = up[up[u][i -1]][i -1];
		}else{
			up[u][i] = -1;
		}
	}
	depth[u] = d;
	visited[u] = 1;
	for(auto itr: adj[u]){
		if(!visited[itr]){
			init_binary_lifting(itr, u, d +1);
		}
	}
}

int lca(int u, int v){
	if(depth[u] != depth[v]){
		if(depth[u] > depth[v]){
			u = lift(u, depth[u] - depth[v]);
		}else{
			v = lift(v, depth[v] - depth[u]);
		}
	}

	if(u == v)
		return u;

	for(int i = 20; i >= 0; --i){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}	
	}
	return up[u][0];
}


void solve(){
	int n, q, x, y;
	cin >> n >> q;
	memset(visited, 0, sizeof(visited));
	for(int i = 2; i <= n; ++i){
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	memset(up, -1, sizeof(up));
	init_binary_lifting(1, -1, 0);
	while(q--){
		cin >> x >> y;
		cout << lift(x, y) << endl;
	}
	
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
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
	