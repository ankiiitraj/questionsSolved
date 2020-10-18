#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
// //Constants
// const int MOD = 1000000007; // 1e9 + 7
// const int MAXN = 1000005; // 1e6 +5
// const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n, ans = 0;
	cin >> n;
	vi a(n +1), pref(n +1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	map<int, vi> m;
	for(int i = 1; i <= n; ++i){
		m[a[i]].push_back(i);
		pref[i] = pref[i -1] + a[i];
	}

	for(auto itr: m){
		vi temp = itr.second;
		if(itr.first&1){
			for(int i = 0; i < temp.size() -1; ++i){
				if(temp[i]&1 and temp[i +1]&1){
					ans = max(ans, pref[temp[i +1] -1] - pref[temp[i]]);
				}else if(temp[i]%2==0 and temp[i +1]%2==0){
					ans = max(ans, pref[temp[i +1] -1] - pref[temp[i]]);
				}
			}
		}else{
			for(int i = 0; i < temp.size() -1; ++i){
				if(temp[i]&1 and temp[i +1]%2==0){
					ans = max(ans, pref[temp[i +1] -1] - pref[temp[i]]);
				}else if(temp[i]%2==0 and temp[i +1]&1){
					ans = max(ans, pref[temp[i +1] -1] - pref[temp[i]]);
				}
			}
		}
	}
	cout << ans << endl;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
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
	