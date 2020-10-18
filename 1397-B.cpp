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

int exp(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x);
			--y;
		}else{
			x = (x * x);
			y /= 2;
		}
	}
	return ans;
}

void solve(){
	int n, ans = 0;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	sort(all(a));
	int max_ = *max_element(all(a));
	int l = 1;
	long double expo = (long double)log2(max_)/(n -1);
	int r  = exp(2, ceil(expo));
	int res = 1e18;
	for(int c = 1; 1; ++c){
		ans = 0;
		for(int i = 0; i < n; ++i){
			int temp = exp(c, i);
			if(temp > 1e11){
				cout << res << endl;
				return;
			}
			ans += abs(temp - a[i]);
		}
		res = min(res, ans);
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
	