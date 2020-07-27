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
int n;
vii a;

int solve(){
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));

return 0;

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	// freopen("ip.txt", "r", stdin);
	freopen("ip.txt", "w", stdout);
#endif
	// int t; cin >> t; for(int test = 1; test <= t; ++test){
	// 	cout << "Case #" << test << ": " <<  solve() << endl;
	// }
	// return 0;
	srand(time(NULL));
	int n = 1000, m = rand()%(n) +1;
	cout << 1 << endl << n << " " << m << endl;
	for(int i = 0; i < n; ++i){
		cout << (int)(rand()%10000001) << endl;
	}

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
	