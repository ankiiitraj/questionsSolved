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
	if(n == 3){
		cout << "2\n";
		return;
	}
	if(n%4 != 0 and (n +1)%4 != 0){
		cout << "0\n";
		return;
	}

	int semi_sum = (n*(n +1))/4 - (n -1), l = 1, r = n;
	int sum = (n*(n +1))/4, ans = 0;

	while(l < r){
		int mid = l + (r - l)/2;
		if((mid*(mid +1))/2 == semi_sum){
			r = mid;
			break;
		}else if((mid*(mid +1))/2 >= semi_sum){
			r = mid;
		}else{
			l = mid +1;
		}
	}
	
	while((r*(r +1))/2 <= sum){
		int dif = sum - (r*(r +1))/2;
		if(dif == 0){
			ans += (r*(r -1))/2;
			r = n - r;
			ans += (r*(r -1))/2;
			break;
		}
		int left_idx = max(1LL, r +1 - dif);
		int right_idx = min(n, r + dif) - dif;
		ans += right_idx - left_idx +1;
		++r;
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
	