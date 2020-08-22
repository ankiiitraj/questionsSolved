#include<bits/stdc++.h>
using namespace std;

int res = 0;
map<pair<int, int>, int> edge_count;
void dfs(int src, int dest, int par, vector<int> adj[], bool visited[], vector<pair<int, int>> &path){
	visited[src] = 1;
	path.push_back({min(src, par), max(src, par)});
	if(src == dest){
		res += 1;
		for(auto itr: path){
			edge_count[itr]++;
		}
		visited[src] = 0;
		path.pop_back();
		return;
	}
	for(auto itr: adj[src]){
		if(!visited[itr]){
			dfs(itr, dest, src, adj, visited, path);
		}
	}
	path.pop_back();
	visited[src] = 0;
	return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int n, m, x, y, a, b;
	cin >> n >> m >> a >> b;
	vector<int> adj[n +1];
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	if(a == b){
		cout << "0\n";
	}else{
		bool visited[n +1] = {0};
		res = 0;
		int ans = 0;
		vector<pair<int, int>> path;
		dfs(a, b, -1, adj, visited, path);
		for(auto itr: edge_count){
			if(itr.second == res){
				ans++;
			}
		}
		cout << ans -1 << endl;
	}

}