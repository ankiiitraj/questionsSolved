#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
	int n, x, ans = 0;
	cin >> n >> x;
	vi a(n +1);
	scnarr(a, n);
	
	int mat[n +1][n +1];
	memset(mat, 0, sizeof(mat));

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			mat[i][j] = mat[i -1][j] + mat[i][j -1] + a[i] + a[j] - mat[i -1][j -1];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int l = 1, r = min(i, j), mid, ini_h, ini_v;
			while(l <= r){
				mid = (l + r)/2;
				int x1 = j - mid +1, y1 = i - mid +1;
				int sum = mat[i][j] - mat[i][x1 -1] - mat[y1 -1][j] + mat[y1 -1][x1 -1];
				// cout << mat[i][j] << " " << mat[i][x1] << " " << mat[y1][j] << " " << mat[y1 -1][x1 -1] << " " << sum << endl;
				if(sum == x){
					ans++;
					break;
				}else if(sum < x){
					l = mid +1;
				}else{
					r = mid -1;
				}

			}
		}
	}

	cout << ans << endl;



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
