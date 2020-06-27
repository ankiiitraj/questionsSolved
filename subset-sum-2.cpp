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
int n;
map<pair<int, int>, int> dp;

int recurse(int pos, int cur_sum){
	if(pos > n)
		return cur_sum;
	if(dp.find({pos, cur_sum}) != dp.end())
		return dp[{pos, cur_sum}];
	return dp[{pos, cur_sum}] = (recurse(pos +1, cur_sum + pos) + recurse(pos +1, cur_sum))%1000000007;

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		dp.clear();
		cin >> n;
		cout << recurse(1, 0) << endl;
	}
}


//Author : Ankit Raj
//Problem Link : https://www.hackerearth.com/problem/algorithm/subset-sum-2/description/

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
	