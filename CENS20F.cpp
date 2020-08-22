#include <bits/stdc++.h>
#include <time.h>
#define int long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) scanf("%ld", &a[i])
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

int dfs(int i, int par, vi &parent, vi &subtree, vi adj[]){
	parent[i] = par;
	int cnt = 0;
	for(auto itr: adj[i]){
		if(itr != par){
			cnt += dfs(itr, i, parent, subtree, adj);
		}
	}
	subtree[i] = cnt;
	cnt++;
	return cnt;
}

int dfs_(int src, vi adj[], vi &parent, int dep, vi &a){
	int sum = 0;
	for(auto itr: adj[src]){
		if(itr != parent[src] and (!(dep&1) or ((dep&1) and a[itr] != -1))){
			sum += dfs_(itr, adj, parent, dep +1, a);
		}
	}
	if(!(dep&1)){
		sum += a[src];
		a[src] = -1;
	}
	return sum;
}

void solve(){
	int n, q, x, y;
	scanf("%ld%ld", &n, &q);
	vi a(n +1), parent(n +1), subtree(n +1);
	scnarr(a, n);
	vi adj[n +1];
	for(int i = 0; i < n -1; ++i){
		scanf("%ld%ld", &x, &y);
		adj[y].push_back(x);
		adj[x].push_back(y);
	}
	dfs(1, -1, parent, subtree, adj);
	vii queries;
	while(q--){
		scanf("%ld", &x);
		queries.push_back({subtree[x], x});

	}
	sort(all(queries));
	reverse(all(queries));

	for(int i = 0; i < queries.size(); ++i){
		if(a[queries[i].second] != -1){
			a[queries[i].second] = dfs_(queries[i].second,adj, parent, 0, a);
		}
	}

	for(int j = 1; j <= n; ++j){
		if(a[j] == -1){
			a[j] = 0;
		}
		printf("%ld ", a[j]);
	}
	printf("\n");

	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; scanf("%ld", &t); while(t--)
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
	