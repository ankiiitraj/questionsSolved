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
	vi a(n);
	scnarr(a, n);
	sort(all(a));
	reverse(all(a));
	mii m;
	vi res;
	res.push_back(a[0]);

	for(auto itr: a)
		m[itr]++;
	m[a[0]]--;
	int cur_gcd = a[0];
	for(int i = 1; i < n; ++i){
		int _max = -1, idx = -1;
		for(int j = 0; j < n; ++j){
			if(m[a[j]] > 0){
				if(_max < __gcd(cur_gcd, a[j])){
					_max = __gcd(cur_gcd, a[j]);
					idx = j;
				}
			}
		}
		res.push_back(a[idx]);
		m[a[idx]]--;
		cur_gcd = __gcd(cur_gcd, a[idx]);
	}
	for(auto itr: res)
		cout << itr << " ";
	cout << endl;
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
	