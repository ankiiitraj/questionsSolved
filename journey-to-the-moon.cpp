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

int parent[100005], size[100005];

void init(int n){
    for(int i = 0; i < n; ++i){
        size[i] = 1;
        parent[i] = i;
    }
}

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void _union(int u, int v){
    if(size[u] > size[v]){
        size[u] += size[v];
        size[v] = 0;
        parent[v] = parent[u];
    }else{
        size[v] += size[u];
        size[u] = 0;
        parent[u] = parent[v];
    }
}

void solve(){
    int n, p, x, y;
    cin >> n >> p;
    init(n);
    for(int i = 0; i < p; ++i){
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if(x == y)
            continue;
        _union(x, y);
    }
    int total = 0;
    for(int i = 0; i < n; ++i){
        if(size[i])
            total += size[i];
    }
    int ans = 0;
    for(int i = 0; i < n +1; ++i){
        if(parent[i] == i){
            total -= size[i];
            ans += total*size[i]; 
        }
    }
    cout << ans << endl;
}

signed main()
{
    faster;
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    // int t; cin >> t; while(t--)
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
    
