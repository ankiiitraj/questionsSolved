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
	vi a(n);
	scnarr(a, n);
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	sort(all(a));
	int max_wt = a[n -2] + a[n -1];

	int ans = INT_MIN;
	
	for(int i = 1; i <= max_wt; ++i){
		int m[105] = {0};
		for(int j = 0; j < n; ++j){
			m[a[j]]++;
		}
		int cnt = 0;
		for(int j = 0; j < n; ++j){
			if(a[j] == i - a[j] and m[a[j]] >= 2){
				cnt++;
				m[a[j]] -= 2;
			}else if(a[j] != i - a[j] and i - a[j] >= 0 and m[i - a[j]] > 0 and m[a[j]] > 0){
				cnt++;
				m[a[j]]--;
				m[i - a[j]]--;
			}
		}
		ans = max(cnt, ans);
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
	