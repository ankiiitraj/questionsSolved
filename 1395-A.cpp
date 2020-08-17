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
	int r, g, b, w;
	cin >> r >> g >> b >> w;
	if((r + g + b + w)&1){
		if(r == 0 or g == 0 or b == 0){
			if(r == 0 and (g%2==0 or b%2==0 or w%2 == 0)){
				puts("YES");
			}else if(g == 0 and (r%2==0 or b%2==0 or w%2 == 0)){
				puts("YES");
			}else if(b == 0 and (r%2==0 or g%2==0 or w%2 == 0)){
				puts("YES");
			}else{
				puts("NO");
			}
		}else{
			puts("YES");

		}
	}else{
		int cnt = 0;
		if(r&1)
			cnt++;
		if(g&1)
			cnt++;
		if(b&1)
			cnt++;
		if(w&1)
			cnt++;
		if(cnt == 0 or cnt == 4)
			puts("YES");
		else
			puts("NO");	
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
	