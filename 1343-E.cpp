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
int n, m, a, b, c;
vi adj[N], p(N);

bool cmp(pii &t1, pii &t2){
	return t1.first > t2.first;
}

vi bfs(int src){
	queue <int> q;
	q.push(src);
	vi dist(n +1, -1);
	dist[src] = 0; 
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(auto itr: adj[cur]){
			q.push(itr);
			dist[itr] = dist[cur] +1;
		}
	}
	return dist;
}



int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int x, y, ans = 0;
		cin >> n >> m >> a >> b >> c;
		p.resize(m, 0);
		scnarr(p, m);
		sort(all(p), cmp);

		for(int i = 0; i <= n; ++i)
			adj[i].clear();

		for(int i = 0; i < m; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		vii distA = bfs(a), distB = bfs(b), distC = bfs(c);

		for(int i = 1; i <= n; ++i){
			
		}


	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :	