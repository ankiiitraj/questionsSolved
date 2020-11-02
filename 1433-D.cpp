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

vi head, head_size;
void init(int n){
	head = vi(n +1);
	head_size = vi(n +1, 1);

	for(int i = 1; i <= n; ++i){
		head[i] = i;
	}
	return;
}

int find(int x){
	if(x == head[x]){
		return x;
	}
	return head[x] = find(head[x]);
}

void _union(int u, int v){
	if(head_size[v] > head_size[u]){
		swap(u, v);
	}
	u = find(u);
	v = find(v);
	
	head_size[u] += head_size[v];
	head_size[v] = 0;
	head[v] = u;

	return;
}

void solve(){
	int n;
	cin >> n;
	vi a(n +1);
	vii edges;
	scnarr(a, n);

	init(n);

	for(int i = 1; i <= n; ++i){
		for(int j = i +1; j <= n; ++j){
			int u = find(i), v = find(j);
			if(u != v and a[i] != a[j]){
				_union(i, j);
				edges.push_back({i, j});
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		if(head_size[i] == n){
			cout << "YES\n";
			for(auto itr: edges){
				cout << itr.first << " " << itr.second << endl;
			}
			return;
		}
	}

	cout << "NO\n";

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
