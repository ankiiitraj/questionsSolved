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
	vector<vi> a(n, vi(n));
	vi d(10, 0);
	char c;
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> c, a[i][j] = c - '0';

	for(int i = 3; i < 4; ++i){
		int res = 0, fx = -1, fy = -1;
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				if(a[j][k] == i){
					fx = j, fy = k;
					break;
				}
			}
			if(fx != -1)
				break;
		}
		for(int j = n -1; j >= 0; --j){
			for(int k = 0; k < n; ++k){
				if(a[j][k] == i and j != fx){
					res = max({ res, abs(fx - j) * max(max(fy, n -1 - fy), max(k, n -1 - k))});
				}
			}
		}
		cout << res << " " << fx << " " << fy << endl;
		fx = -1, fy = -1;
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				if(a[k][j] == i){
					fx = k, fy = j;
					break;
				}
			}
			if(fx != -1)
				break;
		}


		for(int j = n -1; j >= 0; --j){
			for(int k = 0; k < n; ++k){
				if(a[k][j] == i and j != fy){
					res = max(res, max(max(fx, n -1 - fx), max(k, n -1 - k)) * abs(fy - j));
					// cout << fx << " " << fy << " " << j << " " << k << endl;
				}
			}
		}
		d[i] = res;
	}

	for(auto itr: d){
		cout << itr << " ";
	}
	cout << endl;

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
