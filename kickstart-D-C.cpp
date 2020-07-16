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
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

int n, ath, bth;
vi a(1);


long double solve(){
	cin >> n >> ath >> bth;
	a.resize(n);

	for(int i = 1; i < n; ++i){
		cin >> a[i];
	}

	vi res(n +1, 0);

	a[0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			vector<int> painted(n +1, 0);
			int cur = i, cnt = 0;
			do{
				if(cnt % ath == 0){
					painted[cur] = 1;
				}
				cnt++;
				cur = a[cur -1];
			}while(cur != 1);
			if(cur == 1 and cnt % ath == 0)
				painted[1] = 1;
			
			cur = j, cnt = 0;
			do{
				if(cnt % bth == 0){
					painted[cur] = 1;
				}
				cnt++;
				cur = a[cur -1];
			}while(cur != 1);
			if(cur == 1 and cnt % bth == 0)
				painted[1] = 1;
			cnt = 0;
			for(auto itr: painted)
				if(itr)
					cnt++;
			res[cnt]++;
			// debug(painted, i, j, cnt);
		}
	}
	int idx = 0, ans = 0, tot = 0;
	for(auto itr: res){
		ans += itr*idx;
		idx++;
		tot += itr;
	}
	// debug(res, ans);
	long double ans_double = (ans*1.0)/(tot*1.0);

	return ans_double;	
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	cout << fixed << setprecision(10);
	int t; cin >> t; for(int test = 1; test <= t; ++test){
		
		cout << "Case #" << test << ": " << solve() << endl;

	}
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
	