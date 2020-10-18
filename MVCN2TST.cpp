#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
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
	----------------------------------------------------------------------
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
const int MAXN = 1005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vi g[MAXN], height, parent, sizes;
vector<vi> up;

struct tup{
	int first, second, third;
};

bool cmp(const tup p1, const tup p2){
	if(p1.first == p2.first){
		if(p1.third == p2.third){
			return p1.second < p2.second;
		}
		return p1.third < p2.third;
	}
	return p1.first < p2.first;
}

int dfs(int s, int par, int h){
	height[s] = h;
	parent[s] = par;
	int res = 1;
	for(auto itr: g[s]){
		if(itr != par){
			res += dfs(itr, s, h +1);
		}
	}
	sizes[s] = res;
	return res;
}

void solve(){
	int n, q, x, y;
	scanf("%lld", &n);

	for(int i = 1; i <= n; ++i)
		g[i].clear();
	vector<vi> up(n +1, vi(n +1, -1));
	height = vi(n +1, 0);
	parent = vi(n +1, 0);
	sizes = vi(n +1, 0);

	for(int i = 1; i <= n -1; ++i){
		scanf("%lld%lld", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	scanf("%lld", &q);
	vi e(q);

	dfs(1, -1, 0); // O(n)
	for(int i = 1; i <= n; ++i){
		up[i][1] = parent[i];
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 2; j <= n; ++j){
			if(up[i][j -1] != -1)
				up[i][j] = up[up[i][j -1]][1];
			else
				break;
		}
	}
	int _max_height = *max_element(all(height));
	vi hei[_max_height +1];
	for(int i = 1; i <= n; ++i){
		hei[height[i]].push_back(i);
	}

	vector<tup> L[n +1];
	for(int i = 2; i <= n; ++i){
		for(int j = 0; j <= _max_height; ++j){
			for(auto itr: hei[j]){
				if(itr != i and height[i] >= j){
					L[i].push_back({i, itr, j});
				}else if(itr != i and height[i] < j and up[itr][j - height[i]] != i){
					L[i].push_back({i, itr, j});
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		sizes[i] = n - sizes[i];
	}

	for(int i = 0; i < q; ++i){
		scanf("%lld", &e[i]);
	}

	int d = 0, c;
	int pow_of_2 = 1, pow_of_3 = 1;
	for(int i = 0; i < q; ++i){
		pow_of_2 = pow_of_2 * 2 % MOD;
		pow_of_3 = pow_of_3 * 3 % MOD;
		c = d ^ e[i];
		int sum = 0, idx;
		for(int j = 1; j <= n; ++j){
			sum += sizes[j];
			if(sum >= c){
				idx = j;
				break;
			}
		}

		sum -= sizes[idx];
		sizes[idx]--;
		c = c - sum;
		c--;
		int u = L[idx][c].first, v = L[idx][c].second;
		L[idx].erase(L[idx].begin() + c);

		d = (d + (((u * pow_of_2 % MOD) + (v * pow_of_3 % MOD)) % MOD))%MOD;
	}

	printf("%lld\n", d);

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; scanf("%lld", &t); while(t--)
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
	