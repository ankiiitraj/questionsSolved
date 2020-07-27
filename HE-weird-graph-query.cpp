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
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 1000000000000005; // 1e6 +5
vii adj[1005];

vi dijkstar(int src, int n) 
{ 
    priority_queue<pii, vii, greater<pii> > pq; 
  	vi dist(n +1, INF);
    pq.push({0, src});
    dist[src] = 0; 
  
    while (!pq.empty()){ 
        int u = pq.top().second; 
        pq.pop();
  		for(auto itr: adj[u]){
            int v = itr.first; 
            int weight = itr.second;  
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight; 
                pq.push({dist[v], v});
            } 
        } 
    } 

    return dist;
} 

void swap(int* a, int* b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int arr[], int l, int r){ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++){ 
        if (arr[j] <= x) { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int kthSmallest(int arr[], int l, int r, int k){ 
    if (k > 0 && k <= r - l + 1){ 
        int pos = partition(arr, l, r); 
  		if (pos - l == k - 1) 
            return arr[pos]; 
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k); 
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1); 
    }
    return INF; 
} 

void solve(){
	int n, m, x, y, q, w, u, l, r, k;
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%lld%lld%lld", &x, &y, &w);
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	vi dp[n +1];
	for(int i = 1; i <= n; ++i){
		dp[i] = dijkstar(i, n);
	}
	
	scanf("%lld", &q);
	while(q--){
		scanf("%lld%lld%lld%lld", &u, &l, &r, &k);
		int cnt = 0;
		int temp[r -l +1];
		for(int i = l; i <= r; ++i){
			temp[i -l] = dp[i][u];
		}
		cout << kthSmallest(temp, 0, r - l, k) << endl;
		
	}
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
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
	