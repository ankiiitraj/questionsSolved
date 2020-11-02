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
	int n, m;
	cin >> n >> m;

	vector<vi> rows(n, vi(m)), columns(m, vi(n)), res(n, vi(m, 0));

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> rows[i][j];
		}
	}


	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> columns[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		vi temp(m);
		for(int j = 0; j < m; ++j)
			temp[j] = columns[j][i];

		bool flag = 0;
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				if(temp[0] == rows[j][k]){
					res[i] = rows[j];
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
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
