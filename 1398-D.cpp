#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin() +1, a.end()
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
const int INF = 100000000000005; // 1e15 +5

int dp[205][205][205];

int rec(vi &red, vi &green, vi &blue, int r, int g, int b){
	int base = (r == 0) + (b == 0) + (g == 0);
	if(base >= 2){
		return 0;
	}
	if(dp[r][g][b] != -1){
		return dp[r][g][b];
	}
	int one = 0, two = 0, three = 0; 
	if(r > 0 and g > 0){
		one = rec(red, green, blue, r -1, g -1, b) + red[r]*green[g];
	}
	if(g > 0 and b > 0){
		two = rec(red, green, blue, r, g -1, b -1) + blue[b]*green[g];
	}
	if(r > 0 and b > 0){
		three = rec(red, green, blue, r -1, g, b -1) + red[r]*blue[b];
	}
	return dp[r][g][b] = max({ one, two, three});

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif


	int r, g, b;
	cin >> r >> g >> b;
	vi red(r +1), green(g +1), blue(b +1);
	
	for(int i = 0; i <= r +1; ++i){
		for(int j = 0; j <= g +1; ++j){
			for(int k = 0; k <= b +1; ++k){
				dp[i][j][k] = 0;
			}
		}
	}

	for(int i = 1; i <= r; ++i){
		cin >> red[i];
	}
	for(int i = 1; i <= g; ++i){
		cin >> green[i];
	}
	for(int i = 1; i <= b; ++i){
		cin >> blue[i];
	}
	sort(all(red), greater<int>());
	sort(all(blue), greater<int>());
	sort(all(green), greater<int>());
	int ans = 0;
	for(int i = 0; i <= r; ++i){
		for(int j = 0; j <= g; ++j){
			for(int k = 0; k <= b; ++k){
				if(i&&j){
					dp[i][j][k] = max(dp[i][j][k], dp[i -1][j -1][k] + red[i]*green[j]);
				}
				if(j&&k){
					dp[i][j][k] = max(dp[i][j][k], dp[i][j -1][k -1] + blue[k]*green[j]);
				}
				if(k&&i){
					dp[i][j][k] = max(dp[i][j][k], dp[i -1][j][k -1] + red[i]*blue[k]);
				}
				ans = max(ans, dp[i][j][k]);
			}
		}
	}

	// int res = rec(red, green, blue, r, g, b);
	
	// cout << res << endl;
	cout << ans << endl;

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
	