#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define lf double
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

bool check(vi &a, lf d, lf mid){
	lf prev = a[0] + mid;
	for(int i = 1; i < a.size(); ++i){
		if(prev >= a[i] + d){
			return 0;
		}
		if(a[i] > prev){
			prev = a[i] + mid;
		}else{
			prev = prev + 0.00000000001 + mid;
		}
	}
	return 1;
}

void solve(){
	cout << fixed << setprecision(12);
	int n, d;
	cin >> n >> d;
	vi a(n);
	scnarr(a, n);
	sort(all(a));
	lf l = 0.0, r = 1e18*1.0;

	for(int i = 0; i < 110; ++i){
		lf mid = (l + r)/2;
		if(check(a, d, mid)){
			l = mid;
		}else{
			r = mid;
		}
	}

	cout << max(l, r) << endl;

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
	