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

bool if_x_y(int a, int d, int n, int x, int y){
	bool x_flag = 0, y_flag = 0;
	for(int i = 0; i < n; ++i){
		if(a + i*d == x){
			x_flag = 1;
		}
		if(a + i*d == y){
			y_flag = 1;
		}
	}

	return (x_flag&&y_flag);
}


void solve(){
	int x, y, n;
	cin >> n >> x >> y;

	int diff = y - x, ini, d, _min = INF;

	for(int i = 1; i*i <= diff; ++i){
		if(diff%i==0){
			int temp;
			for(int j = 1; j <= x; ++j){
				temp = j + (n -1)*i;
				if(temp < _min and temp >= y and if_x_y(j, i, n, x, y)){
					_min = temp;
					ini = j, d = i;
				}
			}
			for(int j = 1; j <= x; ++j){
				temp = j + (n -1)*(diff/i);
				if(temp < _min and temp >= y and if_x_y(j, diff/i, n, x, y)){
					ini = j, d = diff/i;
					_min = temp;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		cout << ini + i*d << " ";
	}
	cout << endl;
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
	