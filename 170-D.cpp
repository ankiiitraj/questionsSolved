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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 10000005; // 1e7 +5


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
	mii res;
	while(val != 1){
		res[spf[val]]++;
		val /= spf[val];
	}
	return res;
}


int num_of_divisors(int n){
	mii count = prime_factorization(n);
	int ans = 1;
	for(auto itr: count){
		ans *= (itr.second +1); 
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 2; i <= n; ++i)
		ans += i*num_of_divisors(i);

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
	sieve();
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
	