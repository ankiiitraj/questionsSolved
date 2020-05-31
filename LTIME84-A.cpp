#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5
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

vi adj[200005], a, path;
bool vis[200005];
int n;

bool dfs(int s, int d){
	if(s == d){
		path.push_back(s);
		return 1;
	}

	vis[s] = 1;
	for(auto itr:adj[s]){
		if(!vis[itr]){
			bool is = dfs(itr, d);
			if(is){
				path.push_back(s);
				return 1;
			}
		}
	}
	return 0;
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int u, v, q;
		cin >> n >> q;
		a.clear();
		a.resize(n +1, 0);
		scnarr(a, n);

		for(int i = 0; i < n +2; ++i)
			adj[i].clear();

		for(int i = 0; i < n -1; ++i){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		while(q--){
			cin >> u >> v;
			memset(vis, 0, sizeof(vis));
			path.clear();

			dfs(u, v);
			vi temp;
			for(int i = 0; i < path.size(); ++i){
				temp.push_back(a[path[i] -1]);
			}
			sort(all(temp));

			int ans = 1000000000000;
			for(int i = 0; i < temp.size() -1; ++i){
				ans = min(ans, temp[i +1] - temp[i]);
			}
			cout << ans << endl;

		}



	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	