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

void solve(){
	int n, k, l1, l2, r1, r2;
	cin >> n >> k >> l1 >> r1 >> l2 >> r2;

	int total_overlap_cost = abs(l1 - l2) + abs(r1 - r2), total_overlap = max(r1 , r2) - min(l1, l2);
	int inittial_overlap == 0;
	if((l1 <= l2 and r1 >= r2)){
		inittial_overlap = n*(r2 - l2);
	}else if((l2 <= l1 and r2 >= r1)){
		inittial_overlap = n*(r1 - l1);
	}else if()
	if(total_overlap == k){
		cout << total_overlap_cost << endl;
	}else if(k < total_overlap){
		int ans;
		if((l2 >= r1)){
			ans  = l2 - r1 + k;
		}else if((l1 >= r2)){
			ans  = l1 - r2 + k;
		}else{
			ans = k;
		}
		cout << ans << endl;
	}else{
		int ans = (k/total_overlap) * total_overlap_cost;
		k %= total_overlap;
		if((l2 >= r1)){
			ans += l2 - r1 + k;
		}else if((l1 >= r2)){
			ans += l1 - r2 + k;
		}else{
			ans += k;
		}
		cout << ans << endl;
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
	