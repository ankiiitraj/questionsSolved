#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
const int INF = 10000000000000005; // 1e15 +5

void solve(){
	int n, k, res = -INF;
	cin >> n >> k;
	vi a(n +1), p(n +1);
	scnarr(p, n);
	scnarr(a, n);
	
	for(int i = 1; i <= n; ++i){
		int idx = i, ans = -INF, cur = 0, sum, flag = 0, cycle = 0;
		for(int j = 0; j < k; ++j){
			cur += a[idx];
			idx = p[idx];

			if(idx == i){
				if(flag)
					break;
				flag = 1;
				cycle = j +1;
				sum = cur;
			}
			ans = max(ans, cur);
			if(flag)
				ans = max(ans, cur + (k - j -1)/cycle * sum);
		}
		res = max(res, ans);
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
	