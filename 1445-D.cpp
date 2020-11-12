#include <bits/stdc++.h>
#include <time.h>
#define int unsigned long long int
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
const int MOD = 998244353; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
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

void solve(){
	int n, sum, first = 0, second = 0;
	cin >> n;
	vi a(2*n);
	scnarr(a, 2*n);
	sort(all(a));
	for(int i = 0; i < n; ++i){
		first += a[i];
		second += a[2*n -1 -i];
	}

	sum = second - first;
	sum = sum % MOD;

	int num = 1, deno;
	for(int i = 1; i <= 2*n; ++i){
		num = num * i % MOD;
		if(i == n){
			deno = num;
		}
	}

	deno = deno * deno % MOD;

	int modInv = power(deno, MOD -2);

	num = num * modInv % MOD;
	num = num * sum % MOD;

	cout << num << endl;

	return;
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
