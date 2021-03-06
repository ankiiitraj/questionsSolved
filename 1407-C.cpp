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
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n, cnt = 0;
	cin >> n;
	vi v, res(n +1, -1);
	for(int i = 0; i < n; ++i)
		v.push_back(i +1);
	while(1){
		vi to_erase;
		for(int i = 0; i < v.size() -1; i += 2){
			int rem1, rem2;
			cout << "? ";
			cout << v[i] << " " << v[i +1] << endl;
			cin >> rem1;
			cout << "? ";
			cout << v[i +1] << " " << v[i] << endl;
			cin >> rem2;
			if(rem2 > rem1){
				res[v[i +1]] = rem2;
				v[i +1] = -1;
			}else{
				res[v[i]] = rem1;
				v[i] = -1;
			}
		}
		vi temp;
		for(auto itr: v){
			if(itr != -1){
				temp.push_back(itr);
			}
		}
		v = temp;
		if(v.size() <= 1)
			break;
	}
	cout << "! ";
	for(int i = 1; i <= n; ++i){
		if(res[i] == -1){
			cout << n << " ";
		}else{
			cout << res[i] << " ";
		}
	}
	cout << endl;
}

signed main()
{
// 	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
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
	