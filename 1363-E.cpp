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

struct triples{
	int a;
	bool b, c;
};

vi adj[200005];
vector<triples> v;
bool visited[200005];
int ones, zeroes;

void dfs(int s, int par){
	visited[s] = 1;

	if(v[s].b != v[s].c){
		if(v[s].b){
			ones++;
		}else{
			zeroes++;
		}
	}

	if(par != -1 and v[s].a > v[par].a){
		v[s].a = v[par].a;
	}

	for(auto itr: adj[s]){
		if(!visited[itr]){
			dfs(itr, s);
		}
	}
}

int ans;

pii Dfs(int s){
	visited[s] = 1;

	pii cnt = {0, 0};
	for(auto itr: adj[s]){
		if(!visited[itr]){
			pii temp = Dfs(itr);
			cnt.first += temp.first, cnt.second += temp.second;
		}
	}

	if(v[s].b != v[s].c){
		if(v[s].b){
			cnt.first++;
		}else{
			cnt.second++;
		}
	}

	int _min = min(cnt.first, cnt.second); 
	ans += 2*_min*v[s].a;
	cnt.first -= _min;
	cnt.second -= _min;

	return cnt;


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
		int n, x, y;
		cin >> n;


		for(int i = 0; i < n +1; ++i)
			adj[i].clear();

		v.resize(n +2);
		for(int i = 1; i <= n; ++i){
			triples temp;
			cin >> temp.a >> temp.b >> temp.c;
			v[i] = temp;
		}

		for(int i = 0; i < n -1; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		dfs(1, -1);

		if(ones != zeroes){
			cout << "-1\n";
		}else{
			memset(visited, 0, sizeof(visited));
			Dfs(1);
			cout << ans << endl;
		}


	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	