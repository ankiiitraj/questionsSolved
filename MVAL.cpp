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
	int n, cnt = 0, sum = 0;
	cin >> n;
	vi a(n), indices;
	scnarr(a, n);

	for(auto itr: a){
		if(itr > 0)
			sum += itr, cnt++;
	}
	if(cnt == 0 or cnt == 1){
		cout << sum << endl << "0\n";
		return;
	}
	for(int i = 0; i < n; ++i){
		if(a[i] > 0){
			cnt--;
			for(int j = i -1; j >= 0 and cnt > 0; --j){
				if(a[j] <= 0){
					indices.push_back(j +1);
					cnt--;
				}
			}
			int j = i +1;
			for(; j < n and cnt > 0; ++j){
				if(a[j] <= 0){
					indices.push_back(j +1);
					cnt--;
				}else{
					cnt--;
				}
			}
			for(; j < n; ++j){
				if(a[j] > 0)
					indices.push_back(j +1);
			}
			sort(all(indices));
			cout << sum << endl << indices.size() << " ";
			for(auto itr: indices)
				cout << itr << " ";
			cout << endl;
			return;
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
	