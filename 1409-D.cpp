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

vi to_arr(int n){
	vi res;
	while(n){
		res.push_back(n%10);
		n /= 10;
	}
	reverse(all(res));
	return res;
}

int cnt_dig(int n){
	int res = 0;
	while(n){
		n/=10;
		res++;
	}
	return res;
}

void solve(){
	int n, s;
	cin >> n >> s;
	int cnt = cnt_dig(n);
	vi dig_arr = to_arr(n);
	dig_arr.insert(dig_arr.begin(), 0);
	vi pref(dig_arr.size(), 0);
	for(int i = 1; i < dig_arr.size(); ++i){
		pref[i] = dig_arr[i] + pref[i -1];
	}
	if(pref.back() <= s){
		cout << 0 << endl;
		return;
	}
	for(int i = pref.size() -1; i > 0; --i){
		if(pref[i] + 1 <= s){
			for(int j = i +1; j < dig_arr.size(); ++j){
				dig_arr[j] = 0;
			}
			int num = 0;
			for(int j = 1; j <= i; ++j){
				num += (int)pow(10, cnt - j)*dig_arr[j];
			}

			cout << (num + (int)pow(10, cnt - i) - n) << endl;
			return;
		}
	}

	cout << (int)((int)pow(10, cnt) - n) << endl;
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
	