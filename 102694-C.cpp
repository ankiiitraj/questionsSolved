#include<bits/stdc++.h>
using namespace std;

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

void dfs(vector<int>adj[], int src, int par, vector<int> &parent, vector<int> &depth){
	for(auto itr: adj[src]){
		if(itr != par){
			parent[itr] = src;
			depth[itr] = depth[src] +1;
			dfs(adj, itr, src, parent, depth);
		}
	}
}

void init_binary_lift(vector<int> adj[], int src, int par, vector<int> &parent, vector<vector<int>> &dp){
	dp[src][0] = par;
	if(parent[src] != -1){
		for(int i = 1; i < 20; ++i){
			if(dp[dp[src][i -1]][i -1] == -1){
				break;
			}
			dp[src][i] = dp[dp[src][i -1]][i -1];
		}
	}
	for(auto itr: adj[src]){
		if(itr != par){
			init_binary_lift(adj, itr, src, parent, dp);
		}
	}
}

int lift(int a, int dist, vector<vector<int>> &dp){
	if(dist == 0 or a == -1){
		return a;
	}
	for(int i = 19; i >= 0; --i){
		if(dist >= (1<<i)){
			return lift(dp[a][i], dist - (1<<i), dp);
		}
	}
	return -1;
}

int lca(int a, int b, vector <int> &depth, vector<vector<int>> &dp){
	if(depth[a] != depth[b]){
		if(depth[a] > depth[b]){
			a = lift(a, depth[a] - depth[b], dp);
		}else{
			b = lift(b, depth[b] - depth[a], dp);
		}
	}
	if(a == b){
		return a;
	}

	for(int i = 19; i >= 0; --i){
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

void print_lift_table(int n, vector<vector<int>> &dp){
	for(int i = 1; i <= n; ++i){
		cout << i << " : ";
		for(auto itr: dp[i]){
			cout << itr << " ";
		}
		cout << endl;
	}
	return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int n, a, b, q, c;
	cin >> n;
	vector<int> adj[n +1];
	for(int i = 0; i < n -1; ++i){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> parent(n +1), depth(n +1);
	vector<vector<int>> dp(n +1, vector<int>(20, -1));
	parent[1] = -1; depth[1] = 1;
	dfs(adj, 1, -1, parent, depth);
	init_binary_lift(adj, 1, -1, parent, dp);

	cin >> q;

	while(q--){
		cin >> a >> b >> c;
		int LCA = lca(a, b, depth, dp);
		int len = depth[a] - depth[LCA] + depth[b] - depth[LCA];

		if(len <= c){
			cout << b << endl;
		}else if(c > depth[a] - depth[LCA]){
			int temp = c - (depth[a] - depth[LCA]);
			cout << lift(b, depth[b] - depth[LCA] - temp, dp) << endl;
		}else{
			cout << lift(a, c, dp) << endl;
		}
	}
}