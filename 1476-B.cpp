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


void solve(){
	int n, res = 0, k;
	cin >> n >> k;
	vi a(n), prices(n);
	scnarr(a, n);
	prices[0] = a[0];
	for(int i = 1; i < n; ++i) prices[i] = prices[i -1] + a[i];

	for(int i = 1; i < n; ++i){
		int left = k * prices[i -1], right = a[i] * 100; 
		if(left < right){
			int l = prices[i -1], r = 1e12;
			while(l < r){
				int mid = l + (r - l)/2;
				if(k * mid < a[i] * 100){
					l = mid +1;
				}else{
					r = mid;
				}
			}

			res += (l - prices[i -1]);
			a[0] += (l - prices[i -1]);
			prices[0] = a[0];
			for(int j = 1; j < n; ++j) prices[j] = prices[j -1] + a[j];
		}

	}

	cout << res << endl;

	return;
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
