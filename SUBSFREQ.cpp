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
// const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

int power(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x)%MOD;
			--y;
		}else{
			x = (x * x)%MOD;
			y /= 2;
		}
	}
	return ans;
}

int MAXN = 500005;
vi factorial(500005);
void init(){
	factorial[0] = 1;
	for(int i = 1; i < MAXN; ++i){
		factorial[i] = factorial[i -1]*i%MOD;
	}
}
int mod_div(int num, int deno){
	return num*power(deno, MOD -2)%MOD;
}

int mod_subs(int a, int b){
	return (a - b + MOD) % MOD;
}

int nCr(int n, int r){
	int num = factorial[n];
	int deno = factorial[r]*factorial[n - r] % MOD;
	int ans = mod_div(num, deno) % MOD;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	vi a(n), ans(n +1, 0);
	int flag = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	mii fre;
	for(auto itr: a){
		fre[itr]++;
	}

	int temp = 1;
	vector<int> pre(n +5, 1), pre2(n +5, 1);
	for(auto itr: fre){
		temp = 1;
		for(int j = 1; j <= itr.second; ++j){
			temp = (temp + nCr(itr.second, j))%MOD;
			pre[j] = temp * pre[j] % MOD;
		}
		pre2[itr.second +1] = temp * pre2[itr.second +1] % MOD;
	}
	temp = 1;
	for(int i = 1; i <= n; i++)
	{
	      temp = temp * pre2[i] % MOD;
	      pre[i] = temp * pre[i] % MOD;
	}

	for(int i = 1; i <= n; ++i){
		int res = 0, temp_res;
		temp = 1;

	    for(int j = 1; j <= fre[i]; j++){
	    	int new_temp;
			temp_res = nCr(fre[i], j);
			new_temp = temp_res;
			temp = (temp + temp_res) % MOD;
			pre[j] = mod_div(pre[j], temp) % MOD;
			temp_res = temp_res * pre[j] % MOD;
			pre[j] = (pre[j] * mod_subs(temp, new_temp) % MOD)%MOD;
			res = (res + temp_res) % MOD;
		}

		cout << res % MOD << " ";
	}

	cout << endl;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	init();
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
	