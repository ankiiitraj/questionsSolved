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

void solve(){
	int n, m, u, v, ans = -1;
	cin >> n >> m;
	si s, res, result;
	vi adj[n +1];
	for(int i = 1; i <= n; ++i)
		adj[i].clear();

	for(int i = 0; i < m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int j = 0; j < 5; ++j){
		s.clear();
		res.clear();

		int start = rand()%n +1;

		for(int i = start; i <= n; ++i){
			if(s.find(i) == s.end()){
				res.insert(i);
				for(auto itr: adj[i])
					s.insert(itr);
			}
		}
		
		for(int i = 1; i < start; ++i){
			if(s.find(i) == s.end()){
				res.insert(i);
				for(auto itr: adj[i])
					s.insert(itr);
			}
		}

		if((int)res.size() > ans){
			ans = res.size();
			result.clear();
			result = res;
		}

	}


	cout << result.size() << endl;
	for(int i = 1; i <= n; ++i){
		if(result.find(i) != result.end())
			cout << "1 ";
		else
			cout << "0 ";
	}
	cout << endl;

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("b4.in", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	srand(time(NULL));
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
	