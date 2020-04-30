#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 505; // 1e6 +1
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/* -------------------------------Solution Sarted--------------------------------------*/


int n, k; 

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		cin >> n >> k;
		vi a[k], temp(n +1, 0), ans(n +1, 0), adjList[n +1];
		bool adj[n +1][n +1] = {0};	

		/*Declerations*/

		for (int i = 0; i < k; ++i) {
			a[i] = temp;
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < k; ++i){
			if(i == 0){
				for(int j = 0; j < n; ++j){
					for(int k = j +1; k < n; ++k){
						adj[a[i][j]][a[i][k]] = 1;
					}
				}
			}else{
				for(int j = 0; j < n; ++j){
					for(int k = j +1; k < n; ++k){
						if(adj[a[i][j]][a[i][k]] == 0){
							if(adj[a[i][k]][a[i][j]] != 0){
								adj[a[i][k]][a[i][j]] = 0;
							}
						}	
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if(adj[i][j] == 1){
					adjList[i].push_back(j);
				}
			}
		}
		bool used[n +1] = {0};
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adjList[j].size() == i){
					for(auto itr:adjList[j]){
						if(used[itr] == 0){
							used[itr] = 1;
							ans[j] = itr;
							break;
						}
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i){
			if(ans[i +1] == 0)
				cnt++;
		}
		cout << cnt << endl;
		for (int i = 0; i < n; ++i){
			cout << ans[i +1] << " ";
		}
		cout << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
