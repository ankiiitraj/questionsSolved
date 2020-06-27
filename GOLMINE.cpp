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
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	
}
signed main(){
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; scanf("%lld", &t); while(t--){
		int n;
		scanf("%lld", &n);
		long double gold_in_mine, chef, chefu, temp, gold_with_chef = 0.0, gold_with_chefu = 0.0;
		for(int i = 0; i < n; ++i){
			scanf("%Lf%Lf%Lf", &gold_in_mine, &chef, &chefu);
			chef = gold_in_mine/chef, chefu = gold_in_mine/chefu, temp = (long double)((chef*gold_in_mine*1.0)/(chef + chefu));
			gold_with_chef += temp, gold_with_chefu += gold_in_mine - temp;
		}
		printf("%.9Lf %.9Lf\n", gold_with_chef, gold_with_chefu);
	}
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