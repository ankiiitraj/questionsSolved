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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
int n, m;

void dfs(int i, vector<int> &visited, vector<int> adj[], vector<int> &in_coming, vector<int> &topsort){
    visited[i] = 1;
    for(auto itr: adj[i]){
        in_coming[itr]--;
        if(!visited[itr] and !in_coming[itr]){
            topsort.push_back(itr);
            dfs(itr, visited, adj, in_coming, topsort);
        }
    }
}

void solve(){
	int t, x, y;
	cin >> n >> m;
	vector<pii> edges;
	vi visited(n +1, 0), adj[n +1], topsort, in_coming(n +1, 0);

	for(int i = 0; i < m; ++i){
		cin >> t >> x >> y;
		if(t){
			adj[x].push_back(y);
			in_coming[y]++;
		}else{
			edges.push_back({x, y});
		}
	}

	for(int i = 1; i <= n; ++i){
        if(!in_coming[i]){
            if(!visited[i]){
                topsort.push_back(i);    
                dfs(i, visited, adj, in_coming, topsort);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    	if(in_coming[i]){
    		cout << "NO\n";
    		return;
    	}

    mii pos;
    int idx = 1;
    for(auto itr: topsort){
    	pos[itr] = idx++;
    }
	for(auto itr: edges){
		if(pos[itr.first] > pos[itr.second]){
			adj[itr.second].push_back(itr.first);
		}else{
			adj[itr.first].push_back(itr.second);
		}
	}
	// debug(topsort);
	cout << "YES\n";
	for(int i = 0; i <= n; ++i){
		for(auto itr: adj[i]){
			cout << i << " " << itr << endl;
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
	