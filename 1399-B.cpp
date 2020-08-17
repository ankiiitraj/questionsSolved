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
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n;
	cin >> n;
	vi a(n), b(n);
	scnarr(a, n);
	scnarr(b, n);
	int min_a = INF, min_b = INF;
	for(int i = 0; i < n; ++i){
		min_a = min(min_a, a[i]);
		min_b = min(min_b, b[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] > min_a and b[i] > min_b){
			ans += min(a[i] - min_a, b[i] - min_b);
			int cnt = min(a[i] - min_a, b[i] - min_b);
			a[i] -= cnt;
			b[i] -= cnt;
		}
		if(a[i] > min_a){
			ans += a[i] - min_a;
		}
		if(b[i] > min_b){
			ans += b[i] - min_b;
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
	