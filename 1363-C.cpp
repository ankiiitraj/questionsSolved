#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/
vi adj[1015];


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, x, u, v;
		cin >> n >> x;
		for(int i = 0; i <= n +5; ++i)
			adj[i].clear();

		for(int i = 0; i < n -1; ++i){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if(adj[x].size() == 1 or adj[x].size() == 0){
			cout << "Ayush\n";
		}else{
			if(n&1){
				cout << "Ashish\n";
			}else{
				cout << "Ayush\n";
			}
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	