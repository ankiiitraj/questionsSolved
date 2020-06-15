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
int n, m;
mii adj[N];

bool visited[N];
bool dfs(int i){
	visited[i] = 1;
	bool ans = false;
	for(auto &itr:adj[i]){
		if(!visited[itr.first]){
			bool nans = dfs(itr.first);
			ans = ans or nans;
		}
		if(itr.second > 1){
			ans = 1;
		}
	}
	return ans;
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int u, v, cnt = 0, multi = 0;
		cin >> n >> m;
		
		for(int i = 0; i <= n +1; ++i){
			adj[i].clear();
			visited[i] = 0;
		}
		
		map<pii, int> multiEdges;

		for(int i = 0; i < m; ++i){
			cin >> u >> v;
			adj[u][v]++;
			adj[v][u]++;
			if(u > v){
				int temp = u;
				u = v;
				v = temp;
			}
			multiEdges[{u, v}]++;
		}
		int tot = 0;
		for(auto &itr: multiEdges){
			if(itr.second >= 1)
				tot += itr.second -1;
		}

		// for(int i = 1; i <= n; ++i){
		// 	for(auto &itr: adj[i]){
		// 		cout << itr.first << " ";
		// 	}
		// 	cout << endl;
		// }

		for(int i = 1; i <= n; ++i){
			if(!visited[i]){
				bool multi_edged = false;
				multi_edged = dfs(i);
				cnt++;
				if(multi_edged)
					multi++;
			}
		}

		tot -= multi;
		if(multi == 0){
			cout << (cnt - 1)*2 << " 1\n1 2\n";
		}else if(multi >= 1 and cnt == multi +1){
			cout << "2 1\n1 2\n";
		}else if(multi == cnt){
			cout << "0 1\n1 2\n";
		}else if(multi == 1){
			int not_multi = cnt - multi;
			tot += multi;
			int req = tot*2; //cost 1
			int ans;
			if(not_multi >= req){
				ans = req + (not_multi - req)*2;
			}else{
				if(not_multi&1){
					ans = not_multi + 1;
				}else{
					ans = not_multi;
				}
			}

			cout << ans << " 1\n1 2\n";
		}else if(multi >= 2){
			int not_multi = cnt - multi -2;
			int req = tot*2; //cost 1
			int ans;
			if(not_multi >= req){
				ans = req + (not_multi - req)*2;
			}else{
				if(not_multi&1){
					ans = not_multi + 1;
				}else{
					ans = not_multi;
				}
			}

			cout << (2 + ans) << " 1\n1 2\n";
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	