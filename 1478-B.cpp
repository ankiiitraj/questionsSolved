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

int countDigs(int a){
	int res = 0;
	while(a){
		a /= 10;
		res++;
	}
	return res;
}

bool numHave(int a, int d){
	while(a){
		if(a%10 == d)
			return 1;
		a /= 10;
	}
	return 0;
}

int rec(int a, int n, vi &space, vector<vi> &dp){
	if(a == 0)
		return 1;
	if(n < 0 or a < 0) return 0;

	if(dp[n][a] != -1)
		return dp[n][a];

	return dp[n][a] = (rec(a - space[n], n, space, dp) | rec(a, n -1, space, dp));
}

void solve(){
	int n, d;
	cin >> n >> d;
	vi a(n);
	scnarr(a, n);
	int num = d;
	for(int i = 0; i < n; ++i){
		int numOfDigs = countDigs(a[i]);
		if(numOfDigs >= 3){
			cout << "YES\n";
			continue;
		}
		if(numOfDigs == 1){
			if(a[i] % d != 0){
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			continue;
		}

		vi space;
		for(int j = 0; j <= a[i]; ++j){
			if(numHave(j, d)){
				space.push_back(j);
			}
		}
		vector<vi> dp(space.size() +5, vi(a[i] +5, -1));

		cout << (rec(a[i], space.size() -1, space, dp) ? "YES" : "NO") << endl;

	}

	return;
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
