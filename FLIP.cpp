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

int find(string a, string b){
	int n = a.length(), res = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] != b[i]){
			int j = i +1;
			while(j < n and a[j] != b[j]){
				++j;
			}
			res++;
			i = j -1;
		}
	}
	return res;
}

void solve(){
	string a, b, za, zb, oa, ob;
	cin >> a >> b;

	int n = a.length(), res = 0;

	for(int i = 0; i < n; i += 2){
		za += a[i];
		zb += b[i];
	}

	for(int i = 1; i < n; i += 2){
		oa += a[i];
		ob += b[i];
	}

	res = find(za, zb) + find(oa, ob);

	cout << res << endl;

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
