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
const int INF = 100000000000005; // 1e15 +5



void solve(){
	int n, k, temp, cnt = 0;
	cin >> n >> k;
	multiset<int, greater<int>> ms;
	for(int i = 0; i < n; ++i){
		cin >> temp;
		ms.insert(temp*1.0);
	}
	while(cnt < k and *ms.begin() > 1){
		int cur = *ms.begin();
		ms.erase(ms.begin());
		ms.insert(ceil(cur/2));
		ms.insert(floor(cur/2));
		cnt++;
	}

	cout <<  (*ms.begin()) << endl;
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
		// solve();
	string s = "abc";
	cout << string(10, s[0]) << endl;
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