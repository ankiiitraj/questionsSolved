#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 300005; // 1e6 +5
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
/* -------------------------------Solution Sarted--------------------------------------*/

vi adj[N];
int n, k;

bool cmp(pii &t1, pii &t2){
	return t1.first - t1.second < t2.first - t2.second;
}

bool visited[N];
vi subtreeSize(N, 0);
int dfs(int i){
	visited[i] = 1;
	int size = 0;
	for(auto itr:adj[i]){
		if(!visited[itr]){
			size += dfs(itr);
		}
	}
	subtreeSize[i] = size;
	return subtreeSize[i] +1;
}

void bfs(){
	queue <int> q;
	q.push(1);
	vi level(n +10, 0); 
    bool marked[n +10] = {0}; 
    level[1] = 0; 
    marked[1] = true; 
	while (!q.empty()) { 
        int x = q.front(); 
        q.pop(); 
  
        for (int i = 0; i < adj[x].size(); i++) { 
            int b = adj[x][i]; 
  
            if (!marked[b]) {   
                q.push(b); 
                level[b] = level[x] + 1; 
                marked[b] = true; 
            } 
        } 
    }
    int max_lev = -1;
    for(int i = 0; i <= n; ++i){
    	max_lev = max(max_lev, level[i]);
    }
    vector<pii> lev;
    for(int i = 1; i <= n; ++i){
    	lev.push_back({level[i], subtreeSize[i]});
    }
    int ans = 0;
 //    for(int i = 0; i <= max_lev; ++i){
 //    	debug(lev[i], i);
	// }
    	sort(all(lev), cmp);
	// debug(lev);
		for(int i = n -1; k > 0; --k, --i)
			ans += lev[i].first - lev[i].second;
    // for(int i = max_lev; i >= 0 and k > 0; --i){
    // 	sort(all(lev[i]), cmp);
    // 	int offset;
    // 	for(auto itr: lev[i]){
    // 		if(k <= 0)
    // 			break;
    // 		offset = itr.second;
    // 		ans += i - offset;
    // 		// cout << ans << " " << itr.first << " " << itr.second << endl;
    // 		--k;
    // 	}
    // }
    cout << ans << endl; 	
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int x, y;
		cin >> n >> k;
		for(int i = 0; i <= n; ++i)
			adj[i].clear();
		for (int i = 0; i < n -1; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		subtreeSize.resize(n +1, 0);
		dfs(1);
		// debug(subtreeSize);
		bfs();

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	