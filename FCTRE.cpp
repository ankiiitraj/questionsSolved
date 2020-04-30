#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef cc_hash_table<int, int, hash<int>> ht;
typedef cc_hash_table< int, int, hash<int>, equal_to<int>, direct_mask_range_hashing<int>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>, true>> hts;

using namespace std;
using namespace chrono;
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
//Constants
const long long MOD = 1000000007; // 1e9 + 7
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
const int MAXN = 1000005;
int n, x, y;

int spf[MAXN];
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<MAXN; i++) 

		spf[i] = i; 

	for (int i=4; i<MAXN; i+=2) 
		spf[i] = 2; 

	for (int i=3; i*i<MAXN; i++) 
	{ 
		if (spf[i] == i) 
		{ 
			for (int j=i*i; j<MAXN; j+=i) 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

vector <pii> trees[100001];
int v[100001] = {0};
pii tree_ref[100001] = {{0,0}};
int level[100001] = {0};
const int len = (int)log2(100000)+3;
pii dp[100001][len];
 

void dfs(int src, int d){
    v[src]++;
    level[src] = d;
    d++;
    for(pii child : trees[src]){
        if(v[child.first] == 0){
            tree_ref[child.first].first = src;
            tree_ref[child.first].second = child.second;
 
            dfs(child.first, d);
        }
    }
}
 
int lca(int u, int v){
    if(level[u] < level[v]){
        swap(u,v);
    }
 
    if(level[u] != level[v]){
        for(int i = len-1; i>=0 ; i--){
            if(level[dp[u][i].first] == level[v]){
                u = dp[u][i].first;
                break;
            }
            else{
                if(level[dp[u][i].first] > level[v]){
                    u = dp[u][i].first;
                }
            }
        }
    }
 
    if(u!=v){
        for(int i = len-1; i>=0 ; i--){
            if(dp[u][i].first != dp[v][i].first){
                u = dp[u][i].first;
                v = dp[v][i].first;
            }
        }
        u = tree_ref[u].first;
        v = tree_ref[v].first;
    }
 
    return u;
}


unordered_map <int, int> factors[100005];
unordered_map <int, int> nodeData[100005];
bool visited[100005];
void Dfs(int i, int parent){
	visited[i] = 1;
	if(i != 1){
		nodeData[i] = nodeData[parent];
		for(auto &itr: factors[i]){
			nodeData[i][itr.first] += itr.second;
		}
	}
	for(auto itr:trees[i]){
		if(!visited[itr.first]){
			Dfs(itr.first, i);
		}
	}
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	sieve();
	int t; scanf("%d",&t); while(t--)
	{

		int q;
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i){
			trees[i].clear();
			tree_ref[i] = {0, 0};
		}
		for(int i = 0; i < n -1; ++i){
			scanf("%d%d",&x,&y);
			trees[x].push_back({y, 0});
			trees[y].push_back({x, 0});
		}
		
		vector<int> a(n +1);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);

		int sum = 0;
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= n; ++i){
			factors[i].clear();
			nodeData[i].clear();
			x = a[i];
			while (x != 1) 
			{ 
				factors[i][spf[x]]++; 
				nodeData[i][spf[x]]++;
				x = x / spf[x]; 
			}
			sum += factors[i].size();
		}	

		Dfs(1, -1);
		
		memset(v, 0, sizeof(v));
		memset(level, 0, sizeof(level));
		tree_ref[1] = {1,0};    
	    dfs(1,0);
	 
	    for(int i = 1; i <= n; ++i){
	        dp[i][0].first = tree_ref[i].first;
	        dp[i][0].second = tree_ref[i].second;
	    }
	 
	 
	    for(int j = 1; j<len; j++){
	        for(int i = 1; i <= n; ++i){
	            dp[i][j].first = dp[dp[i][j-1].first][j-1].first;
	            dp[i][j].second = max(dp[i][j-1].second, dp[dp[i][j-1].first][j-1].second);
	        }
	    }
		
		scanf("%d", &q);
		int _max = 0;
		unordered_map <int, int> temp;
		auto start = high_resolution_clock::now(); 
		while(q--){
			scanf("%d%d",&x,&y);
			int Lca = lca(x, y); long long ans = 1, falg = 0;
			temp.clear();
			for(auto itr:nodeData[x]){
				temp[itr.first] += itr.second;
				_max++;
			}

			for(auto itr:nodeData[y]){
				temp[itr.first] += itr.second;
			}

			for(auto &itr:nodeData[Lca]){
				temp[itr.first] -= 2*itr.second;
			}

			for(auto &itr:factors[Lca]){
				temp[itr.first] += itr.second;
			}

			for(auto &itr:temp){
				ans = (ans * ((itr.second +1)%MOD))%MOD;
			}
			// cout << nodeData[x].size() << " " << nodeData[y].size() << "\n";
			_max += nodeData[x].size() + nodeData[y].size() + nodeData[Lca].size();
			printf("%lld\n", ans);

		}
		auto stop = high_resolution_clock::now(); 
		auto duration = duration_cast<seconds>(stop - start); 
		// debug(duration.count(), _max);

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
// 183623282