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
const int MAXN = 100005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vi g[MAXN];
// Taken from https://codeforces.com/blog/entry/57593
vi Centroid(int n) {
    vi centroid;
    vi sz(n +1);
    function<void (int, int)> dfs = [&](int u, int prev) {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    dfs(1, -1);
    return centroid;
}

vi sizes(MAXN, 0);
int size_dfs(int s, int t, int par){
	int res = 0;
	if(g[s].size() == 1 and par != -1){
		sizes[s] = 1;
		return 1;
	}
	for(auto itr: g[s]){
		if(itr != par and itr != t){
			res += size_dfs(itr, t, s);
		}
	}
	sizes[s] = res +1;
	return res +1;
}

void solve(){
	int n, x, y;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		g[i].clear();
	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vi centroids = Centroid(n);
	assert(centroids.size() > 0);
	if(centroids.size() == 1){
		cout << x << " " << y << "\n" << x << " " << y << "\n";
	}
	else{
		int _max = -1, node = -1;
		vi temp(n +1, 0);
		sizes = temp;
		size_dfs(centroids[0], centroids[1], -1);
		for(int i = 1; i <= n; ++i){
			if(sizes[i] > _max and i != centroids[0]){
				_max = sizes[i];
				node = i;
			}
		}
		assert(node != -1);
		assert(_max > 0);
		cout << node << " " << centroids[0] << endl;
		cout << node << " " << centroids[1] << endl;
		
	}
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
	