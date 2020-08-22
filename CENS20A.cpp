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

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	int a[n +1][m +1];
	char c;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> c;
			a[i][j] = (c - '0');
		}
	}	
	int bit[n +2][m +2];
	memset(bit, 0, sizeof bit);

	int q;
	cin >> q;
	while(q--){
		int xl, yl, xr, yr;
		cin >> xl >> yl >> xr >> yr;
		bit[xl][yl]++;
		bit[xr +1][yr +1]++;
		bit[xl][yr +1]--;
		bit[xr +1][yl]--;
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			bit[i][j] += bit[i -1][j] + bit[i][j -1] - bit[i -1][j -1];
		}
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(bit[i][j]&1){
				cout << (!a[i][j]);
			}else{
				cout << a[i][j];
			}
		}
		cout << endl;
	}

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
	