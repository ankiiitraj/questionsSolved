#include<bits/stdc++.h>
using namespace std;

int dfs(int src, vector<int> adj[], vector<bool> &visited, int *cnt){
    visited[src] = 1;
    if(adj[src].size() == 1 and src != 1){
        return 1;
    }
    int cur_child = 0, cur_subtree = 0;
    for(auto itr: adj[src]){
        if(!visited[itr]){
            cur_child = dfs(itr, adj, visited, cnt);
            if(cur_child%2 == 0){ 
                *cnt = *cnt +1;
            }else{
                cur_subtree += cur_child;
            }
        }
    }
    return cur_subtree +1;
}

int main(){
    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n +1];

    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n +1, 0);
    int cnt = 0;
    dfs(1, adj, visited, &cnt);
    cout << cnt << endl;
    return 0;
}
