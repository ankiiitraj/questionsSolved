#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
	int n, q, x, y;
	scanf("%lld%lld", &n, &q);
	vi a(n +1);

	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
	}

	if(n == 1){
		while(q--){
			scanf("%lld%lld", &x, &y);
			printf("1\n");
		}
		return;
	}else if(n == 2){
		while(q--){
			scanf("%lld%lld", &x, &y);
			a[x] = y;
			if(a[1] == a[2]){
				printf("1\n");
			}else{
				printf("2\n");
			}
		}
		return;
	}

	int patches = 1;
	for(int i = 2; i <= n; ++i){
        if(a[i] != a[i -1]){
            patches++;
        }
    }


	while(q--){
		scanf("%lld%lld", &x, &y);
		if(x == 1){
			if(a[x] == a[x +1] and a[x] != y){
				patches++;
			}else if(a[x] != a[x +1] and a[x +1] == y){
				patches--;
			}
		}else if(x == n){
			if(a[x] == a[x -1] and a[x] != y){
				patches++;
			}else if(a[x] != a[x -1] and a[x -1] == y){
				patches--;
			}
		}else{
			if(a[x] == a[x +1] and a[x] == a[x -1] and a[x] != y){
				patches += 2;
			}else if((a[x] == a[x -1] or a[x] == a[x +1]) and (y != a[x -1] and y != a[x +1])){
				patches++;
			}else if(a[x] != a[x +1] and a[x] != a[x -1]){
				if(a[x +1] == a[x -1] and a[x +1] == y){
					patches -= 2;
				}else if(a[x +1] != a[x -1] and (a[x +1] == y or a[x -1] == y)){
					patches--;
				}
			}
		}
		printf("%lld\n", patches);
		a[x] = y;
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
	int t; scanf("%lld", &t); while(t--)
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
