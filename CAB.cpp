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
	if(n > k){
		cout << "-1\n";
		return;
	}
	string res(n, 'a');
	k -= n;
	for(int i = 0; i < n; ++i){
		if(k == 0)
			break;
		int j = res[i] - 'a' +1;
		for(; j < 26; ++j){
			if(k - ((int)pow(2LL, j) - (int)pow(2LL, res[i] - 'a')) < 0){
				break;
			}
		}

		if(j != res[i] - 'a' +1){
			k -= ((int)pow(2LL, j -1) - (int)pow(2LL, res[i] - 'a'));
			res[i] = 'a' + j -1;
		}else{
			break;
		}
	}

	if(k != 0)
		cout << "-1\n";
	else
		cout << res << endl;

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
