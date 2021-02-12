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

int rec(int pos)

void solve(){
	int n;
	cin >> n;
	vi a(n), b;
	scnarr(a, n);

	for(int i = 0; i < n; ++i){
		int j = i +1;
		while(j < n and a[j] == a[i]){
			++j;
		}

		if(j - i >= 2){
			b.push_back(a[i]);
		}
		b.push_back(a[i]);

		i = j -1;
	}
	n = b.size();
	if(n <= 2){
		cout << n << endl;
		return;
	}
	vi x, y;
	y.push_back(-1);
	if(b[0] == b[1]){
		x.push_back(b[0]);
		y.push_back(b[1]);
	}else{
		x.push_back(b[0]);
		x.push_back(b[1]);
	}
	for(int i = 2; i < n; ++i){
		if(x.back() != b[i]){
			x.push_back(b[i]);
		}else if(y.back() != b[i]){
			y.push_back(b[i]);
		}
	}
	cout << (x.size() + y.size() -1) << endl;
	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
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
