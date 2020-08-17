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
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

// bool check(int dist, mii m_map, int n){
// 	vector<int> v;
// 	int cnt = 0;
// 	while(cnt < n){
// 		for(auto itr = m_map.rbegin(); itr != m_map.rend(); ++itr){
// 			if(itr->second > 0){
// 				v.push_back(itr->first);
// 				itr->second--;
// 				cnt++;
// 				// if(itr->second == 0){
// 				// 	m_map.erase(itr->first);
// 				// }
// 			}

// 		}
// 	}

// 	debug(v);
// 	return false;

// }
int dp[7][7];
int rec(int arr[], int l, int r, int n){
	if(l == r){
		return dp[l][r] = arr[l]*(n - (r - l));
	}
	if(dp[l][r] != -1)
		return dp[l][r];
	return dp[l][r] = max(rec(arr, l +1, r, n) + arr[l]*(n - (r - l)), rec(arr, l, r -1, n) + arr[r]*(n - (r - l)));
}

void solve(){
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	mii m_map;
	for(auto itr: a){
		m_map[itr]++;
	}
	// check(4, m_map, n);
	// int l = 0, r = n;
	// while(l <= r){
	// 	int mid = l + (r - l)/2;
	// 	if(){
	// 		l = mid;
	// 	}else{
	// 		r = mid -1;
	// 	}
	// }
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	// 	solve();
	// int arr[] = {0, 2, 3, 5, 1, 4};
	// memset(dp, -1, sizeof dp);
	// cout << rec(arr, 1, 5, 5) << endl;
	// for(int i = 1; i <= 5; ++i){
	// 	for(int j = 1; j <= 5; ++j){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	char str[] ="Limericks";
	char *s;
	s= &str[6]-6;
	while(*s)
		printf("%c", *s++);

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
	