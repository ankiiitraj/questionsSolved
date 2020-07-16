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


void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<vi> can_reach(n, vi(m, 1)), can_use(n, vi(m, 0));

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}


	for(int i = n + m -3; i >= 0; --i){
		for(int j = max(0LL, i - (m -1)); j < n and j <= i; ++j){
			if(a[j][i - j] == '#')
				can_reach[j][i - j] = 0;
			else if(!((j +1 < n and can_reach[j +1][i - j]) or (i - j +1 < m and can_reach[j][i - j +1]))){
				can_reach[j][i - j] = 0;
			}
		}
	}
	
	can_use[0][0] = 1;
	string res = "";
	res += a[0][0];
	for(int i = 1; i <= n + m -2; ++i){
		char _min = 'z';
		for(int j = max(0LL, i - (m -1)); j < n and j <= i; ++j){
			if(can_reach[j][i - j] and ((j -1 >= 0 and can_use[j -1][i - j]) or (i - j -1 >= 0 and can_use[j][i - j -1]))){
				_min = min(_min, a[j][i - j]);
			}
		}

		res += _min;

		for(int j = max(0LL, i - (m -1)); j < n and j <= i; ++j){
			if(can_reach[j][i - j] and ((j -1 >= 0 and can_use[j -1][i - j]) or (i - j -1 >= 0 and can_use[j][i - j -1])) and _min == a[j][i - j]){
				can_use[j][i - j] = 1;
			}
		}
	}
	// res += a[n -1][m -1];

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
	