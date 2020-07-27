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
const int MAX_VERTEX = 300005; 

vi Arr(MAX_VERTEX);
vi colors(MAX_VERTEX);
vi size(MAX_VERTEX);
vi pairs_count(MAX_VERTEX);
map <int, int> freq_cols[MAX_VERTEX];
vii edges;
  
void initialize(int n) 
{ 
    for (int i = 0; i <= n; i++) { 
    	freq_cols[i][colors[i]]++;
    	pairs_count[i] = 0;
        Arr[i] = i; 
        size[i] = 1; 
    } 
} 
  
int find(int i) 
{ 
    while (Arr[i] != i) 
    { 
        Arr[i] = Arr[Arr[i]];
        i = Arr[i];
    } 
    return i; 
} 
  
int _union(int xr, int yr) 
{ 
	int total = 0, res = pairs_count[xr] + pairs_count[yr];
    if (size[xr] < size[yr])
    {
    	for(auto itr: freq_cols[xr]){
    		total += itr.second * freq_cols[yr][itr.first];
    		freq_cols[yr][itr.first] += itr.second;
    	}
        Arr[xr] = Arr[yr]; 
        size[yr] += size[xr]; 
        pairs_count[yr] += pairs_count[xr] + total;
    } 
    else
    {
    	for(auto itr: freq_cols[yr]){
    		total += itr.second * freq_cols[xr][itr.first];
    		freq_cols[xr][itr.first] += itr.second;
    	}
    	Arr[yr] = Arr[xr];
        size[xr] += size[yr];
        pairs_count[xr] += pairs_count[yr] + total;
    } 
    return total;
} 

void solve(){
	int n, x, y;
	cin >> n;
	vi queries, ans(n -1);
	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		edges.push_back({x, y});
	}
	for(int i = 0; i < n; ++i)
		cin >> colors[i +1];

	initialize(n);
	for(int i = 0; i < n -1; ++i){
		cin >> x;
		--x;
		queries.push_back(x);
	}

	for(int i = n -2; i >= 0; --i){
		int v1 = edges[queries[i]].first;
		int v2 = edges[queries[i]].second;
		v1 = find(v1);
		v2 = find(v2);
		ans[i] = _union(v1, v2);
	}

	for(auto itr: ans)
		cout << itr << endl;
	
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
	