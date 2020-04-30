#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
const int MAXN = 100005;
vi adj[MAXN];
int depth[MAXN]; 
int parent[MAXN];

const int maxn = 1000005;
int n, x, y;

int spf[maxn];
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<maxn; i++) 

		spf[i] = i; 

	for (int i=4; i<maxn; i+=2) 
		spf[i] = 2; 

	for (int i=3; i*i<maxn; i++) 
	{ 
		if (spf[i] == i) 
		{ 
			for (int j=i*i; j<maxn; j+=i) 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

//O(n)
void dfs(int cur, int prev) 
{ 
    parent[cur] = prev; 
  
    depth[cur] = depth[prev] + 1; 
  
    for (int i=0; i<adj[cur].size(); i++) 
        if (adj[cur][i] != prev) 
            dfs(adj[cur][i],cur); 
} 
  
void preprocess() 
{  
	memset(depth, 0, sizeof(depth));
	memset(parent, 0, sizeof(parent));
    depth[0] = -1; 
    dfs(1,0); 
}

//O(n)
int LCANaive(int u,int v) 
{ 
    if (u == v)  return u; 
    if (depth[u] > depth[v]) 
        swap(u, v); 
    v = parent[v]; 
    return LCANaive(u,v); 
}

mii factors[100005];
mii nodeData[100005];
bool visited[100005];
void Dfs(int i, int parent){
	visited[i] = 1;
	if(i != 1){
		nodeData[i] = nodeData[parent];
		for(auto &itr: factors[i]){
			nodeData[i][itr.first] += itr.second;
		}
	}
	cout << nodeData[i].size() << endl;
	for(auto itr:adj[i]){
		if(!visited[itr]){
			Dfs(itr, i);
		}
	}
}

int32_t main()
{
	// faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	sieve();
	int t; cin >> t; while(t--)
	{
		int q, n, x, y;
		cin >> n;
		for(int i = 1; i <= n; ++i){
			adj[i].clear();
		}
		for(int i = 0; i < n -1; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vi a(n +1);
		scnarr(a, n);

		for(int i = 1; i <= n; ++i){
			factors[i].clear();
			nodeData[i].clear();
			x = a[i];
			while (x != 1) 
			{ 
				factors[i][spf[x]]++; 
				nodeData[i][spf[x]]++;
				x = x / spf[x]; 
			}
		}
		memset(visited, 0, sizeof(visited));	
		Dfs(1, -1);
		// preprocess();
		cin >> q; cout << q << endl;
		while(q--){
			cin >> x >> y;
			int lca = LCANaive(x, y), ans = 1;

			mii temp;
			for(auto &itr:nodeData[x]){
				temp[itr.first] += itr.second;
			}

			for(auto &itr:nodeData[y]){
				temp[itr.first] += itr.second;
			}

			for(auto &itr:nodeData[lca]){
				temp[itr.first] -= 2*itr.second;
			}

			for(auto &itr:factors[lca]){
				temp[itr.first] += itr.second;
			}

			for(auto &itr:temp){
				ans = (ans * ((itr.second +1)%MOD))%MOD;
			}

			// cout << ans << endl;
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	