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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

int n;
string s;

int dp[10][100][2];

int recurse(int size, int cur, bool flag){
	if(size >= n)
		return cur;

	if(dp[size][cur][flag] != -1)
		return dp[size][cur][flag];

	int limit = 9;
	if(flag){
		limit = s[size] - '0';
	}

	int ans = 0;

	for(int i = 0; i <= limit; ++i){
		if(!flag or (int)(s[size] - '0') > i)
			ans += recurse(size +1, cur + i, false);
		else
			ans += recurse(size +1, cur + i, true);
	}
	return dp[size][cur][flag] = ans;
}

void solve(){
	while(1){
		int a, b;
		cin >> a >> b;
		if(a == -1 and b == -1)
			return;
		
		memset(dp, -1, sizeof(dp));

		s = to_string(b);
		n = s.length();

		int to_r = recurse(0, 0, 1);
		
		memset(dp, -1, sizeof(dp));

		s = to_string(a -1);
		n = s.length();

		int to_l = recurse(0, 0, 1);

		cout << to_r - to_l << endl;
	}

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
	