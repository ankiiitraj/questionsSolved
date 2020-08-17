#include <bits/stdc++.h>
#define int long long
#include <time.h>
#define pb push_back
#define all(a) a.begin() +1, a.end()
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
const int MAXN = 1000005, INF = 100000000000000; // 1e6 +5

int nC3(int n){
	if(n <= 2){
		return 0;
	}
	return ((n*(n -1)*(n -2))/6);
}
int nC2(int n){
	if(n <= 1){
		return 0;
	}
	return ((n*(n -1))/2);
}

// Brute_Force exponential time complexity
int rec(vi &a, vi &c, vi &v, int pos, int n, int k, vi &res){
	if(pos >= n or k <= 0){
		map<int, vi> m;
		int ans = 0;
		for(auto itr: res){
			m[c[itr]].push_back(a[itr]);
		}
		for(auto itr: m){
			int cnt = itr.second.size(), cur_ans = nC3(cnt);
			mii par;
			for(auto itr2: itr.second){
				par[itr2]++;
			}
			for(auto itr2: par){
				cur_ans -= (nC3(itr2.second) + nC2(itr2.second)*(cnt - itr2.second));
			}
			ans += cur_ans;
		}
		return ans;
	}

	if(k - v[c[pos]] < 0){
		res.push_back(pos);
		int one = rec(a, c, v, pos +1, n, k, res);
		res.pop_back();
		return one;
	}
	int one = rec(a, c, v, pos +1, n, k - v[c[pos]], res);
	res.push_back(pos);
	int two = rec(a, c, v, pos +1, n, k, res);
	res.pop_back();

	return min(one, two);

}


int dp[3005][3005];
// Memoized for no parallel lines
int solve2(int c, int k, vi &fre, vi &cost){
	if(k <= 0 or c == 0)
		return dp[c][k] = 0;

	if(dp[c][k] != -1)
		return dp[c][k];

	int ans = -INF, cnt = 0;
	for(int i = 0; i <= fre[c]; ++i){
		if(i == 0){
			ans = max(ans, solve2(c -1, k, fre, cost));	
			continue;
		}
		if(k < i*cost[c]){
			break;
		}
		cnt += nC2(fre[c] - i);
		ans = max(ans, solve2(c -1, k - i*cost[c], fre, cost) + cnt);
	}
	return dp[c][k] = ans;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		int n, C, k;
		
		cin >> n >> C >> k;

		vi a(n), b(n), c(n), v(C +1);
		for(int i = 0; i < n; ++i){
			cin >> a[i] >> b[i] >> c[i];
		}
		vi c_fre(C +1, 0);
		for(int i = 0; i < n; ++i){
			c_fre[c[i]]++;
		}
		int max_tris = 0;
		for(int i = 1; i <= C; ++i){
			max_tris += nC3(c_fre[i]);
		}
		for(int i = 1; i <= C; ++i)
			cin >> v[i];

		if(n <= 10){
			vi res;
			cout << rec(a, c, v, 0, n, k, res) << endl;
			continue;
		}

		memset(dp, -1, sizeof dp);
		int res = solve2(C, k, c_fre, v);

		cout << max_tris - res << endl;

	}
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
	