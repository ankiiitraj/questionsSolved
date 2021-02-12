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

mii prime_factorization(int val){
	if(val == 1){
		mii temp;
		return temp;
	}
	mii res;
	while(val != 1){
		res[spf[val]]++;
		val /= spf[val];
	}
	return res;
}



void solve(){
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);

	multiset<mii> m;

	for(int i = 0; i < n; ++i){
		m.insert(prime_factorization(a[i]));
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
