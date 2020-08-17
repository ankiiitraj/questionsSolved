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

int dp[3005][3005][4];

int rec(vector<vi> &mat, int i, int j, int cnt, int r, int c){
	if(i == r and j == c){
		if(cnt > 0)
			return dp[i][j][cnt] = mat[i][j];
		return dp[i][j][cnt] = 0;
	}

	if(dp[i][j][cnt] != -1)
		return dp[i][j][cnt];

	int one = 0, two = 0;

	if(j < c){
		if(cnt > 0 and mat[i][j] > 0){
			two = max(rec(mat, i, j +1, cnt -1, r, c) + mat[i][j], rec(mat, i, j +1, cnt, r, c));
		}else{
			two = rec(mat, i, j +1, cnt, r, c);
		}
	}
	if(i < r){
		if(cnt > 0){
			one = rec(mat, i +1, j, 3, r, c) + mat[i][j];
		}else{
			one = rec(mat, i +1, j, 3, r, c);
		}
	}

	return dp[i][j][cnt] = max(one, two);

}

void solve(){
	int r, c, k, x, y, v;
	cin >> r >> c >> k;
	vector<vi> mat(r +1, vi(c +1, 0));
	for(int i = 0; i < k; ++i){
		cin >> x >> y >> v;
		mat[x][y] = v;
	}

	for(int i = 0; i <= r +1; ++i){
		for(int j = 0; j <= c +1; ++j){
			for(int l = 0; l < 4; ++l){
				dp[i][j][l] = -1;
			}
		}
	}

	cout << rec(mat, 1, 1, 3, r, c) << endl;
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
	