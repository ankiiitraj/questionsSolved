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

int lcm(int a, int b){
	return (a*b)/__gcd(a, b);
}

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
vi adj[105];
vi nodes(105);
int n;
bool visited[105];
void dfs(int i, int d, int cur){
	visited[i] = 1;
	for(auto itr: adj[i]){
		if(!visited[itr]){
			if(cur%(d + 1) == 0)
				dfs(itr, d +1, cur);
			else{
				nodes[itr] = lcm((d +1), nodes[itr]);
				dfs(itr, d +1, nodes[itr]);
			}
		}
	}
}


void solve(){
	int x, y;
	cin >> n;
	nodes.assign(n +1, 1);
	for(int i = 0; i <= n; ++i)
		adj[i].clear();
	for(int i = 0; i < n -1; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int  i = 1; i <= n; ++i){
		memset(visited, 0, sizeof(visited));
		dfs(i, 1, nodes[i]);
	}

	for(int i = 1; i <= n; ++i)
		cout << nodes[i] << " ";
	cout << endl;

	
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
	