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

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5
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
string omit_leading_0s(string s){
	int n = s.length();
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			int start = i;
			s = s.substr(i);
			return s;
		}
	}
	return s;
}

void solve(){
	int a, b;
	string s;
	cin >> a >> b >> s;

	string all_0(s.length(), '0');

	if(s == all_0){
		cout << 0 << endl;
		return;
	}

	s = omit_leading_0s(s);
	reverse(all(s));
	s = omit_leading_0s(s);
	reverse(all(s));


	int n = s.length();

	vi patch_size(n, -1), dp(n, 0);

	for(int i = 0; i < n; ++i){
		if(s[i] == '0'){
			int j = i +1;
			while(s[j] == '0'){
				++j;
			}
			patch_size[j] = j - i;
			i = j -1;
		}
	}
	dp[0] = a;
	for(int i = 1; i < n; ++i){
		if(s[i] == '1' and s[i -1] == '0'){
			if(patch_size[i] * b < a){
				dp[i] = dp[i - patch_size[i] -1] + patch_size[i] * b;
			}else{
				dp[i] = dp[i - patch_size[i] -1] + a;
			}
		}else{
			dp[i] = dp[i -1];
		}
	}
	

	cout << dp[n -1] << endl;





	// vi dp(n), prev(n, 0);
	// dp[0] = a;

	// int pre = 0;
	// for(int i = 1; i < n; ++i){
	// 	if(s[i] == '1'){
	// 		prev[i] = pre;
	// 		pre = i;
	// 	}
	// }

	// for(int i = 1; i < n; ++i){
	// 	if(s[i] == '1'){
	// 		if(s[i -1] == '0'){
	// 			dp[i] = min(dp[i -1], dp[prev[i]] + a);
	// 		}else{
	// 			dp[i] = dp[i -1];
	// 		}
	// 	}else{
	// 		dp[i] = dp[i -1] + b;
	// 	}
	// }
	// debug(dp);
	// cout << dp[n -1] << endl;
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
