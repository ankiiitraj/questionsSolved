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
//Constants
const int MOD = 998244353; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

int calc(int val){
	if(val == 0)
		return 0;
	return (int)(1 << (64 - __builtin_clzll(val) - 1));
}

int fun(vi a, int l){
	return min({
		calc(a[l +2] ^ calc(a[l] ^ a[l +1])),
		calc(a[l +1] ^ calc(a[l] ^ a[l +2])),
		calc(a[l] ^ calc(a[l +2] ^ a[l +1]))
	});
}

int fun_4(vi a, int l){
	return min({
		fun({ calc(a[l] ^ a[l +1]), a[l +2], a[l +3] }, 0),
		fun({ calc(a[l] ^ a[l +2]), a[l +1], a[l +3] }, 0),
		fun({ calc(a[l] ^ a[l +3]), a[l +1], a[l +2] }, 0),
		fun({ calc(a[l +1] ^ a[l +2]), a[l], a[l +3] }, 0),
		fun({ calc(a[l +1] ^ a[l +3]), a[l +2], a[l] }, 0),
		fun({ calc(a[l +2] ^ a[l +3]), a[l], a[l +1] }, 0)
	});
}

void solve(){
	int n, ans = 0;
	cin >> n;
	vi a(n +1);
	scnarr(a, n);

	vi logs(n +1), p_2(31);

	p_2[0] = 1;
	for(int i = 1; i < 31; ++i){
		p_2[i] = p_2[i -1] * 2 % MOD;
	}

	for(int i = 1; i <= n; ++i){
		int temp = a[i], cnt = 0;
		while(temp){
			temp /= 2;
			cnt++;
		}
		logs[i] = cnt;
	}

	for(int i = 1; i <= n; ++i){
		int cur_max = -1, max_cnt = 0, other_cnt = 0;
		for(int j = i; j <= n; ++j){
			if(logs[j] > cur_max){
				cur_max = logs[j];
				other_cnt += max_cnt;
				max_cnt = 1;
			}else if(logs[j] == cur_max){
				max_cnt++;
			}else{
				other_cnt++;
			}

			if(j - i +1 == 1){
				ans = (ans + a[j]) % MOD;
			}else if(j - i +1 == 2){
				ans = (ans + calc(a[i] ^ a[j])) % MOD;
			}else if(j - i +1 == 3){
				if(max_cnt & 1){
					if(cur_max > 0)
						ans = (ans + p_2[cur_max -1]) % MOD;
				}else{
					ans = (ans + fun(a, i)) % MOD;
				}
			}else if(j - i +1 == 4){
				if(max_cnt & 1){
					if(cur_max > 0)
						ans = (ans + p_2[cur_max -1]) % MOD;
				}else if(max_cnt != 2){
					ans = (ans + fun_4(a, i)) % MOD;
				}
			}else{
				if(max_cnt & 1){
					if(cur_max > 0)
						ans = (ans + p_2[cur_max -1]) % MOD;
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
	// int t; cin >> t; while(t--)
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
	