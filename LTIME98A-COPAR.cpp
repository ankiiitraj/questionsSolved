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
const int MAXN = 100005; // 1e5 +5
const int INF = 100000000000005; // 1e15 +5


bool isNotPrime[MAXN +1];
vi primes, spf(MAXN +1); // spf - Smallest prime factor of a number
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
			primes.push_back(i);
			for(int j = i*i; j <= MAXN; j += i){
				isNotPrime[j] = 1;
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

vi prime_factorization(int val){
	vi res;
	while(val != 1){
		res.push_back(spf[val]);
		val /= spf[val];
	}
	return res;
}


void solve(){
	int n;
	scanf("%lld", &n);
	vi a(n);

	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}

	vi primes_counter(MAXN, 0);
	unordered_set<int> sufm;
	for(int i = 0; i < n; ++i){
		vi temp = prime_factorization(a[i]);
		for(auto itr: temp){
			primes_counter[itr]++;
		}

	}

	for(int i = 0; i < n; ++i){
		vi temp = prime_factorization(a[i]);
		for(auto itr: temp)
			sufm.insert(itr), primes_counter[itr]--;

		int cnt = 0;

		for(auto itr: sufm){
			if(primes_counter[itr] > 0){
				cnt++;
				break;
			}
		}
		if(!cnt){
			printf("%lld\n", i +1);
			return;
		}
	}
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
	int t; scanf("%lld", &t); while(t--)
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
