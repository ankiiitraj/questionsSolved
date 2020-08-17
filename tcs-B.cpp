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
	int x, y, n;
	cin >> x >> y >> n;
	if(x > y){
		y ^= x;
		x ^= y;
		y ^= x;
	}

	vector<long double> a(n +1), sma(n +1, 0.0), fma(n +1, 0.0);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long double fm = 0.0000000000, sm = 0.000000000;
	for(int i = 1; i <= x; ++i){
		fm += a[i]*1.000000000;
	}
	fma[x] = (long double)(fm/(x*1.000000000));
	for(int i = 1; i <= y; ++i){
		sm += a[i]*1.000000000;
	}
	sma[y] = sm/(y*1.000000000);
	for(int i = x +1; i <= n; ++i){
		fm += a[i]*1.000000000 - a[i - x]*1.000000000;
		fma[i] = fm/(x*1.000000000);
	}
	for(int i = y +1; i <= n; ++i){
		sm += a[i]*1.000000000 - a[i - y]*1.000000000;
		sma[i] = sm/(y*1.000000000);
	}


	int res = 0;

	for(int i = y; i < n; ++i){
		if(fma[i] > sma[i] and fma[i +1] < sma[i +1]){
			res++;
		}else if(fma[i] < sma[i] and fma[i +1] > sma[i +1]){
			res++;
		}
	}
	
	// for(int i = y; i <= n; ++i){
	// 	if(fma[i] == sma[i])
	// 		res++;
	// }

	cout << res << endl;
}

signed main()
{
	// faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
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
	