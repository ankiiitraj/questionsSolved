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

int hcf(int a, int b)
{
    if (b == 0)
        return a;
    return hcf(b, a % b); 
     
}

void solve(){
	int n, m;
	cin >> n >> m;
	vi a(m);
	scnarr(a, m);
	if(n == 1){
		cout << "0\n";
		return;
	}

	int gcd = a[0];
	for(int i = 0; i < m; ++i){
		gcd = (int)hcf((int)gcd, (int)a[i]);		
	}

	if(gcd <= n){
		cout << (n - gcd) << endl;
	}else{
		int res = -1;
		for(int i = 2; i * i <= gcd; ++i){
			if(i <= n and gcd % i == 0){
				int rev = gcd / i;
				res = max(res, i);
				if(rev <= n and gcd % rev == 0){
					res = max(res, rev);
				}
			}
		}
		if(res == -1)
			res = n -1;
		else
			res = n - res;
		cout << res << endl;
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
