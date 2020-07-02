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
	int n, k;
	cin >> n >> k;

	int mat[n +1][n +1];
	memset(mat, 0, sizeof(mat));

	int cnt = 0, h = 1, v = n +1, total_ones = 0;
	for(int i = 0; i < k; ++i){
		if(cnt == 0){
			cnt++;
			for(int j = 1; j <= n and total_ones < k; ++j, total_ones++){
				mat[j][j] = 1;
			}
		}else if(cnt&1){
			++h;
			cnt++;
			for(int j = h, l = 1; j <= n and total_ones < k; ++total_ones, ++j, ++l){
				mat[l][j] = 1;
			}
		}else{
			cnt++;
			--v;
			for(int j = v, l = 1; j <= n and total_ones < k; ++total_ones, ++j, ++l){
				mat[j][l] = 1;
			}
		}
	}

	int min_row_sum = MOD, max_row_sum = 0;
	int min_col_sum = MOD, max_col_sum = 0;

	for(int i = 1; i <= n; ++i){
		int temp = 0;
		for(int j = 1; j <= n; ++j){
			temp += mat[i][j];
		}
		min_row_sum = min(min_row_sum, temp);
		max_row_sum = max(max_row_sum, temp);
	}

	for(int i = 1; i <= n; ++i){
		int temp = 0;
		for(int j = 1; j <= n; ++j){
			temp += mat[j][i];
		}
		min_col_sum = min(min_col_sum, temp);
		max_col_sum = max(max_col_sum, temp);
	}

	cout << (((max_row_sum - min_row_sum)*(max_row_sum - min_row_sum)) + ((max_col_sum - min_col_sum)*(max_col_sum - min_col_sum))) << endl;

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cout << mat[i][j];
		}
		cout << endl;
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
	