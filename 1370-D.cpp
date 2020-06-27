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
int n, k;

int dp[MAXN][2];

int recurse(vi &a, int pos, int odd_max, int even_max, int count){
	if(pos >= n){
		if(count != k)
			return MOD;
		return min(odd_max, even_max);
	}
	if(count == k){
		return min(odd_max, even_max);
	}

	if(dp[pos][count&1] != -1)
		return dp[pos][count&1];

	if(count&1)
		return dp[pos][count&1] = min(recurse(a, pos +1, odd_max, even_max, count), recurse(a, pos +1, odd_max,  max(even_max, a[pos]), count +1));
	return dp[pos][count&1] = min(recurse(a, pos +1, odd_max, even_max, count), recurse(a, pos +1, max(odd_max, a[pos]), even_max, count +1));

}

void solve_using_dp(){
	cin >> n >> k;
	vi a(n);
	scnarr(a, n);
	memset(dp, -1, sizeof(dp));
	cout << recurse(a, 0, -1, -1, 0) << endl;
	
}

bool check(vi &a, int val){
	int in_even = 0, in_odd = 0;
	for(int i = 0, j = 1; i < n; ++i){
		if(!(j&1)){
			in_odd++;
			++j;
		}else{
			if(a[i] <= val){
				in_odd++;
				++j;
			}
		}
	}
	if(in_odd >= k)
		return true;

	for(int i = 0, j = 1; i < n; ++i){
		if((j&1)){
			in_even++;
			++j;
		}else{
			if(a[i] <= val){
				in_even++;
				++j;
			}
		}
	}
	if(in_even >= k)
		return true;
	return false;
}

void solve(){
	cin >> n >> k;
	vi a(n);
	scnarr(a, n);
	
	int l = 1, h = 1000000000, mid;

	while(l <= h){
		mid = (l + h)/2;
		if(check(a, mid)){
			h = mid -1;
		}else{
			l = mid +1;
		}
	}
	cout << l << endl;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
		solve_using_dp();
	// solve();
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
	