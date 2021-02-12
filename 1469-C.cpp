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
	int n, k;
	cin >> n >> k;
	vi a(n), b(n);
	scnarr(a, n);
	
	if(n == 2){
		if(abs(a[0] - a[1]) >= k){
			cout << "NO\n";
		}
		cout << "YES\n";
		return;
	}

	int prevMax = a[0] + k -1, prevMin = a[0] - k +1;
	for(int i = 1; i <= n -2; ++i){
		int curMax = a[i] + k -1, curMin = a[i];
		if(curMax < prevMin or curMin > prevMax){
			cout << "NO\n";
			return;
		}else{
			if(curMax <= prevMax and curMin >= prevMin){
				prevMax = curMax, prevMin = curMin;
			}else if(curMax >= prevMax and curMin <= prevMin){
				
			}else if(curMin >= prevMin){
				prevMin = curMin;
			}else{
				prevMax = curMax;
			}
			prevMax += (k -1);
			prevMin -= (k -1);
			// cout << prevMin << " " << prevMax << endl;
		}
	}
	int curMax = a[n -1], curMin = a[n -1];
	if(curMax < prevMin or curMin > prevMax){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	return;
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
