#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 100005; // 1e5 +5

int power(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x)%MOD;
			--y;
		}else{
			x = (x * x)%MOD;
			y /= 2;
		}
	}
	return ans;
}
inline int add(int a, int b){
	return (a + b) % MOD;
}
inline int multiply(int a, int b){
	return (a * b) % MOD;
}
inline int subs(int a, int b){
	return ((a - b % MOD) + MOD) % MOD;
}
int divide(int a, int b){
	return (a * (power(b, MOD -2))) % MOD;
}

struct node{
	int sum, dep;
	vi freq;
};
node tree_nodes[MAXN];
vi a(MAXN), adj[MAXN], depth(MAXN, 0), fact(MAXN, 0);
int  up[MAXN][22];
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

void dfs(int u, int par, int dep){
	visited[u] = 1;
	tree_nodes[u].freq.assign(31, 0);
	tree_nodes[u].dep = dep;
	if(par != -1){
		tree_nodes[u].sum = add(tree_nodes[par].sum, a[u]);
		for(int i = 0; i < 31; ++i){
			tree_nodes[u].freq[i] = tree_nodes[par].freq[i] + tree_nodes[u].freq[i];
			if(a[u]&(1<<i))
				tree_nodes[u].freq[i]++;
		}
	}
	else{
		tree_nodes[u].sum = a[u] % MOD;
		for(int i = 0; i < 31; ++i){
			if(a[u]&(1<<i)){
				tree_nodes[u].freq[i]++;
			}
		}
	}

	for(auto itr: adj[u]){
		if(!visited[itr]){
			dfs(itr, u, dep +1);
		}
	}
}

void fact_init(){
	fact[0] = 1;
	for(int i = 1; i < MAXN; ++i){
		fact[i] = multiply(fact[i -1], i);
	}
}

int nCr(int n, int r){
	int num = fact[n];
	int deno = multiply(fact[n - r], fact[r]);
	return divide(num, deno);
}

void solve(){
	fact_init();
	int n, q, x, y, ty;
	cin >> n;
	scnarr(a, n);
	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	init_binary_lifting(1, -1, 0);
	cin >> q;
	memset(visited, 0, sizeof(visited));
	dfs(1, -1, 1);
	while(q--){
		cin >> ty >> x >> y;
		if(ty == 1){
			int l = lca(x, y);
			cout << add(subs(add(tree_nodes[x].sum, tree_nodes[y].sum), multiply(2, tree_nodes[l].sum)), a[l]) << endl;
		}else if(ty == 2){
			vi freq(31, 0);
			int l = lca(x, y), res = 0, len = tree_nodes[x].dep + tree_nodes[y].dep - 2*tree_nodes[l].dep +1;
			for(int i = 0; i < 31; ++i){
				freq[i] = tree_nodes[x].freq[i] + tree_nodes[y].freq[i] - 2*tree_nodes[l].freq[i];
				if(a[l]&(1<<i)){
					freq[i]++;
				}
				if(freq[i] > 0 and len > 1){
					int temp = subs(nCr(len, 2), (len - freq[i] > 1 ? nCr(len - freq[i], 2) : 0));
					res = add(res, multiply((1<<i), temp));
				}
			}
			cout << res << endl;

		}else if(ty == 3){
			vi freq(31, 0);
			int l = lca(x, y), res = 0, len = tree_nodes[x].dep + tree_nodes[y].dep - 2*tree_nodes[l].dep +1;
			for(int i = 0; i < 31; ++i){
				freq[i] = tree_nodes[x].freq[i] + tree_nodes[y].freq[i] - 2*tree_nodes[l].freq[i];
				if(a[l]&(1<<i)){
					freq[i]++;
				}
				if(freq[i] > 0 and len > 2){
					int temp = subs(nCr(len, 3), (len - freq[i] > 2 ? nCr(len - freq[i], 3) : 0));
					res = add(res, multiply((1<<i), temp));
				}
			}
			cout << res << endl;

		}else{
			vi freq(31, 0);
			int l = lca(x, y), res = 0, len = tree_nodes[x].dep + tree_nodes[y].dep - 2*tree_nodes[l].dep +1;
			for(int i = 0; i < 31; ++i){
				freq[i] = tree_nodes[x].freq[i] + tree_nodes[y].freq[i] - 2*tree_nodes[l].freq[i];
				if(a[l]&(1<<i)){
					freq[i]++;
				}
				if(freq[i] > 0 and len > 3){
					int temp = subs(nCr(len, 4), (len - freq[i] > 3 ? nCr(len - freq[i], 4) : 0));
					res = add(res, multiply((1<<i), temp));
				}
			}
			cout << res << endl;

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
	