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
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

pii dfs(vi &visited, vi adj[], int s, int p){
	visited[s] = 1;
	pii res = {1, 0};
	for(auto itr: adj[s]){
		if(itr != p){
			if(visited[itr] == 1){
				res.second = 1;
			}else{
				pii temp = dfs(visited, adj, itr, s);
				res.first += temp.first;
				res.second |= temp.second;
			}
		}
	}
	return res;
}


void solve(){
	int n, m, x, y;
	cin >> n >> m;
	map<pii, int> pos;
	vii cors;
    for(int i = 0; i < n; ++i) pos[{i +1, i +1}] = i +1;
    for(int i = 0; i < m; ++i){
    	cin >> x >> y;
    	if(x == y){
    		continue;
    	}
    	cors.push_back({x, y});
    	pos[cors.back()] = i + n +1;
    }
    vi adj[n + m +1];
    for(auto itr: cors){
    	adj[pos[itr]].push_back(pos[{itr.first, itr.first}]);
    	adj[pos[{itr.first, itr.first}]].push_back(pos[itr]);
    	adj[pos[itr]].push_back(pos[{itr.second, itr.second}]);
    	adj[pos[{itr.second, itr.second}]].push_back(pos[itr]);
    }

    int res = 0;
    vi visited(n + m +1, 0);

    for(int i = n +1; i <= n + m; ++i){
    	if(!visited[i]){
	    	pii temp = dfs(visited, adj, i, -1);
	    	// debug(temp);
	    	res += temp.first/2;
	    	res += temp.second;
    	}
    }

    cout << res << endl;

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
