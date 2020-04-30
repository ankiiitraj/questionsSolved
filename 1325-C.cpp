#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 100005; // 1e6 +1
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

vi v[N];
map <pair<int,int>, int> weights;
int till, upto;
int ans;
bool visited[N], firstLeaf = false, done = false;
set <int> used;

void dfs(int i){
	visited[i] = 1;
	for(auto itr:v[i]){
		if(!visited[itr]){
			dfs(itr);
			if(v[itr].size() == 1){
				weights.insert({{i, itr}, till++});
			}else{
				weights.insert({{i, itr}, upto--});
			}
		}
	}
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
		int n, x, y;
		cin >> n;
		till = 0, upto = n -2;
		vector <pii> edges;
		for (int i = 0; i < n -1; ++i){
			cin >> x >> y;
			edges.push_back({x, y});
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);
		vi answer;
		for(int i = 0; i < n -1; ++i){
			if(weights.find({edges[i]}) != weights.end()){
				answer.push_back(weights[edges[i]]);
			}else if(weights.find({edges[i].second, edges[i].first}) != weights.end()){
				answer.push_back(weights[{edges[i].second, edges[i].first}]);
			}
		}
		for(auto itr:answer)
			cout << itr << "\n";

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
