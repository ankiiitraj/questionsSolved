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
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

int dp[100005][6][2];

int rec(vi &a, int n, int pos, int z, int k, bool can_go_left){
	if(pos >= n or k <= 0 or pos < 1){
		return 0;
	}

	if(dp[pos][z][can_go_left] != -1)
		return dp[pos][z][can_go_left];

	if(z > 0 and can_go_left and pos != 1){
		return dp[pos][z][can_go_left] = max(rec(a, n, pos +1, z, k -1, 1) + a[pos +1], rec(a, n, pos -1, z -1, k -1, 0) + a[pos -1]);
	}

	return dp[pos][z][can_go_left] = rec(a, n, pos +1, z, k -1, 1) + a[pos +1];

}

void solve(){
	int n, k, z;
	cin >> n >> k >> z;
	vi a(n +1);
	scnarr(a, n);

	int pref[n +1] = {0}, total = 0, res = a[0];

	for(int i = 1; i <= n; ++i){
		total += a[i];
		pref[i] = pref[i -1] + a[i];
	}
	int until = a[1];
	int K = k;
	for(int i = 2; i <= min(n, 1 + K); ++i){
		int cnt_k = 0, cnt_z = 0, idx = i, cycle_sum = 0, cur = 0, cur_ans = 0;
		until += a[i];
		cur = until;
		--k;
		while(cnt_k < k and cnt_z < z){
			cnt_k++;
			if(idx == i){
				idx--;
				cnt_z++;
				cycle_sum += a[idx];
			}else{
				idx++;
				cycle_sum += a[idx];
				cur = max(until + pref[idx + (k - cnt_k)] - pref[idx] + cycle_sum, cur);
			}
		}
		cur = max(until + pref[idx + (k - cnt_k)] - pref[idx] + cycle_sum, cur);
		res = max(res, cur);

	}

	cout << res << endl;
}

void solve_using_dp(){
	int n, k, z;
	cin >> n >> k >> z;
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= z; ++j){
			for(int l = 0; l <= 1; ++l)
				dp[i][j][l] = -1;
		}
	}
	vi a(n +1);
	scnarr(a, n);

	cout << rec(a, n, 1, z, k, 1) + a[1] << endl;	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
		solve_using_dp();
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
	