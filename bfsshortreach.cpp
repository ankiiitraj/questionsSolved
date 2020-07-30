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
/*
    Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

void solve(){
    int n, m, x, y;
    cin >> n >> m;
    vi adj[n +1];
    int dist[n +1], src;
    bool visited[1005];
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        dist[i] = -1;
        visited[i] = 0;
    }
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> src;
    queue <int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto itr: adj[cur]){
            if(!visited[itr]){
                visited[itr] = 1;
                q.push(itr);
                dist[itr] = dist[cur] +6;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(i != src){
            cout << dist[i] << " ";
        }
    }
    cout << endl;
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
    