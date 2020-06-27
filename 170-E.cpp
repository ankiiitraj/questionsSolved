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
const int MAXN = 1000005; // 1e6 +5

vi fact(MAXN);

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

void pre(){
	fact[0] = fact[1] = 1;
	for(int i = 2; i < MAXN; ++i){
		fact[i] = (fact[i -1] * i) % MOD;
	}
}

int nCr(int n, int r){
	int numerator = fact[n];
	int denominator = (fact[n -r] * fact[r]) % MOD;

	return (numerator * power(denominator, MOD -2)) % MOD;
}

int nPr(int n, int r){
	int numerator = fact[n];
	int denominator = fact[n - r];

	return (numerator * power(denominator, MOD -2)) % MOD;
}

void solve(){
	pre();
	int n, m;
	cin >> n >> m;

	int total = (nPr(m, n) * nPr(m, n)) % MOD, exclude = 0;

	for(int i = 1; i <= n; ++i){
		exclude = (exclude + nCr(n, i)*nCr(m, i)) % MOD;
	}

	cout << total << " " << nPr(m, n) * exclude << endl;
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
	