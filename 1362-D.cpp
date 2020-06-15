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
vi adj[500005];
vector<pii> a;
int n, m;

bool cmp(pii &p1, pii &p2){
	return p1.first < p2.first;
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
		int x, y, flag = 0;
		vector<pii> edges;
		cin >> n >> m;

		for(int i = 0; i < m; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			edges.push_back({x, y});
		}
		a.resize(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i].first;
			a[i].second = i +1; 
		}
		for(auto &itr: edges){
			if(a[itr.first -1].first == a[itr.second -1].first){
				flag = 1;
				break;
			}
		}
		if(flag){
			cout << -1 << endl;
		}else{
			sort(all(a), cmp);
			vi ans;
			int flag = 0;
			vi map(n +1, 0);
			for(int i = 0; i < n; ++i){
				int _max = 0;
				unordered_set <int> s;
				for(auto itr: adj[a[i].second]){
					if(map[itr] != 0){
						s.insert(map[itr]);
					}
				}
				if(s.size() +1 != a[i].first){
					flag = 1;
					break;
				}else{
					map[a[i].second] = a[i].first; 
					ans.push_back(a[i].second);
				}
			}
			if(flag){
				cout << -1;
			}else{
				for(auto itr: ans){
					cout << itr << " ";
				}
			}
			cout << endl;
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	