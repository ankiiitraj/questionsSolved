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

int func1(int x1, int y1, int z1, int x2, int y2, int z2){
	int ans = 0;
	int _min1;
	
	_min1 = min(z1, y2);
	ans += 2*_min1;
	z1 -= _min1;
	y2 -= _min1;

	_min1 = min(z2, x1);
	z2 -= _min1;
	x1 -= _min1;
	_min1 = min(z2, z1);
	z2 -= _min1;
	z1 -= _min1;
	_min1 = min(y1, y2);
	y1 -= _min1;
	y2 -= _min1;
	_min1 = min(y1, x2);
	y1 -= _min1;
	x2 -= _min1;

	_min1 = min(y1, z2);
	ans -= 2*_min1;
	y1 -= _min1;
	z2 -= _min1;
	return ans;
}

int func2(int x1, int y1, int z1, int x2, int y2, int z2){
	int ans = 0;
	int _min1;
	

	_min1 = min(z2, x1);
	z2 -= _min1;
	x1 -= _min1;
	_min1 = min(z2, z1);
	z2 -= _min1;
	z1 -= _min1;
	_min1 = min(y1, y2);
	y1 -= _min1;
	y2 -= _min1;
	_min1 = min(y1, x2);
	y1 -= _min1;
	x2 -= _min1;

	_min1 = min(z1, y2);
	ans += 2*_min1;
	z1 -= _min1;
	y2 -= _min1;

	_min1 = min(y1, z2);
	ans -= 2*_min1;
	y1 -= _min1;
	z2 -= _min1;
	
	return ans;
}


void solve(){
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;


	
	cout << max(func1(x1, y1, z1, x2, y2, z2), func2(x1, y1, z1, x2, y2, z2)) << endl;

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
	