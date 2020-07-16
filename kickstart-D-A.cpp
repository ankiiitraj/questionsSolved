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

int solve(){
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);

	int prev_max = -1, res = 0;

	for(int i = 0; i < n -1; ++i){
		if(a[i] > prev_max and a[i] > a[i +1]){
			res++;
		}
		if(a[i] > prev_max){
			prev_max = a[i];
		}
	}

	if(a[n -1] > prev_max){
		res++;
	}

	return res;
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; for(int test = 0; test < t; ++test){
		
		cout << "Case #" << test << ": " << solve() << endl;

	}
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
	