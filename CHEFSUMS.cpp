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


bool isNotPrime[MAXN +1];
vi primes, spf(MAXN +1); // spf - Smallest prime factor of a number
int cnt = 0;
void sieve(){
	memset(isNotPrime, 0, sizeof(isNotPrime));

	spf[1] = 1;
	for(int i = 2; i <= MAXN; i++)
		spf[i] = i;

	for(int i = 2; i <= MAXN; i+=2)
		spf[i] = 2;

	isNotPrime[0] = isNotPrime[1] = 1; 
	for(int i = 2; i*i <= MAXN; ++i){
		if(isNotPrime[i] == false){
			spf[i] = i;
			for(int j = i*i; j <= MAXN; j += i){
				isNotPrime[j] = 1;
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

inline int prime_factorization(int val){
	return spf[val];
}

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

int G(vi a, vi idx){
	int gcd = a[idx[0]];
	for(auto itr: idx){
		gcd = __gcd(gcd, a[itr]);
	}
	return gcd;
}

int Sx(vi a, vi idx, int x){
	int res = 0;
	for(auto itr: idx){
		res = (res + power(a[itr], x)) % MOD;
	}
	return res;
}

int Pm(vi a, vi idx, int m){
	int res = 1;
	for(auto itr: idx){
		res = (res * a[itr]) % MOD;
	}
	res = power(res, m);
	return res;
}

int W(vi a, vi idx){
	int _min = INF;
	for(auto itr: idx){
		_min = min(_min, prime_factorization(a[itr]));
	}
	return _min;
}

int solve(vi &idx, vi &a, int m, int x){
	int res;
	res = G(a, idx);
	res = res * W(a, idx) % MOD;
	res = res * Sx(a, idx, x) % MOD;
	res = res * Pm(a, idx, m) % MOD;
	return res;
}

string to_base_c(int n, int c, int k){
	string res;
	while(n){
		res += ((n%c) + '0');
		n /= c;
	}
	while(res.length() < k)
		res += '0';
	reverse(all(res));
	return res;
}

vi to_vec(string s){
	vi res;
	for(auto itr: s){
		res.push_back(itr - '0');
	}
	return res;
}

string sorted_num(string s){
	sort(all(s));
	return s;
}

void solve(){
	int n, k, m, x;
	scanf("%lld%lld%lld%lld", &n, &k, &m, &x);
	vi a(n), idx;
	for(int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	int res = 0;

	map<string, int> dp;

	for(int i = 0; i < power(n, k); ++i){
		string c_i = to_base_c(i, n, k);
		string temp = sorted_num(c_i);

		if(dp.count(temp)){
			res = (res + dp[temp]) % MOD;
		}else{
			idx = to_vec(c_i);
			int tmp = solve(idx, a, m, x);
			res = (res + tmp) % MOD;
			dp[temp] = tmp;
		}
	}

	printf("%lld\n", res);
	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	sieve();
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
	