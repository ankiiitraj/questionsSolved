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
// const int INF = 100000000000005; // 1e15 +5

int dp[1005][1005], cntt = 0;

int rec(vector<int> &a, vector<vector<int>> &pref, int l, int r, int k){
	if(l == r){
		return dp[l][r] = k;
	}

	if(dp[l][r] != -1)
		return dp[l][r];

	int cnt = 0;
	for(int i = 1; i <= 100; ++i){
		cnt += (pref[i][r] - pref[i][l -1] == 1 ? 0 : pref[i][r] - pref[i][l -1]);
	}

	if(cnt == 0)
		return dp[l][r] = k;
	cnt += k;
	for(int i = l; i < r; ++i){
		cntt++;
		int one, two;
		if(dp[l][i] != -1)
			one = dp[l][i];
		else
			one = rec(a, pref, l, i, k);
		if(dp[i +1][r] != -1)
			two = dp[i +1][r];
		else
			two = rec(a, pref, i +1, r, k);
		cnt = min(cnt, one + two);
	}
	return dp[l][r] = cnt;
}

int rec(vector<int> &a, int pos, int last, int k, int n, vector<vector<int>> &pref){
	if(pos > n){
		int cnt = 0;
		for(int i = 1; i <= 100; ++i){
			cnt += (pref[i][pos -1] - pref[i][last -1] == 1 ? 0 : pref[i][pos -1] - pref[i][last -1]);
		}
		return dp[pos][last] = cnt;	
	}

	if(dp[pos][last] != -1)
		return dp[pos][last];

	int cnt = 0;
	for(int i = 1; i <= 100; ++i){
		cnt += (pref[i][pos -1] - pref[i][last -1] == 1 ? 0 : pref[i][pos -1] - pref[i][last -1]);
	}

	return dp[pos][last] = min(rec(a, pos +1, pos, k, n, pref) + cnt + k, rec(a, pos +1, last, k, n, pref));
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; scanf("%lld", &t); while(t--){
		int n, k;
		scanf("%lld%lld", &n, &k);
		vi a(n +1);
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= n; ++j)
				dp[i][j] = -1;
		}
		vector<vector<int>> pref(101, vector<int>(n +1, 0));

		for(int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= 100; ++j){
				pref[j][i] = pref[j][i -1];
			}
			pref[a[i]][i]++;
		}
		// int res = rec(a, pref, 1, n, k);
		int res = rec(a, 2, 1, k, n, pref) + k;
		printf("%lld\n", res);
	}
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
