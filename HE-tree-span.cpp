#include <bits/stdc++.h>
#include <time.h>
#define pb push_back
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
//Constants
const int MAXN = 100005; // 1e5 +5
struct edge{
	int link, w, id;
};

vector<edge> adj[MAXN];
vii parent;
const int INF = INT_MAX;
vi dijkstar(int src, int n, si &s) 
{ 
    priority_queue<pii, vii, greater<pii> > pq; 
  	vi dist(n +1, INF);
  	parent.assign(n +1, {-1, -1});
    pq.push({0, src});
    dist[src] = 0;
    parent[src] = {src, -1};
  	si new_s;
  	new_s.insert(src);
    while (!pq.empty()){
    	if(s == new_s)
    		break; 
        int u = pq.top().second; 
        pq.pop();
  		for(auto itr: adj[u]){
            int v = itr.link; 
            int weight = itr.w;  
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                parent[v] = {u, itr.id};
                if(s.find(v) != s.end())
                	new_s.insert(v);
                pq.push({dist[v], v});
            } 
        } 
    } 

    return dist;
}

void solve(){
	int n, m, x, y, w, k;
	scanf("%d%d", &n, &m);
	vector<edge> edges;
	si ans;
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back({y, w, i +1});
		adj[y].push_back({x, w, i +1});
	}
	scanf("%d", &k);

 	vi ss;
 	si s;
	for(int i = 0; i < k; ++i){
		scanf("%d", &y);
		ss.push_back(y);
		s.insert(y);
	}

	vi dist;
	vii parents;
	long long int _min = 100000000000000;
	int idx;
 	// for(auto itr: ss){
	// for(int i = 0; i < 10; ++i){
	int itr = rand()%k;
	itr = ss[itr];
 		dist = dijkstar(itr, n, s);
 		
 		// int cur = 0;
 		// for(auto itr1: ss){
 		// 	cur += dist[itr1];
 		// }
 		// if(_min > cur){
 			// _min = cur;
	 		idx = itr;
	 		parents = parent;
 		// }
 		// parent.clear();
 	// }
 		// debug(dist, parents);
 	// bool visited[MAXN] = {0};
 	for(auto itr: ss){
 		int cur = itr;
 		while(cur != idx){
 			// if(!visited[parents[cur].first]){
 				ans.insert(parents[cur].second);
 				// visited[parents[cur].first] = 1;
 				cur = parents[cur].first;
 			// }else{
 				// ans.insert(parents[cur].second);
 				// break;
 			// }
 		}
 	}
 	cout << ans.size() << endl;
 	for(auto itr: ans)
 		cout << itr << " ";
	cout << endl;
}

signed main()
{
	srand(time(NULL));
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
		solve();
	return 0;
}
