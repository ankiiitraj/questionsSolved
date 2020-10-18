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
	int n;
	cin >> n;
	vector<vector<char>> g(n, vector<char>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> g[i][j];
		}
	}

	if(g[1][0] == g[0][1]){
		if(g[n -1][n -2] == g[n -2][n -1] and g[n -1][n -2] != g[0][1]){
			cout << "0\n";
		}else if(g[n -1][n -2] == g[n -2][n -1] and g[n -1][n -2] == g[0][1]){
			cout << "2\n" << n << " " << n -1 << endl << n -1 << " " << n << endl;
		}else if(g[n -1][n -2] != g[n -2][n -1] and g[n -1][n -2] == g[0][1]){
			cout << "1\n" << n << " " << n -1 << endl;
		}else if(g[n -1][n -2] != g[n -2][n -1] and g[n -2][n -1] == g[0][1]){
			cout << "1\n" << n -1 << " " << n << endl;
		}
	}else{
		if(g[n -1][n -2] == g[n -2][n -1] and g[n -1][n -2] == g[0][1]){
			cout << "1\n1 2\n";
		}else if(g[n -1][n -2] == g[n -2][n -1] and g[n -1][n -2] == g[1][0]){
			cout << "1\n2 1\n";
		}else if(g[n -1][n -2] != g[n -2][n -1]){
			cout << "2\n";
			if(g[n -1][n -2] == g[0][1]){
				cout << "1 2\n" << n -1 << " " << n << endl;
			}else{
				cout << "1 2\n" << n << " " << n -1 << endl;
			}
		}
	}

	
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
	