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


bool find_ans(vi &a, int n){
	int idx = -1;
	for(int i = n -2; i > 0; --i){
		if(a[i] <= a[i +1] and a[i] < a[i -1]){
			idx = i;
			break;
		}
	}
	
	if(a[n -1] < a[n -2]){
		idx = n -1;
	}

	int cur = -1, cur_min = a[idx];
	for(int i = idx -1; i >= 0; --i){
		if(cur == -1){
			cur = a[i] - cur_min;
		}else{
			if(a[i] - cur < 0){
				return 0;
			}else{
				if(a[i] - cur > cur_min){
					cur = a[i] - cur_min;
				}else{
					cur_min = a[i] - cur;
				}
			}
		}
	}

	return 1;
}

void solve(){
	int n;
	cin >> n;
	vi a(n), sorted_a;
	scnarr(a, n);
	sorted_a = a;
	
	sort(all(sorted_a));
	if(a == sorted_a){
		cout << "YES\n";
		return;
	}

	reverse(all(sorted_a));
	if(a == sorted_a){
		cout << "YES\n";
		return;
	}

	bool one = find_ans(a, n);
	reverse(all(a));
	bool two = find_ans(a, n);

	if(one or two)
		cout << "YES\n";
	else
		cout << "NO\n";

	return;
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
