#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i +1]
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
	int n, ans = 0;
	cin >> n;
	vi a(n +1);
	scnarr(a, n);

	vector<vi> m(n +1, vi(n +1, 0));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			m[i][j] = m[i -1][j];
		}
		m[i][a[i]]++;
	}
	for(int j = 2; j <= n - 2; ++j){
		for(int k = j +1; k <= n -1; ++k){
			ans += m[j -1][a[k]]*(m[n][a[j]] - m[k][a[j]]);
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
	