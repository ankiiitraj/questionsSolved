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
	int p, f, cnt_s, cnt_w, wt_s, wt_w;
	cin >> p >> f >> cnt_s >> cnt_w >> wt_s >> wt_w;
	int res = 0;
	for(int i = 0; i <= cnt_s; ++i){
		int cur = min(i, p/wt_s);
		cur += min(cnt_s - i, f/wt_s);
		cur += min((p - min(i, p/wt_s)*wt_s)/wt_w, cnt_w);
		cur += min((f - min(cnt_s - i, f/wt_s)*wt_s)/wt_w, cnt_w - min((p - min(i,p/wt_s)*wt_s)/wt_w, cnt_w));

		res = max(res, cur);
	}

	swap(p, f);
	swap(cnt_s, cnt_w);
	swap(wt_s, wt_w);

	for(int i = 0; i <= cnt_s; ++i){
		int cur = min(i, p/wt_s);
		cur += min(cnt_s - i, f/wt_s);
		cur += min((p - min(i, p/wt_s)*wt_s)/wt_w, cnt_w);
		cur += min((f - min(cnt_s - i, f/wt_s)*wt_s)/wt_w, cnt_w - min((p - min(i,p/wt_s)*wt_s)/wt_w, cnt_w));

		res = max(res, cur);
	}

	cout << res << endl;

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
	