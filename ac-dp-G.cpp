#include <bits/stdc++.h>
using namespace std;

int dfs(int s, vector<int>adj[], int dp[]){
	if(dp[s] != 0)
		return dp[s];
	for(auto itr: adj[s]){
		dp[s] = max(dp[s], 1+ dfs(itr, adj, dp));
	}
	return dp[s];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int n, m, x, y;
	cin >> n >> m;
	vector<int> adj[n +1];
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	int dp[n +1] = {0};
	bool visited[n +1] = {0};

	for(int i = 1; i <= n; ++i){
		dfs(i, adj, dp);
	}
	int res = 1;
	for(int i = 1; i <= n; ++i){
		res = max(res, dp[i]);
	}	
	cout << res << endl;


}