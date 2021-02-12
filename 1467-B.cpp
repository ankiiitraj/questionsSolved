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
	int n, res = 0;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	if(n <= 3){
		cout << "0\n";
		return;
	}
	vi tan0;
	for(int i = 1; i < n -1; ++i){
		if((a[i] > a[i -1] and a[i] > a[i +1]) or (a[i] < a[i -1] and a[i] < a[i +1])){
			tan0.push_back(i);
			res++;
		}
	}

	if(res <= 1){
		cout << 0 << endl;
		return;
	}else{
		res--;
		for(int i = 0; i < tan0.size() -1; ++i){
			int cur = tan0[i], next = tan0[i +1];
			if(next - cur == 1){
				if(abs(a[cur -1] - a[cur]) >= abs(a[cur] - a[next]) or abs(a[next +1] - a[next]) >= abs(a[cur] - a[next])){
					res--;
					break;
				}else if(cur == 1 or next == n -2){
					res--;
					break;
				}else{
					if(a[cur -1] == a[cur -2] or a[next +1] == a[next +2]){
						res--;
						break;
					}
				}
			}
		}

		for(int i = 1; i < tan0.size() -1; ++i){
			if(tan0[i] - tan0[i -1] == 1 and tan0[i +1] - tan0[i] == 1){
				res--;
				break;
			}
		}
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
