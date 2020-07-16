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
const int MOD = 998244353;
const int MAXN = 1000005; // 1e6 +5

vi a(26);

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

int get_power(string s){
	int n = s.length(), res = 0;
	for(int i = 1; i <= n; ++i){
		string temp = s.substr(0, i);
		int cnt = 0, j = 0, flag = 0;
		while(j + i -1 < n){
			if(s.substr(j, i) == temp){
				cnt++;
			}else{
				break;
			}
			j += i;
		}

		temp = s.substr(j);
		for(int ii = 0; ii < temp.length(); ++ii){
			if(temp[ii] != s[ii]){
				flag = 1;
				break;
			}
		}

		if(!flag and (cnt == n/i or (n%i == 0 and cnt == n/i -1))){
			int cur = 0;
			for(auto itr: s.substr(0, i)){
				cur = cur + a[itr - 'a'] % MOD;
			}
			// cur *= cnt;
			res = res + cur % MOD;
		}
	}
	return res;
}

void solve(){
	string s;
	cin >> s;
	int n = s.length();
	scnarr(a, 26);

	map <string, int> freq, all_powers, power_of_one;
	for(int i = 0; i < n; ++i){
		for(int j = 1; j <= n - i; ++j){
			freq[s.substr(i, j)]++;
			if(freq[s.substr(i, j)] == 1){
				all_powers[s.substr(i, j)] = get_power(s.substr(i, j));
				power_of_one[s.substr(i, j)] = get_power(s.substr(i, j));
			}else{
				all_powers[s.substr(i, j)] = (all_powers[s.substr(i, j)] + power_of_one[s.substr(i, j)]) % MOD; 
			}
			// debug(all_powers, s.substr(i, j));
		}
	}


	int num = 0, deno = (n*(n +1))/2;
	for(auto itr: all_powers)
		num = (num + itr.second) % MOD;

	deno = power(deno, MOD -2);

	num = num * deno % MOD;

	cout << num << endl;

	
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
