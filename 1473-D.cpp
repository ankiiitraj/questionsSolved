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
const int INF = 100000; // 1e15 +5

void solve(){
	int n, m, l, r;
	string s;
	cin >> n >> m >> s;

	int SIZE = log2(n) +1;
	vector<vi> st(SIZE, vi(n +1, INF));
	vector<vi> stm(SIZE, vi(n +1, -INF));

	vi a(n +1, 0);
	for(int i = 0; i < n; ++i){
		a[i +1] = a[i] + (s[i] == '+' ? 1 : -1);
	}
	
	for(int i = 0; i <= n; ++i) st[0][i] = a[i];
	for(int i = 0; i <= n; ++i) stm[0][i] = a[i];

	for(int i = 1; i < SIZE; ++i){
		for(int j = 0; j + (1 << i) <= n +1; ++j){
			st[i][j] = min(st[i -1][j], st[i -1][j + (1 << (i -1))]);
		}
	}
	for(int i = 1; i < SIZE; ++i){
		for(int j = 0; j + (1 << i) <= n +1; ++j){
			stm[i][j] = max(stm[i -1][j], stm[i -1][j + (1 << (i -1))]);
		}
	}
	// for(int i = 0; i < SIZE; ++i){
 //        for(int j = 0; j <= n; ++j){
 //            cout << st[i][j] << " ";
 //        }
 //        cout << endl;
 //    }

	auto findMin = [&](int l, int r){
		if(l > n)
			return INF;
		int maxPowOf2 = log2(r - l +1); // not sure log2 is contant time operation!
		return min(st[maxPowOf2][l], st[maxPowOf2][r - (1 << maxPowOf2) +1]);
	};
	auto findMax = [&](int l, int r){
		if(l > n)
			return -INF;
		int maxPowOf2 = log2(r - l +1); // not sure log2 is contant time operation!
		return max(stm[maxPowOf2][l], stm[maxPowOf2][r - (1 << maxPowOf2) +1]);
	};

	while(m--){
		cin >> l >> r;
		int curSum = a[r] - a[l -1];
		int toAdd = -curSum;
		int _min = min(findMin(0, l -1), findMin(r +1, n) + toAdd);	
		int _max = max(findMax(0, l -1), findMax(r +1, n) + toAdd);	
		// cout << _max << " " << _min << " " << toAdd << ": ";
		cout << _max - _min +1 << endl;
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
