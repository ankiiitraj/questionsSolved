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
	int x, y, z;
	cin >> x >> y >> z;

	if(x == y and y == z){
		cout << "YES\n" << x << " " << x << " " << x << endl;
	}else if(x != y and y != z and x != z){
		cout << "NO\n";
	}else{
		if(x == y and x > z){
			cout << "YES\n" << x << " " << z << " " << z << endl;
		}else if(x == z and x > y){
			cout << "YES\n" << x << " " << y << " " << y << endl;
		}else if(y == z and y > x){
			cout << "YES\n" << x << " " << x << " " << z << endl;
		}else{
			cout << "NO\n";
		}
	}


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
	