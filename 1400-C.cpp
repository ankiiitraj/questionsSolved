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
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		string s;
		int k;
		cin >> s >> k;
		int n = s.length();
		string res(n, '1');

		for(int i = 0; i < n; ++i){
			if(s[i] == '0'){
				if(i - k >= 0){
					res[i - k] = '0';
				}
				if(i + k <= n -1){
					res[i + k] = '0';
				}
			}
		}
		int i = 0;
		for(; i < n; ++i){
			if(s[i] == '1'){
				if(i - k >= 0 and res[i - k] == '1')
					continue;
				if(i + k <= n -1 and res[i + k] == '1')
					continue;
				cout << "-1\n";
				break;
			}
		}
		if(i == n){
			cout << res << endl;
		}
	}
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
	