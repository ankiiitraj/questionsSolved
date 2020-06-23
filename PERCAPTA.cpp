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

/* -------------------------------Solution Sarted--------------------------------------*/
struct point{
	int first, second, id;
};

int n, m;
vi a(200005), b(200005), adj[200005], new_path;
set<int> to_use;
vector<point> pci;
bool visited[200005];

bool cmp(point &p1, point &p2){
	int a = p1.first; 
    int b = p1.second; 
    int c = p2.first; 
    int d = p2.second; 
    int Y = a * d - b * c; 
  
    return (Y > 0) ? 1 : 0; 
}

int cnt;

void dfs(int i){
	visited[i] = 1;
	new_path.push_back(i);
	cnt++;
	for(auto itr:adj[i]){
		if(!visited[itr]){
			dfs(itr);
		}
	}
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
		int u, v;
		cin >> n >> m;
		scnarr(a, n);
		scnarr(b, n);
		for(int i = 0; i <= n; ++i){
			adj[i].clear();
			visited[i] = false;
		}
		pci.clear();
		to_use.clear();
		for(int i = 0; i < n; ++i){
			int num = a[i], deno = b[i], gcd = __gcd(num, deno);
			num /= gcd, deno /= gcd;
			pci.push_back({num, deno, i});
		}

		sort(all(pci), cmp);

		for(int i = 1; i < n; ++i){
			to_use.insert(pci[i -1].id +1);
			if(pci[i].first != pci[i -1].first or pci[i].second != pci[i -1].second){
				break;
			}
			if(i == n -1 and pci[n -1].first == pci[n -2].first or pci[n -1].second == pci[n -2].second){
				to_use.insert(pci[i].id +1);
			}
		}

		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			if(to_use.find(u) != to_use.end() and to_use.find(v) != to_use.end()){
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		int res = 1;
		vi path;
		for(auto i: to_use){
			if(!visited[i]){
				new_path.clear();
				cnt = 0;
				dfs(i);
				if(cnt > res){
					res = cnt;
					path = new_path;
				}
			}
		}

		cout << res << endl;
		for(auto itr: path)
			cout << itr << " ";
		cout << endl;
	}
	return 0;
}