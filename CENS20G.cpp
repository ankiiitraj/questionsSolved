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
	string s;
	cin >> s;
	int n = s.length(), x, y, q, qx, qy;
	cin >> x >> y >> q;
	map<char, int> m;
	for(auto itr: s){
		m[itr]++;
	}
	while(q--){
		cin >> qx >> qy;
		if(qx >= x and m['R'] >= abs(qx - x)){
			if(qy >= y and m['U'] >= abs(qy - y)){
				cout << "YES " << (abs(qx - x) + abs(qy - y)) << endl;
			}else if(qy <= y and m['D'] >= abs(qy - y)){
				cout << "YES " << (abs(qx - x) + abs(qy - y)) << endl;
			}else{
				cout << "NO\n";
			}
		}else if(qx <= x and m['L'] >= abs(qx - x)){
			if(qy >= y and m['U'] >= abs(qy - y)){
				cout << "YES " << (abs(qx - x) + abs(qy - y)) << endl;
			}else if(qy <= y and m['D'] >= abs(qy - y)){
				cout << "YES " << (abs(qx - x) + abs(qy - y)) << endl;
			}else{
				cout << "NO\n";
			}
		}else{
			cout << "NO\n";
		}
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
	