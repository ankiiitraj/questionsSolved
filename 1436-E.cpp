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
	vi a(n), ones(n, 1);
	scnarr(a, n);
	if(a == ones){
		cout << "1\n";
		return;
	}
	vector<vi> m(n +1);
	for(int i = 0; i < n; ++i){
		m[a[i]].push_back(i);
	}

	for(int i = 2; i <= n +1; ++i){
		bool flag = 0;
		for(auto itr: m[i -1]){
			if(itr != 0 and itr != n -1){
				if(a[itr -1] != i or a[itr +1] != i){
					flag = 1;
					break;
				}
			}else if(itr == 0){
				if(a[itr +1] != i){
					flag = 1;
					break;
				}
			}else if(itr == n -1){
				if(a[itr -1] != i){
					flag = 1;
					break;
				}
			}
		}
		if(!flag){
			cout << i << endl;
			return;
		}
	}

	return;
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
