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
const int N = 1000005; // 1e6 +5
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
int n, m;
vi adj[N];

set <int> bfs(int src){
	set <int> s;
	queue <int> q;
	q.push(src);
	vi level(n +1, -1);
	level[src] = 0;
	bool visited[n +1] = {0};
	visited[src] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto itr:adj[cur]){
			if(src == 2 and itr != 1){
				visited[itr] = 1;
				if(!visited[itr]){
					q.push(itr);
					level[itr] = level[cur] +1;
				}
			}else if(src == 1 and itr != 2){
				if(!visited[itr]){
					visited[itr] = 1;
					q.push(itr);
					level[itr] = level[cur] +1;
				}
			}
		}
	}

	if(src == 2){
		for(int i = 1; i <= n; ++i){
			if(level[i] == 1 or level[i] == 2){
				s.insert(i);
			}
		}
	}else if(src == 1){
		for(int i = 1; i <= n; ++i){
			if(level[i] == 1){
				s.insert(i);
			}
		}
	}

	return s;

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
		int a, b;
		cin >> n >> m;

		for(int i = 1; i <= n; ++i)
			adj[i].clear();

		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vi ans;
		set <int> s1 = bfs(2), s2 = bfs(1);
		// debug(s1, s2);
		for(auto &itr:s2){
			if(s1.find(itr) == s1.end()){
				ans.push_back(itr);
			}
		}

		if(ans.size() == 0){
			cout << "-1\n";
			continue;
		}
		sort(all(ans));
		for(auto itr:ans)
			cout << itr << " ";
		cout << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	