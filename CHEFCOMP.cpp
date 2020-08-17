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
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void dfs(si adj[], vector<int> &visited, int src, vi &days, vi &a, vi &b, int cur_node, int cur_day){
	visited[src] = 1;
	for(auto itr: adj[src]){
		if(!visited[itr]){
			dfs(adj, visited, itr, days, a, b, cur_node, cur_day);
			if(b[itr] > 0){
				b[itr] -= min(b[itr], a[cur_node]);
				days[itr] = cur_day;
			}
		}
	}
}

void solve(){
	int n, x, y;
	cin >> n;
	vi a(n +1), b(n +1), p(n +1);
	set<int> adj[n +1];

	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	scnarr(p, n);
	scnarr(a, n);
	scnarr(b, n);
	vector<int> visited(n +1, 0);
	vi days(n +1, 0);
	for(int i = 1; i <= n; ++i){
		visited.assign(n +1, 0);
		if(b[p[i]] != 0){
			b[p[i]] -= min(b[p[i]], a[p[i]]);
			days[p[i]] = i;
		}
		dfs(adj, visited, p[i], days, a, b, p[i], i);
		for(int j = 1; j <= n; ++j){
			if(adj[j].find(p[i]) != adj[j].end())
				adj[j].erase(p[i]);
		}
		adj[p[i]].clear();
	}

	for(int i = 1; i <= n; ++i){
		if(b[i] != 0){
			cout << "-1 ";
		}else{
			cout << days[i] << " ";
		}
	}
	cout << endl;

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
	