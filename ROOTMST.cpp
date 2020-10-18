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
const int MAXN = 500005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

// took from https://cp-algorithms.com/graph/mst_prim.html

struct Edge {
    int w, to, from;
    bool operator<(Edge const& other) const {
        return w < other.w;
    }
};

vi head, size;

void dsu_init(int n){
	head = vi(n +1);
	size = vi(n +1, 1);

	for(int i = 1; i <= n; ++i)
		head[i] = i;

	return;
}

int find(int x){
	while(head[x] != x){
		head[x] = head[head[x]];
		x = head[x];
	}
	return x;
}

void _union(int u, int v){
	u = find(u);
	v = find(v);
	if(size[v] > size[u]){
		swap(u, v);
	}
	size[u] += size[v];
	size[v] = 0;
	head[v] = u;

	return;
}

int calc(int n, int fre, vector<Edge> &edges, vii &e1){
	int res = INF;
	string init, cur;
	for(int i = 0; i < n - fre; ++i)
		init += '0';
	for(int i = 0; i < fre; ++i)
		init += '1';

	while(cur != init){
		if(cur == ""){
			cur = init;
		}

		dsu_init(n +1);

		int cur_wts = 0;
		for(int i = 0; i < n; ++i){
			if(cur[i] == '1'){
				_union(1, e1[i].second);
				cur_wts += e1[i].first;
			}
		}

		for(auto itr: edges){
			if(find(itr.from) != find(itr.to)){
				cur_wts += itr.w;
				_union(itr.from, itr.to);
			}
		}

		res = min(res, cur_wts);
		next_permutation(all(cur));
	}

	return res;
}

void solve(){
	int n, m, u, v, w;
	cin >> n >> m;
	vii e1;
	vector<Edge> edges;
	for(int i = 0; i < m; ++i){
		cin >> u >> v >> w;
		if(min(u, v) == 1){
			e1.push_back({w, max(u, v)});
		}else{
			edges.push_back({w, u, v});
		}
	}

	vi wts(n);

	sort(all(edges));
	
	for(int i = 1; i <= n -1; ++i){
		wts[i] = calc(n -1, i, edges, e1);
		cout << wts[i] << " ";
	}
	cout << endl;

	// debug(wts);

}

signed main(){
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
	