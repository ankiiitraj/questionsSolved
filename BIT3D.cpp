#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n +1);
	scnarr(a, n);

	int res1 = 1, res2 = 1, cur_pos = 0, last_pos = 0;

	for(int i = k; i >= 1; --i){
		if(a[i]%2 == 0){
			cur_pos = i;
			res1++;
			break;
		}
	}
	if(cur_pos != 0){
		while(cur_pos + k <= n){
			bool flag = 0;
			for(int j = cur_pos + k; j > cur_pos and j >= 1; --j){
				if(a[j]%2 == 0){
					last_pos = cur_pos;
					cur_pos = j;
					res1++;
					flag = 1;
					break;
				}
			}
			if(!flag){
				res1 = -1;
				break;
			}
		}
	}else{
		res1 = -1;
	}

	cur_pos = last_pos = 0;
	for(int i = k; i >= 1; --i){
		if(a[i]%2 != 0){
			cur_pos = i;
			res2++;
			break;
		}
	}
	if(cur_pos != 0){
		while(cur_pos + k <= n){
			bool flag = 0;
			for(int j = cur_pos + k; j > cur_pos and j >= 1; --j){
				if(a[j]%2 != 0){
					last_pos = cur_pos;
					cur_pos = j;
					res2++;
					flag = 1;
					break;
				}
			}
			if(!flag){
				res2 = -1;
				break;
			}
		}
	}else{
		res2 = -1;
	}

	if(res1 < 0 and res2 < 0){
		cout << -1 << endl;
	}
	else if(res1 > 0 and res2 > 0){
		cout << min(res1, res2) << endl;
	}else if(res1 > 0){
		cout << res1 << endl;
	}else{
		cout << res2 << endl;
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
	