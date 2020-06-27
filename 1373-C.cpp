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
	string s;
	cin >> s;
	int n = s.length();
	vi pre(n);
	pre[0] = s[0] == '+' ? 1 : -1;
	for(int i = 1; i < n; ++i){
		if(s[i] == '+')
			pre[i] = pre[i -1] +1;
		else
			pre[i] = pre[i -1] -1;
	}

	int _min = 100000000000000, cnt = 0, ans = 0;

	// for(int i = 0; i < n; ++i){
	// 	_min = min(_min, pre[i]);
	// }

	for(int i = 0; i < n; ++i){
		if((pre[i] + cnt) < 0){
			ans += (i +1)*(0 - (cnt + pre[i]));
			cnt += 0 - (cnt + pre[i]);
		}
	}
	cout << ans + n << endl;	
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
	