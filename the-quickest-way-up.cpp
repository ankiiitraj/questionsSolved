#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int dijkstra(vector<pair<int, int>> adj[]){
    vector<int> smallest_paths(101, INF);
    multimap<int, int> q;
    smallest_paths[1] = 0;
    q.insert({0, 1});
    while(!q.empty()){
        int cur = q.begin()->second;
        q.erase(q.begin());
        for(auto itr: adj[cur]){
            if(smallest_paths[itr.first] > itr.second + smallest_paths[cur]){
                smallest_paths[itr.first] = min(smallest_paths[itr.first] ,itr.second + smallest_paths[cur]);
                q.insert({smallest_paths[itr.first], itr.first});
            }
        }
    }
    return smallest_paths[100];
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t; while(t--){

        int n, m, u, v;
        cin >> n;

        vector<pair<int, int>> adj[101];

        for(int i = 0; i < n; ++i){
            cin >> u >> v;
            adj[u].push_back({v, 0});
        }
        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            adj[u].push_back({v, 0});
        }

        for(int i = 1; i < 100; ++i){
            if(adj[i].empty()){
                for(int j = i +1; j <= min(100, i +6); ++j){
                    adj[i].push_back({j, 1});
                }
            }
        }
        int res = dijkstra(adj);
        cout << (res > 100 ? -1 : res) << endl;
    }
    return 0;
}
