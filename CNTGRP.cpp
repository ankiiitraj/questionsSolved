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

vi fact(MAXN);
void init(){
	fact[0] = 1;
	for(int i = 1; i < MAXN; ++i){
		fact[i] = fact[i -1]*i%MOD;
	}
	return;
}

void solve(){
	int n, m, a, flag = 0, idx = -1, ans = 1;
	cin >> n >> m;
	vi freq(n +1, 0);
	for(int i = 0; i < n -1; ++i){
		cin >> a;
		freq[a]++;
	}

	for(int i = 1; i <= n; ++i){
		if(freq[i] == 0){
			flag = 1;
			idx = i;
		}
		if(flag and freq[i] > 0){
			cout << "0\n";
			return;
		}
	}
	for(int i = 1; i < idx; ++i){
		ans = ans * fact[freq[i]] % MOD;
	}
	cout << ans << endl;
	return;
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
	