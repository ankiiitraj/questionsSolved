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

int recurse(string &s, int l, int r, int num){
	if(l == r){
		if(s[l] - 'a' == num)
			return 0;
		else
			return 1;
	}

	int cnt_f = 0, cnt_s = 0; 
	for(int i = l; i <= (l + r)/2; ++i){
		if(s[i] - 'a' != num){
			cnt_f++;
		}
	} 
	for(int i = (l + r)/2 +1; i <= r; ++i){
		if(s[i] - 'a' != num){
			cnt_s++;
		}
	}
	cnt_f += recurse(s, (l + r)/2 +1, r, num +1);
	cnt_s += recurse(s, l, (l + r)/2, num +1);
	return min(cnt_f, cnt_s);
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		int n;
		string s;
		cin >> n >> s;

		cout << recurse(s, 0, n -1, 0) << endl << cnt << endl;
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
