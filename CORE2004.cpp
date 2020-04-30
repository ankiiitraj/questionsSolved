#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/
vi levels(N, -1), adj[N];
int bfs(int n){
	int visited[n +1] = {0}, lev = -1;
	levels.resize(n +1);
	queue <int> q;
	q.push(1), visited[1] = 1, levels[1] = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto itr:v[cur]){
			if(!visited[itr]){
				visited[itr] = 1;
				levels[itr] = levels[cur +1];
				q.push(itr);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		lev = max(lev, levels[i]);
	return lev +1;
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n;
		cin >> n;
		vi a(n +1);
		scnarr(a, n);

		for (int i = 0; i < n -1; ++i){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int lev = bfs(n);
		vector <pii> ans[lev];

		for(int i = 0; i < lev; ++i){
			ans[i].push_back({levels[i], });
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
