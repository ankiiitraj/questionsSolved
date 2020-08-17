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
const int INF = INT_MAX;

int dijkstra(vector<pair<int, int>> adj[], int n, int src, int dest){
    vector<int> smallest_paths(n +1, INF);
    multimap<int, int> q;
    smallest_paths[src] = 0;
    q.insert({0, src});
    while(!q.empty()){
        int cur = q.begin()->second;
        q.erase(q.begin());
        for(auto itr: adj[cur]){
            if(smallest_paths[itr.first] > (itr.second | smallest_paths[cur])){
                smallest_paths[itr.first] = min(smallest_paths[itr.first] ,(itr.second | smallest_paths[cur]));
                q.insert({smallest_paths[itr.first], itr.first});
            }
        }
    }
    return smallest_paths[dest];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    // int t; cin >> t; while(t--)
    {

        int n, m, u, v, w;
        cin >> n >> m;

        vector<pair<int, int>> adj[n +1];

        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        cin >> u >> v;
        int res = dijkstra(adj, n, u, v);
        cout << (res > 1024 ? -1 : res) << endl;
    }
    return 0;
}
