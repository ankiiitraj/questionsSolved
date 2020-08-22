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
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 200005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vi size, arr, w;

void init(int n){
	for(int i = 1; i <= n; ++i){
		size[i] = 1;
		arr[i] = i;
	}
	return;
}

int find(int u){
	if(arr[u] == u){
		return u;
	}

	return arr[u] = find(arr[u]);
}

void _union(int u, int v){
	if(size[u] > size[v]){
		size[u] += size[v];
		arr[v] = u;
	}else{
		size[v] += size[u];
		arr[u] = v;
	}
	return;
}

bool parity_check(int x){
	return (__builtin_popcount(x)&1);
}

void solve(){
	int n, m, q, x, y, ty;
	cin >> n >> m;
	size.assign(n +5, 1);
	arr.resize(n +5);
	w.resize(n +5);
	init(n);
	for(int i = 1; i <= n; ++i){
		cin >> w[i];
	}

	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		if(parity_check(w[x]) == parity_check(w[y])){
			x = find(x);
			y = find(y);
			if(x != y){
				_union(x, y);
			}
		}
	}
	int odd = 0, even = 0;
	for(int i = 1; i <= n; ++i){
		if(parity_check(w[i])){
			odd = max(odd, size[i]);
		}else{
			even = max(even, size[i]);
		}
	}

	cin >> q;
	while(q--){
		cin >> ty >> x;
		if(ty&1){
			if(parity_check(x)){
				cout << even << endl;
			}else{
				cout << odd << endl;
			}
		}else{
			if(parity_check(x)){
				cout << odd << endl;
			}else{
				cout << even << endl;
			}
		}
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
	