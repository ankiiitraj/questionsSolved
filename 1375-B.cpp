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
#define no cout << "NO\n"; return
using namespace std;
using namespace chrono;
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

void solve(){
	int n, m;
	cin >> n >> m;

	vi temp(m, 0);
	vector<vector<int>> a(n);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> temp[j];
		}
		a[i] = temp;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] == 0){
				continue;
			}else{
				int neigh = 0;
				if(i > 0){
					neigh++;
				}
				if(i < n -1){
					neigh++;
				}
				if(j > 0){
					neigh++;
				}
				if(j < m -1){
					neigh++;
				}
				if(a[i][j] > neigh){
					no;
				}
			}	
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int neigh = 0;
			if(i > 0){
				neigh++;
			}
			if(i < n -1){
				neigh++;
			}
			if(j > 0){
				neigh++;
			}
			if(j < m -1){
				neigh++;
			}
			a[i][j] = neigh;	
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
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
	